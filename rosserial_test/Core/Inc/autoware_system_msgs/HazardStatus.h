#ifndef _ROS_autoware_system_msgs_HazardStatus_h
#define _ROS_autoware_system_msgs_HazardStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/DiagnosticStatus.h"

namespace autoware_system_msgs
{

  class HazardStatus : public ros::Msg
  {
    public:
      typedef int32_t _level_type;
      _level_type level;
      uint32_t diagnostics_nf_length;
      typedef diagnostic_msgs::DiagnosticStatus _diagnostics_nf_type;
      _diagnostics_nf_type st_diagnostics_nf;
      _diagnostics_nf_type * diagnostics_nf;
      uint32_t diagnostics_sf_length;
      typedef diagnostic_msgs::DiagnosticStatus _diagnostics_sf_type;
      _diagnostics_sf_type st_diagnostics_sf;
      _diagnostics_sf_type * diagnostics_sf;
      uint32_t diagnostics_lf_length;
      typedef diagnostic_msgs::DiagnosticStatus _diagnostics_lf_type;
      _diagnostics_lf_type st_diagnostics_lf;
      _diagnostics_lf_type * diagnostics_lf;
      uint32_t diagnostics_spf_length;
      typedef diagnostic_msgs::DiagnosticStatus _diagnostics_spf_type;
      _diagnostics_spf_type st_diagnostics_spf;
      _diagnostics_spf_type * diagnostics_spf;
      enum { NO_FAULT =  0 };
      enum { SAFE_FAULT =  1 };
      enum { LATENT_FAULT =  2 };
      enum { SINGLE_POINT_FAULT =  3 };

    HazardStatus():
      level(0),
      diagnostics_nf_length(0), diagnostics_nf(NULL),
      diagnostics_sf_length(0), diagnostics_sf(NULL),
      diagnostics_lf_length(0), diagnostics_lf(NULL),
      diagnostics_spf_length(0), diagnostics_spf(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_level;
      u_level.real = this->level;
      *(outbuffer + offset + 0) = (u_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->level);
      *(outbuffer + offset + 0) = (this->diagnostics_nf_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->diagnostics_nf_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->diagnostics_nf_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->diagnostics_nf_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diagnostics_nf_length);
      for( uint32_t i = 0; i < diagnostics_nf_length; i++){
      offset += this->diagnostics_nf[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->diagnostics_sf_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->diagnostics_sf_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->diagnostics_sf_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->diagnostics_sf_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diagnostics_sf_length);
      for( uint32_t i = 0; i < diagnostics_sf_length; i++){
      offset += this->diagnostics_sf[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->diagnostics_lf_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->diagnostics_lf_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->diagnostics_lf_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->diagnostics_lf_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diagnostics_lf_length);
      for( uint32_t i = 0; i < diagnostics_lf_length; i++){
      offset += this->diagnostics_lf[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->diagnostics_spf_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->diagnostics_spf_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->diagnostics_spf_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->diagnostics_spf_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diagnostics_spf_length);
      for( uint32_t i = 0; i < diagnostics_spf_length; i++){
      offset += this->diagnostics_spf[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_level;
      u_level.base = 0;
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->level = u_level.real;
      offset += sizeof(this->level);
      uint32_t diagnostics_nf_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      diagnostics_nf_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      diagnostics_nf_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      diagnostics_nf_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->diagnostics_nf_length);
      if(diagnostics_nf_lengthT > diagnostics_nf_length)
        this->diagnostics_nf = (diagnostic_msgs::DiagnosticStatus*)realloc(this->diagnostics_nf, diagnostics_nf_lengthT * sizeof(diagnostic_msgs::DiagnosticStatus));
      diagnostics_nf_length = diagnostics_nf_lengthT;
      for( uint32_t i = 0; i < diagnostics_nf_length; i++){
      offset += this->st_diagnostics_nf.deserialize(inbuffer + offset);
        memcpy( &(this->diagnostics_nf[i]), &(this->st_diagnostics_nf), sizeof(diagnostic_msgs::DiagnosticStatus));
      }
      uint32_t diagnostics_sf_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      diagnostics_sf_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      diagnostics_sf_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      diagnostics_sf_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->diagnostics_sf_length);
      if(diagnostics_sf_lengthT > diagnostics_sf_length)
        this->diagnostics_sf = (diagnostic_msgs::DiagnosticStatus*)realloc(this->diagnostics_sf, diagnostics_sf_lengthT * sizeof(diagnostic_msgs::DiagnosticStatus));
      diagnostics_sf_length = diagnostics_sf_lengthT;
      for( uint32_t i = 0; i < diagnostics_sf_length; i++){
      offset += this->st_diagnostics_sf.deserialize(inbuffer + offset);
        memcpy( &(this->diagnostics_sf[i]), &(this->st_diagnostics_sf), sizeof(diagnostic_msgs::DiagnosticStatus));
      }
      uint32_t diagnostics_lf_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      diagnostics_lf_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      diagnostics_lf_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      diagnostics_lf_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->diagnostics_lf_length);
      if(diagnostics_lf_lengthT > diagnostics_lf_length)
        this->diagnostics_lf = (diagnostic_msgs::DiagnosticStatus*)realloc(this->diagnostics_lf, diagnostics_lf_lengthT * sizeof(diagnostic_msgs::DiagnosticStatus));
      diagnostics_lf_length = diagnostics_lf_lengthT;
      for( uint32_t i = 0; i < diagnostics_lf_length; i++){
      offset += this->st_diagnostics_lf.deserialize(inbuffer + offset);
        memcpy( &(this->diagnostics_lf[i]), &(this->st_diagnostics_lf), sizeof(diagnostic_msgs::DiagnosticStatus));
      }
      uint32_t diagnostics_spf_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      diagnostics_spf_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      diagnostics_spf_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      diagnostics_spf_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->diagnostics_spf_length);
      if(diagnostics_spf_lengthT > diagnostics_spf_length)
        this->diagnostics_spf = (diagnostic_msgs::DiagnosticStatus*)realloc(this->diagnostics_spf, diagnostics_spf_lengthT * sizeof(diagnostic_msgs::DiagnosticStatus));
      diagnostics_spf_length = diagnostics_spf_lengthT;
      for( uint32_t i = 0; i < diagnostics_spf_length; i++){
      offset += this->st_diagnostics_spf.deserialize(inbuffer + offset);
        memcpy( &(this->diagnostics_spf[i]), &(this->st_diagnostics_spf), sizeof(diagnostic_msgs::DiagnosticStatus));
      }
     return offset;
    }

    const char * getType(){ return "autoware_system_msgs/HazardStatus"; };
    const char * getMD5(){ return "3885da78760136cf1eec24e0e45c23ab"; };

  };

}
#endif
