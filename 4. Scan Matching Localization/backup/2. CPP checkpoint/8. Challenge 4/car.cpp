/**
 * This is how the car works. No need to make any changes here.
 */

#include "Car.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

// Constructor.
Car::Car() {
  // initialize random seed for wearAndTear
  srand(time(NULL));
  // start off in working condition
  in_working_condition_ = true;
}

// Determine whether or not the car is still drivable after some wear and tear.
void Car::wearAndTear() {
  // 50% chance that the car is still working after wear and tear
  int condition = rand() % 10;
  condition >= 5 ? in_working_condition_ = true : in_working_condition_ = false;
}

// Try to drive the car.
bool Car::drive() {
  bool didDrive = false;

  if (in_working_condition_) {
    std::cout << "Driving!" << std::endl;
    wearAndTear();
    didDrive = true;
  } else {
    std::cout << "Broken down. Please fix." << std::endl;
    didDrive = false;
  }

  return didDrive;
}


// Fix the car.
void Car::fix() {
  in_working_condition_ = true;
  std::cout << "Fixed!" << std::endl;
}
