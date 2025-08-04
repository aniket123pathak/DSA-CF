#include <iostream>
using namespace std;

class Solution {
    public:
    void print (int i,int n)
    {
       if(i>n)
       {
            return ;
       }
       print(i+1,n);
       cout<<i<<" ";
    }
        
};

int main()
{
    Solution s;
    s.print(1,5);
    return 0;
}