#include<stdio.h>
#include<conio.h>
#include<math.h>
long tongtu1DenN_De_Quy(int n);
double bt2_Can(int n);
float deQuy3(int n);
float deQuy4(int n);
long deQuy5(int n);
double deQuy6(int n);
long deQuy7(int n);
long capSoNhan(int n,int U1, int q);
long tinhBieuThucBai6(int n);

void showMenu();
void suLi();

int main(){
	suLi();
	
	return 0;
}
//DE BAI s = 1 + 2 + 3 + 4 + .... + n
long Bt1_tongtu1DenN_De_Quy(int n){
	if(n == 1)
		return n;
	return Bt1_tongtu1DenN_De_Quy(n - 1) + n;
}
double bt2_Can(int n){
	double s = 0;
	if(n == 1)
		return sqrt(2);
	s = sqrt(2 + bt2_Can(n - 1));
	return s;
}
//s = 1/2 + 1/3 + 1/4 + ...+ n/n+1
float deQuy3(int n){
	if(n == 1)
		return 1.0/2;
	return deQuy3(n - 1) + (float)n/(n + 1);
}
float deQuy4(int n){
	if(n == 0)
		return 1;
	return deQuy4(n - 1) + 1.0/(2 * n + 1);
}
long deQuy5(int n){
	if(n == 1)
		return 2;
	return deQuy5(n - 1) + n * (n + 1);
}
//s = 1/1*2*3 + 2/2*3*4 + 3 /3*4*5 + ....+ 1/(n*(n + 1)*(n + 2))
double deQuy6(int n){
	float sum = 0;
	if(n == 0)
		return 0;
	sum = deQuy6(n - 1) + 1.0/(n * (n + 1) * (n + 2));
	return sum;
}
//s = 1 ^ 2 + 2 ^ 2 + 3 ^ 2 + ....+ n ^ 2
long deQuy7(int n){
	if(n == 1)
		return n;
	return deQuy7(n - 1) + pow(n,2);
}
//s = 1 + (1 + 2)+(1 + 2 + 3) + (1 + 2 + 3 + 4)+...+(1 + 2 + 3 + 4 + ... + n)
int deQuy8(int n){
	if(n == 1)
		return n;
	int sum = 0;
	for(int i = 1;i < n;i++){
		sum += deQuy8(n - 1);
	}
	return sum;
}
//Bai tap 4  Cap so cong
int tinhSoHangThuNCapSoCong(int a, int r, int n){
	if(n == 1)//Diem neo hay Con goi la dien dung
		return a;//
	return tinhSoHangThuNCapSoCong(a,r,n - 1) + r;
}
// bai 5 tuong tu
long capSoNhan(int n,int U1, int q){//Un = U1 * q^(n - 1)
	if(n == 1)
		return U1;
	return capSoNhan(n - 1,U1,q) * q;
}
// bai 6 252
long tinhBieuThucBai6(int n){//De Quy phi tuyen
	if(n < 6)
		return n;
	int sum = 0;
	for(int i = 1;i <= 5;i++){ // Cong thuc di tu n - 5 den n - 1 nen i di tu 1 den 5
		sum += tinhBieuThucBai6(n - i);
	}
	return sum;
}
// bai 7
int tinhBieuThucBai7(int n){
	
}
void showMenu(){
	printf("\n\t\t\t\t\t\t\t***********************************************");
	printf("\n\t\t\t\t\t\t\t*                    MENU                     *");
	printf("\n\t\t\t\t\t\t\t***********************************************");
	printf("\n\t\t\t\t\t\t\t* 0 De ket thuc chuong trinh                  *");
	printf("\n\t\t\t\t\t\t\t* 1 BT1                                       *");
	printf("\n\t\t\t\t\t\t\t* 2 BT2                                       *");
	printf("\n\t\t\t\t\t\t\t* 3 BT3                                       *");
	printf("\n\t\t\t\t\t\t\t* 4 BT4                                       *");
	printf("\n\t\t\t\t\t\t\t* 5 BT5                                       *");
	printf("\n\t\t\t\t\t\t\t* 6 BT6                                       *");
	printf("\n\t\t\t\t\t\t\t* 7 BT7                                       *");
	printf("\n\t\t\t\t\t\t\t* 8 BT8                                       *");
	printf("\n\t\t\t\t\t\t\t* 9 BT9                                       *");
	printf("\n\t\t\t\t\t\t\t* 10 BT10                                     *");
	printf("\n\t\t\t\t\t\t\t***********************************************");
	printf("\n\t\t\t\t\t\t\t***********************************************");
}
void suLi(){
	int luachon;
	do{
		showMenu();
		do{
			printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua chon khong hop le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tTong Tu 1 den n = %ld", Bt1_tongtu1DenN_De_Quy(n));
				break;
			}
			case 2:{
				int n;
				printf("\n\tNhap so can ");scanf("%d", &n);
				printf("\n\tCan cua Bieu thu = %lf", bt2_Can(n));
				break;
			}
			case 3:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tBieu thuc = %.3f", deQuy3(n));
				break;
			}
			case 4:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tGia tri cua bieu thu bai 4 = %f", deQuy4(n));
				break;
			}
			case 5:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tGia tri cua bieu thu bai 5 = %ld", deQuy5(n));
				break;
			}
			case 6:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tGia tri cua bieu thu bai 6 = %lf", deQuy6(n));
				break;
			}
			case 7:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("\n\tGia tri cua bieu thu bai 7 = %ld", deQuy7(n));
				break;
			}
			case 8:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("%d",tinhBieuThucBai6(n));
				break;
			}
			case 9:{
				int n;
				printf("\n\tNhap so nguyen : ");scanf("%d", &n);
				printf("%d",deQuy8(n));
				break;
			}
			case 10:{
				int n,a,q;
				printf("\n\tNhap U(n) cap :  ");scanf("%d", &n);
				printf("\n\tCap so nhan  co hang dau vao la ");scanf("%d", &a);
				printf("\n\tCong boi ");scanf("%d", &q);
				printf("\n\tCap so nhan thu U(n) = %ld", capSoNhan(n,a,q));
				break;
			}
		}
		
	}while(luachon != 0);
}

