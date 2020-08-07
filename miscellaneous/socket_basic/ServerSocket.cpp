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

std::unordered_map<uint64_t, Track> Tracks;



int main() {

    int sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    char resBuff[1024];

    sockaddr_in serv_addr, client_addr;
    if (sockfd < 0)
        std::cout << "Error opening socket" << std::endl;

    memset(&serv_addr, 0, sizeof(sockaddr_in));
    memset(&client_addr, 0, sizeof(sockaddr_in));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    socklen_t len;

    int n = recvfrom(sockfd, (char *)resBuff, 1024,
                 MSG_WAITALL, ( struct sockaddr *) &serv_addr,
                 &len);

    auto * t = (Track*)resBuff;

    std::cout << t->id << std::endl;
    std::cout << t->points.size() << std::endl;
//    std::cout << t->points[0].x<< std::endl; // Тут segfault
    return 0;
}
