//test 1
//#include<stdio.h>
//int main()
//{
//	printf("ajhfj");
//	printf("\n_____________test1______________");
//	return 0;
// } 
//---------------------------------------------------------------------------

//test 2 
//#include<iostream>
//using namespace std;
//class Xabc {
//	int *a;
//	int n;
//	public:
//		Xabc(int aa[],int nn):n(nn){
//			a=new int[n]; 
//			for (int i=0;i<n;i++)
//			a[i]=aa[i]; 
//		}
//		int GetA(int i) const {
//		return a[i];
//		}
//		int SumA (int n);
//		~Xabc(){delete []a;}
//};
//	int Xabc::SumA(int n){
//		int s=0;
//		for (int j=0;j<n;j++)
//			s+=a[j];
//			return s;
//	}  
//	
//int main(){
//	
//	int a[6]={2,5,8,3,6,9};
//	Xabc x(a,6);
//	a[3]=19;
//	int d=0;
//	for(int i=0;i<6;i++)
//		d+=x.GetA(i);
//		int f=x.SumA(5);
//		cout<<d+f<<endl;
//		return 0;  
//}
//----------------------------------------------------------------------- 

////test 3———P5》 
//#include<iostream>
//using namespace std;
//int ism(int n);
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int i;
//	if(n==1)
//	{
//		i=0;
//		cout<<i;
//	}
//	else{
//		for(i=0;n!=1;++i)
//		{
//			if(ism(n))
//			n=(3*n+1)/2;
//			else
//			n=n/2;
//		}
//		cout<<i;
//	}	
//	return 0;
// } 
////
// int ism(int n){
// 	int c;
//	c=n%2;
// 	return c;
// }//判断是不是奇数 
//----------------------------------------------------------------------- 

//2017CSP 3.1 
#include<iostream>
#include<cstdio> 
using namespace std;
int main(){
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	char aa[num1-1];
	for(int i=0;i<num1;i++)
	{
		scanf("%d",&aa[i]);
	}
	char bb[num1-1];
	
	for(int ii=0;ii<num1-1;ii++)
	{
		for(int num3=1;num3<num1;num3++)
		{
			int cc;
			if(aa[ii]>aa[num3])
			{
				cc=aa[num3];
				aa[num3]=aa[ii];
				aa[ii]=cc;
			}
		}
		bb[ii]=aa[ii];
	}
	bb[num1-1]=aa[num1-1];
	//_____________________________________________
		
		int outnum=0;
		int num=0,num9=0,k=0;
		for(;k!=(num1-1);)
	{
			for(num=num;num<num1;num++)
		{
			num9=num9+bb[num];
			if(num9>=num2)
			{
			num++;
			num9=0;
			k=num;
			outnum++;
			break;
			}
			else if(num==(num1-1))
			{
				num++;
				outnum++;
				k=num;
				break;
			}
			
		}
		num=k;
		
		if(k==(num1-1))
			break;		
	}
	
	printf("%d",outnum);
	return 0;
}
