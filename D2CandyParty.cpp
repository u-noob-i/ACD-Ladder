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

void solve()
{
    int n;
    cin >> n;
    vl a(n);
    ll sum = 0;
    for (auto &x : a)
        cin >> x, sum += x;
    if (sum % n)
    {
        cout << "No";
        return;
    }
    sum /= n;
    vi bt(31, 0), g1(31, 0), t1(31, 0);
    for (auto &x : a)
    {
        if (x == sum)
            continue;
        bool f = 0;
        rep(i, 0, 30)
        {
            if (x - sum == (1 << i))
            {
                g1[i]++;
                f = 1;
                break;
            }
            if (sum - x == (1 << i))
            {
                t1[i]++;
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        rep(i, 0, 30) rep(j, 0, 30)
        {
            if (x + (1 << i) - (1 << j) == sum)
            {
                bt[j]++;
                bt[i]--;
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << "No";
            return;
        }
    }
    irep(i, 30, 0)
    {
        bt[i] += g1[i] - t1[i];
        if (!i)
            break;
        if (bt[i] > 0)
        {
            t1[i - 1] -= bt[i];
            bt[i - 1] += bt[i];
            if (t1[i - 1] < 0)
            {
                cout << "No";
                return;
            }
        }
        else
        {
            g1[i - 1] -= -bt[i];
            bt[i - 1] -= -bt[i];
            if (g1[i - 1] < 0)
            {
                cout << "No";
                return;
            }
        }
    }
    if (!bt[0])
        cout << "Yes";
    else
        cout << "No";
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
