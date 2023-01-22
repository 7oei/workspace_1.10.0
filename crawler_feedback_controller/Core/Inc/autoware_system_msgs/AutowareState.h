#ifndef _ROS_autoware_system_msgs_AutowareState_h
#define _ROS_autoware_system_msgs_AutowareState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_system_msgs
{

  class AutowareState : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _msg_type;
      _msg_type msg;
      enum { InitializingVehicle = InitializingVehicle };
      enum { WaitingForRoute = WaitingForRoute };
      enum { Planning = Planning };
      enum { WaitingForEngage = WaitingForEngage };
      enum { Driving = Driving };
      enum { ArrivedGoal = ArrivedGoal };
      enum { Emergency = Emergency };
      enum { Finalizing = Finalizing };

    AutowareState():
      state(""),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/AutowareState"; };
    const char * getMD5(){ return "0eb414037acaa38df18284e31ff94747"; };

  };

}
#endif
