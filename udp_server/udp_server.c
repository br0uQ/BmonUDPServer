#include "udp_server.h"

void create_socket() {
    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        perror("socket() failed");
        exit(1);
    }
}

void configure_socket() {
    /* Set socket to allow broadcast */
    broadcastPermission = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission,
                   sizeof(broadcastPermission)) < 0)
    {
        perror("setsockopt() failed");
        exit(1);
    }

    /* Construct local address structure */
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));   /* Zero out structure */
    broadcastAddr.sin_family = AF_INET;                 /* Internet address family */
    broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);/* Broadcast IP address */
    broadcastAddr.sin_port = htons(broadcastPort);         /* Broadcast port */
}

void init_udp_server(char* ip, unsigned short port) {
    broadcastIP = ip;            /* First arg:  broadcast IP address */
    broadcastPort = port;    /* Second arg:  broadcast port */

    create_socket();
    configure_socket();
}

void broadcast(const char *mess)
{
    sendStringLen = strlen(mess);  /* Find length of mess */

    if (sendto(sock, mess, sendStringLen, 0, (struct sockaddr *)
               &broadcastAddr, sizeof(broadcastAddr)) != sendStringLen)
    {
        perror("sendto() sent a different number of bytes than expected");
        exit(1);
    }
}
