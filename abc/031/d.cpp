#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll K, N;
vector<string> v, w;
vi a;
vector<string> s;

bool f(ll k)
{
    if (k == K)
    {
        s = vector<string>(K + 1);
        REP(i, N)
        {
            ll l = 0;
            REP(j, v[i].size())
            {
                ll x = v[i][j] - '0';
                if (l + a[x] > w[i].size())
                {
                    return false;
                }
                if (s[x] == "")
                {
                    s[x] = w[i].substr(l, a[x]);
                }
                else if (s[x] != w[i].substr(l, a[x]))
                {
                    return false;
                }
                l += a[x];
            }
            if (l != w[i].size())
            {
                return false;
            }
        }
        return true;
    }
    for (ll i = 1; i <= 3; ++i)
    {
        a[k + 1] = i;
        if (f(k + 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> K >> N;
    v = vector<string>(N);
    w = vector<string>(N);
    REP(i, N)
    {
        cin >> v[i] >> w[i];
    }

    a = vi(K + 1);
    f(0);

    for (ll i = 1; i <= K; ++i)
    {
        OUT(s[i]);
    }
}