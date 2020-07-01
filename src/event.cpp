#include "event.hpp"

Event::Event(Delta delta, TotalTime time, MooreMachine* target) {
	this->delta = delta;
	this->time = time;
	this->target = target;
}

Event::Event(Delta delta, TotalTime time, MooreMachine* target, char input) {
	this->delta = delta;
	this->time = time;
	this->target = target;
	this->input = input;
}

bool Event::compare(Event const& a, Event const& b) {
	return a.time == b.time ? a.delta > b.delta : a.time > b.time;
}

bool operator==(Event const& a, Event const& b) {
	return a.time == b.time && a.delta == b.delta;
}

std::ostream& operator<<(std::ostream& strm, Event const& a) {
	switch(a.delta) {
		case EXT:
			strm << colors::EXTCOLOR << "EXT";
			break;
		case INT:
			strm << colors::INTCOLOR << "INT";
			break;
		case CON:
			strm << colors::CONCOLOR << "CON";
		default:
			break;
	}
	strm << colors::RESET;
	strm << std::endl << "Current time: " << a.time;
	strm << std::endl << "TARGET " << a.target;
	return strm;
}
