

/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#pragma once

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

namespace sdds {

	class Book {
		std::string b_author;
		std::string b_title;
		std::string b_country;
		std::size_t b_year;
		double b_price;
		std::string b_desc;

	public:
		Book();
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend ostream& operator<<(ostream&, const Book&);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(book_desc);
		}
	};
}

#endif //SDDS_BOOK_H