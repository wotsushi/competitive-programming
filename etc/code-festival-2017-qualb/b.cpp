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
vi D;
ll M;
vi T;

int main()
{
    cin >> N;
    D = vi(N);
    REP(i, N)
    {
        cin >> D[i];
    }
    cin >> M;
    T = vi(M);
    REP(i, M)
    {
        cin >> T[i];
    }

    map<ll, ll> cnt = map<ll, ll>();
    REP(i, N)
    {
        if (cnt.count(D[i]))
        {
            ++cnt[D[i]];
        }
        else
        {
            cnt[D[i]] = 1;
        }
    }
    bool ok = true;
    REP(i, M)
    {
        if (cnt.count(T[i]))
        {
            --cnt[T[i]];
            ok &= (cnt[T[i]] >= 0);
        }
        else
        {
            ok = false;
        }
    }
    string ans = ok ? "YES" : "NO";

    OUT(ans);
}