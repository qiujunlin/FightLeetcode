#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*思路
* 和后序和中序遍历的思路一样
* 
*
*
*/
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = preorder.size() - 1;
        for (int i = 0; i <= right; i++) map[inorder[i]] = i;
        int front = 0;
        return tree(left, right, inorder, preorder, front);

    }
    TreeNode* tree(int left, int right, vector<int>& inorder, vector<int>& preorder, int& front) {
        if (left > right) return NULL;
        if (left == right) {
            front++;
            return new TreeNode(inorder[left]);
        }
        TreeNode* node = new TreeNode(preorder[front]);
        front++;
        node->left = tree(left, map[node->val] - 1, inorder, preorder, front);
        node->right = tree(map[node->val] + 1, right, inorder, preorder, front);
        return node;
    }
};