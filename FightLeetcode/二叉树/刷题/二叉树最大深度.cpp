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
 
class Solution {

public:
    //递归
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int rightdepth = maxDepth(root->right);
        int leftdepth = maxDepth(root->left);
        return max(leftdepth, rightdepth)+1;
    }
    //广度优先搜索
    int maxDepth2(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while (que.size()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left)que.push(node->left);
                if (node->right)que.push(node->right);

            }
            depth += 1;
        }
        return depth;
        
    }
};