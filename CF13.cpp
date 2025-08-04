#include<iostream>
using namespace std;

class Solution {
    public:
        int Sum(int tc)
        {
            int x=0;
            string a;
            while(tc>0)
            {
                cin>>a;
                if(a[1]=='+')
                {
                    x++;
                }
                else{
                    x--;
                }
                tc--;
            }
            return x;
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    cout<<s.Sum(tc);
    return 0;
}