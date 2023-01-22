#ifndef _ROS_autoware_planning_msgs_PathPoint_h
#define _ROS_autoware_planning_msgs_PathPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace autoware_planning_msgs
{

  class PathPoint : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef uint8_t _type_type;
      _type_type type;
      enum { REFFERENCE = 0 };
      enum { FIXED = 1 };

    PathPoint():
      pose(),
      twist(),
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/PathPoint"; };
    const char * getMD5(){ return "e48252d5946ba8f4e2250819f89ca6a2"; };

  };

}
#endif
