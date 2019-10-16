#include"myHash.h"
typedef long long unsigned ubig;

	
#define COUNT_X 8
ubyte * init_data(void * ptr){
	ubig * p = (ubig*)ptr;


	ubig num=(ubig)*p;
        printf(" %llu \n", num);	
	//ubyte (*bytes)[COUNT_X] = (ubyte**)calloc( sizeof(ubig**) , COUNT_X ) ; //
	//for(ubyte i = 0; i < COUNT_X;i++){
	//	bytes [i] = (ubyte*)calloc( sizeof(ubig*) , COUNT_0) ;
	//}
	ubyte * bytes = calloc( sizeof(ubig) , COUNT_X ) ;
	ubyte count=0;
	while( count != COUNT_X ){
		puts("Cycle start");
		//bytes[count][countX] = 
		puts("Init byte");
		printf("tmpV: %llu count: %d #: %llu\n", num,
				count, (num >> count*8));


		bytes[count]=( (num >> (count*8)) & 0xFF );
		count++;
		puts("Byte inited");

		puts("CYCLED END");	
	}
	return bytes;
}

void resurect_data(ubyte ** bytes){
	
}
