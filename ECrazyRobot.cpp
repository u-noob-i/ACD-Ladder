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
ll M = 998244353;

int n, m;
int d[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

bool isval(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return 1;
    return 0;
}

void solve()
{
    cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<string> ans = a;
    vector<vector<bool>> v(n, vector<bool>(m, 0));
    queue<pi> q;
    rep(i, 0, n - 1) rep(j, 0, m - 1) if (a[i][j] == 'L') q.push({i, j});
    while (q.size())
    {
        pi t = q.front();
        q.pop();
        int x = t.first, y = t.second, ct = 0;
        if (a[x][y] != 'L')
        {
            rep(i, 0, 3)
            {
                int nx = x + d[i][0], ny = y + d[i][1];
                if (isval(nx, ny) && a[nx][ny] != '#' && !v[nx][ny])
                    ct++;
            }
        }
        if (ct > 1)
            continue;
        v[x][y] = 1;
        if (a[x][y] != 'L')
            ans[x][y] = '+';
        rep(i, 0, 3)
        {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (isval(nx, ny) && a[nx][ny] != '#' && !v[nx][ny])
                q.push({nx, ny});
        }
    }
    rep(i, 0, n - 1) cout << ans[i] << "\n";
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
