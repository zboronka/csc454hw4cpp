#include "port.hpp"
#include "pipe.hpp"
#include "totaltime.hpp"
#include "vendingmachine.hpp"
#include "event.hpp"
#include "colors.hpp"

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main() {
	VendingMachine* v = new VendingMachine(0,0,0,0);
	v->input = new Port<char>();
	v->output = new Port<string>();

	vector<Event>* pqueue = new vector<Event>();

	regex input("\\((\\d*\\.\\d*|\\d*),(q|d|n)\\)");
	smatch matches;
	string command;
	for(cin >> command; command != "run"; cin >> command) {
		auto words_begin = sregex_iterator(command.begin(), command.end(), input);
		auto words_end = sregex_iterator();
		for(sregex_iterator i = words_begin; i != words_end; i++) {
			pqueue->push_back(Event(EXT, TotalTime(atof((*i)[1].str().c_str()), 0), v, (*i)[2].str().c_str()[0]));
			make_heap(pqueue->begin(), pqueue->end(), Event::compare);
		}
	}

	while(!pqueue->empty()) {
		Event e = pqueue->front();
		pqueue->erase(pqueue->begin());
		make_heap(pqueue->begin(), pqueue->end(), Event::compare);
		if(e.input != 0) {
			v->input->set(e.input);
			cout << colors::INPUT << "INPUT" << colors::RESET << endl;
			cout << e.input << endl;
		}

		if(!pqueue->empty() && e.time == pqueue->front().time) {
			pqueue->erase(pqueue->begin());
			pqueue->push_back(Event(CON, e.time.advance(0.0), e.target, e.input));
			make_heap(pqueue->begin(), pqueue->end(), Event::compare);
			continue;
		}

		try {
			switch(e.delta) {
				case EXT:
					e.target->deltaext(0);
					if(e.target->internal) {
						for(auto i = pqueue->begin(); i < pqueue->end(); i++) {
							if(*e.target->internal==*i) {
								pqueue->erase(i);
								make_heap(pqueue->begin(), pqueue->end(), Event::compare);
							}
						}
					}
					break;
				case INT:
					e.target->lambda();
					e.target->deltaint();
					break;
				case CON:
					e.target->lambda();
					e.target->deltacon();
				default:
					break;
			}
		} catch (const char* msg) {
			cerr << msg << endl;
			break;
		}

		if(e.target->ta() > 0) {
			if(e.target->internal) {
				delete e.target->internal;
			}
			e.target->internal = new Event(INT, e.time.advance(e.target->ta()), e.target);
			pqueue->push_back(*e.target->internal);
			make_heap(pqueue->begin(), pqueue->end(), Event::compare);
		}

		cout << e << endl;

		if(v->output->available()) {
			cout << *e.target << endl;
		}

		cout << endl;
	}

	delete pqueue;
	delete v->internal;
	delete v;
}
