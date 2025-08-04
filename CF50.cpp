#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,k,i;
            cin>>n>>k;
            vector<int> d(n);
            for(i=0;i<n;i++)
            {
                cin>>d[i];
            }
            long long x=k,trek=0;

            for(i=0;i<n;i++)
            {
                if(d[i]==0)
                {
                    k--;
                    if(k==0)
                    {
                        trek++;
                        i++;
                        k=x;
                    }
                }
                else{
                    k=x;
                }
            }
            cout<<trek<<"\n";

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