#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
void showMenu();
int demChuSoDeQuy(int n);
int tinhTichChuSoDeQuy(int n);
int tinhTongChuSoDeQuy(int n);
int demChuSoLeDeQuy(int n);
int timChuSoDauTien(int n);
long soDaoNguoc(int n);
void soDaoNguoc2(int n);
bool kiemTraToanChan(int n);
float tinhTongBieuThuc1(int n);
int uocSoLeLonNhat(int n);
float tinhTongBieuThuc2(int x, int n);
int tongChuSoLe(int n);
int tongChuSoChan(int n);
int kiemTraSoHoanThien(int n);
int checkNguyenTo(int n);
int tongChuSoHoanThien(int n);
int tongChuSoNguyenTo(int n);
int chuSoMin(int n);
int chuSoMax(int n);
int fibonacci(int n);
int Fibonacci_Mang_Toi_Uu(int n, int arr[100]);
void odd(int n);
void even(int n);
void fun1(int n);
int fun(int n);
void nSoFibonacciDauTien(int n);
int maxFibonacci(int n);
int minFibonacci(int n);
int DeQuyDuoi(int n,int count = 0);
void suLi();
int main(){
	suLi();

	
	return 0;
}
void suLi(){
int luachon,n;
	do{
		showMenu();
		do{
			printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua chon khong hop le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\tSo chu so trong n la %d", demChuSoDeQuy(n));
				break;
			}
			case 2:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\tTong Chu so  = %d", tinhTongChuSoDeQuy(n));
				printf("\n\tTich chu so = %d", tinhTichChuSoDeQuy(n));
				break;
			}	
			case 3:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n < 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n < 0);
				printf("\n\tCo %d chu so LE", demChuSoLeDeQuy(n));
				break;
			}
			case 4:{
				printf("\n\tChu so Dau tien la %d", timChuSoDauTien(n));
				break;
			}
			case 5:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
//				printf("\n\tSo dao nguoc : %ld", soDaoNguoc(n));
				printf("\n\tSo dao nguoc 2 : ");
				soDaoNguoc2(n);
				break;
			}
			case 6:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				if(kiemTraToanChan(n) == true)
					printf("\n\tSo vua nhap TOAN CHAN");
				else
					printf("\n\tSo KHONG  TOAN CHAN!!!");
				break;
			}
			case 7:{
				printf("\n\tGia tri cua bieu thuc = %.3f", tinhTongBieuThuc1(n));
				break;
			}
			case 8:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\tUoc so LE lon nhat la %d", uocSoLeLonNhat(n));
				break;
			}
			case 9:{
				int x;
				printf("\n\tNhap gia tri x = ");scanf("%d", &x);
				printf("\n\tTong gia tri bieu  thuc 2 la %.3f", tinhTongBieuThuc2(x,n));
				break;
			}
			case 10:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\t\tTong Chu So Le = %d", tongChuSoLe(n));
				printf("\n\t\tTong Chu So Le = %d", tongChuSoChan(n));
				break;
			}
			case 11:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\t\tTong Chu So Hoan Thien = %d", tongChuSoHoanThien(n));
				printf("\n\t\tTong Chu So Nguyen To = %d", tongChuSoNguyenTo(n));
				break;
			}
			case 12:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
