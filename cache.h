#ifndef CACHE_H
#define CACHE_H

typedef struct Cache
{
    int valid;
    unsigned long long tag;
    int dirty;
    int policycounter;
}Cache;

#endif /* CACHE_H */
