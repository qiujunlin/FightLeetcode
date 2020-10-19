#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > sta;
        vector<int> res;
        if (root == NULL)  return res;
        sta.push(root);
        while (sta.size()) {
            TreeNode* treenode = sta.top();
            res.push_back(treenode->val);
            sta.pop();
            if (treenode->right) {
                sta.push(treenode->right);
            }
            if (treenode->left) {
                sta.push(treenode->left);                 
            }
        }

        return  res;
    }
    //ʹ�õ����ķ���
     //ʹ�õ����İ취��ʹ��nullpoint��Ϊ�ձ��nullpoint��Ϊ�ձ��
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
                if (node->left != NULL) sta.push(node->left);
                sta.push(node);
                sta.push(NULL);
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