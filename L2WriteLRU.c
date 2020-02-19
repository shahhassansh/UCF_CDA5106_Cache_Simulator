#include<L2WriteLRU.h>

int L2writeLRU(Cache L2cache[][32],int l2dec_index)
{
    int i,lru=0,lruway=0;

    lru=L2cache[l2dec_index][0].policycounter;
    for(i=1;i<L2assoc;i++)
    {

        if(L2cache[l2dec_index][i].policycounter<lru)
        {
            lru=L2cache[l2dec_index][i].policycounter;
            lruway=i;
        }

    }
    return lruway;
}
