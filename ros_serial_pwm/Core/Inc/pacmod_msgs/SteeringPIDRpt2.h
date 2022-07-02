#ifndef _ROS_pacmod_msgs_SteeringPIDRpt2_h
#define _ROS_pacmod_msgs_SteeringPIDRpt2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pacmod_msgs
{

  class SteeringPIDRpt2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _p_term_type;
      _p_term_type p_term;
      typedef double _i_term_type;
      _i_term_type i_term;
      typedef double _d_term_type;
      _d_term_type d_term;
      typedef double _all_terms_type;
      _all_terms_type all_terms;

    SteeringPIDRpt2():
      header(),
      p_term(0),
      i_term(0),
      d_term(0),
      all_terms(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_p_term;
      u_p_term.real = this->p_term;
      *(outbuffer + offset + 0) = (u_p_term.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p_term.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_p_term.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_p_term.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_p_term.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_p_term.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_p_term.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_p_term.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->p_term);
      union {
        double real;
        uint64_t base;
      } u_i_term;
      u_i_term.real = this->i_term;
      *(outbuffer + offset + 0) = (u_i_term.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_term.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_term.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_term.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_i_term.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_i_term.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_i_term.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_i_term.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->i_term);
      union {
        double real;
        uint64_t base;
      } u_d_term;
      u_d_term.real = this->d_term;
      *(outbuffer + offset + 0) = (u_d_term.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d_term.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_d_term.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_d_term.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_d_term.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_d_term.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_d_term.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_d_term.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->d_term);
      union {
        double real;
        uint64_t base;
      } u_all_terms;
      u_all_terms.real = this->all_terms;
      *(outbuffer + offset + 0) = (u_all_terms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_all_terms.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_all_terms.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_all_terms.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_all_terms.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_all_terms.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_all_terms.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_all_terms.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->all_terms);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_p_term;
      u_p_term.base = 0;
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_p_term.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->p_term = u_p_term.real;
      offset += sizeof(this->p_term);
      union {
        double real;
        uint64_t base;
      } u_i_term;
      u_i_term.base = 0;
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_i_term.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->i_term = u_i_term.real;
      offset += sizeof(this->i_term);
      union {
        double real;
        uint64_t base;
      } u_d_term;
      u_d_term.base = 0;
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_d_term.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->d_term = u_d_term.real;
      offset += sizeof(this->d_term);
      union {
        double real;
        uint64_t base;
      } u_all_terms;
      u_all_terms.base = 0;
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_all_terms.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->all_terms = u_all_terms.real;
      offset += sizeof(this->all_terms);
     return offset;
    }

    const char * getType(){ return "pacmod_msgs/SteeringPIDRpt2"; };
    const char * getMD5(){ return "1adfcb7e7b84f38f1763878f5d8e8ff5"; };

  };

}
#endif
