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
       print(i,n-1);
       cout<<n<<" ";
    }
        
};

int main()
{
    Solution s;
    s.print(1,5);
    return 0;
}