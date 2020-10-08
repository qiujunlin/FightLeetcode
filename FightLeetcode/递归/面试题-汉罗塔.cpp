#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }
    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        //�ݹ��������
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        else {
            move(n - 1, A, C, B);
            C.push_back(A.back());
            A.pop_back();
            move(n - 1, B, A, C);
        }
    }

};