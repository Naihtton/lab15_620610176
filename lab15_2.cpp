#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	double x;
	for(int i=0;i<N;i++){
		cout << "Row " << i+1 << ": ";
		for(int j=0;j<N;j++){
			cin >> x; A[i][j] = x;
		}
	}
}

void findLocalMax(const double C[][N], bool B[][N]){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			if(C[i][j]>=C[i][j-1] && C[i][j] >= C[i][j+1] && C[i][j] >= C[i-1][j] && C[i][j]>=C[i+1][j]){
				B[i][j] = true;
			}else{B[i][j]=false;}
		}
	}
	for(int k=0;k<N;k++){
		B[0][k]=0;
		B[N-1][k]=0;
	}
	for(int l=0;l<N-2;l++){
		B[l+1][0]=0;
		B[l+1][N-1]=0;
	}
}

void showMatrix(const bool D[][N]){
	for (int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(D[i][j]==true){
				cout << "1 ";
			}else cout << "0 ";
		}
		cout << "\n";
	}
}