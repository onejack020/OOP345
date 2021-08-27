
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
// and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <iostream>
#include <deque>

#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
	extern std::deque<CustomerOrder> pending, completed, incomplete;

	class Workstation: public Station{
		std::deque<CustomerOrder> m_orders;
		Workstation *m_pNextStation = nullptr;
	
	public:
		Workstation(const std::string& str);
		
		Workstation(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		Workstation& operator+=(CustomerOrder&& newOrder);
		
		void fill(std::ostream &os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation *station);
		const Workstation *getNextStation() const;
		void display(std::ostream &os) const;
	};
}


#endif//WORKSTATION_H