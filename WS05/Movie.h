#pragma once

#ifndef SDDS_MOVIE_H

/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#define SDDS_MOVIE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(m_title);
			spellChecker.operator()(m_description);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif //SDDS_MOVIE_H