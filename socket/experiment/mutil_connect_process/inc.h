#ifndef __INC__H
#define __INC__H

#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

void process_conn_client(int sc);
void process_conn_server(int s);

#endif
