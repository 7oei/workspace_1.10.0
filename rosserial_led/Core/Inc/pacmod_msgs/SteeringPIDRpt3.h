#ifndef _ROS_pacmod_msgs_SteeringPIDRpt3_h
#define _ROS_pacmod_msgs_SteeringPIDRpt3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt3 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _new_torque_type;
      _new_torque_type new_torque;
      typedef double _str_angle_desired_type;
      _str_angle_desired_type str_angle_desired;
      typedef double _str_angle_actual_type;
      _str_angle_actual_type str_angle_actual;
      typedef double _error_type;
      _error_type error;

    SteeringPIDRpt3():
      header(),
      new_torque(0),
      str_angle_desired(0),
      str_angle_actual(0),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_new_torque;
      u_new_torque.real = this->new_torque;
      *(outbuffer + offset + 0) = (u_new_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_new_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_new_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_new_torque.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_new_torque.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_new_torque.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_new_torque.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_new_torque.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->new_torque);
      union {
        double real;
        uint64_t base;
      } u_str_angle_desired;
      u_str_angle_desired.real = this->str_angle_desired;
      *(outbuffer + offset + 0) = (u_str_angle_desired.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_str_angle_desired.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_str_angle_desired.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_str_angle_desired.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_str_angle_desired.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_str_angle_desired.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_str_angle_desired.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_str_angle_desired.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->str_angle_desired);
      union {
        double real;
        uint64_t base;
      } u_str_angle_actual;
      u_str_angle_actual.real = this->str_angle_actual;
      *(outbuffer + offset + 0) = (u_str_angle_actual.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_str_angle_actual.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_str_angle_actual.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_str_angle_actual.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_str_angle_actual.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_str_angle_actual.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_str_angle_actual.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_str_angle_actual.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->str_angle_actual);
      union {
        double real;
        uint64_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_new_torque;
      u_new_torque.base = 0;
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_new_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->new_torque = u_new_torque.real;
      offset += sizeof(this->new_torque);
      union {
        double real;
        uint64_t base;
      } u_str_angle_desired;
      u_str_angle_desired.base = 0;
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_str_angle_desired.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->str_angle_desired = u_str_angle_desired.real;
      offset += sizeof(this->str_angle_desired);
      union {
        double real;
        uint64_t base;
      } u_str_angle_actual;
      u_str_angle_actual.base = 0;
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_str_angle_actual.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->str_angle_actual = u_str_angle_actual.real;
      offset += sizeof(this->str_angle_actual);
      union {
        double real;
        uint64_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error = u_error.real;
      offset += sizeof(this->error);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt3"; };
    const char * getMD5(){ return "722f63b47fd2935245656ab58fbec284"; };

  };

}
#endif
