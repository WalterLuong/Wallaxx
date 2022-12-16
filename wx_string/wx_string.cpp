#include "wx_string.hpp"

wx::string::string( void ) {}
wx::string::string( const wx::string & str ) : std::string(str) {}
wx::string::string( const std::string & str ) : std::string(str) {}
wx::string::string( const char *str ) : std::string(str) {}

wx::string::~string( void ) {}

std::ostream &operator<<( std::ostream &fd, const wx::string & str ) {
	fd << str;
	return fd;
}