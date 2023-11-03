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
#define vvvl vector<vector<vector<ll>>>
ll M = 1e9 + 7;

//---------------------------------------------//
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
//---------------------------------------------//

vi a;

int bs(int l, int r, int v)
{
    int s = l, mid, ret = s - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] - a[s - 1] <= v)
            ret = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    map<int, int> ct;
    rep(i, 1, n)
    {
        int x;
        cin >> x;
        ct[x]++;
    }
    a.clear();
    a.pb(0);
    for (auto &itr : ct)
        a.pb(a.back() + itr.second);
    int ans = INF;
    rep(i, 0, 25) rep(j, 0, 25) rep(k, 0, 25)
    {
        int s = 1, e = a.size() - 1, cur = (1 << i) + (1 << j) + (1 << k);
        if (cur < a[e])
            continue;
        int v = bs(s, e, 1 << i);
        cur -= a[v];
        s = v + 1;
        if (s > e)
        {
            ans = min(ans, cur);
            continue;
        }
        v = bs(s, e, 1 << j);
        cur -= a[v] - a[s - 1];
        s = v + 1;
        if (s > e)
        {
            ans = min(ans, cur);
            continue;
        }
        if (a[e] - a[s - 1] > (1 << k))
            continue;
        cur -= a[e] - a[s - 1];
        ans = min(ans, cur);
        // cout << (1 << i) << " " << (1 << j) << " " << (1 << k) << " : " << cur << "\n";
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
