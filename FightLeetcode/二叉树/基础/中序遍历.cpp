#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //递归性能
    vector<int> vec;
    void fun(TreeNode * node) {
        if (node == NULL) return;
        fun(node->left);
        vec.push_back(node->val);
        fun(node->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        if (root == NULL)  return res;

        while (root != NULL || sta.size()) {
            while (root != NULL) {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            res.push_back(root->val);
            root = root->right;

        }
            return  res;
    }
    //解法2 使用迭代 直接
    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        TreeNode* node = root;
        if (root == NULL)  return res;

        while (node != NULL || sta.size()) {
            while (node != NULL) {
                sta.push(node);
                node=node->left;
            }
            node = sta.top();
            sta.pop();
            res.push_back(node->val);
            node =node ->right;
        }
        return  res;
    }
    //解法3 使用 空指针标记
    //使用迭代的办法，使用nullpoint作为空标记
    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        if (root == NULL)  return res;
        sta.push(root);
        while (sta.size()) {
            TreeNode* node = sta.top();
            if (node != NULL) {
                sta.pop();
             
                if (node->right != NULL) sta.push(node->right);
                sta.push(node);
                sta.push(NULL);
                if (node->left != NULL) sta.push(node->left);
            }
            else {

                sta.pop();
                node = sta.top();
                sta.pop();
                res.push_back(node->val);
            }
        }
        return res;

    }
};