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
#define vvvl vector<vector<vector<ll>>>
ll M = 1e9 + 7;

ll getrandom(int range)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0, range);
    return dist6(rng);
}
ll gcd(ll XX, ll YY) { return YY == 0 ? XX : gcd(YY, XX % YY);}
ll exppow(ll XX, ll YY)
{
    XX %= M;
    ll ret = 1;
    while (YY > 0) {
        if (YY % 2)
            ret = (ret * XX) % M;
        XX = (XX * XX) % M;
        YY /= 2;
    }
    return ret;
}
ll fracmod(ll XX, ll YY)
{
    ll ZZ = gcd(XX, YY);
    XX = XX / ZZ;
    YY = YY / ZZ;
    return (XX * exppow(YY, M - 2)) % M;
}

ll w[801], mat[801][801][2];
vvvi adj;

void solve()
{
    adj.clear();
    int n, m;
    ll money;
    cin >> n >> m >> money;
    rep(i, 0, n - 1) cin >> w[i];
    adj.resize(n);
    rep(i, 1, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1].pb({v - 1, c});
    }
    rep(i, 0, n - 1) rep(j, 0, n - 1) mat[i][j][0] = INF, mat[i][j][1] = -INF;
    priority_queue<vl, vvl, greater<vl>> pq;
    mat[0][0][0] = mat[0][0][1] = 0;
    pq.push({0, -money, 0, 0});
    while (pq.size())
    {
        vl t = pq.top();
        pq.pop();
        ll p = t[0], c = -t[1], u = t[2], mx = t[3];
        // cout << u + 1 << " " << mx + 1 << " : " << p << ", " << c << "\n";
        for (auto &i : adj[u])
        {
            ll v = i[0], d = i[1];
            ll mxp = mx, cp = c, pp = p;
            if (w[v] > w[mx])
                mxp = v;
            if (d > c)
            {
                ll x = (d - c + w[mx] - 1) / w[mx];
                pp += x;
                cp += x * w[mx];
            }
            cp -= d;
            if (pp < mat[v][mxp][0] || (pp == mat[v][mxp][0] && cp > mat[v][mxp][1]))
            {
                mat[v][mxp][0] = pp;
                mat[v][mxp][1] = cp;
                pq.push({pp, -cp, v, mxp});
            }
        }
    }
    ll ans = INF;
    rep(i, 0, n - 1) ans = min(ans, mat[n - 1][i][0]);
    if (ans == INF)
        ans = -1;
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
