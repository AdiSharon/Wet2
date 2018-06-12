#include <iostream>
#include "ChainHash.h"

class intcmp {
public:
    bool operator()(int x, int y) const {
        return x==y;
    }
};

class getK {
public:
    int operator() (int x){
        return x;
    }
};

int main() {
    int a[] = {4, 5, 2, 3, 6, 7};
    int length = 6;
    ChainHash<int,getK,intcmp> hash(a, length);
    for(int i=1; i<hash.getSize();i++){
        cout << "Hash insides\t" << hash[i] << endl;
        hash.insert(1);
        hash.insert(10);
        hash.insert(9);
        if(hash.getSize()==9)
            cout << "SizeIsGood\t" << hash[i] << endl;
    }

    cout << "---------------------------------------"<< endl;

//    int b[] = {1, 5, 2, 3, 6, 7};
//    MinHeap<int> heap1(b, length);
//    heap1.insert(11);
//    //heap1.insert(12);
//    //heap1.removeMin();
//    //heap1.insert(0);
//    //heap1.insert(4);
//    while (heap1.getSize() > 0){
//        cout << "Heap Min\t" << heap1.getMin() << endl;
//        heap.removeMin();
//    }

    return 0;
}