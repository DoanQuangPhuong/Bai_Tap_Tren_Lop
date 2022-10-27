#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAXSIZE 100

void nhapChuoi(char str[]);
void xuatChuoi(char str[]);
bool kiemTraKiTuTrongChuoi(char str[], char c);
void kiemTraChuoiCoToanKiTuSoHayKhong(char str[]);
void doiKiTuiDauThanhChuHoaCacKiTuKhacThanhChuThuong(char str[]);
void chuanHoaChuoi(char str[]);
int demSoTuTrongChuoi(char str[]);
void timKiemTenTrongChuoiHoTen(char str[], char arr[][MAXSIZE], char firstName[]);
void timKiemTenTrongChuoiHoTen2(char str[], char firstName[]);
void tachHoLotVaTenTrongChuoi(char str[], char arr[][MAXSIZE]);
bool kiemTraChuoiDoiXung(char str[]);
void kiemTraS2CoXuatHienTrongS1(char str[], char s2[]);
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
	printf("\n* 1 Nhap/Xuat Chuoi                                                      *");
	printf("\n* 2 De kiem tra ki tu co trong Chuoi str[] Hay khong ?                   *");
	printf("\n* 3 Kiem tra chuoi co toan ki tu so hay khong?                           *");
	printf("\n* 4 Chuyen duoi ki tu dau thanh chu HOA Con Lai Thanh Chu Thuong         *");
	printf("\n* 5 Dem So Ki Tu trong Chuoi                                             *");
	printf("\n* 6 Tim Kiem Ten Trong Chuoi                                             *");
	printf("\n* 7 Tach Ho Lot Va Ten Ra                                                *");
	printf("\n* 8 Kiem Tra Mang DOI XUNG hay Khong?                                    *");
	printf("\n* 9 Tim Vi Tri S2 Xuat Hien Trong str[] Neu Khong Thay Noi S2[] vao str[]*");
	printf("\n**************************************************************************");
	printf("\n**************************************************************************");
}
void suLi(){
	int luachon;
	char c;
	char str[MAXSIZE];
	do{
		showMenu();
		do{
			printf("\n\tSu lua chon cua ban la : "); scanf("%d", &luachon);
			if (luachon < 0)
				printf("\nXin vui long nhap lai!!!");
		} while (luachon < 0);
		switch (luachon){
		case 1:{
				   printf("Nhap chuoi : ");
				   nhapChuoi(str);
				   printf("\nChuoi sau khi nhap : ");
				   xuatChuoi(str);
				   break;
			}
		case 2:{
				   printf("\nkiTu Can Kiem Tra : "); fflush(stdin); scanf("%c", &c);
				   if (kiemTraKiTuTrongChuoi(str, c) == true)
					   printf("Ki tu [%c] Co xuat hien trong chuoi ", c);
				   else
					   printf("\nKi tu [%c] Khong Xuat hien trong chuoi Da CHO", c);
				   break;

			}
		case 3:{
				   kiemTraChuoiCoToanKiTuSoHayKhong(str);
				   break;
			}
		case 4:{
				   printf("\n\tChuoi sau khi duoc chuyen doi : ");
				   doiKiTuiDauThanhChuHoaCacKiTuKhacThanhChuThuong(str);
				   xuatChuoi(str);
				   break;
			}
		case 5:{
				   printf("\n\tSo tu trong chuoi la [%d] ", demSoTuTrongChuoi(str));	   
			}
			case 6:{
				char arr[MAXSIZE][MAXSIZE];
				char firstName[14];
				printf("\n\tFirst Name = ");
				fflush(stdin);
				scanf("%s", &firstName);
				printf("\n\t\tTen [%s] Duoc Tim Thay Trong Chuoi :  ", firstName);
				timKiemTenTrongChuoiHoTen(str,arr,firstName);
//				timKiemTenTrongChuoiHoTen2(str,firstName);
				break;
			}
			case 7:{
				char arr[MAXSIZE][MAXSIZE];
				tachHoLotVaTenTrongChuoi(str,arr);
				break;
			}
			case 8:{
				if(kiemTraChuoiDoiXung(str))
					printf("\n\tChuoi Doi Xung");
				else
					printf("\n\tChuoi Khong Doi Xung!!!");
				break;
			}
			case 9:{
				char s2[100];
				printf("\n\tChuoi s2: ");
				fflush(stdin);
				gets(s2);
				kiemTraS2CoXuatHienTrongS1(str,s2);
				break;
			}
		}

	} while (luachon != 0);
}
void nhapChuoi(char str[]){
	fflush(stdin);
	gets(str);
}

