#include <iostream>
using namespace std;


// �Ե����Ϲ鲢����
// ���������Ż��汾
template<typename T>
void mergeSortBottomUp(T arr[], int n){
	for(int sz=1; sz<n; sz=sz+sz)
		// �����������Ϊi<n, i+sz����Խ�磬����Ҫ��֤i+sz<n��ͬʱ�����鲢���ܲ���sz��Ԫ��
		for(int i=0; i+sz<n ; i=i+sz+sz)
			__merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1));
}