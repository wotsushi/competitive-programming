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

ll N, K;
vi R;

int main()
{
    cin >> N >> K;
    R = vi(N);
    REP(i, N) { cin >> R[i]; }

    SORT(R);
    double ans = 0;
    REP(i, K)
    {
        ans = (ans + R[N - K + i]) / 2;
    }

    cout << fixed << setprecision(15);
    OUT(ans);
}