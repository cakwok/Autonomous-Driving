#ifndef COST_H
#define COST_H

#include <vector>

double inefficiency_cost(int target_speed, int intended_lane, int final_lane, 
                         const std::vector<int> &lane_speeds);

#endif  // COST_H