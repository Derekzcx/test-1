#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//冒泡排序 平均时间复杂度为 n^2
void Bubble_Sort(vector<int> &vec){
	for(int i =0; i<vec.size()-1; i++){
		for(int j=i+1; j<vec.size(); j++){
			if(vec[j] < vec[i]) swap(vec[j], vec[i]);
		}
	}
} 
// 插入排序 ，平均时间复杂度为 n^2
void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1]<vec[j]) swap(vec[j], vec[j+1]);
			else break;
		}
	}
} 

// 希尔排序，平均时间复杂度为 n^1.3, 参数2 表示初始间隔 
void Shell_Sort(vector<int> &vec, int n){
	while(n != 0){
		for(int k =0 ; k<n ; k++){
			for(int i=k+n; i<vec.size(); i+=n){
				for(int j=i-n; j>=0; j-=n){
					if(vec[j+n] < vec[j]) swap(vec[j+n], vec[j]);
					else break;
				}
			}
		}
		n = n/2;
	}
} 

// 快排, 平均时间复杂度为 nlogn
void Quick_Sort(vector<int> &vec, int l, int r){
	if(l>=r) return;
	int base_val = vec[l];
	int left = l;
	int right = r;
	bool flag = false;
	while(l!=r){
		if(flag == false){ // 比右边 
			if(vec[r] < base_val){
				vec[l] = vec[r];
				l++;
				flag = true;
			}else{
				r--;
			}
		}else{ // 比左边 
			if(vec[l] > base_val){
				vec[r] = vec[l];
				r--;
				flag = false;
			}else{
				l++;
			}
		}
	}
	vec[l] = base_val;
	Quick_Sort(vec, left, l);
	Quick_Sort(vec, l+1, right);
} 

// 选择排序 , 平均时间复杂度为 n^2
void Insertion_Sort(vector<int> &vec){
	//选择最小值一直放到全面
	for(int i=0; i<vec.size()-1; i++){
		int min = i;
		for(int j=i+1; j<vec.size(); j++){
			if(vec[j] < vec[min]) {min = j;}
		}
		swap(vec[i], vec[min]);	
	} 
} 

// 归并排序, 平均时间复杂度为 nlogn
void Merga_Sort(vector<int> &vec, vector<int> &tmp, int l, int r){
	// 出口 
	if(l >= r) return;
	// 形式上的分区
	int left1 = l;
	int right1 = (l+r)/2;
	int left2 = right1 + 1;
	int right2 = r;
	Merga_Sort(vec,tmp,left1, right1);
	Merga_Sort(vec, tmp, left2, right2);
	
	// 合并
	int k = l;
	while(left1 <= right1 && left2 <= right2){
		if(vec[left1] <= vec[left2]){
			tmp[k] = vec[left1];
			left1++;
			k++;
		}else{
			tmp[k] = vec[left2];
			left2++;
			k++;
		}
	} 
	while(left1 <= right1){
		tmp[k] = vec[left1];
		left1++;
		k++;
	}
	while(left2 <=right2){
		tmp[k] = vec[left2];
		left2++;
		k++;
	}
	for(int k=l; k<=r; k++){
		vec[k] = tmp[k];
	}
} 


// 堆排序，平均时间复杂度为 nlogn
void heapfiy(vector<int> &vec, int i, int end){
	if(i >= end) return;
	int last_node = i;
	int left_son = 2*i+1;
	int right_son = 2*i+2;
	if(left_son < end && vec[left_son] > vec[last_node]) last_node = left_son;
	if(right_son < end && vec[right_son] > vec[last_node]) last_node = right_son;
	if(last_node != i){
		swap(vec[last_node] , vec[i]);
		heapfiy(vec, last_node, end);
	}
} 
void Heap_Sort(vector<int> &vec, int n){
	// 第一次建堆 ， 
	for(int i = (n-1-1)/2; i>=0; i--){
		heapfiy(vec, i, n);
	}
	// 维护堆的性质
	for(int i=n-1; i>=0; i--){
		swap(vec[0], vec[i]);
		heapfiy(vec, 0, i);
	} 
}
 
//

//遍历打印
void printval(int val){
	printf("%d ", val);
} 
int main(){
	vector<int> vec{1, 12, 31, 11, 0, 2, 26, 240, 241, 3009, 11, 2, 11, 0, 12, 9, 111, 999};
	const char* str1 = "before sort:";
	const char* str2 = "after sort:" ;
	printf("%s \n", str1);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("%s \n", str2);
	
	// 冒泡排序测试
//	Bubble_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval);

	// 插入排序测试
//	Insert_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval);
	
//	Shell_Sort(vec, 4);
//	for_each(vec.begin(), vec.end(), printval);

//	Quick_Sort(vec, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

//	Insertion_Sort(vec);
//    for_each(vec.begin(), vec.end(), printval);

//	vector<int> tmp(vec.size(), 0);
//	Merga_Sort(vec, tmp, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

//	Heap_Sort(vec, vec.size());
//	for_each(vec.begin(), vec.end(), printval);
	
	return 0;
}
