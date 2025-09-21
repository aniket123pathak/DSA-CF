#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            string a;
            cin>>a;
            long long max = 1,temp = 1,i;
            for(i=1;i<a.length();i++){
                if(a[i]==a[i-1]){
                    temp++;
                }
                else{
                    if(temp>max){
                        max=temp;
                    }
                    temp=1;
                }
            }
            if(temp>max){
                max = temp;
            }
            cout<<max<<endl;
        }
};

int main () {
    Solution s;
    s.solve();
    return 0;
}