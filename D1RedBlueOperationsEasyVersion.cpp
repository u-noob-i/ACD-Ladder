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

void foo(int n, vl a)
{
    ll k, ans = INF;
    cin >> k;
    sort(a.begin(), a.end());
    if (k <= n)
    {
        rep(i, 0, n - 1)
        {
            if (k > 0)
                a[i] += k--;
            ans = min(ans, a[i]);
        }
        cout << ans << " ";
        return;
    }
    int op = n;
    if ((k - n) % 2)
        op--;
    rep(i, 0, n - 1)
    {
        if (!op)
            break;
        op--;
        a[i] += k--;
    }
    k /= 2;
    sort(a.begin(), a.end(), greater<ll>());
    rep(i, 0, n - 2)
    {
        ll x = (a[i] - a[i + 1]) * (i + 1);
        k -= x;
        if (k < 0)
        {
            k = 0;
            break;
        }
    }
    cout << a[n - 1] - (k + n - 1) / n << " ";
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vl a(n);
    for (auto &x : a)
        cin >> x;
    rep(i, 1, q) foo(n, a);
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
