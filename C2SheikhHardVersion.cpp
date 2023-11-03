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

int a[100001], xx[100001], nxt[100001], prv[100001];
ll s[100001];

void solve()
{
    int n, q;
    cin >> n >> q;
    s[0] = xx[0] = 0;
    rep(i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        xx[i] = xx[i - 1] ^ a[i];
    }
    nxt[n] = n + 1;
    irep(i, n - 1, 1)
    {
        if (a[i + 1])
            nxt[i] = i + 1;
        else
            nxt[i] = nxt[i + 1];
    }
    prv[1] = 0;
    rep(i, 2, n)
    {
        if (a[i - 1])
            prv[i] = i - 1;
        else
            prv[i] = prv[i - 1];
    }
    while (q--)
    {
        int L, R, l, r;
        cin >> L >> R;
        l = L, r = R;
        if (!a[l])
            l = nxt[l];
        if (!a[r])
            r = prv[r];
        if (l > r)
        {
            cout << L << " " << L << "\n";
            continue;
        }
        int al = l, ar = r;
        ll v = s[r] - s[l - 1] - (xx[r] ^ xx[l - 1]);
        int left = l, right = r;
        rep(i, 0, 30)
        {
            if (left > r)
                break;
            right = r;
            rep(j, 0, 30)
            {
                if (left > right)
                    break;
                if (s[right] - s[left - 1] - (xx[right]^xx[left - 1]) < v)
                    break;
                if (ar - al + 1 > right - left + 1)
                    ar = right, al = left;
                right = prv[right];
            }
            left = nxt[left];
        }
        cout << al << " " << ar << "\n";
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
        cout << "\n";
    }
}
