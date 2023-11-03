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

int n, k;
int a[100001], t[100001];

int pos(int d)
{
    int mm = (d + 1) / 2, ret = 0;
    rep(i, 0, n - 1)
    {
        t[i] = a[i];
        if (t[i] < mm)
        {
            t[i] = 1e9;
            ret++;
        }
    }
    int mc = 2;
    rep(i, 1, n - 1)
    {
        int f = 0;
        if (t[i - 1] < d)
            f++;
        if (t[i] < d)
            f++;
        mc = min(mc, f);
    }
    return ret + mc;
}

void solve()
{
    cin >> n >> k;
    rep(i, 0, n - 1) cin >> a[i];
    int l = 0, r = 1e9, mid, ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (pos(mid) <= k)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
