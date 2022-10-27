#include<stdio.h>
#include<conio.h>
#include<string.h>
struct THONGTINMON{
	char mamon[20];
	char tenmon[35];
	int sotinchi;
	float diem;
	float he4;
};

struct SINHVIEN{
	char mssv[15];
	char hoten[50];
	int somon;
	THONGTINMON dsmh[5]; 
};
void input1MonHoc(THONGTINMON &mon);
void inputDSMH(THONGTINMON dsmh[], int n);
void ouput1MonHoc(THONGTINMON mon);
void ouputDSMH(THONGTINMON dsmh[], int n);
void intputDSSV(SINHVIEN dssv[], int &n);
void ouputDSSV(SINHVIEN dssv[] , int n);
void timSvTheoMssv(SINHVIEN dssv[], int n);
void showMenu();
void suLi();
int main(){
	suLi();
	
	
	return 0;
}
void input1MonHoc(THONGTINMON &mon){
	printf("\n\tMa Mon Hoc: ");
	fflush(stdin);
	gets(mon.mamon);
	printf("\n\tTen Mon : ");
	fflush(stdin);
	gets(mon.tenmon);
	printf("\n\tSo Tin Chi : ");scanf("%d", &mon.sotinchi);
	printf("\n\tDiem Mon Hoc : ");scanf("%f", &mon.diem);
}
void inputDSMH(THONGTINMON dsmh[], int n){
	for(int i = 0;i < n;i++){
		printf("\n\t[> <]Mon hoc thu %d ", i + 1);
			input1MonHoc(dsmh[i]);
	}
}
void ouput1MonHoc(THONGTINMON mon){
	printf("\nMa Mon : %-13s Ten Mon : %-25s So Tin Chi :%3d     Diem Mon : %5.2f", mon.mamon,mon.tenmon,mon.sotinchi,mon.diem);
	printf("\n=====================================================================================================");
}
void ouputDSMH(THONGTINMON dsmh[], int n){
	for(int i = 0;i < n;i++){
		printf("\n\n\tMon Hoc Thu %d \n", i + 1);
		ouput1MonHoc(dsmh[i]);
	}
}
void input1SinhVien(SINHVIEN &sv){
	fflush(stdin);
	printf("\n\tMa So Sinh Vien : ");
	gets(sv.mssv);
	printf("\n\tHo Va Ten : ");
	fflush(stdin);
	gets(sv.hoten);
	printf("\n\tSo mon hoc: ");scanf("%d", &sv.somon);
	inputDSMH(sv.dsmh,sv.somon);
}
void intputDSSV(SINHVIEN dssv[], int &n){
	do{
		printf("\nNhap so Luong Sinh Vien : ");scanf("%d", &n);
		if(n <= 0)
		printf("\nVui long nhap lai!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("Sinh Vien thu %d \n", i + 1);
		input1SinhVien(dssv[i]);
	}
}
void ouput1SinhVien(SINHVIEN sv){
	printf("\n\tMa so sinh vien : %s", sv.mssv);
	printf("\n\tHo Ten  : %s",sv.hoten);
	ouputDSMH(sv.dsmh,sv.somon);
}
void ouputDSSV(SINHVIEN dssv[] , int n){
	for(int i = 0;i < n;i++){
		printf("\n=====================================================================================================");
		printf("\n\n\t\t\t\tSinh Vien thu  %d \n", i + 1);
		ouput1SinhVien(dssv[i]);
	}
}
void timSvTheoMssv(SINHVIEN dssv[], int n){
	int flag = 0;
	char masv[15];
	printf("\n\t=========Nhap MSSV can tim :  ");scanf("%s", masv);
	for(int i = 0;i < n;i++){
		if(strcmp(masv,dssv[i].mssv) == 0){
			flag = 1;
			ouput1SinhVien(dssv[i]);
		}
	}
	if(flag == 0)
		printf("\n\tKHONG CO SINH VIEN TRONG DANH SACH!!!!");
}
void diemTrungBinhTichLuy(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		if(dssv[i].dsmh[i].diem > 9.2)
			dssv[i].dsmh[i].he4 = 4;
	}
}

void showMenu(){
	printf("\n*****************************************************");
	printf("\n*			MEMU									   ");
	printf("\n*****************************************************");
	printf("\n* 0 De thoat khoi chuong trinh				       ");
	printf("\n* 1 Nhap/xuat DSSV						           ");
	printf("\n* 2 Tim sinh vien theo MSSV						   ");
	printf("\n* 3 Tim sinh vien DTB Cao Nhat					   ");
	printf("\n* 4 Them xoa sinh vien khoi DSSV					   ");
	printf("\n* 5 Sap xep sinh vien Tang/Giam dan theo DTB		   ");
	printf("\n* 6 Xep loai Hoc tap							       ");
	printf("\n* 7 Thong Ke Sinh Vien Dau/ Rot				       ");
	printf("\n*****************************************************");
}
void suLi(){
	int n, luachon;
	SINHVIEN sv;
	SINHVIEN dssv[100];
	do{
		showMenu();
		do{
			printf("\nLua chon cua ban la: ");scanf("%d", &luachon);
			if(luachon < 0)
			printf("Vui long nhap lai!!!!\n");
			
		}while(luachon < 0);
		switch(luachon){
			case 1:{
			intputDSSV(dssv,n);
			ouputDSSV(dssv,n);
				break;
			}
			case 2:{
				timSvTheoMssv(dssv,n);
				break;
			}
		}
	}while(luachon != 0);
}




