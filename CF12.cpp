#include<iostream>
using namespace std;

class Solution {
    public:
        int Domino(int m,int n)
        {
            return (m*n)/2;
        }
};

int main () {
    Solution s;
    int m,n;
    cin>>m>>n;
    cout<<s.Domino(m,n);
    return 0;
}