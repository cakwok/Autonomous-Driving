#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include <math.h>

class Helpers {
 public:
  // definition of one over square root of 2*pi:
  constexpr static float STATIC_ONE_OVER_SQRT_2PI = 1/sqrt(2*M_PI);

  /**
   * normpdf(X,mu,sigma) computes the probability function at values x using the
   * normal distribution with mean mu and standard deviation std. x, mu and 
   * sigma must be scalar! The parameter std must be positive. 
   * The normal pdf is y=f(x,mu,std)= 1/(std*sqrt(2pi)) e[ -(x−mu)^2 / 2*std^2 ]
   */
  static float normpdf(float x, float mu, float std) {
    return (STATIC_ONE_OVER_SQRT_2PI/std)*exp(-0.5*pow((x-mu)/std,2));
  }
};

#endif  // HELP_FUNCTIONS_H