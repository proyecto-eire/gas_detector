#ifndef _ROS_swarm_common_Alert_h
#define _ROS_swarm_common_Alert_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace swarm_common
{

  class Alert : public ros::Msg
  {
    public:
      typedef bool _active_type;
      _active_type active;
      typedef uint8_t _alert_id_type;
      _alert_id_type alert_id;

    Alert():
      active(0),
      alert_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      *(outbuffer + offset + 0) = (this->alert_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alert_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
      this->alert_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->alert_id);
     return offset;
    }

    virtual const char * getType() override { return "swarm_common/Alert"; };
    virtual const char * getMD5() override { return "3743445f88a6d1b08b3448a1ea4b507a"; };

  };

}
#endif
