#ifndef _ROS_bno055_usb_stick_msgs_EulerAngles_h
#define _ROS_bno055_usb_stick_msgs_EulerAngles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bno055_usb_stick_msgs
{

  class EulerAngles : public ros::Msg
  {
    public:
      typedef double _heading_type;
      _heading_type heading;
      typedef double _roll_type;
      _roll_type roll;
      typedef double _pitch_type;
      _pitch_type pitch;

    EulerAngles():
      heading(0),
      roll(0),
      pitch(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heading.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heading.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heading.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heading.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pitch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pitch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pitch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pitch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pitch);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heading.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
      union {
        double real;
        uint64_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        double real;
        uint64_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pitch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
     return offset;
    }

    const char * getType(){ return "bno055_usb_stick_msgs/EulerAngles"; };
    const char * getMD5(){ return "2cfcb5286131de123be05c39311011e6"; };

  };

}
#endif
