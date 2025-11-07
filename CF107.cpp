#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n;
            cin>>n;
            if(n%2!=0 || n<4){
                cout<<"-1\n";
                return;
            }

            if(n%4==0&&n%6==0){
                cout<<n/6<<" "<<n/4<<endl;
                return;
            }
            if(n%4==0&&n%6!=0){
                if(n%6==4){
                    cout<<((n-4)/6)+1<<" "<<n/4<<endl;
                    return;
                }
                if(n%6==2){
                    cout<<((n-8)/6)+2<<" "<<n/4<<endl;
                    return;
                }
            }
            if(n%4!=0&&n%6==0){
                cout<<n/6<<" "<<((n-6)/4)+1<<endl;
                return;
            }
            if(n%4!=0&&n%6!=0){
                if(n%6==4){
                    cout<<((n-4)/6)+1<<" "<<((n-6)/4)+1<<endl;
                    return;
                }
                if(n%6==2){
                    cout<<((n-8)/6)+2<<" "<<((n-6)/4)+1<<endl;
                    return;
                }
            }

            cout<<"-1\n";
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

/*

if(a[i]>=b[j]){
                    count++;
                    j++;
                    if(c[k]!=0){
                        a[i]=max(c[k],a[i]);
                    }
                    else{
                        i++;
                        k++;
                    }
                }
                else{
                    i++;
                }*/