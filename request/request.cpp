#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iterator>

#include "../include/request/Request.hpp"
#include "../include/utils/Colours.hpp"

Request::Request(std::string request) {
    std::map<std::string, std::string> headers;

    std::vector<std::string> lines;

    std::istringstream buffer(request);
    std::string line;
    while (getline(buffer, line)) {
        lines.push_back(line);
    }
        
    // tokenize & shit it into a vector of shit lol
    std::vector<std::string> requestline;
    std::string reqL = std::string(lines[0]);
    std::string tmp = "";
    for (int i = 0; i <= reqL.length(); i++) {
        if (reqL[i] == ' ') {
            requestline.push_back(tmp);
            tmp = "";
        } else {
            tmp += reqL[i];
        }
    }
    
    headers["method"] = requestline[0];
    headers["route"] = requestline[1];
 
    this->_method = headers["method"];
    this->_route = headers["route"];
    std::cout << boldGreen() << headers["method"] << reset() << " " << headers["route"] << std::endl;
}

std::string Request::method() { return this->_method;}
std::string Request::route() { return this->_route; }
std::string Request::version() { return this->_version; }
std::string Request::headers() { return this->_headers; }
int Request::contentLength() { return this->_contentLength; }