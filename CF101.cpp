#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
    public:
        void solve()
        {
            string a,b;
            cin>>a>>b;
            long long n1 = a.length(),n2=b.length();
            if(n2>n1){
                cout<<"NO\n";
                return;
            }
            long long i=0,j=0;
            long long last = n2-1;
            map<char,long long>mp;
            vector<long long>index;
            bool flag = false;
            for(i=n1-1;i>=0;i--){
                if(a[i]==b[last]){
                    index.push_back(i);
                    mp[b[last]]=i;
                    last--;
                }
                if(last==-1){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                cout<<"NO\n";
                return;
            }

            long long last1 = mp.rbegin()->second;
            long long first1 = mp.begin()->second;

            for(auto ele : mp){
                for(i=ele.second+1;i<n1;i++){
                    for(j=0;j<n2;j++){
                        if(i==index[j]){
                            flag=true;
                            break;
                        }
                    }
                    if(flag==true){
                        flag=false;
                        continue;
                    }
                    if(a[i]==ele.first){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
            cout<<"YES\n";
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
