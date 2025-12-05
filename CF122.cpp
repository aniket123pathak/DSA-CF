#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
    public:
        void solve()
        {
            long long n,k,i,sleep=0,awake=-1;
            cin>>n>>k;
            string a;
            cin>>a;
            for(i=0;i<n;i++){
                if(a[i]=='1'){
                    awake=i+k;
                }
                else if(i>awake){
                    sleep++;
                }
            }
            cout<<sleep<<endl;
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