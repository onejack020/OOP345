
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

#include "Station.h"
#include "Utilities.h"

namespace sdds {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);

		CustomerOrder(const CustomerOrder&) { throw "ERROR: No Copy operation!"; };
		CustomerOrder& operator=(const CustomerOrder&) = delete;

		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
		void clear();
	};
}

#endif//CUSTOMERORDER_H