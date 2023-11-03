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

int a[3001], pp[30001];

void solve()
{

    pp[0] = 1;
    rep(i, 1, 3000) pp[i] = (pp[i - 1] * 2) % M;

    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n)
    {
        int d = a[j] - a[i];
        int l = 1, r = i - 1, mid, x = 0, y = n + 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[i] - a[mid] > d)
            {
                x = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = j + 1, r = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (a[mid] - a[j] >= d)
            {
                y = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        x = (1ll * pp[x] * pp[n - y + 1]) % M;
        ans = (ans + x) % M;
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
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
