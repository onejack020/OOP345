
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
// and the content was created entirely by me.

#include "Workstation.h"
#include "Station.h"

using namespace std;

namespace sdds {

	std::deque<CustomerOrder> pending, completed, incomplete;

	Workstation::Workstation(const std::string& ptr) : Station(ptr) {}

	void Workstation::fill(std::ostream& os) {
		while (!m_orders.empty() && !m_orders.front().isItemFilled(Station::getItemName()) 
			&& Station::getQuantity() > 0) {
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {
		if (m_orders.empty()) {
			return false;
		}

		if (m_orders.front().isItemFilled(Station::getItemName())) {
			if (m_orders.front().isFilled()) {
				completed.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				return true;
			}
			else if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				m_orders.pop_front();
				return true;
			}
			else {
				return false;
			}
		}
		else if (Station::getQuantity() == 0) {
			incomplete.push_back(std::move(m_orders.front()));
			m_orders.pop_front();
			return true;
		}
		return false;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	const Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << Station::getItemName() << " --> ";
		if (m_pNextStation != nullptr) {
			os << m_pNextStation->getItemName();
		}
		else {
			os << "End of Line";
		}
		os << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
} 
