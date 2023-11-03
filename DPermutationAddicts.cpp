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
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int k = 0;
    rep(i, 1, n)
    {
        if (a[i] <= i)
            break;
        else
            k++;
    }
    vvi adj(n + 1);
    vi in(n + 1, 0), b(n + 1);
    rep(i, 1, n)
    {
        if (a[i] >= 1 && a[i] <= n)
        {
            in[i]++;
            adj[a[i]].pb(i);
        }
    }
    int ind = 1;
    vi q;
    rep(i, 1, n) if (!in[i]) q.pb(i);
    while (q.size())
    {
        vi t;
        sort(q.begin(), q.end(), [&](const int &x, const int &y) {
            return adj[x].size() < adj[y].size();
        });
        for (auto &x : q)
        {
            b[ind++] = x;
            for (auto &v : adj[x])
                t.pb(v);
        }
        swap(q, t);
    }
    cout << k << "\n";
    rep(i, 1, n) cout << b[i] << " ";
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
