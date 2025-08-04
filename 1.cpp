#include <iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#define setbit(x) __builtin_popcountll(x)
#define ll long long int
#define msb_pos(x) (63 - __builtin_clzll(x))

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
ll n;
cin>>n;
vector<ll>v(n);
for(int i=0;i<n;i++)
cin>>v[i];
bool check=true;
ll ans=0;
for(int i=0;i<n;i++)
{
    if(abs(v[i]-v[i+1])<=1)
        {check=false;
         break;}

}

if(check && n>=2)
{
for(int i=0;i<n;i++)
{ if(v[i]<=v[i+1] && v[i]>=v[i+2])
      {ans=1;
       break;}
  else if(v[i]>=v[i+1] && v[i]<=v[i+2])
      {ans=1;
       break;}
  else
  {
    ans=-1;
  }
}}
if(n==2 && !check)
    ans=-1;


cout<<ans<<endl;








} }