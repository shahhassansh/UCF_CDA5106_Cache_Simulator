#include<L1.h>

void L1readcache(Cache L1cache[][32],Cache L2cache[][32])
{
    int i,counter=0,counter2=0,rep_candidate=0;

    L1reads+=1;
    L1policy_counter+=1;

    if(strcasecmp(L1policy,"0")==0 || strcasecmp(L1policy,"2")==0 )
    {
        for(i=0;i<L1assoc;i++)
    {
	if(L1cache[L1dec_index][i].valid==1 && (L1cache[L1dec_index][i].tag==L1tag))        //handling read hits
        {
            L1read_hits+=1;
            counter=1;
            L1cache[L1dec_index][i].policycounter=L1policy_counter;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L1read_misses+=1;
        for(i=0;i<L1assoc;i++)
        {

            if(L1cache[L1dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            if(L1cache[L1dec_index][i].valid==1)
            {
                counter2+=1;
            }
        }
        if(counter2==L1assoc)
        {
            rep_candidate=LRU(L1cache);
        }

        if(L1cache[L1dec_index][rep_candidate].dirty==1 && L1cache[L1dec_index][rep_candidate].valid==1)
        {
            L1writebacks+=1;
            if(L2cache_size!=0)
            L2writecache(L1cache,L2cache,rep_candidate);
        }
        if(L2cache_size!=0)
        L2readcache(L2cache);

        L1cache[L1dec_index][rep_candidate].tag=L1tag;
        L1cache[L1dec_index][rep_candidate].policycounter=L1policy_counter;
        L1cache[L1dec_index][rep_candidate].dirty=0;
        L1cache[L1dec_index][rep_candidate].valid=1;
    }
    }

    else if(strcasecmp(L1policy,"1")==0)
    {
        for(i=0;i<L1assoc;i++)
    {
	if(L1cache[L1dec_index][i].valid==1 && (L1cache[L1dec_index][i].tag==L1tag))        //handling read hits
        {
            L1read_hits+=1;
            counter=1;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L1read_misses+=1;
        for(i=0;i<L1assoc;i++)
        {

            if(L1cache[L1dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            if(L1cache[L1dec_index][i].valid==1)
            {
                counter2+=1;
            }
        }
        if(counter2==L1assoc)
        {
            rep_candidate=LRU(L1cache);
        }

        if(L1cache[L1dec_index][rep_candidate].dirty==1 && L1cache[L1dec_index][rep_candidate].valid==1)
        {
            L1writebacks+=1;
            if(L2cache_size!=0)
            L2writecache(L1cache,L2cache,rep_candidate);
        }
        if(L2cache_size!=0)
        L2readcache(L2cache);

        L1cache[L1dec_index][rep_candidate].tag=L1tag;
        L1cache[L1dec_index][rep_candidate].policycounter=L1policy_counter;
        L1cache[L1dec_index][rep_candidate].dirty=0;
        L1cache[L1dec_index][rep_candidate].valid=1;
    }
    }

}

void L1writecache(Cache L1cache[][32],Cache L2cache[][32])
{
    int i,counter=0,counter2=0,rep_candidate=0;
    L1writes+=1;
    L1policy_counter+=1;

    if(strcasecmp(L1policy,"0")==0 || strcasecmp(L1policy,"2")==0)
    {
        for(i=0;i<L1assoc;i++)
    {

        if(L1cache[L1dec_index][i].valid==1 && (L1tag==L1cache[L1dec_index][i].tag))        //handling write hits
        {
            L1write_hits+=1;
            counter=1;
            L1cache[L1dec_index][i].policycounter=L1policy_counter;
            L1cache[L1dec_index][i].dirty=1;
            break;
        }
    }
    if(counter==0)          //handling write misses
    {
        L1write_misses+=1;
        for(i=0;i<L1assoc;i++)
        {
            if(L1cache[L1dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            else
                counter2+=1;
        }
        if(counter2==L1assoc)
        {
            rep_candidate=LRU(L1cache);
        }

        if(L1cache[L1dec_index][rep_candidate].dirty==1 && L1cache[L1dec_index][rep_candidate].valid==1)
        {
            L1writebacks+=1;
            if(L2cache_size!=0)
            L2writecache(L1cache,L2cache,rep_candidate);
        }
        if(L2cache_size!=0)
        L2readcache(L2cache);

        L1cache[L1dec_index][rep_candidate].tag=L1tag;
        L1cache[L1dec_index][rep_candidate].policycounter=L1policy_counter;
        L1cache[L1dec_index][rep_candidate].dirty=1;
        L1cache[L1dec_index][rep_candidate].valid=1;
    }
    }

    else if(strcasecmp(L1policy,"1")==0)
    {
        for(i=0;i<L1assoc;i++)
    {

        if(L1cache[L1dec_index][i].valid==1 && (L1tag==L1cache[L1dec_index][i].tag))        //handling write hits
        {
            L1write_hits+=1;
            counter=1;
            L1cache[L1dec_index][i].dirty=1;
            break;
        }
    }
    if(counter==0)          //handling write misses
    {
        L1write_misses+=1;
        for(i=0;i<L1assoc;i++)
        {
            if(L1cache[L1dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            else
                counter2+=1;
        }
        if(counter2==L1assoc)
        {
            rep_candidate=LRU(L1cache);
        }

        if(L1cache[L1dec_index][rep_candidate].dirty==1 && L1cache[L1dec_index][rep_candidate].valid==1)
        {
            L1writebacks+=1;
            if(L2cache_size!=0)
            L2writecache(L1cache,L2cache,rep_candidate);
        }
        if(L2cache_size!=0)
        L2readcache(L2cache);

        L1cache[L1dec_index][rep_candidate].tag=L1tag;
        L1cache[L1dec_index][rep_candidate].policycounter=L1policy_counter;
        L1cache[L1dec_index][rep_candidate].dirty=1;
        L1cache[L1dec_index][rep_candidate].valid=1;
    }
    }
}