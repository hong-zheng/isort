#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
void display(vector<int>& arr){
	int sz = arr.size();
	for (int i = 0; i < sz; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}
void ss(vector<int>& arr){
	int sz = arr.size();
	// [0,sz-2]
	for (int i = 0; i < sz - 1; ++i){
		int cur = arr[i];
		int curi = i;
		for (int j = i + 1; j < sz; ++j){
			if (arr[j] < cur){
				curi = j;
				cur = arr[j];
			}
		}
		if (curi != i){
			swap(arr[i], arr[curi]);
		}
	}
}

void is(vector<int>& arr){
	int sz = arr.size();
	// 插入排序
	for (int i = 1; i < sz; ++i){
		int end = i;
		// 待插入数据
		int key = arr[end];
		int j = 0;
		for (j = end - 1; j >= 0 && arr[j]>key; --j){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
// 时间复杂度：最坏O(N^2) 最好O(N) 平均O(N^2)
// 空间复杂度：O(1)->常数个变量个数
// 稳定性：稳定
// 数据敏感度（数据有序与无序对算法的影响是否较大）：敏感
// 注意边界问题:<= >= < >等的用法及其意义
void isL(vector<int>& arr){
	int len = arr.size();
	for (int i = 0; i < len-1; ++i){
		int end = i;// 有序元素的最后一个位置
		int key = arr[end + 1];
		// 找到第一个小于 key 的位置
		while (end >= 0 && arr[end] > key){
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void shells(vector<int>& arr){
	int sz = arr.size();
	int gap = sz / 2;
	while (gap >= 1){
		for (int i = gap; i < sz; ++i){
			int end = i-gap;
			int cur = arr[i];
			while (end >= 0 && arr[end] > cur){
				arr[end+gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = cur;
		}
		gap /= 2;
	}
}

// 时间复杂度：最坏O(N^1.3) 最好O(N^1.3s) 平均O(N^1.3)
// 空间复杂度：O(1)->常数个变量个数
// 稳定性：不稳定，分组时相同组的元素不一定可以分在相同的组
// 数据敏感度（数据有序与无序对算法的影响是否较大）：敏感（本质就是插入排序，因此敏感）
// shell 排序是逻辑排序，逻辑分组即可
void shellSort(vector<int>& arr){
	int n = arr.size();
	// 通过步长gap进行逻辑分组
	// 组内进行插入排序
	// 不同组的元素交替进行排序
	int gap = n / 2;
	while (gap >= 1){
		for (int i = 0; i < n - gap; ++i){
			int end = i;
			int key = arr[end + gap];
			while (end >= 0 && arr[end] > key){
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		gap /= 2;
	}
}
void t(){
	void slsort(vector<int>& arr);
	vector<int> arr = { 239,8,7,251,9,0,87,54,39,8,789,1,36,40 };
	display(arr);
	slsort(arr);
	display(arr);
}
void tt(){
	srand(time(NULL));
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i){
		arr.push_back(rand() % 1000);
	}
	size_t beg = clock();
	shellSort(arr);
	size_t end = clock();
	cout << "sort :" << end - beg << endl;
	
	beg = clock();
	shellSort(arr);
	end = clock();
	cout << "after :" << end - beg << endl;
}
int main(){
	tt();

	system("pause");
	return 0;
}


// 插入排序
void isort(vector<int>& arr){
	int sz = arr.size();
	for (int i = 1; i < sz; ++i){
		int cur = arr[i];
		int end = i-1;
		while (end >= 0 && arr[end] > cur){
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = cur;
	}
}
// 选择排序
void ssort(vector<int>& arr){
	int sz = arr.size();
	for (int i = 0; i < sz; ++i){
		int cur = arr[i];
		int curi = i;
		for (int j = i + 1; j < sz; ++j){
			if (arr[j] < cur){
				cur = arr[j];
				curi = j;
			}
		}
		if (curi != i){
			swap(arr[i], arr[curi]);
		}
	}
}
//希尔排序
void slsort(vector<int>& arr){
	int sz = arr.size();
	int gap = sz / 2;
	while (gap >= 1){
		for (int i = gap; i < sz; ++i){
			int end = i - gap;
			int cur = arr[i];
			while (end >= 0 && arr[end] > cur){
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = cur;
		}
		gap /= 2;
	}
}