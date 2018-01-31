#ifndef MY_TIME_H_INCLUDED
#define MY_TIME_H_INCLUDED

#include <time.h>

/************************************************************\
 * struct members for tm:                                   *
 * tm_sec	int	seconds after the minute	0-61*           *
 * tm_min	int	minutes after the hour	0-59                *
 * tm_hour	int	hours since midnight	0-23                *
 * tm_mday	int	day of the month	1-31                    *
 * tm_mon	int	months since January	0-11                *
 * tm_year	int	years since 1900	                        *
 * tm_wday	int	days since Sunday	0-6                     *
 * tm_yday	int	days since January 1	0-365               *
 * tm_isdst	int	Daylight Saving Time flag	                *
\************************************************************/

#define DATE_AND_TIME_LENGTH    15 // 8 for Date + 6 for Time + 1 for '_'

time_t rawtime;
struct tm *timeinfo;
char time_string[7];
char formatted_time_string[9];
char date_and_time[DATE_AND_TIME_LENGTH + 1];

void fetch_system_time(void);
int get_year(void);
int get_month(void);
int get_day(void);
char* get_time(void);
char* get_formatted_time(void);
char* get_date_and_time(void);
char* get_time_string(void);

#endif // MY_TIME_H_INCLUDED
