#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MAXSIZE 50
void nhapMang2C(int arr[][MAXSIZE], int &n, int &m);
void xuatMang2C(int arr[][MAXSIZE], int n, int m);
void xuat2ChieuNgauNhien(int arr[][MAXSIZE], int &n, int &m);
int tongTungDong(int arr[][MAXSIZE], int n, int m, int k);
void xuatTongGiaTriTrenTungDong(int arr[MAXSIZE][MAXSIZE], int n, int m);
int maxTungCot(int arr[MAXSIZE][MAXSIZE], int n, int m, int k);
void xuatPhanTuLonNhatTrenTungCot(int arr[][MAXSIZE], int n, int m);
void xuatPhanTuThuocBien(int arr[MAXSIZE][MAXSIZE], int n, int m);
void swap(int &a, int &b);
void sapXepmangTangDan(int arr[][MAXSIZE], int n, int m);
bool ktDongToanChan(int arr[][MAXSIZE], int n, int m, int k);
void xuatDongChiToanLaSoChan(int arr[][MAXSIZE], int n, int m);
void taoMaTran_ToanChan(int a[][MAXSIZE], int &n, int &m);
int timPhanTuMinTrongDong(int arr[][MAXSIZE], int n, int m, int k);
int timPhanTuMaxTrongDong(int arr[][MAXSIZE], int n, int m, int k);
int timPhanTuNhoNhatTrongCot( int arr[][MAXSIZE], int n, int m, int k);
int timPhanTuLonNhatTrongCot( int arr[][MAXSIZE], int n, int m, int k);
void xuatDiemYenNguaTrongMang(int arr[][MAXSIZE], int n, int m);
int KiemTraPhanTuCucDai(int arr[][MAXSIZE], int n, int m, int dong, int cot);
void xuatPhanTuCucDai(int arr[][MAXSIZE], int n, int m);
int kiemTraCotToanLe(int arr[][MAXSIZE], int n, int m,int k);
void deleteCotToanSoLe(int arr[][MAXSIZE], int n, int &m);
int timPhanTuLonNhatTrenBien(int arr[][MAXSIZE], int n, int m);
int KiemTraCoChuSo2HayKhong(int n);
void xuatCoBaoNhieuPhanTuCoChuSo2TrongMang(int arr[][MAXSIZE], int n, int m);
void dongChanGiamDan(int arr[][MAXSIZE],int n, int m, int k);
void dongLeTangDan(int arr[][MAXSIZE],int n, int m, int k);
void sapXepDongLeTangDongChanGiam(int arr[][MAXSIZE], int n, int m);
void cotChanTangDan(int arr[][MAXSIZE],int n, int m, int k);
void cotLeGiamDan(int arr[][MAXSIZE],int n, int m, int k);
void sapXepCotChanTangDanCotLeGiamDan(int arr[][MAXSIZE], int n, int m);
void lietKeDongToanChan(int arr[][MAXSIZE], int n, int m);
bool kiemTraTungDongCoGiaTriGiamDanHayKhong(int arr[][MAXSIZE], int n, int m,int k);
void lietKeDongChuaGiaTriGiamDan(int arr[][MAXSIZE], int n, int m);
int soLanDemGiaTriX(int arr[][MAXSIZE], int n, int m, int x);
void timGiaTriXuatHienNhieuNhatTrongMang(int arr[][MAXSIZE], int n, int m);
void demTungChuSoTrongGiaTri(int arr[][MAXSIZE], int n, int m, int b[]);
void chuSoXuatHienNhieuNhat(int arr[][MAXSIZE], int n, int m, int b[]);
int tongTungCot(int arr[][MAXSIZE], int n, int m, int k);
int CotCoTongNhoNhat(int arr[][MAXSIZE], int n, int m);
void lietKeCacCotCoTongNhoNhat(int arr[][MAXSIZE], int n, int m);
void HoanVi2Cot(int arr[][MAXSIZE],int n,int m,int &l,int &k);
void HoanVi2Dong(int arr[][MAXSIZE],int n,int m,int &l,int &k);
void showMenu();
void suLi();
int main(){
	suLi();

	return 0;
}
//Xuat Mang
void nhapMang2C(int arr[][MAXSIZE], int &n, int &m){
	do{
		printf("\n\tNhap so dong : "); scanf("%d", &n);
		printf("\n\tNhap so Cot : "); scanf("%d", &m);

	} while (n < 0 || m < 0 || n > MAXSIZE || m > MAXSIZE);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("\narr[%d][%d] = ", i, j); scanf("%d", &arr[i][j]);
		}
	}
}
//Nhap Mang
void xuatMang2C(int arr[][MAXSIZE], int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
//Tao mang ngua nhien
void xuat2ChieuNgauNhien(int arr[][MAXSIZE], int &n, int &m){
	printf("\n\tSo Dong : ");scanf("%d", &n);
	printf("\n\tSo Cot : ");scanf("%d", &m);
	int a = -50;
	int b = 50;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){

			arr[i][j] = a + rand() % (b - a + 1);
		}
		printf("\n");
	}
	xuatMang2C(arr, n, m);
}
//Tao mang Toan la So Chan
void taoMaTran_ToanChan(int arr[][MAXSIZE], int &n, int &m){
	int x = -50;
	int y = 50;
	printf("\n\tSo Dong : ");scanf("%d", &n);
	printf("\n\tSo Cot : ");scanf("%d", &m);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
		int temp;
		do{
			temp = x + rand() % (y - x + 1);
		}while (temp % 2 != 0); //Lap lai trong khi Van con la so le
			arr[i][j] = temp; // Tao chan co gia tri tu -50 den 50
		}
	}
	xuatMang2C(arr,n,m);
}
//Tim phan tu Max cua tung dong
int tongTungDong(int arr[][MAXSIZE], int n, int m, int k){
	int sum = 0;
	for (int j = 0; j < m; j++){
		sum += arr[k][j];
	}
	return sum;
}
//Xuat ra chi so va Gia  tri Max
void xuatTongGiaTriTrenTungDong(int arr[MAXSIZE][MAXSIZE], int n, int m){
	for (int i = 0; i < n; i++){
		printf("Dong %d co Tong  = %d \n", i, tongTungDong(arr, n, m, i));
	}
}
//Tim phan tu max cua tung Cot
int maxTungCot(int arr[MAXSIZE][MAXSIZE], int n, int m, int k){
	int max = arr[0][k];
	for (int i = 1; i < n; i++){
		if (arr[i][k] > max)
			max = arr[i][k];
	}
	return max;
}
//Xuat ra Chi so COT va Gia tri Max
void xuatPhanTuLonNhatTrenTungCot(int arr[][MAXSIZE], int n, int m){
	for (int j = 0; j < m; j++){
		{
			printf("Cot thu %d Co phan tu lon nhat la %d \n", j, maxTungCot(arr, n, m, j));
		}
	}
}

