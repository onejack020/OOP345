

/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 07/02/2021
Workshop 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
#include <iostream>
#include "Set.h"

namespace sdds {
	template<int N, typename T>

	class SetSummable : public Set<N, T> {

	public:
		T accumulate(const std::string& filter) const {

			T accumulator(filter);
			std::string obj;

			for (size_t i = 0u; i < this->size(); ++i) {
				obj = this->get(i).key();

				if (obj == filter) {
					accumulator += this->get(i);
				}
			}

			return accumulator;
		}
	};
}

#endif //SDDS_SETSUMMABLE_H
