#ifndef _ROS_autoware_planning_msgs_RouteSection_h
#define _ROS_autoware_planning_msgs_RouteSection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_planning_msgs
{

  class RouteSection : public ros::Msg
  {
    public:
      uint32_t lane_ids_length;
      typedef int64_t _lane_ids_type;
      _lane_ids_type st_lane_ids;
      _lane_ids_type * lane_ids;
      typedef int64_t _preferred_lane_id_type;
      _preferred_lane_id_type preferred_lane_id;
      uint32_t continued_lane_ids_length;
      typedef int64_t _continued_lane_ids_type;
      _continued_lane_ids_type st_continued_lane_ids;
      _continued_lane_ids_type * continued_lane_ids;

    RouteSection():
      lane_ids_length(0), lane_ids(NULL),
      preferred_lane_id(0),
      continued_lane_ids_length(0), continued_lane_ids(NULL)
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
      union {
        int64_t real;
        uint64_t base;
      } u_preferred_lane_id;
      u_preferred_lane_id.real = this->preferred_lane_id;
      *(outbuffer + offset + 0) = (u_preferred_lane_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_preferred_lane_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_preferred_lane_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_preferred_lane_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_preferred_lane_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_preferred_lane_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_preferred_lane_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_preferred_lane_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->preferred_lane_id);
      *(outbuffer + offset + 0) = (this->continued_lane_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->continued_lane_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->continued_lane_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->continued_lane_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->continued_lane_ids_length);
      for( uint32_t i = 0; i < continued_lane_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_continued_lane_idsi;
      u_continued_lane_idsi.real = this->continued_lane_ids[i];
      *(outbuffer + offset + 0) = (u_continued_lane_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_continued_lane_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_continued_lane_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_continued_lane_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_continued_lane_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_continued_lane_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_continued_lane_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_continued_lane_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->continued_lane_ids[i]);
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
      union {
        int64_t real;
        uint64_t base;
      } u_preferred_lane_id;
      u_preferred_lane_id.base = 0;
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_preferred_lane_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->preferred_lane_id = u_preferred_lane_id.real;
      offset += sizeof(this->preferred_lane_id);
      uint32_t continued_lane_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      continued_lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      continued_lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      continued_lane_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->continued_lane_ids_length);
      if(continued_lane_ids_lengthT > continued_lane_ids_length)
        this->continued_lane_ids = (int64_t*)realloc(this->continued_lane_ids, continued_lane_ids_lengthT * sizeof(int64_t));
      continued_lane_ids_length = continued_lane_ids_lengthT;
      for( uint32_t i = 0; i < continued_lane_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_continued_lane_ids;
      u_st_continued_lane_ids.base = 0;
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_continued_lane_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_continued_lane_ids = u_st_continued_lane_ids.real;
      offset += sizeof(this->st_continued_lane_ids);
        memcpy( &(this->continued_lane_ids[i]), &(this->st_continued_lane_ids), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/RouteSection"; };
    const char * getMD5(){ return "f2f5aadafa97ec1dda39866d5941c987"; };

  };

}
#endif
