#include <iostream>
#include <vector>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root == NULL) return res;  
        que.push(root);
        while (que.size()) {
            int num = que.size();
            vector<int> vec;
            for (int i = 0;i < num;i++) {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                if (node->left)que.push(node->left);
                if (node->right) que.push(node->right);
                que.pop();
            }
            res.push_back(vec);
        }
        return res;
    }
};