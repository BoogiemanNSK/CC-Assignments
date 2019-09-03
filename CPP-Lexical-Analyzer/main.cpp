#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cctype>

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

bool isEndOfLiteral(char);
bool isCorrectDecimalSuffix(std::string);

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

    /// SCANNER CODE BEGIN ///

    char ch = '0';    
    std::string str;

    while(ch != EOF) {
        // Reading new token
        ch = in.get();
        str = "";
        
        // End Of File check
        if (ch == EOF) continue;

        // Comments check
        else if (ch == '/') {
            ch = in.get();

            // One-line comment
            if (ch == '/') {
                while (ch != '\n') ch = in.get();
            }

            // Multi-line comment
            else if (ch == '*') {
                bool isComment = true;
                while (isComment) {
                    ch = in.get();
                    if (ch == '*') {
                        ch = in.get();
                        if (ch == '/') isComment = false;
                    }
                }
            }
        }

        // Char literal check
        else if (ch == '\'') {
            bool isChar = true;

            while (isChar) {
                ch = in.get();

                // Next char is special char
                if (ch == '\\') {
                    str += ch;

                    ch = in.get();
                    str += ch;
                }

                // End of char or file
                else if (ch == '\'' || ch == EOF) {
                    isChar = false;
                }

                else {
                    str += ch;
                }
            }

            if (ch != EOF && str.length() > 0) /* LITERAL_CHAR */;
        }

        // String literal check
        else if (ch == '\"') {
            bool isChar = true;

            while (isChar) {
                ch = in.get();

                // Next char is special char
                if (ch == '\\') {
                    str += ch;

                    ch = in.get();
                    str += ch;
                }

                // End of char or file
                else if (ch == '\"' || ch == EOF) {
                    isChar = false;
                }

                else {
                    str += ch;
                }
            }

            if (ch != EOF) /* LITERAL_STRING */;
        }

        // Binary / Octal / Hexadecimal check
        else if (ch == '0') {
            ch = in.get();

            // Hexadecimal (Hex)
            if (ch == 'x' || ch == 'X') {
                str = "0" + ch;
                ch = in.get();
                
                while (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F') {
                    str += ch;
                    ch = in.get();
                }

                std::string suffix = "";
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    str += ch;
                    suffix += tolower(ch);
                    ch = in.get();
                }

                if (isEndOfLiteral(ch) && isCorrectDecimalSuffix(suffix)) {
                    if (suffix == "") /* LITERAL_HEX */;
                    else if (suffix == "u") /* LITERAL_UNSIGNED_HEX */;
                    else if (suffix == "l") /* LITERAL_LONG_HEX */;
                    else if (suffix == "lu" || suffix == "ul") /* LITERAL_UNSIGNED_LONG_HEX */;
                    else if (suffix == "ull" || suffix == "lul" || suffix == "llu") /* LITERAL_INSIGNED_LONG_LONG_HEX */;
                }
            }

            // Binary
            else if (ch == 'b' && ch == 'B') {
                str = "0" + ch;
                ch = in.get();
                
                while (ch == '0' || ch == '1') {
                    str += ch;
                    ch = in.get();
                }

                std::string suffix = "";
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    str += ch;
                    suffix += tolower(ch);
                    ch = in.get();
                }

                if (isEndOfLiteral(ch) && isCorrectDecimalSuffix(suffix)) {
                    if (suffix == "") /* LITERAL_BINARY */;
                    else if (suffix == "u") /* LITERAL_UNSIGNED_BINARY */;
                    else if (suffix == "l") /* LITERAL_LONG_BINARY */;
                    else if (suffix == "lu" || suffix == "ul") /* LITERAL_UNSIGNED_LONG_BINARY */;
                    else if (suffix == "ull" || suffix == "lul" || suffix == "llu") /* LITERAL_UNSIGNED_LONG_LONG_BINARY */;
                }
            }

            // Ineger / Floating-point / Octal
            else if (ch >= '0' && ch <= '9' || ch == '.' || ch == 'e' || ch == 'E') {
                
                // Octal check
                while (ch >= '0' && ch <= '7') {
                    str += ch;
                    ch = in.get();
                }

                // Either octal or mistake
                if (ch == 'l' || ch == 'L' || ch == 'u' || ch == 'U' || isEndOfLiteral(ch)) {
                    std::string suffix = "";
                    while (!isEndOfLiteral(ch) && ch != EOF) {
                        str += ch;
                        suffix += tolower(ch);
                        ch = in.get();
                    }

                    // Octal
                    if (isEndOfLiteral(ch) && isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") /* LITERAL_OCTAL */;
                        else if (suffix == "u") /* LITERAL_UNSIGNED_OCTAL */;
                        else if (suffix == "l") /* LITERAL_LONG_OCTAL */;
                        else if (suffix == "lu" || suffix == "ul") /* LITERAL_UNSIGNED_LONG_OCTAL */;
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") /* LITERAL_UNSIGNED_LONG_LONG_OCTAL */;
                    }

                    // Mistake - ignore it
                    else continue;
                }

                // Integer check
                while (ch >= '0' && ch <= '9') {
                    str += ch;
                    ch = in.get();
                }

                // Either integer or mistake
                if (ch == 'l' || ch == 'L' || ch == 'u' || ch == 'U' || isEndOfLiteral(ch)) {
                    std::string suffix = "";
                    while (!isEndOfLiteral(ch) && ch != EOF) {
                        str += ch;
                        suffix += tolower(ch);
                        ch = in.get();
                    }

                    // Octal
                    if (isEndOfLiteral(ch) && isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") /* LITERAL_INT */;
                        else if (suffix == "u") /* LITERAL_UNSIGNED_INT */;
                        else if (suffix == "l") /* LITERAL_LONG_INT */;
                        else if (suffix == "lu" || suffix == "ul") /* LITERAL_UNSIGNED_LONG_INT */;
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") /* LITERAL_UNSIGNED_LONG_LONG_INT */;
                    }

                    // Mistake - ignore it
                    else continue;
                }

            }

            // Just a zero integer
            else if (isEndOfLiteral(ch)) /* LITERAL_INTEGER */;

        }

        // Integer / Floating-point
        else if (ch >= '1' && ch <= '9') {

        }

    }

    /// SCANNER CODE END ///

    in.close();
    return 0;
}

bool isEndOfLiteral(char c) {
    return c == ' ' || 
        c == ';' || 
        c == ',' ||
        c == '<' ||
        c == '>' ||
        c == ':' ||
        c == '?' ||
        c == '/' ||
        c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '%' ||
        c == '=' ||
        c == '^' ||
        c == '&' ||
        c == '|' ||
        c == '!' ||
        c == ')' ||
        c == ']';
}

bool isCorrectDecimalSuffix(std::string s) {
    return s == "" ||
        s == "l" ||
        s == "ll" ||
        s == "llu" ||
        s == "lul" ||
        s == "u" ||
        s == "ul" ||
        s == "ull";
}
