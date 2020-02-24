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

ll N;
vi a;

int main()
{
    cin >> N;
    a = vi(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    SORT(a);
    set<ll> s;
    ll ans = 0;
    REP(i, N)
    {
        ll x = a[i];
        ll c = 1;
        while (x % 2 == 0)
        {
            if (s.find(x / 2) != s.end())
            {
                c = 0;
            }
            x /= 2;
        }
        ans += c;
        s.insert(a[i]);
    }
    OUT(ans);
}