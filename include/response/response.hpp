#include <iostream>
//std::string response(std::string text, int code);

class Response {
    public:
        Response(int socketID);
        std::string data(std::string data);
        std::string status(int status);
        std::string build();
        std::string contentType(std::string type);
        std::string sendFile(std::string file);
    private:
        std::string _data;
        std::string _status;
        std::string response;
        std::string bytes;
        std::string _contentType;
        std::string fileData;
        int socketID;
};