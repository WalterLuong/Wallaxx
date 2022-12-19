#include "wx_string.hpp"

wx::string	wx::string::cut( wx::string const &cut ) {
	for ( char c : cut )
		this->erase( std::remove(this->begin(), this->end(), c), this->end());
	return *this;
}
