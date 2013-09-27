#include <iostream>
using namespace std;

distance_type l_distance(const string &str1, const string &str2)
{
    typedef unsigned int uint;

    size_t len_str1 = str1.size();
    size_t len_str2 = str2.size();

    distance_type dist[len_str1+1][len_str2+1];

    for(uint i=0; i<=len_str1; ++i)
        dist[i][0] = i;
    for(uint j=0; j<=len_str2; ++j)
        dist[0][j] = j;

    distance_type cost;
    for(uint i=1; i<=len_str1; ++i)
    {
        for(uint j=1; j<=len_str2; ++j)
        {
            cost = ( str1[i-1] == str2[j-1] )?  0 : 1 ;
            dist[i][j] = min( min ( dist[i-1][j] + 1 ,              // deletion
                                    dist[i][j-1] + 1 ),             // insertion
                              dist[i-1][j-1] + cost );        // substitution
        }
    }

    return dist[len_str1][len_str2];
}
