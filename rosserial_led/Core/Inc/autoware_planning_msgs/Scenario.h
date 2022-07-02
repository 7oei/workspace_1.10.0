#ifndef _ROS_autoware_planning_msgs_Scenario_h
#define _ROS_autoware_planning_msgs_Scenario_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autoware_planning_msgs
{

  class Scenario : public ros::Msg
  {
    public:
      typedef const char* _current_scenario_type;
      _current_scenario_type current_scenario;
      uint32_t activating_scenarios_length;
      typedef char* _activating_scenarios_type;
      _activating_scenarios_type st_activating_scenarios;
      _activating_scenarios_type * activating_scenarios;
      enum { Empty = Empty };
      enum { LaneDriving = LaneDriving };
      enum { Parking = Parking };

    Scenario():
      current_scenario(""),
      activating_scenarios_length(0), activating_scenarios(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_current_scenario = strlen(this->current_scenario);
      varToArr(outbuffer + offset, length_current_scenario);
      offset += 4;
      memcpy(outbuffer + offset, this->current_scenario, length_current_scenario);
      offset += length_current_scenario;
      *(outbuffer + offset + 0) = (this->activating_scenarios_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->activating_scenarios_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->activating_scenarios_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->activating_scenarios_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activating_scenarios_length);
      for( uint32_t i = 0; i < activating_scenarios_length; i++){
      uint32_t length_activating_scenariosi = strlen(this->activating_scenarios[i]);
      varToArr(outbuffer + offset, length_activating_scenariosi);
      offset += 4;
      memcpy(outbuffer + offset, this->activating_scenarios[i], length_activating_scenariosi);
      offset += length_activating_scenariosi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_current_scenario;
      arrToVar(length_current_scenario, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_scenario; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_scenario-1]=0;
      this->current_scenario = (char *)(inbuffer + offset-1);
      offset += length_current_scenario;
      uint32_t activating_scenarios_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      activating_scenarios_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      activating_scenarios_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      activating_scenarios_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->activating_scenarios_length);
      if(activating_scenarios_lengthT > activating_scenarios_length)
        this->activating_scenarios = (char**)realloc(this->activating_scenarios, activating_scenarios_lengthT * sizeof(char*));
      activating_scenarios_length = activating_scenarios_lengthT;
      for( uint32_t i = 0; i < activating_scenarios_length; i++){
      uint32_t length_st_activating_scenarios;
      arrToVar(length_st_activating_scenarios, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_activating_scenarios; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_activating_scenarios-1]=0;
      this->st_activating_scenarios = (char *)(inbuffer + offset-1);
      offset += length_st_activating_scenarios;
        memcpy( &(this->activating_scenarios[i]), &(this->st_activating_scenarios), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "autoware_planning_msgs/Scenario"; };
    const char * getMD5(){ return "9e42802502551bee186fe00316732f56"; };

  };

}
#endif
