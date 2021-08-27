
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
//   and the content was created entirely by me.

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;


	Station::Station(std::string ptr) {
		Utilities object;
		size_t next_pos = 0;
		bool more = true;

		try {
			itemName = object.extractToken(ptr, next_pos, more);
			m_widthField = max(m_widthField, object.getFieldWidth());
			nextSerialNum = stoi(object.extractToken(ptr, next_pos, more));
			stockItems = stoi(object.extractToken(ptr, next_pos, more));
			stationDesc = object.extractToken(ptr, next_pos, more);
		}
		catch (string& exp) {
			cout << exp;
		}

		stationID = ++id_generator;
	}

	const std::string& Station::getItemName() const {
		return itemName;
	}

	unsigned int Station::getNextSerialNumber() {
		return nextSerialNum++;
	}

	unsigned int Station::getQuantity() const {
		return stockItems;
	}

	void Station::updateQuantity() {
		if (stockItems > 0) {
			stockItems--;
		}
	}

	void Station::display(std::ostream& os, bool full) const {

		os << right << "[" << setw(3) << setfill('0') << stationID << "]";
		os << left << " Item: " << setw(m_widthField) << setfill(' ') << itemName;
		os << right << " [" << setw(6) << setfill('0') << nextSerialNum << "]";

		if (full == true) {
			os << left << " Quantity: " << setw(m_widthField) << setfill(' ') << stockItems;
			os << " Description: " << stationDesc;
		}
		os << endl;
	}
}