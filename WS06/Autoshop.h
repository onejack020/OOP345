#pragma once
//==============================================
// Name:           Md Rafi Al Arabi Bhuiyan
// Student Number: 147307193
// Email:          mraabhuiyan@myseneca.ca
// Date:           17/03/2021
//==============================================

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {

	private:
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};
	
	template<typename T>
	inline void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
		for (auto& obj : m_vehicles) {
			if (test(obj)) {
				vehicles.push_back(obj);
			}
		}
	}
}