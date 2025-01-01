#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;
#define forn(i, e) for (ll i = 1; i <= e; i++)
#define forsn(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 1; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

ll n,m,x;
struct condition{
    ll st,ed,g;
};

condition dk[10];
ll ans = 0;
vector<ll> nums1, curnums;
set<ll> st;

ll multi(ll x, ll y){
    ll res = 1;
    while (y--){
        res *= x;
    }
    return res;
}

bool kt(){
    for (ll i=0; i<m;i++){
        if (__gcd(curnums[dk[i].st], curnums[dk[i].ed]) != dk[i].g) return false;
    }
    return true;
}

void quaylui(){
    for (ll i = 0; i < SZ(nums1); i++){
        curnums.pb(nums1[i]);
        if (curnums.size() == SZ(st)){
            if (kt()) {
                ans+= multi(x,n - SZ(st));
            }
        }
        else quaylui();
        curnums.pop_back();
    }    
}

void solve(){
    cin >> n >> m >> x;
    for (ll i=0;i < m; i++){
        cin >> dk[i].st >> dk[i].ed >> dk[i].g;
    }
    if (m == 0){
        cout << multi(x,n);
        return;
    }
    curnums.clear();
    for (ll i=0; i < m; i++){
        st.insert(dk[i].st);
        st.insert(dk[i].ed);
        if (find(ALL(nums1), dk[i].g) == nums1.end()) nums1.pb(dk[i].g);
        for (ll j = i+1; j < m; j++){
            ll tmp = __gcd(dk[i].g,dk[j].g);
            ll lcm = dk[i].g * dk[j].g / tmp;
            if (find(ALL(nums1), lcm) == nums1.end() && lcm <= x) nums1.pb(lcm);
        }
    }
    for (ll i = 0; i < SZ(nums1); i++){
        for (ll j = nums1[i]; j <= x; j+=nums1[i]){
            if (find(ALL(nums1), j) == nums1.end()) nums1.pb(j);
        }
    }
    for (ll i = 0; i < m; i++){
        dk[i].st = distance(st.begin(), st.find(dk[i].st));
        dk[i].ed = distance(st.begin(), st.find(dk[i].ed));
    }
    quaylui();
    cout << ans;
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
