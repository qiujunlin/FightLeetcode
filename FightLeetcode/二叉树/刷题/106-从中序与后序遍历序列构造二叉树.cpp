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
/*˼·
* 1.��ԭ����  ���Ӻ����postorder��������ÿһ���ڵ㶼Ϊ���ڵ㣬��������ָ��ֱ�ָ��inorder������ұ�
*  2.��������  l>r,��l=rʱ�򣬵�ǰΪҶ�ӽڵ�
* 3.����ǰ����������Ľڵ���Ϊ���ڵ㣬����ָ�룬����������м��������ߵݹ�
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