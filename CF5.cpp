#include<iostream>
using namespace std;

class Solution {
    public:
        int square(int m,int n,int a)
        {
            long long tn = (n + a - 1) / a;
            long long tm = (m + a - 1) / a;
            return tn * tm;
        }
};

int main () {
    Solution s;
    int m,n,a;
    cout<<s.square(m,n,a);   
    return 0;
}