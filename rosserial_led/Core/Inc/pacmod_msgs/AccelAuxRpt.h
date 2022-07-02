#ifndef _ROS_pacmod_msgs_AccelAuxRpt_h
#define _ROS_pacmod_msgs_AccelAuxRpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class AccelAuxRpt : public ros::Msg
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
      typedef bool _user_interaction_type;
      _user_interaction_type user_interaction;
      typedef bool _user_interaction_is_valid_type;
      _user_interaction_is_valid_type user_interaction_is_valid;
      typedef bool _brake_interlock_active_type;
      _brake_interlock_active_type brake_interlock_active;
      typedef bool _brake_interlock_active_is_valid_type;
      _brake_interlock_active_is_valid_type brake_interlock_active_is_valid;

    AccelAuxRpt():
      header(),
      raw_pedal_pos(0),
      raw_pedal_pos_is_valid(0),
      raw_pedal_force(0),
      raw_pedal_force_is_valid(0),
      user_interaction(0),
      user_interaction_is_valid(0),
      brake_interlock_active(0),
      brake_interlock_active_is_valid(0)
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
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active;
      u_brake_interlock_active.real = this->brake_interlock_active;
      *(outbuffer + offset + 0) = (u_brake_interlock_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active_is_valid;
      u_brake_interlock_active_is_valid.real = this->brake_interlock_active_is_valid;
      *(outbuffer + offset + 0) = (u_brake_interlock_active_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_interlock_active_is_valid);
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
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active;
      u_brake_interlock_active.base = 0;
      u_brake_interlock_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_interlock_active = u_brake_interlock_active.real;
      offset += sizeof(this->brake_interlock_active);
      union {
        bool real;
        uint8_t base;
      } u_brake_interlock_active_is_valid;
      u_brake_interlock_active_is_valid.base = 0;
      u_brake_interlock_active_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_interlock_active_is_valid = u_brake_interlock_active_is_valid.real;
      offset += sizeof(this->brake_interlock_active_is_valid);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/AccelAuxRpt"; };
    const char * getMD5(){ return "2f644f02020323fdb0afab1a11b54b70"; };

  };

}
#endif
