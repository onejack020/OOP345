
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
//   and the content was created entirely by me.

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;


namespace sdds {
	
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() : m_name(""),
		m_product(""),
		m_cntItem(0),
		m_lstItem(nullptr)
	{}

	CustomerOrder::CustomerOrder(const std::string& ptr) {
		
		Utilities object;
		size_t next_pos = 0;
		bool more = true;
		
		m_cntItem = 0;

		try{
			m_name = object.extractToken(ptr, next_pos, more);
			m_product = object.extractToken(ptr, next_pos, more);

			size_t currentPos = next_pos;
			
			while (more){
				object.extractToken(ptr, currentPos, more);
				m_cntItem++;
			}

			m_lstItem = new Item * [m_cntItem];

			for (unsigned int i = 0; i < m_cntItem; i++){
				m_lstItem[i] = new Item(object.extractToken(ptr, next_pos, more));
			}

			m_widthField = max(object.getFieldWidth(), m_widthField);
		}
		catch (string& exp){
			cout << exp;
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& prm) noexcept {
		m_name = prm.m_name;
		m_product = prm.m_product;
		m_cntItem = prm.m_cntItem;
		m_lstItem = prm.m_lstItem;

		prm.m_name = "";
		prm.m_product = "";
		prm.m_cntItem = 0;
		prm.m_lstItem = nullptr;
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& prm) noexcept {
		
		if (this != &prm){
			clear();

			m_name = prm.m_name;
			m_product = prm.m_product;
			m_cntItem = prm.m_cntItem;
			m_lstItem = prm.m_lstItem;

			prm.m_name = "";
			prm.m_product = "";
			prm.m_cntItem = 0;
			prm.m_lstItem = nullptr;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		clear();
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
				return false;
			}
		}

		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i ++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				return m_lstItem[i]->m_isFilled;
			}
		}

		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		
		for (size_t i = 0; i < m_cntItem; i++){
			
			if (m_lstItem[i]->m_itemName == station.getItemName()){
				
				if (station.getQuantity() > 0){
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;

					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else{
					os << "    Unable to fill NAME, PRODUCT " << m_lstItem[i]->m_itemName << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]"
			   << " " << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName
			   << " - " <<  (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
		}
	}

	void CustomerOrder::clear() {
		if (m_lstItem != nullptr){
			for (size_t i = 0; i < m_cntItem; i++){
				delete m_lstItem[i];
			}

			delete[] m_lstItem;
		}
	}
}
