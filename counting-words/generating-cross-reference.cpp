#include "split-words.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <istream>

using std::map;
using std::string;
using std::vector;
using std::istream;
using std::getline;
using std::cin;

map<string, vector<int> > xref(istream& in,
	vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while (getline(cin, line)) {
		++line_number;

		vector<string> words = find_words(line);
		for (vector<string>::const_iterator it = words.begin();
			it != words.end(); ++it) {
			ret[*it].push_back(line_number);
		}
	}
	return ret;
}