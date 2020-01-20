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

ll N, Q;
vi op, a, b;

int main()
{
    cin >> N >> Q;
    op = vi(Q);
    a = vi(Q);
    b = vi(Q);
    REP(i, Q)
    {
        cin >> op[i] >> a[i];
        if (op[i] == 1)
        {
            cin >> b[i];
        }
    }

    vector<string> f = vector<string>(N);
    REP(i, N)
    {
        REP(j, N)
        {
            f[i].push_back('N');
        }
    }
    REP(i, Q)
    {
        ll A = a[i] - 1;
        if (op[i] == 1)
        {
            f[A][b[i] - 1] = 'Y';
        }
        else if (op[i] == 2)
        {
            REP(j, N)
            {
                if (f[j][A] == 'Y')
                {
                    f[A][j] = 'Y';
                }
            }
        }
        else
        {
            vi to_update = vi();
            REP(j, N)
            {
                if (f[A][j] == 'Y')
                {
                    REP(k, N)
                    {
                        if (f[j][k] == 'Y' && k != A)
                        {
                            to_update.push_back(k);
                        }
                    }
                }
            }
            REP(j, to_update.size())
            {
                f[A][to_update[j]] = 'Y';
            }
        }
    }

    REP(i, N)
    {
        OUT(f[i]);
    }
}
