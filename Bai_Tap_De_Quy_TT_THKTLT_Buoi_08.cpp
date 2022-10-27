/*
Ten :Doan Quang Phuong
*/
#include<stdio.h>
#include <conio.h>
#include<math.h>
#define MAXSIZE 100
void nhapMang(int Arr[MAXSIZE], int &n);
void xuatMang(int Arr[MAXSIZE], int n);
int tongChan(int arr[], int n);
void sapXepTangDan(int arr[], int n);
int timXnhiPhan(int arr[],int x, int left, int right);
int timMaxChan(int arr[], int n);
int timMax(int arr[], int n);
int timMax2(int arr[], int n);
int timMin(int arr[], int n);
int timMaxChan(int arr[], int n);
void xuatCacSoOViTriLe(int arr[], int n);
int demChuSoNguyenDuong(int n);
int demChuSoChanNguyenDuong(int n);
int timChuSoDauTien(int n);
void timChuSoDaoNguoc(int n);
int chuSoMin(int n);
int chuSoMax(int n);
int kiemTraSoToanLe(int n);
int bai8A(int n);
long bai8B(int n);
int bai8E(int n);
int bai8F(int n);
int bai10(int arr[],int x,int left , int right);

void showMenu();
void suLi();

int main(){
	suLi();


	return 0;
}

void showMenu(){
	printf("\n**************************************************************************");
	printf("\n*                                          MENU                          *");
	printf("\n**************************************************************************");
	printf("\n* 0 De ket thuc chuong trinh!!!!                                         *");
	printf("\n* 1Nhap/Xuat mang                                                        *");
	printf("\n* 2Tong Chan                                                             *");
	printf("\n**************************************************************************");
	printf("\n**************************************************************************");
}

void suLi(){
	int luachon,n,x;
	int arr[MAXSIZE];
	do{
		showMenu();
		do{
			printf("\n\tSu lua chon cua ban la : "); scanf("%d", &luachon);
			if (luachon < 0)
				printf("\nXin vui long nhap lai!!!");
		} while (luachon < 0);
		switch (luachon){
		case 1:{
				   nhapMang(arr, n);
				   sapXepTangDan(arr, n);
				   printf("\n\tMang sau khi xuat : ");
				   xuatMang(arr, n);
				   break;
		}
		case 2:{
				   printf("\n\tTong Chan = %d", tongChan(arr, n));
				   break;
		}
		case 3:{
				   printf("\n\tGia tri can tim : "); scanf("%d", &x);
				   if (timXnhiPhan(arr, x, 0, n - 1) == 1)
					   printf("\n\tTim Thay");
				   else
					   printf("\n\tKhong Tim Thay!!!");
				   break;
		}
		case 4:{
				   printf("\n\tCac Phan Tu O Vi Tri Le : ");
				   xuatCacSoOViTriLe(arr, n);
				   break;
		}
		case 5:{
			printf("\n\tMax : %d", timMax(arr,n));
			printf("\n\tMin: %d", timMin(arr,n));
			break;
		}
		case 6:{
			printf("\n\tMAX CHAN : %d ", timMaxChan(arr,n));
			break;
		}
		case 7:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
			printf("\n\tDem Chu So = %d", demChuSoNguyenDuong(n));
			printf("\n\tDem Chu So Chan = %d", demChuSoChanNguyenDuong(n));
			printf("\n\tChu So Dau Tien = %d", timChuSoDauTien(n));
			printf("\n\tChu So Dao Nguoc la %d ", bai8B(n));
			break;
		}
		case 8:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
//			printf("\n\tChu So Min = %d ", chuSoMin(n));
			printf("\n\tChu So Max = %d ", chuSoMax(n));
			break;
		}
		case 9:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
			if(kiemTraSoToanLe(n) != 0)
				printf("\n\tToan Le");
			else
				printf("\n\tKhong Toan Le");
			break;
		}
		case 10:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
			printf("Chu So [%d] Dau Tien : %d",n,bai8A(n));
			break;
		}
		case 11:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
			printf("\n\tSo Dao Nguoc la %ld", bai8B(n));
			break;
		}
		case 12:{
			printf("Nhap So Nguyen Duong : ");scanf("%d", &n);
			if(bai8E(n) == 1)
				printf("Toan Le");
			else
				printf("Khong Toan le!!!");
			if(bai8F(n) == 1)
				printf("\nToan Chan");
			else
				printf("\nKhong Toan Chan!!!");
			break;
		}
		case 13:{
			printf("\n\tGia tri can tim : "); scanf("%d", &x);
			if(bai10(arr,x,0,n-1) == 1)
				printf("Tim Thay!!!");
			else
				printf("\n\tKhong Tim Thay!!!");
		}
		
		}

	} while (luachon != 0);
}

void nhapMang(int arr[MAXSIZE], int &n){
	do{
		printf("\n\tSo luong phan tu : "); scanf("%d", &n);
		if (n <= 0)
			printf("\n\tVui long nhap lai!!!");
	} while (n <= 0);
	for (int i = 0; i < n; i++){
		printf("\nArr[%d] = ", i); scanf("%d", &arr[i]);
	}
}

