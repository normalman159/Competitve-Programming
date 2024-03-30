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
 

 
void solve(){
    double n; cin >> n;
    ll n1 = (ll)n;
    vector<ll> v(n+1);
    ll MA = -INF, MI = INF;
    map<ll,ll> count_app;
    double sum = 0;
    for (ll i=1;i<=n;i++){
        cin >> v[i];
        MA = max(MA,v[i]);
        MI = min(MI,v[i]);
        sum+=v[i];
        count_app[v[i]]++;
    }
    double avg = sum/n;
    ll mode, track_app = -INF;
    auto track_id = count_app.begin();
    for (auto it = count_app.begin(); it!=count_app.end();++it){
        if (it->second > track_app){
            track_app = it->second;
            track_id = it;
        }
    }
    mode = track_id->first;
    ll median;
    vector<ll> v1 = v;
    sort(v.begin()+1, v.end());
    if (n1%2!=0) median = v[n1/2+1];
    else median = v[(n1/2) + 1];
    double sigma;
    double up = 0;
    for (ll i=1;i<=n1;i++){
        up+=(v1[i] - avg)*(v1[i] - avg);
    }
    sigma = sqrt(up/n);



    cout << MA << ln;
    cout << MI << ln;
    cout << fixed << setprecision(6) << avg << ln;
    cout << median << ln;
    cout << mode << ln;
    cout << fixed << setprecision(6) << sigma << ln;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}