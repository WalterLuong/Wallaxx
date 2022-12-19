#ifndef STRING_BASIC_HPP
# define STRING_BASIC_HPP

#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

namespace wx
{
	typedef struct s_token t_token;
	struct s_token {
		std::string value;
		int type;
	};

	class string : public std::string {
	public:
		string( void );
		string( const string & str );
		string( const std::string & str );
		string( const char *str );
		virtual ~string( void );

		string &operator=( string const & str );

		// --------------------------------- //
		//    Modification sur la string     //
		// --------------------------------- //
		string	toUpper( void );
		string	toLower( void );

		string  cut( const string & cut ); // Delete tout les char contenu dans cut


	};

	std::vector<t_token> tokenizer( string, string* );

}

std::ostream &operator<<( std::ostream &fd, const wx::string &str );



#endif