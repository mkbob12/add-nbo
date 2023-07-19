#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <arpa/inet.h>

// 파일 생성하여 저장 

uint32_t sum_buffer(uint32_t sum, uint32_t buffer1, uint32_t buffer2){
    sum = ntohl(buffer1) + ntohl(buffer2);
    return sum;
}


int main(int argc, char*argv[]){
	uint32_t buffer1;
	uint32_t buffer2;
    uint32_t sum = 0;

	FILE* file1 = fopen(argv[1],"rb");
	FILE* file2 = fopen(argv[2],"rb");

	if (file1 == NULL){
		printf("파일이 없습니다. 프로그램을 종료합니다.");
	}
	buffer1 = 0;
	buffer2 = 0;

	fread(&buffer1,sizeof(uint32_t),1,file1);
	fread(&buffer2,sizeof(uint32_t),1,file2);
	
	sum = sum_buffer(sum, buffer1, buffer2);

    
	
    
    printf("%u (0x%x) + %u(0x%x) = %x \n", ntohl(buffer1),  ntohl(buffer1), ntohl(buffer2),ntohl(buffer2), sum);
    fclose(file1);
    fclose(file2);
	
}