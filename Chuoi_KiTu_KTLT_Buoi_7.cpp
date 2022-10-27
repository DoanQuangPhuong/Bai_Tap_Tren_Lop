#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXSIE 1000
void showMenu();
int demKhongTrangTrongChuoi(char str[]);
void chuanHoaChuoi(char str[]);
void demSoKiTuTrongChuoi(char str[]);
int demSoTuTrongChuoi(char str[]);
void chuyenKiTuDauThanhHoaConLaiVietThuong(char str[]);
void timTenTrongChuoi(char str[], char ten[],char *ketQua);
void deleteKiTu_C(char str[],char c);
void hoanVi2Chuoi(char &x, char &y);
void daoNguocChuoi(char str[]);
int timKhoangTrangCuoi(char str[]);
void xuatChuoiTen(char str[]);
int  timKhoangTrangDauTien(char str[]);
void xuatHo(char str[]);
void suLi();

int main(){
	suLi();
	return 0;
}
void showMenu(){
	printf("\n*********************************************************************************");
	printf("\n*                                        MENU                                   *");
	printf("\n*********************************************************************************");
	printf("\n* 0 De Ket Thuc Chuong Trinh                                                    *");
	printf("\n* 1 Nhap/Xuat Chuoi                                                             *");
	printf("\n* 2 Dem Co Bao Nhieu Khoang Trang Trong Chuoi                                   *");
	printf("\n* 3 Chua Hoa Chuoi                                                              *");
	printf("\n* 4 Liet Ke Moi Ki Tu Xuat Hien May Lan trong Chuoi                             *");
	printf("\n* 5 Dem So tu trong chuoi                                                       *");
	printf("\n* 6 Doi Ki Tu Dau Tien Thanh Chu HOA, con lai chuyen thanh chu thuong           *");
	printf("\n* 7 Viet Chuong Trinh Tim Kiem TEN trong chuoi HOTEN                            *");
	printf("\n* 8 DELETE Mot Tu Trong Chuoi Ban Dau                                           *");
	printf("\n* 9 Dao Tu trong Chuoi                                                          *");
	printf("\n* 10 Chen Tu Vao BAT CU VI TRI NAO trong chuoi                                  *");
	printf("\n* 11 Viet Ham Cat chuoi Ho Ten Thanh Chuoi Ho, chuoi Ten                        *");
	printf("\n* 12 Tim Kiem Xem Ki tu nao xuat Hien Nhieu Nhat trong chuoi                    *");
	printf("\n*********************************************************************************");
	
}
void suLi(){
	int luachon;
	char str[MAXSIE];
	do{
		showMenu();
			do{
			printf("\n\tSu Lua Chon Cua Ban la : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tVui Long Nhap Lai LUA CHON CUA BAN!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				printf("\n\tChuoi : ");
				fflush(stdin);
				gets(str);
				printf("\n\tXuat Chuoi : %s", str);
				break;
			}
			case 2:{
				printf("\n\tCo %d Khoang Trang Trong Chuoi", demKhongTrangTrongChuoi(str));
				break;
			}
			case 3:{
				chuanHoaChuoi(str);
				printf("xuat chuoi Vua Chuan Hoa : %s", str);
				break;
			}
			case 4:{
				demSoKiTuTrongChuoi(str);
				break;
			}
			case 5:{
				printf("\n\tCO %d Tu trong chuoi ", demSoTuTrongChuoi(str));
				break;
			}
			case 6:{
				chuyenKiTuDauThanhHoaConLaiVietThuong(str);
				printf("\n\tKi Tu Duoc Doi thanh : %s", str);
				break;
			}
			case 7:{
				char ketQua[20];
				char ten[12];
				printf("\n\tTen can tim : ");scanf("%s", &ten);
				timTenTrongChuoi(str,ten,ketQua);
				break;
			}
			case 8:{
				char c;
				printf("\n\tKi tu Can Xoa : ");scanf("%s", &c);
				deleteKiTu_C(str,c);
 				printf("\n\tCHUOI SAU KHI XOA KIS TU_C la : %s", str);
				break;
			}
			case 9:{
				daoNguocChuoi(str);
				break;
			}
			case 10:{
				printf("\n\tChuoi sau khi duoc tach TEN  la :  ");
				xuatChuoiTen(str);
				break;
			}
			case 11:{
				printf("\n\tChuoi sau Khi duo Tach HO la  : ");
				xuatHo(str);
				break;
			}
		}
		
	}while(luachon != 0);
}
int demKhongTrangTrongChuoi(char str[]){
	int count = 0,n = strlen(str);
	for(int i = 0;i < n;i++){
		if(str[i] == ' ')
			count++;
	}
	return count;	
}
void chuanHoaChuoi(char str[]){
	//Chuyen Hoa dau chuoi
	while(str[0] == ' ')
		strcpy(&str[0],&str[1]);
		//Chuyen Hoa Giua Chuoi
	int n = strlen(str);
	for(int i = 0;i < n - 1;i++){
		if(str[i] ==' ' && str[i + 1] == ' '){
			strcpy(&str[i],&str[i + 1]);
			i--;
		}			
	}
	//Chuoi Hoa Cuoi Chuoi
	while(str[n - 1] == ' '){
		str[n - 1] = '\0';
		n--;
	}
}
void chuyenKiTuDauThanhHoaConLaiVietThuong(char str[]){
	strlwr(str);
	str[0] = str[0] - 32;
	int n = strlen(str);
	for(int i = 1;i < n;i++){
		if(str[i - 1] == ' ' && str[i] != ' ')
			str[i] -= 32;
	}
}

