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
    string h = "Some string ~~(8:> \n (that was a rat)";
    int i = NUM;
    const int j = 1;

    /*
        Here is another comment.
        Which is also multi-line.
        ~~(8:> ~~(8:> ~~(8:>
    */

    float k = 123.4e5;
    float l = .1l;
    bool m = false;
    auto t = 01249.5;
    auto u = 0x12.3p2;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << h << endl;
    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    cout << l << endl;
    cout << m << endl;
    cout << t << endl;
    cout << u << endl;
    cout << 1 + 2 + 3 << endl;

    return 0;
}
