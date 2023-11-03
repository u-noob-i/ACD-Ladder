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

int query(int l, int r)
{
    int x;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin >> x;
    return x;
}

void solve()
{
    int n, x;
    cin >> n;
    int l = 1, r = n, mid, mm = query(1, n), ans = -1, ct = 1;
    if (mm == 1)
        l = 2;
    else if (mm == n)
        r = n - 1;
    else
    {
        ct++;
        x = query(1, mm);
        if (x == mm)
            r = mm - 1;
        else
            l = mm + 1;
    }
    while (ct < 20 && l <= r)
    {
        ct++;
        mid = (l + r) / 2;
        if (mid < mm)
        {
            x = query(mid, mm);
            if (x == mm)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        else
        {
            x = query(mm, mid);
            if (x == mm)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
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
