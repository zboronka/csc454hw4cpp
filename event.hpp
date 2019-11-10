#ifndef EVENT_HPP
#define EVENT_HPP

#include "totaltime.hpp"
#include "vendingmachine.hpp"
#include "colors.hpp"

enum Delta { EXT, INT, CON };

class VendingMachine;
class Event {
	public:
		TotalTime* time;
		VendingMachine* target;
		Delta delta;
		char input = 0;
		Event(Delta, TotalTime*, VendingMachine*);
		Event(Delta, TotalTime*, VendingMachine*, char); 

		friend bool operator<(Event const&, Event const&); 
		friend bool operator==(Event const&, Event const&);
		friend std::ostream& operator<<(std::ostream&, Event const&);
};

#endif
