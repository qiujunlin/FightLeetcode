#include <iostream>
#include <vector>
#include <stack>

#include<algorithm>
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
    //ʹ��ǰ������ķ������������ȷ������������ٷ���������������ٽ��������з�ת
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        if (root == NULL)  return res;
        sta.push(root);
        while (sta.size()) {
            TreeNode* treenode = sta.top();
            res.push_back(treenode->val);
            sta.pop();
            if (treenode->left) {
                sta.push(treenode->left);
            }
            if (treenode->right) {
                sta.push(treenode->right);
            }
        }
        reverse(res.begin(), res.end());
        return  res;    
    }
    //ʹ�õ����İ취��ʹ��nullpoint��Ϊ�ձ��
    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        if (root == NULL)  return res;
        sta.push(root);
        while (sta.size()) {
            TreeNode* node = sta.top();
            if (node != NULL) {
                sta.pop();
                sta.push(node);
                sta.push(NULL);
                if (node->right != NULL) sta.push(node->right);
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