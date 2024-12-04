#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
void yn(bool ans) {puts(ans?"yes":"no");}
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2()=default;vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3()=default;vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}};
template <typename T> void reset(T *arr, int l, int r, T val) {fill(arr+l,arr+r+1,val);}

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
