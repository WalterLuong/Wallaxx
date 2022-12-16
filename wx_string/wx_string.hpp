#ifndef STRING_BASIC_HPP
# define STRING_BASIC_HPP

#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>

namespace wx
{
	class string : public std::string {
	public:
		string( void );
		string( const string & str );
		string( const std::string & str );
		string( const char *str );
		~string( void );

		string	toUpper( void );
		string	toLower( void );
	};


}

std::ostream &operator<<( std::ostream &fd, const wx::string &str );



#endif