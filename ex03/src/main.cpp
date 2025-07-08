/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:39:31 by mratke            #+#    #+#             */
/*   Updated: 2025/07/07 21:22:01 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

int main(void) {
  Fixed firstDot(-10);
  Fixed secondDot(0);
  Fixed thirdDot(10);

  Point bottomLeft(firstDot, firstDot);  // (-10, -10)
  Point top(secondDot, secondDot);       // (0, 0)
  Point bottomRight(thirdDot, firstDot); // (10, -10)

  Fixed checkX(0);
  Fixed checkY(-5);
  Point check(checkX, checkY); // (0, -5)
  bool result = check.bsp(bottomLeft, top, bottomRight, check);
  std::cout << result << std::endl;
}
