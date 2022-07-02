#ifndef _ROS_autoware_system_msgs_HazardStatusStamped_h
#define _ROS_autoware_system_msgs_HazardStatusStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_system_msgs/HazardStatus.h"

namespace autoware_system_msgs
{

  class HazardStatusStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_system_msgs::HazardStatus _status_type;
      _status_type status;

    HazardStatusStamped():
      header(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/HazardStatusStamped"; };
    const char * getMD5(){ return "248e3f821d3db5a696bef4268625bd60"; };

  };

}
#endif
