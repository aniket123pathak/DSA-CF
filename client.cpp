#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
 
vector<int> clients;
mutex clientsMutex;
 
void broadcast(const string &msg, int excludeFd) {
    lock_guard<mutex> lock(clientsMutex);
    for (int fd : clients)
        if (fd != excludeFd) send(fd, msg.c_str(), msg.size(), 0);
}
 
void handleClient(int clientFd) {
    char buffer[1024];
    while (true) {
        int n = recv(clientFd, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0) break;
        buffer[n] = '\0';
        cout << "[Client " << clientFd << "]: " << buffer << endl;
        broadcast(string("[Client ") + to_string(clientFd) + "]: " + buffer, clientFd);
    }
    lock_guard<mutex> lock(clientsMutex);
    clients.erase(remove(clients.begin(), clients.end(), clientFd), clients.end());
    close(clientFd);
    cout << "Client " << clientFd << " disconnected." << endl;
}
 
int main() {
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(9201);
    bind(serverFd, (sockaddr*)&addr, sizeof(addr));
    listen(serverFd, 10);
    cout << "Multiuser chat server listening on port 9201..." << endl;
 
    while (true) {
        int clientFd = accept(serverFd, nullptr, nullptr);
        { lock_guard<mutex> lock(clientsMutex); clients.push_back(clientFd); }
        cout << "Client " << clientFd << " connected." << endl;
        thread(handleClient, clientFd).detach();
    }
    return 0;
}