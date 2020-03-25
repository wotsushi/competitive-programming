#pragma region template
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

template <typename T>
struct BinaryIndexedTree
{
    vector<T> data;

    BinaryIndexedTree(int sz)
    {
        data.assign(++sz, 0);
    }

    T sum(int k)
    {
        T ret = 0;
        for (++k; k > 0; k -= k & -k)
            ret += data[k];
        return (ret);
    }

    void add(int k, T x)
    {
        for (++k; k < data.size(); k += k & -k)
            data[k] += x;
    }
};

int main()
{
    ll Q;
    cin >> Q;
    vi T(Q), X(Q);
    REP(i, Q)
    {
        cin >> T[i] >> X[i];
    }

    auto bit = BinaryIndexedTree<ll>(200001);
    REP(i, Q)
    {
        if (T[i] == 1)
        {
            bit.add(X[i], 1);
        }
        else
        {
            ll ok = 200000;
            ll ng = 0;
            while (abs(ng - ok) > 1)
            {
                ll mid = (ok + ng) / 2;
                if (bit.sum(mid) >= X[i])
                {
                    ok = mid;
                }
                else
                {
                    ng = mid;
                }
            }
            bit.add(ok, -1);
            OUT(ok);
        }
    }
}
#pragma endregion template