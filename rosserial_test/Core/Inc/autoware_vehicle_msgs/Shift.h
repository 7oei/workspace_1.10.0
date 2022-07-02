#ifndef _ROS_autoware_vehicle_msgs_Shift_h
#define _ROS_autoware_vehicle_msgs_Shift_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_vehicle_msgs
{

  class Shift : public ros::Msg
  {
    public:
      typedef int32_t _data_type;
      _data_type data;
      enum { NONE = 0 };
      enum { PARKING = 1 };
      enum { REVERSE = 2 };
      enum { NEUTRAL = 3 };
      enum { DRIVE = 4 };
      enum { LOW = 5 };

    Shift():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "autoware_vehicle_msgs/Shift"; };
    const char * getMD5(){ return "2fd0e3a838050b8d14292e38efefcee4"; };

  };

}
#endif
