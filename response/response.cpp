#include <iostream>
#include <fstream>
#include <string>

#include <sys/socket.h>
#include <unistd.h>

#include "../include/response/Response.hpp"

Response::Response(int socketID) {
    this->response = "";
    this->bytes = "";
    this->_data = "";
    this->_status = "200";
    this->_contentType = "text/plain";
    this->fileData = "";
    this->socketID = socketID;
}

std::string Response::data(std::string data) {
    this->bytes = std::to_string(data.length());
    this->_data = data;
    return this->_data;
}

std::string Response::status(int code) {
    this->_status = std::to_string(code);
    return this->_status;
}

std::string Response::contentType(std::string type) {
    this->_contentType = type;
    return this->_contentType;
}

std::string Response::sendFile(std::string file) {
    std::string line;
    std::fstream target;
    target.open(file, std::ios::in);
    std::string tmp = "";
    
    if(!target) tmp = "cannot find file";
    
    while(std::getline(target, line)) {
        tmp += line + "\n";
    }
    target.close();


    this->bytes = std::to_string(tmp.length());
    this->_data = tmp;
    return this->_data;
}

std::string Response::build() {
    // TODO log to console;
    
    this->response = "HTTP/1.1 " + this->_status + " OK\nContent-Type: " + this->_contentType + "\nContent-Length:" + this->bytes + "\n\n" + this->_data; 
    write(this->socketID, this->response.c_str(), this->response.length());
    close(this->socketID);
    
    return this->response;
}