//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================


#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		
		Vehicle* temp = nullptr;
		std::string str;
		std::stringstream ss;
		
		std::getline(in, str);
		
		if (!str.empty()) {
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);

			ss << str;

			if (ss.str().at(0) == 'c' || ss.str().at(0) == 'C') {
				temp = new Car(ss);
			}
			else if (ss.str().at(0) == 'r' || ss.str().at(0) == 'R') {
				temp = new Racecar(ss);
			}
			else
				throw std::string("Unrecognized record type: [") + ss.str().at(0) + ("]");
		}
		else
			return nullptr;
		return temp;
	}
	
	std::string& trim(std::string& str) {
		bool valid = true;
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);

		while (valid){

			if (str.find("  ") != std::string::npos) {
				str.erase(str.find("  "), 1);
				valid = true;
			}
			else if (str.find(" ,") != std::string::npos) {
				str.replace(str.find(" ,"), str.size(), ",");
				valid = true;
			}
			else
				valid = false;
		}

		return str;
	}
	
	bool isNumber(std::string str) {
		for (size_t i = 0; i < str.length(); i++)
			if (isdigit(str[i]) == false)
				return false;

		return true;
	}
}