//				printf("\n\t\tChu So Min = %d", chuSoMin(n));
				printf("\n\t\tChu So Max = %d", chuSoMax(n));
				break;
			}
			case 13:{
				int arr[100];
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\tFibonacci = %d", fibonacci(n));
				printf("\n\tFibonacci = %d", Fibonacci_Mang_Toi_Uu(n,arr));
				break;
			}
			case 14:{
				int n = 1;
				odd(n);
				break;
			}
			case 15:{
				int n = 4;
				fun1(n);
				break;
			}
			case 16:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				printf("\n\tGia tri = %d", fun(n));
				break;
			}
			case 17:{
				do{
					printf("\n\tNhap so nguyen : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long nhap lai!!!");
				}while(n <= 0);
				nSoFibonacciDauTien(n);
				printf("\n\tMAX Fibonacci = %d ", maxFibonacci(n));
				printf("\n\tMIN Fibonacci = %d ", minFibonacci(n));
				break;
			}
			
		}
		
	}while(luachon != 0);
}
void showMenu(){
	printf("\n***************************************************************");
	printf("\n*                                MENU                          ");
	printf("\n***************************************************************");
	printf("\n* 0 De ket thuc chuong trinh                                   ");
	printf("\n* 1 Dem chu so [DE QUY]                                        ");
	printf("\n* 2 tong/tich chu so nguyen duong[DE QUY]                      ");
	printf("\n* 3 Dem chu so le trong so nguyen duong[DE QUY]                ");
	printf("\n* 4 Tim Chu So Dau Tien trong so nguyen duong[DE QUY]          ");
	printf("\n* 5 So dao nguoc                                               ");
	printf("\n* 6 Kiem tra so toan chan                                      ");
	printf("\n* 7 Tinh gia tri cua Bieu thuc                                 ");
	printf("\n* 8 Uoc so le lon nhat                                         ");
	printf("\n* 9 Tinh gia tri cua Bieu thuc 2                               ");
	printf("\n***************************************************************");
	printf("\n***************************************************************");
}
int demChuSoDeQuy(int n){
	if(n == 1)
		return 1;
	return 1 + demChuSoDeQuy(n / 10);
}
int tinhTongChuSoDeQuy(int n){
	if(n < 10)
		return n;
	return n % 10 + tinhTongChuSoDeQuy(n / 10);
}
int tinhTichChuSoDeQuy(int n){
	if(n < 10)
		return n;
	return n % 10 * tinhTichChuSoDeQuy(n / 10);
}
int demChuSoLeDeQuy(int n){
	if(n < 10){
		if(n % 2 == 0)
			return 0;
		return 1;
	}
	int chuSo = n % 10;
	if(chuSo % 2 != 0)//la so le
	{
		return 1 + demChuSoLeDeQuy(n / 10);
	}
	return demChuSoLeDeQuy(n / 10);//khong phai so le chay vao ham nay
}



int timChuSoDauTien(int n){
	if(n < 10)
		return n;
	return timChuSoDauTien(n / 10);
}
long soDaoNguoc(int n){
	if(n == 0)
		return 0;
	int len = demChuSoDeQuy(n);//Do Dai Cua So Nguyen Duong n  VD: n = 4321
	return n % 10 *(pow(10,len - 1)) + soDaoNguoc(n / 10);//1*(10^3) + 2*(10^2) + 3*(10^1) + 4*(10^0)=1234
}
//              cach 2
void soDaoNguoc2(int n){
	if(n != 0)
	{
		printf("%d", n % 10);
		soDaoNguoc2(n/10);
	}
}
bool kiemTraToanChan(int n){
	if(n == 0)
		return true;
	int chuSo = n % 10;
	if(chuSo % 2 != 0)
		return false;
	return kiemTraToanChan(n / 10);
}

// S = 1 + 1/1+2 + 1/1+2+3 + ... + 1/1+2+3+..+ n
float tinhTongBieuThuc1(int n){//Dung phuong phap DE QUY vi tuyen
	if(n == 1)
		return 1;
	float tong = 1;
	for(int i = 2;i <= n;i++){
		tong += i;
	}
	return tinhTongBieuThuc1(n - 1) + 1.0/tong;
}

