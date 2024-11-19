#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
// Note: you can add or delete any code/functions whenever needed

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//(πÈ≤¢≈≈–Ú)
// Note: you can add or delete any code/functions whenever needed
void merge(int* b,int front,int center,int rear){
	int tmp[rear-front+1];
		int p1=front;
		int p2=center+1;
		int p=0;
		for(;p1<=center&&p2<=rear;){
			if(b[p1]<b[p2]){
				tmp[p++]=b[p1++];
			}
			else{
				tmp[p++]=b[p2++];
			}
		}
		for(;p1<=center;) tmp[p++]=b[p1++];
		for(;p2<=rear;) tmp[p++]=b[p2++];
		for(int k=0;k<p;k++){
			b[front+k]=tmp[k];
		}	
}

void mergeSort(int *b, int front,int rear) {
    // Your code here
    //cout<<b[front]<<" "<<b[rear];
		int center=(front+rear)/2;
		if(center<rear){
			mergeSort(b,front,center);
			mergeSort(b,center+1,rear);
			merge(b,front,center,rear);	
		}
}


//(øÏÀŸ≈≈–Ú)
// Note: you can add or delete any code/functions whenever needed
void quickSort(int *a,int front, int rear) {
    // Your code here
    if(rear-front<1) return;

    int center=(front+rear)/2;
    if(a[front]>a[center]){
    	swap(&a[front],&a[center]);
	}
	if(a[center]>a[rear]){
		swap(&a[center],&a[rear]);
	}
	if(a[front]>a[center]){
		swap(&a[front],&a[center]);
	}
	
	swap(&a[center],&a[rear-1]);
	
	int i=front;
	int j=rear-2;
	int pivot=a[rear-1];
	for(;;){
		while(a[i]<pivot) i++;
		while(a[j]>=pivot&&i<j) j--;
		if(i<j) swap(&a[i],&a[j]);
		else break;
	}
	//when i>=j
	cout<<i<<j<<endl;
	swap(&a[i],&a[rear-1]);
	quickSort(a,front,i-1);
	quickSort(a,i+1,rear);
}


int main() {
    int N;
    cin >> N;
    int max_num = 100000;
    int myArray[max_num];
    for (int i = 0; i < N; i++)
        cin >> myArray[i];
	int choice;
	cin >> choice;
	if(choice == 1){
		cout << "Merge Sort" << endl;
		mergeSort(myArray,0, N-1);
	}
	else{
		cout << "Quick Sort" << endl;
		quickSort(myArray,0, N-1);
	}

    for (int i = 0; i < N - 1; i++)
        cout << myArray[i] << " ";
    cout << myArray[N - 1] << endl;
    return 0;
}
