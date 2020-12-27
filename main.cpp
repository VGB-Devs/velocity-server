#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "./include/request/request.hpp"
#include "./include/response/response.hpp"

#define PORT 80
int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { perror("In socket"); exit(EXIT_FAILURE); }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { perror("In bind"); exit(EXIT_FAILURE); }
    if (listen(server_fd, 10) < 0) { perror("In listen"); exit(EXIT_FAILURE); }
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { perror("In accept"); exit(EXIT_FAILURE); }
    
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        std::string requestString = buffer;
        Request request(requestString);
        Response res;
        
        res.contentType("text/html");

        if (request.method() != "GET") {
            res.status(405);
            res.data("'" + request.method() + "' Method is not allowed!");
        } else {
            res.status(200);
            //res.data("<h1>Welcome</h1> to " + request.route());
            res.sendFile("index.html");
        }

        std::string d = res.build();
        write(new_socket , d.c_str(), strlen(d.c_str()));
        close(new_socket);
    }
    return 0;
}