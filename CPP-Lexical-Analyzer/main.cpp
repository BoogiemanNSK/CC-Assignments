#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#define EXE_NAME "main"

class Token {
public:
    void printToken() {
        printf("TOKEN: %s, POSITION: [%d, %d], DATA: \"%s\"\n", m_type.c_str(), m_line, m_pos, m_data.c_str());
    }

    Token(const std::string& type, int line, int pos, const std::string& data) {
        m_type = type;
        m_line = line;
        m_pos = pos;
        m_data = data;
    }

private:
    std::string m_type;
    int m_line;
    int m_pos;
    std::string m_data;
};

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
