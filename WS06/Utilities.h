#pragma once
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================


#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string& trim(std::string& str);
	bool isNumber(std::string str);
}