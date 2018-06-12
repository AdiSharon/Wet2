#ifndef WET2_CHAINHASH_H
#define WET2_CHAINHASH_H

#include "List.h"

using namespace DS::ChainHash;

template <typename T, typename getKey, typename Compare>
class ChainHash {
    int array_size;
    int occupied;
    List<T>* lists_array;
    getKey get;
    Compare cmp;

    int hash(int key){
        return key % array_size;
    }

    void reHash(int new_size){
        List<T>* temp = new List<T>[new_size];
        int curr_size = this->array_size;
        try {3
            this->array_size = new_size;
            for (int i = 0; i < curr_size; ++i) {
                for (typename List<T>::Iterator it = lists_array[i].begin(); it != lists_array[i].end() ; it++) {
                    T& curr = it.getData();
                    temp[hash(get(curr))].insert(curr);
                }
            }
        } catch (bad_alloc& exp){
            this->array_size = curr_size;
            delete[] temp;
            throw exp;
        }
        delete[] this->lists_array;
        this->lists_array = temp;
    }

public:

    T& operator=(const ChainHash& CH){
        List<T>* temp = new List<T>[CH.array_size];
        try {
            for (int i = 0; i < CH.array_size; ++i) {
                temp[i] = CH.lists_array[i];
            }
        } catch (bad_alloc& exp) {
            delete[] temp;
            throw exp;
        }
        delete[] this->lists_array;
        this->lists_array = temp;
        this->array_size = CH.array_size;
        this->occupied = CH.occupied;
        this->get = CH.get;
        this->cmp = CH.cmp;
        return *this;
    }

    T& find(const T& data){
        typename List<T>::Iterator it = lists_array[hash(get(data))].find(cmp, data);
        if (it == lists_array[hash(get(data))].end()){
            throw ChainHashElementNotFound();
        }
        return it.getData();
    }

    T& operator[](const T& data) {
        return find(data);
    }

    void insert(const T& data){
        try{
            find(data);
        } catch (ChainHashElementNotFound& exp){
            if (occupied == array_size){
                reHash((array_size * 2));
            }
            lists_array[hash(get(data))].insert(data);
            occupied++;
            return;
        }
        throw ChainHashElementAlreadyExists();
    }

    void remove(T& data) {
        typename List<T>::Iterator it = lists_array[hash(get(data))].find(cmp, data);
        if (it == lists_array[hash(get(data))].end()){
            throw ChainHashElementNotFound();
        }
        lists_array[hash(get(data))].remove(it);
        occupied--;
    }

    int getSize(){
        return this->occupied;
    }

    ChainHash(const T* items_array, int length):
            array_size(length * 2),
            occupied(0),
            lists_array(NULL),
            get(get),
            cmp(cmp){
        if (length <= 0){
            throw ChainHashInvalidInput();
        }
        lists_array = new List<T>[length * 2];
        try {
            for (int i = 0; i < length; ++i) {
                insert(items_array[i]);
            }
        } catch (bad_alloc& exp){
            delete[] lists_array;
            throw exp;
        } catch (ChainHashInvalidInput& exp) {
            delete[] lists_array;
            throw exp;
        }
    }

    ~ChainHash() {
        delete[] lists_array;
    }

    ChainHash(const ChainHash& CH):
            lists_array(CH.lists_array),
            occupied(CH.occupied),
            array_size(CH.array_size),
            get(CH.get),
            cmp(CH.cmp){
        lists_array = new List<T>[CH.array_size];
        try {
            for (int i = 0; i < array_size; ++i) {
                lists_array[i] = CH.lists_array[i];
            }
        } catch (bad_alloc& exp){
            delete[] lists_array;
            throw exp;
        }
    }


};


#endif //WET2_CHAINHASH_H
