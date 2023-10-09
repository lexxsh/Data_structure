#include "array.h"
#include <iostream>

int main() {
    DynamicArray arr;

    for(int i = 0; i <10;i++){
	    arr.add(i);
    }
    arr.remove(0);
    arr.remove(0);
    arr.remove(0);

    arr.put(2,999);
    for(int i = 10;i<50;i++){
	    arr.add(i);
    }

    arr.remove(2);
    for(int i = 0; i<arr.size();i++){
	    std::cout<<arr.get(i)<<" ";
    }
    std::cout<<"\n";
}