void xuatPhanTuThuocBien(int arr[MAXSIZE][MAXSIZE], int n, int m){
	printf("\n\tPHAN TU THUOC BIEN : ");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1 ){
				printf("%4d ", arr[i][j]);
			}
		}
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void sapXepmangTangDan(int arr[][MAXSIZE], int n, int m){
	for (int i = 0; i < n; i++){ // Chay het dong
		for (int j = 0; j < m - 1; j++){ //Chay den phan tu ke  cuoi
			for (int k = j + 1; k < m; k++){ // Chay het cot
				if (arr[i][j] > arr[i][k])
					swap(arr[i][j], arr[i][k]);
			}
		}
	}
	xuatMang2C(arr, n, m);
}
//Kiem tra dong co toan chu so chan hay khong?
bool ktDongToanChan(int arr[][MAXSIZE], int n, int m,int k){
	for (int j = 0; j < m; j++){
		if (arr[k][j] % 2 != 0)
			return false;
	}
	return true;
}
//Xuat dong toan chan
void xuatDongChiToanLaSoChan(int arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for (int i = 0; i < n; i++){
		if (ktDongToanChan(arr, n, m, i) == true){
			printf("\n\tDONG THU %d Toan Chan", i);
			flag = 1;
		}
	}
	if (flag == 0)//flag khong  != 1 thi thuc hien len duoi
		printf("\n\tKHONG CO DONG TOAN CHAN NAO TRONG MANG!!!!");
}
//												Tim Phan Tu YEN NGUA
//=========================================================================================================================
int timPhanTuMinTrongDong(int arr[][MAXSIZE], int n, int m, int k){
	int min = arr[k][0];
	for(int j = 1;j < m;j++){
		if(arr[k][j] < min)
			min = arr[k][j];
	}
	return min;
}
int timPhanTuMaxTrongDong(int arr[][MAXSIZE], int n, int m, int k){
	int max = arr[k][0];
	for(int j = 1;j < m;j++){
		if(arr[k][j] > max)
			max = arr[k][j];
	}
	return max;
}
int timPhanTuLonNhatTrongCot( int arr[][MAXSIZE], int n, int m, int k){
	int max = arr[0][k];
	for(int i = 1;i < n;i++){
		if(arr[i][k] > max)
			max = arr[i][k];
	}
	return max;
}
int timPhanTuNhoNhatTrongCot( int arr[][MAXSIZE], int n, int m, int k){
	int min = arr[0][k];
	for(int i = 1;i < n;i++){
		if(arr[i][k] < min)
			min = arr[i][k];
	}
	return min;
} 
void xuatDiemYenNguaTrongMang(int arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == timPhanTuMinTrongDong(arr,n,m,i) && arr[i][j] == timPhanTuLonNhatTrongCot(arr,n,m,j) 
			|| arr[i][j] == timPhanTuMaxTrongDong(arr,n,m,i) && arr[i][j] == timPhanTuNhoNhatTrongCot(arr,n,m,j)){
			 	  		printf("\n\tDiem YEN NGUA trong mang la %4d " , arr[i][j]);
			 	  			flag = 1;
				   } 
			 }
		}
		if(flag == 0)
			printf("\n\tKhong Co Diem YEN NGUA trong Mang Da cho!!!!!");
}

