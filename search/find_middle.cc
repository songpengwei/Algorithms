#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    if (nums[i] == nums[j]) return;
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int get_mid(vector<int> &nums) {
    int left = 0, right = nums.size() - 1, k = nums.size() / 2;

    while (left <= right) {
        int l = left, r = right;
        swap(nums, l, (l+r)>>1);
        int last = l;
        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < nums[l]) {
                swap(nums, ++last, i);
            }
        }
        swap(nums, l, last);

        if (last == k) return nums[last];
        else if(last < k) left = last + 1;
        else right = last - 1;
    }
}

int get_k_number(vector<int> &nums, int k)  {
    int left = 0, right = nums.size()-1;

    while (left <= right) {
        int l = left, r = right;
        int key = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= key) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] < key) ++l;
            nums[r] = nums[l];
        }
        nums[l] = key;

        if (l == k-1) return nums[l];
        else if (l > k-1) right = l - 1;
        else left = l + 1;
    }

    return nums[left];
}

int main()
{
    int a[] = {10, 9, 2, 3, 1, 4, 5};
    vector<int> a1(a, a+7);
    int b[] = {1, 2, 3, 4, 5, 6};
    vector<int> b1(b, b+6);
    cout << get_mid(a1) << endl;
    cout << get_k_number(a1, 4) << endl;

    return 0;
}
