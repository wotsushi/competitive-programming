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

ll N, M, D;
vi A;

int main()
{
    cin >> N >> M >> D;
    A = vi(M);
    REP(i, M)
    {
        cin >> A[i];
    }

    vi p = vi(N);
    REP(i, N)
    {
        p[i] = i;
    }
    REP(i, M)
    {
        swap(p[A[i] - 1], p[A[i]]);
    }
    vi q = vi(N);
    REP(i, N)
    {
        q[p[i]] = i;
    }

    vector<bool> used = vector<bool>(N, false);
    vi ans = vi(N);
    REP(i, N)
    {
        if (not used[i])
        {
            ll j = i;
            vi r = vi();
            while (not used[j])
            {
                used[j] = true;
                r.push_back(j);
                j = q[j];
            }
            REP(k, r.size())
            {
                // 1-indexedに変換
                ans[r[k]] = r[(k + D) % r.size()] + 1;
            }
        }
    }

    REP(i, N)
    {
        OUT(ans[i]);
    }
}