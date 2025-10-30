#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long count0=0,count1=0;
            string a;
            cin>>a;
            for(int i = 0 ; i < a.length() ; i++){
                if(a[i]=='0'){
                    count0++;
                }
                else{
                    count1++;
                }
            }

            if(count0==a.length()||count1==a.length()){
                cout<<"NET\n";
                return;
            }

            if(min(count1,count0)%2==0){
                cout<<"NET\n";
            }
            else{
                cout<<"DA\n";
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