/*Name: singh Azorawar
ID : 138497193
Email : sazorawar@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds 
{



	ConfirmationSender::ConfirmationSender()
		: reserv{ nullptr }
		, count{ 0 }
	{
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& rs) noexcept
	{
		count = rs.count;
		//delete
		delete[] reserv;
		//set to nullptr
		reserv = nullptr;
		reserv = new const Reservation * [rs.count + 1];

		//for loop
		for (auto i = 0u; i < rs.count; i++)
		{
			//set reserve with the fucntion argument
			reserv[i] = rs.reserv[i];

		}
	}


	ConfirmationSender::ConfirmationSender(ConfirmationSender&& rs) noexcept
	{

		*this = std::move(rs);

	}


	


	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res)noexcept
	{
		//if loop
		if (res.reserv != nullptr)
		{
			//delete reserv
			delete[] reserv;
			//set reserv to nullptr
			reserv = nullptr;

			reserv = new const Reservation * [count + 1];

			//for loop
			for (auto j = 0u; j < res.count; j++)
			{
				reserv[j] = res.reserv[j];
			}

			count = res.count;
		}

		return *this;
	}


	//decontructor
	ConfirmationSender::~ConfirmationSender()
	{
		//delete reserve
		delete[] reserv;
		//set it to nullptr
		reserv = { nullptr };
	}


	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res) noexcept
	{
		if (this != &res)
		{

			this->reserv = res.reserv;
			count = res.count;

			res.reserv = { nullptr };
			res.count = { 0 };
		}


		return *this;
	}


	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		const Reservation** temp = nullptr;
		bool found = false;

		for (auto j = 0u; j < count; j++)
		{
			if (reserv[j] == &res)
			{
				found = true;
				j= count;
			}

		}

		if (!found)
		{

			temp = new const Reservation * [count + 1];

			for (auto i = 0u; i < count; i++)
			{
				temp[i] = reserv[i];
			}

			temp[count] = &res;
			//increment count
			++count;
			//delete reserv
			delete[] reserv;
			//and set it to temp
			reserv = temp;

		}



		return *this;
	}



	


	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& rs)
	{
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (rs.reserv == nullptr) {
			os << "There are no confirmations to send!\n--------------------------\n";
		}
		else {
			for (auto i = 0u; i < rs.count; i++)
			{
				if (rs.reserv[i] != nullptr)
					os << *rs.reserv[i];
			}
			os << "--------------------------\n";

		}



		return os;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		//set found to false
		bool found = false;
		for (auto i = 0u; i < count; i++)
		{
			if (reserv[i] == &res)
			{
				//set reserve to nullptr

				reserv[i] = nullptr;
			}
		}


		if (found)
		{
			//set detected to false
			bool detected = false;

			const Reservation** temp = nullptr;
			temp = new const Reservation * [count - 1];

			for (auto j = 0u; j < count; j++)
			{
				if (reserv[j] != nullptr && !detected)
				{
					temp[j] = reserv[j];
				}

				else if (detected)
				{
					temp[j - 1] = reserv[j];
				}

				else
				{
					//set detected to true
					detected = true;
				}
			}
			//decrement count
			count--;
			//set reserv to temp
			reserv = temp;
			//and then set temp tp nullptr
			temp = nullptr;
		}


		return *this;

	}


}