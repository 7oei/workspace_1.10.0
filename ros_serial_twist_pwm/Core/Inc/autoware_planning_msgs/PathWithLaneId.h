#ifndef _ROS_autoware_planning_msgs_PathWithLaneId_h
#define _ROS_autoware_planning_msgs_PathWithLaneId_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_planning_msgs/PathPointWithLaneId.h"
#include "nav_msgs/OccupancyGrid.h"

namespace autoware_planning_msgs
{

  class PathWithLaneId : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t points_length;
      typedef autoware_planning_msgs::PathPointWithLaneId _points_type;
      _points_type st_points;
      _points_type * points;
      typedef nav_msgs::OccupancyGrid _drivable_area_type;
      _drivable_area_type drivable_area;

    PathWithLaneId():
      header(),
      points_length(0), points(NULL),
      drivable_area()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      offset += this->drivable_area.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (autoware_planning_msgs::PathPointWithLaneId*)realloc(this->points, points_lengthT * sizeof(autoware_planning_msgs::PathPointWithLaneId));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(autoware_planning_msgs::PathPointWithLaneId));
      }
      offset += this->drivable_area.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/PathWithLaneId"; };
    const char * getMD5(){ return "96253f4cd9f527a5fc96a075341910d5"; };

  };

}
#endif
