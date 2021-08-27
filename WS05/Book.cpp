
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
#include "Book.h"

using namespace std;

namespace sdds {
	
	Book::Book() {
		string b_author{ "" };
		string b_title{ "" };
		string b_country{ "" }; 
		string b_year{ 0 }; 
		string b_price{ 0 }; 
		string b_desc{ "" };
	}

	const std::string& Book::title() const {
		return b_title;
	}

	const std::string& Book::country() const {
		return b_country;
	}

	const size_t& Book::year() const {
		return b_year;
	}

	double& Book::price() {
		return b_price;
	}
	
	void Book::spaceRemover(std::string& str){
		bool space = true;
		
		while (space){
			if (str[0] == ' '){
				str.erase(0, 1);
			}
			else if (str[str.length() - 1] == ' '){
				str.erase(str.length() - 1, str.length());
			}
			else{
				space = false;
			}
		}
	}

	Book::Book(const std::string& strBook){
		
		string templ = strBook;
		
		
		// author
		this->b_author = templ.substr(0, templ.find(',')); 
		this->spaceRemover(this->b_author);
		templ.erase(0, templ.find(',') + 1);


		// title
		this->b_title = templ.substr(0, templ.find(','));
		this->spaceRemover(this->b_title);
		templ.erase(0, templ.find(',') + 1);


		// country
		this->b_country = templ.substr(0, templ.find(','));
		this->spaceRemover(this->b_country);
		templ.erase(0, templ.find(',') + 1);


		// price
		this->b_price = std::stod(templ.substr(0, templ.find(',')));
		templ.erase(0, templ.find(',') + 1);


		// year
		this->b_year = std::stoi(templ.substr(0, templ.find(',')));
		templ.erase(0, templ.find(',') + 1);


		// description
		this->b_desc = templ;
		this->spaceRemover(this->b_desc);

	}

	std::ostream& operator<<(std::ostream& os, const Book& bk){
		os << std::setw(20) << bk.b_author << " | ";
		os << std::setw(22) << bk.b_title << " | ";
		os << std::setw(5) << bk.b_country << " | ";
		os << std::setw(4) << bk.b_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << bk.b_price << " | ";
		os << bk.b_desc << std::endl;
		return os;
	}
}