void xuatMang(int arr[MAXSIZE], int n){
	for (int i = 0; i < n; i++){
		printf("%3d", arr[i]);
	}
}

int tongChan(int arr[], int n){
	if (n == 1)
	{
		if (arr[0] % 2 == 0)
			return arr[0];
		return 0;
	}
	if (arr[n - 1] % 2 == 0)
		return arr[n - 1] + tongChan(arr, n - 1);
	return tongChan(arr, n - 1);
}

int tongLe(int arr[], int n){
	if (n == 1)
	{
		if (arr[0] % 2 == 0)
			return arr[0];
		return 0;
	}
	if (arr[n - 1] % 2 != 0)
		return arr[n - 1] + tongChan(arr, n - 1);
	return tongChan(arr, n - 1);
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void sapXepTangDan(int arr[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

int timXnhiPhan(int arr[], int x, int left, int right){
	if(left > right)
		return -1;
		int mid = (left + right) / 2;
		if (arr[mid] == x)
			return 1;
		else if (arr[mid] > x)
			return timXnhiPhan(arr, x, 0, mid - 1);
		return timXnhiPhan(arr, x, mid + 1, right);
} 

int max2So(int a, int b){
	return a > b ? a : b;
}

int min2So(int a, int b){
	return a < b ? a : b;
}

int timMax(int arr[], int n){
	if (n == 1)
	return arr[0];
		return max2So(timMax(arr,n - 1),arr[n - 1]);

}

//                  Cach 2 

int timMax2(int arr[], int n){
	if(n == 1)
		return arr[0];
	else
	{
		int x = timMax2(arr,n - 1);
		if(arr[n - 1] > x)
			return arr[n - 1];
		return x;
	}
}

//==============================

int timMin(int arr[], int n){
	if (n == 1)
	return arr[0];
		return min2So(timMin(arr,n - 1),arr[n - 1]);

}

void xuatCacSoOViTriLe(int arr[], int n){
	if (n == 1)
		return;
	xuatCacSoOViTriLe(arr, n - 1);
	if ((n - 1) % 2 != 0)
		printf("%3d ", arr[n - 1]);
}

int max2ChanSo(int a, int b){
	if(a % 2 == 0 && b % 2 == 0 && a > b)
		return a;
	return b;
}

int timMaxChan(int arr[], int n){
		if (n == 1){
			if(arr[0] % 2 == 0)
				return arr[0];
			return -1;
		}
		return max2ChanSo(timMaxChan(arr,n - 1),arr[n - 1]);
}

int demSoPhanTuLonHon20(int arr[], int n){
	if(n == 1){
		if(arr[0] > 20)
			return 1;
		return 0;
	}
	if(arr[n - 1] > 20)
		return 1 + demSoPhanTuLonHon20(arr,n - 1);
	return  demSoPhanTuLonHon20(arr,n - 1);
}

int demChuSoNguyenDuong(int n){
	if(n == 0)
		return 0;
	return 1 + demChuSoNguyenDuong(n / 10);
}

int demChuSoChanNguyenDuong(int n){
	if(n == 0)
		return 0;
	int k = n % 10;
	if(k % 2 == 0)
		return 1 + demChuSoChanNguyenDuong(n / 10);
	return demChuSoChanNguyenDuong(n / 10);
}

int timChuSoDauTien(int n){
	if(n == 0)
		return 0;
	if(n >= 10)
		return timChuSoDauTien(n/10);
	return n;
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

int kiemTraSoToanLe(int n){
	if(n == 0)
		return 0;
	int k = n % 10;
	if(k % 2 == 0)
		return 0;
	return kiemTraSoToanLe(n / 10);
}

int Bai9_ToHop(int k, int n){
	if(k == 0 || k == n)
		return 1;
	return Bai9_ToHop(k,n - 1) + Bai9_ToHop(k - 1,n - 1);
}

//==========================================================

int bai8A(int n){
	if(n < 10)
		return n;
	return bai8A(n/10);
}

long bai8B(int n){
	if(n == 0)
		return 0;
	int len = demChuSoNguyenDuong(n);
	return n % 10 * (pow(10,len-1)) + bai8B(n/10);
}

int bai8E(int n){
	if(n == 0)
		return 1;
	int i = n % 10;
	if(i % 2 == 0)
		return 0;
	else
		return bai8E(n / 10);
}

int bai8F(int n){
	if(n == 0)
		return 1;
	int i = n % 10;
	if(i % 2 != 0)
		return 0;
	else
		return bai8F(n / 10);
}

int bai10(int arr[],int x,int left , int right){
	if(left > right)
		return 0;
	int mid = (left + right) / 2;
	if(arr[mid] == x)
		return 1;
	else if(arr[mid] >  x)
		return bai10(arr,x,left,mid - 1);
	else
		return bai10(arr,x,mid + 1,right);
}
//===================================================================
void bai10(int &m , int n){
	do{
		printf("Doan m = ");scanf("%d", &m);
	}
	if(m > n)
		return;
	for(int i = m;i <= n;i++){
		printf("")
	}
}








