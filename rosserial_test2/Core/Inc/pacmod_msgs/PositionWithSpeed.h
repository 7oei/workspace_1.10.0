#ifndef _ROS_pacmod_msgs_PositionWithSpeed_h
#define _ROS_pacmod_msgs_PositionWithSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class PositionWithSpeed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _angular_position_type;
      _angular_position_type angular_position;
      typedef double _angular_velocity_limit_type;
      _angular_velocity_limit_type angular_velocity_limit;

    PositionWithSpeed():
      header(),
      angular_position(0),
      angular_velocity_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_angular_position;
      u_angular_position.real = this->angular_position;
      *(outbuffer + offset + 0) = (u_angular_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_angular_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_angular_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_angular_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_angular_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angular_position);
      union {
        double real;
        uint64_t base;
      } u_angular_velocity_limit;
      u_angular_velocity_limit.real = this->angular_velocity_limit;
      *(outbuffer + offset + 0) = (u_angular_velocity_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_velocity_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_velocity_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_velocity_limit.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_angular_velocity_limit.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_angular_velocity_limit.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_angular_velocity_limit.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_angular_velocity_limit.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angular_velocity_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_angular_position;
      u_angular_position.base = 0;
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_angular_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->angular_position = u_angular_position.real;
      offset += sizeof(this->angular_position);
      union {
        double real;
        uint64_t base;
      } u_angular_velocity_limit;
      u_angular_velocity_limit.base = 0;
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_angular_velocity_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->angular_velocity_limit = u_angular_velocity_limit.real;
      offset += sizeof(this->angular_velocity_limit);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/PositionWithSpeed"; };
    const char * getMD5(){ return "7e96a8c8cbc8234d4d2c87880ddb7cfe"; };

  };

}
#endif
