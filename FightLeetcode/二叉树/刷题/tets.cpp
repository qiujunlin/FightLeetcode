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
int main() {
    queue<TreeNode* > que;
    que.push(NULL);
    return 0;
}