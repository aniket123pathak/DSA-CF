#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Performs XOR operation on two binary strings
string xor_op(string a, string b) {
    string result = "";
    // Skip the first bit (always 0 after XORing a 1 with a 1)
    for (size_t i = 1; i < b.length(); i++) {
        if (a[i] == b[i]) {
            result += "0";
        } else {
            result += "1";
        }
    }
    return result;
}

// Performs Modulo-2 division and returns the remainder
string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    int n = dividend.length();

    while (pick < n) {
        if (tmp[0] == '1') {
            tmp = xor_op(divisor, tmp) + dividend[pick];
        } else {
            tmp = xor_op(string(pick, '0'), tmp) + dividend[pick];
        }
        pick += 1;
    }

    // Perform XOR on the last remaining bits
    if (tmp[0] == '1') {
        tmp = xor_op(divisor, tmp);
    } else {
        tmp = xor_op(string(pick, '0'), tmp);
    }

    return tmp;
}

// Sender function: generates the codeword
string sender(string data, string generator) {
    cout << "\n--- SENDER SIDE ---" << endl;
    
    // Append (N-1) zeros to the data
    string appended_data = data + string(generator.length() - 1, '0');
    cout << "Appended Data: " << appended_data << endl;
    
    // Calculate CRC
    string crc = mod2div(appended_data, generator);
    cout << "Calculated CRC: " << crc << endl;
    
    // Final codeword
    string codeword = data + crc;
    cout << "Codeword generated: " << codeword << endl;
    
    return codeword;
}

// Simulates transmission by flipping a random bit
void introduce_error(string &codeword) {
    cout << "\n--- TRANSMISSION CHANNEL ---" << endl;
    cout << "Original Codeword: " << codeword << endl;
    
    // Randomly pick a bit index to flip
    int error_index = rand() % codeword.length();
    codeword[error_index] = (codeword[error_index] == '0') ? '1' : '0';
    
    cout << "Error introduced at index " << error_index << endl;
    cout << "Received Codeword: " << codeword << endl;
}

// Receiver function: checks for errors
void receiver(string received_data, string generator) {
    cout << "\n--- RECEIVER SIDE ---" << endl;
    
    // Calculate remainder of received data
    string remainder = mod2div(received_data, generator);
    cout << "Calculated Remainder: " << remainder << endl;
    
    // Check if remainder contains any '1'
    bool has_error = false;
    for (char bit : remainder) {
        if (bit == '1') {
            has_error = true;
            break;
        }
    }
    
    if (has_error) {
        cout << "Result: ERROR DETECTED! (Remainder is not zero)" << endl;
    } else {
        cout << "Result: NO ERROR. Data is perfectly intact." << endl;
    }
}

int main() {
    // Seed the random number generator
    srand(time(0)); 

    string data_word, generator_poly;

    cout << "Enter Data Word (e.g., 100100): ";
    cin >> data_word;
    
    cout << "Enter Generator Polynomial (e.g., 1101): ";
    cin >> generator_poly;

    // 1. Sender Side
    string codeword = sender(data_word, generator_poly);

    // 2. Introduce Error
    string received_frame = codeword;
    introduce_error(received_frame);

    // 3. Receiver Side (Testing the corrupted frame)
    receiver(received_frame, generator_poly);

    // 4. Test with exact original codeword to prove it works without errors
    cout << "\n\n--- TESTING RECEIVER WITHOUT ERRORS ---";
    receiver(codeword, generator_poly);

    return 0;
}


/*

Hcyclic Redundancy check (CRC): CRC is
an eccoa-detection techNique Used to detect
changes oz ezcozs in data dueing sto&age
o& teansmission
CRC uses binazy division &modulo azithmetic.
A special numbet called CRC Eemainder
is calculated fEom data &appen ded to
C Scanned with OKEN Scanner
RSCOE
Page No.: 14
osiginal data befoce tEansmission. At
the Ecceivee, ceceived data is divided
by same pEedeteemined divisoe to check
whethee an esEo& has occueed.
CRC iS moze poweeful than simple VRC,
LRC, pa&ity check X checksum methods..
Woeking of CRC :
1 Sende& has oziginal data to be teansmitted
2) A p&e deteemined binazy numbee called
the diviso& is selected.
3) Zeeos ate appended to data accading
to size of divisoe.
4) Resulting data is divided by divisoe using
binazy division. 5) Remaindce obtained is called CRC.
6) CRC is appended to oziginal data
7) Complete data is teansmitted to cecrivet.
8) Receivee divides Ecceived data by
same divisoa.
g) If Eemainder is zezo, data is accepted
as ese0c-fEee.
10) If eemainde& is non-zes0, an cE20s is detected X data is Eejected.
C Scanned with OKEN Scanner
RSCOE
Ⓡ Page No.: S
Requizements of CRC:
A CRC should satisty following Conditions:
- CRC must have one bit less than diviso&.
- Appending CRC to data should make
complete bit sequence exactly divisible
by pzedeteemined diviso&.
CRC Genézatoe:
The following steps ake pestozmed at sendee:
is Append n zesos to otiginal data, whede
divisoe contains ntt bits.
ii) Divide newly foemed data by predetcsmined
divisoe using binazy division
ii) Remainder obtained is the CRc.
iv) Replace appended zeeos with CRC semaindes.
✓) Resulting data + CRC is t&ansmitted
to the receives.
*/