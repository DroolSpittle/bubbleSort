#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a);
void selectionSort(vector<int>& a);
void printVector(vector<int> a);

int main()
{
    vector<int> decreasingInts;

    ifstream randomInts("ints.txt");

    int readIn = 0;

    while(randomInts >> readIn)
    {
        decreasingInts.push_back(readIn);
    }

    //randomInts.close();

    printVector(decreasingInts);

    bubbleSort(decreasingInts);

    printVector(decreasingInts);

    cout << "The largest element in the array using a bubble sort is: " << decreasingInts[0] << "\n\n";

    vector<int> selectSort;

    //ifstream randomInts("ints.txt");

    randomInts.clear();
    randomInts.seekg(0);

    readIn = 0;

    while(randomInts >> readIn)
    {
     selectSort.push_back(readIn);
    }

    randomInts.close();

    printVector(selectSort);

    selectionSort(selectSort);

    printVector(selectSort);

    cout << "The largest element in the array using a selection sort is: " << selectSort[0] << "\n\n";

    return 0;
}

void bubbleSort(vector<int>& a)
{
    bool swap = true;
    while(swap == true)
    {
        swap = false;
        for(size_t i = 0; i < a.size()-1; i++)
        {
            if(a[i]<a[i+1])
            {
                a[i] += a[i+1];
                //cout << "a[i]: " << a[i] << " a[i+1]:" << a[i+1] << "\n";
                a[i+1] = a[i] - a[i+1];
                //cout << "a[i]: " << a[i] << " a[i+1]:" << a[i+1] << "\n";
                a[i] -= a[i+1];
                //cout << "a[i]: " << a[i] << " a[i+1]:" << a[i+1] << "\n";
                swap = true;
            }
            
        }
    }
}

void selectionSort(vector<int>& a)
{
    int i = 0;
    int j = 0;
    int minIndex = 0;

    for(i = 0; i < a.size()-1; i++)
    {
        minIndex = i;
        for(j = i + 1; j < a.size(); j++)
        if(a[j] > a[minIndex])
        {
            minIndex  = j;
        }
        int temp = a[minIndex];
        int temp2 = a[i];
        a[minIndex] = temp2;
        a[i] = temp;
    }

}

void printVector(vector<int> a)
{
    for(size_t i=0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}