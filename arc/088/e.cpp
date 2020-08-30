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
#pragma region bit 1.0
template <typename T>
struct bit
{
    ll n;
    vector<T> a;

    bit() {}

    bit(ll n) : n(n)
    {
        a.assign(n + 1, 0);
    }

    void add(ll i, T x)
    {
        ++i;
        while (i <= n)
        {
            a[i] += x;
            i += i & -i;
        }
    }

    T sum(ll i)
    {
        T s = 0;
        while (i > 0)
        {
            s += a[i];
            i -= i & -i;
        }
        return s;
    }
};
#pragma endregion bit

int main()
{
    IN(string, S);
    ll N = S.size();

    vector<deque<ll>> I(26);
    REP(i, N)
    {
        I[S[i] - 'a'].push_back(i);
    }
    vector<bool> used(N);
    bit<ll> bit(N);
    ll ans = 0;
    ll mid = N - 1;
    REP(i, N)
    {
        if (not used[i])
        {
            ll c = S[i] - 'a';
            ll j = I[c].back();
            if (i == j)
            {
                mid = i;
                break;
            }
            I[c].pop_front();
            I[c].pop_back();
            ans += N - 1 - j - (bit.sum(N) - bit.sum(j));
            used[i] = true;
            used[j] = true;
            bit.add(i, 1);
            bit.add(j, 1);
        }
    }
    for (ll i = N - 1; i > mid; --i)
    {
        if (not used[i])
        {
            ll c = S[i] - 'a';
            ll j = I[c].front();
            if (i == j)
            {
                OUT(-1);
                return 0;
            }
            I[c].pop_front();
            I[c].pop_back();
            ans += j - bit.sum(j);
            used[i] = true;
            used[j] = true;
            bit.add(i, 1);
            bit.add(j, 1);
        }
    }
    OUT(ans);
}