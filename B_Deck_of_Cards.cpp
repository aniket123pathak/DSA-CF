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
        ll n,k,i;
        cin>>n>>k;
        string a;
        cin>>a;

        vector<char>cards(n,'+');
        ll front = 0;
        ll back = n-1;

        for(i=0;i<k;i++){
            if(a[i]=='0'){
                if(cards[front]=='?'){
                    cards[front+1]='?';
                }
                cards[front]='-';
                front++;
            }

            if(a[i]=='1'){
                if(cards[back]=='?'){
                    cards[back-1]='?';
                }
                cards[back]='-';
                back++;
            }

            if(a[i]=='2'){
                if(cards[front]=='?'){
                    cards[front+1]='?';
                }
                cards[front]='?';
                front++;

                if(cards[back]=='?'){
                    cards[back-1]='?';
                }
                cards[back]='?';
                back++;
            }
        }

        for(i=0;i<n;i++){
            cout<<cards[i];
        }
        cout<<endl;


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