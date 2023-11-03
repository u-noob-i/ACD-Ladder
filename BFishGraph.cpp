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

vvvi adj;
vi d, e;
vb vis, cy;

bool iscyc(int og, int u, int p)
{
    vis[u] = cy[u] = 1;
    if (p != og)
    {
        for (auto &v : adj[u])
        {
            if (v[0] == og)
            {
                e.pb(v[1]);
                return 1;
            }
        }
    }
    for (auto &v : adj[u])
    {
        if (vis[v[0]] || v[0] == p)
            continue;
        e.pb(v[1]);
        if (iscyc(og, v[0], u))
            return 1;
        e.pr();
    }
    cy[u] = 0;
    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    d.assign(n, 0);
    vvi edges(m);
    rep(i, 0, m - 1)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        u--, v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        d[u]++, d[v]++;
    }
    rep(i, 0, n - 1)
    {
        if (d[i] >= 4)
        {
            e.clear();
            vis.assign(n, 0);
            cy.assign(n, 0);
            if (iscyc(i, i, i))
            {
                int ct = 0;
                for (auto v : adj[i])
                {
                    if (!cy[v[0]])
                    {
                        e.pb(v[1]);
                        ct++;
                    }
                    if (ct == 2)
                        break;
                }
                if (ct != 2)
                    continue;
                cout << "YES";
                cout << "\n" << e.size();
                for (auto &x : e)
                    cout << "\n" << edges[x][0] << " " << edges[x][1];
                return;
            }
        }
    }
    cout << "NO";
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
