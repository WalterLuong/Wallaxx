#include "wx_string.hpp"

wx::string	wx::string::toLower( void ) {
	std::transform(this->begin(), this->end(), this->begin(), [](unsigned char c){ return std::tolower(c); });
	return *this;
}
