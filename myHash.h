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

void hashing(hash_block * blocks, size_t cblock);


//H
#define TYPEFOROPERATION hash_block * block
#define BLOCK_OPERATION_INIT(NAME) void NAME ##_H  (TYPEFOROPERATION);

#define INIT_N \
	ubig N=1;\
	for(ubyte i=26;i--;)\
		N= (N<<8) | (*block).data[i] ;
	

BLOCK_OPERATION_INIT(A1);
BLOCK_OPERATION_INIT(A2);
BLOCK_OPERATION_INIT(A3);
BLOCK_OPERATION_INIT(A4);

long long unsigned W_H( hash_block * block);
//TODO: B0-B3
// Z

ubig C_H(TYPEFOROPERATION);

//H

