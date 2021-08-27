/*Name: singh Azorawar
ID : 138497193
Email : sazorawar@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds{
	
	Restaurant::Restaurant(Restaurant& reservation) noexcept{
		*this = reservation;
	}


	Restaurant::Restaurant(Restaurant&& reservation) noexcept{
		*this = move(reservation);
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
		this->num_rest = cnt;
		this->reservation = new Reservation[cnt];

		for (auto j = 0u; j < cnt; j++){
			reservation[j] = *reservations[j];
		}
	}

	Restaurant& Restaurant::operator=(Restaurant& res) noexcept{
		
		if (reservation != res.reservation){
			
			delete[] reservation;
			reservation = nullptr;

			num_rest = res.num_rest;
			this->reservation = new Reservation[num_rest];

			for (auto i = 0u; i < num_rest; i++){
				reservation[i] = res.reservation[i];
			}
		}
		else{

			for (auto i = 0u; i < res.num_rest; i++){
				res.reservation[i] = reservation[i];
			}
		}
		return *this;
	}


	Restaurant& Restaurant::operator=(Restaurant&& res) noexcept{
		if (this != &res) {
			delete[] this->reservation;
			this->reservation = res.reservation;
			this->num_rest = res.num_rest;
			res.reservation = nullptr;
		}
		return *this;
	}
	
	size_t Restaurant::size() const{
		return this->num_rest;
	}


	std::ostream& operator<<(std::ostream& os, const Restaurant& res){
		static int number = 0;
		os << "--------------------------\nFancy Restaurant" << " (" << ++number << ")" << "\n--------------------------\n";
		if (res.reservation == nullptr || res.num_rest == 0){
			os << "This restaurant is empty!\n--------------------------\n";
		}
		else {
			for (auto i = 0u; i < res.num_rest; i++){
				os << res.reservation[i];
			}

			os << "--------------------------\n";
		}
		return os;
	}

	Restaurant::~Restaurant(){
		if (this->reservation != nullptr){
			delete[] reservation;
			reservation = nullptr;
		}
	}
}