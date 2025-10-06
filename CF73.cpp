#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i;
            cin>>n;
            string a;
            cin>>a;
            long long single=0,couple=0,triple = 0,count=0;
            for(i=0;i<n;i++){
                if(a[i]=='.'){
                    count++;
                }
                else{
                    if(count==1){
                        single++;
                    }
                    else if(count==2){
                        couple++;
                    }
                    else if(count>2){
                        triple++;
                    }
                    else{

                    }
                    count=0;
                }

                if(i==n-1){
                    if(count==1){
                        single++;
                    }
                    else if(count==2){
                        couple++;
                    }
                    else if(count>2){
                        triple++;
                    }
                    else{

                    }
                    count=0;
                }
                
            }

            if(triple>0){
                cout<<"2\n";
                return;
            }
            else{
                cout<<single+2*couple<<"\n";
            }
            
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