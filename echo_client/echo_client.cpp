/*
 * Boosting your C++ Development with Boost
 *
 * Based on boost::asio example program from
 * http://www.boost.org/doc/libs/1_36_0/doc/html/boost_asio/example/echo/blocking_tcp_echo_client.cpp
 *
 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			std::cerr << "Usage: echo_client <host> <port>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		tcp::resolver resolver(io_service);
		tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
		tcp::resolver::iterator iterator = resolver.resolve(query);

		tcp::socket s(io_service);
		s.connect(*iterator);

		using namespace std; // For strlen.
		std::cout << "Enter message: ";
		char request[max_length];
		std::cin.getline(request, max_length);
		size_t request_length = strlen(request);
		
		boost::asio::write(s, boost::asio::buffer(request, request_length));

		char reply[max_length];
		size_t reply_length = boost::asio::read(s, boost::asio::buffer(reply, request_length));
    
		std::cout << "Reply is: ";
		std::cout.write(reply, reply_length);
		std::cout << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
