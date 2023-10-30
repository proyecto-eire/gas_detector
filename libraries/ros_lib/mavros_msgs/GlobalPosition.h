#ifndef _ROS_mavros_msgs_GlobalPosition_h
#define _ROS_mavros_msgs_GlobalPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mavros_msgs
{

  class GlobalPosition : public ros::Msg
  {
    public:
      typedef uint32_t _time_boot_ms_type;
      _time_boot_ms_type time_boot_ms;
      typedef int32_t _lat_type;
      _lat_type lat;
      typedef int32_t _lon_type;
      _lon_type lon;
      typedef int32_t _alt_type;
      _alt_type alt;
      typedef int32_t _relative_alt_type;
      _relative_alt_type relative_alt;
      typedef int16_t _vx_type;
      _vx_type vx;
      typedef int16_t _vy_type;
      _vy_type vy;
      typedef int16_t _vz_type;
      _vz_type vz;
      typedef uint16_t _hdg_type;
      _hdg_type hdg;

    GlobalPosition():
      time_boot_ms(0),
      lat(0),
      lon(0),
      alt(0),
      relative_alt(0),
      vx(0),
      vy(0),
      vz(0),
      hdg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time_boot_ms >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_boot_ms >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_boot_ms >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_boot_ms >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_boot_ms);
      union {
        int32_t real;
        uint32_t base;
      } u_lat;
      u_lat.real = this->lat;
      *(outbuffer + offset + 0) = (u_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lat);
      union {
        int32_t real;
        uint32_t base;
      } u_lon;
      u_lon.real = this->lon;
      *(outbuffer + offset + 0) = (u_lon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lon);
      union {
        int32_t real;
        uint32_t base;
      } u_alt;
      u_alt.real = this->alt;
      *(outbuffer + offset + 0) = (u_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alt);
      union {
        int32_t real;
        uint32_t base;
      } u_relative_alt;
      u_relative_alt.real = this->relative_alt;
      *(outbuffer + offset + 0) = (u_relative_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_alt);
      union {
        int16_t real;
        uint16_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        int16_t real;
        uint16_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        int16_t real;
        uint16_t base;
      } u_vz;
      u_vz.real = this->vz;
      *(outbuffer + offset + 0) = (u_vz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vz.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vz);
      *(outbuffer + offset + 0) = (this->hdg >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hdg >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hdg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->time_boot_ms =  ((uint32_t) (*(inbuffer + offset)));
      this->time_boot_ms |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_boot_ms |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_boot_ms |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_boot_ms);
      union {
        int32_t real;
        uint32_t base;
      } u_lat;
      u_lat.base = 0;
      u_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lat = u_lat.real;
      offset += sizeof(this->lat);
      union {
        int32_t real;
        uint32_t base;
      } u_lon;
      u_lon.base = 0;
      u_lon.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lon = u_lon.real;
      offset += sizeof(this->lon);
      union {
        int32_t real;
        uint32_t base;
      } u_alt;
      u_alt.base = 0;
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alt = u_alt.real;
      offset += sizeof(this->alt);
      union {
        int32_t real;
        uint32_t base;
      } u_relative_alt;
      u_relative_alt.base = 0;
      u_relative_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_alt = u_relative_alt.real;
      offset += sizeof(this->relative_alt);
      union {
        int16_t real;
        uint16_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        int16_t real;
        uint16_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        int16_t real;
        uint16_t base;
      } u_vz;
      u_vz.base = 0;
      u_vz.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vz.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vz = u_vz.real;
      offset += sizeof(this->vz);
      this->hdg =  ((uint16_t) (*(inbuffer + offset)));
      this->hdg |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hdg);
     return offset;
    }

    virtual const char * getType() override { return "mavros_msgs/GlobalPosition"; };
    virtual const char * getMD5() override { return "f1f84b3a3a0c324e73c3830e9000efab"; };

  };

}
#endif
