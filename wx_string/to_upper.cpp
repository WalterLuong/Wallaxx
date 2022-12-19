#include "wx_string.hpp"

wx::string	wx::string::toUpper( void ) {
	std::transform(this->begin(), this->end(), this->begin(), [](unsigned char c){ return std::toupper(c); });
	return *this;
}
