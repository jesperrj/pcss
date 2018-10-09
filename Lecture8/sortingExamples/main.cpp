#include <iostream>
#include <vector>

using namespace std;

typedef int* int_ptr;

class ArraySort{
private:
    int original[100];
    int sorted[100];
    int length;
    int comparisons=0;
public:
    // constructor
    ArraySort(int org[], int len):
        length(len){
            for(int i=0;i<len;i++){
                original[i]=org[i];
                sorted[i]=org[i];
            }
    }

    // bubble sort function
    void bubbleSort(){
        bool swap_flag=true;
        int tmp;

        while(swap_flag){
            swap_flag=false;

            for(int i=1;i<length;i++){

                if (sorted[i]<sorted[i-1]){

                    swap_flag=true;

                    tmp=sorted[i];

                    sorted[i]=sorted[i-1];
                    sorted[i-1]=tmp;
                }

                addComplexity();
            }
        }
        return;
    }

    // quick sort function
    void quickSort(int start,int stop){
        if(start<stop){
            int pNdx=start;
            int tmp;
            for(int i=start;i<stop;i++){
                if(sorted[i]<sorted[stop]){
                    tmp=sorted[i];
                    sorted[i]=sorted[pNdx];
                    sorted[pNdx]=tmp;
                    pNdx++;
                }
                addComplexity();
            }
            tmp=sorted[pNdx];
            sorted[pNdx]=sorted[stop];
            sorted[stop]=tmp;

            quickSort(start,pNdx-1);
            //cout<<comparisons<<" ";
            quickSort(pNdx+1,stop);
            //cout<<comparisons<<" ";
        }
        return;
    }

    // function prints the original and sorted array
    void printArray(){
        cout<<"\nOriginal array:\n";
        for(int i=0;i<length;i++){
            cout<<original[i]<<" ";
        }

        cout<<"\nSorted array:\n";
        for(int i=0;i<length;i++){
            cout<<sorted[i]<<" ";
        }
        return;
    }

    // function adds to complexity (comparisons)
    void addComplexity(){
        comparisons++;
    }

    // function that prints complexity
    void printComplexity(){
        cout<<"\nNumber of comparisons:\n";
        cout<<comparisons;
    }

};

int main()
{
    int a[]={5,3,1,4,2,10,2,6,1,7,9,4};
    int len=sizeof(a)/sizeof(a[0]);

    ArraySort array_sort=ArraySort(a,len);

    //array_sort.quickSort(0,len-1);
    array_sort.bubbleSort();

    array_sort.printArray();

    array_sort.printComplexity();

    return 0;
}
