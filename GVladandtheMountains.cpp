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

int h[200001], p[200001], r[200001];

void dsj(int n)
{
    rep(i, 0, n - 1)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}

void merge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return;
    if (r[x] > r[y])
        p[y] = x;
    else if (r[y] > r[x])
        p[x] = y;
    else
    {
        p[x] = y;
        r[y]++;
    }
}

void solve()
{
    int n, m, q;
    cin >> n >> m;
    vvi edges(m, vi(3));
    rep(i, 0, n - 1) cin >> h[i];
    rep(i, 0, m - 1)
    {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--, edges[i][1]--;
        edges[i][2] = max(h[edges[i][0]], h[edges[i][1]]);
    }
    sort(edges.begin(), edges.end(), [&](const vi & x, const vi & y) {
        return x[2] < y[2];
    });
    cin >> q;
    vvi queries(q, vi(4));
    rep(i, 0, q - 1)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        queries[i][0]--, queries[i][1]--;
        queries[i][3] = i;
    }
    sort(queries.begin(), queries.end(), [&](const vi & x, const vi & y) {
        return h[x[0]] + x[2] < h[y[0]] + y[2];
    });
    dsj(n);
    vector<string> ans(q);
    for (int i = 0, j = 0; j < q; j++)
    {
        while (i < m && edges[i][2] <= h[queries[j][0]] + queries[j][2])
        {
            merge(edges[i][0], edges[i][1]);
            i++;
        }
        if (find(queries[j][0]) == find(queries[j][1]))
            ans[queries[j][3]] = "YES";
        else
            ans[queries[j][3]] = "NO";
    }
    for (auto &x : ans)
        cout << x << "\n";
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
