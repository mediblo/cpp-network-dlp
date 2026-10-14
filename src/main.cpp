#include <iostream>
#include <winsock2.h>
#include <stdexcept>

class HelloWorld {
public:
	HelloWorld() {
		std::cout << "Hello, World!" << std::endl;
	}

	~HelloWorld() {
		std::cout << "Goodbye, World!" << std::endl;
	}
};

class WinsockRuntime {
private:
	bool flag = false;
public:
	WinsockRuntime() {
		WSADATA wsaData;
		WORD ver = MAKEWORD(2,2);
		int a = WSAStartup(ver, &wsaData);

		if (a == 0) {
			flag = true;
			int lo = LOBYTE(wsaData.wVersion);
			int hi = HIBYTE(wsaData.wVersion);
			
			if (lo != 2 || hi != 2) {
				int aa = WSACleanup();
				std::cout << aa << "Winsock version mismatch result" << std::endl;
				throw std::runtime_error("Winsock version mismatch");
			}

		}
		else {
			throw std::runtime_error("Winsock init fail");
		}
		std::cout << a << std::endl;
	}

	WinsockRuntime(const WinsockRuntime&) = delete;
	WinsockRuntime& operator=(const WinsockRuntime&) = delete;

	~WinsockRuntime() {
		if (flag) {
			int a = WSACleanup();
			std::cout << a << std::endl;
		}
	}
};

class Socket {
private:
	SOCKET sock = INVALID_SOCKET;

public:

	Socket(const Socket&) = delete;
	Socket& operator=(const Socket&) = delete;

	Socket() = default;

	~Socket() {
		if (sock != INVALID_SOCKET) {
			closesocket(sock);
		}
	}
};

int main() {
	HelloWorld hello;

	try{	
		WinsockRuntime winsock;
		Socket socket;
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}