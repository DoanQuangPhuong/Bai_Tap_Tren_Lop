#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#define MAXSIZE 100
typedef int Itemtype;//Khai bao 1 kieu du lieu nguoi dung
void thucThi();
void input1Chieu_De_Quy(int arr[], int n);
void ouput1Chieu_De_Quy(int arr[], int n);
int tongCacPhanTuTrongMang(int arr[], int n);
int tongCacPhanTuChanTrongMang(int arr[], int n);
long long  tichCacPhanTuTrongMang(int arr[], int n);
void xuatCacSoNguyenToTrongMang(int arr[], int n);
void xuatCacSoHoanThientrongMang(int arr[], int n);
int max1Chieu(int arr[], int n);
int min1Chieu(int arr[], int n);
int min1Chieu2(int arr[], int n);
int demDuong(int arr[], int n);
int demChan(int arr[], int n);
int demLe(int arr[], int n);
int demAm(int arr[], int n);
int chanCuoiCung(int arr[], int n);
int viTrichanCuoiCung(int arr[], int n);
int max(int arr[], int fisrt, int last);
int sumLe(int arr[], int n);
void showMenu();

int main(){
	thucThi();
	
	
	return 0;
}

void nhapSoNhguyenN(int &n){
	do{
		scanf("%d", &n);
		if(n < 0)
			printf("\nVui long nhap lai!!!");
	}while(n < 0);
}

void showMenu(){
	printf("\n**************************************************");
	printf("\n*                      MENU                      *");
	printf("\n**************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh                   *");
	printf("\n* 1 Nhap/Xuat mang 1 chieu                       *");
	printf("\n**************************************************");	 
}

void thucThi(){
	int n;
	Itemtype arr[MAXSIZE];
	int luachon;
	do{
		showMenu();
		printf("\nSu lua chon cua ban la: ");
		nhapSoNhguyenN(luachon);
		switch(luachon){
			case 1:{
					do{
					printf("\n\t\tSo Luong Phan Tu : ");scanf("%d", &n);
					if(n <= 0)
						printf("\n\tVui long Nhap Lai!!!!");
					}while(n <= 0);
					input1Chieu_De_Quy(arr,n);
					printf("\n\t\tMANG 1 CHIEU : ");
					ouput1Chieu_De_Quy(arr,n);
				break;
			}
			case 2:{
//				printf("\n\tTong = %d", tongCacPhanTuTrongMang(arr,n));
				printf("\n\tTong Chan = %d", tongCacPhanTuChanTrongMang(arr,n));
				printf("\n\tTich = %lld", tichCacPhanTuTrongMang(arr,n));
				break;
			}
			case 3:{
				printf("\n\tSo nguyen to : ");
				xuatCacSoNguyenToTrongMang(arr,n);
				printf("\n\tSo Hoan Thien : ");
				xuatCacSoHoanThientrongMang(arr,n);
				break; 
			}
			case 4:{
				printf("\n\tMAX = %d", max1Chieu(arr,n));
				printf("\n\tMAX 2  = %d", max(arr,0,n - 1));
				printf("\n\tMIN = %d", min1Chieu(arr,n));
				break;
			}	
			case 5:{
				printf("\n\tCo %d so Duong", demDuong(arr,n));
				printf("\n\tCo %d so Am", demAm(arr,n));
				printf("\n\tCo %d so Chan", demChan(arr,n));
				printf("\n\tCo %d so Le", demLe(arr,n));
				break;
			}
			case 6:{
				if(chanCuoiCung(arr,n) != 0)
					printf("\n\tChan Cuoi = %d", chanCuoiCung(arr,n));
				else
				printf("\n\tKhong co phan tu chan trong mang!!!");
				break;
			}
			case 7:{
				if(viTrichanCuoiCung(arr,n) != 0)
					printf("\n\tPhan Tu Chan Cuoi Nam O Vi Tri Thu %d", viTrichanCuoiCung(arr,n));
				else
				printf("\n\tKhong co phan tu chan trong mang!!!");
				break;
			}
			case 8:{
				printf("\n\tMin = %d", min1Chieu2(arr,n));
				break;
			}
			case 9:{
				printf("\n\t\tTong Le : %d", sumLe(arr,n));
				break;
			}
		}
	}while(luachon != 0);
} 

void input1Chieu_De_Quy(int arr[], int n){
	if(n == 0)
		return;
	input1Chieu_De_Quy(arr,n - 1);
	printf("\narr[%d] = ", n - 1);scanf("%d", &arr[n - 1]);
}

