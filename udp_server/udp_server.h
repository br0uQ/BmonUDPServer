#ifndef UPD_SERVER_H_INCLUDED
#define UPD_SERVER_H_INCLUDED

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

int sock;                         /* Socket */
struct sockaddr_in broadcastAddr; /* Broadcast address */
char *broadcastIP;                /* IP broadcast address */
unsigned short broadcastPort;     /* Server port */
int broadcastPermission;          /* Socket opt to set permission to broadcast */
unsigned int sendStringLen;       /* Length of string to broadcast */

void init_udp_server(char* ip, unsigned short port);
void broadcast(const char *mess);

#endif // UPD_SERVER_H_INCLUDED
