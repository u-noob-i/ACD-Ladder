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

int cp;
int par[200001], sz[200001];

void dsj(int n)
{
    cp = n;
    rep(i, 0, n - 1)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u)
{
    if (par[u] != u)
        par[u] = find(par[u]);
    return par[u];
}

void merge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return;
    cp--;
    if (sz[x] < sz[y])
    {
        par[x] = y;
        sz[y] += sz[x];
    }
    else
    {
        par[y] = x;
        sz[x] += sz[y];
    }
}

void solve()
{
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vpi b(n);
    rep(i, 0, n - 1)
    {
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end(), [&](const pi & x, const pi & y) {
        if (x.first == y.first)
            return x.second < y.second;
        return x.first < y.first;
    });
    ll ans = 0;
    dsj(n);
    rep(i, 0, n - 1)
    {
        if (cp == 1 || b[i].first >= p)
            break;
        int x = b[i].first, ind = b[i].second;
        for (int j = ind - 1; j >= 0; j--)
        {
            if (a[j] < a[ind] || find(j) == find(ind) || a[j] % a[ind])
                break;
            merge(j, ind);
            ans += x;
        }
        for (int j = ind + 1; j < n; j++)
        {
            if (a[j] < a[ind] || find(j) == find(ind) || a[j] % a[ind])
                break;
            merge(j, ind);
            ans += x;
        }
    }
    ans += 1ll * p * (cp - 1);
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