//=======================================================================================================================
int KiemTraPhanTuCucDai(int arr[][MAXSIZE], int n, int m, int dong, int cot){
	int flag = 1; //Khoi dau mac dinh o [dong][cot] là cuc Dai
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
	if (dong + i >= 0 && cot + j >= 0 && dong + i < n && cot + j < m && !(i == 0 && j == 0)){
		if (arr[dong][cot] <= arr[dong + i][cot + j]){
			flag = 0;
			}
		}
	}
}
	return flag;
}
//=======================================================================================================================
void xuatPhanTuCucDai(int arr[][MAXSIZE], int n, int m){
	int dem = 0;
	printf("\nCac phan tu cuc dai la: ");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
	if (KiemTraPhanTuCucDai(arr,m, n, i, j) == 1){
		printf("%3d", arr[i][j]);
		dem++;
		}
	}
}
	printf("\n\tCo %d So thoa man ", dem);
}
//Kiem Tra Tung Cot Toan Le
int kiemTraCotToanLe(int arr[][MAXSIZE], int n, int m,int k){
	for(int i = 0;i < n;i++){
		if(arr[i][k] % 2 == 0)
			return 0;//Khong thoa
	}
	return 1;//Thoa
}

void deleteCotToanSoLe(int arr[][MAXSIZE], int n, int &m){
	printf("\n\tMA TRAN SAU KHI DUOC XOA HET NHUNG COT LE \n");
	for(int j = 0;j < m;j++){
		if(kiemTraCotToanLe(arr,n,m,j) == 1)//Neu Cot Toan Le Thi Duyet
		{
			for(int i = 0;i < n;i++){
				for(int k = j;k < m - 1;k++)
					arr[i][k] = arr[i][k + 1];
			}
			m--;
		}
	}
	xuatMang2C(arr,n,m);
}

int timPhanTuLonNhatTrenBien(int arr[][MAXSIZE], int n, int m){
	int max = arr[0][0];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				max = (arr[i][j] > max ? arr[i][j] : max);
			}
		}
	}
	return max;
}
//Kiem Tra Phan Tu co Chu So 2 trong Mang khong??
int KiemTraCoChuSo2HayKhong(int n){
	while(n > 0){
		int k = n % 10;
			if(k == 2)
				return 1;
		n /= 10;
	}
	return 0;
}
//Xuat phan tu co chu so 2 trong mang
void xuatCoBaoNhieuPhanTuCoChuSo2TrongMang(int arr[][MAXSIZE], int n, int m){
	int count = 0,flag = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(KiemTraCoChuSo2HayKhong(arr[i][j]) == 1){
				count++;
				flag = 1;
			}
		}
	}
	if(flag == 0)
		printf("\n\tKHONG CO PHAN TU CO CHU SO '2' TRONG MANG!!!!!");
	else
		printf("\n\t[ > < ] Co [%d] phan tu co chu so '2'" , count);
}
//==========================================Sap Xep Chi So LE tang,CHAN giam=====================================================

//					Sap Xep Chi So Chan Giam Dan
void dongChanGiamDan(int arr[][MAXSIZE],int n, int m, int k){
	for(int i = 0;i < m - 1;i++)//Chay Cot den Phan Tu  Nho hon [Cot - 1]
		for(int j = i + 1;j < m;j++){
			if(arr[k][i] < arr[k][j])
				swap(arr[k][i],arr[k][j]);
		}
}

