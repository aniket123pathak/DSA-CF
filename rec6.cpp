#include <iostream>
using namespace std;

class Solution {
    public:
    int add (int n,int sum)
    {
       if(n<1)
       {
            return sum;
       }
       add(n-1,sum+n);
    }
        
};

int main()
{
    Solution s;
    int k = s.add(5,0);
    cout<<k;
    return 0;
}