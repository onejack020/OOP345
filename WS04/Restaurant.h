/*Name: singh Azorawar
ID : 138497193
Email : sazorawar@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"

namespace sdds 
{
	class Restaurant
	{

		size_t num_rest;

		Reservation* reservation{ nullptr };
		

	public:


		Restaurant(Restaurant&& reservation) noexcept;
		Restaurant(Restaurant& reservation) noexcept;


		//decontructor
		~Restaurant();

		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant& operator=(Restaurant& res) noexcept;

		Restaurant& operator=(Restaurant&& res) noexcept;


		
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif
