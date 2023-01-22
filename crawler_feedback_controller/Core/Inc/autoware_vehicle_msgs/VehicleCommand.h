#ifndef _ROS_autoware_vehicle_msgs_VehicleCommand_h
#define _ROS_autoware_vehicle_msgs_VehicleCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autoware_control_msgs/ControlCommand.h"
#include "autoware_vehicle_msgs/Shift.h"

namespace autoware_vehicle_msgs
{

  class VehicleCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autoware_control_msgs::ControlCommand _control_type;
      _control_type control;
      typedef autoware_vehicle_msgs::Shift _shift_type;
      _shift_type shift;
      typedef int32_t _emergency_type;
      _emergency_type emergency;

    VehicleCommand():
      header(),
      control(),
      shift(),
      emergency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->control.serialize(outbuffer + offset);
      offset += this->shift.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_emergency;
      u_emergency.real = this->emergency;
      *(outbuffer + offset + 0) = (u_emergency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emergency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emergency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emergency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emergency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->control.deserialize(inbuffer + offset);
      offset += this->shift.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_emergency;
      u_emergency.base = 0;
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emergency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emergency = u_emergency.real;
      offset += sizeof(this->emergency);
     return offset;
    }

    const char * getType(){ return "autoware_vehicle_msgs/VehicleCommand"; };
    const char * getMD5(){ return "bbb7dc630dc29a8a183cf780a04b2cb9"; };

  };

}
#endif
