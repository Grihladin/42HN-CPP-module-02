/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:54:01 by mratke            #+#    #+#             */
/*   Updated: 2025/07/02 18:19:12 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : x(0), y(0) { std::cout << "Default constructor called"; }

Point::Point(const Fixed a, const Fixed b) : x(a), y(b) {
  std::cout << "Param constructor called";
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
  std::cout << "Copy constructor called";
}

Point &Point::operator=(const Point &other) {
  (void)other;
  std::cerr << "ERROR: Assignment operator is not possible for Point since x "
               "and y are const.\n";
  exit(1);
}

const Fixed Point::getX() { return (x); }
const Fixed Point::getY() { return (y); }

// cross product formula for determining which side of a line a point is on.
Fixed sign(Point a, Point b, Point c) {

  Fixed first = a.getX() - c.getX();
  Fixed second = b.getY() - c.getY();
  Fixed third = b.getX() - c.getX();
  Fixed fourth = a.getY() - c.getY();

  return (first * second - third * fourth);
}
// Cross Product method
bool Point::bsp(Point const a, Point const b, Point const c,
                Point const point) {
  Fixed d1, d2, d3;
  bool has_neg, has_pos;

  d1 = sign(point, a, b);
  d2 = sign(point, b, c);
  d3 = sign(point, c, a);

  if (d1 == 0 || d2 == 0 || d3 == 0)
    return (false);

  has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return !(has_neg && has_pos);
}

Point::~Point() { std::cout << "Destructor is called"; }
