#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n;
            cin>>n;
            cout<<n;
            while(n!=1){
                if(n%2==1){
                    n=(n*3)+1;
                }
                else{
                    n=n/2;
                }
                cout<<" "<<n;
            }
            cout<<endl;
        }
};

int main () {
    Solution s;
    s.solve();
    return 0;
}