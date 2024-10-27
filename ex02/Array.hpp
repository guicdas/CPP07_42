#pragma once

#include <iostream>
#include <exception>
#include <ctime>
#include <stdlib.h>

template < typename A >
class Array{
	private:
		A				*Arr;
		unsigned int	aSize;

	public:
		Array( void ): Arr(NULL), aSize(0){};
		Array( unsigned int ): Arr(new A[size]), aSize(size){};
		Array(const Array & ): aSize(a.size())
		{
			std::cout << "Copy Constuctor created" << std::endl;
			this->Arr = NULL;
			*this = a;
		};
		Array& operator=( const Array<A> & ){
			std::cout << "Assignment operator called" << std::endl;
			if (this->Arr != NULL)
				delete [] this->Arr;
			if (a.size() != 0)
			{
				this->aSize = a.size();
				this->Arr = new A[this->aSize];
				for (int i = 0; i < this->size() ; i++)
					this->Arr[i] = a.Arr[i];
			}
			return (*this);
		};
		~Array( void ){
			std::cout << "Destroyed array of size " << this->aSize << std::endl;
			if (this->Arr != NULL)
				delete [] this->Arr;
		};

	int	size( void ) const{return (this->aSize);};
	
	A &operator[]( unsigned int )
	{
		if (i >= this->aSize || this->Arr == NULL)
			throw (OutOfBoundsException());
		return (this->Arr[i]);
	}

	class OutOfBoundsException : public std::exception
	{
		public:
				virtual const char *what() const throw(){return ("Error: Accessing invalid index!\n");};
	};
};
