#ifndef _ROS_bno055_usb_stick_msgs_Output_h
#define _ROS_bno055_usb_stick_msgs_Output_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "bno055_usb_stick_msgs/EulerAngles.h"
#include "geometry_msgs/Quaternion.h"
#include "bno055_usb_stick_msgs/CalibrationStatus.h"

namespace bno055_usb_stick_msgs
{

  class Output : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _magnetometer_type;
      _magnetometer_type magnetometer;
      typedef geometry_msgs::Vector3 _gyroscope_type;
      _gyroscope_type gyroscope;
      typedef bno055_usb_stick_msgs::EulerAngles _euler_angles_type;
      _euler_angles_type euler_angles;
      typedef geometry_msgs::Quaternion _quaternion_type;
      _quaternion_type quaternion;
      typedef geometry_msgs::Vector3 _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      typedef geometry_msgs::Vector3 _gravity_vector_type;
      _gravity_vector_type gravity_vector;
      typedef double _temperature_type;
      _temperature_type temperature;
      typedef bno055_usb_stick_msgs::CalibrationStatus _calibration_status_type;
      _calibration_status_type calibration_status;

    Output():
      header(),
      acceleration(),
      magnetometer(),
      gyroscope(),
      euler_angles(),
      quaternion(),
      linear_acceleration(),
      gravity_vector(),
      temperature(0),
      calibration_status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->magnetometer.serialize(outbuffer + offset);
      offset += this->gyroscope.serialize(outbuffer + offset);
      offset += this->euler_angles.serialize(outbuffer + offset);
      offset += this->quaternion.serialize(outbuffer + offset);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      offset += this->gravity_vector.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature);
      offset += this->calibration_status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->magnetometer.deserialize(inbuffer + offset);
      offset += this->gyroscope.deserialize(inbuffer + offset);
      offset += this->euler_angles.deserialize(inbuffer + offset);
      offset += this->quaternion.deserialize(inbuffer + offset);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      offset += this->gravity_vector.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      offset += this->calibration_status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "bno055_usb_stick_msgs/Output"; };
    const char * getMD5(){ return "1189549f30b7c0d425e89b36006afea6"; };

  };

}
#endif
