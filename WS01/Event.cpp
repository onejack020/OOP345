
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Event.h"

using namespace std;

unsigned int g_sysClock = 0;

namespace sdds {

	Event::Event() {
		evnt_desc = nullptr;
		s_midnight = 0;
	}

	Event::Event(const Event& cpy) {

		evnt_desc = nullptr;
		*this = cpy;
	}


	Event::~Event() {

		delete[] evnt_desc;
		evnt_desc = nullptr;
	}

	void Event::display() {

		static int counter = 1;

		int hrs = s_midnight / 3600;
		int min = (s_midnight % 3600) / 60;
		int sec = (s_midnight % 3600) % 60;

		cout.width(2);
		cout.fill(' ');
		cout << counter << ". ";
		counter++;

		if (evnt_desc == nullptr) {

			cout << "| No Event |" << '\n';
		}
		else {

			cout.width(2);
			cout.fill('0');
		    cout << hrs << ":";

			cout.width(2);
			cout.fill('0');
			cout << min << ":";

			cout.width(2);
			cout.fill('0');
			cout << sec << " => " << evnt_desc << '\n';
		}
	}

	void Event::set(const char* array) {

		delete[] evnt_desc;
		evnt_desc = nullptr;

		if (array == nullptr || array[0] == '\0') {

			evnt_desc = nullptr;
			s_midnight = 0;
		}
		else {

			delete[] evnt_desc;
			evnt_desc = nullptr;

			evnt_desc = new char[strlen(array) + 1];
			strcpy(evnt_desc, array);
			s_midnight = ::g_sysClock;
		}
	}

	Event& Event::operator=(const Event& cpy) {

		if (this != &cpy) {

			if (cpy.evnt_desc != nullptr) {

				s_midnight = cpy.s_midnight;

				delete[] evnt_desc;
				evnt_desc = nullptr;

				evnt_desc = new char[strlen(cpy.evnt_desc) + 1];
				strcpy(evnt_desc, cpy.evnt_desc);
			}
			else {

				delete[] evnt_desc;
				evnt_desc = nullptr;

				s_midnight = 0;
			}
		}
		return *this;
	}
}
