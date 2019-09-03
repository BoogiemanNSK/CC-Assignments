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

bool isEndOfLiteral(char);

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
                bool is_comment = true;
                while (is_comment) {
                    ch = in.get();
                    if (ch == '*') {
                        ch = in.get();
                        if (ch == '/') is_comment = false;
                    }
                }
            }
        }

        // Char check
        else if (ch == '\'') {
            ch = in.get();
            str = "" + ch;
            
            ch = in.get();
            if (ch == '\'') {
                // LITERAL_CHAR
            }
        }

        // String check
        else if (ch == '\"') {
            ch = in.get();

            while (ch != '\"') {
                str += ch;
                ch = in.get();

                // To prevent infinite loop
                if (ch == EOF) {
                    break;
                }
            }

            if (ch != EOF) {
                // LITERAL_STRING
            }
        }

        // Binary / Octal / Hexadecimal check
        else if (ch == '0') {
            ch = in.get();

            // Hexadecimal
            if (ch == 'x' || ch == 'X') {
                str = "0" + ch;
                ch = in.get();
                
                while (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F') {
                    str += ch;
                    ch = in.get();
                }

                if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'u' || ch == 'U') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_HEXADECIMAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_lONG_LONG_HEXADECIMAL
                        }
                    }

                    else if (ch == 'u' || ch == 'U') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_HEXADECIMAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_UNSIGNED_LONG_HEXADECIMAL
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_LONG_HEXADECIMAL
                    }

                }

                if (ch == 'u' || ch == 'U') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_HEXADECIMAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_USIGNED_LONG_HEXADECIMAL
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_UNSIGNED_HEXADECIMAL
                    }

                }

                if (isEndOfLiteral(ch)) {
                    // LITERAL_HEXADECIMAL
                }
            }

            // Octal
            else if (ch >= '0' && ch <= '7') {
                str = "0" + ch;
                ch = in.get();
                
                while (ch >= '0' && ch <= '7') {
                    str += ch;
                    ch = in.get();
                }

                if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'u' || ch == 'U') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_OCTAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_lONG_LONG_OCTAL
                        }
                    }

                    else if (ch == 'u' || ch == 'U') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_OCTAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_UNSIGNED_LONG_OCTAL
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_LONG_OCTAL
                    }

                }

                if (ch == 'u' || ch == 'U') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_OCTAL
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_USIGNED_LONG_OCTAL
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_UNSIGNED_OCTAL
                    }

                }

                if (isEndOfLiteral(ch)) {
                    // LITERAL_OCTAL
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

                if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'u' || ch == 'U') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_BINARY
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_lONG_LONG_BINARY
                        }
                    }

                    else if (ch == 'u' || ch == 'U') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_BINARY
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_UNSIGNED_LONG_BINARY
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_LONG_BINARY
                    }

                }

                if (ch == 'u' || ch == 'U') {
                    str += ch;
                    ch = in.get();

                    if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();

                        if (ch == 'l' || ch == 'L') {
                            str += ch;
                            ch = in.get();

                            if (isEndOfLiteral(ch)) {
                                // LITERAL_UNSIGNED_LONG_LONG_BINARY
                            }
                        }

                        else if (isEndOfLiteral(ch)) {
                            // LITERAL_USIGNED_LONG_BINARY
                        }
                    }

                    else if (isEndOfLiteral(ch)) {
                        // LITERAL_UNSIGNED_BINARY
                    }

                }

                if (isEndOfLiteral(ch)) {
                    // LITERAL_BINARY
                }
            }

            // Just a zero integer
            else if (isEndOfLiteral(ch)) {
                // LITERAL_INTEGER
            }

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