//Dem So ki Tu Trong Chuoi
void demSoKiTuTrongChuoi(char str[]){
	strlwr(str);
	char s[26];
	strcpy(s,"abcdefghijklmpnoqrstuvxywz");
	int dem[26] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 26;j++)
			if(str[i] == s[j])
				dem[j]++;
	}
	for(int i = 0;i < 26;i++){
		if(dem[i] != 0){
			printf("\n\t%c Xuat Hien %d Lan",s[i],dem[i]);
		}
	}
}
//void KiTuXuatHienNhieuNhatTrongChuoi(char str[]){
//	int i;
//	strlwr(str);
//	char s[26];
//	strcpy(s,"abcdefghijklmpnoqrstuvxywz");
//	int dem[26] = {0};
//	int n = strlen(str);
//	for(i = 0;i < n;i++){
//		for(int j = 0;j < 26;j++)
//			if(str[i] == s[j])
//				dem[j]++;
//	}
//	if(str[i] != ' ')
//		char max = str[i];
//	for(int i = 0;i < 26;i++){
//		if(dem[i] != 0){
//			max = (dem[i] > max ? s[i] : max);
//		}	
//	}
//	printf("\n\tKi Tu Xuat Hien Nhieu Nhat la %c", max);
//}
int demSoTuTrongChuoi(char str[]){
	int count = 0;
	int n = strlen(str);
	if(str[0] != ' ')
		count++;
	for(int i = 0;i < n - 1;i++){
		if(str[i] == ' ' && str[i + 1] != ' ')
			count++;
	}
	return count;
}
void xoa(char str[], int vi_Tri){
	int n = strlen(str);
	for(int i = vi_Tri;i < n - 1;i++){
		str[i] =str[i + 1];
	}
	str[n - 1] ='\0';
}
void deleteKiTu_C(char str[],char c){
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		if(str[i] == c){
			xoa(str,i);
			i--;
		}
	}
}
void timTenTrongChuoi(char str[], char ten[],char *ketQua){
	ketQua = strstr(str,ten);
	if(*ketQua != NULL){
		printf("\n\tDa Nhap Dung");
		printf("\n\t%s", ketQua);
	}
	else
		printf("\n\tDa Nhap sai!!!");
}
void hoanVi2Chuoi(char &x, char &y){
	char temp = x;
	x = y;
	y = temp;
}
void daoNguocChuoi(char str[]){
	int n = strlen(str);
	for(int i = 0;i < n/2;i++){
		hoanVi2Chuoi(str[i],str[n - i - 1]);
	}
	printf("\n\tCHUOI SAU KHI DUOC DAO NGUOC : %s",str);
}
int timKhoangTrangCuoi(char str[]){
	int n = strlen(str);
	for(int i = n - 1; i >= 0;i--){
		if(str[i] == ' ')
			return i;
	}
	return -1;
}
void xuatChuoiTen(char str[]){
	int k = timKhoangTrangCuoi(str);
	int n = strlen(str);
	for(int i = k + 1;i < n;i++){
		printf("%c", str[i]);
	}
}
int  timKhoangTrangDauTien(char str[]){
	int n = strlen(str);
	if(str[0] == ' ')
		strcpy(&str[0],&str[1]);
	for(int i = 0;i < n;i++){
		if(str[i] == ' ' && str[i] != NULL)
			return i;
	}
	return -1;
}
void xuatHo(char str[]){
	int n = strlen(str);
	if(str[0] == ' ')
		strcpy(&str[0],&str[1]);
	int k = timKhoangTrangDauTien(str);
	for(int i = 0;i < k;i++){
		printf("%c", str[i]);
	}
}










