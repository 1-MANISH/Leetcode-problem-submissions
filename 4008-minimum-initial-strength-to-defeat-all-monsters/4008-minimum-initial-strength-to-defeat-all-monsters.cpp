class Solution {
public:
    using ll = long long;

    bool possible(ll initial, vector<int>& monsters, vector<ll>& bonus) {
        ll strength = initial;

        for (int i = 0; i < monsters.size(); i++) {
            if (strength + bonus[i] < monsters[i])
                return false;

            strength -= monsters[i];
            if (strength < 0)
                strength = 0;
        }

        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        //  bonuses
        vector<ll> bonus(n + 1, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            ll val = b[2];
            bonus[l] += val;
            if (r + 1 < n) // to not this bonous to index >r
                bonus[r + 1] -= val;
        }
        for (int i = 1; i < n; i++) {
            bonus[i] = bonus[i-1]+bonus[i];
        }
        ll low = 0,high = 0;
        for (int x : monsters)
            high += x;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (possible(mid, monsters, bonus))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};