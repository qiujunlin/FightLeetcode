#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*˼·
* ʹ�����������˼��ܼ�
* 
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)return root;
        queue<Node*> que;
        que.push(root);
        while (que.size()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                if (i < size - 1) {
    /*���ﷸ��һ�������˺þòŷ�����������ˣ������size֮ǰʹ�õ���que.size()-1��û�з����ڴ���֮ǰ��
    * ��ʹ����pop�������еĴ�С�Ѿ��ı��ˣ�����һֱ���֡�member access within misaligned address 0xbebebebebebebebe ��
    * Ҳ����ʹ��û�н��г�ʼ���Ľڵ�
    */
                    node->next = que.front();
                }
                else {
                    node->next = NULL;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return root;
    }
};