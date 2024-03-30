#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;
#define ln "\n"
const ll LimN = 1e5 + 5;
ll n,a[LimN];

struct Node{
    ll fi, ed,id;
};
Node t[LimN];

ll tachcuoi(ll x){
    return x%10;
}

ll tachdau(ll x){
    string s = to_string(x);
    ll res = s[0] - '0';
    return res;
}

bool cmp(Node a, Node b){
    if (a.fi == b.fi){
        return a.ed > b.ed;
    }
    return a.fi > b.fi;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    string res;
    for (ll i=1;i<=n;i++){
        ll x = a[i];
        t[i].fi = tachdau(x);
        t[i].ed = tachcuoi(x);
        t[i].id  = i;
    }
    sort(t+1,t+1+n,cmp);
    for (ll i=1;i<=n;i++){
        ll x = t[i].id;
        string st = to_string(a[x]);
        res+=st;
    }
    cout << res;
    return 0;
}
