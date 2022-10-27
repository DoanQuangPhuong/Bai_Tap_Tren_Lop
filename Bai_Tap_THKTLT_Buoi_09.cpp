#include<stdio.h>
#include <conio.h>
#include<math.h>
#define MAXSIZE 100
#include<stdbool.h>
void thapDongHoHa_Noi(char cotA, char cotB, char cotC, int n, int &SoLan);
void xuat(int n);
bool OK(int x2, int y2);
void Try(int i , int n, int &completed);
void showMenu();
void suLi();
int  main(){
	suLi();
	return 0;
}


void showMenu(){
printf("\n**************************************************************************");
printf("\n*                                          MENU                          *");
printf("\n**************************************************************************");
printf("\n Nhan Phim 0 De Ket Thuc Chuong Trinh                                    *");
printf("\n Nhan Phim 1 De Quy Thap Ha Noi                                          *");
printf("\n**************************************************************************");
printf("\n**************************************************************************");
}
void suLi(){
	int luachon, SoLan = 0,n;
	char cotA = 'A', cotB = 'B', cotC = 'C';
	do{
		showMenu();
		do{
			printf("\n\tSu lua chon cua ban la : "); scanf("%d", &luachon);
			if (luachon < 0)
				printf("\nXin vui long nhap lai!!!");
		} while (luachon < 0);
		switch (luachon){
		case 1:{
				   do{
					   printf("\n\tNhap So Dia Can Chuyen : "); scanf("%d", &n);
					   if (n < 0)
						   printf("\n\tVui long nhap lai!!!!");
				   } while (n < 0);
				   printf("\n\t\t\tKET QUA CHUYEN DIA HA NOI");
				   thapDongHoHa_Noi(cotA, cotB, cotC, n, SoLan);
				   printf("\n\t\t\tSo Lan Chuyen Dia la %d ", SoLan);
				   break;
			}
			case 2:{
				int n = 8;
				int completed = 0;
				Try(1,n,completed);
				printf("Tong Cach Dat la %d", completed);
				break;
			}
		}

	} while (luachon != 0);
}
void thapDongHoHa_Noi(char cotA, char cotB, char cotC,int n, int &SoLan){
	if (n == 1){// n > 0 [Nguon la A, Dich La B , Trung Gian La C]
		printf("\n\t\t\t\t%c -> %c", cotA, cotB);
		SoLan++;
		return;
	}
	thapDongHoHa_Noi(cotA, cotC, cotB, n - 1, SoLan);//Nguon -> A, Dich -> C, Trung Gian -> B
	thapDongHoHa_Noi(cotA, cotB, cotC, 1, SoLan); //Nguon-> A, Dich-> B, Trung Gian->C
	thapDongHoHa_Noi(cotB, cotA, cotC, n - 1, SoLan);//Nguon-> B, Dich-> A, Trung Gian-> C
}
int a[20];
bool OK(int x2, int y2){
	for(int i = 1;i < x2;i++){
		if(a[i] == y2 || abs(i - x2) == abs(a[i] - y2))//Kiem tra cach dat co thoa man khong
			return false;
	}
	return true;
}
void xuat(int n){
	for(int i = 1;i <= n;i++){
		printf("%d", a[i]);
	}
	printf("\n");
}
void Try(int i , int n, int &completed){
	//Thu Dat quan hau vao cac cot tu 1 den n
	for(int j = 1;j <= n;j++){
		//Neu cach dat nay thoa man thi luu tai vi tri
		if(OK(i,j))
		{
			a[i] = j;
			if(i == n)
			{
				printf("\nCach Dat Thu %d ",++completed);
				xuat(n);
			}
			Try(i + 1,n,completed);
		}
	}
}










