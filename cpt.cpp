#include <bits/stdc++.h>
#define bool int
using namespace std;
using ll=long long;
#define sign(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> bool ckmin(T &a, T b) {return b<a ? a=b, true : false;}
template <typename T> bool ckmax(T &a, T b) {return b>a ? a=b, true : false;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
void yn(bool ans) {puts(ans?"yes":"no");}
ll cdiv(ll a, ll b) {return a/b+(sign(a)/sign(b)==1 && a%b);}
ll logfl(ll base, ll x) {assert(base>1);ll res=0,val=1;while (val*base<=x) {val*=base;res++;}return res;}
ll sqrtfl(ll x) {ll rt=sqrtl(x);if (rt*rt>x) rt--;if ((rt+1)*(rt+1)<=x) rt++;return rt;}
int popcount(ll x) {int cnt=0;while (x) {cnt+=x&1;x/=2;}return cnt;}
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2()=default;vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}void assign(int n, int m, T val = T()) {this->vector<vector<T>>::assign(n, vector<T>(m, val));}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3()=default;vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}void assign(int n, int m, int k, T val = T()) {this->vector<vector<vector<T>>>::assign(n, vector<vector<T>>(m, vector<T>(k, val)));}};
template <typename T> void readv(vec<T> &v, int n) {v.assign(n+1,0);for (int i=1; i<=n; ++i) cin>>v[i];}
void readbinstr(vec<int> &v, int n) {v.assign(n+1,0);for (int i=1; i<=n; ++i) {char c; cin>>c;v[i]=c-'0';}}

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
