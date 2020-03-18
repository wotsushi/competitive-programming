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

typedef tuple<ll, ll, ll> iii;

class mint
{
public:
    ll a;

    mint(const ll x = 0) : a(x % MOD) {}
    ll &value() { return a; }
    mint pow(ll rhs)
    {
        ll exp = rhs;
        mint res = mint(1);
        mint p = mint(a);
        while (exp)
        {
            if (exp & 1)
            {
                res *= p;
            }
            exp >>= 1;
            p *= p;
        }
        return res;
    }
    mint pow(mint rhs)
    {
        return pow(rhs.a);
    }
    mint &operator+=(ll rhs)
    {
        a += rhs;
        if (a >= MOD)
        {
            a -= MOD;
        }
        return *this;
    }
    mint &operator+=(mint rhs)
    {
        *this += rhs.a;
        return *this;
    }
    mint &operator-=(ll rhs)
    {
        if (a < rhs)
        {
            a += MOD;
        }
        a -= rhs;
        return *this;
    }
    mint &operator-=(mint rhs)
    {
        *this -= rhs.a;
        return *this;
    }
    mint &operator*=(ll rhs)
    {
        a = a * rhs % MOD;
        return *this;
    }
    mint &operator*=(mint rhs)
    {
        *this *= rhs.a;
        return *this;
    }
    mint &operator/=(ll rhs)
    {
        *this *= mint(rhs).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(mint rhs)
    {
        *this /= rhs.a;
        return *this;
    }
};

mint operator+(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const ll &lhs, const mint &rhs)
{
    return mint(lhs) += rhs;
}
mint operator-(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const ll &lhs, const mint &rhs)
{
    return mint(lhs) -= rhs;
}
mint operator*(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const ll &lhs, const mint &rhs)
{
    return mint(lhs) *= rhs;
}
mint operator/(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const ll &lhs, const mint &rhs)
{
    return mint(lhs) /= rhs;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<vi> a(H, vi(W));
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> a[i][j];
        }
    }

    priority_queue<iii> q;
    REP(i, H)
    {
        REP(j, W)
        {
            q.push(iii(a[i][j], i, j));
        }
    }
    vector<vector<mint>> dp(H, vector<mint>(W, mint(0)));
    vi DI = {1, 0, -1, 0};
    vi DJ = {0, 1, 0, -1};
    while (!q.empty())
    {
        iii t = q.top();
        q.pop();
        ll x = get<0>(t);
        ll i = get<1>(t);
        ll j = get<2>(t);
        dp[i][j] = mint(1);
        REP(k, 4)
        {
            ll u = i + DI[k];
            ll v = j + DJ[k];
            if (0 <= u and u < H and 0 <= v and v < W and a[u][v] > x)
            {
                dp[i][j] += dp[u][v];
            }
        }
    }
    mint ans = mint(0);
    REP(i, H)
    {
        REP(j, W)
        {
            ans += dp[i][j];
        }
    }

    OUT(ans.a);
}