#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main(){
	int n = 100000;

	// ��ȻisConnectedֻ��ҪO(1)��ʱ��, ������union������ҪO(n)��ʱ��
	// ������Թ��̵��㷨���Ӷ���O(n^2)��
	UnionFindTestHelper::testUF1(n);

	return 0;
}