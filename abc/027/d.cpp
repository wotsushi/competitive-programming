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

int main()
{
    string S;
    cin >> S;
    ll N = S.size();
    vi D;
    ll d = 0;
    for (ll i = N - 1; i >= 0; --i)
    {
        if (S[i] == 'M')
        {
            D.push_back(d);
        }
        else if (S[i] == '+')
        {
            ++d;
        }
        else
        {
            --d;
        }
    }
    SORT(D);
    ll ans = 0;
    REP(i, D.size())
    {
        if (i < D.size() / 2)
        {
            ans += -D[i];
        }
        else
        {
            ans += D[i];
        }
    }

    OUT(ans);
}