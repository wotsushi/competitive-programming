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

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

typedef tuple<ll, ll, ll> iii;

int main()
{
    ll N, M;
    cin >> N >> M;
    vi a(M), b(M), y(M);
    REP(i, M)
    {
        cin >> a[i] >> b[i] >> y[i];
    }
    ll Q;
    cin >> Q;
    vi u(Q), w(Q);
    REP(i, Q)
    {
        cin >> u[i] >> w[i];
    }
    vector<iii> roads(M);
    REP(i, M)
    {
        roads[i] = iii(y[i], a[i], b[i]);
    }
    RSORT(roads);
    vector<iii> q(Q);
    REP(i, Q)
    {
        q[i] = iii(w[i], u[i], i);
    }
    RSORT(q);
    UnionFind uft(N + 1);
    ll j = 0;
    vi ans(Q);
    REP(i, Q)
    {
        while (j < M and get<0>(roads[j]) > get<0>(q[i]))
        {
            uft.unite(get<1>(roads[j]), get<2>(roads[j]));
            ++j;
        }
        ans[get<2>(q[i])] = uft.size(get<1>(q[i]));
    }
    REP(i, Q)
    {
        OUT(ans[i]);
    }
}