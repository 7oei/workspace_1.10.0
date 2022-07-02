#ifndef _ROS_autoware_control_msgs_ControlCommand_h
#define _ROS_autoware_control_msgs_ControlCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_control_msgs
{

  class ControlCommand : public ros::Msg
  {
    public:
      typedef double _steering_angle_type;
      _steering_angle_type steering_angle;
      typedef double _steering_angle_velocity_type;
      _steering_angle_velocity_type steering_angle_velocity;
      typedef double _velocity_type;
      _velocity_type velocity;
      typedef double _acceleration_type;
      _acceleration_type acceleration;

    ControlCommand():
      steering_angle(0),
      steering_angle_velocity(0),
      velocity(0),
      acceleration(0)
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
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_acceleration;
      u_acceleration.real = this->acceleration;
      *(outbuffer + offset + 0) = (u_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acceleration);
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
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_acceleration;
      u_acceleration.base = 0;
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acceleration = u_acceleration.real;
      offset += sizeof(this->acceleration);
     return offset;
    }

    const char * getType(){ return "autoware_control_msgs/ControlCommand"; };
    const char * getMD5(){ return "beac3f978f000d5cd26de68de9ebce17"; };

  };

}
#endif
