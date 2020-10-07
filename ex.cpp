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
	// ��������
	for (int i = 1; i < sz; ++i){
		int end = i;
		// ����������
		int key = arr[end];
		int j = 0;
		for (j = end - 1; j >= 0 && arr[j]>key; --j){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
// ʱ�临�Ӷȣ��O(N^2) ���O(N) ƽ��O(N^2)
// �ռ临�Ӷȣ�O(1)->��������������
// �ȶ��ԣ��ȶ�
// �������жȣ�����������������㷨��Ӱ���Ƿ�ϴ󣩣�����
// ע��߽�����:<= >= < >�ȵ��÷���������
void isL(vector<int>& arr){
	int len = arr.size();
	for (int i = 0; i < len-1; ++i){
		int end = i;// ����Ԫ�ص����һ��λ��
		int key = arr[end + 1];
		// �ҵ���һ��С�� key ��λ��
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

// ʱ�临�Ӷȣ��O(N^1.3) ���O(N^1.3s) ƽ��O(N^1.3)
// �ռ临�Ӷȣ�O(1)->��������������
// �ȶ��ԣ����ȶ�������ʱ��ͬ���Ԫ�ز�һ�����Է�����ͬ����
// �������жȣ�����������������㷨��Ӱ���Ƿ�ϴ󣩣����У����ʾ��ǲ�������������У�
// shell �������߼������߼����鼴��
void shellSort(vector<int>& arr){
	int n = arr.size();
	// ͨ������gap�����߼�����
	// ���ڽ��в�������
	// ��ͬ���Ԫ�ؽ����������
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


// ��������
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
// ѡ������
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
//ϣ������
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