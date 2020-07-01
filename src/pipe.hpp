#ifndef PIPE_HPP
#define PIPE_HPP

#include "port.hpp"
#include "mooremachine.hpp"

template <class T>
class Pipe {
	public:
		Port<T>* input_port;
		Port<T>* output_port;
		MooreMachine* input_machine;
		MooreMachine* output_machine;

		Pipe(Port<T>* input_port, Port<T>* output_port, MooreMachine* input_machine, MooreMachine* out_machine) { 
			this->input_port = input_port;
			this->output_port = output_port;
			this->input_machine = input_machine;
			this->output_machine = output_machine;
		}
		bool pipe() {
			if(input_port->available()) {
				output_port->set(input_port->get());
				return true;
			} 
			return false;
		}
};

#endif
