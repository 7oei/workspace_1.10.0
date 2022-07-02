#ifndef _ROS_autoware_planning_msgs_StopReasonArray_h
#define _ROS_autoware_planning_msgs_StopReasonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_planning_msgs/StopReason.h"

namespace autoware_planning_msgs
{

  class StopReasonArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t stop_reasons_length;
      typedef autoware_planning_msgs::StopReason _stop_reasons_type;
      _stop_reasons_type st_stop_reasons;
      _stop_reasons_type * stop_reasons;

    StopReasonArray():
      header(),
      stop_reasons_length(0), stop_reasons(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->stop_reasons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_reasons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_reasons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_reasons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_reasons_length);
      for( uint32_t i = 0; i < stop_reasons_length; i++){
      offset += this->stop_reasons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t stop_reasons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_reasons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_reasons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_reasons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_reasons_length);
      if(stop_reasons_lengthT > stop_reasons_length)
        this->stop_reasons = (autoware_planning_msgs::StopReason*)realloc(this->stop_reasons, stop_reasons_lengthT * sizeof(autoware_planning_msgs::StopReason));
      stop_reasons_length = stop_reasons_lengthT;
      for( uint32_t i = 0; i < stop_reasons_length; i++){
      offset += this->st_stop_reasons.deserialize(inbuffer + offset);
        memcpy( &(this->stop_reasons[i]), &(this->st_stop_reasons), sizeof(autoware_planning_msgs::StopReason));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/StopReasonArray"; };
    const char * getMD5(){ return "7ce98b6832f5620bd8021b7133c8fde0"; };

  };

}
#endif
