/*
ID: vitsali1
LANG: C++
TASK: dualpal
*/
#include <cstdio>
#include <string> 

using namespace std;

bool check( string str ) {
    int i, j;
    for ( i = 0, j = str.length() - 1; i < j; ++i, --j ) {
        if ( str[ i ] != str[ j ] ) {
            return false;
        }
    }
    return true;
}

string convert( int num, int s ) {
    string str;
    while ( num > 0 ) {
        str += ( num % s );
        num /= s;
    }
    return str;
}

int main() {
    freopen( "dualpal.in", "r", stdin );
    freopen( "dualpal.out", "w", stdout );
    int num, lim;
    scanf( "%d%d", &lim, &num );
    int count = 0;
    bool found;
    string str;
    while ( count < lim ) {
        ++num;
        found = false;
        for ( int i = 2; i <= 10; ++i ) {
            str = convert( num, i ); 
            if ( check( str ) ) {
                if ( found ) {
                    printf( "%d\n", num );
                    ++count;
                    break;
                }
                found = true;
            }
        }
    }
    return 0;
}
