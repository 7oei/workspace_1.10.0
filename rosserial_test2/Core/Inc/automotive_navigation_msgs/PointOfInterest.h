#ifndef _ROS_automotive_navigation_msgs_PointOfInterest_h
#define _ROS_automotive_navigation_msgs_PointOfInterest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace automotive_navigation_msgs
{

  class PointOfInterest : public ros::Msg
  {
    public:
      typedef uint64_t _guid_type;
      _guid_type guid;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef const char* _params_type;
      _params_type params;

    PointOfInterest():
      guid(0),
      latitude(0),
      longitude(0),
      params("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->guid >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->guid >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->guid >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->guid >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->guid >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->guid >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->guid >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->guid >> (8 * 7)) & 0xFF;
      offset += sizeof(this->guid);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      uint32_t length_params = strlen(this->params);
      varToArr(outbuffer + offset, length_params);
      offset += 4;
      memcpy(outbuffer + offset, this->params, length_params);
      offset += length_params;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->guid =  ((uint64_t) (*(inbuffer + offset)));
      this->guid |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->guid |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->guid);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      uint32_t length_params;
      arrToVar(length_params, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_params; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_params-1]=0;
      this->params = (char *)(inbuffer + offset-1);
      offset += length_params;
     return offset;
    }

    const char * getType(){ return "automotive_navigation_msgs/PointOfInterest"; };
    const char * getMD5(){ return "e13bf4b872a022336936c4b575654650"; };

  };

}
#endif
