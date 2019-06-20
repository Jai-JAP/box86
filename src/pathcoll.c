#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#ifndef MAX_PATH
#define MAX_PATH 4096
#endif

#include "debug.h"
#include "pathcoll.h"

void FreeCollection(path_collection_t* collection)
{
    if(collection->cap) {
        for(int i=0; i<collection->size; ++i)
            free(collection->paths[i]);
        free(collection->paths);
    }
    collection->paths = NULL;
    collection->size = 0;
    collection->cap = 0;
    return;
}

void ParseList(const char* List, path_collection_t* collection)
{
    if(collection->cap)
        FreeCollection(collection);
    // count the stings (basically count(':') + 1) to define cap
    int cnt = 1;
    {
        const char* p = List;
        while(p) {
            p = strchr(p, ':');
            ++cnt;
            if(p) ++p;
        }
    }
    // alloc empty strings
    collection->cap = cnt;
    collection->paths = (char**)calloc(cnt, sizeof(char*));
    // and now split the paths...
    char tmp[MAX_PATH];
    const char *p = List;
    int idx = 0;
    while(p) {
        const char *p2 = strchr(p, ':');
        if(!p2) {
            strncpy(tmp, p, MAX_PATH - 1);
            p=NULL;
        } else {
            int l = (uintptr_t)p2 - (uintptr_t)p;
            strncpy(tmp, p, l);
            tmp[l]='\0';
            p=p2+1;
        }
        // check if there is terminal '/', add it if not
        int l = strlen(tmp);
        // skip empty strings
        if(l) {
            if(tmp[l-1]!='/')
                strcat(tmp, "/");
            collection->paths[idx]  =strdup(tmp);
            collection->size=++idx;
        }
    }
}

void CopyCollection(path_collection_t* to, path_collection_t* from)
{
    to->cap = from->cap;
    to->paths = (char**)calloc(to->cap, sizeof(char*));
    to->size = from->size;
    for (int i=0; i<to->size; ++i)
        to->paths[i] = strdup(from->paths[i]);
}

void AddPath(const char* path, path_collection_t* collection)
{
    char tmp[MAX_PATH];
    strcpy(tmp, path);
    int l = strlen(tmp);
    // skip empty strings
    if(l) {
        if(tmp[l-1]!='/')
            strcat(tmp, "/");
        if(collection->size==collection->cap) {
            collection->cap += 4;
            collection->paths = (char**)realloc(collection->paths, collection->cap*sizeof(char*));
        }
        collection->paths[collection->size++]=strdup(tmp);
    }
}
