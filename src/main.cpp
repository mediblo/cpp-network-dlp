#include <iostream>
#include <winsock2.h>

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
		WORD ver = MAKEWORD(2, 2);
		int a = WSAStartup(ver, &wsaData);

		if (a == 0) {
			flag = true;
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

int main() {
	HelloWorld hello;
	WinsockRuntime winsock;

	return 0;
}