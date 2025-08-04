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
        cout<<i<<"  ";
        print(i+1,n);
    }
        
};

int main()
{
    Solution s;
    s.print(1,5);
    return 0;
}