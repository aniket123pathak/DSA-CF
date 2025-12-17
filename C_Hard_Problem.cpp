#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long m,a,b,c;
            cin>>m>>a>>b>>c;

            long long remRow1 = 0 ;
            long long m1=0;
            if(m>=a){
                remRow1=m-a;
                m1=a;
            }
            else{
                m1=m;
            }
            long long remRow2 = 0 ;
            long long m2 = 0 ;
            if(m>=b){
                remRow2=m-b;
                m2=b;
            }
            else{
                m2=m;
            }

            long long totalRem = remRow1+remRow2;
            long long m3  = 0 ;

            if(totalRem>=c){
                m3=c;
            }
            else{
                m3=totalRem;
            }
            cout<<m1+m2+m3<<endl;
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