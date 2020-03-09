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

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;

    double ok = 1e9;
    double ng = 0;
    while (ok - ng > 1e-12)
    {
        double mid = (ok + ng) / 2;
        if (A * mid + B * sin(C * mid * M_PI) - 100 >= 0)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    double ans = ok;

    cout << fixed << setprecision(15) << ans << endl;
}