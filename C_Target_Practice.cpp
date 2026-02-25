#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        char a[10][10];
        ll count=0;
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                cin>>a[i][j];
                if(a[i][j]=='X'){
                    if(i==0||j==0||i==9||j==9){
                        count++;
                        continue;
                    }
                    if(i==1||j==1||i==8||j==8){
                        count+=2;
                        continue;
                    }
                    if(i==2||j==2||i==7||j==7){
                        count+=3;
                        continue;
                    }
                    if(i==3||j==3||i==6||j==6){
                        count+=4;
                        continue;
                    }
                    if(i==4||j==4||i==5||j==5){
                        count+=5;
                        continue;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}