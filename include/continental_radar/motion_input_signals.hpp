//
// Created by shivesh on 9/14/19.
//

#ifndef CONTINENTAL_RADAR_MOTION_INPUT_SIGNALS_HPP
#define CONTINENTAL_RADAR_MOTION_INPUT_SIGNALS_HPP

#include <cstdint>

namespace continental_radar
{
typedef union speed_information {
  struct {
    uint64_t RadarDevice_Speed1:5;
    uint64_t Reserved:1;
    uint64_t RadarDevice_SpeedDirection:2;
    uint64_t RadarDevice_Speed2:8;
  } data = {};

  uint8_t raw_data[2];
} speed_information;

typedef enum RadarDevice_SpeedDirection {
  STANDSTILL = 0x0,
  FORWARD = 0x1,
  BACKWARD = 0x2,
} RadarDevice_SpeedDirection;

typedef union yaw_rate_information {
  struct {
    uint64_t RadarDevice_YawRate1:8;
    uint64_t RadarDevice_YawRate2:8;
  } data = {};

  uint8_t raw_data[2];
} yaw_rate_information;

class SpeedInformation
{
 public:
  SpeedInformation();

  ~SpeedInformation();

  void set_speed(uint64_t speed);

  void set_speed_direction(RadarDevice_SpeedDirection direction);

  speed_information get_speed_information();

 private:
  speed_information speed_information_msg;
};

class YawRateInformation
{
 public:
  YawRateInformation();

  ~YawRateInformation();

  void set_yaw_rate(uint64_t yaw_rate);

 private:
  speed_information speed_information_msg;

  yaw_rate_information yaw_rate_information_msg;
};
}

#endif //CONTINENTAL_RADAR_MOTION_INPUT_SIGNALS_HPP
