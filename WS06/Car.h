#pragma once
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#include "Vehicle.h"

namespace sdds {

	enum class Condition : char {
		New = 'n',
		Used = 'u',
		Broken = 'b'
	};

	class Car : public Vehicle {
	
	private:
		std::string m_maker;
		Condition m_cond;
		double m_speed;
	
	public:
		Car();
		~Car() {};
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}