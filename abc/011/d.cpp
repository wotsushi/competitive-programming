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

ll N, D;
ll X, Y;

double f(ll n, ll m)
{
    double res = 1;
    REP(i, m)
    {
        res *= n - i;
        res /= 4 * (m - i);
    }
    return res;
}

int main()
{
    cin >> N >> D;
    cin >> X >> Y;

    double ans = 0;
    if (X % D == 0 and Y % D == 0)
    {
        ll x = X / D;
        ll y = Y / D;
        REP(i, N + 1)
        {
            if (i >= x)
            {
                ll a = i - x;
                ll r = N - i - a;
                if (abs(y) <= r and r % 2 == abs(y % 2))
                {
                    ll b = (r + y) / 2;
                    ll c = r - b;
                    double p = f(N, i) * f(N - i, a) * f(r, b);
                    REP(i, c)
                    {
                        p /= 4;
                    }
                    ans += p;
                }
            }
        }
    }

    cout << fixed << setprecision(15);
    OUT(ans);
}