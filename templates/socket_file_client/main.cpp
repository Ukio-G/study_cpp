#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <unordered_map>


int send_data_to_server(std::string filename, void * data, int length)
{
    int sockfd;
    sockaddr_un servaddr;

    if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        std::cout << "socket creation failed\n";
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(sockaddr_un));
    servaddr.sun_family = AF_UNIX;
    memcpy(servaddr.sun_path, filename.c_str(), filename.size());
    std::cout << servaddr.sun_path << std::endl;

    if (connect(sockfd, (struct sockaddr *) &servaddr, SUN_LEN(&servaddr)) < 0)
    {
        std::cout << "client: connection error\n";
        std::cout << "errno = " << errno << std::endl;
        exit(1);
    }

    write(sockfd, data, length);
    close(sockfd);
    return sockfd;
}

int main(int argc, char **argv) {
    char data[128];
    bzero(data, 128);
    memcpy(data, "data", 4);
    send_data_to_server("/tmp/simple_server.sock", data, 4);
}
