#include"myHash.h"
#include<string.h>
int main(int argc, char ** argv){
	size_t s=strlen(argv[1]);
	size_t counter=0;
	hash_block * arr = init_data( argv[1], s );

	ubyte cb=0;
	while(arr[cb].num != 0){
		for(ubyte i = 0; i < 26 && counter++ < s ; i++)
			printf("%c _ ", arr[cb].data[i]);
		cb++;
	}

	puts("");
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	puts("");
	puts("Block was inited. Now hashing");	
}
