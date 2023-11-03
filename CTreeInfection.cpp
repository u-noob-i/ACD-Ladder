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
    vi ct(n, 0);
    rep(i, 1, n - 1)
    {
        int x;
        cin >> x;
        ct[x - 1]++;
    }
    priority_queue<int> pq;
    pq.push(1);
    rep(i, 0, n - 1) if (ct[i]) pq.push(ct[i]);
    int t = 0;
    vpi a;
    while (pq.size())
    {
        int x = pq.top();
        pq.pop();
        x--;
        t++;
        a.pb({x, t});
    }
    for (auto &x : a)
    {
        x.first -= t - x.second;
        if (x.first > 0)
            pq.push(x.first);
    }
    int x = 0;
    while (pq.size() && pq.top() > x)
    {
        int y = pq.top();
        pq.pop();
        pq.push(y - 1);
        x++;
    }
    cout << t + x;
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
