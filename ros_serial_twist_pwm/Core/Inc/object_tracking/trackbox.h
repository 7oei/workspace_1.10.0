#ifndef _ROS_object_tracking_trackbox_h
#define _ROS_object_tracking_trackbox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace object_tracking
{

  class trackbox : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _box_num_type;
      _box_num_type box_num;
      uint32_t x1_length;
      typedef float _x1_type;
      _x1_type st_x1;
      _x1_type * x1;
      uint32_t x2_length;
      typedef float _x2_type;
      _x2_type st_x2;
      _x2_type * x2;
      uint32_t x3_length;
      typedef float _x3_type;
      _x3_type st_x3;
      _x3_type * x3;
      uint32_t x4_length;
      typedef float _x4_type;
      _x4_type st_x4;
      _x4_type * x4;
      uint32_t y1_length;
      typedef float _y1_type;
      _y1_type st_y1;
      _y1_type * y1;
      uint32_t y2_length;
      typedef float _y2_type;
      _y2_type st_y2;
      _y2_type * y2;
      uint32_t y3_length;
      typedef float _y3_type;
      _y3_type st_y3;
      _y3_type * y3;
      uint32_t y4_length;
      typedef float _y4_type;
      _y4_type st_y4;
      _y4_type * y4;

    trackbox():
      header(),
      box_num(0),
      x1_length(0), x1(NULL),
      x2_length(0), x2(NULL),
      x3_length(0), x3(NULL),
      x4_length(0), x4(NULL),
      y1_length(0), y1(NULL),
      y2_length(0), y2(NULL),
      y3_length(0), y3(NULL),
      y4_length(0), y4(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->box_num >> (8 * 0)) & 0xFF;
      offset += sizeof(this->box_num);
      *(outbuffer + offset + 0) = (this->x1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x1_length);
      for( uint32_t i = 0; i < x1_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x1i;
      u_x1i.real = this->x1[i];
      *(outbuffer + offset + 0) = (u_x1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x1i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x1[i]);
      }
      *(outbuffer + offset + 0) = (this->x2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x2_length);
      for( uint32_t i = 0; i < x2_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x2i;
      u_x2i.real = this->x2[i];
      *(outbuffer + offset + 0) = (u_x2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x2i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x2[i]);
      }
      *(outbuffer + offset + 0) = (this->x3_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x3_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x3_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x3_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x3_length);
      for( uint32_t i = 0; i < x3_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x3i;
      u_x3i.real = this->x3[i];
      *(outbuffer + offset + 0) = (u_x3i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x3i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x3i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x3i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x3[i]);
      }
      *(outbuffer + offset + 0) = (this->x4_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x4_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x4_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x4_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x4_length);
      for( uint32_t i = 0; i < x4_length; i++){
      union {
        float real;
        uint32_t base;
      } u_x4i;
      u_x4i.real = this->x4[i];
      *(outbuffer + offset + 0) = (u_x4i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x4i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x4i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x4i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x4[i]);
      }
      *(outbuffer + offset + 0) = (this->y1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y1_length);
      for( uint32_t i = 0; i < y1_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y1i;
      u_y1i.real = this->y1[i];
      *(outbuffer + offset + 0) = (u_y1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y1i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y1[i]);
      }
      *(outbuffer + offset + 0) = (this->y2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y2_length);
      for( uint32_t i = 0; i < y2_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y2i;
      u_y2i.real = this->y2[i];
      *(outbuffer + offset + 0) = (u_y2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y2i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y2[i]);
      }
      *(outbuffer + offset + 0) = (this->y3_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y3_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y3_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y3_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y3_length);
      for( uint32_t i = 0; i < y3_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y3i;
      u_y3i.real = this->y3[i];
      *(outbuffer + offset + 0) = (u_y3i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y3i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y3i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y3i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y3[i]);
      }
      *(outbuffer + offset + 0) = (this->y4_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y4_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y4_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y4_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y4_length);
      for( uint32_t i = 0; i < y4_length; i++){
      union {
        float real;
        uint32_t base;
      } u_y4i;
      u_y4i.real = this->y4[i];
      *(outbuffer + offset + 0) = (u_y4i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y4i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y4i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y4i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y4[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->box_num =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->box_num);
      uint32_t x1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x1_length);
      if(x1_lengthT > x1_length)
        this->x1 = (float*)realloc(this->x1, x1_lengthT * sizeof(float));
      x1_length = x1_lengthT;
      for( uint32_t i = 0; i < x1_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x1;
      u_st_x1.base = 0;
      u_st_x1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x1 = u_st_x1.real;
      offset += sizeof(this->st_x1);
        memcpy( &(this->x1[i]), &(this->st_x1), sizeof(float));
      }
      uint32_t x2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x2_length);
      if(x2_lengthT > x2_length)
        this->x2 = (float*)realloc(this->x2, x2_lengthT * sizeof(float));
      x2_length = x2_lengthT;
      for( uint32_t i = 0; i < x2_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x2;
      u_st_x2.base = 0;
      u_st_x2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x2 = u_st_x2.real;
      offset += sizeof(this->st_x2);
        memcpy( &(this->x2[i]), &(this->st_x2), sizeof(float));
      }
      uint32_t x3_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x3_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x3_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x3_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x3_length);
      if(x3_lengthT > x3_length)
        this->x3 = (float*)realloc(this->x3, x3_lengthT * sizeof(float));
      x3_length = x3_lengthT;
      for( uint32_t i = 0; i < x3_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x3;
      u_st_x3.base = 0;
      u_st_x3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x3 = u_st_x3.real;
      offset += sizeof(this->st_x3);
        memcpy( &(this->x3[i]), &(this->st_x3), sizeof(float));
      }
      uint32_t x4_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x4_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x4_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x4_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x4_length);
      if(x4_lengthT > x4_length)
        this->x4 = (float*)realloc(this->x4, x4_lengthT * sizeof(float));
      x4_length = x4_lengthT;
      for( uint32_t i = 0; i < x4_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_x4;
      u_st_x4.base = 0;
      u_st_x4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_x4 = u_st_x4.real;
      offset += sizeof(this->st_x4);
        memcpy( &(this->x4[i]), &(this->st_x4), sizeof(float));
      }
      uint32_t y1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y1_length);
      if(y1_lengthT > y1_length)
        this->y1 = (float*)realloc(this->y1, y1_lengthT * sizeof(float));
      y1_length = y1_lengthT;
      for( uint32_t i = 0; i < y1_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y1;
      u_st_y1.base = 0;
      u_st_y1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y1 = u_st_y1.real;
      offset += sizeof(this->st_y1);
        memcpy( &(this->y1[i]), &(this->st_y1), sizeof(float));
      }
      uint32_t y2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y2_length);
      if(y2_lengthT > y2_length)
        this->y2 = (float*)realloc(this->y2, y2_lengthT * sizeof(float));
      y2_length = y2_lengthT;
      for( uint32_t i = 0; i < y2_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y2;
      u_st_y2.base = 0;
      u_st_y2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y2 = u_st_y2.real;
      offset += sizeof(this->st_y2);
        memcpy( &(this->y2[i]), &(this->st_y2), sizeof(float));
      }
      uint32_t y3_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y3_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y3_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y3_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y3_length);
      if(y3_lengthT > y3_length)
        this->y3 = (float*)realloc(this->y3, y3_lengthT * sizeof(float));
      y3_length = y3_lengthT;
      for( uint32_t i = 0; i < y3_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y3;
      u_st_y3.base = 0;
      u_st_y3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y3 = u_st_y3.real;
      offset += sizeof(this->st_y3);
        memcpy( &(this->y3[i]), &(this->st_y3), sizeof(float));
      }
      uint32_t y4_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y4_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y4_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y4_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y4_length);
      if(y4_lengthT > y4_length)
        this->y4 = (float*)realloc(this->y4, y4_lengthT * sizeof(float));
      y4_length = y4_lengthT;
      for( uint32_t i = 0; i < y4_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_y4;
      u_st_y4.base = 0;
      u_st_y4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_y4 = u_st_y4.real;
      offset += sizeof(this->st_y4);
        memcpy( &(this->y4[i]), &(this->st_y4), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "object_tracking/trackbox"; };
    const char * getMD5(){ return "abfa3e829554679ea1d12754b272bb49"; };

  };

}
#endif
