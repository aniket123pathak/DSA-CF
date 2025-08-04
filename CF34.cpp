#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void Tournament()
        {
            long long n,j,k;
            cin>>n>>j>>k;
            vector<long long> v(n);
            for(int i = 0 ;i<n;i++)
            {
                cin>>v[i];
            }
            long long max = *max_element(v.begin(),v.end());
            if(v[j-1]==max)
            {
                cout<<"Yes\n";
                return ;
            }
            else{
                if(k!=1)
                {
                    cout<<"Yes\n";
                    return;
                }
            }
            cout<<"no\n";
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.Tournament();
    }   
    return 0;
}