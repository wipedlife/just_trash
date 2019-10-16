#include<stdlib.h>
#include<stdio.h>


typedef unsigned char ubyte;
typedef struct{
	ubyte data[26]; // 14+12
	short unsigned num;
}hash_block ;
ubyte * init_data(void * ptr);
hash_block init_hash (ubyte * ptr);

//ubyte
//	bin_search(ubyte x)
//{
//	 if( !x ) return x;
//	 ubyte t = 0;
//	 ubyte rv = 0
//	 while ( t < x ){
//		 t << 1; 
//		 rv++;
//	 }
//	 printf("end %d\n",rv);
//  	 return rv;
//}

