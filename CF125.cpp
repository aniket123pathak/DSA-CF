#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,x,diff=0;
            cin>>n;
            vector<long long>hash(1001);
            for(i=0;i<n;i++){
                cin>>x;
                if(hash[x]==0){
                    hash[x]++;
                    diff++;
                }
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