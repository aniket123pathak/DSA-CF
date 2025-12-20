#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i;
            cin>>n;
            vector<string>a(n);
            string k = "";
            string x ="";
            string y="";
            for(i=0;i<n;i++){
                cin>>a[i];

                if(i==0){
                    k+=a[i];
                }
                else{
                    x=k+a[i];
                    y=a[i]+k;

                    if(x>y){
                        k=y;
                    }
                    else{
                        k=x;
                    }
                    x="";
                    y="";
                }
            }
            
            cout<<k<<endl;

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