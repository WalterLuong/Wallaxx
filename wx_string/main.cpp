#include "wx_string.hpp"

int main( void ) {

	wx::string str = std::string("Je S'appelle Grout!");
	std::cout << "Lower: " << str.toLower() << std::endl;
	std::cout << "Upper: " << str.toUpper() << std::endl;

	std::cout << str.length() << std::endl;

	return 0;
}