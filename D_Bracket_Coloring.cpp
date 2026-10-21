#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        ll op=0;
        ll cl=0;
        for(i=0;i<n;i++){
            if(s[i]=='('){
                op++;
            }
            else{
                cl++;
            }
        }
        if(op!=cl){
            cout<<-1<<endl;
            return;
        }
        stack<char>st1;
        stack<char>st2;
        for(i=0;i<n;i++){
            if(!st1.empty()){
                if(s[i]==')'&&st1.top()=='('){
                    st1.pop();
                }
                else{
                    st1.push(s[i]);
                }
            }
            else{
                st1.push(s[i]);
            }
        }
        if(st1.empty()){
            cout<<1<<endl;
            for(i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
            return;
        }
        string temp = s;
        reverse(temp.begin(),temp.end());
        for(i=0;i<n;i++){
            if(!st2.empty()){
                if(temp[i]==')'&&st2.top()=='('){
                    st2.pop();
                }
                else{
                    st2.push(temp[i]);
                }
            }
            else{
                st2.push(temp[i]);
            }
        }
        if(st2.empty()){
            cout<<1<<endl;
            for(i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
            return;
        }
        ll k = 0;
        vector<ll>ans(n,0);
        ll left = 0;
        ll right = n-1;
        op =0;
        cl = 0;
        ll cnt = 0;
        while(left<right){
            bool check = false;
            if(s[left]=='('){
                while(left<right){
                    if(s[right]==')'){
                        check = true;
                        ans[left]=1;
                        ans[right]=1;
                        cnt+=2;
                        left++;
                        right--;
                        break;
                    }
                    else{
                        right--;
                    }
                }
                if(!check){
                    break;
                }
            }
            else{
                left++;
            }
        }
        bool check2 = false;
        if(cnt==n || cnt==0){
            check2 = true;
        }
        left = 0;
        right = n-1;
        while(left<right){
            bool check = false;
            if(s[left]==')' && ans[left]==0){
                while(left<right){
                    if(s[right]=='('&&ans[right]==0){
                        check = true;
                        ans[left]=2;
                        ans[right]=2;        
                        cnt+=2;
                        left++;
                        right--;
                        break;
                    }
                    else{
                        right--;
                    }
                }
                if(!check){
                    break;
                }
            }
            else{
                left++;
            }
        }

        if(check2){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }

        for(i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        return;
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