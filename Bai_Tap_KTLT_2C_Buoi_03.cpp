#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100
typedef int Itemtype;
void nhapMang2C(Itemtype arr[][MAXSIZE], int &n, int &m);
void xuatMang2C(Itemtype arr[][MAXSIZE], int n, int m);
void taoMaTran_ToanChan(Itemtype arr[][MAXSIZE], int &n, int &m);
void xuLy();
int kiemTraLeDauTien(int n);
int tongChuSoDauLe(Itemtype arr[][MAXSIZE], int n, int m);
int kiemTraSoHoanThien(int n);
void xuatSoHoanThienTrongMang(Itemtype arr[][MAXSIZE], int n, int m);
int tongDuongBien(Itemtype arr[][MAXSIZE], int n, int m);
int kiemTraSoNguyenTo(int n);
int demSoNguyenToTrongMang(Itemtype arr[][MAXSIZE], int n, int m);
int demSoDuong(Itemtype arr[][MAXSIZE], int n, int m);
int demSoAm(Itemtype arr[][MAXSIZE], int n, int m);
int demSoLe(Itemtype arr[][MAXSIZE], int n, int m);
int demSoChan(Itemtype arr[][MAXSIZE], int n, int m);
void demSoLanX_XuatHienTrongMang(Itemtype arr[][MAXSIZE], int n, int m, int &x);
int tongCotK(Itemtype arr[][MAXSIZE], int n, int m, int k);
int TongCotMin(Itemtype arr[][MAXSIZE], int n, int m);
void xuatCacCotMin(Itemtype arr[][MAXSIZE], int n, int m);
void dongCoNhieuSoHoanThienNhat(Itemtype arr[][MAXSIZE], int n, int m);
int kiemTraDongThuKToanChan(Itemtype arr[][MAXSIZE], int n, int m, int k);
void xuatChiSoDongToanChan(Itemtype arr[][MAXSIZE], int n, int m);
int soNguyenToDauTien(Itemtype arr[][MAXSIZE], int n, int m);
int TimSoNguyenToNhoNhat(Itemtype arr[][MAXSIZE], int n, int m);
int timPTLonNhatCotThuK(Itemtype arr[][MAXSIZE], int n, int m,int k);
int timPTNhoNhatCotThuK(Itemtype arr[][MAXSIZE], int n, int m,int k);
int timPTLonNhatDongThuI(Itemtype arr[][MAXSIZE], int n, int m,int k);
int timPTNhoNhatDongThuI(Itemtype arr[][MAXSIZE], int n, int m,int k);
void soLanXuatHienCacPhanTuTrongMang(Itemtype arr[][MAXSIZE], int n, int m);
int soLanDemGiaTriX(Itemtype arr[][MAXSIZE], int n, int m, int x);
void timGiaTriXuatHienNhieuNhatTrongMang(Itemtype arr[][MAXSIZE], int n, int m);
void swap(int &a, int &b);
void hoanVi2Hang(Itemtype arr[][MAXSIZE], int n, int m, int H1, int H2);
void delete1Cot(Itemtype arr[][MAXSIZE], int n, int &m, int x);
void hoanVi2Cot(Itemtype arr[][MAXSIZE], int n, int m, int x, int y);
void deleteCach2(Itemtype arr[][MAXSIZE], int n, int &m, int x);
void chieuMaTranTheoTrucNgang(Itemtype arr[][MAXSIZE], int n, int m);
void bienDoi2Cthanh1C(Itemtype arr[][MAXSIZE], int n, int m, Itemtype b[MAXSIZE], int &k);
void sapXep1CMoiTaoTangDAN(Itemtype b[MAXSIZE], int k);
void xuatMaTranTangDanTheoHinhXoanOc(Itemtype b[],Itemtype arr[][MAXSIZE], int n, int m);
void sapXepMaTranTangDanZicZac(Itemtype b[],Itemtype arr[][MAXSIZE], int n, int m);
void showMenu();

int main(){
	xuLy();
	
	
	
	return 0;
}
void nhapMotSoNguyen(int &n){
	do{
	scanf("%d", &n);
	if(n < 0)
		printf("\nVui long nhap lai n > 0!!!");
	}while(n < 0);
}

