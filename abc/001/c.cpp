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

const string DIR[] = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
const ll P[] = {0, 3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327, INF};

ll Deg;
ll Dis;

int main()
{
    cin >> Deg >> Dis;

    ll t = 10 * Dis / 6;
    ll w = t % 10 >= 5 ? t / 10 + 1 : t / 10;
    ll W = upper_bound(P, P + 13, w) - (P + 1);
    string Dir;
    ll deg = 10 * Deg;
    if (W == 0)
    {
        Dir = "C";
    }
    else if (deg < 1125)
    {
        Dir = "N";
    }
    else
    {
        Dir = DIR[(deg - 1125) / 2250];
    }

    cout << Dir << " " << W << endl;
}