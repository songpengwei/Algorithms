#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    stringstream ss;
    int arr[] = {1, 2, 3, 44, 1};
    for (int i = 0; i < 5; ++i) {
        ss << arr[i];
    }
    cout << ss.str().c_str() << endl;

    return 0;
}
