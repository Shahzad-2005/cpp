#include <iostream>
#include <cstring>

void process_data(char* input) {
    char buffer[10];
    // Issue 1: Buffer overflow risk (Security)
    // strcpy does not check for size, which is a major security flaw
    strcpy(buffer, input);
    std::cout << "Processed Buffer: " << buffer << std::endl;
}

int main() {
    // Issue 2: Memory leak (Performance/Resource Management)
    // Memory is allocated but never cleared with 'delete'
    int* data_leak = new int[100];
    
    const char* long_msg = "This string is much longer than the buffer size of 10";
    // We intentionally pass a long string to trigger the potential overflow
    // process_data((char*)long_msg); // Commented out to prevent crash, but remains a static flaw
    
    // Issue 3: Uninitialized variable (Bug/Risk)
    int secret_key;
    if (secret_key > 0) {
        std::cout << "Secret Key: " << secret_key << std::endl;
    }

    return 0;
}
