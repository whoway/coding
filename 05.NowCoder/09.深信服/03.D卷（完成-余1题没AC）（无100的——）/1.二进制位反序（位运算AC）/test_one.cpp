#include <stdio.h>
#include <string.h>

unsigned int reverse(unsigned int num)
{
    //TODO:
    unsigned int ret=0;
	for(int i=0;i<32;++i)
	{
		unsigned int test=1<<i;
		if(num&test)
		{
			ret^=(1<<(31-i));
		}
		
	 } 
	 
	 return ret;
}

int main(int argc, char *argv[])
{
    unsigned int num = 0;
    unsigned int ret = 0;

    if (1 != fscanf(stdin, "0x%x", &num)) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    ret = reverse(num);
    printf("%08x\n", ret);
    return 0;
}
