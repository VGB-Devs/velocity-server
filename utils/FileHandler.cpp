#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/utils/FileHandler.hpp"

StaticHandler::StaticHandler(std::string route, std::vector<std::string>methods, std::string file, std::string contentType) {
    this->route = route;
    this->methods = methods;
    this->file = file;
    this->contentType = contentType;
}

std::string StaticHandler::read() {
    std::string line;
    std::fstream target;
    target.open(this->file, std::ios::in);
    std::string tmp = "";
    
    if(!target) tmp = "cannot find file";
    
    while(std::getline(target, line)) {
        tmp += line + "\n";
    }
    target.close();

    return tmp;
}