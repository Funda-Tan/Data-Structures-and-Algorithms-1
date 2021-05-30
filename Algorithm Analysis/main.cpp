//Funda Tan 21801861
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void function1(int* arr1, int* arr2, int* arr3, int size1){
    //append array3 with array1's items
    for(int i = 0; i < size1; i++){
        arr3[i] = arr1[i];
    }

    for(int i = size1; i < size1*2; i++){
        arr3[i] = arr1[size1-1];
    }

    //find place in arr3 for arr2's items to insert
    bool flag = false;
    int counter = 0;
    for(int i = 0; i < size1; i++){
            flag = false;
        for(int j = 0; j < size1*2; j++){ //time complexity O(n^2) because I used a flag to
            if(flag == false){             //escape when the item is inserted
                if(arr2[i] <= arr3[j]){
                    for(int k = size1*2-1; k >= j; k--){
                        arr3[k] = arr3[k-1];
                    }
                    arr3[j] = arr2[i];
                    flag = true;
                    counter++;
                }
            }
        }
    }

    //insert the remainins ones
    if(counter!= size1){
        int i = 0;
        while(counter < size1){
            arr3[size1*2-1-i] = arr2[size1-1-i];
            counter++;
            i++;
        }
    }
}

void function2(int* arr1, int* arr2, int* arr3, int size1){
    int arrCounter1 = 0;
    int arrCounter2 = 0;
    int arrCounter3 = 0;

    //find the small one and insert it to arr3
    while(arrCounter1 < size1 && arrCounter2 < size1){
        if(arr1[arrCounter1] < arr2[arrCounter2]){
            arr3[arrCounter3] = arr1[arrCounter1];
            arrCounter3++;
            arrCounter1++;
        }

        else{
            arr3[arrCounter3] = arr2[arrCounter2];
            arrCounter3++;
            arrCounter2++;
        }
    }

    //insert the remaining ones
    while(arrCounter1 < size1){
        arr3[arrCounter3] = arr1[arrCounter1];
        arrCounter3++;
        arrCounter1++;
    }

    while(arrCounter2 < size1){
        arr3[arrCounter3] = arr2[arrCounter2];
        arrCounter3++;
        arrCounter2++;
    }
}

int main()
{
    //FUNCTION 1
    // arr1 is smaller than arr2
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = i+1;
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = i+1+size1;
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }

    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10; i++)
        function1(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 1: Case 1: ";
    cout << "Execution took " << duration / 10 << " milliseconds." << endl;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

    // arr2 is smaller than arr1
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = i+1+size1;
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = i+1;
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }
    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10; i++)
        function1(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 1: Case 2: ";
    cout << "Execution took " << duration / 10 << " milliseconds." << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

    //no ordering
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = rand();
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = rand();
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }

        sort(arr1,arr1+size1);
        sort(arr2,arr2+size1);
    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10; i++)
        function1(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 1: Case 3: ";
    cout << "Execution took " << duration / 10 << " milliseconds." << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

    //FUNCTION 2
    // arr1 is smaller than arr2
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = i+1;
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = i+1+size1;
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }

    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10000; i++)
        function2(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 2: Case 1: ";
    cout << "Execution took " << duration / 10000 << " milliseconds." << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

    // arr2 is smaller than arr1
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = i+1+size1;
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = i+1;
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }

    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10000; i++)
        function2(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 2: Case 2: ";
    cout << "Execution took " << duration / 10000 << " milliseconds." << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

    // no ordering
    for(int size1 = 10; size1 < 100001; size1 = size1 * 10){
        int* arr1 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr1[i] = rand();
        }

        int* arr2 = new int[size1];
        for(int i = 0; i < size1; i++){
            arr2[i] = rand();
        }

        int* arr3 = new int[size1*2];
        for(int i = 0; i < size1*2; i++){
            arr3[i] = 0;
        }

        sort(arr1,arr1+size1);
        sort(arr2,arr2+size1);

    //Store the starting time
    double duration;
    clock_t endTime;
    clock_t startTime = clock();
    duration = 1000 * double( startTime ) / CLOCKS_PER_SEC;

    for(int i = 0; i < 10000; i++)
        function2(arr1, arr2, arr3, size1);

    endTime = clock();
    duration = 1000 * double( endTime ) / CLOCKS_PER_SEC;
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Function 2: Case 3: ";
    cout << "Execution took " << duration / 10000 << " milliseconds." << endl;

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    }

return 0;
}

