#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>

#include "sensor_data.h"
#include "vehicle.h"

using namespace std;

struct Lane {
  double width;
  int speed_limit;
};

class Road {
public:

  vector<Lane> lanes;
  map<int, Vehicle> vehicles;
  Vehicle ego;

  // Default Constructor
  Road() {};
  
  // Constructor with lanes: Builds the specified number of lanes at initialization.
  // @param width Width of each lane
  // @param lane_speeds Speed limit for each lane, starting from the right lane
  Road(double width, vector<int> lane_speeds);
  // Road(int speed_limit, double traffic_density, vector<int> lane_speeds);

  // Destructor
  virtual ~Road();

  void UpdateEgoKinematics(EgoSensorData ego_data);
  
  //! Updates the current state of the traffic. If there is a new vehicle in the environmet data,
  // it is added to the vehicles array. If a vehicle in the new data was already in the vehicles array
  // it updates its state.
  void PopulateTraffic(EnvironmentSensorData environment_data);
};

#endif