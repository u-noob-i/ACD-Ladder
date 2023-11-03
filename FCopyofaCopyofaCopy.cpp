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
ll M = 1e9 + 7;

int n, m, k;
vi arr;
vector<vector<string>> a;

void dac(vi &t)
{
    rep(p, 1, n - 2) rep(q, 1, m - 2)
    {
        vi o, z;
        int ss = -1;
        for (auto &i : t)
        {
            if (a[i][p][q] == '0')
                z.pb(i);
            else
                o.pb(i);
            if (a[i][p][q - 1] == '1')
                ss = 1;
            else
                ss = 0;
        }
        if (o.size() && z.size())
        {
            if (ss == 1)
            {
                dac(z);
                dac(o);
            }
            else
            {
                dac(o);
                dac(z);
            }
            return;
        }
    }
    for (auto &i : t)
        arr.pb(i);
}

void solve()
{
    cin >> n >> m >> k;
    a.resize(k + 1, vector<string>(n));
    rep(i, 0, k) rep(j, 0, n - 1) cin >> a[i][j];
    vi t;
    rep(i, 0, k) t.pb(i);
    dac(t);
    vvi op;
    rep(i, 1, k)
    {
        rep(p, 1, n - 1) rep(q, 1, m - 1)
        {
            if (a[arr[i]][p][q] != a[arr[i - 1]][p][q])
                op.pb({1, p + 1, q + 1});
        }
        op.pb({2, arr[i] + 1});
    }
    cout << arr[0] + 1 << "\n" << op.size();
    for (auto &x : op)
    {
        cout << "\n";
        for (auto &y : x)
            cout << y << " ";
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
