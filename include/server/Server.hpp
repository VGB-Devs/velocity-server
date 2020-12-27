#include <iostream>
#include <map>
#include <vector>

#include "../request/Request.hpp"
#include "../response/Response.hpp"

class Server {
    private:
        int port;
        bool _useStatic;
        std::map<std::string, std::string> staticServer;
    public:
        Server();
        bool useStatic(bool value);
        int setPort(int givenPort);
        void start(std::function<void (Request, Response)> cb, int argc, const char *argv[]);
        //std::string listenStatic(std::string route, std::string file);
        //void listen()
};