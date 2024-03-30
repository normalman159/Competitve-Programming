#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 
void sub1(ll n, ll m, vector<ll> &stair, vector<ll> &people){
    for (ll i=1;i<=m;i++){
        ll curr = people[i];
        ll res = 0;
        for (ll j = 1;j<=n;j++){
            if (stair[j]<=curr) res++;
            else break;
        }
        cout << res << ln;
    }
}

void sub2(ll n, ll m, vector<ll> &stair, vector<ll> &people){
    for (ll i=1;i<=m;i++){
        ll curr = people[i];
        ll z = upper_bound(stair.begin(), stair.end(), curr) - stair.begin();
        z--;
        cout << z << ln;
    }
}

void sub3(ll n, ll m, vector<ll> &stair, vector<ll> &people){
    vector<ll>prefix_max(n+1);
    prefix_max[1] = stair[1];
    forsn(i,2,n){
        prefix_max[i] = max(prefix_max[i-1],stair[i]);
    }
    forsn(i,1,m){
        ll curr = people[i];
        ll z = upper_bound(ALL(prefix_max), curr) - prefix_max.begin();
        z--;
        cout << z << ln;
    }
}

void solve(){
    ll n,m; cin >> n >> m;
    bool flag_sub2 = true;
    vector<ll> stair(n+1), people(m+1);
    forsn(i,1,n){
        cin >> stair[i];
    } 
    forsn(i,1,m) cin >> people[i];
    stair.pb(INF);
    forsn(i,1,n){
        if ((stair[i]>stair[i+1])){
            flag_sub2 = false;
            break;
        } 
    }
    if (m <= 100){
        sub1(n,m,stair,people);
    }
    else if (flag_sub2==true){
        sub2(n,m,stair,people);
    }
    else{
        sub3(n,m,stair,people);
    }
}
 
 
int main()
{
    // freopen("CLIMBSTAIR.INP","r",stdin);
    // freopen("CLIMBSTAIR.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}