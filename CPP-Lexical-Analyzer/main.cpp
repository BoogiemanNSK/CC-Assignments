#include <iostream>
#include <fstream>

#define EXE_NAME "main"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " EXE_NAME ".exe [Source file]\n";
        return -1;
    }

    std::ifstream in;
    in.open(argv[1]); // TODO Обработать ошибку неправильного имени файла

    

    in.close();

    return 0;
}
