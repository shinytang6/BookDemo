#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

// ���ֲ��ҷ�������������arr�У�����target
// ����ҵ�target,������Ӧ������index
// ���û�ҵ�target,����-1
template<typename T>
int binarySearch(T arr[], int n, T target){
	
	// ��arr[l...r]֮�в���target
	int l = 0, r = n-1;
	while(l <= r){
		
		//int mid = (l+r)/2;
		// ��ֹ���������������������ӷ������������ʹ��������߼����mid
		// �ᣡ����
		int mid = l + (r-l)/2;

		if(arr[mid] == target)
			return mid;
		if(target < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}


// �õݹ�ķ�ʽд���ֲ��ҷ�
template<typename T>
int __binarySearch2(T arr[] ,int l ,int r,int target){
	if(l>r) 
		return -1;

	// ��ֹ���������������������ӷ������������ʹ��������߼����mid
	int mid = l + (r-l)/2;

	if(arr[mid] == target)
		return mid;
	if(arr[mid] > target)
		return __binarySearch2(arr ,l , mid-1,target);
	else
		return  __binarySearch2(arr ,mid+1 ,r ,target);

}

template<typename T>
int binarySearch2(T arr[], int n, T target){

    return __binarySearch2( arr , 0 , n-1, target);
}


// �ȽϷǵݹ�͵ݹ���ֲ��ҷ���Ч��
// �ǵݹ��㷨�������ڵݹ��㷨
int main(){
	
	int n = 1000000;
    int* a = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        a[i] = i;

    // ���Էǵݹ���ֲ��ҷ�
    clock_t startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;



	// ���Եݹ�Ķ��ֲ��ҷ�
    startTime = clock();

    // �������ǵĴ���������[0...N)
    // ��[0...N)�������ֵʹ�ö��ֲ��ң����ս��Ӧ�þ������ֱ���
    // ��[N...2*N)�������ֵʹ�ö��ֲ��ң���Ϊ��Щ���ֲ���arr�У����Ϊ-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (With Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

	delete[] a;
	return 0;
}