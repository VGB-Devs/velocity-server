#include <iostream>

class Request {
    public:
        Request(std::string request);
        std::string method();
        std::string route();
        std::string version();
        std::string headers();
        int contentLength();
    private:
        std::string _method;
        std::string _route;
        std::string _version;
        int _contentLength;
        std::string _headers;
};
