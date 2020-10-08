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
* 1.还原过程  ，从后遍历postorder，遇见的每一个节点都为根节点，定义两个指针分别指向inorder的左边右边
*  2.结束条件  l>r,当l=r时候，当前为叶子节点
* 3.将当前后序遍历出的节点作为根节点，更新指针，在中序遍历中继续向两边递归
* 
* 
*/
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int left = 0;
        int right = inorder.size() - 1;
        int back = right;
        for (int i = left; i <= right; i++)  map[inorder[i]] = i;
        return tree(left, right, inorder, postorder, back);
    }
    TreeNode* tree(int left, int right, vector<int>& inorder, vector<int>& postorder, int& back) {
        if (left > right) return NULL;
        if (left == right) {
            back--;
            return new TreeNode(inorder[left]);
        }
        TreeNode* node = new TreeNode(postorder[back]);
        back--;
        node->right = tree(map[node->val] + 1, right, inorder, postorder, back);
        node->left = tree(left, map[node->val] - 1, inorder, postorder, back);
        return node;

    }
};