//					Sap Xep Chi So Le Tang Dan

void dongLeTangDan(int arr[][MAXSIZE],int n, int m, int k){
	for(int i = 0;i < m - 1;i++)
		for(int j = i + 1;j < m;j++){
			if(arr[k][i] > arr[k][j])
				swap(arr[k][i],arr[k][j]);
		}
}

//					Sap Xep Le Tang,Chan Giam

void sapXepDongLeTangDongChanGiam(int arr[][MAXSIZE], int n, int m){
	for(int i = 0;i < n;i++){
		if(i % 2 == 0)
		{
			dongChanGiamDan(arr,n,m,i);
		}
		else //i % 2 != 0
		{
			dongLeTangDan(arr,n,m,i);
		}
	}
	xuatMang2C(arr,n,m);
}

//=======================================Sap Xep cot Chan TANG DAN, Cot Le Giam Dan=================================================

//				Sap Xep Cot Co chi so Chan TANG DAN

void cotChanTangDan(int arr[][MAXSIZE],int n, int m, int k){
	for(int i = 0;i < n - 1;i++)//Chay Dong den Phan Tu  Nho hon [Dong - 1]
		for(int j = i + 1;j < n;j++){
			if(arr[i][k] > arr[j][k])
				swap(arr[i][k],arr[j][k]);
		}
}

//				Sap Xep Cot Co chi so Le GIAM DAN

void cotLeGiamDan(int arr[][MAXSIZE],int n, int m, int k){
	for(int i = 0;i < n - 1;i++)//Chay Dong den Phan Tu  Nho hon [Dong - 1]
		for(int j = i + 1;j < n;j++){
			if(arr[i][k] < arr[j][k])
				swap(arr[i][k],arr[j][k]);
		}
}

//						Sap Xep cot Chan TANG DAN, Cot Le Giam Dan

void sapXepCotChanTangDanCotLeGiamDan(int arr[][MAXSIZE], int n, int m){
	for(int j = 0;j < m;j++){
		if(j % 2 == 0)
		{
			cotChanTangDan(arr,n,m,j);
		}
		else
		{
			cotLeGiamDan(arr,n,m,j);
		}
	}
	xuatMang2C(arr,n,m);
}

//======================================================================================================================


void lietKeDongToanChan(int arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for(int i = 0;i < n;i++){
		if(ktDongToanChan(arr,n,m,i) == true)
		{
			printf("\tDong thu %d toan chan \n", i);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("\n\tKHONG CO DONG TOAN CHAN TRONG MANG!!!!!");
}

//					KIEM TRA DONG CO GIA TRI GIAM DAN HAY KHONG???

bool kiemTraTungDongCoGiaTriGiamDanHayKhong(int arr[][MAXSIZE], int n, int m,int k){
	for(int j = 0;j < m - 1;j++){
		if(arr[k][j] > arr[k][j + 1])
			return true;
	}
	return false;
}

//					LIET KE DONG CHUA GIA TRI GIAM DAN

void lietKeDongChuaGiaTriGiamDan(int arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for(int i = 0;i < n;i++){
		if(kiemTraTungDongCoGiaTriGiamDanHayKhong(arr,n,m,i) == true){
			printf("\tDong %d Co gia tri GIAM DAN \n", i);
				flag = 1;
		}
	}
	if(flag == 0)
		printf("\n\tKHONG CO DONG CHUA GIA TRI 'GIAM DAN' TRONG MANG!!!!");
}

//						Dem X trong mang

int soLanDemGiaTriX(int arr[][MAXSIZE], int n, int m, int x){
	int count = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == x)
				count++;
		}
	}
		return count;
}

//						Tim phan tu xuat hien nhieu nhat trong mang

void timGiaTriXuatHienNhieuNhatTrongMang(int arr[][MAXSIZE], int n, int m){
	int temp = soLanDemGiaTriX(arr,n,m,arr[0][0]), temp1, index1 = 0, index2 = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			temp1 = soLanDemGiaTriX(arr,n,m,arr[i][j]);
				if(temp1 > temp){
					temp = temp1;
					index1 = i;
					index2 = j;
				}
		}
	}
		printf("\n\tGia tri Xuat Hien Nhieu Nhat trong Ma Tran la [%d] :  %d lan", arr[index1][index2], temp);
}

