#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,count1=0;
            cin>>n;
            vector<long long>a(n),b(n);
            for(i=0;i<n;i++){
                cin>>a[i];
                if(a[i]==1){
                    count1++;
                }
                
            }
            for(i=0;i<n;i++){
                cin>>b[i];
                if(b[i]==1){
                    count1++;
                }
            }
            if(count1%2==0){
                cout<<"Tie\n";
                return;
            }
            long long ajisai=0;
            long long mai=0;
            for(i=n-1;i>=0;i--){
                if(i%2==0){
                    if(a[i]!=b[i]){
                        cout<<"Ajisai\n";
                        return;
                    }
                }
                else{
                    if(a[i]!=b[i]){
                        cout<<"Mai\n";;
                        return;
                    }
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