/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wx_complex.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:36:36 by wluong            #+#    #+#             */
/*   Updated: 2022/12/21 04:10:42 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WX_COMPLEX_HPP
#define WX_COMPLEX_HPP

#include <iostream>
#include <string>
#include "math.h"

namespace	wx {

template <class T>
class Complex
{
	
	public:
		typedef T			value_type;

	private:
		
		value_type		_x;
		value_type		_y;

	public:
		
		/****************************
		****	CONSTRUCTORS	*****
		****************************/

		Complex( const T& re = T(), const T& im = T() ) : _x(re), _y(im) {};
		
		Complex( Complex const & src ) { this->_x = src._x; this->_y = src.y; };

		template <class U>
		Complex (Complex<U> const & x) { this->_x = x._x; this->_y = x._y; };

		~Complex() {};

		/****************************
		******GETTERS & SETTERS******
		****************************/

		value_type	imag() const { return this->_y; };
		void		imag(value_type val) { this->_y = val;};

		value_type	real() const { return this->_x;};
		void		real(value_type val) { this->_x = val;};

		/****************************
		*******	OPERATORS	*********
		****************************/

		Complex & operator= (const value_type& val) { this->_x = val, this->_y = 0; return *this; };

		Complex & operator+= (const value_type& val) { this->_x += val; return *this; };

		Complex & operator-= (const value_type& val) { this->_x -= val; return *this; };

		Complex& operator*= (const T& val) { this->_x *= val; this->_y *= val; return *this; };

		Complex& operator/= (const T& val) {
			if (val == 0)
				throw std::runtime_error("ERROR: Division by 0.");
			else {
				this->_x /= val;
				this->_y /= val;
				return *this;
			}
		};
		
		Complex& operator= (const Complex& rhs) {
			this->_x = rhs._x;
			this->_y = rhs._y;
			return *this;
		};
		
		template<class X>
		Complex& operator= (const Complex<X>& rhs) {
			this->_x = rhs._x;
			this->_y = rhs._y;
			return *this;
		};
		
		template<class X>
		Complex& operator+= (const Complex<X>& rhs) {
			this->_x += rhs._x;
			this->_y += rhs._y;
			return *this;
		};
		
		template<class X>
		Complex& operator-= (const Complex<X>& rhs) {
			this->_x -= rhs._x;
			this->_y -= rhs._y;
			return *this;
		};
		
		template<class X>
		Complex& operator*= (const Complex<X>& rhs) {
			value_type tmp_x = this->_x * rhs._x - this->_y * rhs._y;
			value_type tmp_y = this->_x * rhs._y + this->_y * rhs._x;
			this->_x = tmp_x;
			this->_y = tmp_y;
			return *this;
		};
		
		template<class X>
		Complex& operator/= (const Complex<X>& rhs) {
			if (rhs._x == 0 && rhs._y == 0)
				throw std::runtime_error("ERROR: Division by 0.");
			else {
				value_type tmp_x = (this->_x * rhs._x + this->_y * rhs._y) / (rhs._x * rhs._x + rhs._y * rhs._y);
				value_type tmp_y = (this->_y * rhs._x - this->_x * rhs._y) / (rhs._x * rhs._x + rhs._y * rhs._y);
				this->_x = tmp_x;
				return *this;
			}
		};

};

template<class T>
Complex<T> operator+(const Complex<T>& lhs, const Complex<T>& rhs) {
	T	x = lhs.real() + rhs.real();
	T	y = lhs.imag() + rhs.imag();
	lhs.real(x);
	lhs.imag(y);
};

template<class T>
Complex<T> operator+(const Complex<T>& lhs, const T& val) {
	T x = lhs.real() + val;
	lhs.real(x);
};

template<class T>
Complex<T> operator+(const T& val, const Complex<T>& rhs) {
	T x = rhs.real() + val;
	rhs.real(x);
};

template<class T>
Complex<T> operator-(const Complex<T>& lhs, const Complex<T>& rhs) {
	lhs.real() -= rhs.real();
	lhs.imag() -= rhs.imag();
};

template<class T> 
Complex<T> operator-(const Complex<T>& lhs, const T& val) {
	lhs.real() -= val;
};

template<class T>
Complex<T> operator-(const T& val, const Complex<T>& rhs) {
	rhs.real() -= val;
};

template<class T>
Complex<T> operator*(const Complex<T>& lhs, const Complex<T>& rhs) {
	lhs *= rhs;
};

template<class T>
Complex<T> operator*(const Complex<T>& lhs, const T& val) {
	lhs.real() *= val;
	lhs.imag() *= val;
};

template<class T>
Complex<T> operator*(const T& val, const Complex<T>& rhs) {
	rhs.real() *= val;
	rhs.imag() *= val;
};

template<class T>
Complex<T> operator/(const Complex<T>& lhs, const Complex<T>& rhs) {
	lhs /= rhs;
};

template<class T>
Complex<T> operator/(const Complex<T>& lhs, const T& val) {
	if (val == 0)
		throw std::runtime_error("ERROR: Division by 0.");
	else {
		lhs.real() /= val;
		lhs.imag() /= val;
	}
};

template<class T>
Complex<T> operator/(const T& val, const Complex<T>& rhs) {
	if (val == 0)
		throw std::runtime_error("ERROR: Division by 0.");
	else {
		rhs.real() /= val;
		rhs.imag() /= val;
	}
};

// template<class T>
// Complex<T> operator+(const Complex<T>& rhs);

// template<class T>
// Complex<T> operator-(const Complex<T>& rhs);

template<class T>
bool operator==(const Complex<T>& lhs, const Complex<T>& rhs) {
	return lhs.real() == rhs.real() && lhs.imag() == rhs.imag() ? true : false;
};

template<class T>
bool operator==(const Complex<T>& lhs, const T& val) {
	return lhs.real() == val && lhs.imag() == 0 ? true : false;
};

template<class T>
bool operator==(const T& val, const Complex<T>& rhs) {
	return rhs.real() == val && rhs.imag() == 0 ? true : false;
};

template<class T>
bool operator!=(const Complex<T>& lhs, const Complex<T>& rhs) {
	return (!(lhs==rhs));
};

template<class T>
bool operator!=(const Complex<T>& lhs, const T& val) {
	return (!(lhs==val));
};

template<class T>
bool operator!=(const T& val, const Complex<T>& rhs) {
	return (!(rhs==val));
};

template <class T>
std::ostream & operator<<( std::ostream & os, wx::Complex<T> const & rhs){
	std::string sign = "";
	if (rhs.imag() != 0)
		rhs.imag() < 0 ? sign = " - " : sign = " + ";
	os << rhs.real() << sign << rhs.imag() << "i";
	return os;
};

}

#endif