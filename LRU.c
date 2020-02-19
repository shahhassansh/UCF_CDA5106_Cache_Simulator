#include<LRU.h>

int LRU(Cache L1cache[][32])
{
    int i,lru=0,lruway=0;

    lru=L1cache[L1dec_index][0].policycounter;
    for(i=1;i<L1assoc;i++)
    {

        if(L1cache[L1dec_index][i].policycounter<lru)
        {
            lru=L1cache[L1dec_index][i].policycounter;
            lruway=i;
        }

    }
    return lruway;
}