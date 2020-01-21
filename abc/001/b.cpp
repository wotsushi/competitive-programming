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

ll m;

int main()
{
    cin >> m;

    ll ans;
    if (m < 100)
    {
        ans = 0;
    }
    else if (m <= 5000)
    {
        ans = m / 100;
    }
    else if (m <= 30000)
    {
        ans = m / 1000 + 50;
    }
    else if (m <= 70000)
    {
        ans = (m / 1000 - 30) / 5 + 80;
    }
    else
    {
        ans = 89;
    }

    cout << setfill('0') << right << setw(2) << ans << endl;
}