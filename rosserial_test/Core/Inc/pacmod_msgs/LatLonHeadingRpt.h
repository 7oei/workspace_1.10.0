#ifndef _ROS_pacmod_msgs_LatLonHeadingRpt_h
#define _ROS_pacmod_msgs_LatLonHeadingRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class LatLonHeadingRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _latitude_degrees_type;
      _latitude_degrees_type latitude_degrees;
      typedef uint8_t _latitude_minutes_type;
      _latitude_minutes_type latitude_minutes;
      typedef uint8_t _latitude_seconds_type;
      _latitude_seconds_type latitude_seconds;
      typedef int8_t _longitude_degrees_type;
      _longitude_degrees_type longitude_degrees;
      typedef uint8_t _longitude_minutes_type;
      _longitude_minutes_type longitude_minutes;
      typedef uint8_t _longitude_seconds_type;
      _longitude_seconds_type longitude_seconds;
      typedef double _heading_type;
      _heading_type heading;

    LatLonHeadingRpt():
      header(),
      latitude_degrees(0),
      latitude_minutes(0),
      latitude_seconds(0),
      longitude_degrees(0),
      longitude_minutes(0),
      longitude_seconds(0),
      heading(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_latitude_degrees;
      u_latitude_degrees.real = this->latitude_degrees;
      *(outbuffer + offset + 0) = (u_latitude_degrees.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latitude_degrees);
      *(outbuffer + offset + 0) = (this->latitude_minutes >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latitude_minutes);
      *(outbuffer + offset + 0) = (this->latitude_seconds >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latitude_seconds);
      union {
        int8_t real;
        uint8_t base;
      } u_longitude_degrees;
      u_longitude_degrees.real = this->longitude_degrees;
      *(outbuffer + offset + 0) = (u_longitude_degrees.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->longitude_degrees);
      *(outbuffer + offset + 0) = (this->longitude_minutes >> (8 * 0)) & 0xFF;
      offset += sizeof(this->longitude_minutes);
      *(outbuffer + offset + 0) = (this->longitude_seconds >> (8 * 0)) & 0xFF;
      offset += sizeof(this->longitude_seconds);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heading);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_latitude_degrees;
      u_latitude_degrees.base = 0;
      u_latitude_degrees.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->latitude_degrees = u_latitude_degrees.real;
      offset += sizeof(this->latitude_degrees);
      this->latitude_minutes =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latitude_minutes);
      this->latitude_seconds =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latitude_seconds);
      union {
        int8_t real;
        uint8_t base;
      } u_longitude_degrees;
      u_longitude_degrees.base = 0;
      u_longitude_degrees.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->longitude_degrees = u_longitude_degrees.real;
      offset += sizeof(this->longitude_degrees);
      this->longitude_minutes =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->longitude_minutes);
      this->longitude_seconds =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->longitude_seconds);
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/LatLonHeadingRpt"; };
    const char * getMD5(){ return "137a7c22b052c703f38a29aa79de4e50"; };

  };

}
#endif
