#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
    games are in pair so i think total no of games will be (n*(n-1))/2;

    easy problem optimization needed brute force wont work due to time constraints

    store input column wise
    sort column we have to add every abs(every paie)

    2 6 3 7
    2 3 6 7

    7-2
    7-3
    7-6

    6-2
    6-3

    3-2

    (3*7+2*6+1*3)-(3*2+2*3+1*6)


*/

class Solution {
public:
    void solve()
    {
        ll n,m,i,j,k;
        cin>>n>>m;
        vector<vector<ll>>a(n,vector<ll>(m));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        if(n==1){
            cout<<"0\n";
            return;
        }
        vector<vector<ll>>b(m,vector<ll>(n));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                b[i][j]=a[j][i];
            }
        }
        for(i=0;i<m;i++){
            sort(b[i].begin(),b[i].end());
        }
        ll finalCnt=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                finalCnt+=(b[i][n-1-j]-b[i][j])*(n-1-j);
            }
        }
        cout<<finalCnt<<endl;
    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}