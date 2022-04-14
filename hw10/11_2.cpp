#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "pattern.h"

#define umap std::unordered_map
#define vec std::vector

using std::string;

int main() {
	const int len = 8;
	const int finalTextLen = 200;
	std::ifstream file("text.txt");
	string s((std::istreambuf_iterator<char>(file)),
                 std::istreambuf_iterator<char>());
	umap<string, int> map;
	for (uint i = 0; i < s.length() - len; ++i) {
		string current = s.substr(i, len);
		if (map.find(current) != map.end())
			map[current]++;
		else
			map[current] = 0;
	}
	umap<string, vec<Pattern>> lookupTable;
	for (auto pair : map) {
		string smallStr = pair.first.substr(0, len - 1);
		// if smallstr already has entry in the lookup table
		if (lookupTable.find(smallStr) != lookupTable.end()) {
			// if pattern already in vec: increase occ
			//if (std::find(lookupTable[smallStr].begin(), lookupTable[smallStr].end(), pair.first) != lookupTable[smallStr].end()) {
			auto it = std::find_if(lookupTable[smallStr].begin(),
							 	   lookupTable[smallStr].end(),
							 	   [smallStr](Pattern const& e) {
								       return e.pattern == smallStr;
							 	   });
			if (it != lookupTable[smallStr].end()) {
				++(lookupTable[smallStr][it - lookupTable[smallStr].begin()]);

			// else add new pattern
			} else {
				lookupTable[smallStr].push_back(Pattern(pair.first));

			}

		// create new entry in lookup table, with one pattern
		} else {
			vec v = { Pattern(pair.first) };
			lookupTable[smallStr] = v;
		}
	}
	// set cum probabilities
	for (auto& pair : lookupTable) {
		double sum = 0.0;
		for (auto& pattern : pair.second) {
			sum += pattern.occs();
		}
		//std::cout << "SSSSSUUUUUUMMMMMM " << sum << std::endl;
		double cumSum = 0.0;
		for (auto& pattern : pair.second) {
			//std::cout << "occs " << pattern.occs() << std::endl;
			double prob = pattern.occs() / sum;
			//std::cout << "prob " << prob << std::endl;
			pattern.setCum(cumSum += prob);
			//std::cout << "cumsum " << pattern.prob() << std::endl;
		}
		//std::cout << "#########################" << std::endl;
	}
	
	// generate random text
	string text = "The work";
	while (text.length() < finalTextLen) {
		//std::cout << text << std::endl;
		string current = text.substr(text.length() - (len - 1));
		//std::cout << '"' << current << '"' << std::endl;
		// unkown pattern, exit
		if (lookupTable.find(current) == lookupTable.end()) {
			std::cout << "pattern not found" << std::endl;
			break;
		}
		auto prob = (double) rand() / (double) RAND_MAX;
		for (auto e : lookupTable[current]) {
			if (e.takeMe(prob)) {
				//std::cout << "last " << e.last() << std::endl;
				text += e.last();
				break;
			}
		}
	}
	std::cout << ">>>>fin<<<<" << std::endl;
	std::cout << text << std::endl;
	return 0;
}
