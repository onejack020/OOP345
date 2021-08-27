
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 07/02/2021
Workshop 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <cstring>
#include <iostream>

namespace sdds {

	template<int N, typename T>

	class Set {
		T array[N];
		size_t noOfElm{ 0 };

	public:

		size_t size() const {
			return noOfElm;
		}

		const T& get(size_t idx) const {
			return array[idx];
		}

		void operator+=(const T& item) {
			
			if (noOfElm < N) {
				array[noOfElm] = item;
				noOfElm++;
			}
		}
	};
}

#endif //SDDS_SET_H_