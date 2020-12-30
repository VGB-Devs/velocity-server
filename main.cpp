#include <iostream>

#include "./include/server/Server.hpp"

void getA(Request req, Response res) {
    res.contentType("text/html");
        res.status(200);
        res.sendFile("./views/index.html");
        std::cout << "test" << std::endl;
        res.build();
}

int main(int argc, char const *argv[]) {
    Server server;
    server.setPort(80);
    server.start(getA, argc, argv);
    server.get("/", getA);
    return 0;
}