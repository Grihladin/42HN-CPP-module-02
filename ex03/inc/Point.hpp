/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:33:07 by mratke            #+#    #+#             */
/*   Updated: 2025/07/02 17:55:23 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
  const Fixed x;
  const Fixed y;

public:
  Point();
  Point(const Point &other);
  Point &operator=(const Point &other);
  Point(const Fixed a, const Fixed y);
  ~Point();

  const Fixed getX();
  const Fixed getY();
  bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif
