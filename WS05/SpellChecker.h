
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#pragma once

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H


#include <iostream>
#include <string>

namespace sdds {

	class SpellChecker {

		std::ifstream m_file;
		std::string m_badWords[6];
		std::string m_goodWords[6];
		
		//for misspelled words
		int m_count[6];

	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif //SDDS_SPELLCHECKER_H