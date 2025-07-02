/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:39:28 by mratke            #+#    #+#             */
/*   Updated: 2025/07/02 16:40:15 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : integer(0) { std::cout << "Default constructor called\n"; };

Fixed::Fixed(const Fixed &other) : integer(other.integer) {
  std::cout << "Copy constructor called\n";
};

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    this->integer = other.integer;
  }
  return *this;
}

Fixed::Fixed(const int param) : integer(param << fractionalBits) {
  std ::cout << "Int constructor called\n";
}

Fixed::Fixed(const float param)
    : integer((int)roundf(param * (1 << fractionalBits))) {
  std ::cout << "Float constructor called\n";
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return (integer);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  integer = raw;
}

float Fixed::toFloat(void) const {
  return ((float)integer / (1 << fractionalBits));
}

int Fixed::toInt(void) const { return (integer >> fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
