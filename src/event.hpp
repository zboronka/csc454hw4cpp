#ifndef EVENT_HPP
#define EVENT_HPP

#include "totaltime.hpp"
#include "mooremachine.hpp"
#include "colors.hpp"

enum Delta { EXT, INT, CON };

class MooreMachine;
class Event {
	public:
		TotalTime time = TotalTime(0,0);
		MooreMachine* target;
		Delta delta;
		char input = 0;
		Event(Delta, TotalTime, MooreMachine*);
		Event(Delta, TotalTime, MooreMachine*, char); 

		static bool compare(Event const&, Event const&);
		friend bool operator==(Event const&, Event const&);
		friend std::ostream& operator<<(std::ostream&, Event const&);
};

#endif
