
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
// and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <vector>

#include "Workstation.h"

namespace sdds {

	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder = 0;
		Workstation* m_firstStation = nullptr;
	
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif//LINEMANAGER_H