#ifndef _ROS_vector_sensors_vector_id_complete_h
#define _ROS_vector_sensors_vector_id_complete_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_sensors
{

  class vector_id_complete : public ros::Msg
  {
    public:
      uint32_t num_ports_length;
      typedef int32_t _num_ports_type;
      _num_ports_type st_num_ports;
      _num_ports_type * num_ports;
      enum { MQ2 = 0 };
      enum { MQ3 = 1 };

    vector_id_complete():
      num_ports_length(0), st_num_ports(), num_ports(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->num_ports_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_ports_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_ports_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_ports_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_ports_length);
      for( uint32_t i = 0; i < num_ports_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_num_portsi;
      u_num_portsi.real = this->num_ports[i];
      *(outbuffer + offset + 0) = (u_num_portsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_portsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_portsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_portsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_ports[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t num_ports_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      num_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      num_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      num_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->num_ports_length);
      if(num_ports_lengthT > num_ports_length)
        this->num_ports = (int32_t*)realloc(this->num_ports, num_ports_lengthT * sizeof(int32_t));
      num_ports_length = num_ports_lengthT;
      for( uint32_t i = 0; i < num_ports_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_num_ports;
      u_st_num_ports.base = 0;
      u_st_num_ports.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_num_ports.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_num_ports.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_num_ports.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_num_ports = u_st_num_ports.real;
      offset += sizeof(this->st_num_ports);
        memcpy( &(this->num_ports[i]), &(this->st_num_ports), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "vector_sensors/vector_id_complete"; };
    virtual const char * getMD5() override { return "c978ba007e38f13f5f52595877593a30"; };

  };

}
#endif
