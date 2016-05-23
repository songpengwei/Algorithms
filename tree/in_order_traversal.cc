#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// this structure can also be used as previous order traversal.
vector<int> non_recur(vector<int> &ans, TreeNode* root) {
    stack<TreeNode *> nodes;

    TreeNode* node = root;

    while (node || !nodes.empty()) {
        while (node) {
            nodes.push(node);
            node = node->left;
        }

        node = nodes.top();
        nodes.pop();
        ans.push_back(node->val);

        node = node->right;
    }

    return ans;
}

int main()
{

}
