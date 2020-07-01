#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

#include <string>

#include "mooremachine.hpp"
#include "port.hpp"
#include "event.hpp"

class Event;
class VendingMachine: public MooreMachine {
	private:
		int quarters;
		int dimes;
		int nickels;

		int value;

		std::string getChange(int v);
	public:
		Port<char>* input;
		Port<std::string>* output;

		VendingMachine(int, int, int, int);
		~VendingMachine() { delete input; delete output; }

		double ta() { return value > 0 ? 2 : -1; }

		void lambda();
		void deltaint();
		void deltaext(double);
		void deltacon();

		std::string insertion() const;
};

#endif
