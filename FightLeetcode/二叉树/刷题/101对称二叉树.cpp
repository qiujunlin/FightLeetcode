#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//使用递归的方法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        else  return compare(root->left, root->right);
    }
    bool compare(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;
        if (a->val != b->val) return false;
        return compare(a->left, b->right) && compare(a->right, b->left);
    }
};