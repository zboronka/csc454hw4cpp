#ifndef MOOREMACHINE_HPP
#define MOOREMACHINE_HPP

#include "event.hpp"

class Event;
class MooreMachine {
	public:
		Event* internal;
		int priority;

		virtual double ta() = 0;

		virtual void lambda() = 0;

		virtual void deltaint() = 0;
		virtual void deltaext(double) = 0;
		virtual void deltacon() = 0;
		virtual std::string insertion() const = 0;
		friend std::ostream& operator<<(std::ostream&, MooreMachine const&);
};

#endif
