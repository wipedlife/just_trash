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
		printf("%llu %llu %llu %p\n", count_blocks, cb, (cb*MAGICNUMBER), sP);
		memcpy( (bytes[cb]).data, sP,
				 MAGICNUMBER  
				);
		printf("data now: %s\n", bytes[cb].data);
		sP+=MAGICNUMBER ;
		bytes[cb].num=1+(cb);
	}
	return bytes;;
		
			
}



	
