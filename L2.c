#include<L2.h>


void L2writecache(Cache L1cache[][32],Cache L2cache[][32],int rep_candidate)
{
    unsigned long long decode_add=0,tag=0,l2tag=0;
    unsigned long l2dec_index=0;

    tag=L1cache[L1dec_index][rep_candidate].tag;
    decode_add=( (((tag<<L1index_width) | (L1dec_index)) << (L1offset_width)) | (L1dec_offset) );//decoding address from tag of L1 eviction block


    l2tag=decode_add>>(L2index_width+L2offset_width);
    l2dec_index=(decode_add<<L2tag_width)>>(L2tag_width+L2offset_width);

    int i,counter=0,counter2=0,rep2_candidate=0;
    L2writes+=1;
    L2policy_counter+=1;

    if(strcasecmp(L2policy,"0")==0 || strcasecmp(L2policy,"2")==0 )
    {
        for(i=0;i<L2assoc;i++)
    {

        if(L2cache[l2dec_index][i].valid==1 && (l2tag==L2cache[l2dec_index][i].tag))        //handling write hits
        {
            L2write_hits+=1;
            counter=1;
            L2cache[l2dec_index][i].policycounter=L2policy_counter;
            L2cache[l2dec_index][i].dirty=1;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L2write_misses+=1;
        for(i=0;i<L2assoc;i++)
        {
            if(L2cache[l2dec_index][i].valid==0)
            {
                rep2_candidate=i;
                break;
            }
            else
                counter2+=1;
        }
        if(counter2==L2assoc)
        {
            rep2_candidate=L2writeLRU(L2cache,l2dec_index);
        }

        if(L2cache[l2dec_index][rep2_candidate].dirty==1 && L2cache[l2dec_index][rep2_candidate].valid==1)
        {
            L2writebacks+=1;
        }

        L2cache[l2dec_index][rep2_candidate].tag=l2tag;
        L2cache[l2dec_index][rep2_candidate].policycounter=L2policy_counter;
        L2cache[l2dec_index][rep2_candidate].dirty=1;
        L2cache[l2dec_index][rep2_candidate].valid=1;
    }
    }

    else if(strcasecmp(L2policy,"1")==0)
    {
        for(i=0;i<L2assoc;i++)
    {

        if(L2cache[l2dec_index][i].valid==1 && (l2tag==L2cache[l2dec_index][i].tag))        //handling write hits
        {
            L2write_hits+=1;
            counter=1;
            L2cache[l2dec_index][i].dirty=1;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L2write_misses+=1;
        for(i=0;i<L2assoc;i++)
        {
            if(L2cache[l2dec_index][i].valid==0)
            {
                rep2_candidate=i;
                break;
            }
            else
                counter2+=1;
        }
        if(counter2==L2assoc)
        {
            rep2_candidate=L2writeLRU(L2cache,l2dec_index);
        }

        if(L2cache[l2dec_index][rep2_candidate].dirty==1 && L2cache[l2dec_index][rep2_candidate].valid==1)
        {
            L2writebacks+=1;
        }

        L2cache[l2dec_index][rep2_candidate].tag=l2tag;
        L2cache[l2dec_index][rep2_candidate].policycounter=L2policy_counter;
        L2cache[l2dec_index][rep2_candidate].dirty=1;
        L2cache[l2dec_index][rep2_candidate].valid=1;
    }
    }
}

void L2readcache(Cache L2cache[][32])
{
    int i,counter=0,counter2=0,rep_candidate=0;

    L2reads+=1;
    L2policy_counter+=1;

    if(strcasecmp(L2policy,"0")==0 || strcasecmp(L2policy,"2")==0)
    {
        for(i=0;i<L2assoc;i++)
    {
	if(L2cache[L2dec_index][i].valid==1 && (L2cache[L2dec_index][i].tag==L2tag))        //handling read hits
        {
            L2read_hits+=1;
            counter=1;
            L2cache[L2dec_index][i].policycounter=L2policy_counter;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L2read_misses+=1;
        for(i=0;i<L2assoc;i++)
        {

            if(L2cache[L2dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            if(L2cache[L2dec_index][i].valid==1)
            {
                counter2+=1;
            }
        }
        if(counter2==L2assoc)
        {
            rep_candidate=L2LRU(L2cache);
        }

        if(L2cache[L2dec_index][rep_candidate].dirty==1 && L2cache[L2dec_index][rep_candidate].valid==1)
        {
            L2writebacks+=1;
        }

        L2cache[L2dec_index][rep_candidate].tag=L2tag;
        L2cache[L2dec_index][rep_candidate].policycounter=L2policy_counter;
        L2cache[L2dec_index][rep_candidate].dirty=0;
        L2cache[L2dec_index][rep_candidate].valid=1;
    }
    }

    else if(strcasecmp(L2policy,"1")==0)
    {
        for(i=0;i<L2assoc;i++)
    {
	if(L2cache[L2dec_index][i].valid==1 && (L2cache[L2dec_index][i].tag==L2tag))        //handling read hits
        {
            L2read_hits+=1;
            counter=1;
            break;
        }
    }
    if(counter==0)          //handling read misses
    {
        L2read_misses+=1;
        for(i=0;i<L2assoc;i++)
        {

            if(L2cache[L2dec_index][i].valid==0)
            {
                rep_candidate=i;
                break;
            }
            if(L2cache[L2dec_index][i].valid==1)
            {
                counter2+=1;
            }
        }
        if(counter2==L2assoc)
        {
            rep_candidate=L2LRU(L2cache);
        }

        if(L2cache[L2dec_index][rep_candidate].dirty==1 && L2cache[L2dec_index][rep_candidate].valid==1)
        {
            L2writebacks+=1;
        }

        L2cache[L2dec_index][rep_candidate].tag=L2tag;
        L2cache[L2dec_index][rep_candidate].policycounter=L2policy_counter;
        L2cache[L2dec_index][rep_candidate].dirty=0;
        L2cache[L2dec_index][rep_candidate].valid=1;
    }
    }

}
