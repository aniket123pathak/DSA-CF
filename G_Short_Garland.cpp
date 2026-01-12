#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long
const int MOD = 998244353;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll fact[300005];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}

struct State {
    map<int, ll> m; 
    ll offset = 0;  
    ll mul = 1;     
    ll cnt_long = 0;
    ll safe_sum = 0;
};

int n, k;
vector<vector<int>> adj;

State dfs(int u) {
    if (adj[u].empty()) {
        State s;
        s.m[0] = 1;
        s.safe_sum = 1;
        return s;
    }

    vector<State> children_states;
    children_states.reserve(adj[u].size());
    
    int bad_children = 0; 
    ll prod_safe = 1;     
    
    for (int v : adj[u]) {
        State res = dfs(v);
        
        res.offset++;
        
        auto it = res.m.lower_bound(k - res.offset);
        while (it != res.m.end()) {
            ll ways = (it->second * res.mul) % MOD;
            res.safe_sum = (res.safe_sum - ways + MOD) % MOD;
            res.cnt_long = (res.cnt_long + ways) % MOD;
            it = res.m.erase(it);
        }
        
        if (res.safe_sum == 0) bad_children++;
        else prod_safe = (prod_safe * res.safe_sum) % MOD;
        
        children_states.push_back(move(res));
    }

    if (bad_children > 1) {
        return State(); 
    }

    State current;
    ll perm_fact = fact[children_states.size() - 1]; 

    if (bad_children == 1) {
        for (auto& s : children_states) {
            if (s.safe_sum == 0) {
                ll M = (perm_fact * prod_safe) % MOD;
                
                current = move(s);
                current.mul = (current.mul * M) % MOD;
                current.cnt_long = (current.cnt_long * M) % MOD;
                break;
            }
        }
    } else {
        int largest_idx = -1;
        size_t max_size = 0;
        for(int i=0; i<children_states.size(); ++i) {
            if(children_states[i].m.size() > max_size) {
                max_size = children_states[i].m.size();
                largest_idx = i;
            }
        }

        if (largest_idx != -1) {
            State& s = children_states[largest_idx];
            ll term = (perm_fact * prod_safe) % MOD;
            ll M = (term * modInverse(s.safe_sum)) % MOD;
            
            current = move(s);
            current.mul = (current.mul * M) % MOD;
            current.cnt_long = (current.cnt_long * M) % MOD;
            current.safe_sum = (current.safe_sum * M) % MOD;
        }

        for (int i = 0; i < children_states.size(); ++i) {
            if (i == largest_idx) continue;
            State& s = children_states[i];
            
            ll term = (perm_fact * prod_safe) % MOD;
            ll M = (term * modInverse(s.safe_sum)) % MOD;
            
            ll add_long = (s.cnt_long * M) % MOD;
            current.cnt_long = (current.cnt_long + add_long) % MOD;
            
            ll inv_curr_mul = modInverse(current.mul);
            
            // Fixed loop for compatibility
            for (auto const& entry : s.m) {
                ll key = entry.first;
                ll val = entry.second;
                
                ll real_depth = key + s.offset;
                ll ways = (val * s.mul) % MOD; 
                ways = (ways * M) % MOD;       
                
                current.safe_sum = (current.safe_sum + ways) % MOD;
                
                int store_key = real_depth - current.offset;
                ll stored_val = (ways * inv_curr_mul) % MOD;
                current.m[store_key] = (current.m[store_key] + stored_val) % MOD;
            }
        }
    }
    
    return current;
}

class Solution {
public:
    void solve() {
        cin >> n >> k;
        adj.assign(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }

        State res = dfs(1);
        
        ll ans = (res.safe_sum + res.cnt_long) % MOD;
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    Solution s;
    int tc;
    cin >> tc;
    while (tc--) {
        s.solve();
    }
    return 0;
}