#include "event.hpp"

Event::Event(Delta delta, TotalTime* time, VendingMachine* target) {
	this->delta = delta;
	this->time = time;
	this->target = target;
}

Event::Event(Delta delta, TotalTime* time, VendingMachine* target, char input) {
	this->delta = delta;
	this->time = time;
	this->target = target;
	this->input = input;
}

bool Event::compare(Event const& a, Event const& b) {
	return *a.time == *b.time ? a.delta > b.delta : *a.time > *b.time;
}

bool operator==(Event const& a, Event const& b) {
	return *a.time == *b.time && a.delta == b.delta;
}

std::ostream& operator<<(std::ostream& strm, Event const& a) {
	switch(a.delta) {
		case EXT:
			strm << EXTCOLOR << "EXT";
			break;
		case INT:
			strm << INTCOLOR << "INT";
			break;
		case CON:
			strm << CONCOLOR << "CON";
		default:
			break;
	}
	strm << RESET;
	strm << endl << "Current time: " << *a.time;
	strm << endl << "TARGET " << a.target;
	return strm;
}
