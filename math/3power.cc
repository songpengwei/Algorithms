#include <cmath>
#include <iostream>

using namespace std;

int get_max_3power_of_int() {
    return pow(3, (int)(log(0x7FFFFFFF)/log(3)));
}

bool is_3power(int num) {
    int max3pow = get_max_3power_of_int();
    return num > 0 && max3pow % num == 0;
}

int main()
{
    cout << log(8) << endl;
    cout << "81 is" << is_3power(81) << endl;
    return 0;
}
