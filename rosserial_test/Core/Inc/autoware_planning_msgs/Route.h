#ifndef _ROS_autoware_planning_msgs_Route_h
#define _ROS_autoware_planning_msgs_Route_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "autoware_planning_msgs/RouteSection.h"

namespace autoware_planning_msgs
{

  class Route : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _goal_pose_type;
      _goal_pose_type goal_pose;
      uint32_t route_sections_length;
      typedef autoware_planning_msgs::RouteSection _route_sections_type;
      _route_sections_type st_route_sections;
      _route_sections_type * route_sections;

    Route():
      header(),
      goal_pose(),
      route_sections_length(0), route_sections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->route_sections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->route_sections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->route_sections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->route_sections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->route_sections_length);
      for( uint32_t i = 0; i < route_sections_length; i++){
      offset += this->route_sections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_pose.deserialize(inbuffer + offset);
      uint32_t route_sections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      route_sections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      route_sections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      route_sections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->route_sections_length);
      if(route_sections_lengthT > route_sections_length)
        this->route_sections = (autoware_planning_msgs::RouteSection*)realloc(this->route_sections, route_sections_lengthT * sizeof(autoware_planning_msgs::RouteSection));
      route_sections_length = route_sections_lengthT;
      for( uint32_t i = 0; i < route_sections_length; i++){
      offset += this->st_route_sections.deserialize(inbuffer + offset);
        memcpy( &(this->route_sections[i]), &(this->st_route_sections), sizeof(autoware_planning_msgs::RouteSection));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/Route"; };
    const char * getMD5(){ return "a97cc0d08212f1aeb6ccf49a5a9f422b"; };

  };

}
#endif
