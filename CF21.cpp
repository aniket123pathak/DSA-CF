#include<iostream>
using namespace std;

class Solution {
    public:
        int pot()
        {
            int n,s;
            cin>>n>>s;
            int dx,dy,xi,yi;
            int count=0;
            
            for(int i =0 ;i<n;i++)
            {
                cin>>dx>>dy>>xi>>yi;
                if(xi==yi&&dx==dy)
                {
                    count++;
                }
                if(xi+yi==s&&dx!=dy)
                {
                    count++;
                }
            }
            return count;
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc>0)
    {
        cout<<s.pot();
        cout<<endl;
        tc--;
    }   
    return 0;
}