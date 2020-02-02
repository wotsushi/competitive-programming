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
string S;

int main()
{
    cin >> N >> K;
    cin >> S;

    string U = S;
    SORT(U);
    vector<bool> useable = vector<bool>(N, true);
    string T = "";
    REP(r, N)
    {
        string t = T;
        REP(i, N)
        {
            if (useable[i])
            {
                t = T + U[i];
                map<char, ll> c;
                ll k = 0;
                REP(j, r + 1)
                {
                    if (t[j] != S[j])
                    {
                        k += 2;
                        ++c[t[j]];
                    }
                }
                REP(j, r + 1)
                {
                    if (t[j] != S[j] and c[S[j]] > 0)
                    {
                        --c[S[j]];
                        --k;
                    }
                }
                if (k <= K)
                {
                    T = t;
                    useable[i] = false;
                    break;
                }
            }
        }
    }

    OUT(T);
}