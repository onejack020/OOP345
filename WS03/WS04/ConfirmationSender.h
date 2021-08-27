


#ifndef CONFIRMATION_SENDER_H
#define CONFIRMATION_SENDER_H

#include "Reservation.h"
namespace sdds 
{
	class ConfirmationSender
	{
	

		const sdds::Reservation** reserv{ nullptr };

        size_t count;
		
	//public below
	public:

		//constructor
		ConfirmationSender();
		//decontructor
		~ConfirmationSender();

		ConfirmationSender(const ConfirmationSender& rs) noexcept;
		ConfirmationSender(ConfirmationSender&& rs) noexcept;

		
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender& operator=(const ConfirmationSender& res) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& res) noexcept;
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& rs);
	};
}
#endif


