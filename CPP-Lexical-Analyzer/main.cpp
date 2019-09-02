#include <iostream>
#include <fstream>

#define EXE_NAME "main"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "[ERROR] Usage: " EXE_NAME ".exe [Source file]\n";
        return -1;
    }

    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cout << "[ERROR] Incorrect source file name!\n";
        return -1;
    }

    char ch = '0';    
    while(ch != EOF) {
        ch = in.get();
        if (ch == EOF) continue;

        std::cout << ch;
    }

    in.close();
    return 0;
}
