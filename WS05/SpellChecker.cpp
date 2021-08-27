
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {

		std::ifstream m_file(filename);
		size_t loads = 0u;
		string words;

		if (!m_file.is_open()) {
			throw("Bad file name!");
		}

		do {
			getline(m_file, words);

			if (m_file) {
				size_t pos = words.find_first_of(' ');
				m_badWords[loads] = words.substr(0, pos);
				words.erase(0, pos);
				pos = words.find_first_not_of(' ');
				m_goodWords[loads] = words.substr(pos);
				++loads;
			}
		} while (m_file && loads < 6);

		for (size_t i = 0; i < 6; ++i) {
			m_count[i] = 0;
		}
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < 6;) {
			size_t pos = text.find(m_badWords[i]);

			if (pos != std::string::npos) {
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				++m_count[i];
			}
			else {
				++i;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {

		for (size_t i = 0; i < 6; ++i) {
			out << right << setw(15) << m_badWords[i] << ": " << m_count[i] << " replacements" << endl;
		}
	}
}
