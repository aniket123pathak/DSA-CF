#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,x,y,i;
            cin>>n>>x>>y;
            string a;
            cin>>a;
            long long count8=0,count4=0;
            for(i=0;i<n;i++){
                if(a[i]=='8'){
                    count8++;
                }
            }
            count4=n-count8;
            x=abs(x);
            y=abs(y);

            long long c = 2*count8 + count4;
            if(x+y<=c && x<=n && y<=n){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
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