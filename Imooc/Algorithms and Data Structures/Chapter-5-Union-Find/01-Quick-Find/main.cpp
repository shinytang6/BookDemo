#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main(){
	int n = 100000;

	// 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
	// 总体测试过程的算法复杂度是O(n^2)的
	UnionFindTestHelper::testUF1(n);

	return 0;
}