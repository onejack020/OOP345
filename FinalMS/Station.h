
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {

	class Station {
		int stationID;
		std::string itemName;
		std::string stationDesc;
		int nextSerialNum;
		int stockItems;

		static size_t m_widthField;
		static int id_generator;

	public:
		Station(std::string);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif//SDDS_STATION_H