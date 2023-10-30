#ifndef _ROS_vector_sensors_vector_id_h
#define _ROS_vector_sensors_vector_id_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_sensors
{

  class vector_id : public ros::Msg
  {
    public:
      typedef const char* _sensor_id_type;
      _sensor_id_type sensor_id;
      typedef int32_t _port_number_type;
      _port_number_type port_number;

    vector_id():
      sensor_id(""),
      port_number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_sensor_id = strlen(this->sensor_id);
      varToArr(outbuffer + offset, length_sensor_id);
      offset += 4;
      memcpy(outbuffer + offset, this->sensor_id, length_sensor_id);
      offset += length_sensor_id;
      union {
        int32_t real;
        uint32_t base;
      } u_port_number;
      u_port_number.real = this->port_number;
      *(outbuffer + offset + 0) = (u_port_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_port_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_port_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_port_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->port_number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_sensor_id;
      arrToVar(length_sensor_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sensor_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sensor_id-1]=0;
      this->sensor_id = (char *)(inbuffer + offset-1);
      offset += length_sensor_id;
      union {
        int32_t real;
        uint32_t base;
      } u_port_number;
      u_port_number.base = 0;
      u_port_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_port_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_port_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_port_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->port_number = u_port_number.real;
      offset += sizeof(this->port_number);
     return offset;
    }

    virtual const char * getType() override { return "vector_sensors/vector_id"; };
    virtual const char * getMD5() override { return "00607cc4caa98810157216b9f8795e66"; };

  };

}
#endif
