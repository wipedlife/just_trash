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
	hash_block tmp;
	memcpy(&tmp, block, sizeof(hash_block));
		
	for(ubyte i=26;i--;){
		A1_H(&tmp);
		ubyte c =tmp.data[i];
		A2_H(&tmp);
		ubyte c1= tmp.data[i];
		block->data[i]=
			block->data[i]^c;
		block->data[i]=
			block->data[i]^c1;
		//T...
		//rv = (rv << 8) + byte
	}
}
inline void A4_H(TYPEFOROPERATION){
	INIT_N;
	ubig a,b,c,d,e;
	a = N ^ 7;
     	b = N ^ 2;
     	c = N ^ 3;
     	d = N << 12;
     	e = N >> 14;
	for(ubyte i=26;i--;)
		block->data[i]^=
		((a^b) | (a^c) | (a^d) | (a^e)) ^ ((b^c) 
		| (b^e) | (b^d) | (e^a)) | (14+12);
}

inline ubig W_H(TYPEFOROPERATION){
	INIT_N;
	hash_block tmp;
	memcpy(&tmp, block, sizeof(hash_block));
	ubig a1,a2,a3;
	for(ubyte i=26;i--;){
		A1_H(&tmp);
		a1 +=tmp.data[i];
		A2_H(&tmp);
		a2 += tmp.data[i];
		A3_H(&tmp);
		a3 += tmp.data[i];
	}
	memcpy(&tmp, block, sizeof(hash_block));
	for(ubyte i =26;i--;){
		tmp.data[i]=(N&0xFF);
		N>>=8;
	}
	A4_H(&tmp);
	N=N^26;
	for(ubyte i =26;i--;)
		N=N^(N<<8) | tmp.data[i];
	return
		((a1+a2+a3)^N << (14+12) ) ^ (14+12);
	
}

inline ubig C_H(TYPEFOROPERATION){
	ubig c,v;
	ubig e=W_H(block);
	//char str[26];
	//memcpy( str, block.data, 26 );
	c = (v << 8 | e) << (14+12) | (14+12);
	v = ( (v ^ c)^e ) << (14+12) | (14+12);
	return ( (v << (14+12)) ^ (14+12) );
	
}


void hashing(hash_block * blocks, size_t cblock){
	for(size_t i=cblock;i--;){
		A1_H(&blocks[i]);
		A2_H(&blocks[i]);
		A3_H(&blocks[i]);
		A4_H(&blocks[i]);	
	}
	for(size_t i=cblock;i--;){
		ubig ch = C_H(&blocks[i]);
		ubig wh = W_H(&blocks[i]);
		for(size_t cbyte=0;cbyte<MAGICNUMBER;cbyte++){
			blocks[i].data[cbyte]=
				blocks[i].data[cbyte]^ch;
			blocks[i].data[cbyte]=
				blocks[i].data[cbyte]^wh;
			if(i+1 < MAGICNUMBER)
			 blocks[i].data[cbyte]^=
				blocks[i+1].data[cbyte];
			else
				blocks[i].data[cbyte]^=
					blocks[i-14].data[cbyte];
		}

	}
}



	
