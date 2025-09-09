#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;

            if(a==b&&c==d){
                cout<<"YES\n";
                return;
            }

            if (a!=b)
            {
                if (a>b)
                {
                    while(a>0&&b>1){
                        a=a-2;
                        b=b-1;
                    }
                    if(a>2||b>2){
                        cout<<"NO\n";
                        return;
                    }
                }
                else
                {
                   while(a>1&&b>0){
                        a=a-1;
                        b=b-2;
                    }
                    if(a>2||b>2){
                        cout<<"NO\n";
                        return;
                    }
                }
                
            }

            if (c!=d)
            {
                if (c>d)
                {
                    while(c>0&&d>1){
                        c=c-2;
                        d=d-1;
                    }
                    if(c>2||d>2){
                        cout<<"NO\n";
                        return;
                    }
                }
                else
                {
                   while(c>1&&d>0){
                        c=c-1;
                        d=d-2;
                    }
                    if(c>2||d>2){
                        cout<<"NO\n";
                        return;
                    }
                }
                
            }

            cout<<"YES\n";
            
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}