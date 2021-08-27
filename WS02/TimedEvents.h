
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 01/02/2021
Workshop 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#pragma once

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

namespace sdds {

	const int MAX_EVENT = 10;

	class TimedEvents {

		int no_Records;
		std::chrono::steady_clock::time_point st_time;
		std::chrono::steady_clock::time_point ed_time;

		struct {
			std::string evnt_name{};
			std::string units_time{};
			std::chrono::steady_clock::duration duration{};
		}events[MAX_EVENT];

	public:
		TimedEvents();                          //default constructor
		void startClock();                     //start timer
		void stopClock();                     //end timer
		void addEvent(const char*);          //time recorder
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);        //friend helper function
	};
}

#endif //SDDS_TIMEDEVENTS_H