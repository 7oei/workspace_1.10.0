#ifndef _ROS_pacmod_msgs_EngineRpt_h
#define _ROS_pacmod_msgs_EngineRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class EngineRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _engine_speed_type;
      _engine_speed_type engine_speed;
      typedef double _engine_torque_type;
      _engine_torque_type engine_torque;
      typedef int16_t _engine_coolant_temp_type;
      _engine_coolant_temp_type engine_coolant_temp;
      typedef bool _engine_speed_avail_type;
      _engine_speed_avail_type engine_speed_avail;
      typedef bool _engine_torque_avail_type;
      _engine_torque_avail_type engine_torque_avail;
      typedef bool _engine_coolant_temp_avail_type;
      _engine_coolant_temp_avail_type engine_coolant_temp_avail;

    EngineRpt():
      header(),
      engine_speed(0),
      engine_torque(0),
      engine_coolant_temp(0),
      engine_speed_avail(0),
      engine_torque_avail(0),
      engine_coolant_temp_avail(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_engine_speed;
      u_engine_speed.real = this->engine_speed;
      *(outbuffer + offset + 0) = (u_engine_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_engine_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_engine_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_engine_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_engine_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_engine_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_engine_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_engine_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->engine_speed);
      union {
        double real;
        uint64_t base;
      } u_engine_torque;
      u_engine_torque.real = this->engine_torque;
      *(outbuffer + offset + 0) = (u_engine_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_engine_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_engine_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_engine_torque.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_engine_torque.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_engine_torque.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_engine_torque.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_engine_torque.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->engine_torque);
      union {
        int16_t real;
        uint16_t base;
      } u_engine_coolant_temp;
      u_engine_coolant_temp.real = this->engine_coolant_temp;
      *(outbuffer + offset + 0) = (u_engine_coolant_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_engine_coolant_temp.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->engine_coolant_temp);
      union {
        bool real;
        uint8_t base;
      } u_engine_speed_avail;
      u_engine_speed_avail.real = this->engine_speed_avail;
      *(outbuffer + offset + 0) = (u_engine_speed_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_speed_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_torque_avail;
      u_engine_torque_avail.real = this->engine_torque_avail;
      *(outbuffer + offset + 0) = (u_engine_torque_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_torque_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_coolant_temp_avail;
      u_engine_coolant_temp_avail.real = this->engine_coolant_temp_avail;
      *(outbuffer + offset + 0) = (u_engine_coolant_temp_avail.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_coolant_temp_avail);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_engine_speed;
      u_engine_speed.base = 0;
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_engine_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->engine_speed = u_engine_speed.real;
      offset += sizeof(this->engine_speed);
      union {
        double real;
        uint64_t base;
      } u_engine_torque;
      u_engine_torque.base = 0;
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_engine_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->engine_torque = u_engine_torque.real;
      offset += sizeof(this->engine_torque);
      union {
        int16_t real;
        uint16_t base;
      } u_engine_coolant_temp;
      u_engine_coolant_temp.base = 0;
      u_engine_coolant_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_engine_coolant_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->engine_coolant_temp = u_engine_coolant_temp.real;
      offset += sizeof(this->engine_coolant_temp);
      union {
        bool real;
        uint8_t base;
      } u_engine_speed_avail;
      u_engine_speed_avail.base = 0;
      u_engine_speed_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_speed_avail = u_engine_speed_avail.real;
      offset += sizeof(this->engine_speed_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_torque_avail;
      u_engine_torque_avail.base = 0;
      u_engine_torque_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_torque_avail = u_engine_torque_avail.real;
      offset += sizeof(this->engine_torque_avail);
      union {
        bool real;
        uint8_t base;
      } u_engine_coolant_temp_avail;
      u_engine_coolant_temp_avail.base = 0;
      u_engine_coolant_temp_avail.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_coolant_temp_avail = u_engine_coolant_temp_avail.real;
      offset += sizeof(this->engine_coolant_temp_avail);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/EngineRpt"; };
    const char * getMD5(){ return "ce4743585f6b90cb725120aba6ddfafc"; };

  };

}
#endif
