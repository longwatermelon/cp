#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
template <typename T> T cdiv(T a, T b) {return a/b+(a/b>=0 && a%b!=0);}
template <typename T> T fdiv(T a, T b) {return a/b-(a/b<0 && a%b!=0);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator<(pt_t pt2)const{return PTX==pt2.PTX?PTY<pt2.PTY:PTX<pt2.PTX;}bool operator==(pt_t pt2)const{return PTX==pt2.PTX&&PTY==pt2.PTY;}bool operator>(pt_t pt2)const{return !(*this<pt2||*this==pt2);}};
template <typename T> vector<int> genord(int len, T cmp) {vector<int> ord(len+1);for(int i=1;i<=len;++i)ord[i]=i;sort(begin(ord)+1,end(ord),cmp);return ord;}

void solve() {
}

int main() {
}
