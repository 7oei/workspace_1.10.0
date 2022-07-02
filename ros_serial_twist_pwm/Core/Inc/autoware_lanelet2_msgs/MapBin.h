#ifndef _ROS_autoware_lanelet2_msgs_MapBin_h
#define _ROS_autoware_lanelet2_msgs_MapBin_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autoware_lanelet2_msgs
{

  class MapBin : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _format_version_type;
      _format_version_type format_version;
      typedef const char* _map_version_type;
      _map_version_type map_version;
      uint32_t data_length;
      typedef int8_t _data_type;
      _data_type st_data;
      _data_type * data;

    MapBin():
      header(),
      format_version(""),
      map_version(""),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_format_version = strlen(this->format_version);
      varToArr(outbuffer + offset, length_format_version);
      offset += 4;
      memcpy(outbuffer + offset, this->format_version, length_format_version);
      offset += length_format_version;
      uint32_t length_map_version = strlen(this->map_version);
      varToArr(outbuffer + offset, length_map_version);
      offset += 4;
      memcpy(outbuffer + offset, this->map_version, length_map_version);
      offset += length_map_version;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_format_version;
      arrToVar(length_format_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_format_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_format_version-1]=0;
      this->format_version = (char *)(inbuffer + offset-1);
      offset += length_format_version;
      uint32_t length_map_version;
      arrToVar(length_map_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_map_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_map_version-1]=0;
      this->map_version = (char *)(inbuffer + offset-1);
      offset += length_map_version;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (int8_t*)realloc(this->data, data_lengthT * sizeof(int8_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(int8_t));
      }
     return offset;
    }

    const char * getType(){ return "autoware_lanelet2_msgs/MapBin"; };
    const char * getMD5(){ return "9d7c66d4c8e6e3f95a20131a6e37fe22"; };

  };

}
#endif
