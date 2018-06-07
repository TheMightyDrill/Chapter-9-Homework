//#include <iostream>
//
//using namespace std;
//
////chapter 9 challenge #2
//
////Parameters (array, first position, final position, integer being searched for)
//int  recursiveBinarySearch(int arr[], int firstEl, int lastEl, int needInt) {
//	
//	if (arr[(lastEl + firstEl)/2] < needInt) {
//
//		firstEl = (lastEl + firstEl) / 2;
//
//		return recursiveBinarySearch(arr, firstEl, lastEl, needInt);
//
//	}
//	
//	if(arr[(lastEl+firstEl)/2] > needInt ) {
//
//		lastEl = (lastEl) / 2;
//
//		return recursiveBinarySearch(arr, firstEl, lastEl, needInt);
//	}
//
//	return arr[(lastEl+firstEl)/2];
//}
//
//int main() {
//
//
//	int arr[100];
//	arr[0] = 3;
//
//	for (int i = 1; i < 100; i++) {
//		arr[i] = arr[i - 1] + 3;
//	}
//
//	cout << recursiveBinarySearch(arr, 0, 99, 72) << endl;
//
//
//	system("pause");
//	return 0;
//}