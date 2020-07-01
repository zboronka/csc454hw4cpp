#include "mooremachine.hpp"

std::ostream& operator<<(std::ostream& strm, MooreMachine const& m) {
	return strm << m.insertion();
}
