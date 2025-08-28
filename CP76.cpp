#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,k;
            cin>>n>>k;

            vector<long long>v(n),hash(101);

            for(int i = 0;i<n;i++){
                cin>>v[i];
                hash[v[i]]++;
            }

            if(hash[k]>0){
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