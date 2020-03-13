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

ll N, W;
vi v, w;
int main()
{
    cin >> N >> W;
    v = vi(N);
    w = vi(N);
    REP(i, N)
    {
        cin >> v[i] >> w[i];
    }

    ll A = *max_element(ALL(w));
    ll B = *max_element(ALL(v));
    ll ans;
    if (N <= 30)
    {
        ll m = N / 2;
        vector<pair<ll, ll>> wv;
        REP(p, 1 << m)
        {
            ll a = 0;
            ll b = 0;
            REP(i, m)
            {
                a += ((p >> i) & 1) * w[i];
                b += ((p >> i) & 1) * v[i];
            }
            if (a <= W)
            {
                wv.push_back(make_pair(a, b));
            }
        }
        SORT(wv);
        map<ll, ll> opt;
        opt[0] = 0;
        ll v_max = 0;
        REP(i, wv.size())
        {
            if (wv[i].second > v_max)
            {
                opt[-wv[i].first] = wv[i].second;
                v_max = wv[i].second;
            }
        }
        ans = 0;
        REP(p, 1 << (N - m))
        {
            ll a = 0;
            ll b = 0;
            REP(i, N - m)
            {
                a += ((p >> i) & 1) * w[m + i];
                b += ((p >> i) & 1) * v[m + i];
            }
            if (a <= W)
            {
                ans = max(ans, (*opt.lower_bound(-(W - a))).second + b);
            }
        }
    }
    else if (A <= 1000)
    {
        vi dp(N * A + 1);
        REP(i, N)
        {
            for (ll j = N * A; j >= w[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        ans = dp[min(W, N * A + 1)];
    }
    else
    {
        vi dp(N * B + 1, INF);
        dp[0] = 0;
        REP(i, N)
        {
            for (ll j = N * B; j >= v[i]; --j)
            {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        for (ll j = N * B; j >= 0; --j)
        {
            if (dp[j] <= W)
            {
                ans = j;
                break;
            }
        }
    }

    OUT(ans);
}