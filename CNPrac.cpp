#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string xor_func(const string& a, const string& b) {
    string result = "";
    for (size_t i = 1; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string divide(const string& data, const string& divisor) {
    int n = divisor.length();
    string temp = data.substr(0, n);
    
    for (size_t i = n; i < data.length(); i++) {
        if (temp[0] == '1') {
            temp = xor_func(temp, divisor) + data[i];
        } else {
            temp = xor_func(temp, string(n, '0')) + data[i];
        }
    }
    
    if (temp[0] == '1') {
        temp = xor_func(temp, divisor);
    } else {
        temp = xor_func(temp, string(n, '0'));
    }
    
    return temp;
}

string asciiToBinary(const string& text) {
    string binary = "";
    for (char c : text) {
        binary += bitset<8>(c).to_string(); 
    }
    return binary;
}

int main() {
    string text, divisor, receivedText;
    
    cout << "--- TRANSMITTER ---" << endl;
    cout << "Enter ASCII text: ";
    getline(cin, text);
    cout << "Enter generator polynomial in binary: ";
    getline(cin, divisor);
    string data = asciiToBinary(text);
    cout << "ASCII Binary Data: " << data << endl;
    
    string appendedData = data + string(divisor.length() - 1, '0');
    
    string crc = divide(appendedData, divisor);
    cout << "CRC: " << crc << endl;
    
    cout << "\n--- RECEIVER ---" << endl;
    cout << "Enter received ASCII text: ";
    getline(cin, receivedText);
    
    string receivedBinaryData = asciiToBinary(receivedText);
    
    string receivedCodeword = receivedBinaryData + crc;
    
    string remainder = divide(receivedCodeword, divisor);
    cout << "Remainder: " << remainder << endl;
    
    if (remainder.find('1') != string::npos) {
        cout << "Error Detected! (The text was altered)" << endl;
    } else {
        cout << "No Error Detected. (The text matches)" << endl;
    }
    
    return 0;
}