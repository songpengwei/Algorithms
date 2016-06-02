/**
 * BINARY SEARCH
 * Tips:
 * 1. Loop condition. (equal sign)
 * 2. Middle position calculation.(Overflow, round direction)
 * 3. How to change left/right pointer.(Minus/plus one)
 *
 * a. Sometimes we want to find one element, then we should add
 *    the equal sign in the condition, because we should iterator
 *    one every element and we find in any position, and will
 *    probably exit loop without test all the elements.
 *    In other cases, we just use binary search to find the border
 *    The only goal we have is to loop all the elements, then
 *    we need not add the equal sign, because when we exit the loop
 *    left == right, which is the border.
 * b. When left + right overflow, then we should use left + (right -
 *    left) / 2.
 *    When we have left = mid / right = mid, we should calculate middle
 *    round to right/left to avoid infinite loop when there are only
 *    two elements.
 * c. It depends on we need the middle element or not to add (-1/+1)
 *    when move the left/right pointer.
 */
#include <iostream>
#include <vector>

using namespace std;

// origin search
int find(vector<int> &arr, int target) {
    int left = 0, right = arr.size()-1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// find range, for example {1, 2, 2, 2, 4, 5}
// find the boundary of all 2s, i.e. position 1~3.
int find_range(vector<int> &arr, int target, bool left_range) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left_range ? (left + right) / 2 : (left + right + 1) / 2;
        if (arr[mid] == target) {
            // Find left boundary: if we round right when calculate mid, then
            // we will trap into infinite loop here(imagine
            // we only have two elements in the array).
            // Find right boundary: the similar reason.
            left_range ? right = mid : left = mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}


// find pivot in the rotated sorted array with no duplicates
// that is find the smallest element in the array.
int find_pivot(vector<int> &arr) {
    int left = 0, right = arr.size()-1;

    while (left < right) {
        int mid = (left + right) / 2;

        // Two reasons for using the arr[right]
        // as the target to compare:
        // 1. arr[right] can use to judge the where
        // 'mid' lay, left/right side of the pivot
        // 2. if the array has not been rotated,
        // we can still find the right element.

        // If we use the arr[left] as the target,
        // we can satisfy the reason 1 but not the
        // reason 2, because the movement of the
        // left/right pointer will not be consistent
        // in reason 1 and reason 2.
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// find the pivot in the rotated sorted array which probably
// have some duplicates.
int find_pivot_duplicates(vector<int> &arr) {
    int left = 0, right = arr.size()-1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] == arr[right]) {
            // shrink the right border
            // to skip the duplicates in the
            // interrupt place.
            --right;
        } else if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main()
{
    vector<int> arr = {1, 3, 3, 3, 3, 4, 5, 6, 9};
    cout << find(arr, 5) << endl;
    cout << find_range(arr, 3, true) << endl;
    cout << find_range(arr, 3, false) << endl;

    vector<int> rotate_arr = {9, 10, 11, 1, 3, 5, 6};
    vector<int> rotate_arr_duplicates = {1, 1, 1, 2, 3, 1, 1};
    cout << find_pivot(rotate_arr) << endl;
    cout << find_pivot_duplicates(rotate_arr_duplicates) << endl;
    return 0;
}

