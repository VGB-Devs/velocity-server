#include <iostream>
#include <sys/socket.h>

#include "./include/server/Server.hpp"

void onRequest(Request req, Response res) {
    res.contentType("text/html");

    if (req.route() == "/") {
        res.status(200);
        res.sendFile("./views/index.html");
    } else if (req.route() == "/static/style.css") { 
        res.contentType("text/css");
        res.status(200);
        res.sendFile("./static/style.css");
    } else {
        res.status(404);
        
        res.data("<h3>404</h3>'" + req.route() + "' cannot be found on the server!");
    }

    res.build();
}

int main(int argc, char const *argv[]) {
    Server server;
    server.setPort(80);
    server.start(onRequest, argc, argv);
    return 0;
}