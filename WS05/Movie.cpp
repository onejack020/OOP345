
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;

namespace sdds {

	Movie::Movie() {

		m_title = "";
		m_year = 0;
		m_description = "";
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {
		string temp = strMovie;
		string title, year, description;

		title = temp.substr(0, temp.find(','));
		title.erase(0, title.find_first_not_of(' '));
		title.erase(title.find_last_not_of(' ') + 1);
		temp.erase(0, temp.find(',') + 1);

		year = temp.substr(0, temp.find(','));
		year.erase(0, year.find_first_not_of(' '));
		year.erase(year.find_last_not_of(' ') + 1);
		temp.erase(0, temp.find(',') + 1);

		description = temp.substr(0, temp.find(','));
		description.erase(0, description.find_first_not_of(' '));
		description.erase(description.find_last_not_of(' ') + 1);
		temp.erase(0, temp.find(',') + 1);

		m_title = title;
		m_year = stoi(year);
		m_description = description;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << setw(40);
		os << movie.title() << " | ";
		os << setw(4);
		os << movie.m_year << " | ";
		os << movie.m_description << endl;
		
		return os;
	}
}
