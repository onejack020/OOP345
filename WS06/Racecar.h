//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#pragma once
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
	
	private:
		double m_booster;
	
	public:
		Racecar();
		~Racecar() {};
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}