#include <iostream>
#include <sys/socket.h>

#include "./include/server/Server.hpp"

void onRequest(Request req, Response res) {
    res.contentType("text/html");

        if (req.method() != "GET") {
            res.status(405);
            res.data("'" + req.method() + "' Method is not allowed!");
        } else {
            res.status(200);
            res.sendFile("./views/index.html");
        }

    res.build();
}

int main(int argc, char const *argv[]) {
    Server server;
    server.setPort(80);
    server.start(onRequest, argc, argv);
    return 0;
}