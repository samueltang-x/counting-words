// counting-words.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "generating-cross-reference.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;

int main()
{
	string s;
	map<string, int> counter;

	/*
	cout << "Please enter the article to analyse: " << endl;
	while (cin >> s)
		++counter[s];

	for (map < string, int>::const_iterator iter = counter.begin();
		iter != counter.end(); ++iter) {
		cout << iter->first << "\t" << iter->second << endl;
	}
	*/
	
	cout << "Please enter the article to analyse: " << endl;
	map<string, vector<int> > ret = xref(cin);

	for (map < string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
		cout << it->first << " occurs on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;

		++line_it;
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}

		cout << endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
