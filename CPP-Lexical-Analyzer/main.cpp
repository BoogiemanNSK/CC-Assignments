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
bool isPossibleSignBeforeLiteral(char);
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
    bool skipLiteral = false;

    while(ch != EOF) {
        // Reading new token
        skipLiteral = false;
        ch = in.get();
        str = "";
        
        // End Of File or Sign Before Literal check
        if (ch == EOF || isPossibleSignBeforeLiteral(ch)) continue;

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

        // Char / string literal check
        else if (ch == '\'' || ch == '\"' || ch == 'u' || ch == 'U' || ch == 'L' || ch == 'R') {
            bool u8 = false, u = false, U = false, L = false, R = false;
            
            if (ch == 'u') {
                str += ch;
                ch = in.get();
                
                if (ch == '8') {
                    u8 = true;
                    str += ch;
                    ch = in.get();
                }
            } else if (ch == 'U') {
                str += ch;
                ch = in.get();
                U = true;
            } else if (ch == 'L') {
                str += ch;
                ch = in.get();
                L = true;
            }

            if (ch == 'R') {
                str += ch;
                ch = in.get();
                R = true;
            }

            // At this moment it have to be one of brackets, otherwise - mistake, skip.
            if (ch != '\'' && ch != '\"') {
                while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                continue;
            }

            bool isChar = false;
            if (ch == '\'') {
                isChar = true;
            }

            bool isLiteral = true;
            while (isLiteral) {
                ch = in.get();

                // Next char is special char
                if (ch == '\\') {
                    str += ch;
                    ch = in.get();
                    str += ch;
                }

                // End of char or file
                else if ((ch == '\'' && isChar) || (ch == '\"' && !isChar) || ch == EOF) {
                    isLiteral = false;
                }

                else {
                    str += ch;
                }
            }

            if (ch == EOF) continue;
            else if (isChar && str.length() > 0 && !u8 && !u && !U && !L && !R) {
                /* LITERAL_CHAR */
                std::cout << "LITERAL_CHAR [" << str << "]" << std::endl;
            }
            else if (isChar && str.length() > 0 && u8 && !u && !U && !L && !R) {
                /* LITERAL_CHAR_UTF-8 */
                std::cout << "LITERAL_CHAR_UTF-8 [" << str << "]" << std::endl;
            }
            else if (isChar && str.length() > 0 && !u8 && u && !U && !L && !R) {
                /* LITERAL_CHAR_UTF-16 */
                std::cout << "LITERAL_CHAR_UTF-16 [" << str << "]" << std::endl;
            }
            else if (isChar && str.length() > 0 && !u8 && !u && U && !L && !R) {
                /* LITERAL_CHAR_UTF-32 */
                std::cout << "LITERAL_CHAR_UTF-32 [" << str << "]" << std::endl;
            }
            else if (isChar && str.length() > 0 && !u8 && !u && !U && L && !R) {
                /* LITERAL_CHAR */
                std::cout << "LITERAL_CHAR_WIDE [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && !U && !L && !R) {
                /* LITERAL_STRING */
                std::cout << "LITERAL_STRING [" << str << "]" << std::endl;
            }
            else if (!isChar && u8 && !u && !U && !L && !R) {
                /* LITERAL_STRING_UTF-8 */
                std::cout << "LITERAL_STRING_UTF-8 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && u && !U && !L && !R) {
                /* LITERAL_STRING_UTF-16 */
                std::cout << "LITERAL_STRING_UTF-16 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && U && !L && !R) {
                /* LITERAL_STRING_UTF-32 */
                std::cout << "LITERAL_STRING_UTF-32 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && !U && L && !R) {
                /* LITERAL_STRING_WIDE */
                std::cout << "LITERAL_STRING_WIDE [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && !U && !L && R) {
                /* LITERAL_STRING_RAW */
                std::cout << "LITERAL_STRING_RAW [" << str << "]" << std::endl;
            }
            else if (!isChar && u8 && !u && !U && !L && R) {
                /* LITERAL_STRING_RAW_UTF-8 */
                std::cout << "LITERAL_STRING_RAW_UTF-8 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && u && !U && !L && R) {
                /* LITERAL_STRING_RAW_UTF-16 */
                std::cout << "LITERAL_STRING_RAW_UTF-16 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && U && !L && R) {
                /* LITERAL_STRING_RAW_UTF-32 */
                std::cout << "LITERAL_STRING_RAW_UTF-32 [" << str << "]" << std::endl;
            }
            else if (!isChar && !u8 && !u && !U && L && R) {
                /* LITERAL_STRING_RAW_WIDE */
                std::cout << "LITERAL_STRING_RAW_WIDE [" << str << "]" << std::endl;
            }
        }

        // Binary / Octal / Hexadecimal check
        else if (ch == '0') {
            str += ch;
            ch = in.get();

            // Hexadecimal (Hex)
            if (ch == 'x' || ch == 'X') {
                bool isFloat = false;
                str += ch;
                ch = in.get();

                // At least one hex digit or dot (float) has to follow prefix - skip if not the case
                if (!(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F' || ch == '.')) {
                    while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                    continue;
                }
                
                while (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F' || ch == '\'' || ch == '.') {
                    if (ch == '.') {
                        if (isFloat) {
                            // Cannot have two dots
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                        isFloat = true;
                    }
                    else if (ch == '\'') {
                        ch = in.get();
                        // At least one hex digit has to follow separator - skip if not the case
                        if (!(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                    }
                    str += ch;
                    ch = in.get();
                }
                if (skipLiteral) continue;

                // If float - has to have exponent
                if (isFloat && ch != 'p' && ch != 'P') {
                    while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                    continue;
                }
                
                if (ch == 'p' || ch == 'P') {
                    str += ch;
                    ch = in.get();

                    if (ch == '+' || ch == '-') {
                        str += ch;
                        ch = in.get();
                    }

                    // Must be at least one number
                    if (!(ch >= '0' && ch <= '9')) {
                        // Otherwise, mistake - skip literal
                        while (!isEndOfLiteral(ch) && ch != EOF) {
                            ch = in.get();
                        }
                        continue;
                    }

                    while (ch >= '0' && ch <= '9' || ch == '\'') {
                        str += ch;
                        ch = in.get();
                    
                        // At least one digit shoild follow after separator - skip if not the case
                        if (ch == '\'') {
                            ch = in.get();
                            if (!(ch >= '0' && ch <= '9')) {
                                while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                                skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (skipLiteral) continue;

                    if (ch == 'f' || ch == 'F') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) {
                            /* LITERAL_HEX_FLOAT_WITH_EXP */
                            std::cout << "LITERAL_HEX_FLOAT_WITH_EXP [" << str << "]" << std::endl;
                        }                        
                    }
                    else if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) {
                            /* LITERAL_HEX_LONG_DOUBLE_WITH_EXP */
                            std::cout << "LITERAL_HEX_LONG_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                        }
                    }
                    else if (isEndOfLiteral(ch)) {
                        /* LITERAL_HEX_DOUBLE_WITH_EXP */
                        std::cout << "LITERAL_HEX_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                    }

                    // Shouldn't have any more symobls after                    
                    continue;                    
                }

                std::string suffix = "";
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    str += ch;
                    suffix += tolower(ch);
                    ch = in.get();
                }
                
                if (isCorrectDecimalSuffix(suffix)) {
                    if (suffix == "") {
                        /* LITERAL_HEX */
                        std::cout << "LITERAL_HEX [" << str << "]" << std::endl;
                    }
                    else if (suffix == "u") {
                        /* LITERAL_UNSIGNED_HEX */
                        std::cout << "LITERAL_UNSIGNED_HEX [" << str << "]" << std::endl;
                    }
                    else if (suffix == "l") {
                        /* LITERAL_LONG_HEX */
                        std::cout << "LITERAL_LONG_HEX [" << str << "]" << std::endl;
                    }
                    else if (suffix == "lu" || suffix == "ul") {
                        /* LITERAL_UNSIGNED_LONG_HEX */
                        std::cout << "LITERAL_UNSIGNED_LONG_HEX [" << str << "]" << std::endl;
                    }
                    else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                        /* LITERAL_UNSIGNED_LONG_LONG_HEX */
                        std::cout << "LITERAL_UNSIGNED_LONG_LONG_HEX [" << str << "]" << std::endl;
                    }
                }
            }

            // Binary
            else if (ch == 'b' && ch == 'B') {
                str += ch;
                ch = in.get();
                
                // At least one binary digit has to follow prefix - skip if not the case
                if (!(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')) {
                    while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                    continue;
                }

                while (ch == '0' || ch == '1' || ch == '\'') {
                    if (ch == '\'') {
                        ch = in.get();
                        // At least one binary digit has to follow separator - skip if not the case
                        if (!(ch == '0' || ch == '1')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                    }
                    str += ch;
                    ch = in.get();
                }
                if (skipLiteral) continue;

                std::string suffix = "";
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    str += ch;
                    suffix += tolower(ch);
                    ch = in.get();
                }

                if (isCorrectDecimalSuffix(suffix)) {
                    if (suffix == "") {
                        /* LITERAL_BINARY */
                        std::cout << "LITERAL_BINARY [" << str << "]" << std::endl;
                    }
                    else if (suffix == "u") {
                        /* LITERAL_UNSIGNED_BINARY */
                        std::cout << "LITERAL_UNSIGNED_BINARY [" << str << "]" << std::endl;
                    }
                    else if (suffix == "l") {
                        /* LITERAL_LONG_BINARY */
                        std::cout << "LITERAL_LONG_BINARY [" << str << "]" << std::endl;
                    }
                    else if (suffix == "lu" || suffix == "ul") {
                        /* LITERAL_UNSIGNED_LONG_BINARY */
                        std::cout << "LITERAL_UNSIGNED_LONG_BINARY [" << str << "]" << std::endl;
                    }
                    else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                        /* LITERAL_UNSIGNED_LONG_LONG_BINARY */
                        std::cout << "LITERAL_UNSIGNED_LONG_LONG_BINARY [" << str << "]" << std::endl;
                    }
                }
            }

            // Integer / Floating-point / Octal
            else if (ch >= '0' && ch <= '9' || ch == '.' || ch == 'e' || ch == 'E' || ch == '\'') {
                
                // At least one digit shoild follow after separator - skip if not the case
                if (ch == '\'') {
                    ch = in.get();
                    if (!(ch >= '0' && ch <= '9')) {
                        while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                        continue;
                    }
                }

                // Octal check
                while (ch >= '0' && ch <= '7' || ch == '\'') {
                    // At least one digit shoild follow after separator - skip if not the case
                    if (ch == '\'') {
                        ch = in.get();
                        if (!(ch >= '0' && ch <= '9')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                        // Non-octal digit follows separator
                        else if (!(ch >= '0' && ch <= '7')) {
                            break;
                        }
                    }
                    str += ch;
                    ch = in.get();
                }
                if (skipLiteral) continue;

                // Either octal or mistake
                if (ch == 'l' || ch == 'L' || ch == 'u' || ch == 'U' || isEndOfLiteral(ch)) {
                    std::string suffix = "";
                    while (!isEndOfLiteral(ch) && ch != EOF) {
                        str += ch;
                        suffix += tolower(ch);
                        ch = in.get();
                    }

                    // Octal
                    if (isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") {
                            /* LITERAL_OCTAL */
                            std::cout << "LITERAL_OCTAL [" << str << "]" << std::endl;
                        }
                        else if (suffix == "u") {
                            /* LITERAL_UNSIGNED_OCTAL */
                            std::cout << "LITERAL_UNSIGNED_OCTAL [" << str << "]" << std::endl;
                        }
                        else if (suffix == "l") {
                            /* LITERAL_LONG_OCTAL */
                            std::cout << "LITERAL_LONG_OCTAL [" << str << "]" << std::endl;
                        }
                        else if (suffix == "lu" || suffix == "ul") {
                            /* LITERAL_UNSIGNED_LONG_OCTAL */
                            std::cout << "LITERAL_UNSIGNED_LONG_OCTAL [" << str << "]" << std::endl;
                        }
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                            /* LITERAL_UNSIGNED_LONG_LONG_OCTAL */
                            std::cout << "LITERAL_UNSIGNED_LONG_LONG_OCTAL [" << str << "]" << std::endl;
                        }
                    }

                    // Mistake - ignore literal
                    else continue;
                }

                // Remaining integer part
                while (ch >= '0' && ch <= '9' || ch == '\'') {
                    str += ch;
                    ch = in.get();
                    
                    // At least one digit shoild follow after separator - skip if not the case
                    if (ch == '\'') {
                        ch = in.get();
                        if (!(ch >= '0' && ch <= '9')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                    }
                }
                if (skipLiteral) continue;

                // Decimal point
                if (ch == '.') {
                    str += ch;
                    ch = in.get();

                    // Separator cannot follow decimal point 
                    if (ch == '\'') {
                        while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                        continue;
                    }

                    while (ch >= '0' && ch <= '9' || ch == '\'') {
                        str += ch;
                        ch = in.get();
                    
                        // At least one digit shoild follow after separator - skip if not the case
                        if (ch == '\'') {
                            ch = in.get();
                            if (!(ch >= '0' && ch <= '9')) {
                                while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                                skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (skipLiteral) continue;

                    if (ch == 'f' || ch == 'F') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) { 
                            /* LITERAL_FLOAT */
                            std::cout << "LITERAL_FLOAT [" << str << "]" << std::endl;
                        }                        
                    }
                    else if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) {
                            /* LITERAL_LONG_DOUBLE */
                            std::cout << "LITERAL_LONG_DOUBLE [" << str << "]" << std::endl;
                        }
                    }
                    else if (isEndOfLiteral(ch)) {
                        /* LITERAL_DOUBLE */
                        std::cout << "LITERAL_DOUBLE [" << str << "]" << std::endl;
                    }
                }

                // Exponent
                if (ch == 'e' || ch == 'E') {
                    str += ch;
                    ch = in.get();

                    if (ch == '+' || ch == '-') {
                        str += ch;
                        ch = in.get();
                    }

                    // Must be at least one number
                    if (!(ch >= '0' && ch <= '9')) {
                        // Otherwise, mistake - skip literal
                        while (!isEndOfLiteral(ch) && ch != EOF) {
                            ch = in.get();
                        }
                        continue;
                    }

                    while (ch >= '0' && ch <= '9' || ch == '\'') {
                        str += ch;
                        ch = in.get();
                    
                        // At least one digit shoild follow after separator - skip if not the case
                        if (ch == '\'') {
                            ch = in.get();
                            if (!(ch >= '0' && ch <= '9')) {
                                while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                                skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (skipLiteral) continue;

                    if (ch == 'f' || ch == 'F') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) {
                            /* LITERAL_FLOAT_WITH_EXP */
                            std::cout << "LITERAL_FLOAT_WITH_EXP [" << str << "]" << std::endl;
                        }                        
                    }
                    else if (ch == 'l' || ch == 'L') {
                        str += ch;
                        ch = in.get();
                        if (isEndOfLiteral(ch)) {
                            /* LITERAL_LONG_DOUBLE_WITH_EXP */
                            std::cout << "LITERAL_LONG_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                        }
                    }
                    else if (isEndOfLiteral(ch)) {
                        /* LITERAL_DOUBLE_WITH_EXP */
                        std::cout << "LITERAL_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                    }
                }

                // If reached this line - then mistake
                // Not octal, integer or floating-point number
                // Skip literal
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    ch = in.get();
                }
            }

            // Just a zero integer
            else if (isEndOfLiteral(ch)) {
                /* LITERAL_INT */
                std::cout << "LITERAL_INT [" << str << "]" << std::endl;
            }

        }

        // Integer / Floating-point
        else if (ch >= '1' && ch <= '9') {
            str += ch;
            ch = in.get();

            // Integer check
            while (ch >= '0' && ch <= '9' || ch == '\'') {
                str += ch;
                ch = in.get();
                    
                // At least one digit shoild follow after separator - skip if not the case
                if (ch == '\'') {
                    ch = in.get();
                    if (!(ch >= '0' && ch <= '9')) {
                        while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                        skipLiteral = true;
                        break;
                    }
                }
            }
            if (skipLiteral) continue;

            // Either integer or mistake
            if (ch == 'l' || ch == 'L' || ch == 'u' || ch == 'U' || isEndOfLiteral(ch)) {
                std::string suffix = "";
                while (!isEndOfLiteral(ch) && ch != EOF) {
                    str += ch;
                    suffix += tolower(ch);
                    ch = in.get();
                }

                // Integer
                if (isCorrectDecimalSuffix(suffix)) {
                    if (suffix == "") {
                        /* LITERAL_INT */
                        std::cout << "LITERAL_INT [" << str << "]" << std::endl;
                    }
                    else if (suffix == "u") {
                        /* LITERAL_UNSIGNED_INT */
                        std::cout << "LITERAL_UNSIGNED_INT [" << str << "]" << std::endl;
                    }
                    else if (suffix == "l") {
                        /* LITERAL_LONG_INT */
                        std::cout << "LITERAL_LONG_INT [" << str << "]" << std::endl;
                    }
                    else if (suffix == "lu" || suffix == "ul") {
                        /* LITERAL_UNSIGNED_LONG_INT */
                        std::cout << "LITERAL_UNSIGNED_LONG_INT [" << str << "]" << std::endl;
                    }
                    else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                        /* LITERAL_UNSIGNED_LONG_LONG_INT */
                        std::cout << "LITERAL_UNSIGNED_LONG_LONG_INT [" << str << "]" << std::endl;
                    }
                }

                // Mistake - ignore literal
                else continue;
            }

            // Decimal point
            if (ch == '.') {
                str += ch;
                ch = in.get();

                // Separator cannot follow decimal point 
                if (ch == '\'') {
                    while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                    continue;
                }

                while (ch >= '0' && ch <= '9' || ch == '\'') {
                    str += ch;
                    ch = in.get();
                    
                    // At least one digit shoild follow after separator - skip if not the case
                    if (ch == '\'') {
                            ch = in.get();
                        if (!(ch >= '0' && ch <= '9')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                    }
                }
                if (skipLiteral) continue;

                if (ch == 'f' || ch == 'F') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) { 
                        /* LITERAL_FLOAT */
                        std::cout << "LITERAL_FLOAT [" << str << "]" << std::endl;
                    }                        
                }
                else if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) {
                        /* LITERAL_LONG_DOUBLE */
                        std::cout << "LITERAL_LONG_DOUBLE [" << str << "]" << std::endl;
                    }
                }
                else if (isEndOfLiteral(ch)) {
                    /* LITERAL_DOUBLE */
                    std::cout << "LITERAL_DOUBLE [" << str << "]" << std::endl;
                }
            }

            // Exponent
            if (ch == 'e' || ch == 'E') {
                str += ch;
                ch = in.get();

                if (ch == '+' || ch == '-') {
                    str += ch;
                    ch = in.get();
                }

                // Must be at least one number
                if (!(ch >= '0' && ch <= '9')) {
                    // Otherwise, mistake - skip literal
                    while (!isEndOfLiteral(ch) && ch != EOF) {
                        ch = in.get();
                    }
                    continue;
                }

                while (ch >= '0' && ch <= '9' || ch == '\'') {
                    str += ch;
                    ch = in.get();

                    // At least one digit shoild follow after separator - skip if not the case
                    if (ch == '\'') {
                        ch = in.get();
                        if (!(ch >= '0' && ch <= '9')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                            }
                    }
                }
                if (skipLiteral) continue;

                if (ch == 'f' || ch == 'F') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) {
                        /* LITERAL_FLOAT_WITH_EXP */
                        std::cout << "LITERAL_FLOAT_WITH_EXP [" << str << "]" << std::endl;
                    }                        
                }
                else if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) {
                        /* LITERAL_LONG_DOUBLE_WITH_EXP */
                        std::cout << "LITERAL_LONG_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                    }
                }
                else if (isEndOfLiteral(ch)) {
                    /* LITERAL_DOUBLE_WITH_EXP */
                    std::cout << "LITERAL_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                }
            }

            // If reached this line - then mistake
            // Not octal, integer or floating-point number
            // Skip literal
            while (!isEndOfLiteral(ch) && ch != EOF) {
                ch = in.get();
            }
        }

        // Floating-point with no integer part
        else if (ch == '.') {
            str += ch;
            ch = in.get();

            // Separator cannot follow decimal point 
            if (ch == '\'') {
                while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                continue;
            }

            while (ch >= '0' && ch <= '9' || ch == '\'') {
                str += ch;
                ch = in.get();
                    
                // At least one digit shoild follow after separator - skip if not the case
                if (ch == '\'') {
                    ch = in.get();
                    if (!(ch >= '0' && ch <= '9')) {
                        while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                        skipLiteral = true;
                        break;
                    }
                }
            }
            if (skipLiteral) continue;

            if (ch == 'f' || ch == 'F') {
                str += ch;
                ch = in.get();
                if (isEndOfLiteral(ch)) { 
                    /* LITERAL_FLOAT */
                    std::cout << "LITERAL_FLOAT [" << str << "]" << std::endl;
                }                        
            }
            else if (ch == 'l' || ch == 'L') {
                str += ch;
                ch = in.get();
                if (isEndOfLiteral(ch)) {
                    /* LITERAL_LONG_DOUBLE */
                    std::cout << "LITERAL_LONG_DOUBLE [" << str << "]" << std::endl;
                }
            }
            else if (isEndOfLiteral(ch)) {
                /* LITERAL_DOUBLE */
                std::cout << "LITERAL_DOUBLE [" << str << "]" << std::endl;
            }

            // Exponent
            else if (ch == 'e' || ch == 'E') {
                str += ch;
                ch = in.get();

                if (ch == '+' || ch == '-') {
                    str += ch;
                    ch = in.get();
                }

                // Must be at least one number
                if (!(ch >= '0' && ch <= '9')) {
                    // Otherwise, mistake - skip literal
                    while (!isEndOfLiteral(ch) && ch != EOF) {
                        ch = in.get();
                    }
                    continue;
                }

                while (ch >= '0' && ch <= '9' || ch == '\'') {
                    str += ch;
                    ch = in.get();
                    
                    // At least one digit shoild follow after separator - skip if not the case
                    if (ch == '\'') {
                        ch = in.get();
                        if (!(ch >= '0' && ch <= '9')) {
                            while (!isEndOfLiteral(ch) && ch != EOF) ch = in.get();
                            skipLiteral = true;
                            break;
                        }
                    }
                }
                if (skipLiteral) continue;

                if (ch == 'f' || ch == 'F') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) {
                        /* LITERAL_FLOAT_WITH_EXP */
                        std::cout << "LITERAL_FLOAT_WITH_EXP [" << str << "]" << std::endl;
                    }                        
                }
                else if (ch == 'l' || ch == 'L') {
                    str += ch;
                    ch = in.get();
                    if (isEndOfLiteral(ch)) {
                        /* LITERAL_LONG_DOUBLE_WITH_EXP */
                        std::cout << "LITERAL_LONG_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                    }
                }
                else if (isEndOfLiteral(ch)) {
                    /* LITERAL_DOUBLE_WITH_EXP */
                    std::cout << "LITERAL_DOUBLE_WITH_EXP [" << str << "]" << std::endl;
                }
            }

            // Should not be anything after exponent part (mistake)
            while (!isEndOfLiteral(ch) && ch != EOF) {
                ch = in.get();
            }
        }

        // Additional check for bool and nullptr
        else {
            while (!isEndOfLiteral(ch) && ch != EOF) {
                str += ch;
                ch = in.get();
            }

            if (str == "true" || str == "false") {
                /* LITERAL_BOOL */
                std::cout << "LITERAL_BOOL [" << str << "]" << std::endl;
            }

            else if (str == "nullptr") {
                /* LITERAL_NULLPTR */
                std::cout << "LITERAL_NULLPTR [" << str << "]" << std::endl;
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

bool isPossibleSignBeforeLiteral(char c) {
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
        c == '(' ||
        c == '[' ||
        c == '{' ||
        c == '\n'||
        c == '\t';
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
