#ifndef _ROS_autoware_planning_msgs_StopFactor_h
#define _ROS_autoware_planning_msgs_StopFactor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace autoware_planning_msgs
{

  class StopFactor : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _stop_pose_type;
      _stop_pose_type stop_pose;
      typedef double _dist_to_stop_pose_type;
      _dist_to_stop_pose_type dist_to_stop_pose;
      uint32_t stop_factor_points_length;
      typedef geometry_msgs::Point _stop_factor_points_type;
      _stop_factor_points_type st_stop_factor_points;
      _stop_factor_points_type * stop_factor_points;

    StopFactor():
      stop_pose(),
      dist_to_stop_pose(0),
      stop_factor_points_length(0), stop_factor_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->stop_pose.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dist_to_stop_pose;
      u_dist_to_stop_pose.real = this->dist_to_stop_pose;
      *(outbuffer + offset + 0) = (u_dist_to_stop_pose.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dist_to_stop_pose.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dist_to_stop_pose.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dist_to_stop_pose.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dist_to_stop_pose.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dist_to_stop_pose.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dist_to_stop_pose.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dist_to_stop_pose.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dist_to_stop_pose);
      *(outbuffer + offset + 0) = (this->stop_factor_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_factor_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_factor_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_factor_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_factor_points_length);
      for( uint32_t i = 0; i < stop_factor_points_length; i++){
      offset += this->stop_factor_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->stop_pose.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_dist_to_stop_pose;
      u_dist_to_stop_pose.base = 0;
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dist_to_stop_pose.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dist_to_stop_pose = u_dist_to_stop_pose.real;
      offset += sizeof(this->dist_to_stop_pose);
      uint32_t stop_factor_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_factor_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_factor_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_factor_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_factor_points_length);
      if(stop_factor_points_lengthT > stop_factor_points_length)
        this->stop_factor_points = (geometry_msgs::Point*)realloc(this->stop_factor_points, stop_factor_points_lengthT * sizeof(geometry_msgs::Point));
      stop_factor_points_length = stop_factor_points_lengthT;
      for( uint32_t i = 0; i < stop_factor_points_length; i++){
      offset += this->st_stop_factor_points.deserialize(inbuffer + offset);
        memcpy( &(this->stop_factor_points[i]), &(this->st_stop_factor_points), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/StopFactor"; };
    const char * getMD5(){ return "a70a47293c6811064a0885fcd95cfffe"; };

  };

}
#endif
