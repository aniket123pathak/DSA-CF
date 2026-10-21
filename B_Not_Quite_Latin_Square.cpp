#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        ll cntA=0,cntB=0,cntC=0;
        for(i=0;i<3;i++){
            if(s1[i]=='A'){
                cntA++;
            }
            else if(s1[i]=='B'){
                cntB++;
            }
            else if(s1[i]=='C'){
                cntC++;
            }
        }
        for(i=0;i<3;i++){
            if(s2[i]=='A'){
                cntA++;
            }
            else if(s2[i]=='B'){
                cntB++;
            }
            else if(s2[i]=='C'){
                cntC++;
            }
        }
        for(i=0;i<3;i++){
            if(s3[i]=='A'){
                cntA++;
            }
            else if(s3[i]=='B'){
                cntB++;
            }
            else if(s3[i]=='C'){
                cntC++;
            }
        }

        if(cntA!=3){
            cout<<'A'<<endl;
        }
        else if(cntB!=3){
            cout<<"B"<<endl;
        }
        else{
            cout<<"C"<<endl;
        }
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}