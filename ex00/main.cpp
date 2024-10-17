#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swapped a and b!\n"<< "a = " << a << ", b = " << b << std::endl;
	std::cout << "minimum( a, b ) = " << ::minimum( a, b ) << std::endl;
	std::cout << "maximum( a, b ) = " << ::maximum( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	//std::string d = "chaine";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swapped c and d!\n"<< "c = " << c << ", d = " << d << std::endl;
	std::cout << "minimum( c, d ) = " << ::minimum( c, d ) << std::endl;
	std::cout << "maximum( c, d ) = " << ::maximum( c, d ) << std::endl;

}