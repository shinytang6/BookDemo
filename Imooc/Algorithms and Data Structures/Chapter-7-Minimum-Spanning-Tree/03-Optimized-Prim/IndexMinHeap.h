#include <iostream>
using namespace std;

// ��С������
template<typename Item>
class IndexMinHeap{

private:
    Item *data;     // ��С�������е�����
    int *indexes;   // ��С�������е�����, indexes[x] = i ��ʾ����i��x��λ��
    int *reverse;   // ��С�������еķ�������, reverse[i] = x ��ʾ����i��x��λ��

    int count;
    int capacity;

    // ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] > data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    // ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j]] > data[indexes[j+1]] )
                j += 1;

            if( data[indexes[k]] <= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    // ���캯��, ����һ���յ�������, ������capacity��Ԫ��
    IndexMinHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    // �����������е�Ԫ�ظ���
    int size(){
        return count;
    }

    // ����һ������ֵ, ��ʾ���������Ƿ�Ϊ��
    bool isEmpty(){
        return count == 0;
    }

    // ����С�������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
    // �����i���û�����,�Ǵ�0������
    void insert(int index, Item item){
        assert( count + 1 <= capacity );
        assert( index + 1 >= 1 && index + 1 <= capacity );

        index += 1;
        data[index] = item;
        indexes[count+1] = index;
        reverse[index] = count+1;
        count++;
        shiftUp(count);
    }

    // ����С��������ȡ���Ѷ�Ԫ��, �������������洢����С����
    Item extractMin(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // ����С��������ȡ���Ѷ�Ԫ�ص�����
    int extractMinIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // ��ȡ��С�������еĶѶ�Ԫ��
    Item getMin(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    // ��ȡ��С�������еĶѶ�Ԫ�ص�����
    int getMinIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    // ������i���ڵ�λ���Ƿ����Ԫ��
    bool contain( int index ){

        return reverse[index+1] != 0;
    }

    // ��ȡ��С������������Ϊi��Ԫ��
    Item getItem( int index ){
        assert( contain(index) );
        return data[index+1];
    }

    // ����С������������Ϊi��Ԫ���޸�ΪnewItem
    void change( int index , Item newItem ){

        assert( contain(index) );
        index += 1;
        data[index] = newItem;

        shiftUp( reverse[index] );
        shiftDown( reverse[index] );
    }

};