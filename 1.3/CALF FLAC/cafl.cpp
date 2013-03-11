/*
ID: vitsali1
LANG: C++
TASK: calfflac
*/
#include <cstdio>
#include <cctype>

using namespace std;

struct nw {
    char let;
    int pos;
};
int m = 0, posb, pose, lim;

void expand( int beg, int end, nw s[] ) {
    if ( s[ beg ].let != s[ end ].let ) {
        if ( beg == end ) {
            return;
        }
        else {
            if ( 1 > m ) {
                m = 1;
                posb = s[ beg ].pos;
                pose = s[ beg ].pos;
            }
            return;
        }
    }
    int i, j, count = 0;
    if ( beg == end ) {
        count = 1;
    }
    else {
        count = 2;
    }
    if ( count > m ) {
        m = count;
        posb = s[ beg ].pos;
        pose = s[ end ].pos;
    }
    i = beg - 1;
    j = end + 1;
    while ( i >= 0 && s[ i ].pos > s[ beg ].pos - 1001 && j < lim && s[ j ].pos < s[ end ].pos + 1001 ) {
        if ( s[ i ].let == s[ j ].let ) {
            if ( j - i + 1 > m ) {
                m = j - i + 1;
                posb = s[ i ].pos;
                pose = s[ j ].pos;
            }
        }
        else {
            return;
        }
        --i;
        ++j;
    }
}

int main() {
    freopen( "calfflac.in", "r", stdin );
    freopen( "calfflac.out", "w", stdout );
    char s[ 20001 ], c;
    nw n[ 20001 ];
    int i = 0, j;
    while ( scanf( "%c", &c ) != EOF ) {
        s[ i++ ] = c;
    }
    s[ i ] = '\0';
    for ( i = 0, j = 0; s[ i ] != '\0'; ++i ) {
        if ( isalpha( s[ i ] ) ) {
            n[ j ].let = tolower( s[ i ] );
            n[ j++ ].pos = i;
        }
    }
    lim = j;
    for ( i = 0; i < lim; ++i ) {
        expand( i, i, n );
        if ( i + 1 < lim ) {
            expand( i, i + 1, n );
        }
    }
    printf( "%d\n", m );
    for ( i = posb; i <= pose; ++i ) {
        printf( "%c", s[ i ] );
    }
    printf( "\n" );
    return 0;
}
