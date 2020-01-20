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

typedef vector<vi> vv;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll N, M;
vi K;
vv A;

int main()
{
    cin >> N >> M;
    K = vi(N);
    A = vv(N);
    REP(i, N)
    {
        cin >> K[i];
        A[i] = vi(K[i]);
        REP(j, K[i])
        {
            cin >> A[i][j];
        }
    }

    vi cnt = vi(M);
    REP(i, N)
    {
        REP(j, K[i])
        {
            ++cnt[A[i][j] - 1];
        }
    }
    ll ans = 0;
    REP(i, M)
    {
        if (cnt[i] == N)
        {
            ++ans;
        }
    }

    OUT(ans);
}