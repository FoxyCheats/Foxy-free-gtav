#include <iostream>
#include <sstream>
#include <string>
#include <charconv>
#include <vector>
#include <winsock2.h>
#include "RequestHandler.h"
#include <iomanip>

std::vector<std::string> split(const std::string& expression, const char& delimiter = '\n') {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(expression);
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

RequestHandler::RequestHandler() {

    WSAStartup(MAKEWORD(2, 0), &m_WSAData);

    m_sin.sin_family = AF_INET;
    m_sin.sin_port = htons(80);

    m_sock = (socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));

    m_BUFF = 8096;

}

std::string RequestHandler::build_request(std::string method, std::string path, std::string headers_) noexcept
{
    std::ostringstream headers;
    headers << method.c_str() << " " << path.c_str() << " HTTP/1.1\r\nHost: " << m_hostname << "\r\nConnection: close\r\n" << headers_.c_str() << "\r\n";
    return headers.str();
}

std::string RequestHandler::build_request(std::string method, std::string path, std::string body, std::string headers_) noexcept
{
    std::ostringstream headers;
    headers << method.c_str() << " " << path.c_str() << " HTTP/1.1\r\nHost: " << m_hostname << "\r\nConnection: close\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: " << body.size() << "\r\n" << headers_.c_str() << "\r\n" << body;
    return headers.str();
}

void RequestHandler::get(std::string path, std::string headers = "") noexcept {
    std::string request(build_request("GET", path, headers));
    send(m_sock, request.c_str(), request.size(), 0);
}

void RequestHandler::post(std::string path, std::string body, std::string headers = "") noexcept {
    std::string request(build_request("POST", path, body, headers));
    send(m_sock, request.c_str(), request.size(), 0);
}

std::string RequestHandler::pull_response(bool body_only = true) noexcept {
    int nDataLength;
    char response[m_BUFF];
    std::string website_HTML;

    while ((nDataLength = recv(m_sock,response,sizeof(response),0)) > 0){
        unsigned int i = 0;
        while (response[i] >= 32 || response[i] == '\n' || response[i] == '\r'){
            website_HTML+=response[i];
            i += 1;
        }
    }

    if (body_only) {
        bool start(false);
        std::vector<std::string> splitted_response(split(response, '\n'));
        std::string body("");

        for (unsigned int index(0); index < splitted_response.size(); index++) {
            std::string line_(splitted_response[index]);
            const char* line(static_cast<const char*>(line_.c_str()));
            if (*line == '\r') {
                start = true;
            } else if (start) {
                body += line_;
            }
        }
        return body;
    } else {
        return response;
    }
}


void RequestHandler::wrap_url(const char* host) noexcept {
    shutdown(m_sock, 2);
    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    m_hostname = host;
    m_host = gethostbyname(host);
    m_sin.sin_addr.s_addr = *((unsigned long*)m_host->h_addr);
    connect(m_sock, (SOCKADDR *) &m_sin, sizeof(m_sin));
}

void RequestHandler::drop_memory() noexcept {
    closesocket(m_sock);
    WSACleanup();
}
