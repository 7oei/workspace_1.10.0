#ifndef _ROS_autoware_system_msgs_DrivingCapability_h
#define _ROS_autoware_system_msgs_DrivingCapability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_system_msgs/HazardStatus.h"

namespace autoware_system_msgs
{

  class DrivingCapability : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_system_msgs::HazardStatus _autonomous_driving_type;
      _autonomous_driving_type autonomous_driving;
      typedef autoware_system_msgs::HazardStatus _remote_control_type;
      _remote_control_type remote_control;

    DrivingCapability():
      header(),
      autonomous_driving(),
      remote_control()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->autonomous_driving.serialize(outbuffer + offset);
      offset += this->remote_control.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->autonomous_driving.deserialize(inbuffer + offset);
      offset += this->remote_control.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/DrivingCapability"; };
    const char * getMD5(){ return "c4d17628913c0eb224f5e91ae1e82f9c"; };

  };

}
#endif
