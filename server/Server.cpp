#include <iostream>
#include <map>
#include <vector>

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


#include "../include/server/Server.hpp"
#include "../include/utils/FileHandler.hpp"
#include "../include/utils/Colours.hpp"

Server::Server() {this->_useStatic = false;}

int Server::setPort(int port) { this->port = port; return this->port; }
bool Server::useStatic(bool value) { this->_useStatic = value; return this->_useStatic; }
void Server::start(std::function<void (Request, Response)> cb, int argc, char const *argv[]) {
    std::cout << boldGreen() + "Server started on port " << this->port << reset() << std::endl;
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { perror("In socket"); exit(EXIT_FAILURE); }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( this->port );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { perror("In bind"); exit(EXIT_FAILURE); }
    if (listen(server_fd, 10) < 0) { perror("In listen"); exit(EXIT_FAILURE); }
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { perror("In accept"); exit(EXIT_FAILURE); }
    
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        std::string requestString = buffer;
        Request request(requestString);
        Response response(new_socket);
        
        cb(request, response);
    }
}