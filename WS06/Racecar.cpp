//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar() {
		m_booster = 0.0;
	}
	
	Racecar::Racecar(std::istream& in) : Car(in) {
		in >> m_booster;
	}
	
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
	
	double Racecar::topSpeed() const {
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}