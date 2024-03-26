#ifndef _ROS_ros_msd700_msgs_HardwareState_h
#define _ROS_ros_msd700_msgs_HardwareState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_msd700_msgs
{

  class HardwareState : public ros::Msg
  {
    public:
      typedef float _ch_ultrasonic_distance_1_type;
      _ch_ultrasonic_distance_1_type ch_ultrasonic_distance_1;
      typedef float _ch_ultrasonic_distance_2_type;
      _ch_ultrasonic_distance_2_type ch_ultrasonic_distance_2;
      typedef float _ch_ultrasonic_distance_3_type;
      _ch_ultrasonic_distance_3_type ch_ultrasonic_distance_3;
      typedef float _ch_ultrasonic_distance_4_type;
      _ch_ultrasonic_distance_4_type ch_ultrasonic_distance_4;
      typedef float _ch_ultrasonic_distance_5_type;
      _ch_ultrasonic_distance_5_type ch_ultrasonic_distance_5;
      typedef float _ch_ultrasonic_distance_6_type;
      _ch_ultrasonic_distance_6_type ch_ultrasonic_distance_6;
      typedef float _ch_ultrasonic_distance_7_type;
      _ch_ultrasonic_distance_7_type ch_ultrasonic_distance_7;
      typedef float _ch_ultrasonic_distance_8_type;
      _ch_ultrasonic_distance_8_type ch_ultrasonic_distance_8;
      typedef int32_t _right_motor_pulse_delta_type;
      _right_motor_pulse_delta_type right_motor_pulse_delta;
      typedef int32_t _left_motor_pulse_delta_type;
      _left_motor_pulse_delta_type left_motor_pulse_delta;
      typedef float _heading_type;
      _heading_type heading;

    HardwareState():
      ch_ultrasonic_distance_1(0),
      ch_ultrasonic_distance_2(0),
      ch_ultrasonic_distance_3(0),
      ch_ultrasonic_distance_4(0),
      ch_ultrasonic_distance_5(0),
      ch_ultrasonic_distance_6(0),
      ch_ultrasonic_distance_7(0),
      ch_ultrasonic_distance_8(0),
      right_motor_pulse_delta(0),
      left_motor_pulse_delta(0),
      heading(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_1;
      u_ch_ultrasonic_distance_1.real = this->ch_ultrasonic_distance_1;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_1);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_2;
      u_ch_ultrasonic_distance_2.real = this->ch_ultrasonic_distance_2;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_2);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_3;
      u_ch_ultrasonic_distance_3.real = this->ch_ultrasonic_distance_3;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_3);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_4;
      u_ch_ultrasonic_distance_4.real = this->ch_ultrasonic_distance_4;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_4);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_5;
      u_ch_ultrasonic_distance_5.real = this->ch_ultrasonic_distance_5;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_5);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_6;
      u_ch_ultrasonic_distance_6.real = this->ch_ultrasonic_distance_6;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_6.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_6);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_7;
      u_ch_ultrasonic_distance_7.real = this->ch_ultrasonic_distance_7;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_7.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_7.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_7.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_7.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_7);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_8;
      u_ch_ultrasonic_distance_8.real = this->ch_ultrasonic_distance_8;
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distance_8.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distance_8.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distance_8.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distance_8.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distance_8);
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_pulse_delta;
      u_right_motor_pulse_delta.real = this->right_motor_pulse_delta;
      *(outbuffer + offset + 0) = (u_right_motor_pulse_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_motor_pulse_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_motor_pulse_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_motor_pulse_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_motor_pulse_delta);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_pulse_delta;
      u_left_motor_pulse_delta.real = this->left_motor_pulse_delta;
      *(outbuffer + offset + 0) = (u_left_motor_pulse_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_motor_pulse_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_motor_pulse_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_motor_pulse_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_motor_pulse_delta);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.real = this->heading;
      *(outbuffer + offset + 0) = (u_heading.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_1;
      u_ch_ultrasonic_distance_1.base = 0;
      u_ch_ultrasonic_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_1 = u_ch_ultrasonic_distance_1.real;
      offset += sizeof(this->ch_ultrasonic_distance_1);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_2;
      u_ch_ultrasonic_distance_2.base = 0;
      u_ch_ultrasonic_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_2 = u_ch_ultrasonic_distance_2.real;
      offset += sizeof(this->ch_ultrasonic_distance_2);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_3;
      u_ch_ultrasonic_distance_3.base = 0;
      u_ch_ultrasonic_distance_3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_3 = u_ch_ultrasonic_distance_3.real;
      offset += sizeof(this->ch_ultrasonic_distance_3);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_4;
      u_ch_ultrasonic_distance_4.base = 0;
      u_ch_ultrasonic_distance_4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_4 = u_ch_ultrasonic_distance_4.real;
      offset += sizeof(this->ch_ultrasonic_distance_4);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_5;
      u_ch_ultrasonic_distance_5.base = 0;
      u_ch_ultrasonic_distance_5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_5 = u_ch_ultrasonic_distance_5.real;
      offset += sizeof(this->ch_ultrasonic_distance_5);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_6;
      u_ch_ultrasonic_distance_6.base = 0;
      u_ch_ultrasonic_distance_6.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_6.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_6.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_6.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_6 = u_ch_ultrasonic_distance_6.real;
      offset += sizeof(this->ch_ultrasonic_distance_6);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_7;
      u_ch_ultrasonic_distance_7.base = 0;
      u_ch_ultrasonic_distance_7.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_7.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_7.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_7.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_7 = u_ch_ultrasonic_distance_7.real;
      offset += sizeof(this->ch_ultrasonic_distance_7);
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distance_8;
      u_ch_ultrasonic_distance_8.base = 0;
      u_ch_ultrasonic_distance_8.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ch_ultrasonic_distance_8.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ch_ultrasonic_distance_8.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ch_ultrasonic_distance_8.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ch_ultrasonic_distance_8 = u_ch_ultrasonic_distance_8.real;
      offset += sizeof(this->ch_ultrasonic_distance_8);
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_pulse_delta;
      u_right_motor_pulse_delta.base = 0;
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_motor_pulse_delta = u_right_motor_pulse_delta.real;
      offset += sizeof(this->right_motor_pulse_delta);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_pulse_delta;
      u_left_motor_pulse_delta.base = 0;
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_motor_pulse_delta = u_left_motor_pulse_delta.real;
      offset += sizeof(this->left_motor_pulse_delta);
      union {
        float real;
        uint32_t base;
      } u_heading;
      u_heading.base = 0;
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading = u_heading.real;
      offset += sizeof(this->heading);
     return offset;
    }

    virtual const char * getType() override { return "ros_msd700_msgs/HardwareState"; };
    virtual const char * getMD5() override { return "59163398a5ab981a5777e0f0b059f048"; };

  };

}
#endif
