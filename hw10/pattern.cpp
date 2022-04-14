#include "pattern.h"
#include <iostream>

/*bool Pattern::operator==(const Pattern& other) {
	return other.pattern == pattern;
}
bool Pattern::operator==(const std::string& other) {
	return other == pattern;
}
bool operator==(const Pattern& first, const Pattern& second) {
	return first.pattern == second.pattern;
}
bool operator==(const Pattern& first, const std::string& second) {
	return first.pattern == second;
}
bool operator==(const std::string& first, const Pattern& second) {
	return first == second.pattern;
}*/
int Pattern::occs() const {
	return occurances;
}
void Pattern::setCum(const double c) {
	cumProb = c;
}
char Pattern::last() const {
	return pattern[pattern.length() - 1];
}
bool Pattern::takeMe(double prob) const {
	return cumProb > prob;
}
double Pattern::prob() const {
	return cumProb;
}
Pattern& Pattern::operator++() {
	++occurances;
	return *this;
}
