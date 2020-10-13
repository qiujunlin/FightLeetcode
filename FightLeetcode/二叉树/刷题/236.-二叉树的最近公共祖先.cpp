#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 /*
 * �ݹ������
��ֹ������
��Խ��Ҷ�ڵ㣬��ֱ�ӷ��� nullnull ��
�� rootroot ���� p, qp,q ����ֱ�ӷ��� rootroot ��
���ƹ�����

�����ݹ����ӽڵ㣬����ֵ��Ϊ leftleft ��
�����ݹ����ӽڵ㣬����ֵ��Ϊ rightright ��
����ֵ�� ���� leftleft �� rightright ����չ��Ϊ���������
�� leftleft �� rightright ͬʱΪ�� ��˵�� rootroot ���� / �������ж������� p,qp,q ������ nullnull ��
�� leftleft �� rightright ͬʱ��Ϊ�� ��˵�� p, qp,q ������ rootroot �� ��� ���ֱ��� �� / ������������� rootroot Ϊ����������ȣ����� rootroot ��
�� leftleft Ϊ�� ��rightright ��Ϊ�� ��p,qp,q ������ rootroot ���������У�ֱ�ӷ��� rightright ������ɷ�Ϊ���������
p,qp,q ����һ���� rootroot �� ������ �У���ʱ rightright ָ�� pp������Ϊ pp ����
p,qp,q ���ڵ㶼�� rootroot �� ������ �У���ʱ�� rightright ָ�� ����������Ƚڵ� ��
�� leftleft ��Ϊ�� �� rightright Ϊ�� ������� 3. ͬ��

���ߣ�jyd
���ӣ�https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};