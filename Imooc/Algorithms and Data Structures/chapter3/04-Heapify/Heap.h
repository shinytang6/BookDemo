#include <iostream>
using namespace std;

template<typename Item>
class MaxHeap{
	
private:
	Item* data;
	int count;
	int capacity;

	// 将元素插入到最大堆合适的位置
	void shiftUp(int k){
		while( k>1 && data[k/2] < data[k]){
			swap(data[k/2], data[k]);
			k = k/2;
		}
	}

	void shiftDown(int k){
		// 判断节点是否有左孩子
		while( 2*k <= count){
			
			int j = 2 * k;
			if( j+1 <= count && data[j+1] > data[j])
				j++;
			// data[j] 是 data[2*k]和data[2*k+1]中的最大值

			if(data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	
	}

public:
	// 因为这里的最大堆从1开始编号，所以要空出数组0处的位置
	// 构造一个空堆，可容纳capacity个元素
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		this->count = 0;
		this->capacity = capacity;
	}

	// 通过一个给定数组创建一个最大堆
	// 该构造堆过程中，时间复杂度为O(n)
	// heapify
	MaxHeap(Item arr[], int n){
		data = new Item[n+ 1];
		this->capacity = n;
		for(int i=0; i<n ; i++)
			data[i+1] = arr[i];
		this->count = n;

		// 完全二叉树中最后一个非叶子节点的序号是n/2，所以从n/2开始向前进行shiftDown
		for(int i=count/2; i>=1; i--){
			shiftDown(i);
		}
	
	}

	~MaxHeap(){
		delete[] data;
	}

	// 返回堆中的元素个数
	int size(){
		return count;
	}

	// 判断堆中是否为空
	int isEmpty(){
		return count == 0;
	}

	// 向最大堆中插入一个新元素item
	void insert(Item item){

		assert( count+1 <= capacity);
		data[count+1] = item;
		count++;
		shiftUp( count );
	}

	// 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
	// 最大堆的移出操作都是针对根节点进行的，移出后将最后一个叶节点移到根节点，再重新进行shiftDown操作构成新的最大堆
	// 若对数组进行依次移出操作，则返回的结果是从大到小的排列
	Item extractMax(){

		assert(count > 0);
		Item ret = data[1];

		swap(data[count], data[1]);
		count--;
		shiftDown(1);

		return ret;
	}



public:
    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2.0, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2.0,level))+1,int(pow(2.0,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

};