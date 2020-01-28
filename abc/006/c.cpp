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

ll N, M;

int main()
{
    cin >> N >> M;

    ll a = -1;
    ll b = -1;
    ll c = -1;
    REP(i, M / 3 + 1)
    {
        ll m = M - 3 * i;
        if (m % 2 == 0)
        {
            ll x = 2 * (N - i) - m / 2;
            ll y = i;
            ll z = m / 2 - (N - i);
            if (x >= 0 and y >= 0 and z >= 0 and x + y + z == N)
            {
                a = x;
                b = y;
                c = z;
            }
        }
    }

    cout << a << " " << b << " " << c << endl;
}