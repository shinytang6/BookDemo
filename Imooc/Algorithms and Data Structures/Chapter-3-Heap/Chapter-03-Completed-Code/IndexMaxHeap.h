#include <iostream>
using namespace std;

// Advanced�汾����reverse����������ʹ��change����Ч�ʸ���
template<typename Item>
class IndexMaxHeap{
	
private:
	Item* data;  // ����������е�����
	int* indexes; // ����������е�����
	int* reverse;  // ����������еķ���������, reverse[i] = x ��ʾ����i��x��λ��
	int count;
	int capacity;

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftUp(int k){
		while( k>1 && data[indexes[k/2]] < data[indexes[k]]){
			swap( indexes[k/2], indexes[k]);

			// ����indexes[k]��indexes[k/2]�Ѿ��ߵ�
			reverse[indexes[k]] = k;
			reverse[indexes[k/2]] = k/2;
			k = k/2;
		}
	}

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftDown(int k){
		// �жϽڵ��Ƿ�������
		while( 2*k <= count){
			
			int j = 2 * k;
			if( j+1 <= count && data[indexes[j+1]] > data[indexes[j]])
				j++;
			// data[j] �� data[2*k]��data[2*k+1]�е����ֵ

			if(data[indexes[k]] >= data[indexes[j]])
				break;
			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	
	}

public:
	
	// ���캯��, ����һ���յ�������, ������capacity��Ԫ��
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		// 0��ʾ�����ڸ�i
		for(int i=0; i<=capacity; i++)
			reverse[i] = 0;

		this->count = 0;
		this->capacity = capacity;
	}


	~IndexMaxHeap(){
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	// ���ض��е�Ԫ�ظ���
	int size(){
		return count;
	}

	// �ж϶����Ƿ�Ϊ��
	int isEmpty(){
		return count == 0;
	}

	// ������������в���һ����Ԫ��item
	// ��ָ������
	// �����i���û����ԣ��Ǵ�0��ʼ������
	void insert(int i, Item item){

		assert( count+1 <= capacity);
		assert( i+1 <= capacity && i+1 >= 1);

		i++;
		data[i] = item;
		indexes[count+1] = i;
		reverse[i] = count + 1;

		count++;
		shiftUp( count );
	}

	// �������������ȡ���Ѷ�Ԫ��, �������������洢���������
	Item extractMax(){

		assert(count > 0);

		Item ret = data[indexes[1]];

		swap( indexes[count], indexes[1]);
		reverse[indexes[1]] = 1;
		// 0��ʾ�����ڣ���Ϊ����count--��ʾɾ���������һ��Ԫ��
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	// �������������ȡ���Ѷ�Ԫ�ص�����
	Item extractMaxIndex(){

		assert(count > 0);

		// ���û����صģ���Ҫ��1
		int ret = indexes[1] - 1;

		swap( indexes[count], indexes[1]);
		reverse[indexes[1]] = 1;
		// 0��ʾ�����ڣ���Ϊ����count--��ʾɾ���������һ��Ԫ��
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	Item getItem(int i){
		assert(contain(i));
		return data[i+1];
	}

    // ������i���ڵ�λ���Ƿ����Ԫ��
	bool contain(int i){
		assert( i+1>=1 && i+1<=capacity);
		return reverse[i+1] != 0;
	
	}

	void change(int i, Item newItem){
		
		assert(contain(i));
		i++;
		data[i] = newItem;

		//// ��Ҫ�ҵ�j,����indexes[j]=i, j��ʾdata[i]�ڶ��е�λ��
		//// Ȼ��������Ųһ�� shiftUp(j),��shiftDown(j);
		//for(int j=1; j<=count; j++){
		//	if(indexes[j] == i){
		//		shiftUp(j);
		//		shiftDown(j);
		//		return;
		//	}
		//}

		// ��ʱchange����ʱ�临�Ӷ�ΪO(logn)
		// ���� reverse ֮��,
        // ���ǿ��Էǳ��򵥵�ͨ��reverseֱ�Ӷ�λ����i��indexes�е�λ��,�����ñ���һ������
		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);
	}

};