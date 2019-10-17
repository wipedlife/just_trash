#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef long long unsigned ubig;

typedef unsigned char ubyte;

#define MAGICNUMBER 26


typedef struct hash_block{
	ubyte data[MAGICNUMBER]; // 14+12
	short unsigned num;
}hash_block ;


hash_block * init_data(void * ptr, size_t s);
ubyte bin_search(ubig x);

