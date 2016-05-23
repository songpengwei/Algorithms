#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// much more like recursive version
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    stack<TreeNode*> s;
    if (root) s.push(root);
    while (!s.empty()) {
        TreeNode* now = s.top();
        s.pop();

        ans.push_back(now->val);
        if (now->right) s.push(now->right);
        if (now->left) s.push(now->left);
    }
    return ans;
}

vector<int> preorderTraversal1(TreeNode* root) {
    vector<int> ans;

    stack<TreeNode*> s;
    TreeNode* it = root;
    while (!s.empty() || it) {
        while (it) {
            s.push(it);
            ans.push_back(it->val);
            it = it->left;
        }

        TreeNode* now = s.top();
        s.pop();
        it = now->right;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);

    root->right = node1;
    node1->left = node2;

    preorderTraversal1(root);


    return 0;
}
