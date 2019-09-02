#include <iostream>
#include <string>

#define NUM 25;
using namespace std;

int main() {
    int a = 10;
    int b = 0xFee;
    long c = 16L;
    float d = 15.3f;

    // Just a comment :3

    int e = (25 + 36) * 2;
    char f = 'g';
    char g = 36;
    string h = "Some string ~~(8:>\n(that was a rat)";
    int i = NUM;
    const int j = 1;

    /*
        Here is another comment.
        Which is also multi-line.
        ~~(8:> ~~(8:> ~~(8:>
    */

    std::cout << a << endl;
    std::cout << b << endl;
    std::cout << c << endl;
    std::cout << d << endl;
    std::cout << e << endl;
    std::cout << f << endl;
    std::cout << g << endl;
    std::cout << h << endl;
    std::cout << i << endl;
    std::cout << j << endl;
    std::cout << 1 + 2 + 3 << endl;

    return 0;
}
