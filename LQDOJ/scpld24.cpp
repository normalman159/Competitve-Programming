#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll n;
const ll LimN = 4e6+5;
ll cnt[LimN];
ll add(ll a, ll b){
    return a*a + b*b;
}
struct node{
    ll fi,se;
};
node t[LimN];
struct node1{
    ll sum,s1,s2,s3,s4;
};
node1 t1[LimN];

void sinh(ll a,ll b, ll c, ll d){
    vector<ll> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(d);
    v.push_back(c);
    sort(v.begin(),v.end());
    for (auto x : v){
        cout << x << " ";
    }
}

bool ch(node1 k){
    ll a = k.s1, b = k.s2,c=k.s3,d=k.s4;
    if (a*a + b*b + c*c + d*d == n) return true;
    return false;
}

void solve(){
    cin >> n;
    ll k = sqrt(n);
    for (ll i=0;i<=LimN-5;i++){
        t[i].fi = t[i].se = -1;
    }
    for (ll a = 1; a<=k;a++){
        for (ll b = a;b<=k;b++){
            ll x = add(a,b);
            cnt[x]++;
            if (a + b > t[x].fi + t[x].se){
                t[x].fi = max(t[x].fi,a);
                t[x].se = max(t[x].se,b);
            }
        }
    }
    //c^2 + d^2 = n-a^2-b^2;
    ll u = 1;
    bool flag = false;
    for (ll c=1;c<=k;c++){
        for (ll d = c;d<=k;d++){
            ll x = add(c,d);
            if (n - x>=0 && cnt[n-x]>=1){
                ll sum = t[n-x].fi + t[n-x].se + d + c;
                t1[u] = {sum,t[n-x].fi, t[n-x].se, c, d};
                u++;
                flag = true;
            }
        }
    }
    if (flag == false){
        cout << -1;
        return;
    }   
    ll mx = -INF, checki;
    for (ll i =1;i<u;i++){
        if (t1[i].sum > mx && ch(t1[i])){
            mx = max(mx,t1[i].sum);
            checki = i;
        }
        // cout << i <<" "<<t1[i].sum << " " << t1[i].s1 << " " << t1[i].s2 << " " << t1[i].s3 << " " << t1[i].s4 << ln;
    }
    // cout << checki << ln;
    sinh(t1[checki].s1,t1[checki].s2,t1[checki].s3,t1[checki].s4);    
}
int main()
{
    fast_cin();
    solve();
    return 0;
}