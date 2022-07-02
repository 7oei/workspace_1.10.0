#ifndef _ROS_pacmod_msgs_MotorRpt3_h
#define _ROS_pacmod_msgs_MotorRpt3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class MotorRpt3 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _torque_output_type;
      _torque_output_type torque_output;
      typedef double _torque_input_type;
      _torque_input_type torque_input;

    MotorRpt3():
      header(),
      torque_output(0),
      torque_input(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_torque_output;
      u_torque_output.real = this->torque_output;
      *(outbuffer + offset + 0) = (u_torque_output.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torque_output.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torque_output.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torque_output.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_torque_output.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_torque_output.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_torque_output.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_torque_output.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->torque_output);
      union {
        double real;
        uint64_t base;
      } u_torque_input;
      u_torque_input.real = this->torque_input;
      *(outbuffer + offset + 0) = (u_torque_input.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torque_input.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torque_input.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torque_input.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_torque_input.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_torque_input.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_torque_input.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_torque_input.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->torque_input);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_torque_output;
      u_torque_output.base = 0;
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_torque_output.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->torque_output = u_torque_output.real;
      offset += sizeof(this->torque_output);
      union {
        double real;
        uint64_t base;
      } u_torque_input;
      u_torque_input.base = 0;
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_torque_input.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->torque_input = u_torque_input.real;
      offset += sizeof(this->torque_input);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/MotorRpt3"; };
    const char * getMD5(){ return "1640bb8a85b4353a76a6e6a5df503313"; };

  };

}
#endif
