#include <stdio.h>
#include <stdlib.h>

#include "udp_server/udp_server.h"
#include "dht22/dht22.h"

int main()
{
    char message[10];
    printf("Start UDP Test\n");
    printf("==============\n\n");

    init_udp_server("10.0.2.255", 55555);

    init_sensor();
    while (1) {
        read_dht22_dat();
        printf("Humidity = %.1f %% Temperature = %.1f *C \n", get_humidity(), get_temp());
        // ToDo: create string for broadcast
        snprintf(message, sizeof(message), "%.1f,%.1f", get_humidity(), get_temp());
        broadcast(message);

        delay(4000);    // wait 4s
    }

    close_sensor();

    printf("\n============\n");
    printf("UPD Test end\n");
    return 0;
}
