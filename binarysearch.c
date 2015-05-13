#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int GetRandomInRange ( int min , int max );
void printArray (int* arr, int size);

int binarySearch (int* arr, int target, int size);

int main(){

    /*initialize random*/
    srand( time( NULL ) );

    const int SIZE = 40;

    int testArray[SIZE];
    testArray[0]=GetRandomInRange(0,3);
    for(int i=1; i<SIZE;i++){
        testArray[i]=testArray[i-1]+GetRandomInRange(2,3);
    }

    printArray(testArray,SIZE);

    //one in the array
    printf("%s\n", "/////in the array//////");
    for(int i=0;i<4;i++){
        int tind = GetRandomInRange(0,SIZE-1);
        int bind = binarySearch(testArray,testArray[tind],SIZE);
        printf("value:%d bsi:%d orig:%d\n", testArray[tind],bind,tind);
    }

    printf("%s\n", "/////at the end//////");
    int tind = SIZE-1;
    int bind = binarySearch(testArray,testArray[tind],SIZE);
    printf("value:%d bsi:%d orig:%d\n", testArray[tind],bind,tind);
    
    printf("%s\n", "/////outofrange//////");
    int val = -5;
    bind = binarySearch(testArray,val,SIZE);
    printf("value:%d bsi:%d \n", val,bind);

    val = testArray[SIZE-1]+50;
    bind = binarySearch(testArray,val,SIZE);
    printf("value:%d bsi:%d \n", val,bind); 


    printf("%s\n", "/////not in array//////");
    tind = GetRandomInRange(1,SIZE-1);
    int value = testArray[tind];
    testArray[tind]=testArray[tind]-1;
    bind = binarySearch(testArray,value,SIZE);
    printf("value:%d bsi:%d \n", value,bind);

}

void printArray (int* arr, int size){
    for (int i=0;i<size;i++){
        printf("[%d]:%d\n", i,arr[i]);
    }
}

int GetRandomInRange ( int min , int max ) {

    int random;
    /*calculate inclusive range size*/
    int range = max - min + 1;
    if ( range == 1 )
        return min;
    /*map return 0-range onto min through max*/
    random = (rand() % range) + min;
    return random;
}

int binarySearch (int* array, int target, int size){
    int low =0;
    int high = size-1;
    int med;

    if(target<array[0])return -1;
    if(target>array[size-1])return size;

    do{
        med=low+((high-low)/2);
        if(array[med]==target) return med;
        if(array[med]<target) low=med;
        if(array[med]>target) high=med;
    }while(high-low>1);

    return high;
}