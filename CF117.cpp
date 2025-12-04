#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n,x;
            cin>>n;
            vector<int>freq(101);
            for(int i = 0 ;i<n;i++){
                cin>>x;
                freq[x]++;
            }
            int rem = 0;

            for(int i = 0;i<101;i++){
                if(i>freq[i]){
                    rem+=freq[i];
                }
                else if(i<freq[i]){
                    rem+=freq[i]-i;
                }
                else{
                    
                }
            }
            cout<<rem<<endl;
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