void nhapMang2C(Itemtype arr[][MAXSIZE], int &n, int &m){
	do{
		printf("Nhap so Hang: ");scanf("%d", &n);
		printf("\nNhap so Cot: ");scanf("%d", &m);
		if(n <= 0 || m <= 0)
			printf("\nKhong hop le vui long nhap lai!!!");
	}while(n <= 0 || m <= 0);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			printf("\narr[%d][%d] = ", i,j);scanf("%d", &arr[i][j]);
		}
}

void xuatMang2C(Itemtype arr[][MAXSIZE], int n, int m){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}
void taoMaTran_ToanChan(Itemtype arr[][MAXSIZE], int &n, int &m){
    int x = -50;
	int y = 50;
	do{
		printf("\n\tSo dong : ");scanf("%d", &n);
		printf("\n\tSo cot : ");scanf("%d", &m);
		if(n < 0|| m < 0)
			printf("\n\tVui long nhap lai!!!");
	}while(n < 0||m < 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
		int temp;
			do{
			temp = x + rand() % (y - x + 1);
			} while (temp % 2 != 0); //Lap cho den khi con la so le
			arr[i][j] = temp; //Toa mang chan co gia tri tu -50 den 50
		}
	}
}
int kiemTraLeDauTien(int n){
	while(n >= 10){
		n /= 10;
	}
	return(n % 2 == 0 ? 0 : 1);
}

int tongChuSoDauLe(Itemtype arr[][MAXSIZE], int n, int m){
	int sum = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraLeDauTien(arr[i][j]) == 1)
				sum += arr[i][j];
		}
		return sum;
}

int kiemTraSoHoanThien(int n){
	int sum = 0;
	for(int i = 1;i < n;i++){
		if(n % i == 0)
			sum += i;
	}
	return(sum != n ? 0 : 1);
}

void xuatSoHoanThienTrongMang(Itemtype arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraSoHoanThien(arr[i][j]) == 1){
				flag = 1;
				printf("\n\tSo %d La So hoan thien O vi tri dong thu %d cot thu %d ",arr[i][j],i,j);
			}
		}
		if(flag == 0)
			printf("\n\tKhong co so HOAN THIEN trong mang!!!");
}

int tongPtuLonHonTriTuyetDoiLienSau(Itemtype arr[][MAXSIZE], int n, int m){
	int sum = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m - 1;j++){
			if(arr[i][j] > abs(arr[i][j + 1]))
			sum += arr[i][j];
		}
		return sum;		
}

int tongGiaTriTrenDongThuK(Itemtype arr[][MAXSIZE], int n, int m, int k){
	int sum = 0;
	for(int j = 0;j < m;j++)
		sum += arr[k][j];
	return sum;
}

int tongDuongBien(Itemtype arr[][MAXSIZE], int n, int m){
	int sum = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(i == 0 || j == 0 || j == n - 1 || i == n - 1){
				sum += arr[i][j];
			}
		}
		return sum;
}

int kiemTraSoNguyenTo(int n){
	if(n < 2)
		return 0;
	for(int i = 2;i <= sqrt(n);i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int demSoNguyenToTrongMang(Itemtype arr[][MAXSIZE], int n, int m){
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraSoNguyenTo(arr[i][j]) == 1)
				count++;
		}
		return count;
}

int demSoDuong(Itemtype arr[][MAXSIZE], int n, int m){
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			 if(arr[i][j] > 0)
			 	count++;
		}
		return count;
}

int demSoAm(Itemtype arr[][MAXSIZE], int n, int m){
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			 if(arr[i][j] < 0)
			 	count++;
		}
		return count;
}

int demSoChan(Itemtype arr[][MAXSIZE], int n, int m){
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			 if(arr[i][j] % 2 == 0)
			 	count++;
		}
		return count;
}

int demSoLe(Itemtype arr[][MAXSIZE], int n, int m){
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			 if(arr[i][j] % 2 != 0)
			 	count++;
		}
		return count;
}

void demSoLanX_XuatHienTrongMang(Itemtype arr[][MAXSIZE], int n, int m, int &x){
	int count = 0,flag = 0;
	printf("\nNhap X cam dem : ");
	nhapMotSoNguyen(x);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(arr[i][j] == x){
				count++;
				flag = 1;
			}
		}
		if(flag == 0)
			printf("\n\tKhong co Gia tri [%d] xuat Hien trong mang!!!!", x);
		else
	    	printf("\n\tPhan tu %d Xuat hien %d lan ", x,count);
}

