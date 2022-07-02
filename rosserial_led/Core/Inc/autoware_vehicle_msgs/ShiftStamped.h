#ifndef _ROS_autoware_vehicle_msgs_ShiftStamped_h
#define _ROS_autoware_vehicle_msgs_ShiftStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_vehicle_msgs/Shift.h"

namespace autoware_vehicle_msgs
{

  class ShiftStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_vehicle_msgs::Shift _shift_type;
      _shift_type shift;

    ShiftStamped():
      header(),
      shift()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->shift.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->shift.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_vehicle_msgs/ShiftStamped"; };
    const char * getMD5(){ return "f22613f797e09e8010076f27026bcc5a"; };

  };

}
#endif
