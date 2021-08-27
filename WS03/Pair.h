/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 07/02/2021
Workshop 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <cstring>
#include <iostream>

namespace sdds {

	template<typename V, typename K>

	class Pair {
		
		V values;
		K keys;

	public:
		Pair() {};

		Pair(const K& key, const V& value) {
			
			keys = key;
			values = value;
		}

		const V& value() const {
			return values;
		}

		const K& key() const {
			return keys;
		}

		virtual void display(std::ostream& os) const {

			os << this->keys;
			os << " : " << this->values << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}
	};
}

#endif //SDDS_PAIR_H