#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    long long powOf3(int x){
        long long p3 = 1;
        while(x>0){
            p3=p3*3;
            x--;
        }
        return p3;
    }

    void solve()
    {
        long long n;
        cin >> n;
        long long cost = 0;
        long long x = 0;
        long long rem = 0;
        while (n > 0) {
            rem = n % 3;
            if (rem > 0) {
                cost =cost +  rem * (powOf3(x + 1) + x * powOf3(x - 1));
            }
            n =n / 3;
            x++;
        }
        cout << cost << "\n";
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