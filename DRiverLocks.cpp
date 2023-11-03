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
    int n, q;
    cin >> n;
    vl a(n + 1), s(n + 1, 0), p(n + 1), t(n + 1);
    ll x;
    rep(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll mm = 0;
    p[1] = a[1];
    t[1] = s[n];
    rep(i, 2, n)
    {
        p[i] = p[i - 1] + max(0ll, (s[i] - p[i - 1] * i + i - 1) / i);
        t[i] = p[i] + max(0ll, (s[n] - p[i] * i + i - 1) / i);
    }
    // rep(i, 1, n) cout << p[i] << " " << t[i] << "\n";
    cin >> q;
    while (q--)
    {
        x;
        cin >> x;
        int l = 1, r = n, m, v = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (t[m] <= x)
            {
                v = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << v << "\n";
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
