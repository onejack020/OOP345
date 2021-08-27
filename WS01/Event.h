



#ifndef EVENT_H
#define EVENT_H

extern unsigned int g_sysClock;

namespace sdds {

	class Event {
		char* evnt_desc;             // representing event description
		unsigned int s_midnight;                // seconds from midnight

	public:

		Event();                                   //default constructor
		Event(const Event&);                      //copy constructor
		void display();                           //displays content of event  
		~Event();                                //destructor
		void set(const char* array = nullptr);            //a modifier
		Event& operator=(const Event&);           //copy assignment operator
	};
}

#endif