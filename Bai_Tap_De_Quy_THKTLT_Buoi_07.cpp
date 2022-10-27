#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAXSIZE 100
typedef int Itemtype;
/*
ten:Doan Quang Phuong
mssv:2001216062
Mon : Thuc Hanh Ki Thuat Lap Trinh_ST4_4_6
Bai kiem tra so 1
*/
void nhapSoNguyen(int &n);
void nhapSoNguyen2(int &n);
void nhapSoThuc(float &n);
int BaiTap1A(int n);
int nonRecursion1A(int n);
double BaiTap1B(int n);
double nonRecursion1B(int n);
double BaiTap1C(int n);
double BaiTap1D(int n);
long BaiTap1E(int n);
long nonRecursion1E(int n);
double BaiTap1F(int n);
double nonRecursion1F(int n);
double BaiTap1G(int n);
double nonRecursion1G(int n);
int uocChungLonNhat(int a, int b);
int tinhSoHangThuNCapSoCong(int a, int r, int n);
long capSoNhan(int n,int a, int q);
long tinhBieuThucBai6(int n);
double Bai9_1(int n);
long Bai9_2(int n);
int tongSoTu1DenN(int N);
int Bai9_3(int n);
double Bai9_4(int n);
int tinhSoHangThuNCapSoCong(int a, int r, int n);
int daySoFibonacci(int n);
long Yn(int n);
long An(int n);
int Fi(int n);
void showMenu();
void suLi();
int main(){
	suLi();

	return 0;
}
void showMenu(){
	printf("\n*******************************************************");
	printf("\n*                         MENU                        *");
	printf("\n*******************************************************");
	printf("\n* 0 De Ket Thuc Chuong Trinh                          *"); 
	printf("\n*******************************************************");
	printf("\n*******************************************************");

}
void suLi(){
	int luachon;
	do{
		showMenu();
		do{
			printf("\n\tSu Lua Chon Cua Ban la : "); scanf("%d", &luachon);
			if (luachon < 0)
				printf("\n\tVui long nhap lai lua chon cua ban!!!");
		} while (luachon < 0);
		switch (luachon){
		case 1:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %d", BaiTap1A(n));
				   printf("\n\t\tTong Bieu Thuc Khu De Quy = %d", nonRecursion1A(n));
				   break;
			}
		case 2:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %lf", BaiTap1B(n));
				   printf("\n\t\tTong Bieu Thuc Khu De Quy = %lf", nonRecursion1B(n));
				   break;
			}
		case 3:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %lf", BaiTap1C(n));
				
				   break;
			}
		case 4:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %lf", BaiTap1D(n));
				   break;
			}
		case 5:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %ld", BaiTap1E(n));
				   printf("\n\t\tTong Bieu Thuc Khu De Quy = %ld", nonRecursion1E(n));
				   break;
			}                   
		case 6:{
				   int n;
				   nhapSoNguyen(n);
				   printf("\n\t\tTong Bieu Thuc = %lf", BaiTap1F(n));
				   printf("\n\t\tTong Bieu Thuc Khu De Quy = %lf", nonRecursion1F(n));
				   break;
			}
			case 7:{
					int n;
				    nhapSoNguyen(n);
				    printf("\n\t\tTong Bieu Thuc = %lf", BaiTap1G(n));
				    printf("\n\t\tTong Bieu Thuc Khu De Quy = %lf", nonRecursion1G(n));
				break;
			}	
			case 8:{
				int a,b;
				nhapSoNguyen2(a);
				nhapSoNguyen2(b);
				printf("\n\tUoc Chung Lon Nhat : %d", uocChungLonNhat(a,b));
				
				break;
			}
			case 9:{
				int n;
				nhapSoNguyen(n);
				printf("\n\tGia tri Bieu Thuc 1 = %lf", Bai9_1(n));
				printf("\n\tGia tri Bieu Thuc 2 = %ld", Bai9_2(n));
				printf("\n\tGia tri Bieu Thuc 3 = %d", Bai9_3(n));
				printf("\n\tGia tri Bieu Thuc 4 = %lf", Bai9_4(n));
				break;
			}
			case 10:{
				int a,n,r;
				printf("\n\tSo Hang Dau = ");scanf("%d", &a);
				printf("\n\tSo Cong Boi = ");scanf("%d", &r);
				printf("\n\tSo Hang n = ");scanf("%d", &n);
				printf("\n\tTong So Hang Thu %d = %d" , n, tinhSoHangThuNCapSoCong(a,r,n));
				break;
			}
			case 11:{
				int n;
				nhapSoNguyen(n);
				printf("\n\t\tGia tri bieu thuc = %ld", tinhBieuThucBai6(n));
				break;
			}
			case 12:{
				int n;
				nhapSoNguyen(n);
				printf("\n\tSo Fibonacci Thu %d la %d", n,daySoFibonacci(n));
				printf("\n\tSo Fibonacci Nho hon %d la %d", n,Fi(n));
				break;
			}
			case 13:{
				int n;
				nhapSoNguyen(n);
				printf("\n\tY[%d] = %ld", n,Yn(n));
				break;
			}
			case 14:{
				int n;
				nhapSoNguyen(n);
				printf("\n\tA[%d] = %ld", n,An(n));
				break;
				break;
			}
		}

	} while (luachon != 0);
}
void nhapSoNguyen(int &n){
	do{
		printf("\n\tNhap So Nguyen : "); scanf("%d", &n);
		if (n <= 0)
			printf("\n\tVui long nhap lai!!!");
	} while (n <= 0);
}
void nhapSoNguyen2(int &n){
	do{
		printf("\n\tNhap So Nguyen : "); scanf("%d", &n);
		if (n < 0)
			printf("\n\tVui long nhap lai!!!");
	} while (n < 0);
}
void nhapSoThuc(float &n){
		printf("\n\tNhap So Thuc : "); scanf("%f", &n);	
}
int BaiTap1A(int n){
	if (n == 1)
		return 1;
	return n + BaiTap1A(n - 1);
}
int nonRecursion1A(int n){
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += i;
	}
	return sum;
}
double BaiTap1B(int n){
	if (n == 1)
		return sqrt((double)5);
	return sqrt((double)5) + BaiTap1B(n - 1);//sai
}
double nonRecursion1B(int n){
	double sum = 0;
	for (int i = 1; i <= n; i++){
		sum += (double)(sqrt((double)5 + sum));//sai
	}
	return sum;
}
double BaiTap1C(int n){
	if (n == 1)
		return 0.5;
	return  (double)n / (n + 1) + BaiTap1C(n - 1);
}

