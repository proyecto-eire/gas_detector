#ifndef _ROS_vector_sensors_vector_id_value_h
#define _ROS_vector_sensors_vector_id_value_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_sensors
{

  class vector_id_value : public ros::Msg
  {
    public:
      uint32_t sensors_names_length;
      typedef char* _sensors_names_type;
      _sensors_names_type st_sensors_names;
      _sensors_names_type * sensors_names;
      uint32_t sensors_pins_length;
      typedef uint8_t _sensors_pins_type;
      _sensors_pins_type st_sensors_pins;
      _sensors_pins_type * sensors_pins;
      uint32_t sensors_values_length;
      typedef uint8_t _sensors_values_type;
      _sensors_values_type st_sensors_values;
      _sensors_values_type * sensors_values;
      enum { MQ2 = 0 };
      enum { MQ3 = 1 };
      enum { MQ4 = 2 };
      enum { MQ5 = 3 };
      enum { MQ6 = 8 };
      enum { MQ7 = 7 };
      enum { MQ8 = 6 };
      enum { MQ9 = 5 };
      enum { MQ135 = 4 };

    vector_id_value():
      sensors_names_length(0), st_sensors_names(), sensors_names(nullptr),
      sensors_pins_length(0), st_sensors_pins(), sensors_pins(nullptr),
      sensors_values_length(0), st_sensors_values(), sensors_values(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sensors_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_names_length);
      for( uint32_t i = 0; i < sensors_names_length; i++){
      uint32_t length_sensors_namesi = strlen(this->sensors_names[i]);
      varToArr(outbuffer + offset, length_sensors_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->sensors_names[i], length_sensors_namesi);
      offset += length_sensors_namesi;
      }
      *(outbuffer + offset + 0) = (this->sensors_pins_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_pins_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_pins_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_pins_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_pins_length);
      for( uint32_t i = 0; i < sensors_pins_length; i++){
      *(outbuffer + offset + 0) = (this->sensors_pins[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensors_pins[i]);
      }
      *(outbuffer + offset + 0) = (this->sensors_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_values_length);
      for( uint32_t i = 0; i < sensors_values_length; i++){
      *(outbuffer + offset + 0) = (this->sensors_values[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensors_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t sensors_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensors_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensors_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensors_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensors_names_length);
      if(sensors_names_lengthT > sensors_names_length)
        this->sensors_names = (char**)realloc(this->sensors_names, sensors_names_lengthT * sizeof(char*));
      sensors_names_length = sensors_names_lengthT;
      for( uint32_t i = 0; i < sensors_names_length; i++){
      uint32_t length_st_sensors_names;
      arrToVar(length_st_sensors_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_sensors_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_sensors_names-1]=0;
      this->st_sensors_names = (char *)(inbuffer + offset-1);
      offset += length_st_sensors_names;
        memcpy( &(this->sensors_names[i]), &(this->st_sensors_names), sizeof(char*));
      }
      uint32_t sensors_pins_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensors_pins_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensors_pins_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensors_pins_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensors_pins_length);
      if(sensors_pins_lengthT > sensors_pins_length)
        this->sensors_pins = (uint8_t*)realloc(this->sensors_pins, sensors_pins_lengthT * sizeof(uint8_t));
      sensors_pins_length = sensors_pins_lengthT;
      for( uint32_t i = 0; i < sensors_pins_length; i++){
      this->st_sensors_pins =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_sensors_pins);
        memcpy( &(this->sensors_pins[i]), &(this->st_sensors_pins), sizeof(uint8_t));
      }
      uint32_t sensors_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensors_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensors_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensors_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensors_values_length);
      if(sensors_values_lengthT > sensors_values_length)
        this->sensors_values = (uint8_t*)realloc(this->sensors_values, sensors_values_lengthT * sizeof(uint8_t));
      sensors_values_length = sensors_values_lengthT;
      for( uint32_t i = 0; i < sensors_values_length; i++){
      this->st_sensors_values =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_sensors_values);
        memcpy( &(this->sensors_values[i]), &(this->st_sensors_values), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "vector_sensors/vector_id_value"; };
    virtual const char * getMD5() override { return "8401812b7aeddbf54d908cda1adab61d"; };

  };

}
#endif
