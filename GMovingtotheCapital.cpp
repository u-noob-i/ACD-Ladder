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
#define vvvl vector<vector<vector<ll>>>
ll M = 1e18;

//---------------------------------------------//
ll getrandom(int range)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0, range);
    return dist6(rng);
}
ll gcd(ll XX, ll YY) { return YY == 0 ? XX : gcd(YY, XX % YY);}
ll exppow(ll XX, ll YY)
{
    XX %= M;
    ll ret = 1;
    while (YY > 0) {
        if (YY % 2)
            ret = (ret * XX) % M;
        XX = (XX * XX) % M;
        YY /= 2;
    }
    return ret;
}
ll fracmod(ll XX, ll YY)
{
    ll ZZ = gcd(XX, YY);
    XX = XX / ZZ;
    YY = YY / ZZ;
    return (XX * exppow(YY, M - 2)) % M;
}
//---------------------------------------------//

vvi adj, dp;
vi dist;
vb vis;

int dfs(int u, int c)
{
    if (dp[u][c] != -1)
        return dp[u][c];
    int val = dist[u];
    for (auto &v : adj[u])
        if (dist[u] < dist[v])
            val = min(val, dfs(v, c));
        else if (!c)
            val = min(val, dfs(v, c + 1));
    dp[u][c] = val;
    return val;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    dp.assign(n, vi(2, -1));
    dist.assign(n, INF);
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
    }
    priority_queue<pi, vpi, greater<pi>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size())
    {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (dist[u] != d)
            continue;
        for (auto &v : adj[u])
            if (dist[v] > d + 1)
                dist[v] = d + 1, pq.push({dist[v], v});
    }
    vis.assign(n, 0);
    dp[0][0] = dp[0][1] = 0;
    rep(i, 0, n - 1) cout << min(dfs(i, 0), dfs(i, 1)) << " ";
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
