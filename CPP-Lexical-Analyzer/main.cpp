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
        // Reading new token
        ch = in.get();
        
        // End Of File check
        if (ch == EOF) continue;

        // Comments check
        else if (ch == '/') {
            ch = in.get();

            if (ch == '/') { // One-line comment
                while (ch != '\n') ch = in.get();
            }

            else if (ch == '*') { // Multi-line comment
                bool is_comment = true;
                while (is_comment) {
                    ch = in.get();
                    if (ch == '*') {
                        ch = in.get();
                        if (ch == '/') is_comment = false;
                    }
                }
            }
            
            else { // Mistake in code?
                // Somehow handle mistake 
            }
        }

    }

    in.close();
    return 0;
}
