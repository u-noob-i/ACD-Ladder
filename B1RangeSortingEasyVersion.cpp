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

int t[5001][4];

void foo(int i, int x, int y, int z, int w)
{
    t[i][0] = x;
    t[i][1] = y;
    t[i][2] = z;
    t[i][3] = w;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        int cur = 0, ind = 0;
        foo(ind, i, i, a[i], a[i]);
        rep(j, i + 1, n - 1)
        {
            int si = j, mx = a[j];
            while (ind >= 0 && t[ind][2] > a[j])
            {
                cur -= t[ind][1] - t[ind][0];
                mx = max(mx, t[ind][3]);
                si = t[ind][0];
                ind--;
            }
            if (ind < 0 || t[ind][3] < a[j])
            {
                ind++;
                foo(ind, si, j, a[j], mx);
                cur += j - si;
            }
            else
            {
                cur -= t[ind][1] - t[ind][0];
                t[ind][1] = j;
                t[ind][3] = max(t[ind][3], mx);
                cur += t[ind][1] - t[ind][0];
            }
            ans += cur;
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
