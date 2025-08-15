#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,x,i,j;
            string v;
            cin>>n>>x>>v;

            if(x==1||x==n){
                cout<<"1\n";
                return;
            }
            long long firstLeftWall=0;
            for(i=x-2;i>=0;i--){
                if(v[i]=='#'){
                    firstLeftWall=i+1;
                    break;
                }
            }
            long long firstRightWall=0;
            for(i=x;i<=n;i++){
                if(v[i]=='#'){
                    firstRightWall = i+1;
                    break;
                }
            }
            if(firstLeftWall-1==0&&firstRightWall-1==0){
                cout<<"1\n";
                return;
            }

            long long countRight = min(x,n-firstRightWall);
            long long countLeft = min(n-x-1 ,firstLeftWall+1);

            long long maxS = max(countLeft,countRight);
            
            cout<<maxS<<"\n";


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