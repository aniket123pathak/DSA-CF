#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    ll, 
    null_type, 
    greater<ll>, 
    rb_tree_tag, 
    tree_order_statistics_node_update> 
    ordered_set;

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        vector<pair<ll,ll>>a(n);
        for(i=0;i<n;i++){
           cin>>a[i].first;
           cin>>a[i].second;
        }
        sort(a.begin(),a.end());
        // we have to optimizeeeee thiss...how to optimizeee
        //a[i].first<a[j].first && a[j].second<a[i].second
        /*
        I will sort the pairs by their starting point ...now what wee want..how meeting will occur...
        The starting point of 'a' is behind point b and ending point of a is after ending point of b then meeting will occur......
        so i will start iterating through array...
        as i have sorted that in ascending each starting point of next point will be after cur starting point....
        so we just need to check for each point how many ending points off previous points are after me.....
        for that i willl use data structure as a tree....
        for each pount i will push ending point of each cur....and 
        for now from second pont onwards iu have to check the correct pos for my cur 
        ending point means means check how many elemnts in ds are greater than my current point....
        and i have to place my cur ending point on his correct pos in ds....as a ds i canot use vector deque 
        cause placing them in correct pos in middle will take o(n) so i have to use the tree...whhich tree??
        */
        ordered_set oSet;
        ll greeting =0;
        for(i=0;i<n;i++){
            ll start = a[i].first;
            ll end = a[i].second;
            greeting+=oSet.order_of_key(end);
            oSet.insert(end);
        }
        cout<<greeting<<endl;
        
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