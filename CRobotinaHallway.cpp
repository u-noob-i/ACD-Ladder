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
    vvl a(2, vl(n));
    rep(i, 0, 1) rep(j, 0, n - 1) cin >> a[i][j];
    ll l = 0, r = 1e10, mid, ans;
    while (l <= r)
    {
        bool f = 1;
        mid = (l + r) / 2;
        ll t = mid;
        int i = 0, j = 0;
        while (j < n)
        {
            if (a[i][j] > t)
            {
                j--;
                t--;
                if (j)
                    t--;
                i = 1 - i;
                rep(k, j, n - 1)
                {
                    if (a[i][k] > t)
                        f = 0;
                    if (k)
                        t++;
                }
                i = 1 - i;
                irep(k, n - 1, j)
                {
                    if (a[i][k] > t)
                        f = 0;
                    t++;
                }
                break;
            }
            if (j)
                t++;
            i = 1 - i;
            if (a[i][j] > t)
            {
                if (j)
                    t--;
                i = 1 - i;
                rep(k, j, n - 1)
                {
                    if (a[i][k] > t)
                        f = 0;
                    if (k)
                        t++;
                }
                i = 1 - i;
                irep(k, n - 1, j)
                {
                    if (a[i][k] > t)
                        f = 0;
                    t++;
                }
                break;
            }
            t++;
            j++;
        }
        if (f)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans + 2 * n - 1;
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
