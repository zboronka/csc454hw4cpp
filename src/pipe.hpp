#ifndef PIPE_HPP
#define PIPE_HPP

#include "port.hpp"

template <class T>
class Pipe {
	public:
		Port<T>* input;
		Port<T>* output;
		Pipe(Port<T>* input, Port<T>* output) { this->input = input; this->output = output; }
		bool pipe() { if(input->available()) { output->set(input->get()); return true; } return false; }
};

#endif
