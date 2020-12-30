#include <iostream>

#include "../response/Response.hpp"
#include "../request/Request.hpp"

#pragma once

class IncomingEvent {
    public:
        std::function<void (Request req, Response res)> callback;
};