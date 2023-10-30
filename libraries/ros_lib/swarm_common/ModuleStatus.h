#ifndef _ROS_swarm_common_ModuleStatus_h
#define _ROS_swarm_common_ModuleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace swarm_common
{

  class ModuleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _module_type;
      _module_type module;
      typedef bool _status_type;
      _status_type status;
      uint32_t errors_length;
      typedef uint16_t _errors_type;
      _errors_type st_errors;
      _errors_type * errors;

    ModuleStatus():
      header(),
      module(0),
      status(0),
      errors_length(0), st_errors(), errors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->module >> (8 * 0)) & 0xFF;
      offset += sizeof(this->module);
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->errors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->errors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->errors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->errors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->errors_length);
      for( uint32_t i = 0; i < errors_length; i++){
      *(outbuffer + offset + 0) = (this->errors[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->errors[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->errors[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->module =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->module);
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      uint32_t errors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      errors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->errors_length);
      if(errors_lengthT > errors_length)
        this->errors = (uint16_t*)realloc(this->errors, errors_lengthT * sizeof(uint16_t));
      errors_length = errors_lengthT;
      for( uint32_t i = 0; i < errors_length; i++){
      this->st_errors =  ((uint16_t) (*(inbuffer + offset)));
      this->st_errors |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_errors);
        memcpy( &(this->errors[i]), &(this->st_errors), sizeof(uint16_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "swarm_common/ModuleStatus"; };
    virtual const char * getMD5() override { return "417d9c87dee4200ec3a6cdf64b71621f"; };

  };

}
#endif
