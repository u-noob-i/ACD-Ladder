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

int d[200001], p[200001], sz[200001];

void dsj(int n)
{
    rep(i, 0, n - 1)
    {
        p[i] = i;
        sz[i] = 1;
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
    if (sz[x] < sz[y])
    {
        p[x] = y;
        sz[y] += sz[x];
    }
    else
    {
        p[y] = x;
        sz[x] += sz[y];
    }
}

void solve()
{
    memset(d, 0, sizeof(d));
    int n, m;
    cin >> n >> m;
    dsj(n);
    vvi edges(m, vi(2));
    for (auto &x : edges)
    {
        cin >> x[0] >> x[1];
        x[0]--, x[1]--;
        d[x[0]]++;
        d[x[1]]++;
    }
    int k = 0;
    rep(i, 0, n - 1)
    {
        if (d[i] != 2 && d[i] != 4)
        {
            cout << "NO";
            return;
        }
        if (d[i] == 4)
            k++;
    }
    if (!k || n % k || m != k * (k + 1))
    {
        cout << "NO";
        return;
    }
    for (auto &x : edges)
        if (d[x[0]] == 2 || d[x[1]] == 2)
            merge(x[0], x[1]);
    rep(i, 0, n - 1)
    {
        if (sz[find(i)] != k)
        {
            cout << "NO";
            return;
        }
    }
    for (auto &x : edges)
        if (d[x[0]] == 4 && d[x[1]] == 4)
            merge(x[0], x[1]);
    if (sz[find(0)] != n)
        cout << "NO";
    else
        cout << "YES";
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