double BaiTap1D(int n){
	if (n == 0)
		return 1;
	return (float)1 / (2 * n + 1) + BaiTap1D(n - 1);
}
long BaiTap1E(int n){
	if (n == 1)
		return 2;
	return n *(n + 1) + BaiTap1E(n - 1);
}
long nonRecursion1E(int n){
	long sum = 0;
	for (int i = 1; i <= n; i++){
		sum += i*(i + 1);
	}
	return sum;
}
long tinhGiaiThua(int n){
	long sum = 1;
	for (int i = 2; i <= n; i++){
		sum *= i;
	}
	return sum;
}
double BaiTap1F(int n){
	if (n == 1)
		return (double)(1 * tinhGiaiThua(2) / (2 + sqrt((double)3)));
	return (double)(n * tinhGiaiThua(n + 1) / ((n + 1) + sqrt((double)(n + 2)))) + BaiTap1F(n - 1);
}
double nonRecursion1F(int n){
	double sum = 0;
	for (int i = 1; i <= n; i++){
		sum += (double)(i * tinhGiaiThua(i + 1) / ((i + 1) + sqrt((double)(i + 2))));
	}
	return sum;
}
double BaiTap1G(int n){
	if (n == 1)
		return (double)((1 + sqrt((double) 1 + 2))/ (2 + sqrt((double)tinhGiaiThua(3))));
	return (double)((n + sqrt((double)(n + n + 1))) / ((n + 1) + sqrt((double)(tinhGiaiThua(n + 2)))))+ BaiTap1G(n - 1);
}
double nonRecursion1G(int n){
	double sum = 0;
	for(int i = 1;i <= n;i++){
		sum += (double)((i + sqrt((double) (i + i + 1)))/ ((i + 1) + sqrt((double)tinhGiaiThua(i + 2))));
	}
	return sum;
}
int uocChungLonNhat(int a, int b){
	if(b == 0)
		return a;
	if(a > b)
		return uocChungLonNhat(b,a - b);
	return uocChungLonNhat(a,b - a);
}
double Bai9_1(int n){
	if(n == 1)
		return 1.0/6;
	return 1.0/(n*(n + 1)*(n + 2)) + Bai9_1(n - 1);
}
long Bai9_2(int n){
	if(n == 1)
		return 1;
	return pow(n,2) + Bai9_2(n - 1);
}
int tongSoTu1DenN(int N){
	int sum = 0;
	for(int i = 1;i <= N;i++){
		sum += i;
	}
	return sum;
}
int Bai9_3(int n){
	if(n == 1)
		return 1;
	return tongSoTu1DenN(n) + Bai9_3(n - 1);
}
double Bai9_4(int n){
	if(n == 1)
		return -3.0/2;
	return (double)pow(-1,n)*((2*n - 1) + 2*n)/ (tinhGiaiThua(2*n)) + Bai9_4(n - 1);
}
int tinhSoHangThuNCapSoCong(int a, int r, int n){//U(n)= u1 + (n - 1)*r
	if(n == 1)//Diem neo hay Con goi la dien dung
		return a;//
	return r + tinhSoHangThuNCapSoCong(a,r,n - 1);
}
// bai 5 tuong tu
long capSoNhan(int n,int a, int q){
	if(n == 1)
		return a;
	return capSoNhan(n - 1,a,q) * q;
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
int daySoFibonacci(int n){
	if(n <= 2)
		return 1;
	return daySoFibonacci(n - 1) + daySoFibonacci(n - 2);
}
int Fi(int n){
	int F=0,F1=1,F2=1;
	if(n==1) return 0;
	if(n==2) return 1;
	while(F1+F2<n){
		F=F1+F2;
		F1=F2;
		F2=F;
	}	
	return F;
}

// Bai 15

long An(int n){
	int sum = 0;
	if(n == 1)
		return n;
	for(int i = 1;i <= n;i++){
		sum += n * (An(n - 1));
	}
	return n * (An(n - 1));
}
// Bai 16
long Yn(int n){
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else if(n == 3)
		return 3;
	else
	{
		return Yn(n - 1) + 2 * Yn(n - 2) + 3 * Yn(n - 3);
	}	
}




