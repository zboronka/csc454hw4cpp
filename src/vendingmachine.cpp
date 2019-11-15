#include "vendingmachine.hpp"

VendingMachine::VendingMachine(int quarters, int dimes, int nickels, int value) {
	this->quarters = quarters;
	this->dimes = dimes;
	this->nickels = nickels;
	this->value = value;
}

void VendingMachine::lambda() {
	string ret = "";

	ret += getChange(value % 100);

	for(int i = 0; i < value / 100; i++) {
		ret += "<coffee>";
	}

	output->set(ret);
}

void VendingMachine::deltaint() {
	string changeString = getChange(value);

	for(auto c = changeString.begin(); c < changeString.end(); c++) {
		switch(*c) {
			case 'q':
				quarters--;
				break;
			case 'd':
				dimes--;
				break;
			case 'n':
				nickels--;
				break;
			default:
				break;
		}
	}

	value = 0;
}

void VendingMachine::deltaext(double e) {
	switch(input->get()) {
		case 'q':
			quarters++;
			value+=25;
			break;
		case 'd':
			dimes++;
			value+=10;
			break;
		case 'n':
			nickels++;
			value+=5;
			break;
		default:
			break;
	}
}

void VendingMachine::deltacon() {
	switch(input->get()) {
		case 'q':
			quarters++;
			value=25;
			break;
		case 'd':
			dimes++;
			value=10;
			break;
		case 'n':
			nickels++;
			value=5;
			break;
		default:
			break;
	}

	string changeString = getChange(value);

	for(auto c = changeString.begin(); c < changeString.end(); c++) {
		switch(*c) {
			case 'q':
				quarters--;
				break;
			case 'd':
				dimes--;
				break;
			case 'n':
				nickels--;
				break;
			default:
				break;
		}
	}
}

string VendingMachine::getChange(int v) {
	string ret = "";

	int q = v / 25 > quarters ? quarters : v / 25;
	int d = (v-q*25) / 10 > dimes ? dimes : (v-q*25) / 10;
	int n = ((v-q*25)-d*10) / 5 > nickels ? nickels : ((v-q*25)-d*10) / 5;
	
	if(q*25 + d*10 + n*5 != v) {
		throw "Not enough change in machine";
	}

	for(int i = 0; i < q; i++) {
		ret += "q";
	}
	for(int i = 0; i < d; i++) {
		ret += "d";
	}
	for(int i = 0; i < n; i++) {
		ret += "n";
	}

	return ret;
}

ostream& operator<<(ostream& strm, VendingMachine const& a) {
	strm << OUTPUT << "OUTPUT" << RESET << endl;
	strm << a.output->get();
	return strm;
}
