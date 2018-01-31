#include "logger.h"
#include "../my_time/my_time.h"
#include <stdlib.h>

void init_logging(char* name) {
    char filename[DATE_AND_TIME_LENGTH + MAX_LOGFILE_NAME_LENGTH];

    // create filename
    fetch_system_time();
    snprintf(filename, sizeof(filename),
             "%s-%s.log", get_date_and_time(), name);

    // open logfile
    logfile = fopen(filename, "w");
    if (logfile == NULL) {
        perror("Could not open logfile!");
        exit(1);
    }
}

void write_log(char* text) {
    fprintf(logfile, "%s: %s\n", get_formatted_time(), text);
}

void close_logging() {
    fclose(logfile);
}
