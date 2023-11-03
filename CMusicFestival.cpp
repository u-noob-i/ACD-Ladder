#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e9
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vvi a(n);
    map<int, vpi> ind;
    map<int, int> dp;
    rep(i, 0, n - 1)
    {
        int k, x;
        cin >> k;
        while (k--)
        {
            cin >> x;
            if (!a[i].size() || a[i].back() < x)
            {
                // cout << x << " ";
                a[i].pb(x);
                ind[x].pb({i, a[i].size()});
            }
        }
        // cout << "\n";
    }
    int ans = -1, prev = 0;
    for (auto itr = ind.rbegin(); itr != ind.rend(); itr++)
    {
        int x = itr->first;
        vpi t = itr->second;
        dp[x] = prev;
        for (auto &i : t)
        {

            int cur = a[i.first].size() - i.second + 1;
            auto jtr = dp.upper_bound(a[i.first].back());
            if (jtr != dp.end())
                cur += jtr->second;
            dp[x] = max(dp[x], cur);
        }
        // cout << x << " " << dp[x] << "\n";
        ans = max(ans, dp[x]);
        prev = max(prev, dp[x]);
    }
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
