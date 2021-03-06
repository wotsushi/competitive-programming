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

#define CEIL(a, b) ((a) + (b)-1) / (b)

ll N;
vi C, S, F;

int main()
{
    cin >> N;
    C = vi(N - 1);
    S = vi(N - 1);
    F = vi(N - 1);
    REP(i, N - 1)
    {
        cin >> C[i] >> S[i] >> F[i];
    }

    REP(i, N)
    {
        ll ans = 0;
        if (i < N - 1)
        {
            ans = 0;
            for (ll j = i; j < N - 1; ++j)
            {
                ans = S[j] + CEIL(max(0LL, ans - S[j]), F[j]) * F[j] + C[j];
            }
        }
        OUT(ans);
    }
}