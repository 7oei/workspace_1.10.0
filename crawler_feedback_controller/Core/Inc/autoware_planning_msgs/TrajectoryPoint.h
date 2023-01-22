#ifndef _ROS_autoware_planning_msgs_TrajectoryPoint_h
#define _ROS_autoware_planning_msgs_TrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Accel.h"

namespace autoware_planning_msgs
{

  class TrajectoryPoint : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef geometry_msgs::Accel _accel_type;
      _accel_type accel;

    TrajectoryPoint():
      pose(),
      twist(),
      accel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/TrajectoryPoint"; };
    const char * getMD5(){ return "12a3981be6e2e29bdfd02e1da364b8ff"; };

  };

}
#endif