//Tim uoc so le lon nhat VD: 100 la 25
int uocSoLeLonNhat(int n){
	if(n % 2 != 0)
		return n;
	return uocSoLeLonNhat(n / 2);
}
//			Tinh gia tri bieu thuc 2
//S = x + x^2/2! + x^3/3! + x^4/4!+...+x^n/n!
float tinhTongBieuThuc2(int x, int n){
	if(n == 1)
		return x;
	int tich = 1;
	for(int i = 1;i <= n;i++){
		tich *= i;
	}
	return tinhTongBieuThuc2(x,n - 1) + (float)pow(x,n) / tich;
}
int tongChuSoLe(int n){
	if(n == 0)
		return 0;
	else
	{
		int i = n % 10;
		if(i % 2 != 0)
			return i + tongChuSoLe(n / 10);
		else
			return tongChuSoLe(n / 10);
	}
}
int tongChuSoChan(int n){
	if(n == 0)
		return 0;
	else
	{
		int i = n % 10;
		if(i % 2 == 0)
			return i + tongChuSoChan(n / 10);
		else
			return tongChuSoChan(n / 10);
	}
}
int kiemTraSoHoanThien(int n){
	int sum = 0;
	for(int i = 1;i < n;i++){
		if(n % i == 0)
			sum += i;
	}
	return (sum != n ? 0 : 1);
}
int checkNguyenTo(int n){
	if(n < 2)
		return 0;
	for(int i = 2;i <= sqrt(n);i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int tongChuSoHoanThien(int n){
	if(n == 0)
		return 0;
	else
	{
		int i = n % 10;
		if(kiemTraSoHoanThien(i) == 1)
			return i + tongChuSoHoanThien(n / 10);
		else
			return tongChuSoHoanThien(n / 10);
	}
}
int tongChuSoNguyenTo(int n){
	if(n == 0)
		return 0;
	else
	{
		int i = n % 10;
		if(checkNguyenTo(i) == 1)
			return i + tongChuSoNguyenTo(n / 10);
		else
			return tongChuSoNguyenTo(n / 10);
	}
}

int chuSoMin(int n){
	if(n < 10)
		return n;
	if((n % 10) < chuSoMin(n/10))
		return n % 10;
	return chuSoMin(n/10);
	
}
int chuSoMax(int n){
		if(n < 10)
		return n;
	if((n % 10) > chuSoMax(n/10))
		return n % 10;
	return chuSoMax(n/10);
}

int fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int Fibonacci_Mang_Toi_Uu(int n, int arr[100])
{
	if(arr[n] != 0)
		return arr[n];
	if(n <= 2)
	{
		arr[1] = 1;
		arr[2] = 1;
		return 1;
	}
	arr[n] = Fibonacci_Mang_Toi_Uu(n - 1,arr) + Fibonacci_Mang_Toi_Uu(n - 2,arr);
	return arr[n];
}
//Swap de in cac So Tu 1 den 10 Theo cach ma khi so le Cong 1 So Chan Tru Di 1
//========================================================================
void odd(int n){
	if(n <= 10){
		printf("%4d", n + 1);
		n++;
		even(n);
	}
}
void even(int n){
	if(n <= 10){
		printf("%3d", n - 1);
		n++;
		odd(n);
	}
}
//========================================================================
//Determine, how many number of times the star will be printed on the screen
// Xac Dinh Xem Ngoi Sao Se in tren man hinh bao nhieu lan
void fun1(int n){
	if(n > 1)
		fun1(n - 1);
	for(int i = 0;i < n;i++){
		printf(" * ");
	}
}
//========================================================================
//consider  the following c function
//xem xét ch?c nang c sau dây
int fun(int n){
	int x = 1,k;
	if(n == 1)
		return x;
	for(k = 1;k < n;k++)
		x +=  fun(k) * fun(n - k);
	return x;
}
//========================================================================
void nSoFibonacciDauTien(int n){
	printf("\n\t\t%d So Fibonacci Dau Tien la : ",n);
	for(int i = 1;i <= n;i++){
		printf("%3d", fibonacci(i));
	}
}
//========================================================================
int maxFibonacci(int n){
	int max = fibonacci(1);
	for(int i = 2;i <= n;i++){
		if(fibonacci(i) > max)
			max = fibonacci(i);
	}
	return max;
}
//========================================================================
int minFibonacci(int n){
	int min = fibonacci(1);
	for(int i = 2;i <= n;i++){
		if(fibonacci(i) < min)
			min = fibonacci(i);
	}
	return min;
}





