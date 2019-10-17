#include"myHash.h"

hash_block * init_data(void * ptr, size_t s){

	ubyte * sP = ptr;
	size_t count_blocks = 1+(s / MAGICNUMBER) ;	
	printf("Size %lu ; %lu \n", s, count_blocks);

	hash_block * bytes = calloc( sizeof(hash_block) ,
		       count_blocks+1 ) ;
	//for(size_t i=count_blocks;i--;)
	//	bytes[i] = 
	//		calloc( sizeof(hash_block) , MAGICNUMBER );
	for ( size_t cb=0; cb < count_blocks; cb++ ){

		for(char i = MAGICNUMBER; i >= 0; i--)
		       (bytes[cb]).data[i]=0;	
		memcpy( (bytes[cb]).data, sP,
				 MAGICNUMBER  
				);
		sP+=MAGICNUMBER ;
		bytes[cb].num=1+(cb);
	}
	return bytes;
}
inline void A1_H(TYPEFOROPERATION){
	ubig a=0;
	ubig b=0;
	ubig c=0;

	for( ubyte i = 0; i < MAGICNUMBER;i++){
		a += block->data[i] << 7;
		b += block->data[i] << 2;
		c += block->data[i] << 3;
	}
	for( ubyte i = 0; i < MAGICNUMBER;i++ ){
		if ( i % 2 == 0 )
			block->data[i]=
				(((a & b) | (b & c) | (b & a)) << 7) | 7;
		else if( i % 3 == 0 )
			block->data[i]=
				(((a & b) ^ (b & c) | (b & a)) << 7) | 7;
		else
			block->data[i]=
				(((a & b) | (b & c) ^ (b & a)) << 7) | 7;

	
	}	
	//(*block).data=;

}

inline void A2_H(TYPEFOROPERATION){
	//hash_block tmpblock;
	//memcpy(&tmpblock, block, sizeof(hash_block));
	ubig a=0;
	ubig z=0;
	ubig c=0;
	ubig k=0;

	INIT_N;
	N>>=12;
	for(ubyte i=26;i--;){
		a+=N>>14;
		z+=N & a;
		c+=N | a;
		k+=z & c;
		ubyte rv=( ( ( k & c | z | a | N  ) << (14+12) ) );
		block->data[i]=(rv << (14+12) ) | (14+12);
	}
}
inline void A3_H(TYPEFOROPERATION){
	INIT_N;
	for(ubyte i=26;i--;){
	
	}
}
inline void A4_H(TYPEFOROPERATION){}


void hashing(hash_block * blocks, size_t cblock){
	for(size_t i=cblock;i--;){
		A1_H(&blocks[i]);
		A2_H(&blocks[i]);
	}
}



	
