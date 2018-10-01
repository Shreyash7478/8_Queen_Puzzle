#include<iostream>
using namespace std;
void display(int arr[]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << "0 ";
		}
		cout << "1 ";
		for (int j = arr[i] + 1; j < 8; j++) {
			cout << "0 ";
		}
		cout << "\n";
	}

	cout << "\n_____________________________\n\n";
}
bool found(int arr[], int c, int r) {
	for (int i = 0; i < r; i++) {
		if (arr[i] == c) {
			return true;
		}
	}
	return false;
}
bool diagonal(int arr[], int c, int r) {
	for (int i = 0; i < r; i++) {
		if (((i-r)==(arr[i]-c)) || ((r - i) == (arr[i] - c))) {
			return true;
		}
	}
	return false;
}
void solved(int arr[], int r = 0) {
	if (r == 8) {
		display(arr);
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (!(found(arr, i, r)) && !(diagonal(arr, i, r))) {
			arr[r] = i;
			solved(arr, r + 1);
		}
	}
}
int main() {
	int arr[8];
	solved(arr);
	system("pause");
}