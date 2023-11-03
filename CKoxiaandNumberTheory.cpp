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

int ct[101];

void solve()
{
    int n;
    cin >> n;
    vl a(n);
    for (auto &x : a)
        cin >> x;
    bool f = 1;
    sort(a.begin(), a.end());
    rep(i, 1, n - 1) if (a[i] == a[i - 1]) f = 0;
    rep(i, 2, 50)
    {
        fill(ct, ct + i, 0);
        for (auto &x : a)
            ct[x % i]++;
        int mn = INF;
        rep(j, 0, i - 1) mn = min(mn, ct[j]);
        if (mn >= 2)
            f = 0;
    }
    if (f)
        cout << "YES";
    else
        cout << "NO";
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
