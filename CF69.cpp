#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long  n,m,i;
            string a,b,c;
            cin>>n>>a;
            cin>>m>>b;

            cin>>c;
            vector<char>v;
            vector<char>w;

            for(i=0;i<n;i++){
                v.push_back(a[i]);
            }

            for(i=0;i<b.length()&&i<c.length();i++){
                if(c[i]=='D'){
                    v.push_back(b[i]);
                }
                else{
                    v.insert(v.begin(),b[i]);
                }
            }

            for(i=0;i<v.size();i++){
                cout<<v[i];
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