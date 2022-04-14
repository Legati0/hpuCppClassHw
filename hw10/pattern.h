#ifndef PATTERN_H
#define PATTERN_H

#include <string>


class Pattern {
	
private:
	int occurances = 1;
	double cumProb = 0;
public:
	std::string pattern = "";
	Pattern(std::string pattern) : pattern(pattern) {}
	virtual ~Pattern() {};
	void setCum(const double c);
	int occs() const;
	char last() const;
	bool takeMe(double prob) const;
	double prob() const;

	bool operator==(const Pattern& other) const;
	bool operator==(const std::string& other) const;

	Pattern& operator++();
};

#endif
