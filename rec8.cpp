#include <iostream>
using namespace std;

class Solution {
    public:
    int add (int n)
    {
        if(n==0)return 0;

        return n+add(n-1);
    }
        
};

int main()
{
    Solution s;
    int k = s.add(5);
    cout<<k;
    return 0;
}