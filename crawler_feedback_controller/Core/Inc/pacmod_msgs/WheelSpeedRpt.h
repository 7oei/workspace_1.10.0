#ifndef _ROS_pacmod_msgs_WheelSpeedRpt_h
#define _ROS_pacmod_msgs_WheelSpeedRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class WheelSpeedRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _front_left_wheel_speed_type;
      _front_left_wheel_speed_type front_left_wheel_speed;
      typedef double _front_right_wheel_speed_type;
      _front_right_wheel_speed_type front_right_wheel_speed;
      typedef double _rear_left_wheel_speed_type;
      _rear_left_wheel_speed_type rear_left_wheel_speed;
      typedef double _rear_right_wheel_speed_type;
      _rear_right_wheel_speed_type rear_right_wheel_speed;

    WheelSpeedRpt():
      header(),
      front_left_wheel_speed(0),
      front_right_wheel_speed(0),
      rear_left_wheel_speed(0),
      rear_right_wheel_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_front_left_wheel_speed;
      u_front_left_wheel_speed.real = this->front_left_wheel_speed;
      *(outbuffer + offset + 0) = (u_front_left_wheel_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_left_wheel_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_left_wheel_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_left_wheel_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_front_left_wheel_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_front_left_wheel_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_front_left_wheel_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_front_left_wheel_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->front_left_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_front_right_wheel_speed;
      u_front_right_wheel_speed.real = this->front_right_wheel_speed;
      *(outbuffer + offset + 0) = (u_front_right_wheel_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_right_wheel_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_right_wheel_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_right_wheel_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_front_right_wheel_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_front_right_wheel_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_front_right_wheel_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_front_right_wheel_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->front_right_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_rear_left_wheel_speed;
      u_rear_left_wheel_speed.real = this->rear_left_wheel_speed;
      *(outbuffer + offset + 0) = (u_rear_left_wheel_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_left_wheel_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_left_wheel_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_left_wheel_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rear_left_wheel_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rear_left_wheel_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rear_left_wheel_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rear_left_wheel_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rear_left_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_rear_right_wheel_speed;
      u_rear_right_wheel_speed.real = this->rear_right_wheel_speed;
      *(outbuffer + offset + 0) = (u_rear_right_wheel_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_right_wheel_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_right_wheel_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_right_wheel_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rear_right_wheel_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rear_right_wheel_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rear_right_wheel_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rear_right_wheel_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rear_right_wheel_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_front_left_wheel_speed;
      u_front_left_wheel_speed.base = 0;
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_front_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->front_left_wheel_speed = u_front_left_wheel_speed.real;
      offset += sizeof(this->front_left_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_front_right_wheel_speed;
      u_front_right_wheel_speed.base = 0;
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_front_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->front_right_wheel_speed = u_front_right_wheel_speed.real;
      offset += sizeof(this->front_right_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_rear_left_wheel_speed;
      u_rear_left_wheel_speed.base = 0;
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rear_left_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rear_left_wheel_speed = u_rear_left_wheel_speed.real;
      offset += sizeof(this->rear_left_wheel_speed);
      union {
        double real;
        uint64_t base;
      } u_rear_right_wheel_speed;
      u_rear_right_wheel_speed.base = 0;
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rear_right_wheel_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rear_right_wheel_speed = u_rear_right_wheel_speed.real;
      offset += sizeof(this->rear_right_wheel_speed);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/WheelSpeedRpt"; };
    const char * getMD5(){ return "0ade552ffaaff87eca01c4d9b49bb8ae"; };

  };

}
#endif
