#include<bits/stdc++.h>
using namespace std ;
 
 
// START
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
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
 
 
int main(){
	int N ; cin >> N ;
	vector<int> dp( N + 1, 0 ) ;
	dp[0] = 1 ;
	for( int i = 1 ; i <= N ; i++ ){
		for( int j = 1 ; j <= 6 ; j++ ){
			if( j <= i )
			dp[i] = ( dp[i] + 0LL + dp[i - j] ) % mod ;
		}
	}
	cout << dp[N] << endl ;
}
