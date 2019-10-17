#include"myHash.h"
#include<string.h>
int main(int argc, char ** argv){
	printf("Test compiled %s %s\n", __TIME__, __FILE__);
	size_t s=strlen(argv[1]);
	size_t counter=0;

	hash_block * arr = init_data( argv[1], s );

	puts("Block was inited. Now hashing");	
	hashing(arr, s/MAGICNUMBER);
	puts("");
	puts("DATA~~~~~~~~~~~~~~~~DATA ;JUST HEX VALUE OF BYTES NOW;~~~~~~~~~~~~~~~~~~~~~~~~~");	
	puts("");
	puts("");
	ubyte cb=0;
	printf("0x");
	while(arr[cb].num != 0){
		for(ubyte i = 0; i < 26 && counter++ < s ; i++)
			printf("%x", arr[cb].data[i]);
		cb++;
	}
	puts("");
	puts("");

	free(arr);

}
