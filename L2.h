#include<common.h>
#include<L2LRU.h>
#include<L2WriteLRU.h>
#include <strings.h>

void L2writecache(Cache L1cache[][32],Cache L2cache[][32],int);
void L2readcache(Cache L2cache[][32]);