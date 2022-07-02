#ifndef _ROS_autoware_planning_msgs_StopReason_h
#define _ROS_autoware_planning_msgs_StopReason_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autoware_planning_msgs/StopFactor.h"

namespace autoware_planning_msgs
{

  class StopReason : public ros::Msg
  {
    public:
      typedef const char* _reason_type;
      _reason_type reason;
      uint32_t stop_factors_length;
      typedef autoware_planning_msgs::StopFactor _stop_factors_type;
      _stop_factors_type st_stop_factors;
      _stop_factors_type * stop_factors;
      enum { INTERSECTION = Intersection };
      enum { MERGE_FROM_PRIVATE_ROAD = MergeFromPrivateRoad };
      enum { CROSSWALK = Crosswalk };
      enum { WALKWAY = Walkway };
      enum { STOP_LINE = StopLine };
      enum { DETECTION_AREA = DetectionArea };
      enum { TRAFFIC_LIGHT = TrafficLight };
      enum { OBSTACLE_STOP = ObstacleStop };
      enum { SURROUND_OBSTACLE_CHECK = SurroundObstacleCheck };
      enum { BLIND_SPOT = BlindSpot };
      enum { BLOCKED_BY_OBSTACLE = BlockedByObstacle };
      enum { STOPPING_LANE_CHANGE = StoppingLaneChange };
      enum { REMOTE_EMERGENCY_STOP = RemoteEmergencyStop };

    StopReason():
      reason(""),
      stop_factors_length(0), stop_factors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_reason = strlen(this->reason);
      varToArr(outbuffer + offset, length_reason);
      offset += 4;
      memcpy(outbuffer + offset, this->reason, length_reason);
      offset += length_reason;
      *(outbuffer + offset + 0) = (this->stop_factors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_factors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_factors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_factors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_factors_length);
      for( uint32_t i = 0; i < stop_factors_length; i++){
      offset += this->stop_factors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_reason;
      arrToVar(length_reason, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reason-1]=0;
      this->reason = (char *)(inbuffer + offset-1);
      offset += length_reason;
      uint32_t stop_factors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_factors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_factors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_factors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_factors_length);
      if(stop_factors_lengthT > stop_factors_length)
        this->stop_factors = (autoware_planning_msgs::StopFactor*)realloc(this->stop_factors, stop_factors_lengthT * sizeof(autoware_planning_msgs::StopFactor));
      stop_factors_length = stop_factors_lengthT;
      for( uint32_t i = 0; i < stop_factors_length; i++){
      offset += this->st_stop_factors.deserialize(inbuffer + offset);
        memcpy( &(this->stop_factors[i]), &(this->st_stop_factors), sizeof(autoware_planning_msgs::StopFactor));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/StopReason"; };
    const char * getMD5(){ return "24b3613c25b0439e4bf379e422b51ba7"; };

  };

}
#endif
