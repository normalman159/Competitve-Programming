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


void sub1(ll n,ll q, vector<ll> &a, vector<ll> &b, vector<ll> &k){
    for (ll i=1;i<=q;i++){
        ll curr_p = 0;
        ll curr = k[i];
        if (curr < a[1]){
            cout << 0 << ln;
            continue;
        }
        for(ll j = 1; j<=n;j++){
            if (curr >= a[j]){
                curr-=b[j];
                curr_p +=a[j];
            }
            else{
                break;
            }
        }
        cout << curr_p << ln;
    }
}

void sub2(ll n,ll q, vector<ll> &a, vector<ll> &b, vector<ll> &k){
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for (ll i=1;i<=n;i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    for (ll i=1;i<=q;i++){
        ll curr = k[i];
        if (curr < a[1]) {
            cout << 0 << ln;
            continue;
        }
        ll z = upper_bound(a.begin(),a.end(), curr) - a.begin();
        z--;
        cout << prefix[z] - prefix[0] << ln;
    }
}

void sub3(ll n,ll q, vector<ll> &a, vector<ll> &b, vector<ll> &k){
    a.pb(INF);
    forsn(i,1,n){
        b[i] = abs(b[i]);
    }
    vector<ll> prefix_b(n+1), prefix_a(n+1),prefix_tmp(n+1);
    prefix_b[0] = 0;
    prefix_a[0] = 0;
    for (ll i=1;i<=n;i++){
        prefix_b[i] = prefix_b[i-1] + b[i];
        prefix_a[i] = prefix_a[i-1] + a[i];
    }   
    for (ll i=1;i<=n;i++){
        prefix_tmp[i] = a[i+1] - prefix_b[i];
    }
    for (ll i=1;i<=q;i++){
        ll curr = k[i];
        if (curr < a[1]) {
            cout << 0 << ln;
            continue;
        }
        ll z = lower_bound(prefix_tmp.begin()+1,prefix_tmp.end(), curr) - prefix_tmp.begin();
        if (curr+ prefix_b[z] == a[z+1]){
            z++;
        }
        cout << prefix_a[z] << ln;
    }
}

void solve(){
    ll n,q; cin >> n >> q;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> k(q+1);
    bool flag_sub2 = true;
    bool flag_sub3 = true;
    for (ll i=1;i<=n;i++){
         cin >> a[i];
    }
    forsn(i,1,n){
        cin >> b[i];    
        if (b[i]!=0) flag_sub2 = false;
        if (b[i]>=0) flag_sub3 = false;
    } 
    forsn(i,1,q) cin >> k[i];
    // sub1(n,q,a,b,k);
    // cout << ln;
    // sub3(n,q,a,b,k);
    if (n <= 5e3 && q <= 5e3){
        sub1(n,q,a,b,k);
    }
    else if (flag_sub2 == true){
        sub2(n,q,a,b,k);
    }
    else if (flag_sub3 == true){
        sub3(n,q,a,b,k);
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}