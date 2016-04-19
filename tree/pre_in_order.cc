#include <iostream>
#include <cassert>
#include <string>

using namespace std;


string get_post_order(string pre_order, string in_order) {
    assert(pre_order.size() == in_order.size());

    int n = pre_order.size();
    if (n == 0) return "";

    char root = pre_order[0];
    int i;
    for (i = 0; i < n; ++i) {
        if (in_order[i] == root) {
            break;
        }
    }

    assert(i < n);

    string pre_left = pre_order.substr(1, i);
    string pre_right = pre_order.substr(i+1);

    string in_left = in_order.substr(0, i);
    string in_right = in_order.substr(i+1);

    return get_post_order(pre_left, in_left) + get_post_order(pre_right, in_right) + root;
}

int main()
{
    cout << get_post_order("abdec", "dbeac") << endl;

    return 0;

}
