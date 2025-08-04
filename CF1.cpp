#include<iostream>
using namespace std;

class Solution {
    public:
        int Bacteria(int k,int b ,int n,int t)
        {
            long long z = 1;
            while (k * z + b <= t) {
                z = k * z + b;
                n--;
            }       
            return (n > 0 ? n : 0);
        }
};

int main () {
    Solution s;
    int k,b,n,t;
    cin>>k>>b>>n>>t;
    int bc = s.Bacteria(k,b,n,t);
    cout<<bc;
    return 0;
}