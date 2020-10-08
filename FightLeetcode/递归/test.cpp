#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*˼·
* 1
*
*/
int main() {
    unordered_map<string, string> map;
    map.insert("hah", "heihei");
    cout<<map["hah"]<<endl;

    return 0;
}