#ifndef _ROS_autoware_vehicle_msgs_RawControlCommand_h
#define _ROS_autoware_vehicle_msgs_RawControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_vehicle_msgs
{

  class RawControlCommand : public ros::Msg
  {
    public:
      typedef double _steering_angle_type;
      _steering_angle_type steering_angle;
      typedef double _steering_angle_velocity_type;
      _steering_angle_velocity_type steering_angle_velocity;
      typedef double _throttle_type;
      _throttle_type throttle;
      typedef double _brake_type;
      _brake_type brake;

    RawControlCommand():
      steering_angle(0),
      steering_angle_velocity(0),
      throttle(0),
      brake(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_steering_angle;
      u_steering_angle.real = this->steering_angle;
      *(outbuffer + offset + 0) = (u_steering_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_steering_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_steering_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_steering_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_steering_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->steering_angle);
      union {
        double real;
        uint64_t base;
      } u_steering_angle_velocity;
      u_steering_angle_velocity.real = this->steering_angle_velocity;
      *(outbuffer + offset + 0) = (u_steering_angle_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_angle_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_angle_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_angle_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_steering_angle_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_steering_angle_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_steering_angle_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_steering_angle_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->steering_angle_velocity);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_throttle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_throttle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_throttle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_throttle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        double real;
        uint64_t base;
      } u_brake;
      u_brake.real = this->brake;
      *(outbuffer + offset + 0) = (u_brake.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_brake.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_brake.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_brake.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_brake.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_steering_angle;
      u_steering_angle.base = 0;
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_steering_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->steering_angle = u_steering_angle.real;
      offset += sizeof(this->steering_angle);
      union {
        double real;
        uint64_t base;
      } u_steering_angle_velocity;
      u_steering_angle_velocity.base = 0;
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_steering_angle_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->steering_angle_velocity = u_steering_angle_velocity.real;
      offset += sizeof(this->steering_angle_velocity);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        double real;
        uint64_t base;
      } u_brake;
      u_brake.base = 0;
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->brake = u_brake.real;
      offset += sizeof(this->brake);
     return offset;
    }

    const char * getType(){ return "autoware_vehicle_msgs/RawControlCommand"; };
    const char * getMD5(){ return "8d9ebe05823053d6cd0059203f4d5e53"; };

  };

}
#endif
