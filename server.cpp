#include <iostream>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
 
void receiveLoop(int sockFd) {
    char buffer[1024];
    while (true) {
        int n = recv(sockFd, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0) { cout << "\nPeer disconnected." << endl; exit(0); }
        buffer[n] = '\0';
        cout << "\rPeer: " << buffer << "\nYou: " << flush;
    }
}
 
int main(int argc, char* argv[]) {
    if (argc < 2) { cout << "Usage: ./p2p_chat server|client" << endl; return 1; }
    int sockFd, connFd;
 
    if (string(argv[1]) == "server") {
        sockFd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(9200);
        bind(sockFd, (sockaddr*)&addr, sizeof(addr));
        listen(sockFd, 1);
        cout << "Waiting for peer to connect..." << endl;
        connFd = accept(sockFd, nullptr, nullptr);
    } else {
        connFd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(9200);
        inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
        connect(connFd, (sockaddr*)&serverAddr, sizeof(serverAddr));
    }
 
    cout << "Connected! Start chatting (type 'exit' to quit)." << endl;
    thread receiver(receiveLoop, connFd);
    receiver.detach();
 
    string msg;
    while (true) {
        cout << "You: ";
        getline(cin, msg);
        if (msg == "exit") break;
        send(connFd, msg.c_str(), msg.size(), 0);
    }
 
    close(connFd);
    return 0;
}