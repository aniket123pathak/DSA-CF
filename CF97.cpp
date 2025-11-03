#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            string a;
            cin>>a;
            long long n = a.length();
            long long i,countAB=0,countBA=0;
            long long countA=0,countB=0;
            for(i=0;i<n;i++){
                if(a[i]=='a'){
                    countA++;
                }
                else{
                    countB++;
                }
            }
            for(i=1;i<n;i++){
                if(a[i-1]=='a'&&a[i]=='b'){
                    countAB++;
                }
                if(a[i-1]=='b'&&a[i]=='a'){
                    countBA++;
                }
            }
            if(countAB==countBA){
                cout<<a<<endl;
                return;
            }
            if(a[0]!=a[n-1]){
                a[0]=a[n-1];
            }

            cout<<a<<endl;

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