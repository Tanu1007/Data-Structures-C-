#include <iostream>
using namespace std;

int binarysearch(int arr[],int left,int right,int x){
	while(left<=right){
		int mid = left+(right-left)/2;
		if(arr[mid]==x) return mid;
		else if(arr[mid]<x) left = mid+1;
		else right = mid-1;
	}
	return -1;
}

int main(){
	int num;
	cin >> num;
	int arr[5];
	for(int i=0;i<5;i++) cin >> arr[i];
	
	int output;
	output = binarysearch(arr,0,9,num);
	if(output==-1) cout << "No such value: " << endl;
	else cout << "Value exist at: " << output+1 << endl;
}
