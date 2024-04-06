#ifndef REQUESTHANDLER_H_INCLUDED
#define REQUESTHANDLER_H_INCLUDED
#include <string>
#include <winsock2.h>

class RequestHandler {
    private:
    SOCKET m_sock;
    SOCKADDR_IN m_sin;
    WSADATA m_WSAData;
    struct hostent *m_host;
    std::string build_request(std::string, std::string, std::string) noexcept;
    std::string build_request(std::string, std::string, std::string, std::string) noexcept;
    unsigned int m_BUFF;
    const char* m_hostname;

    public:
    RequestHandler();
    void get(std::string, std::string) noexcept;
    void post(std::string, std::string, std::string) noexcept;
    std::string pull_response(bool) noexcept;
    void wrap_url(const char*) noexcept;
    void drop_memory() noexcept;
};

#endif // REQUESTHANDLER_H_INCLUDED
