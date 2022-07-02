#ifndef _ROS_bno055_usb_stick_msgs_CalibrationStatus_h
#define _ROS_bno055_usb_stick_msgs_CalibrationStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bno055_usb_stick_msgs
{

  class CalibrationStatus : public ros::Msg
  {
    public:
      typedef uint16_t _system_type;
      _system_type system;
      typedef uint16_t _gyroscope_type;
      _gyroscope_type gyroscope;
      typedef uint16_t _accelerometer_type;
      _accelerometer_type accelerometer;
      typedef uint16_t _magnetometer_type;
      _magnetometer_type magnetometer;

    CalibrationStatus():
      system(0),
      gyroscope(0),
      accelerometer(0),
      magnetometer(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->system >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->system >> (8 * 1)) & 0xFF;
      offset += sizeof(this->system);
      *(outbuffer + offset + 0) = (this->gyroscope >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gyroscope >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyroscope);
      *(outbuffer + offset + 0) = (this->accelerometer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerometer >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accelerometer);
      *(outbuffer + offset + 0) = (this->magnetometer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->magnetometer >> (8 * 1)) & 0xFF;
      offset += sizeof(this->magnetometer);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->system =  ((uint16_t) (*(inbuffer + offset)));
      this->system |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->system);
      this->gyroscope =  ((uint16_t) (*(inbuffer + offset)));
      this->gyroscope |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gyroscope);
      this->accelerometer =  ((uint16_t) (*(inbuffer + offset)));
      this->accelerometer |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->accelerometer);
      this->magnetometer =  ((uint16_t) (*(inbuffer + offset)));
      this->magnetometer |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->magnetometer);
     return offset;
    }

    const char * getType(){ return "bno055_usb_stick_msgs/CalibrationStatus"; };
    const char * getMD5(){ return "dcc2b46dfebad9476df3c38a333f4515"; };

  };

}
#endif
