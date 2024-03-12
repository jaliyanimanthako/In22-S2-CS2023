#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Function to adjust the heap structure to maintain the min-heap property
void minHeapify(vector<int>& heap, int index, int size) {
    int minIndex = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < size && heap[index] > heap[left])
        minIndex = left;
    
    if (right < size && heap[minIndex] > heap[right])
        minIndex = right;
    
    if (minIndex != index) {
        int temp = heap[index];
        heap[index] = heap[minIndex];
        heap[minIndex] = temp;
        minHeapify(heap, minIndex, size);
    }
}

// Function to move an element up the heap if necessary to maintain the min-heap property
void shiftUp(vector<int>& heap, int index) {
    if (index == 0) return;
    int parentIndex = (index - 1) / 2;
    
    if (heap[index] < heap[parentIndex]) {
        int temp = heap[index];
        heap[index] = heap[parentIndex];
        heap[parentIndex] = temp;
        shiftUp(heap, parentIndex);
    }
}

// Function to insert a value into the min-heap
void insertValue(vector<int>& heap, int v, int& size) {
    heap.push_back(v);
    size++;
    shiftUp(heap, size - 1);
}

// Function to delete a value from the min-heap
void deleteValue(vector<int>& heap, int v, int& size) {
    int idx = -1;
    for (int i = 0; i < size; ++i) {
        if (heap[i] == v) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        heap[idx] = heap[--size];
        heap.pop_back();
        minHeapify(heap, idx, size);
    }
}

// Function to get the minimum element from the min-heap
int getMin(const vector<int>& heap) {
    if (!heap.empty())
        return heap[0];
    return -1;
}

int main() {
    int Q, choice, size = 0;
    cin >> Q;
    vector<int> heap;
    while (Q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                int v;
                cin >> v;
                insertValue(heap, v, size);
                break;
            case 2:
                cin >> v;
                deleteValue(heap, v, size);
                break;
            case 3:
                cout << getMin(heap) << endl;
                break;
        }
    }
    return 0;
}
