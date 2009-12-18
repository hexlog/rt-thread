#ifndef __RT_HW_SERIAL_H__
#define __RT_HW_SERIAL_H__

#include <rthw.h>
#include <rtthread.h>

#include "s3c24x0.h"

#define RTC_DEBUG

#define RTC_ENABLE	0x01
#define RTC_DISABLE	0x02

static const unsigned char days_in_month[] = 
{
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

#define LEAPS_THRU_END_OF(y) ((y)/4 - (y)/100 + (y)/400)
#define LEAP_YEAR(year) ((!(year % 4) && (year % 100)) || !(year % 400))

struct rtc_time 
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

void rt_hw_rtc_get (struct rtc_time *tmp);
void rt_hw_rtc_set (struct rtc_time *tmp);
void rt_hw_rtc_reset (void);
void rt_rtc_time_to_tm(rt_uint32_t time, struct rtc_time *tm);

#endif