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

ll T;
ll N;
vi A;
ll M;
vi B;

int main()
{
    cin >> T;
    cin >> N;
    A = vi(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    cin >> M;
    B = vi(M);
    REP(i, M)
    {
        cin >> B[i];
    }

    ll k = 0;
    bool ok = true;
    REP(i, M)
    {
        while (k < N and B[i] - A[k] > T)
        {
            ++k;
        }
        if (k < N and A[k] <= B[i])
        {
            ++k;
        }
        else
        {
            ok = false;
        }
    }
    string ans = ok ? "yes" : "no";
    OUT(ans);
}