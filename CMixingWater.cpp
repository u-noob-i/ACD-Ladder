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
    ll h, c, t;
    cin >> h >> c >> t;
    if (t == h)
    {
        cout << 1;
        return;
    }
    double d = abs(((1.0 * h + c) / 2) - (1.0 * t));
    ll ans = 2, l = 1, r = 1e9, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        double cur = (1.0 * mid * h + (mid - 1) * c) / (2 * mid - 1);
        if (cur > t)
            l = mid + 1;
        else
            r = mid - 1;
    }
    for (ll i = max(0ll, l - 10); i <= l + 10; i++)
    {
        double cur = (1.0 * i * h + (i - 1) * c) / (2 * i - 1);
        if (abs(cur - t) < d)
        {
            d = abs(cur - t);
            ans = 2 * i - 1;
        }
    }
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
