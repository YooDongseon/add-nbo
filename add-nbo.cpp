#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if(argc <= 2){
        printf("syntax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin c.bin \n");
        return 0;
    }

    uint32_t n1 = 0;
    uint32_t n2 = 0; 
    
    FILE *f1 = NULL;
    FILE *f2 = NULL;
    
    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");
    
    fread(&n1, sizeof(uint32_t), 1, f1);
    fread(&n2, sizeof(uint32_t), 1, f2);

    n1 = ntohl(n1);
    n2 = ntohl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
   
    fclose(f1);
    fclose(f2);
}