int tongCotK(Itemtype arr[][MAXSIZE], int n, int m, int k){
	int sum = 0;
	for(int i = 0; i < n;i++){
		sum += arr[i][k];
	}
	return sum;
}

int TongCotMin(Itemtype arr[][MAXSIZE], int n, int m){
	int TongMin = tongCotK(arr,n,m,0);
	for(int j = 1;j < m;j++){
		if(tongCotK(arr,n,m,j) < TongMin)
			TongMin = tongCotK(arr,n,m,j);		
	}
	return TongMin;
}

void xuatCacCotMin(Itemtype arr[][MAXSIZE], int n, int m){
	int MinTongCot = TongCotMin(arr,n,m);
	for(int j = 0;j < n;j++){
		if(tongCotK(arr,n,m,j) == MinTongCot)
			printf("\n\tCot co Tong la %d nho nhat o Vi tri Thu %d ", MinTongCot,j);
	}
}

void dongCoNhieuSoHoanThienNhat(Itemtype arr[][MAXSIZE], int n, int m){
	int count[n] = {0}; // Neu dong co so hoan thien thi dong thi i trong COUNT tang len
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraSoHoanThien(arr[i][j]) == 1)
				count[i]++;
		}
	int max = count[0];
	for(int i = 1;i < n;i++){
		if(count[i] != 0)
			max = (count[i] > max ? count[i] : max);
			
	}
	for(int i = 0;i < n;i++){
		if(count[i] == max)
			printf("\n\tDong Thu [%d] co Nhieu So HOAN THIEN NHAT CU THE LA  %d So ",i,max);
	}
}

int kiemTraDongThuKToanChan(Itemtype arr[][MAXSIZE], int n, int m, int k){
	for(int j = 0;j < m;j++)
		if(arr[k][j] % 2 != 0)
			return 0;
		return 1;
}

void xuatChiSoDongToanChan(Itemtype arr[][MAXSIZE], int n, int m){
	int flag = 0;
	for(int i = 0;i < n;i++){
		if(kiemTraDongThuKToanChan(arr,n,m,i) == 1){
			printf("\n\tDong Thu %d Toan la so chan", i);
				flag = 1;
		}	
	}
	if(flag == 0)
		printf("\n\tMang Khong Co Dong Toan la So Chan!!!!");
}

int soNguyenToDauTien(Itemtype arr[][MAXSIZE], int n, int m){
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraSoNguyenTo(arr[i][j]) == 1)
				return arr[i][j];
		}
		return -1;
}

int TimSoNguyenToNhoNhat(Itemtype arr[][MAXSIZE], int n, int m){
	if(soNguyenToDauTien(arr,n,m) == -1)
		return -1;
	int NTdauTien = soNguyenToDauTien(arr,n,m);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(kiemTraSoNguyenTo(arr[i][j]) == 1 && arr[i][j] < NTdauTien) 
				NTdauTien = arr[i][j];
		}
		return NTdauTien;
}

int timPTLonNhatCotThuK(Itemtype arr[][MAXSIZE], int n, int m,int k){
	int max = arr[0][k];
	for(int i = 1;i < n;i++){
		if(arr[i][k] > max)
			max = arr[i][k];
	}
	return max;
}

int timPTNhoNhatCotThuK(Itemtype arr[][MAXSIZE], int n, int m,int k){
	int min = arr[0][k];
	for(int i = 1;i < n;i++){
		if(arr[i][k] < min)
			min = arr[i][k];
	}
	return min;
}

int timPTLonNhatDongThuI(Itemtype arr[][MAXSIZE], int n, int m,int k){
	int max = arr[k][0];
	for(int j = 1;j < m;j++){
		if(arr[k][j] > max)
			max = arr[k][j];
	}
	return max;
}

int timPTNhoNhatDongThuI(Itemtype arr[][MAXSIZE], int n, int m,int k){
	int max = arr[k][0];
	for(int j = 1;j < m;j++){
		if(arr[k][j] < max)
			max = arr[k][j];
	}
	return max;
}

void soLanXuatHienCacPhanTuTrongMang(Itemtype arr[][MAXSIZE], int n, int m){
	int i,j;
	for(i = 0;i < n;i++){
			int count = 0;
		for(j = 0;j < m;j++){
			for(int k = 0;k < m;k++){
				if(arr[i][j] == arr[i][k]){//sai
					if(j <= k){
						count++;
					}
					else{
						break;
					}
				}
			}
			
		}
		printf("\n\t[> <] Gia tri %d Xuat hien %d lan trong mang",arr[i][j],count);
	}
}


