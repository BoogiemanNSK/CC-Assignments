#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cctype>

#define EXE_NAME "main"

bool isEndOfLiteral(char);
bool isPossibleSignBeforeLiteral(char);
bool isCorrectDecimalSuffix(std::string);

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

class Reader {
public:
    Reader(const std::string& filename) {
        m_in.open(filename);
        m_currentLine = 1;
        m_cursorPosition = -1;

        if (!m_in.is_open()) {
            std::cout << "[ERROR] Incorrect source file name!\n";
            exit(-1);
        }

        // Reading new token
        m_skipLiteral = false;
        readChar();
        m_str = "";
    }

    Token* nextToken() {
        while (m_ch != EOF) {
            printf("%d [%d, %d]\n", m_ch, m_currentLine, m_cursorPosition);
            if (m_ch == '\n') nextLine();

            // End Of File or Sign Before Literal check
            if (m_ch == EOF || isPossibleSignBeforeLiteral(m_ch)) continue;

            // Comments check
            else if (m_ch == '/') {
                readChar();

                // One-line comment
                if (m_ch == '/') {
                    while (m_ch != '\n') readChar();
                    nextLine();
                }

                // Multi-line comment
                else if (m_ch == '*') {
                    bool isComment = true;
                    while (isComment) {
                        readChar();
                        if (m_ch == '*') {
                            readChar();
                            if (m_ch == '/') isComment = false;
                        } else if (m_ch == '\n') nextLine();
                    }
                }
            }

            // Char / string literal check
            else if (m_ch == '\'' || m_ch == '\"' || m_ch == 'u' || m_ch == 'U' || m_ch == 'L' || m_ch == 'R') {
                bool u8 = false, u = false, U = false, L = false, R = false;
                
                if (m_ch == 'u') {
                    m_str += m_ch;
                    readChar();
                    
                    if (m_ch == '8') {
                        u8 = true;
                        m_str += m_ch;
                        readChar();
                    }
                } else if (m_ch == 'U') {
                    m_str += m_ch;
                    readChar();
                    U = true;
                } else if (m_ch == 'L') {
                    m_str += m_ch;
                    readChar();
                    L = true;
                }

                if (m_ch == 'R') {
                    m_str += m_ch;
                    readChar();
                    R = true;
                }

                // At this moment it have to be one of brackets, otherwise - mistake, skip.
                if (m_ch != '\'' && m_ch != '\"') {
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                    continue;
                }

                bool isChar = false;
                if (m_ch == '\'') {
                    isChar = true;
                }

                bool isLiteral = true;
                while (isLiteral) {
                    readChar();

                    // Next char is special char
                    if (m_ch == '\\') {
                        m_str += m_ch;
                        readChar();
                        m_str += m_ch;
                    }

                    // End of char or file
                    else if ((m_ch == '\'' && isChar) || (m_ch == '\"' && !isChar) || m_ch == EOF) {
                        isLiteral = false;
                    }

                    else {
                        m_str += m_ch;
                    }
                }

                if (m_ch == EOF) continue;
                else if (isChar && m_str.length() > 0 && !u8 && !u && !U && !L && !R) {
                    /* LITERAL_CHAR */
                    return new Token("LITERAL_CHAR", m_currentLine, m_cursorPosition, m_str);
                }
                else if (isChar && m_str.length() > 0 && u8 && !u && !U && !L && !R) {
                    /* LITERAL_CHAR_UTF-8 */
                    return new Token("LITERAL_CHAR_UTF-8", m_currentLine, m_cursorPosition, m_str);
                }
                else if (isChar && m_str.length() > 0 && !u8 && u && !U && !L && !R) {
                    /* LITERAL_CHAR_UTF-16 */
                    return new Token("LITERAL_CHAR_UTF-16", m_currentLine, m_cursorPosition, m_str);
                }
                else if (isChar && m_str.length() > 0 && !u8 && !u && U && !L && !R) {
                    /* LITERAL_CHAR_UTF-32 */
                    return new Token("LITERAL_CHAR_UTF-32", m_currentLine, m_cursorPosition, m_str);
                }
                else if (isChar && m_str.length() > 0 && !u8 && !u && !U && L && !R) {
                    /* LITERAL_CHAR */
                    return new Token("LITERAL_CHAR_WIDE", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && !U && !L && !R) {
                    /* LITERAL_STRING */
                    return new Token("LITERAL_STRING", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && u8 && !u && !U && !L && !R) {
                    /* LITERAL_STRING_UTF-8 */
                    return new Token("LITERAL_STRING_UTF-8", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && u && !U && !L && !R) {
                    /* LITERAL_STRING_UTF-16 */
                    return new Token("LITERAL_STRING_UTF-16", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && U && !L && !R) {
                    /* LITERAL_STRING_UTF-32 */
                    return new Token("LITERAL_STRING_UTF-32", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && !U && L && !R) {
                    /* LITERAL_STRING_WIDE */
                    return new Token("LITERAL_STRING_WIDE", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && !U && !L && R) {
                    /* LITERAL_STRING_RAW */
                    return new Token("LITERAL_STRING_RAW", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && u8 && !u && !U && !L && R) {
                    /* LITERAL_STRING_RAW_UTF-8 */
                    return new Token("LITERAL_STRING_RAW_UTF-8", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && u && !U && !L && R) {
                    /* LITERAL_STRING_RAW_UTF-16 */
                    return new Token("LITERAL_STRING_RAW_UTF-16", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && U && !L && R) {
                    /* LITERAL_STRING_RAW_UTF-32 */
                    return new Token("LITERAL_STRING_RAW_UTF-32", m_currentLine, m_cursorPosition, m_str);
                }
                else if (!isChar && !u8 && !u && !U && L && R) {
                    /* LITERAL_STRING_RAW_WIDE */
                    return new Token("LITERAL_STRING_RAW_WIDE", m_currentLine, m_cursorPosition, m_str);
                }
            }

            // Binary / Octal / Hexadecimal check
            else if (m_ch == '0') {
                m_str += m_ch;
                readChar();

                // Hexadecimal (Hex)
                if (m_ch == 'x' || m_ch == 'X') {
                    bool isFloat = false;
                    m_str += m_ch;
                    readChar();

                    // At least one hex digit or dot (float) has to follow prefix - skip if not the case
                    if (!(m_ch >= '0' && m_ch <= '9' || m_ch >= 'a' && m_ch <= 'f' || m_ch >= 'A' && m_ch <= 'F' || m_ch == '.')) {
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                        continue;
                    }
                    
                    while (m_ch >= '0' && m_ch <= '9' || m_ch >= 'a' && m_ch <= 'f' || m_ch >= 'A' && m_ch <= 'F' || m_ch == '\'' || m_ch == '.') {
                        if (m_ch == '.') {
                            if (isFloat) {
                                // Cannot have two dots
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                            isFloat = true;
                        }
                        else if (m_ch == '\'') {
                            readChar();
                            // At least one hex digit has to follow separator - skip if not the case
                            if (!(m_ch >= '0' && m_ch <= '9' || m_ch >= 'a' && m_ch <= 'f' || m_ch >= 'A' && m_ch <= 'F')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                        }
                        m_str += m_ch;
                        readChar();
                    }
                    if (m_skipLiteral) continue;

                    // If float - has to have exponent
                    if (isFloat && m_ch != 'p' && m_ch != 'P') {
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                        continue;
                    }
                    
                    if (m_ch == 'p' || m_ch == 'P') {
                        m_str += m_ch;
                        readChar();

                        if (m_ch == '+' || m_ch == '-') {
                            m_str += m_ch;
                            readChar();
                        }

                        // Must be at least one number
                        if (!(m_ch >= '0' && m_ch <= '9')) {
                            // Otherwise, mistake - skip literal
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                                readChar();
                            }
                            continue;
                        }

                        while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                            m_str += m_ch;
                            readChar();
                        
                            // At least one digit shoild follow after separator - skip if not the case
                            if (m_ch == '\'') {
                                readChar();
                                if (!(m_ch >= '0' && m_ch <= '9')) {
                                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                    m_skipLiteral = true;
                                    break;
                                }
                            }
                        }
                        if (m_skipLiteral) continue;

                        if (m_ch == 'f' || m_ch == 'F') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) {
                                /* LITERAL_HEX_FLOAT_WITH_EXP */
                                return new Token("LITERAL_HEX_FLOAT_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                            }                        
                        }
                        else if (m_ch == 'l' || m_ch == 'L') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) {
                                /* LITERAL_HEX_LONG_DOUBLE_WITH_EXP */
                                return new Token("LITERAL_HEX_LONG_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                            }
                        }
                        else if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_HEX_DOUBLE_WITH_EXP */
                            return new Token("LITERAL_HEX_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }

                        // Shouldn't have any more symobls after                    
                        continue;                    
                    }

                    std::string suffix = "";
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                        m_str += m_ch;
                        suffix += tolower(m_ch);
                        readChar();
                    }
                    
                    if (isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") {
                            /* LITERAL_HEX */
                            return new Token("LITERAL_HEX", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "u") {
                            /* LITERAL_UNSIGNED_HEX */
                            return new Token("LITERAL_UNSIGNED_HEX", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "l") {
                            /* LITERAL_LONG_HEX */
                            return new Token("LITERAL_LONG_HEX", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "lu" || suffix == "ul") {
                            /* LITERAL_UNSIGNED_LONG_HEX */
                            return new Token("LITERAL_UNSIGNED_LONG_HEX", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                            /* LITERAL_UNSIGNED_LONG_LONG_HEX */
                            return new Token("LITERAL_UNSIGNED_LONG_LONG_HEX", m_currentLine, m_cursorPosition, m_str);
                        }
                    }
                }
                

                // Binary
                else if (m_ch == 'b' && m_ch == 'B') {
                    m_str += m_ch;
                    readChar();
                    
                    // At least one binary digit has to follow prefix - skip if not the case
                    if (!(m_ch >= '0' && m_ch <= '9' || m_ch >= 'a' && m_ch <= 'f' || m_ch >= 'A' && m_ch <= 'F')) {
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                        continue;
                    }

                    while (m_ch == '0' || m_ch == '1' || m_ch == '\'') {
                        if (m_ch == '\'') {
                            readChar();
                            // At least one binary digit has to follow separator - skip if not the case
                            if (!(m_ch == '0' || m_ch == '1')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                        }
                        m_str += m_ch;
                        readChar();
                    }
                    if (m_skipLiteral) continue;

                    std::string suffix = "";
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                        m_str += m_ch;
                        suffix += tolower(m_ch);
                        readChar();
                    }

                    if (isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") {
                            /* LITERAL_BINARY */
                            return new Token("LITERAL_BINARY", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "u") {
                            /* LITERAL_UNSIGNED_BINARY */
                            return new Token("LITERAL_UNSIGNED_BINARY", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "l") {
                            /* LITERAL_LONG_BINARY */
                            return new Token("LITERAL_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "lu" || suffix == "ul") {
                            /* LITERAL_UNSIGNED_LONG_BINARY */
                            return new Token("LITERAL_UNSIGNED_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                            /* LITERAL_UNSIGNED_LONG_LONG_BINARY */
                            return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                        }
                    }
                }

                // Integer / Floating-point / Octal
                else if (m_ch >= '0' && m_ch <= '9' || m_ch == '.' || m_ch == 'e' || m_ch == 'E' || m_ch == '\'') {
                    
                    // At least one digit shoild follow after separator - skip if not the case
                    if (m_ch == '\'') {
                        readChar();
                        if (!(m_ch >= '0' && m_ch <= '9')) {
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                            continue;
                        }
                    }

                    // Octal check
                    while (m_ch >= '0' && m_ch <= '7' || m_ch == '\'') {
                        // At least one digit shoild follow after separator - skip if not the case
                        if (m_ch == '\'') {
                            readChar();
                            if (!(m_ch >= '0' && m_ch <= '9')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                            // Non-octal digit follows separator
                            else if (!(m_ch >= '0' && m_ch <= '7')) {
                                break;
                            }
                        }
                        m_str += m_ch;
                        readChar();
                    }
                    if (m_skipLiteral) continue;

                    // Either octal or mistake
                    if (m_ch == 'l' || m_ch == 'L' || m_ch == 'u' || m_ch == 'U' || isEndOfLiteral(m_ch)) {
                        std::string suffix = "";
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                            m_str += m_ch;
                            suffix += tolower(m_ch);
                            readChar();
                        }

                        // Octal
                        if (isCorrectDecimalSuffix(suffix)) {
                            if (suffix == "") {
                                /* LITERAL_OCTAL */
                                return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                            }
                            else if (suffix == "u") {
                                /* LITERAL_UNSIGNED_OCTAL */
                                return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                            }
                            else if (suffix == "l") {
                                /* LITERAL_LONG_OCTAL */
                                return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                            }
                            else if (suffix == "lu" || suffix == "ul") {
                                /* LITERAL_UNSIGNED_LONG_OCTAL */
                                return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                            }
                            else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                                /* LITERAL_UNSIGNED_LONG_LONG_OCTAL */
                                return new Token("LITERAL_UNSIGNED_LONG_LONG_BINARY", m_currentLine, m_cursorPosition, m_str);
                            }
                        }

                        // Mistake - ignore literal
                        else continue;
                    }

                    // Remaining integer part
                    while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                        m_str += m_ch;
                        readChar();
                        
                        // At least one digit shoild follow after separator - skip if not the case
                        if (m_ch == '\'') {
                            readChar();
                            if (!(m_ch >= '0' && m_ch <= '9')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (m_skipLiteral) continue;

                    // Decimal point
                    if (m_ch == '.') {
                        m_str += m_ch;
                        readChar();

                        // Separator cannot follow decimal point 
                        if (m_ch == '\'') {
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                            continue;
                        }

                        while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                            m_str += m_ch;
                            readChar();
                        
                            // At least one digit shoild follow after separator - skip if not the case
                            if (m_ch == '\'') {
                                readChar();
                                if (!(m_ch >= '0' && m_ch <= '9')) {
                                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                    m_skipLiteral = true;
                                    break;
                                }
                            }
                        }
                        if (m_skipLiteral) continue;

                        if (m_ch == 'f' || m_ch == 'F') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) { 
                                /* LITERAL_FLOAT */
                                return new Token("LITERAL_FLOAT", m_currentLine, m_cursorPosition, m_str);
                            }                        
                        }
                        else if (m_ch == 'l' || m_ch == 'L') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) {
                                /* LITERAL_LONG_DOUBLE */
                                return new Token("LITERAL_LONG_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                            }
                        }
                        else if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_DOUBLE */
                            return new Token("LITERAL_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                        }
                    }

                    // Exponent
                    if (m_ch == 'e' || m_ch == 'E') {
                        m_str += m_ch;
                        readChar();

                        if (m_ch == '+' || m_ch == '-') {
                            m_str += m_ch;
                            readChar();
                        }

                        // Must be at least one number
                        if (!(m_ch >= '0' && m_ch <= '9')) {
                            // Otherwise, mistake - skip literal
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                                readChar();
                            }
                            continue;
                        }

                        while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                            m_str += m_ch;
                            readChar();
                        
                            // At least one digit shoild follow after separator - skip if not the case
                            if (m_ch == '\'') {
                                readChar();
                                if (!(m_ch >= '0' && m_ch <= '9')) {
                                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                    m_skipLiteral = true;
                                    break;
                                }
                            }
                        }
                        if (m_skipLiteral) continue;

                        if (m_ch == 'f' || m_ch == 'F') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) {
                                /* LITERAL_FLOAT_WITH_EXP */
                                return new Token("LITERAL_FLOAT_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                            }                        
                        }
                        else if (m_ch == 'l' || m_ch == 'L') {
                            m_str += m_ch;
                            readChar();
                            if (isEndOfLiteral(m_ch)) {
                                /* LITERAL_LONG_DOUBLE_WITH_EXP */
                                return new Token("LITERAL_LONG_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                            }
                        }
                        else if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_DOUBLE_WITH_EXP */
                            return new Token("LITERAL_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }
                    }

                    // If reached this line - then mistake
                    // Not octal, integer or floating-point number
                    // Skip literal
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                        readChar();
                    }
                }

                // Just a zero integer
                else if (isEndOfLiteral(m_ch)) {
                    /* LITERAL_INT */
                    std::cout << "LITERAL_INT [" << m_str << "]" << std::endl;
                    return new Token("LITERAL_INT", m_currentLine, m_cursorPosition, m_str);
                }

            }

            // Integer / Floating-point
            else if (m_ch >= '1' && m_ch <= '9') {
                m_str += m_ch;
                readChar();

                // Integer check
                while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                    m_str += m_ch;
                    readChar();
                        
                    // At least one digit shoild follow after separator - skip if not the case
                    if (m_ch == '\'') {
                        readChar();
                        if (!(m_ch >= '0' && m_ch <= '9')) {
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                            m_skipLiteral = true;
                            break;
                        }
                    }
                }
                if (m_skipLiteral) continue;

                // Either integer or mistake
                if (m_ch == 'l' || m_ch == 'L' || m_ch == 'u' || m_ch == 'U' || isEndOfLiteral(m_ch)) {
                    std::string suffix = "";
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                        m_str += m_ch;
                        suffix += tolower(m_ch);
                        readChar();
                    }

                    // Integer
                    if (isCorrectDecimalSuffix(suffix)) {
                        if (suffix == "") {
                            /* LITERAL_INT */
                            return new Token("LITERAL_INT", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "u") {
                            /* LITERAL_UNSIGNED_INT */
                            return new Token("LITERAL_UNSIGNED_INT", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "l") {
                            /* LITERAL_LONG_INT */
                            return new Token("LITERAL_LONG_INT", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "lu" || suffix == "ul") {
                            /* LITERAL_UNSIGNED_LONG_INT */
                            return new Token("LITERAL_UNSIGNED_LONG_INT", m_currentLine, m_cursorPosition, m_str);
                        }
                        else if (suffix == "ull" || suffix == "lul" || suffix == "llu") {
                            /* LITERAL_UNSIGNED_LONG_LONG_INT */
                            return new Token("LITERAL_UNSIGNED_LONG_LONG_INT", m_currentLine, m_cursorPosition, m_str);
                        }
                    }

                    // Mistake - ignore literal
                    else continue;
                }

                // Decimal point
                if (m_ch == '.') {
                    m_str += m_ch;
                    readChar();

                    // Separator cannot follow decimal point 
                    if (m_ch == '\'') {
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                        continue;
                    }

                    while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                        m_str += m_ch;
                        readChar();
                        
                        // At least one digit shoild follow after separator - skip if not the case
                        if (m_ch == '\'') {
                                readChar();
                            if (!(m_ch >= '0' && m_ch <= '9')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (m_skipLiteral) continue;

                    if (m_ch == 'f' || m_ch == 'F') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) { 
                            /* LITERAL_FLOAT */
                            return new Token("LITERAL_FLOAT", m_currentLine, m_cursorPosition, m_str);
                        }                        
                    }
                    else if (m_ch == 'l' || m_ch == 'L') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_LONG_DOUBLE */
                            return new Token("LITERAL_LONG_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                        }
                    }
                    else if (isEndOfLiteral(m_ch)) {
                        /* LITERAL_DOUBLE */
                        return new Token("LITERAL_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                    }
                }

                // Exponent
                if (m_ch == 'e' || m_ch == 'E') {
                    m_str += m_ch;
                    readChar();

                    if (m_ch == '+' || m_ch == '-') {
                        m_str += m_ch;
                        readChar();
                    }

                    // Must be at least one number
                    if (!(m_ch >= '0' && m_ch <= '9')) {
                        // Otherwise, mistake - skip literal
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                            readChar();
                        }
                        continue;
                    }

                    while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                        m_str += m_ch;
                        readChar();

                        // At least one digit shoild follow after separator - skip if not the case
                        if (m_ch == '\'') {
                            readChar();
                            if (!(m_ch >= '0' && m_ch <= '9')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                                }
                        }
                    }
                    if (m_skipLiteral) continue;

                    if (m_ch == 'f' || m_ch == 'F') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_FLOAT_WITH_EXP */
                            return new Token("LITERAL_FLOAT_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }                        
                    }
                    else if (m_ch == 'l' || m_ch == 'L') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_LONG_DOUBLE_WITH_EXP */
                            return new Token("LITERAL_LONG_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }
                    }
                    else if (isEndOfLiteral(m_ch)) {
                        /* LITERAL_DOUBLE_WITH_EXP */
                        return new Token("LITERAL_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                    }
                }

                // If reached this line - then mistake
                // Not octal, integer or floating-point number
                // Skip literal
                while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                    readChar();
                }
            }

            // Floating-point with no integer part
            else if (m_ch == '.') {
                m_str += m_ch;
                readChar();

                // Separator cannot follow decimal point 
                if (m_ch == '\'') {
                    while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                    continue;
                }

                while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                    m_str += m_ch;
                    readChar();
                        
                    // At least one digit shoild follow after separator - skip if not the case
                    if (m_ch == '\'') {
                        readChar();
                        if (!(m_ch >= '0' && m_ch <= '9')) {
                            while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                            m_skipLiteral = true;
                            break;
                        }
                    }
                }
                if (m_skipLiteral) continue;

                if (m_ch == 'f' || m_ch == 'F') {
                    m_str += m_ch;
                    readChar();
                    if (isEndOfLiteral(m_ch)) { 
                        /* LITERAL_FLOAT */
                        std::cout << "LITERAL_FLOAT [" << m_str << "]" << std::endl;
                        return new Token("LITERAL_FLOAT", m_currentLine, m_cursorPosition, m_str);
                    }                        
                }
                else if (m_ch == 'l' || m_ch == 'L') {
                    m_str += m_ch;
                    readChar();
                    if (isEndOfLiteral(m_ch)) {
                        /* LITERAL_LONG_DOUBLE */
                        std::cout << "LITERAL_LONG_DOUBLE [" << m_str << "]" << std::endl;
                        return new Token("LITERAL_LONG_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                    }
                }
                else if (isEndOfLiteral(m_ch)) {
                    /* LITERAL_DOUBLE */
                    std::cout << "LITERAL_DOUBLE [" << m_str << "]" << std::endl;
                    return new Token("LITERAL_DOUBLE", m_currentLine, m_cursorPosition, m_str);
                }

                // Exponent
                else if (m_ch == 'e' || m_ch == 'E') {
                    m_str += m_ch;
                    readChar();

                    if (m_ch == '+' || m_ch == '-') {
                        m_str += m_ch;
                        readChar();
                    }

                    // Must be at least one number
                    if (!(m_ch >= '0' && m_ch <= '9')) {
                        // Otherwise, mistake - skip literal
                        while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                            readChar();
                        }
                        continue;
                    }

                    while (m_ch >= '0' && m_ch <= '9' || m_ch == '\'') {
                        m_str += m_ch;
                        readChar();
                        
                        // At least one digit shoild follow after separator - skip if not the case
                        if (m_ch == '\'') {
                            readChar();
                            if (!(m_ch >= '0' && m_ch <= '9')) {
                                while (!isEndOfLiteral(m_ch) && m_ch != EOF) readChar();
                                m_skipLiteral = true;
                                break;
                            }
                        }
                    }
                    if (m_skipLiteral) continue;

                    if (m_ch == 'f' || m_ch == 'F') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_FLOAT_WITH_EXP */
                            return new Token("LITERAL_FLOAT_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }                        
                    }
                    else if (m_ch == 'l' || m_ch == 'L') {
                        m_str += m_ch;
                        readChar();
                        if (isEndOfLiteral(m_ch)) {
                            /* LITERAL_LONG_DOUBLE_WITH_EXP */
                            return new Token("LITERAL_LONG_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                        }
                    }
                    else if (isEndOfLiteral(m_ch)) {
                        /* LITERAL_DOUBLE_WITH_EXP */
                        return new Token("LITERAL_DOUBLE_WITH_EXP", m_currentLine, m_cursorPosition, m_str);
                    }
                }

                // Should not be anything after exponent part (mistake)
                while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                    readChar();
                }
            }

            // Additional check for bool and nullptr
            else {
                while (!isEndOfLiteral(m_ch) && m_ch != EOF) {
                    m_str += m_ch;
                    readChar();
                }

                if (m_str == "true" || m_str == "false") {
                    /* LITERAL_BOOL */
                    return new Token("LITERAL_BOOL", m_currentLine, m_cursorPosition, m_str);
                }

                else if (m_str == "nullptr") {
                    /* LITERAL_NULLPTR */
                    return new Token("LITERAL_NULLPTR", m_currentLine, m_cursorPosition, m_str);
                }
            }
        }

        return nullptr;
    }

    void reset() {

    }

private:
    int m_currentLine;
    int m_cursorPosition;
    std::ifstream m_in;

    char m_ch = '0';    
    std::string m_str;
    bool m_skipLiteral = false;

    void readChar() {
        m_ch = m_in.get();
        m_cursorPosition++;
    }

    void nextLine() {
        m_currentLine++;
        m_cursorPosition = -1;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "[ERROR] Usage: " EXE_NAME ".exe [Source file]\n";
        return -1;
    }

    Reader reader(argv[1]);

    Token* token;
    token = reader.nextToken();
    printf("TOKEN\n");
    while(token != nullptr) {
        token->printToken();
        token = reader.nextToken();
    }

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
