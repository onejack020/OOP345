//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#include <iostream>
#include <string>
#include <vector>
#include "Autoshop.h"

namespace sdds {
	Autoshop::~Autoshop() {
		for (auto& obj : m_vehicles) {
			delete obj;
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		
		for (auto& obj : m_vehicles) {
			obj->display(out);
			out << std::endl;
		}
		
		out << "--------------------------------" << std::endl;
	}
}
