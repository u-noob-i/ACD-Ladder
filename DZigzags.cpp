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

int a[3001], ct[3001], f[3001];

void solve()
{
    memset(ct, 0, sizeof(ct));
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        ct[a[i]]++;
    }
    rep(i, 0, n - 1)
    {
        ll cur = 0;
        ct[a[i]]--;
        memset(f, 0, sizeof(f));
        rep(j, i + 1, n - 1)
        {
            // cout << i + 1 << " " << j + 1 << " " << cur << "\n";
            if (a[i] == a[j])
                ans += cur - f[a[j]];
            cur -=  1ll * f[a[j]] * (ct[a[j]] - f[a[j]]);
            f[a[j]]++;
            cur += 1ll * f[a[j]] * (ct[a[j]] - f[a[j]]);
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

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
