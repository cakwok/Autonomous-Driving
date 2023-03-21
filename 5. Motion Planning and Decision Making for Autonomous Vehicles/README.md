## Motion Planning and Decision Making for Autonomous Vehicles

In this project, I have implemented two of the main components of a traditional hierarchical planner: The Behavior Planner and the Motion Planner to:

- Avoid static objects (cars, bicycles and trucks) parked on the side of the road (but still invading the lane). The vehicle must avoid crashing with these vehicles by executing either a “nudge” or a “lane change” maneuver.
- Handle any type of intersection (3-way, 4-way intersections and roundabouts) by STOPPING in all of them (by default)
- Track the centerline on the traveling lane.

By implementing:

- Behavioral planning logic using Finite State Machines - FSM
- Static objects collision checking.
- Path and trajectory generation using cubic spirals
- Best trajectory selection though a cost function evaluation. This cost function will mainly perform a collision check and a proximity check to bring cost higher as we get closer or collide with objects but maintaining a bias to stay closer to the lane center line.

Below shows the output of the implementation with the Carla simulator.  0 collision achieved, behavioral state work as expected, car stopped as expected, lane passed as expected.

![image](https://user-images.githubusercontent.com/21034990/226438848-cde4eada-09f9-498c-a2e8-a2fe0e28d090.png)
<img width="1275" alt="image" src="https://user-images.githubusercontent.com/21034990/226526344-4dc79b95-66ba-4cd3-87d6-bb824e3fd3da.png">
