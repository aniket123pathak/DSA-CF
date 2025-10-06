#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long x,y;
            cin>>y>>x;

            if(y>x){
                if(y%2==0){
                    cout<<(y*y)-(x-1);
                }
                else {
                    cout<<(((y-1)*(y-1))+1)+(x-1);
                }
            }
            else{
                if(x%2==0){
                    cout<<(((x-1)*(x-1))+1)+(y-1);
                }
                else {
                    cout<<((x*x))-(y-1);
                }
            }
            cout<<endl;
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