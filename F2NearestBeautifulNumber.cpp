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
ll M = 1e18;

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

int x, k;
vi a, ans;
set<int> v;

bool dfs(int i)
{
    if (i == a.size())
        return 1;
    rep(j, a[i], 9)
    {
        if (v.find(j) == v.end() && v.size() < k)
        {
            v.insert(j);
            ans[i] = j;
            if (j == a[i] && dfs(i + 1))
                return 1;
            else if (j > a[i])
            {
                int t = (v.size() == k ? *v.begin() : 0);
                rep(k, i + 1, ans.size() - 1) ans[k] = t;
                return 1;
            }
            v.erase(j);
        }
        else if (v.find(j) != v.end())
        {
            ans[i] = j;
            if (j == a[i] && dfs(i + 1))
                return 1;
            else if (j > a[i])
            {
                int t = (v.size() == k ? *v.begin() : 0);
                rep(k, i + 1, ans.size() - 1) ans[k] = t;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    a.clear();
    ans.clear();
    v.clear();
    cin >> x >> k;
    while (x)
        a.pb(x % 10), x /= 10;
    reverse(a.begin(), a.end());
    ans.resize(a.size());
    dfs(0);
    for (auto &i : ans)
        cout << i;
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
