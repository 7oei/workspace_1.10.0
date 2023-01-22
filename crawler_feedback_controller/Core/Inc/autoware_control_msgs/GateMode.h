#ifndef _ROS_autoware_control_msgs_GateMode_h
#define _ROS_autoware_control_msgs_GateMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_control_msgs
{

  class GateMode : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;
      enum { AUTO =  0 };
      enum { REMOTE =  1 };

    GateMode():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "autoware_control_msgs/GateMode"; };
    const char * getMD5(){ return "5bece6ebb624ff4ed40dde5bdd2cc49f"; };

  };

}
#endif
