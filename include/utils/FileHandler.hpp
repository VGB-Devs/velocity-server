#include <iostream>
#include <vector>

class StaticHandler {
    private:
        std::vector<std::string> methods;
        std::string file;
        std::string route;
        std::string contentType;
    public:
        StaticHandler(std::string route, std::vector<std::string> methods, std::string file, std::string contentType);
        std::string read();
};