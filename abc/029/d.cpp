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

int main()
{
    ll N;
    cin >> N;

    string S = to_string(N);
    ll ans = 0;
    while (!S.empty())
    {
        ll k = S.size();
        if (S[0] >= '2')
        {
            ans += pow(10, k - 1) + (k - 1) * (S[0] - '0') * pow(10, k - 2);
        }
        else if (S[0] == '1')
        {
            if (k == 1)
            {
                ++ans;
            }
            else
            {
                ans += stoll(S.substr(1)) + 1 + (k - 1) * pow(10, k - 2);
            }
        }
        S.erase(S.begin());
    }
    OUT(ans);
}