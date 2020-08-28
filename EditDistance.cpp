#include<bits/stdc++.h>
using namespace std ;
 
/*                        [Template]                        */
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
int mod = (int)1e9 + 7 ;
/************************************************************/


signed main(){
	string a, b ;
	cin >> a >> b ;
	int lena = a.size(), lenb = b.size() ;
	let dp = matrix<int>( lena + 1, lenb + 1, 0 ) ;
	for( int i = 0 ; i <= lenb ; i++ ){
		dp[0][i] = i ;
	}
	for( int j = 0 ; j <= lena ; j++ ){
		dp[j][0] = j ;
	}
	for( int i = 1 ; i <= lena ; i++ ){
		for( int j = 1 ; j <= lenb ; j++ ){
			if( a[i-1] == b[j-1] ){
				dp[i][j] = dp[i-1][j-1] ;
			}
			else {
				dp[i][j] = 1 + min({
					dp[i-1][j-1], // replacing
					dp[i-1][j],    // deleting
					dp[i][j-1]          // inserting
				}) ; 
			}
		}
	}
	cout << dp[lena][lenb] << endl ;
	return 0 ;
}  