void demTungChuSoTrongGiaTri(int arr[][MAXSIZE], int n, int m, int b[]){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int temp = abs(arr[i][j]);//PHAN tu phai lon hon 0;
			while(temp > 0)
			{
				int k = temp % 10;
				b[k]++;//Dem tung chu so vao mang b[] gom 10 phan tu tu 0 den 9
				temp /= 10;
			}
		}
	}
}

void chuSoXuatHienNhieuNhat(int arr[][MAXSIZE], int n, int m, int b[]){
	int max = abs(arr[0][0] % 10);
	for(int i = 0;i < 10;i++){
		if(b[i] != 0)
		{
			max = (b[i] > b[max] ? i : max);//Neu b[i] lon hon b[max] thi max gan Chi So thu i Tuk la Gia tri i ,khong gan max = max
		}
	}
	printf("\n\t[ > < ] Chu So xuat hien nhieu nhat trong mang la %d ", max);
}

//				Tong tung Chi so cot

int tongTungCot(int arr[][MAXSIZE], int n, int m, int k){
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum += arr[i][k];
	}
	return sum;
}

//				Tim ra  cot co Tong Nho Nhat

int CotCoTongNhoNhat(int arr[][MAXSIZE], int n, int m){
	int min = tongTungCot(arr,n,m,0);
	for(int j = 1;j < m;j++){
		if(tongTungCot(arr,n,m,j) < min)
			min = tongTungCot(arr,n,m,j);
	}
	return min;
}

//					Liet Ke Cot Co tong Nho nhat

void lietKeCacCotCoTongNhoNhat(int arr[][MAXSIZE], int n, int m){
	int TongcotMin = CotCoTongNhoNhat(arr,n,m);
	for(int j = 0;j < m;j++){
		if(tongTungCot(arr,n,m,j) == TongcotMin)//Neu mà Tong cot thu j == TongcotMin thì in ra cot thu j và tong
			printf("\tCOT Thu %d Co Tong NHO NHAT la [%d] \n", j, TongcotMin);
	}
}

//					Hoan vi 2 cot bat ki

void HoanVi2Cot(int arr[][MAXSIZE],int n,int m,int &l,int &k){
	do{
		printf("\n\tCot thu : ");scanf("%d", &l);
		printf("\n\tDoi Cho Cot Thu : ");scanf("%d", &k);
		if(l < 0 || k < 0 || l >= m || k >= m)
			printf("\n\tVui long nhap lai!!!!");
	}while(l < 0 || k < 0 || l >= m || k >= m);
	for(int i = 0;i < n;i++){
			swap(arr[i][l],arr[i][k]);
	}
	printf("\n\t[> <]MANG SAU KHI HOAN VI cot %d vs cot %d \n", l,k);
	xuatMang2C(arr,n,m);
}

//						hoan vi hai dong bat ki

void HoanVi2Dong(int arr[][MAXSIZE],int n,int m,int &l,int &k){
	do{
		printf("\n\tDong thu : ");scanf("%d", &l);
		printf("\n\tDoi Cho Dong Thu : ");scanf("%d", &k);
		if(l < 0 || k < 0 || l >= n || k >= n)
			printf("\n\tVui long nhap lai!!!!");
	}while(l < 0 || k < 0 || l >= n || k >= n);
	for(int j = 0;j < m;j++){
			swap(arr[l][j],arr[k][j]);
	}
	printf("\n\t[> <]MANG SAU KHI HOAN VI dong %d vs dong %d \n", l,k);
	xuatMang2C(arr,n,m);
}

