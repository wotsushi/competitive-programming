#pragma region template 2.4
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_asc = priority_queue<T, vector<T>, greater<T>>;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define FOR(i, a) for (auto &i : a)
#define CH(f, x, y) x = f(x, y)
#define IN(T, x) \
    T x;         \
    cin >> x;
#define AIN(T, a, n) \
    vector<T> a(n);  \
    FOR(i, a)        \
    cin >> i;
#define A2IN(T1, a, T2, b, n) \
    vector<T1> a(n);          \
    vector<T2> b(n);          \
    REP(i, n)                 \
    cin >> a[i] >> b[i];
#define OUT(x) cout << (x) << endl;
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define DUMPA(a)          \
    cout << #a << " = {"; \
    JOUT(ALL(a), ", ", cout) << "}" << endl;

template <typename T>
ostream &JOUT(T s, T e, string sep = " ", ostream &os = cout)
{
    if (s != e)
    {
        os << *s;
        ++s;
    }
    while (s != e)
    {
        os << sep << *s;
        ++s;
    }
    return os;
}

ostream &YES(bool cond, string yes = "Yes", string no = "No", ostream &os = cout)
{
    if (cond)
    {
        os << yes << endl;
    }
    else
    {
        os << no << endl;
    }
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    JOUT(ALL(v), ", ", os) << ']';
    return os;
}

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template
#pragma region rollinghash 1.0
const ll RH_BASE[2] = {1007, 2009};
const ll RH_MOD[2] = {1000000007, 1000000009};

struct rollinghash
{
    vvi h;
    vvi p;

    rollinghash() {}

    rollinghash(const string &s)
    {
        ll n = s.size();
        h.assign(2, {});
        p.assign(2, {});
        REP(k, 2)
        {
            h[k].assign(n + 1, 0);
            p[k].assign(n + 1, 1);
            REP(i, n)
            {
                h[k][i + 1] = (RH_BASE[k] * h[k][i] + s[i]) % RH_MOD[k];
                p[k][i + 1] = (RH_BASE[k] * p[k][i]) % RH_MOD[k];
            }
        }
    }

    ii hash(ll i, ll j)
    {
        ll h0 = (h[0][j] - h[0][i] * p[0][j - i]) % RH_MOD[0];
        ll h1 = (h[1][j] - h[1][i] * p[1][j - i]) % RH_MOD[1];
        return {(h0 + RH_MOD[0]) % RH_MOD[0], (h1 + RH_MOD[1]) % RH_MOD[1]};
    }
};
#pragma endregion rollinghash

int main()
{
    IN(ll, N);
    AIN(ll, a, N);
    AIN(ll, b, N);
    vector<bool> ok(N, true);
    REP(j, 30)
    {
        string A, B, B_inv;
        REP(i, N)
        {
            A.push_back('0' + ((a[i] >> j) & 1));
            B.push_back('0' + ((b[i] >> j) & 1));
            B_inv.push_back('1' - ((b[i] >> j) & 1));
        }
        A += A;
        A.pop_back();
        rollinghash ra(A), rb(B), rb_inv(B_inv);
        auto hb = rb.hash(0, N);
        auto hb_inv = rb_inv.hash(0, N);
        REP(i, N)
        {
            auto ha = ra.hash(i, i + N);
            ok[i] = ok[i] and (ha == hb or ha == hb_inv);
        }
    }
    REP(k, N)
    {
        if (ok[k])
        {
            cout << k << ' ' << (a[k] ^ b[0]) << endl;
        }
    }
}