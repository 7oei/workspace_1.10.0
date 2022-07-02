#ifndef _ROS_pacmod_msgs_BrakeAuxRpt_h
#define _ROS_pacmod_msgs_BrakeAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class BrakeAuxRpt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _raw_pedal_pos_type;
      _raw_pedal_pos_type raw_pedal_pos;
      typedef bool _raw_pedal_pos_is_valid_type;
      _raw_pedal_pos_is_valid_type raw_pedal_pos_is_valid;
      typedef double _raw_pedal_force_type;
      _raw_pedal_force_type raw_pedal_force;
      typedef bool _raw_pedal_force_is_valid_type;
      _raw_pedal_force_is_valid_type raw_pedal_force_is_valid;
      typedef double _raw_brake_pressure_type;
      _raw_brake_pressure_type raw_brake_pressure;
      typedef bool _raw_brake_pressure_is_valid_type;
      _raw_brake_pressure_is_valid_type raw_brake_pressure_is_valid;
      typedef bool _brake_on_off_type;
      _brake_on_off_type brake_on_off;
      typedef bool _brake_on_off_is_valid_type;
      _brake_on_off_is_valid_type brake_on_off_is_valid;
      typedef bool _user_interaction_type;
      _user_interaction_type user_interaction;
      typedef bool _user_interaction_is_valid_type;
      _user_interaction_is_valid_type user_interaction_is_valid;

    BrakeAuxRpt():
      header(),
      raw_pedal_pos(0),
      raw_pedal_pos_is_valid(0),
      raw_pedal_force(0),
      raw_pedal_force_is_valid(0),
      raw_brake_pressure(0),
      raw_brake_pressure_is_valid(0),
      brake_on_off(0),
      brake_on_off_is_valid(0),
      user_interaction(0),
      user_interaction_is_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_raw_pedal_pos;
      u_raw_pedal_pos.real = this->raw_pedal_pos;
      *(outbuffer + offset + 0) = (u_raw_pedal_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_pedal_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_pedal_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_pedal_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_raw_pedal_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_raw_pedal_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_raw_pedal_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_raw_pedal_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->raw_pedal_pos);
      union {
        bool real;
        uint8_t base;
      } u_raw_pedal_pos_is_valid;
      u_raw_pedal_pos_is_valid.real = this->raw_pedal_pos_is_valid;
      *(outbuffer + offset + 0) = (u_raw_pedal_pos_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_pedal_pos_is_valid);
      union {
        double real;
        uint64_t base;
      } u_raw_pedal_force;
      u_raw_pedal_force.real = this->raw_pedal_force;
      *(outbuffer + offset + 0) = (u_raw_pedal_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_pedal_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_pedal_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_pedal_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_raw_pedal_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_raw_pedal_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_raw_pedal_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_raw_pedal_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->raw_pedal_force);
      union {
        bool real;
        uint8_t base;
      } u_raw_pedal_force_is_valid;
      u_raw_pedal_force_is_valid.real = this->raw_pedal_force_is_valid;
      *(outbuffer + offset + 0) = (u_raw_pedal_force_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_pedal_force_is_valid);
      union {
        double real;
        uint64_t base;
      } u_raw_brake_pressure;
      u_raw_brake_pressure.real = this->raw_brake_pressure;
      *(outbuffer + offset + 0) = (u_raw_brake_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_brake_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_brake_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_brake_pressure.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_raw_brake_pressure.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_raw_brake_pressure.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_raw_brake_pressure.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_raw_brake_pressure.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->raw_brake_pressure);
      union {
        bool real;
        uint8_t base;
      } u_raw_brake_pressure_is_valid;
      u_raw_brake_pressure_is_valid.real = this->raw_brake_pressure_is_valid;
      *(outbuffer + offset + 0) = (u_raw_brake_pressure_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_brake_pressure_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_brake_on_off;
      u_brake_on_off.real = this->brake_on_off;
      *(outbuffer + offset + 0) = (u_brake_on_off.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_on_off);
      union {
        bool real;
        uint8_t base;
      } u_brake_on_off_is_valid;
      u_brake_on_off_is_valid.real = this->brake_on_off_is_valid;
      *(outbuffer + offset + 0) = (u_brake_on_off_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_on_off_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction;
      u_user_interaction.real = this->user_interaction;
      *(outbuffer + offset + 0) = (u_user_interaction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_interaction);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction_is_valid;
      u_user_interaction_is_valid.real = this->user_interaction_is_valid;
      *(outbuffer + offset + 0) = (u_user_interaction_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_interaction_is_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_raw_pedal_pos;
      u_raw_pedal_pos.base = 0;
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_raw_pedal_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->raw_pedal_pos = u_raw_pedal_pos.real;
      offset += sizeof(this->raw_pedal_pos);
      union {
        bool real;
        uint8_t base;
      } u_raw_pedal_pos_is_valid;
      u_raw_pedal_pos_is_valid.base = 0;
      u_raw_pedal_pos_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->raw_pedal_pos_is_valid = u_raw_pedal_pos_is_valid.real;
      offset += sizeof(this->raw_pedal_pos_is_valid);
      union {
        double real;
        uint64_t base;
      } u_raw_pedal_force;
      u_raw_pedal_force.base = 0;
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_raw_pedal_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->raw_pedal_force = u_raw_pedal_force.real;
      offset += sizeof(this->raw_pedal_force);
      union {
        bool real;
        uint8_t base;
      } u_raw_pedal_force_is_valid;
      u_raw_pedal_force_is_valid.base = 0;
      u_raw_pedal_force_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->raw_pedal_force_is_valid = u_raw_pedal_force_is_valid.real;
      offset += sizeof(this->raw_pedal_force_is_valid);
      union {
        double real;
        uint64_t base;
      } u_raw_brake_pressure;
      u_raw_brake_pressure.base = 0;
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_raw_brake_pressure.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->raw_brake_pressure = u_raw_brake_pressure.real;
      offset += sizeof(this->raw_brake_pressure);
      union {
        bool real;
        uint8_t base;
      } u_raw_brake_pressure_is_valid;
      u_raw_brake_pressure_is_valid.base = 0;
      u_raw_brake_pressure_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->raw_brake_pressure_is_valid = u_raw_brake_pressure_is_valid.real;
      offset += sizeof(this->raw_brake_pressure_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_brake_on_off;
      u_brake_on_off.base = 0;
      u_brake_on_off.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_on_off = u_brake_on_off.real;
      offset += sizeof(this->brake_on_off);
      union {
        bool real;
        uint8_t base;
      } u_brake_on_off_is_valid;
      u_brake_on_off_is_valid.base = 0;
      u_brake_on_off_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_on_off_is_valid = u_brake_on_off_is_valid.real;
      offset += sizeof(this->brake_on_off_is_valid);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction;
      u_user_interaction.base = 0;
      u_user_interaction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_interaction = u_user_interaction.real;
      offset += sizeof(this->user_interaction);
      union {
        bool real;
        uint8_t base;
      } u_user_interaction_is_valid;
      u_user_interaction_is_valid.base = 0;
      u_user_interaction_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_interaction_is_valid = u_user_interaction_is_valid.real;
      offset += sizeof(this->user_interaction_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/BrakeAuxRpt"; };
    const char * getMD5(){ return "1b24f296f5fabbe64603c0988f5aae5b"; };

  };

}
#endif
