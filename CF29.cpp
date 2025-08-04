#include<iostream>
using namespace std;

class Solution {
    public:
        void race()
        {
            int a,x,y;
            cin>>a>>x>>y;


            for(int b=1;b<101;b++)
            {
                if(a==b)
                {
                    continue;
                }
                if(abs(b-x)<abs(a-x)&&abs(b-y)<abs(a-y))
                {
                    cout<<"YES\n";
                    return;
                }
            }
            cout<<"NO\n";

            
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc>0)
    {
        s.race();
        tc--;
    }
    return 0;
}