void showMenu(){
	printf("\n***************************************************************");
	printf("\n*                           MENU                              *");
	printf("\n***************************************************************");
	printf("\n* 0 De thoat khoi chuong trinh                                *");
	printf("\n* 1 Nhap/Xuat mang 2 chieu                                    *");
	printf("\n* 2  Tao Mang ngau Nhien                                      *");
	printf("\n* 3  Tao Mang ngau Nhien Toan Chan                            *");
	printf("\n* 4 Tinh va xuat tong gia tri tung dong                       *");
	printf("\n* 5 Xuat phan tu lon nhat tren tung cot                       *");
	printf("\n* 6 Xuat cac phan tu bien                                     *");
	printf("\n* 7 sap xep mag tang dan theo tung DONG                       *");
	printf("\n* 8 Xuat dong chi chua Toan CHAN                              *");
	printf("\n* 9 Xuat phan tu la diem yen ngua                             *");
	printf("\n* 10 Xuat Phan tu cuc DAI                                     *");
	printf("\n* 11 Xoa Cot TOAN nhung So LE                                 *");
	printf("\n* 12 Tim Phan Tu MAX tren BIEN                                *");
	printf("\n* 13 Trong Mang co bao nhieu PT co chu so '2'                 *");
	printf("\n* 14 Sap xep mang Dong LE Tang, Dong Chan Giam                *");
	printf("\n* 15 Sap xep mang Cot LE Giam, Cot Chan Tang                  *");
	printf("\n* 16 Liet Ke Dong Toan Chan                                   *");
	printf("\n* 17 Liet Ke Dong Chua Gia Tri GIAM DAN                       *");
	printf("\n* 18 Tim phan tu XUAT HIEN NHIEU NHAT trong mang              *");
	printf("\n* 19 Tim CHU SO xuat hien NHIEU NHAT trong mang               *");
	printf("\n* 20 COT co tong gia tri nho nhat trong mang                  *");
	printf("\n* 21 HOAN VI 2 COT                                            *");
	printf("\n* 22 HOAN VI 2 DONG                                           *");
	printf("\n* 23 Xuat cac phan tu HOANG HAU trong mang                    *");
	printf("\n***************************************************************");
}

void suLi(){
	int arr[MAXSIZE][MAXSIZE], n, m,luachon;
	do{
		showMenu();
		do{
			printf("\n\tLua chon cua ban la : "); scanf("%d", &luachon);
			if (luachon < 0)
				printf("\n\tLua chon khong hop le!!!!");
		} while (luachon < 0);
		switch (luachon){
		case 1:{
				   nhapMang2C(arr, n, m);
				   xuatMang2C(arr, n, m);
				   break;
			}
		case 2:{
				   printf("\n\tMANG 2 CHIEU SAU KHI DUOC XUAT NGAU NHIEN");
				   xuat2ChieuNgauNhien(arr, n, m);
				   break;
			}
		case 3:{
				printf("\n\tMANG NGAU NHIEN TOAN LA SO CHAN \n");
				taoMaTran_ToanChan(arr,n,m);
				break;
			}
		case 4:{
				   xuatTongGiaTriTrenTungDong(arr, n, m);
				   break;
			}
		case 5:{
				   xuatPhanTuLonNhatTrenTungCot(arr, n, m);
				   break;
			}
		case 6:{
				   xuatPhanTuThuocBien(arr, n, m);
				   break;
		 }
		case 7:{
				   sapXepmangTangDan(arr, n, m);
				   break;
			}
		case 8:{
				   xuatDongChiToanLaSoChan(arr, n, m);
				   break;
			}
			case 9:{
				xuatDiemYenNguaTrongMang(arr,n,m);
				break;
			}
			case 10:{
				xuatPhanTuCucDai(arr,n,m);
				break;
			}
			case 11:{
				deleteCotToanSoLe(arr,n,m);
				break;
			}
			case 12:{
				printf("\n\tPHAN TU LON NHAT TREN 'BIEN' la %d", timPhanTuLonNhatTrenBien(arr,n,m));
				break;
			}
			case 13:{
				xuatCoBaoNhieuPhanTuCoChuSo2TrongMang(arr,n,m);
				break;
			}
			case 14:{
				printf("\n\tSAP XEP MANG DONG LE TANG DAN, DONG CHAN GIAM DAN \n");
				sapXepDongLeTangDongChanGiam(arr,n,m);
				break;
			}
			case 15:{
				printf("\n\tSAP XEP MANG COT LE GIAM DAN, COT CHAN TANG DAN \n");
				sapXepCotChanTangDanCotLeGiamDan(arr,n,m);
				break;
			}
			case 16:{
				lietKeDongToanChan(arr,n,m);
				break;
			}
			case 17:{
				lietKeDongChuaGiaTriGiamDan(arr,n,m);
				break;
			}
			case 18:{
				timGiaTriXuatHienNhieuNhatTrongMang(arr,n,m);
				break;
			}
			case 19:{
				int b[10] = {0};
				demTungChuSoTrongGiaTri(arr,n,m,b);
				chuSoXuatHienNhieuNhat(arr,n,m,b);
				break;
			}
			case 20:{
				lietKeCacCotCoTongNhoNhat(arr,n,m);
				break;
			}
			case 21:{
				int l,k;
				HoanVi2Cot(arr,n,m,l,k);
				break;
			}
			case 22:{
				int l,k;
				HoanVi2Dong(arr,n,m,l,k);
				break;
			}
		}
	} while (luachon != 0);
}
