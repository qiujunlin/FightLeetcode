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
/*˼·: 
1.ʹ�ù����������
* -ʹ���������飬��һ���洢�ڵ㣬�ڶ����洢����ڵ�ֱ��ۼӵĺ�
  -������ ĳһ���ʱ��ȡ����һ���ڵ㣬ȡ���ýڵ��Ӧ�ۼӵ�ֵ
  -�����ýڵ����ڵ㣬����ڵ㲻Ϊ�յ�ʱ�򣬽���ڵ���ӣ�����ڵ�͸ղ�ȡ���Ķ�Ӧ�ۼӵ�ֵ��ӣ��ж��Ƿ���ȣ����ж��Ƿ���Ҷ�ӽڵ�
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        queue<TreeNode*> que;//�洢�ڵ�
        queue<int>  val;//�洢��Ӧ��ֵ
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
    /*�ݹ�ķ���
    * �ݹ��������  1.�ڵ�Ϊ�� 2.���ڵ��ֵΪ��ȷֵ 3.���������ߵݹ�
    */
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL&&root->val==sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};