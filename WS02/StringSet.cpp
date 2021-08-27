

/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 01/02/2021
Workshop 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#include "StringSet.h"
#include "TimedEvents.h"


namespace sdds {

	StringSet::StringSet() {

		no_strings = 0;
		r_strings = nullptr;
	}

	StringSet::StringSet(const char* filename) {

		no_strings = 0;
		std::string records;
		std::ifstream is(filename);
		
		while (!is.eof()) {
			getline(is, records, ' ');
			no_strings++;
		}

		is.clear();
		is.seekg(0);
		
		r_strings = new std::string[no_strings];

		for (unsigned int i = 0; i < no_strings; i++) {
			getline(is, r_strings[i], ' ');
		}

		is.close();
	}

	StringSet::StringSet(const StringSet& obj) { 
		*this = obj; 
	}

	StringSet& StringSet::operator=(const StringSet& str) {

		if (this != &str) {
			if (str.no_strings > 0) {
				r_strings = new std::string[str.no_strings];
				no_strings = str.no_strings;

				for (unsigned int i = 0; i < str.no_strings; i++) {
					r_strings[i] = str.r_strings[i];
				}
			}
		}

		return *this;
	}

	StringSet::~StringSet() {
		delete[] r_strings;
	}

	size_t StringSet::size() { 
		return no_strings;
	}


	std::string StringSet::operator[](size_t index) {	
		
		if (r_strings != nullptr && index <= no_strings) {
			return r_strings[index];
		}
		else {
			return "";
		}
	}

	StringSet::StringSet(StringSet&& str) {
		*this = std::move(str);
	}

	StringSet& StringSet::operator=(StringSet&& str) {

		if (this != &str) {
			no_strings = str.no_strings;
			r_strings = str.r_strings;
			str.no_strings = 0;
			str.r_strings = nullptr;
		}
		return *this;
	}
}
