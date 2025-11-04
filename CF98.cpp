#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long x,n;
            cin>>x>>n;

            if(x%2==0){
                if(n%4==0){
                    cout<<x<<endl;
                }
                else if(n%4==1){
                    cout<<x-n<<endl;
                }
                else if(n%4==2){
                    cout<<x+1<<endl;
                }
                else{
                    cout<<x+n+1<<endl;
                }
            }
            else{
                if(n%4==0){
                    cout<<x<<endl;
                }
                else if(n%4==1){
                    cout<<x+n<<endl;
                }
                else if(n%4==2){
                    cout<<x-1<<endl;
                }
                else{
                    cout<<x-(n+1)<<endl;
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