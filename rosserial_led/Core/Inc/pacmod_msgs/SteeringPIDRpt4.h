#ifndef _ROS_pacmod_msgs_SteeringPIDRpt4_h
#define _ROS_pacmod_msgs_SteeringPIDRpt4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt4 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _angular_velocity_type;
      _angular_velocity_type angular_velocity;
      typedef double _angular_acceleration_type;
      _angular_acceleration_type angular_acceleration;

    SteeringPIDRpt4():
      header(),
      angular_velocity(0),
      angular_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_angular_velocity;
      u_angular_velocity.real = this->angular_velocity;
      *(outbuffer + offset + 0) = (u_angular_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_angular_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_angular_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_angular_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_angular_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angular_velocity);
      union {
        double real;
        uint64_t base;
      } u_angular_acceleration;
      u_angular_acceleration.real = this->angular_acceleration;
      *(outbuffer + offset + 0) = (u_angular_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_angular_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_angular_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_angular_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_angular_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angular_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_angular_velocity;
      u_angular_velocity.base = 0;
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->angular_velocity = u_angular_velocity.real;
      offset += sizeof(this->angular_velocity);
      union {
        double real;
        uint64_t base;
      } u_angular_acceleration;
      u_angular_acceleration.base = 0;
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->angular_acceleration = u_angular_acceleration.real;
      offset += sizeof(this->angular_acceleration);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt4"; };
    const char * getMD5(){ return "2bc4404ec9df7da4ed993a2081a68002"; };

  };

}
#endif
