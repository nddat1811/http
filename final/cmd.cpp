#include <iostream>
#include <fstream>
#include "HTTPRequest.hpp"

int main(int argc, const char* argv[])
{
    try
    {
        if( argc == 2 )
        {
            std::cout << "Not enough parameters" << argv[1] << '\n';
        }
        else if( argc > 2 )
        {
            std::cout << "http:" << argv[1] << '\n';
            std::cout << "output file:" << argv[2] << '\n';
        }
        else
        {
            std::cout << "Ban nen cung cap mot tham so" << '\n';
        }
        std::string output;
        output = argv[2];
        http::Request request{argv[1]};


        // send a get request
        const auto response = request.send("GET");
        // std::cout << std::string{response.headers.begin(), response.headers.end()} << '\n';
        //std::cout << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
        for(int i = 0; i < response.headers.size(); i++)
        {
           std::cout << response.headers[i].first << ", " << response.headers[i].second << '\n';
        }
        
        std::cout << "j:" << response.status.reason << '\n';

        if (response.status.code == http::Status::Ok)
        {
            if (!output.empty())
            {
                std::ofstream outfile{output, std::ofstream::binary};
                outfile.write(reinterpret_cast<const char*>(response.body.data()),
                              static_cast<std::streamsize>(response.body.size()));
            }
            else
                std::cout << std::string{response.body.begin(), response.body.end()} << '\n';
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}