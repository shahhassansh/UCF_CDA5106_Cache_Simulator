#include<L2LRU.h>

int L2LRU(Cache L2cache[][32])
{
    int i,lru=0,lruway=0;

    lru=L2cache[L2dec_index][0].policycounter;
    for(i=1;i<L2assoc;i++)
    {

        if(L2cache[L2dec_index][i].policycounter<lru)
        {
            lru=L2cache[L2dec_index][i].policycounter;
            lruway=i;
        }

    }
    return lruway;
}