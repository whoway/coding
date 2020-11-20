#include<stdio.h>
unsigned int align_n(unsigned int size, int n)
{
	
	
	unsigned int test=(1<<n)-1;//第0-n位全是1 
	
	unsigned int temp=size;//复制 
	temp&=(~(test<<(32-n))); //获得第0-n位的位

	
	unsigned int out;
	
	if(temp&test)//如果有1 
	{

		size&=(~test);//末尾置0 
		
//		printf("size=%d\n",size);
		if(size&(1<<n)) 
		{
//			printf("OK");//错在这里 
			
			out=size+(1<<n);
		}
		else
		{
			out=size^(1<<n);//错在这里 ,如果那个地方是0可以，要是1要进位 
		}
		
//		printf("OK");
		
		return out;
	}
	
	
	
	out=size&=(~test);;
	return out;
	
}

int main()
{
	unsigned int size,out;
	int n;
	scanf("0x%x,%d",&size,&n);
//	printf("size=%x,n=%d\n",size,n); 
	out=align_n(size,n);
	
	printf("0x%x",out); 
	return 0; 
} 
