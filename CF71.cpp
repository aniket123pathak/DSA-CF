#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,x=0,y,z=9;
            cin>>n;
            vector<long long>v;
            if(n%10==0){
                cout<<"0\n";
            }

            int cd,ld,rem;

            y=11;
            while(y<n){
                if(n/y==0&&(n/y)%10!=0){
                    v.insert(v.begin(),n/y);
                    y=y+z*10;
                }
            }
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
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

