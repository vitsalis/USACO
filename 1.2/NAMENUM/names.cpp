/*
ID: vitsali1
LANG: C++
TASK: namenum
*/
#include <cstdio>
#include <string>

using namespace std;

bool check( char s[], char names[][ 3 ], char nick[] ) {
    int i, j;
    for ( i = 0; nick[ i ] != '\0'; ++i ) {
        if ( s[ i ] == '\0' ) return false;
        for ( j = 0; j < 3; ++j ) {
            if ( names[ s[ i ] - '0' ][ j ] == nick[ i ] ) {
                break; 
            }
            if ( j + 1 == 3 ) {
                return false;
            }
        }
    }
    if ( s[ i ] == '\0' ) {
        return true;
    }
    return false;
}

int main() {
    FILE *fin = fopen( "dict.txt", "r" );
    freopen( "namenum.in", "r", stdin );
    freopen( "namenum.out", "w", stdout );
    char name[ 20 ], s[ 20 ], names[ 10 ][ 3 ];
    bool found = false;
    string solution;
    string out;
    scanf( "%s", s );
	names[ 2 ][ 0 ] = 'A';
    names[ 2 ][ 1 ] = 'B';
    names[ 2 ][ 2 ] = 'C';
    names[ 3 ][ 0 ] = 'D';
    names[ 3 ][ 1 ] = 'E';
    names[ 3 ][ 2 ] = 'F';
    names[ 4 ][ 0 ] = 'G';
    names[ 4 ][ 1 ] = 'H';
    names[ 4 ][ 2 ] = 'I';
    names[ 5 ][ 0 ] = 'J';
    names[ 5 ][ 1 ] = 'K';
    names[ 5 ][ 2 ] = 'L';
    names[ 6 ][ 0 ] = 'M';
    names[ 6 ][ 1 ] = 'N';
    names[ 6 ][ 2 ] = 'O';
    names[ 7 ][ 0 ] = 'P';
    names[ 7 ][ 1 ] = 'R';
    names[ 7 ][ 2 ] = 'S';
    names[ 8 ][ 0 ] = 'T';
    names[ 8 ][ 1 ] = 'U';
    names[ 8 ][ 2 ] = 'V';
    names[ 9 ][ 0 ] = 'W';
    names[ 9 ][ 1 ] = 'X';
    names[ 9 ][ 2 ] = 'Y';
    while ( fscanf( fin, "%s", name ) != EOF ) {
        if ( check( s, names, name ) ) {
            printf( "%s\n", name );
            found = true;
        }
    }
    fclose( fin );
    if ( !found ) printf( "NONE\n" );
    return 0;
}
