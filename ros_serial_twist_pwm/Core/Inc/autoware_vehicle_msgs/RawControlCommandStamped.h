#ifndef _ROS_autoware_vehicle_msgs_RawControlCommandStamped_h
#define _ROS_autoware_vehicle_msgs_RawControlCommandStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_vehicle_msgs/RawControlCommand.h"

namespace autoware_vehicle_msgs
{

  class RawControlCommandStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_vehicle_msgs::RawControlCommand _control_type;
      _control_type control;

    RawControlCommandStamped():
      header(),
      control()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->control.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->control.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_vehicle_msgs/RawControlCommandStamped"; };
    const char * getMD5(){ return "ccea005b7cf7925ef1bd2da9b128b41e"; };

  };

}
#endif
