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
/*思路
* 使用中序遍历的思想很简单
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
    /*这里犯了一个错，找了好久才发现是哪里错了，这里的size之前使用的是que.size()-1，没有发现在代码之前，
    * 我使用了pop（）队列的大小已经改变了，导致一直出现“member access within misaligned address 0xbebebebebebebebe ”
    * 也就是使用没有进行初始化的节点
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