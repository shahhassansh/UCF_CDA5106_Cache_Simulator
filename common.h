#ifndef COMMON_H
#define COMMON_H

extern int L1read_hits,L2read_hits;
extern int L1reads,L2reads;
extern int L1writes,L2writes;
extern int L1write_hits,L2write_hits;
extern int L1read_misses,L2read_misses;
extern int L1write_misses,L2write_misses;
extern int L1writebacks,L2writebacks;
extern int L1policy_counter,L2policy_counter;
extern int L1index_width,L2index_width;
extern int L1offset_width,L2offset_width;
extern int L1tag_width,L2tag_width;
extern char L1policy[10],L2policy[10];
extern int L1cache_size,L2cache_size;
extern int L1assoc,L2assoc;
extern int L1block_size,L2block_size;
extern int l;
extern float L1missrate,L2missrate;
extern int memtraffic;
extern unsigned long long address,L1tag,L2tag;
extern unsigned long L1dec_index,L2dec_index;
extern unsigned long L1dec_offset,L2dec_offset;

#endif