#include "pattern.h"
#include <iostream>

bool Pattern::operator==(const Pattern& other) const {
	return other.pattern == pattern;
}
bool Pattern::operator==(const std::string& other) const {
	return other == pattern;
}
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
