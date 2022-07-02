#ifndef _ROS_pacmod_msgs_VehicleDynamicsRpt_h
#define _ROS_pacmod_msgs_VehicleDynamicsRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class VehicleDynamicsRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _brake_torque_type;
      _brake_torque_type brake_torque;
      typedef uint8_t _g_forces_type;
      _g_forces_type g_forces;

    VehicleDynamicsRpt():
      header(),
      brake_torque(0),
      g_forces(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_brake_torque;
      u_brake_torque.real = this->brake_torque;
      *(outbuffer + offset + 0) = (u_brake_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake_torque.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_brake_torque.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_brake_torque.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_brake_torque.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_brake_torque.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->brake_torque);
      *(outbuffer + offset + 0) = (this->g_forces >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g_forces);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_brake_torque;
      u_brake_torque.base = 0;
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_brake_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->brake_torque = u_brake_torque.real;
      offset += sizeof(this->brake_torque);
      this->g_forces =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->g_forces);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/VehicleDynamicsRpt"; };
    const char * getMD5(){ return "76c5ee0fb5b1065da372a973e2ffdd31"; };

  };

}
#endif
