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

const string A = "atcoder";
string S;
string T;

int main()
{
    cin >> S;
    cin >> T;

    bool w = true;

    REP(i, S.size())
    {
        w &= S[i] == T[i] or A.find(S[i]) != string::npos and T[i] == '@' or A.find(T[i]) != string::npos and S[i] == '@';
    }

    string ans = w ? "You can win" : "You will lose";

    OUT(ans);
}