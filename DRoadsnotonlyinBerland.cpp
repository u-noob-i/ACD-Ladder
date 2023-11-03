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

int p[1001], r[1001];
int sz;

void dsj(int n)
{
    rep(i, 0, n - 1)
    {
        p[i] = i;
        r[i] = 0;
    }
    sz = n;
}

int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}

bool merge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return 0;
    sz--;
    if (r[x] < r[y])
        p[x] = y;
    else if (r[y] < r[x])
        p[y] = x;
    else
        p[y] = x, r[x]++;
    return 1;
}

void solve()
{
    int n, u, v;
    cin >> n;
    dsj(n);
    vvi ans;
    rep(i, 0, n - 2)
    {
        int u, v;
        cin >> u >> v;
        if (!merge(u - 1, v - 1))
            ans.pb({u, v});
    }
    set<int> a;
    rep(i, 0, n - 1) a.insert(find(i) + 1);
    auto itr = a.begin();
    int prv = *itr, i = 0;
    itr++;
    while (itr != a.end())
    {
        ans[i].pb(prv);
        ans[i].pb(*itr);
        prv = *itr;
        i++;
        itr++;
    }
    cout << ans.size();
    for (auto &itr : ans)
    {
        cout << "\n";
        for (auto &i : itr)
            cout << i << " ";
    }
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
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
