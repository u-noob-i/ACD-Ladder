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
    vl a(n);
    map<ll, ll> ct;
    ll mm = -1, ans = 0;
    for (auto &x : a)
    {
        cin >> x;
        mm = max(mm, x);
        ct[x]++;
    }
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    for (auto &x : a)
    {
        ans += ct[x] * (ct[x] - 1) * (ct[x] - 2);
        if (x > 1000000)
        {
            for (ll j = 2; j * x <= mm; j++)
                if (x % j == 0 && ct.find(x / j) != ct.end() && ct.find(x * j) != ct.end())
                    ans += ct[x] * ct[x / j] * ct[x * j];
        }
        else
        {
            if (x > 1 && ct.find(1) != ct.end() && ct.find(x * x) != ct.end())
                ans += ct[x] * ct[1] * ct[x * x];
            for (ll j = 2; j <= sqrt(x); j++)
            {
                if (x % j == 0 && ct.find(x / j) != ct.end() && ct.find(x * j) != ct.end())
                    ans += ct[x] * ct[x / j] * ct[x * j];
                if (x % j == 0 && j != x / j && ct.find(j) != ct.end() && ct.find(x * x / j) != ct.end())
                    ans += ct[x] * ct[j] * ct[x * x / j];
            }
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
