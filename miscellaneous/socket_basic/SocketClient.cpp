//
// Created by ukio on 16.05.2020.
//

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <unordered_map>

#include "Tracker.h"


int main() {
    Track t;
    t.id = 101;
    Additional additional = {1, 1};
    t.appendNewPoint(1, 1, additional);
    t.appendNewPoint(7, 2, additional);
    t.appendNewPoint(4, 3, additional);

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    sendto(sockfd, &t, 1024,
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,
           sizeof(servaddr));
}
