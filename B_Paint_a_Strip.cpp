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
            vector<long long>count;

            long long sum = 1 ;
            count.push_back(1);
            i=0;
            while(sum<=100000){
                sum+=3*powOf2(i);
                count.push_back(sum);
                i++;
            }

            for(i=0;i<count.size();i++){
                if(n<=count[i]){
                    cout<<i+1<<endl;
                    return;
                }
            }
        }

        int powOf2(int n){
            long long pow=1;
            while(n--){
                pow*=2;
            }
            return pow;
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