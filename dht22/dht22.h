#ifndef DHT22_H_INCLUDED
#define DHT22_H_INCLUDED

static float get_humidity();
static float get_temp();
static uint8_t sizecvt(const int read);
static int read_dht22_dat();
void init_sensor();
void close_sensor();

#endif // DHT22_H_INCLUDED
