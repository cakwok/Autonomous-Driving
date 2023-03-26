#include <iostream>
#include "help_functions.h"

// TODO: assign a value, the difference in distances between x_t and x_{t-1}
// that maximizes the returned probability of norm_pdf

float value = 1;  // YOUR VALUE HERE


float parameter = 1.0;  // set as control parameter or observation measurement
float stdev = 1.0;  // position or observation standard deviation

int main() {

  float prob = Helpers::normpdf(value, parameter, stdev);

  std::cout << prob << std::endl;

  return 0;
}