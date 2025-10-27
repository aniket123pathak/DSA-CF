#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n , i;
            cin>>n;
            long long rem = n ;
            long long max = 0 ;
            while(rem>2){
                if(rem%3==0){
                    max+=rem/3;
                    rem=rem/3;
                }
                else{
                    max+=rem/3;
                    rem=rem-2*(rem/3);
                }
            }
            cout<<max<<endl;
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