/*Name: singh Azorawar
ID : 138497193
Email : sazorawar@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <string>
#include <iomanip>

#include <algorithm>
#include "Reservation.h"



namespace sdds	
{
	Reservation::Reservation()
		: Id{ "" }
		, Name{ "" }
		, Email{ "" }
		, numOfPeople{ 0 }
		, Day{ 0 }
		, hour{ 0 }
	{
	}

	Reservation::Reservation(const std::string& str)
	{
		std::string name{ str };
		size_t number = 0;

		
		size_t next_space = { name.find(' ') };
		if (next_space == 0) {
			while (name.find(' ') == 0) {
				next_space = { name.find(' ') };
				name.erase(number, next_space + 1);
			}
			next_space = { name.find(':') };
			if (next_space > 7) {
				next_space = { name.find(' ') };
			}
			Id = { name.substr(number, next_space) };
			name.erase(number, next_space);
		}

		else
		{
			if (next_space >= 7)
			{
				if (name.find(':') == 7)
				{
					next_space = { name.find(':') };
				}
			}
			else 
			{
				
				next_space = { name.find(':') };
			}

			Id = { name.substr(number, next_space) };
			
			name.erase(number, next_space);
		}


		
		next_space = { name.find(' ') };
		if (next_space <= 1) 
		{
			while (name.find(' ') == 0 || name.find(':') == 0)
			{
				if (name.find(' ') == 0)
				{
					
					name.erase(number, next_space + 1);
				}
				else if (name.find(':') == 0) {
					name.erase(number, next_space + 1);
				}
			}


			next_space = { name.find(' ') };
			if (next_space > 7 || name.find(',') >= 12) {
				if (next_space > 7) {
					next_space = { name.find(',') };
				}
				else {
					next_space = { name.find(',') - 4 };
				}
			}

			Name = { name.substr(number, next_space) };
			name.erase(number, next_space);
		}
		else {
			Name = { name.substr(number, next_space) };
			name.erase(number, next_space + 1);
		}


		


		next_space = 0;
		while (name.find(' ') == 0 || name.find(',') == 0)
		{
			if (name.find(' ') == 0) {
				name.erase(number, next_space + 1);
			}
			else if (name.find(',') == 0) {
				name.erase(number, next_space + 1);
			}
		}
		next_space = { name.find(' ') };
		if (next_space >= 17)
		{

			if (next_space >= 17) {
				next_space = { name.find(',') };
			}
		}
		Email = { name.substr(number, next_space) };
		name.erase(number, next_space);



		

		next_space = 0;
		while (name.find(' ') == 0 || name.find(',') == 0) 
		{
			if (name.find(' ') == 0)
			{

				name.erase(number, next_space + 1);
			}
			else if (name.find(',') == 0) {
				name.erase(number, next_space + 1);
			}
		}
		next_space = { name.find(' ') };
		if (next_space >= 2) {
			if (next_space >=2) {
				next_space = { name.find(',') };
			}
		}
		numOfPeople = std::stoi(name);
		name.erase(number, next_space);

		


		next_space = 0;
		while (name.find(' ') == 0 || name.find(',') == 0)
		{
			if (name.find(' ') == 0)
			{
				
				name.erase(number, next_space + 1);
			}
			else if (name.find(',') == 0) {
				name.erase(number, next_space + 1);
			}
		}

		next_space = { name.find(' ') };
		if (next_space >= 2) {
			if (next_space >= 2) {
				next_space = { name.find(',') };
			}
		}
		Day = std::stoi(name);
		name.erase(number, next_space);


		next_space = 0;
		while (name.find(' ') == 0 || name.find(',') == 0) {
			if (name.find(' ') == 0) {
				name.erase(number, next_space + 1);
			}
			else if (name.find(',') == 0) {
				name.erase(number, next_space + 1);
			}
		}
		next_space = { name.find(' ') };
		if (next_space >= 2) {
			if (next_space >= 2) {
				next_space = { name.find(',') };
			}
		}
		hour = std::stoi(name);
		name.erase(number, next_space);


	}


	void Reservation::display(std::ostream& os) const
	{	
		char ch = '>';
		std::string r_email = Email;

		r_email.push_back(ch);
		if (hour >= 6 && hour <= 9)
		{
			os << "Reservation ";
			os << std::setw(10) << std::right << Id << ":";
			os << std::setw(21) << std::right << Name << "  ";
			os << "<" << std::left << std::setw(23) << r_email;
			os <<"Breakfast on day ";
			os << Day;
			os << " @ ";
			os << hour << ":" << "00";
			os << " for " << numOfPeople;
		}
		else if(hour >= 11 && hour <= 15 ) {
			os << "Reservation ";
			os << std::setw(10) << std::right << Id << ":";
			os << std::setw(21) << std::right << Name << "  ";
			os << "<" << std::left << std::setw(23) << r_email;
			os << "Lunch on day ";
			os << Day;
			os << " @ ";
			os << hour << ":" << "00";
			os << " for " << numOfPeople;
		}
		else if (hour >= 17 && hour <= 21) {
			os << "Reservation ";
			os << std::setw(10) << std::right << Id << ":";
			os << std::setw(21) << std::right << Name << "  ";
			os << "<" << std::left << std::setw(23) << r_email;
			os << "Dinner on day ";
			os << Day;
			os << " @ ";
			os << hour << ":" << "00";
			os << " for " << numOfPeople;

		}
		else {
			os << "Reservation ";
			os << std::setw(10) << std::right << Id << ":";
			os << std::setw(21) << std::right << Name << "  ";
			os << "<" << std::left << std::setw(23) << r_email;
			os << "Drinks on day ";
			os << Day;
			os << " @ ";
			os << hour << ":" << "00";
			os << " for " << numOfPeople;
		}
		if (numOfPeople != 1)
		{
			os << " people." << std::endl;
		}
		else {
			os << " person." << std::endl;
		}
	}


	//constructor
	Reservation::~Reservation()
	{
	}
}

