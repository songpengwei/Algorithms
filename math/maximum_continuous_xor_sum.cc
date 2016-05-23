/**
 * Problem: we can pick continuous numbers from two endpoint. And the two
 *          pieces of numbers can't intersect.
 * Solve: partial sum + trie.
 * Tips: see comments below.
 */
#include <iostream>
#include <vector>

using namespace std;

long long reverse(long long num) {
    long long ans = 0;
    // reverse 0...49 to 49..0, totally 50 bits.
    for (int i = 0; i < 50; ++i) {
        // first shift ans left by one
        // if we shift ans in the end of the loop,
        // then we will shift one more at last.
        ans = (ans << 1) | (num & 0x1l);
        num >>= 1;
    }

    return ans;
}

class TrieNode {
public:
    TrieNode *nodes[2];
    TrieNode() {
        nodes[0] = nodes[1] = NULL;
    }
};

class TrieTree {
private:
    TrieNode *root;

public:
    TrieTree() {
        root = new TrieNode();
    }

    void freeSpace(TrieNode *root) {
        if (root == NULL) return;

        freeSpace(root->nodes[0]);
        freeSpace(root->nodes[1]);

        delete root;
    }

    ~TrieTree() {
        freeSpace(root);
    }

    void addNum(long long n) {
        TrieNode *it = root;

        long long num = reverse(n);
        for (int i = 0; i < 50; ++i) {
            int bit = 0x1 & num;
            if (it->nodes[bit] == NULL) {
                it->nodes[bit] = new TrieNode();
            }
            it = it->nodes[bit];

            num >>= 1;
        }
    }

    long long findNum(long long n) {
        TrieNode *it = root;
        long long ans = 0;

        long long num = reverse(n);
        for (int i = 0; i < 50; ++i) {
            int bit = 0x1 & num;
            if (it->nodes[bit]) {
                it = it->nodes[bit];
                ans = ans << 1 | bit;
            } else {
                it = it->nodes[1-bit];
                ans = ans << 1 | 1 - bit;
            }

            num >>= 1;
        }

        return ans;
    }
};

long long solve(vector<long long> &nums) {
    long long left = 0, right = 0;

    int n = nums.size();
    for (int i = 0; i < n; ++i) left ^= nums[i];

    TrieTree q;
    q.addNum(0);

    long long ans = 0;
    for (int i = n-1; i >= 0; --i) {
        ans = max(ans, left ^ q.findNum(~left));

        left ^= nums[i];
        right ^= nums[i];

        q.addNum(right);
    }

    // xorLeft[0..0] xorRight[0..n-1]
    // don't drop the last one
    ans = max(ans, left ^ q.findNum(~left));

    return ans;
}

int main()
{
    int n;
    while (cin >> n) {
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        cout << solve(nums) << endl;
    }
    //long long nums[] = {1, 2, 3, 4};

    //vector<long long> in(nums, nums+4);

    //cout << solve(in) << endl;

    return 0;
}
