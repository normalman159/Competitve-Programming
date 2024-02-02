#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll n, award[MXN], start[MXN],ed[MXN];
ll dp[MXN];
vector<pair<ll,ll>> finish[MXN];
unordered_map<ll,ll> mp;
void solve(){
    cin >> n;
    set<ll> st;
    for (ll i=1;i<=n;i++){
        cin >> start[i] >> ed[i] >> award[i];
        ed[i]++;
        st.insert(start[i]); st.insert(ed[i]);
    }   
    ll max_num = st.size();
    for (auto x : st){
        if (mp[x] == 0){
            mp[x] = mp.size();
        }
    }
    for (ll i=1;i<=max_num;i++){
        finish[mp[ed[i]]].push_back({mp[start[i]], award[i]});
    }
    for (ll i=1;i<=max_num;i++){
        if (i!=1){
            dp[i] = dp[i-1];
        }
        for (auto [st,re] : finish[i]){
            dp[i] = max(dp[i], dp[st] + re);
        }
    }
    cout << dp[max_num];
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}