#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e18
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
ll M = 998244353;

int n, k, x, y;
vvi adj;

// 1 2
// 1 3
// 2 4
// 2 5

int dfs(int u, int h, int &ct)
{
    int t = 0;
    if (!adj[u].size())
        return 0;
    for (auto v : adj[u])
    {
        int x = dfs(v, h, ct);
        if (x == h - 1 && u)
        {
            // cout << v + 1 << "\n";
            ct++;
        }
        else
            t = max(t, 1 + x);
    }
    return t;
}

void solve()
{
    cin >> n >> k;
    adj.clear();
    adj.resize(n);
    rep(i, 1, n - 1)
    {
        int x;
        cin >> x;
        adj[x - 1].pb(i);
    }
    int l = 1, r = n - 1, mid, v = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int ct = 0;
        // cout << mid << ": ";
        dfs(0, mid, ct);
        if (ct <= k)
        {
            v = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << v;
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
