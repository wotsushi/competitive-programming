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
vi C;

int main()
{
    cin >> N;
    C = vi(N);
    REP(i, N)
    {
        cin >> C[i];
    }

    double f = 1;
    for (ll i = 1; i <= N; ++i)
    {
        f *= i;
    }
    double ans = 0;
    REP(i, N)
    {
        ll k = -1;
        REP(j, N)
        {
            if (C[i] % C[j] == 0)
            {
                ++k;
            }
        }
        ans += k % 2 == 0 ? f * (k + 2) / (2 * (k + 1)) : f / 2;
    }
    ans /= f;

    cout << fixed << setprecision(15);
    OUT(ans)
}