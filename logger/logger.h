#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <stdio.h>

#define MAX_LOGFILE_NAME_LENGTH     40

FILE *logfile;

void init_logging(char* name);
void write_log(char* text);
void close_logging();

#endif // LOGGER_H_INCLUDED
