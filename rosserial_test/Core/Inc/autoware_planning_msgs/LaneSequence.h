#ifndef _ROS_autoware_planning_msgs_LaneSequence_h
#define _ROS_autoware_planning_msgs_LaneSequence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_planning_msgs
{

  class LaneSequence : public ros::Msg
  {
    public:
      uint32_t lane_ids_length;
      typedef int64_t _lane_ids_type;
      _lane_ids_type st_lane_ids;
      _lane_ids_type * lane_ids;

    LaneSequence():
      lane_ids_length(0), lane_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->lane_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_ids_length);
      for( uint32_t i = 0; i < lane_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_lane_idsi;
      u_lane_idsi.real = this->lane_ids[i];
      *(outbuffer + offset + 0) = (u_lane_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lane_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lane_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lane_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lane_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lane_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t lane_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_ids_length);
      if(lane_ids_lengthT > lane_ids_length)
        this->lane_ids = (int64_t*)realloc(this->lane_ids, lane_ids_lengthT * sizeof(int64_t));
      lane_ids_length = lane_ids_lengthT;
      for( uint32_t i = 0; i < lane_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_lane_ids;
      u_st_lane_ids.base = 0;
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_lane_ids = u_st_lane_ids.real;
      offset += sizeof(this->st_lane_ids);
        memcpy( &(this->lane_ids[i]), &(this->st_lane_ids), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/LaneSequence"; };
    const char * getMD5(){ return "8ff2c02f553be6713a6038a7d7d22b99"; };

  };

}
#endif
