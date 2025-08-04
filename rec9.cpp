#include <iostream>
using namespace std;

class Solution {
    public:
    int rec (int n)
    {
        if(n==0) return 1;
        return n*rec(n-1);
    }
        
};

int main()
{
    Solution s;
    int k = s.rec(0);
    cout<<k;
    return 0;
}