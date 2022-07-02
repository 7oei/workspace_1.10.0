#ifndef _ROS_pacmod_msgs_DetectedObjectRpt_h
#define _ROS_pacmod_msgs_DetectedObjectRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class DetectedObjectRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _front_object_distance_low_res_type;
      _front_object_distance_low_res_type front_object_distance_low_res;
      typedef double _front_object_distance_high_res_type;
      _front_object_distance_high_res_type front_object_distance_high_res;

    DetectedObjectRpt():
      header(),
      front_object_distance_low_res(0),
      front_object_distance_high_res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_front_object_distance_low_res;
      u_front_object_distance_low_res.real = this->front_object_distance_low_res;
      *(outbuffer + offset + 0) = (u_front_object_distance_low_res.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_object_distance_low_res.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_object_distance_low_res.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_object_distance_low_res.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_front_object_distance_low_res.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_front_object_distance_low_res.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_front_object_distance_low_res.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_front_object_distance_low_res.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->front_object_distance_low_res);
      union {
        double real;
        uint64_t base;
      } u_front_object_distance_high_res;
      u_front_object_distance_high_res.real = this->front_object_distance_high_res;
      *(outbuffer + offset + 0) = (u_front_object_distance_high_res.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_object_distance_high_res.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_object_distance_high_res.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_object_distance_high_res.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_front_object_distance_high_res.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_front_object_distance_high_res.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_front_object_distance_high_res.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_front_object_distance_high_res.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->front_object_distance_high_res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_front_object_distance_low_res;
      u_front_object_distance_low_res.base = 0;
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_front_object_distance_low_res.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->front_object_distance_low_res = u_front_object_distance_low_res.real;
      offset += sizeof(this->front_object_distance_low_res);
      union {
        double real;
        uint64_t base;
      } u_front_object_distance_high_res;
      u_front_object_distance_high_res.base = 0;
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_front_object_distance_high_res.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->front_object_distance_high_res = u_front_object_distance_high_res.real;
      offset += sizeof(this->front_object_distance_high_res);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/DetectedObjectRpt"; };
    const char * getMD5(){ return "bc712b16be2ea6767f3e682c00a854bc"; };

  };

}
#endif
