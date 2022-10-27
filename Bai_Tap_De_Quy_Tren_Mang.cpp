#include<stdio.h>
#include<conio.h>
#include<math.h>
float deQuy1(int n);
float deQuy2(float x, int n);
float deQuy3(float x, int n);
float deQuy4(int n);
float deQuy5(int n);
long gt(int n);
double Bai13(int n);
double Bai14(int n);
void suLi();
int main(){
	suLi();


	
	return 0;
}
// s = 1 + 1/2 + 1/3 + 1/4 + ....+ 1/n
float deQuy1(int n){
	if(n == 1)
		return 1;
	return deQuy1(n - 1) + 1.0 / n;
}
// s = x^1+x^2+x^3+....+x^n
float deQuy2(float x, int n){
	if(n == 1|| n == 0)
		return x;
	return deQuy2(x,n - 1) + pow(x,n);
}
//s = x^2 + x^4+x^6+...+x^2n
float deQuy3(float x, int n){
	if(n == 1)
		return 4;
	return deQuy3(x,n - 1) + pow(x,2*n);
}
// s = 1 + 1/2 + 1/3 + 1/4 + ....+ 1/n
float deQuy4(int n){
	if(n == 1)
		return n;
	return deQuy4(n - 1) + 1.0/n;
}
//s = 1/2 + 1/3 + 1/4 + ...+ n/n+1
float deQuy5(int n){
	if(n == 1)
		return 1.0/2;
	return deQuy5(n - 1) + (float)n/(n + 1);
}

long gt(int n){
	long sub = 1;
	for(int i = 2;i <= n;i++){
		sub *= i;
	}
	return sub;
}

double Bai13(int n){
	if(n == 1){
		return (double)(1 * gt(2) / (2 + sqrt((double)3)));
	}
	return (double)(n * gt(n + 1) / ((n + 1 ) + sqrt((double)(n + 2))))+ Bai13(n - 1);
}

double Bai14(int n){
	if(n == 1){
		return (double)(1 + sqrt((double)1 + 2)) / (2 + sqrt((double)gt(3)));
	}
	return (double)(n + sqrt((double)n + n + 1)) / ((n + 1 ) + sqrt((double)gt(n + 2)))+ Bai14(n - 1);
}

void suLi(){
int luachon;
	do{
		do{
			printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua chon khong hop le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
					int n;
					printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
					printf("\n\tTong Gia tri bieu thuc la %.3f", deQuy1(n));
			}
			case 2:{
				int n;
				float x;
				printf("\n\t nhap x : ");scanf("%f", &x);
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong Bien thuc la %.3f", deQuy2(x,n));
				break;
			}
			case 3:{
				int n;
				float x;
				printf("\n\t nhap x : ");scanf("%f", &x);
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong Bien thuc la %.3f", deQuy3(x,n));
				break;
			}
			case 4:{
				int n;
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong Bien thuc la %.3f", deQuy4(n));
				break;
			}
			case 5:{
				int n;
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong bieu thuc = %.3f", deQuy5(n));
				break;
			}
			case 6:{
				int n;
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong bieu thuc = %lf", Bai13(n));
				break;
			}
			case 7:{
				int n;
				printf("\n\tNhap so nguyen  : ");scanf("%d", &n);
				printf("\n\tTong bieu thuc = %lf", Bai14(n));
				break;
			}
			
		}
		
	}while(luachon != 0);
}




