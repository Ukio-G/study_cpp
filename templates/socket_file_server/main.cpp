#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <unordered_map>
#include <fcntl.h>
#include <libnet.h>
#include <thread>


bool stop = false;
void recv_loop(int sock_fd)
{
    while (!stop) {
        auto csock = accept(sock_fd, NULL, NULL);
        if (csock < 0) {
            std::cout << "[SocketServer]: accept() failed\n";
            continue;
        }

        std::thread([csock] {
            char buf[1024];
            auto bytes = recv(csock, buf, sizeof buf - 1, 0);
            if (bytes <= 0) {
                std::cout << "[SocketServer]: recv() failed\n";
            } else {
                buf[bytes] = '\0';
                std::cout << "[SocketServer]: recv() buffer: " << buf << std::endl;
            }
            close(csock);
        }).detach();
    }
    close(sock_fd);
}

int create_socket_server(std::string sock_path)
{
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cout << "[SocketServer]: socket() failed \n";
        throw 1;
    }

    sockaddr_un saddr = {};
    saddr.sun_family = AF_UNIX;
    strcpy(saddr.sun_path, sock_path.c_str());
    remove(sock_path.c_str());
    auto ret = bind(sockfd, (struct sockaddr*)&saddr, sizeof saddr);

    if (ret < 0) {
     std::cout << "[SocketServer]: bind() failed \n";
        throw 1;
    }
    ret = chmod(sock_path.c_str(), S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (ret < 0) {
        std::cout << "[SocketServer]: chmod() failed \n";
        throw 1;
    }

    ret = listen(sockfd, 1);
    return sockfd;
}

int main() {
    recv_loop(create_socket_server("/tmp/simple_server.sock"));
}