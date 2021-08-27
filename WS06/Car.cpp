//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Car.h"

namespace sdds {
	
	Car::Car() {
		m_maker = {};
		m_cond = {};
		m_speed = 0.0;
	}
	
	Car::Car(std::istream& in) : m_speed(0.0) {
		std::string str;
		std::string tag, maker, cond, speed;
		
		getline(in, tag, ',');
		getline(in, maker, ',');
		getline(in, cond, ',');
		getline(in, speed, ',');
		
		trim(maker);
		trim(cond);
		trim(speed);

		m_maker = maker;

		if (cond.empty()) {
			cond = "n";
			m_cond = Condition(cond[0]);
		}
		else if (cond[0] != 'n' && cond[0] != 'u' && cond[0] != 'b') {
			throw std::string("Invalid record!");
		}
		else
			m_cond = Condition(cond[0]);

		if (isNumber(speed)) {
			m_speed = std::stod(speed);
		}
		else
			throw std::string("Invalid record!");
	}
	
	std::string Car::condition() const {
		std::string Cond;

		if (m_cond == Condition::New) {
			Cond = "new";
		}
		else if (m_cond == Condition::Used) {
			Cond = "used";
		}
		else if (m_cond == Condition::Broken) {
			Cond = "broken";
		}

		return Cond;
	}
	
	double Car::topSpeed() const {
		return m_speed;
	}
	
	void Car::display(std::ostream& out) const {
		out << "| " << std::right << std::setw(10) << m_maker
			<< " | " << std::left << std::setw(6) << condition() << " | "
			<< std::setw(6) << std::setprecision(2) << std::fixed
			<< topSpeed() << " |";
	}
}