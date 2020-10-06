#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*思路: 
1.使用广度优先搜索
* -使用两个数组，第一个存储节点，第二个存储当层节点分别累加的和
  -遍历到 某一层的时候，取出第一个节点，取出该节点对应累加的值
  -遍历该节点的左节点，当左节点不为空的时候，将左节点入队，将左节点和刚才取出的对应累加的值相加，判断是否相等，并判断是否是叶子节点
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        queue<TreeNode*> que;//存储节点
        queue<int>  val;//存储对应的值
        que.push(root);
        val.push(root->val);
        while (que.size()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                int curval = val.front();
                que.pop();
                val.pop();
                TreeNode* nodeleft = node->left;
                TreeNode* noderight = node->right;

                if (nodeleft) {
                    que.push(nodeleft);
                    int leftval = nodeleft->val;
                    if (nodeleft->left==NULL && nodeleft->right==NULL && (curval + leftval == sum))
                        return true;
                    val.push(curval + leftval);
                }
                if (noderight) {
                    que.push(noderight);
                    int rightval = noderight->val;
                    if (noderight->left==NULL && noderight->right==NULL && (curval + rightval == sum))
                        return true;
                    val.push(curval + rightval);
                }

            }


        }
        return false;
    }
    /*递归的方法
    * 递归结束条件  1.节点为空 2.到节点的值为正确值 3.继续向两边递归
    */
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL&&root->val==sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};