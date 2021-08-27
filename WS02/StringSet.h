
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 01/02/2021
Workshop 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#pragma once

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

namespace sdds {
	
	class StringSet {

		unsigned int no_strings;                 
		std::string* r_strings = nullptr;           

	public:
		StringSet();                           //default constructor
		StringSet(const char*);                //1-argument constructor
		StringSet(const StringSet&);             // copy constructor
		StringSet& operator=(const StringSet&);  //copy assignment operator
		~StringSet();                           //destructor
		size_t size();                         //return number of strings
		std::string operator[](size_t);        
		StringSet(StringSet&&);                //move constructor
		StringSet& operator=(StringSet&&);     //move operator
	};

}

#endif //SDDS_STRINGSET_H