#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

/*uint32_t convert_endian(uint32_t target)
{
    return ((target << 24) & 0xff000000 | (target << 8) & 0x00ff0000 \
    | (target >> 8) & 0x0000ff00| (target >> 24) & 0x000000ff);
}*/

int main(int argc, char *argv[])
{   
    if(argc != 3)
    {
        puts("[+]Usage: add-nbo <file1> <file2>");
        exit(1);
    }

    FILE *fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL)
    {
        puts("[X]File ERROR!");
        exit(1);
    }
    FILE *fp2 = fopen(argv[2], "rb");
    if (fp2 == NULL)
    {
        puts("[X]File ERROR!");
        exit(1);
    }

    uint32_t tmp1 = 0;
    uint32_t tmp2 = 0;

    fread(&tmp1, 4, 1, fp1);
    tmp1 = ntohl(tmp1);
    
    fread(&tmp2, 4, 1, fp2);
    tmp2 = ntohl(tmp2);

    uint32_t tmp3 = tmp1 + tmp2;
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n", tmp1, tmp1, tmp2, tmp2, tmp3, tmp3);

    return 0;
}