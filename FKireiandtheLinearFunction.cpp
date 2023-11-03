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
    int n, m, w, l, r, k;
    string s;
    cin >> s >> w >> m;
    n = s.length();
    vi a(n + 1, 0);
    rep(i, 1, n) a[i] = a[i - 1] + (s[i - 1] - '0');
    map<int, vi> arr;
    rep(i, w, n)
    {
        int x = (a[i] - a[i - w]) % 9;
        if (arr[x].size() <= 1)
            arr[x].pb(i - w + 1);
    }
    rep(j, 1, m)
    {
        cin >> l >> r >> k;
        int v = (a[r] - a[l - 1]) % 9, ax = -1, ay = -1;
        for (auto &itr : arr)
        {
            int x = itr.first;
            int y = (k - (v * x) % 9) % 9;
            if (y < 0)
                y += 9;
            if (arr.find(y) == arr.end())
                continue;
            if (x != y && arr.find(y) != arr.end())
            {
                if (ax == -1 || arr[x][0] < ax)
                {
                    ax = arr[x][0];
                    ay = arr[y][0];
                }
                else if (arr[x][0] == ax && arr[y][0] < ay)
                    ay = arr[y][0];
            }
            else if (x == y && arr[x].size() > 1)
            {
                if (ax == -1 || arr[x][0] < ax)
                {
                    ax = arr[x][0];
                    ay = arr[x][1];
                }
                else if (arr[x][0] == ax && arr[x][1] < ay)
                    ay = arr[x][1];
            }
        }
        cout << ax << " " << ay << "\n";
    }
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
        // cout << "\n";
    }
}
