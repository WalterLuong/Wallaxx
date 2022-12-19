#include "wx_string.hpp"

wx::string::string( void ) : std::string() {}
wx::string::string( const wx::string & str ) : std::string(str) {}
wx::string::string( const std::string & str ) : std::string(str) {}
wx::string::string( const char *str ) : std::string(str) {}

wx::string::~string( void ) {}

std::ostream &operator<<( std::ostream &fd, const wx::string & str ) {
	fd << std::string(str);
	return fd;
}

// int main( void ) {

// 	wx::string str = std::string("Je S'appelle Grout!");
// 	std::cout << str << std::endl;
// 	std::cout << "Lower: " << str.toLower() << std::endl;
// 	std::cout << "Upper: " << str.toUpper() << std::endl;
// 	std::cout << "Cut  : " << str.cut(" '") << std::endl;
	
// 	std::cout << str.length() << std::endl;

// 	return 0;
// }