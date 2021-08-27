
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 07/02/2021
Workshop 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_PAIRSUMMABLE_H_
#define SDDS_PAIRSUMMABLE_H_
#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds {

	template<typename V, typename K>
	
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t minWidth;

	public:
		PairSummable() {};

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value){
			if (minWidth < key.size()) {
				minWidth = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const {

			bool is = false;
			if (this->key() == b.key) {
				is = true;
			}
			else {
				is = false;
			}

			return is;
		}

		PairSummable& operator+=(const PairSummable& src) {
			
			if (this->key() == src.key() && this != &src) {
				*this = PairSummable(Pair<V, K>::key(), Pair<V, K>::value() + src.value());
			}

			return *this;
		}

		void display(std::ostream& os) const {
			os << std::left;
			os << std::setw(minWidth);

			Pair<V,K>::display(os);

			os << std::right;
		}
	};

	template<typename V, typename K>

	size_t PairSummable<V, K>::minWidth{ 0 };

	template<>
	std::string PairSummable<std::string, std::string>::initial = "";

	template<>
	int PairSummable<int, std::string>::initial = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src) {

		if (this != &src && Pair<std::string, std::string>::key() == src.key())

			*this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() == "" ? src.value() : Pair<std::string, std::string>::value() + ", " + src.value());

		return *this;
	}
}


#endif //SDDS_PAIRSUMMABLE_H_