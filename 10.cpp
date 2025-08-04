#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
    public:
        void solve()
        {
            long long n,k,i,level=1;
            cin>>n>>k;
            vector<int> h(n);
            for(i=0;i<n;i++)
            {
                cin>>h[i];
            }
            k=k-1;
            if(n==1)
            {
                cout<<"Yes\n";
                return;
            }
            long long currentBH=h[k]+1;
            sort(h.begin(),h.end());
 
            for(i=0;i<n;i++)
            {
                if(h[i]==currentBH-1)
                {
                    k=i;
                    break;
                }
            }
            for(i=k;i+1<n;i++)
            {
                if(level+(h[i+1]-h[i])<=currentBH)
                {
                    currentBH=h[i+1]+1;
                    level+=h[i+1]-h[i];
                }
                else{
                    cout<<"No\n";
                    return;
                }
            }
            cout<<"Yes\n";
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