void xuatChuoi(char str[])
{
	printf("%s", str);
}

bool kiemTraKiTuTrongChuoi(char str[], char c){
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return true;
		i++;
	}
	return false;
}

void kiemTraChuoiCoToanKiTuSoHayKhong(char str[]){
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		printf("\nChuoi Khong Chua Toan Ki Tu So!!!!");
	else
		printf("\nChuoi Chua Toan Ki Tu So");
}

void doiKiTuiDauThanhChuHoaCacKiTuKhacThanhChuThuong(char str[]){
	strlwr(str);
	if (str[0] != ' ')
	{
		str[0] = str[0] - 32;
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i - 1] == ' '&& str[i] != ' ')
			str[i] -= 32;
	}
}
int demSoTuTrongChuoi(char str[]){
	int count = 0;
	if (str[0] != ' ')
		count++;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
			count++;
	} 
	return count;
}
//                                         C1
void timKiemTenTrongChuoiHoTen(char str[], char arr[][MAXSIZE], char firstName[]){
	int n = 0,flag = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	for(int i = 0;i < n;i++){
		if(strcmp(arr[n - 1],firstName) == 0){
			flag = 1;
		}
	}
	if(flag == 0)
		printf("Khong Tim Thay!!!");
	else
		for(int i = 0;i < n;i++){
			printf("%s ", arr[i]);
		}
}
//C2 
int khoangTrangCuoiCung(char str[]){
	int n = strlen(str);
	for(int i = n - 1;i >= 0;i--){
		if(str[i] == ' ' && str[i] != NULL){
			return i;
		}
	}
	return -1;
}
void timKiemTenTrongChuoiHoTen2(char str[], char firstName[]){
	int n = strlen(str);
	int n1 = strlen(firstName),flag = 1;//sai
	
	if(khoangTrangCuoiCung(str) != -1){
		int k = khoangTrangCuoiCung(str) + 1;
		for(int i = 0;i < n1;i++){
			if(firstName[i] != str[k]){
				flag = 0;
				break;
			}
			++k;
		}
		if(flag == 1)
		{
			for(int j = 0;j < n;j++){
				printf("%s ", str[j]);
			}
		}
			
	}
	else 
		printf("Khong Tim Thay!!!");
	
}

void tachHoLotVaTenTrongChuoi(char str[], char arr[][MAXSIZE]){
	int n = 0,flag = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	printf("\n\t\tTen : %s \n", arr[n - 1]);
	printf("\n\t\tHo Lot : ");
		for(int i = 0;i < n - 1;i++){
			printf("%s ", arr[i]);
		}
}
bool kiemTraChuoiDoiXung(char str[]){
	int n = strlen(str);
	for(int i = 0;i < n / 2;i++){
		if(str[i] != str[n - i - 1])
			return false;
	}
	return true;
}
void kiemTraS2CoXuatHienTrongS1(char str[], char s2[]){
	int n = strlen(str), n1 = strlen(s2),start,flag;
	for(int i = 0;i < n;i++){
		if(str[i] == s2[0] && n - i >= n1){
			start = i;
			flag = 1;
			for(int j = 0;j < n1;j++){
				if(s2[j] != str[start]){
					flag = 0;
					break;
				}
				start++;
			}
			if(flag == 1)
			printf("\n\tVi Tri Xuat Hien Chuoi [%s] trong Chuoi [%s] la Vi Tri Thu %d ",s2,str, i);
		}
	}
	if(flag == 0){
		strcat(str , s2);
		printf("Chuoi Sau Khi Duoc Noi : %s ", str);
	}
}
	
	
	
	

