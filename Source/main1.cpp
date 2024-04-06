#include <iostream>
#include <vector>
#include <sstream>
#include "RequestHandler.h"

bool is_included(std::string expr, std::string looking_for) {
    return expr.find(looking_for) < expr.size();
}

int main(int argc, const char* argv[])
{
    RequestHandler handler;
    const char* url("www.stridemodmenu.com");
    handler.wrap_url(url);

    // Path of request :
    std::ostringstream base_path;
    base_path << "/api/auth.php?username=USERNAME&password=PASSWORD&hwid=HWID";

    // Headers :
    std::ostringstream fundamental_headers;
    fundamental_headers << "Content-Type: application/json\r\n";
    /**
    IF YOU WANT TO ADD HEADERS TO YOUR REQUESTS :

    */


    handler.get(base_path.str(), fundamental_headers.str());

    // Displays the response :
    std::string response(handler.pull_response(true));

    // Auth verification :
    if (is_included(response, "{\"success\":true}")) {
        // SUCCESS, continue...
        std::cout << "OK" << std::endl;
    } else {
        // ERROR, invalid creditentials...
    }

    // Drop the memory that we don't use anymore (To do once your requests are done):
    handler.drop_memory();

    return 0;
}
