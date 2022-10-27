#include<stdio.h>
#include<conio.h>
double tienDienTrong1Thang(int n){
	double Tien;
	if(n <= 50){
		Tien = n * 1.678;
	}
	else if(n <= 100){
		Tien = 50 * 1.678 + (n - 50) * 1.734;
	}
	else if(n <= 200){
		Tien = 50 * 1.678 + 50 * 1.743 + (n - 100) * 2.014;
	}
	else if(n <= 300){
		Tien = 50 * 1.678 + 50 * 1.743 + 100 * 2.014 + (n - 200) * 2.536;
	}
	else if(n <= 400){
		Tien = 50 * 1.678 + 50 * 1.743 + 100 * 2.014 + 100 * 2.536 + (n - 300) * 2.834;
	}
	else{
		Tien = 50 * 1.678 + 50 * 1.743 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (n - 400) * 2.927;
	}
	return Tien;
}

int main(){
	float n;
	do{
		printf("\n\tNhap So Tien Dien Thang nay : ");scanf("%f", &n);
		if(n <= 0)
			printf("\n\tERROR!!!");
	}while(n <= 0);
	printf("\n\t\tSo Tien Cua Thang Nay Phai Tra la : %lf", tienDienTrong1Thang(n));
	
	
	getch();
	return 0;
}
