
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 01/02/2021
Workshop 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		no_Records = 0;
		st_time = {};
		ed_time = {};
		}

	void TimedEvents::startClock() {
		st_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		ed_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* evnt) {
		auto length = std::chrono::duration_cast<std::chrono::nanoseconds>(ed_time - st_time);

		if (no_Records < MAX_EVENT) {
			
			this->events[no_Records].evnt_name = evnt;
			this->events[no_Records].units_time = "nanoseconds";
			this->events[no_Records].duration = length;
			
			no_Records++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& event) {

		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		
		for (int i = 0; i < event.no_Records; i++) {

			os << std::setw(21) << std::left << event.events[i].evnt_name << ' ' << std::setw(13) << std::right << event.events[i].duration.count() << ' ' << event.events[i].units_time << std::endl;
		}

		os << "--------------------------" << std::endl;
		return os;
	}
}

