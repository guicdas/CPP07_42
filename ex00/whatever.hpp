#pragma once

#include <iostream>

template < typename T >

T const &	maximum(T const & a1, T const & a2) {
	if (a1 <= a2)
		return (a2);
	return (a1);
}

template < typename T >
T const &	minimum(T const & a1, T const & a2){
	if (a1 < a2)
		return (a1);
	return (a2);
}

template < typename T >
void	swap(T & a1, T & a2){
	T temp = a1;
	a1 = a2;
	a2 = temp;
}