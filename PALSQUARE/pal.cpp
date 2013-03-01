/*
ID: vitsali1
LANG: C++
TASK: palsquare
*/
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

char let[ 16 ] = "ABCDEFGHIJKLMN";
const int N = 300;

bool check( string str ) {
    int i, j;
    for ( i = 0, j = str.length() - 1; i <= j; ++i, --j ) {
        if ( str[ i ] != str[ j ] ) {
            return false;
        }
    }
    return true;
}

string convert( int num, int s ) {
    string str;
    stack < int > a;
    while ( num > 0 ) {
        int rem = num % s;
        a.push( rem );
        num /= s;
    }
    while ( !a.empty() ){
        str += a.top();
        a.pop();
    }
    return str;
}

void printString( string str ) {
    for ( int i = 0; i < str.length(); ++i ) {
        if ( !isalpha( str[ i ] ) ) {
            printf( "%d", str[ i ] );
        }
        else {
           printf( "%c", str[ i ] ); 
        }
    }
}

string fix( string str, int s ) {
    int i;
    string fixed;
    for ( i = 0; i < str.length(); ++i ) {
        if ( str[ i ] >= 10 ) {
            fixed += let[ str[ i ] % 10 ];
        }
        else {
            fixed += str[ i ];
        }
    }
    return fixed;
}

int main() {
    freopen( "palsquare.in", "r", stdin );
    freopen( "palsquare.out", "w", stdout );
    int B, i;
    scanf( "%d", &B );
    string str, a;
    for ( i = 1; i <= N; ++i ) {
        int n = pow( i, 2 );
        str = convert( n, B );
        if ( check( str ) ) {
            a = convert( i, B );
            if ( B >= 10 ) {
                a = fix( a, B % 10 );
                str = fix( str, B % 10 );
            }
            printString( a );
            printf( " " );
            printString( str );
            printf( "\n" );
        }
    }
    return 0;
}