//===================================================================================================================

int soLanDemGiaTriX(Itemtype arr[][MAXSIZE], int n, int m, int x){
	int count = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr[i][j] == x)
				count++;
		}
	}
		return count;
}

void timGiaTriXuatHienNhieuNhatTrongMang(Itemtype arr[][MAXSIZE], int n, int m){
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
//===================================================================================================================

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void hoanVi2Hang(Itemtype arr[][MAXSIZE], int n, int m, int H1, int H2){
	printf("\n\tMa Tran Sau khi Hoan Vi dong  \n");
		for(int j = 0;j < m;j++){
			swap(arr[H1][j],arr[H2][j]);
		}
		xuatMang2C(arr,n,m);
}

//					Delete theo cach thong thuong

void delete1Cot(Itemtype arr[][MAXSIZE], int n, int &m, int x){
	for(int j = x;j < m - 1;j++){
		for(int i = 0;i < n;i++){
			arr[i][j] = arr[i][j + 1];
		}
	}
	m--;
	xuatMang2C(arr,n,m);
}

//								Cach 2

void hoanVi2Cot(Itemtype arr[][MAXSIZE], int n, int m, int x, int y){
	for(int i = 0;i < n;i++){
		swap(arr[i][x],arr[i][y]);
	}
}

//??

void deleteCach2(Itemtype arr[][MAXSIZE], int n, int &m, int x){
	for(int i = x;i < m - 1;i++){
		hoanVi2Cot(arr,n,m,i,i + 1);
	}
	m--;
	xuatMang2C(arr,n,m);
}

//					Chieu ma tran theo truc ngang

void chieuMaTranTheoTrucNgang(Itemtype arr[][MAXSIZE], int n, int m){
	printf("\n\tChieu Ma tran Theo chieu ngang \n");
	for(int i = n - 1;i >= 0;i--){
		for(int j = 0;j < m;j++){
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

//====================================================================================================================

// 							Bien Doi Mang 2 chieu Ve mang 1 chieu
void bienDoi2Cthanh1C(Itemtype arr[][MAXSIZE], int n, int m, Itemtype b[MAXSIZE], int &k){
	k = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			b[k++] = arr[i][j];
		}
}
// 							Sap Xep Mang 1 Chieu Vua Duoc Tao Tang Dan 
void sapXep1CMoiTaoTangDAN(Itemtype b[MAXSIZE], int k){
	for(int i = 0;i < k - 1;i++)
		for(int j = i + 1;j < k;j++){
			if(b[i] > b[j])
				swap(b[i],b[j]);
		}
}

//							Sap Xep Ma Tran Tang Dan Theo Hinh Xoan Oc
void xuatMaTranTangDanTheoHinhXoanOc(Itemtype b[],Itemtype arr[][MAXSIZE], int n, int m){
	int temp = 0, dongMin = 0 , dongMax = n , cotMin = 0 , cotMAX = m;
	while(dongMin < dongMax && cotMin < cotMAX){
	// 				Sap xep dong dau tien trong Ma tran
	for(int i = cotMin;i < cotMAX;i++){
		arr[dongMin][i] = b[temp];
		temp++;
	}
	dongMin++;
	//				sap Xep Cot Cuoi Cung trong Ma Tran
	for(int i = dongMin;i < dongMax;i++){
		arr[i][cotMAX - 1] = b[temp];
		temp++;
	}
	cotMAX--;
	// 				Sap Xep dong cuoi cung trong Ma Tran
	if(dongMin < dongMax){// Vi Dong Cot Thay Doi O Phia Tren Nen Phai Kiem Tra Thoa Thi Thuc Hien Tiep
		for(int i = cotMAX - 1;i >= cotMin;i--){
			arr[dongMax - 1][i] = b[temp];
			temp++;
		}
		dongMax--;
	}
	//  				Sap Xep Cot dau tien
	if(cotMin < cotMAX){// Vi Dong Cot Thay Doi O Phia Tren Nen Phai Kiem Tra Thoa Thi Thuc Hien Tiep
	for(int i = dongMax - 1 ;i  >= dongMin;i--){
		arr[i][cotMin] = b[temp];
			temp++;
			}
		cotMin++;
		}
	}
}

//						Sap Xep Ma Tran Tang Dan Theo Kieu Zic Zac

void sapXepMaTranTangDanZicZac(Itemtype b[],Itemtype arr[][MAXSIZE], int n, int m){
	int temp = 0;
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){//Neu Dong Chan Thi Sap Theo Thu Tu Tu Tren Xuong Duoi
			for(int j = 0;j < m;j++){
				arr[i][j] = b[temp++];
			}
		}
		else
		{
			for(int j = m - 1;j >= 0;j--){//Dong Le Thi Sap Tu Duoi Len Tren
				arr[i][j] = b[temp++];
			}
		}
	}
	xuatMang2C(arr,n,m);
}

//===============================================================================================================

void showMenu(){
	printf("\n*********************************************************");
	printf("\n*                          MENU                         *");
	printf("\n*********************************************************");
	printf("\n* 0 De Thoa khoi chuong trinh                           *");
	printf("\n* 1 Nhap Xuat Mang 2 Chieu                              *");
	printf("\n* 2 Tong Tat Ca cac phan tu co chu so dau la so LE      *");
	printf("\n* 3 Liet Ke cac so HOAN THIEN trong mang                *");
	printf("\n* 4 Tong PT lon hon tri tuyet doi PT lien sau           *");
	printf("\n* 5 Tinh tong gia tri tren dong thu k                   *");
	printf("\n* 6 Tong ca gia tri nam tren duong bien                 *");
	printf("\n* 7 Dem chan, le, am, duong, nguyen to trong mang       *");
	printf("\n* 8 Dem Tan Xuat X xuat hien trong mang                 *");
	printf("\n* 9 Liet Ke COT co Tong Nho Nhat                        *");
	printf("\n* 10 Dong Co nhieu So HOAN THIEN Nhat                   *");
	printf("\n* 11 Liet Ke Chi So Cac Dong Chua Toan Gia Tri Chan     *");
	printf("\n* 12 Tim So Nguyen To Nho Nhat Trong Mang               *");
	printf("\n* 13 Liet Ke Phan Tu (Nho) Lon nhat trong Cot K         *");
	printf("\n* 14 Tim Phan Tu Lon (Nho) Nhat Trong Dong K            *");
	printf("\n* 15 Tim Gia Tri Xuat Hien Nhieu Nhat trong mang        *");
	printf("\n* 16 Tim Hoan vi 2 Dong tren Ma tran                    *");
	printf("\n* 17 Xoa cot bat ki                                     *");
	printf("\n* 18 Chieu Ma Tran theo truc NGANG                      *");
	printf("\n* 19 Sap Xep Ma Tran Theo TANG DAN Theo Dang XOAN OC    *");
	printf("\n* 20 Randum mang Toan Chan                              *");
	printf("\n*********************************************************");	
}
void xuLy(){
	Itemtype arr[MAXSIZE][MAXSIZE],n,m,k,x;
	int luachon;
	do{
		    showMenu();
			printf("\nSu lua chon cua ban la : ");
	        nhapMotSoNguyen(luachon);
		switch(luachon){
			case 1:{
				nhapMang2C(arr,n,m);
				printf("Mang sau khi duoc tao : \n");
				xuatMang2C(arr,n,m);
				break;
			}
			case 2:{
				printf("\n\tTong phan tu co chi so LE dau tien = %d",tongChuSoDauLe(arr,n,m));
				break;
			}
			case 3:{
				xuatSoHoanThienTrongMang(arr,n,m);
				break;
			}
			case 4:{
				printf("\n\tTong ca phan tu co tri tuyet duoi lon hon so lien sau no la : %d",tongPtuLonHonTriTuyetDoiLienSau(arr,n,m));
				break;
			}
			case 5:{
				printf("Nhap dong thu K = ");
				nhapMotSoNguyen(k);
				printf("\n\tTong dong thu %d = %d ", k,tongGiaTriTrenDongThuK(arr,n,m,k));
				break;
			}
			case 6:{
				printf("\n\tTong duong bien = %d ", tongDuongBien(arr,n,m));
				break;
			}
			case 7:{
				printf("\n\tTat ca so chan trong ma tran la %d ", demSoChan(arr,n,m));
				printf("\n\tTat ca so Le trong ma tran la %d ", demSoLe(arr,n,m));
				printf("\n\tTat ca so Am trong ma tran la %d ", demSoAm(arr,n,m));
				printf("\n\tTat ca so Duong trong ma tran la %d ", demSoDuong(arr,n,m));
				printf("\n\tTat ca so Nguen To trong ma tran la %d ", demSoNguyenToTrongMang(arr,n,m));
				break;
			}
			case 8:{
				demSoLanX_XuatHienTrongMang(arr,n,m,x);
				break;
			}
			case 9:{
				xuatCacCotMin(arr,n,m);
				break;
			}
			case 10:{
				dongCoNhieuSoHoanThienNhat(arr,n,m);
				break;
			}
			case 11:{
				xuatChiSoDongToanChan(arr,n,m);
				break;
			}
			case 12:{
				if(TimSoNguyenToNhoNhat(arr,n,m) == -1)
					printf("\n\tKhong co So nguyen to nao trong mang!!!");
				else
				printf("\n\tSo nguyen To Nho Nhat trong Mang 2 chieu la %d ", TimSoNguyenToNhoNhat(arr,n,m));
				break;
			}
			case 13:{
				int cotThuI;
				printf("\n\tNhap cot thu K can tim : ");scanf("%d", &cotThuI);
				printf("\n\t[> <]Phan tu %d LON NHAT O Cot Thu %d ", timPTLonNhatCotThuK(arr,n,m,cotThuI),cotThuI);
				printf("\n\t[> <]Phan tu %d NHO NHAT O Cot Thu %d ", timPTNhoNhatCotThuK(arr,n,m,cotThuI),cotThuI);
				break;
			}
			case 14:{
				int dongThuI;
				printf("\n\tNhap Dong thu K can tim : ");scanf("%d", &dongThuI);
				printf("\n\t[> <]Phan tu %d LON NHAT O Dong thu %d ", timPTLonNhatDongThuI(arr,n,m,dongThuI),dongThuI);
				printf("\n\t[> <]Phan tu %d LON NHAT O Dong thu %d ", timPTNhoNhatDongThuI(arr,n,m,dongThuI),dongThuI);
				break;
			}
			case 15:{
				timGiaTriXuatHienNhieuNhatTrongMang(arr,m,n);
				break;
			}
			case 16:{
				int l,k;
				do{	
				printf("\n\tHoan Doi hang : ");scanf("%d", &l);
				printf("\n\tVoi Hang : ");scanf("%d", &k);
				if(l < 0 || k < 0 || l >= n || k >= n)
					printf("\n\t\tHang khong hop le!!!Vui long nhap lai");
			}while(l < 0 || k < 0 || l >= n || k >= n);
				hoanVi2Hang(arr,n,m,l,k);
				break;
			}
			case 17:{
				int x;
				do{
					printf("\n\tCot muon xoa : ");scanf("%d", &x);
					if(x < 0 || x >= m)
						printf("\n\tCot khong hop le!!!!"); 
				}while(x < 0 || x >= m);
				printf("\n\tCot thu %d Sau khi duoc Xoa \n", x);
				delete1Cot(arr,n,m,x);
				break;
			}
			case 18:{
				chieuMaTranTheoTrucNgang(arr,n,m);
				break;
			}
			case 19:{
				Itemtype b[MAXSIZE], k;
				printf("\n\tSap Xep Mang tang dan theo Dang XOAN OC \n");
				bienDoi2Cthanh1C(arr,n,m,b,k);
				sapXep1CMoiTaoTangDAN(b,k);
				xuatMaTranTangDanTheoHinhXoanOc(b,arr,n,m);
				xuatMang2C(arr,n,m);
				break;
			}
			case 20:{
				taoMaTran_ToanChan(arr,n,m);
				printf("\n\tMANG TOAN CHAN SAU KHI SINH  \n");
				xuatMang2C(arr,n,m);
				break;
			}
			case 21:{
				Itemtype b[MAXSIZE], k;//Khoi Tao mang 1C Chua Tat ca gia tri trong Mang 2C
				printf("\n\tSap Xep Mang tang dan theo Dang ZIC ZAC\n");
				bienDoi2Cthanh1C(arr,n,m,b,k);//Gan Tat Ca phan tu mang vao Mang 1C Vua tao
				sapXep1CMoiTaoTangDAN(b,k);//Sap Xep Mang 1C Tang Dan
				sapXepMaTranTangDanZicZac(b,arr,n,m);
				break;
			}
		}
	}while(luachon != 0);	
}

