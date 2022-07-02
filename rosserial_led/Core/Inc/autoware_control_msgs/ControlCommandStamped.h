#ifndef _ROS_autoware_control_msgs_ControlCommandStamped_h
#define _ROS_autoware_control_msgs_ControlCommandStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_control_msgs/ControlCommand.h"

namespace autoware_control_msgs
{

  class ControlCommandStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_control_msgs::ControlCommand _control_type;
      _control_type control;

    ControlCommandStamped():
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

    const char * getType(){ return "autoware_control_msgs/ControlCommandStamped"; };
    const char * getMD5(){ return "6cfe21cd566778564e42651227ec479d"; };

  };

}
#endif
