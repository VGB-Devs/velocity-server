#include <iostream>
#include <map>
#include <vector>

#include "../request/Request.hpp"
#include "../response/Response.hpp"

#include "../events/IncomingEvent.hpp"

#pragma once

class Server {
    private:
        int port;
        bool _useStatic;
        std::map<std::string, std::string> staticServer;
        std::map<std::string, IncomingEvent> IncGetEvent;
    public:
        Server();
        bool useStatic(bool value);
        int setPort(int givenPort);
        void start(std::function<void (Request, Response)> cb, int argc, const char *argv[]);
        void emitIncoming(std::string method, Request req, Response Res);
        void get(std::string method, std::function<void (Request req, Response res)>);
        //std::string listenStatic(std::string route, std::string file);
        //void listen()
};