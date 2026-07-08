#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n, q;
        if (!(cin >> n >> q)) return;

        ll B = 450; // Block size roughly equal to sqrt(N)
        ll num_blocks = (n + B - 1) / B;

        vector<ll> A(n + 1, 0);
        vector<ll> bl(num_blocks), br(num_blocks);
        vector<ll> b_lazy(num_blocks, 0); // Initially all elements are 0
        vector<ll> b_sum(num_blocks, 0);
        vector<ll> b_ans(num_blocks, 0);

        for (ll b = 0; b < num_blocks; b++) {
            bl[b] = b * B + 1;
            br[b] = min(n, (b + 1) * B);
            b_lazy[b] = 0;
            b_sum[b] = 0;
            b_ans[b] = 0;
        }

        // Pushes block-wide lazy updates down to individual elements
        auto push = [&](ll b) {
            if (b_lazy[b] != -1) {
                for (ll i = bl[b]; i <= br[b]; i++) {
                    A[i] = b_lazy[b];
                }
                b_lazy[b] = -1;
            }
        };

        // Rebuilds a block's sum and max answer locally
        auto rebuild = [&](ll b) {
            ll ones = 0;
            b_sum[b] = 0;
            b_ans[b] = -1e18; 
            for (ll i = bl[b]; i <= br[b]; i++) {
                if (A[i] == 1) {
                    ones++;
                } else {
                    b_ans[b] = max(b_ans[b], ones);
                }
            }
            b_sum[b] = ones;
        };

        // Range update function to set [L, R] to val (0 or 1)
        auto update = [&](ll L, ll R, ll val) {
            ll blk_L = (L - 1) / B;
            ll blk_R = (R - 1) / B;

            if (blk_L == blk_R) {
                push(blk_L);
                for (ll i = L; i <= R; i++) A[i] = val;
                rebuild(blk_L);
            } else {
                // Handle partial left block
                push(blk_L);
                for (ll i = L; i <= br[blk_L]; i++) A[i] = val;
                rebuild(blk_L);

                // Handle partial right block
                push(blk_R);
                for (ll i = bl[blk_R]; i <= R; i++) A[i] = val;
                rebuild(blk_R);

                // Handle completely covered inner blocks
                for (ll b = blk_L + 1; b < blk_R; b++) {
                    b_lazy[b] = val;
                    if (val == 0) {
                        b_sum[b] = 0;
                        b_ans[b] = 0;
                    } else {
                        b_sum[b] = br[b] - bl[b] + 1;
                        b_ans[b] = -1e18;
                    }
                }
            }
        };

        // Process Queries
        for (ll q_idx = 0; q_idx < q; q_idx++) {
            ll type;
            cin >> type;
            if (type == 0) {
                ll l, r;
                cin >> l >> r;
                update(l, r, 0);
            } else if (type == 1) {
                ll l, r;
                cin >> l >> r;
                update(l, r, 1);
            } else if (type == 2) {
                ll total_ones = 0;
                for (ll b = 0; b < num_blocks; b++) {
                    total_ones += b_sum[b];
                }
                ll zeros = n - total_ones;
                if (zeros >= 1) {
                    update(1, zeros, 0);
                }
                if (total_ones >= 1) {
                    update(zeros + 1, n, 1);
                }
            }

            // Calculate the global answer across all blocks
            ll global_max = 0;
            ll running_ones = 0;
            for (ll b = 0; b < num_blocks; b++) {
                if (b_ans[b] >= 0) {
                    global_max = max(global_max, running_ones + b_ans[b]);
                }
                running_ones += b_sum[b];
            }
            cout << global_max + 1 << "\n";
        }
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