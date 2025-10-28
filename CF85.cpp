#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i,countOdd=0;
            cin>>n;
            vector<long long>a(n);
            for(i=0;i<n;i++){
                cin>>a[i];
                if(a[i]%2!=0){
                    countOdd++;
                }
            }
            if(countOdd>0){
                cout<<"2\n";
                return;
            }

            for(i=0;i<n;i++){
                if(a[i]%3!=0){
                    cout<<"3\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%5!=0){
                    cout<<"5\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%7!=0){
                    cout<<"7\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%11!=0){
                    cout<<"11\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%13!=0){
                    cout<<"13\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%17!=0){
                    cout<<"17\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%19!=0){
                    cout<<"19\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%23!=0){
                    cout<<"23\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%29!=0){
                    cout<<"29\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%31!=0){
                    cout<<"31\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%37!=0){
                    cout<<"37\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%41!=0){
                    cout<<"41\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%43!=0){
                    cout<<"43\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%47!=0){
                    cout<<"47\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%53!=0){
                    cout<<"53\n";
                    return;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]%59!=0){
                    cout<<"59\n";
                    return;
                }
            }
            cout<<"-1\n";


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