void ouput1Chieu_De_Quy(int arr[], int n){
	if(n == 0)
		return;
	ouput1Chieu_De_Quy(arr,n - 1);
	printf("%4d",arr[n - 1]);
}

int tongCacPhanTuTrongMang(int arr[], int n){
	if(n == 1)
		return arr[0];
	return tongCacPhanTuTrongMang(arr,n - 1) + arr[n - 1];
	
}

long long  tichCacPhanTuTrongMang(int arr[], int n){
	if(n == 1)
		return arr[0];
	return tichCacPhanTuTrongMang(arr,n - 1) * arr[n - 1];
	
}

int tongCacPhanTuChanTrongMang(int arr[], int n){
	if(n == 0)
		return 0;
	int sum = tongCacPhanTuChanTrongMang(arr,n - 1);
	if(arr[n - 1] % 2 == 0)
		sum += arr[n - 1];
	return sum;
	
}


bool kiemTraSoNguyenTo(int n){
	if(n < 2)
		return 0;
	for(int i = 2;i <= sqrt(n);i++)
	{
		if(n % 2 == 0)
			return 0;
	}
	return 1;
}

bool kiemTraSoHoanThien(int n){
	int sum = 0;
	for(int i = 1;i < n;i++){
		if(n % i == 0)
			sum += i ;
	}
	return (sum != n ? false : true);
}

void xuatCacSoNguyenToTrongMang(int arr[], int n){
	if(n == 0)
		return;
	xuatCacSoNguyenToTrongMang(arr,n - 1);
	if(kiemTraSoNguyenTo(arr[n - 1]) == 1)
		printf("%3d", arr[n - 1]);
}

void xuatCacSoHoanThientrongMang(int arr[], int n){
	if(n == 0)
		return;
	xuatCacSoHoanThientrongMang(arr,n - 1);
	if(kiemTraSoHoanThien(arr[n - 1]) == 1)
		printf("%3d", arr[n - 1]);
}

int max(int arr[], int fisrt, int last){
	if(fisrt == last)
		return arr[fisrt];
	int max1C = max(arr,fisrt + 1,last);
	if(max1C < arr[fisrt])
		max1C = arr[fisrt];
	return max1C;
}

int max1Chieu(int arr[], int n){
	if(n == 1)
		return arr[0];
	if(max1Chieu(arr,n - 1) > arr[n - 1])
			return max1Chieu(arr,n - 1);
		return arr[n - 1];
}

int min1Chieu(int arr[], int n){
	if(n == 1)
		return arr[0];
	if( min1Chieu(arr,n - 1) < arr[n - 1])
			return min1Chieu(arr,n - 1);
		return arr[n - 1];
}

//                    C2

int min1Chieu2(int arr[], int n){
	if(n == 1)
		return arr[0];
	int min = min1Chieu2(arr,n - 1);
	if( arr[n - 1] < min)
		min = arr[n - 1];
	return min;
}

int demDuong(int arr[], int n){
	if(n == 0)
		return 0;
	int count = demDuong(arr,n - 1);;
	if(arr[n - 1] > 0)
		count++;
	return count;
}


int demAm(int arr[], int n){
	if(n == 0)
		return 0;
	int count = demAm(arr,n - 1);;
	if(arr[n - 1] < 0)
		count++;
	return count;
}

int demChan(int arr[], int n){
	if(n == 0)
		return 0;
	int count = demChan(arr,n - 1);;
	if(arr[n - 1] % 2 ==  0)
		count++;
	return count;
}

int demLe(int arr[], int n){
	if(n == 0)
		return 0;
	int count = demLe(arr,n - 1);;
	if(arr[n - 1] % 2 !=  0)
		count++;
	return count;
}

//									Chan Cuoi Cung

int chanCuoiCung(int arr[], int n){
	if(n == 0)
		return 0;
	int chanCuoi = chanCuoiCung(arr,n - 1);
	if(arr[n - 1] % 2 == 0)
		chanCuoi = arr[n - 1];
	return chanCuoi;
}

int viTrichanCuoiCung(int arr[], int n){
	if(n == 0)
		return 0;
	int viTri = viTrichanCuoiCung(arr,n - 1);
	if(arr[n - 1] % 2 == 0)
		viTri = n - 1;
	return viTri;
}

int sumLe(int arr[], int n){
	if(n == 1){
		if(arr[0] % 2 != 0)
			return arr[0];
		return 0;
	}
	int TongLe = sumLe(arr,n - 1);	
		if(arr[n - 1] % 2 != 0)
			TongLe += arr[n - 1];
	return TongLe;
}







