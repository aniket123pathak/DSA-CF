#include <iostream>
#include <vector>

using namespace std;

// The modulus required by the problem
const int MOD = 1e9 + 7;

int n, m;

/**
 * Recursive function to generate valid next_masks for the next column
 * based on the current_mask of the current column.
 * * @param row: Current row we are trying to fill in the current column (0 to n-1)
 * @param current_mask: The profile mask coming from the previous column
 * @param next_mask: The profile mask we are building for the next column
 * @param ways: The number of ways to reach the 'current_mask' state
 * @param next_dp: The DP table for the next column we are updating
 */
void generate_next_masks(int row, int current_mask, int next_mask, long long ways, vector<long long>& next_dp) {
    // Base Case: If we have successfully filled all rows for this column
    if (row == n) {
        next_dp[next_mask] = (next_dp[next_mask] + ways) % MOD;
        return;
    }

    // Case 1: The current cell (row, col) is already filled by a horizontal tile
    // coming from the previous column (col-1).
    if ((current_mask >> row) & 1) {
        // We cannot place a new tile here. Move to the next row.
        // The corresponding bit in next_mask stays 0.
        generate_next_masks(row + 1, current_mask, next_mask, ways, next_dp);
    } else {
        // Case 2: The current cell is empty. We must fill it.
        
        // Option A: Try to place a Vertical Tile (2x1)
        // We need the next row (row+1) to be within bounds AND also empty in current_mask.
        if (row + 1 < n && !((current_mask >> (row + 1)) & 1)) {
            generate_next_masks(row + 2, current_mask, next_mask, ways, next_dp);
        }

        // Option B: Try to place a Horizontal Tile (1x2)
        // We place a tile at (row, col) occupying (row, col+1).
        // This creates a protrusion, so we set the bit 'row' in next_mask to 1.
        generate_next_masks(row + 1, current_mask, next_mask | (1 << row), ways, next_dp);
    }
}

void solve() {
    // Optimized I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return;

    // dp[mask] stores the number of ways to fill the prefix of the grid
    // ending with a specific profile 'mask'.
    // Size is 2^N (since N <= 10, max size is 1024).
    vector<long long> dp(1 << n, 0);

    // Initial state: Imaginary column -1 is full, so mask 0 has 1 way.
    dp[0] = 1;

    // Iterate through each column j from 0 to m-1
    for (int j = 0; j < m; ++j) {
        vector<long long> next_dp(1 << n, 0);
        
        // Iterate through all possible masks from the previous column
        for (int mask = 0; mask < (1 << n); ++mask) {
            // Only process states that are reachable
            if (dp[mask] > 0) {
                // Use DFS to generate all valid transitions to the next column
                generate_next_masks(0, mask, 0, dp[mask], next_dp);
            }
        }
        
        // Update dp table for the next iteration
        dp = next_dp;
    }

    // The answer is the number of ways to fill the grid up to column m-1
    // with no protrusions into column m (mask 0).
    cout << dp[0] << endl;
}

int main() {
    solve();
    return 0;
}