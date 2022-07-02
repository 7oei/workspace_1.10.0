#ifndef _ROS_pacmod_msgs_MotorRpt1_h
#define _ROS_pacmod_msgs_MotorRpt1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class MotorRpt1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _current_type;
      _current_type current;
      typedef double _position_type;
      _position_type position;

    MotorRpt1():
      header(),
      current(0),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position = u_position.real;
      offset += sizeof(this->position);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/MotorRpt1"; };
    const char * getMD5(){ return "bc762724eccc08e26b60b6284460fe26"; };

  };

}
#endif
