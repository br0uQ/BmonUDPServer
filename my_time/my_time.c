#include <stdio.h>
#include "my_time.h"

void fetch_system_time(void) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);
}

int get_year() {
    return 1900+timeinfo->tm_year;
}

int get_month() {
    return timeinfo->tm_mon + 1;
}

int get_day() {
    return timeinfo->tm_mday;
}

char* get_time() {
    snprintf(time_string, sizeof(time_string),
             "%02d%02d%02d",
             timeinfo->tm_hour,
             timeinfo->tm_min,
             timeinfo->tm_sec);
    return time_string;
}

char* get_formatted_time() {
    snprintf(formatted_time_string, sizeof(formatted_time_string),
             "%02d:%02d:%02d",
             timeinfo->tm_hour,
             timeinfo->tm_min,
             timeinfo->tm_sec);
    return formatted_time_string;
}

char* get_date_and_time() {
    snprintf(date_and_time, sizeof(date_and_time),
             "%04d%02d%02d_%s",
             get_year(),
             get_month(),
             get_day(),
             get_time());
    return date_and_time;
}

char* get_time_string() {
    return asctime(timeinfo);
}
