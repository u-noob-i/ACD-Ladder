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

void solve()
{
    int n, q, l, r;
    cin >> n >> q;
    vi a(n), xo(n + 1, 0), z(n + 1, 0);
    map<int, vi> xxo, xxe;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        xo[i + 1] = a[i] ^ xo[i];
        if (i % 2)
            xxe[xo[i + 1]].pb(i + 1);
        else
            xxo[xo[i + 1]].pb(i + 1);
        z[i + 1] = z[i] + (a[i] == 0);
    }
    while (q--)
    {
        cin >> l >> r;
        int x = r - l + 1;
        if (z[r] - z[l - 1] == x)
            cout << 0;
        else if (x <= 2 || xo[r]^xo[l - 1])
            cout << -1;
        else if (x % 2 || !a[r - 1] || !a[l - 1])
            cout << 1;
        else
        {
            bool f = 0;
            if (l % 2 == 0)
            {
                int lo = 0, hi = (int)xxe[xo[l - 1]].size() - 1, mid;
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    int ind = xxe[xo[l - 1]][mid];
                    if (ind >= l && ind <= r)
                    {
                        f = 1;
                        break;
                    }
                    if (ind < l)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
            else
            {
                int lo = 0, hi = (int)xxo[xo[l - 1]].size() - 1, mid;
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    int ind = xxo[xo[l - 1]][mid];
                    if (ind >= l && ind <= r)
                    {
                        f = 1;
                        break;
                    }
                    if (ind < l)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
            if (f)
                cout << 2;
            else
                cout << -1;
        }
        cout << "\n";
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

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
