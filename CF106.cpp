#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,j;
            cin >> n; 
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
                    if((a[j]%a[i])%2==0){
                        cout<<a[i]<<" "<<a[j]<<endl;
                        return;
                    }
                }
            }
            cout<<"-1\n";
        }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}