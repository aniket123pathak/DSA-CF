#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,count=0,count2=0,count3=0;
            cin>>n;
            while(n!=1){
                if(n%2==0){
                    n/=2;
                    count2++;
                }
                else if(n%3==0){
                    n/=3;
                    count3++;
                }
                else{
                    cout<<"-1\n";
                    return;
                }
            }
            if(count2>count3){
                cout<<"-1\n";
                return;
            }
            if(count2==count3){
                count=count2;
            }
            if(count2<count3){
                count=2*count3-count2;
            }


            cout<<count<<endl;
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