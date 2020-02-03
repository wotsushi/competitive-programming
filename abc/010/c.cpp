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

ll txa, tya, txb, tyb, T, V;
ll n;
vi x, y;

int main()
{
    cin >> txa >> tya >> txb >> tyb >> T >> V;
    cin >> n;
    x = vi(n);
    y = vi(n);
    REP(i, n)
    {
        cin >> x[i] >> y[i];
    }

    string ans = "NO";
    REP(i, n)
    {
        if (abs(sqrt(pow(x[i] - txa, 2) + pow(y[i] - tya, 2)) + sqrt(pow(x[i] - txb, 2) + pow(y[i] - tyb, 2)) - V * T <= 1e-5))
        {
            ans = "YES";
        }
    }
    OUT(ans);
}