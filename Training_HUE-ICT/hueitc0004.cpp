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
 
struct Node{
    ll left,right,id;
};

bool cmp_left(Node a,Node b){
    return a.left > b.left;
}
bool cmp_right(Node a,Node b){
    return a.right > b.right;
}

void solve(){
    ll n; cin >> n;
    vector<Node> v;
    for (ll i=1;i<=n;i++){
        ll x1,x2; cin >> x1 >> x2;
        v.pb({x1,x2,i});
    }
    vector<Node> v1 =v;
    sort(ALL(v), cmp_left);
    sort(ALL(v1), cmp_right);
    if (v[0].left > v1[0].right){
        if (!(v[0].id == v1[0].id)){
            cout << v[0].left + v1[0].right;
            return;
        }
        cout << v[0].left + v1[1].right;
        return;
    }
    else{
        if (!(v[0].id == v1[0].id)){
            cout << v[0].left + v1[0].right;
            return;
        }
        cout << v[1].left + v1[0].right;
        return;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}