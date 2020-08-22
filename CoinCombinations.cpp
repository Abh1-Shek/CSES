#include<bits/stdc++.h>
using namespace std ;
 
 
// START
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
// END
const int mod = (int)1e9 + 7 ;
 
signed main() {
	int n, x ; cin >> n >> x;
	vector<int> c(n);
	for(let &ci of c) cin >> ci;
	vector<int> dp( x + 1, 0 ) ;
	dp[0] = 1 ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 1 ; j <= x ; j++ ){
			if( j - c[i] >= 0 )
			dp[j] = (dp[j] + dp[j-c[i]])%mod ; 
		}
	}
	cout << dp[x] << endl; 
}