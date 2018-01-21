#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main(){
	int n = 100000;

	// ��ȻisConnectedֻ��ҪO(1)��ʱ��, ������union������ҪO(n)��ʱ��
	// ������Թ��̵��㷨���Ӷ���O(n^2)��
	UnionFindTestHelper::testUF1(n);

	// ����UF2��˵, ��ʱ��������O(n*h)��, hΪ���鼯�����������߶�
	// �����ϸ�����, h��lognû�й�ϵ, ������ҿ��Լ���ô���
	// ���Ǻ������ݻ��h�����Ż�, �������, ���h��ԶС��n��
	// ��������ʵ�ֵ�UF2���Խ��ԶԶ����UF1, nԽ��Խ����:)
	UnionFindTestHelper::testUF2(n);

	return 0;
}