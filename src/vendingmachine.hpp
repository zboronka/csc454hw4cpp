#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

#include <string>

#include "port.hpp"
#include "event.hpp"

using namespace std;

class Event;
class VendingMachine {
	private:
		int quarters;
		int dimes;
		int nickels;

		int value;

		string getChange(int v);
	public:
		Port<char>* input;
		Port<string>* output;
		Event* internal;

		VendingMachine(int, int, int, int);
		~VendingMachine() { delete input; delete output; }

		double ta() { return value > 0 ? 2 : -1; }

		void lambda();
		void deltaint();
		void deltaext(double);
		void deltacon();

		friend ostream& operator<<(ostream&, VendingMachine const&);
};

#endif
