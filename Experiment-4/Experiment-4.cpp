//UID - 24BCS12059

/*Building a heap is not O(n log n) because we do not perform a full log n operation on every element. When we build a heap using the bottom-up method, most of the elements are leaf nodes, and leaf nodes do not need any heapify operation. Only a few nodes near the top of the tree require more work, and those are very few in number.

Since most nodes take very little time and only a small number take more time, the total time adds up to O(n), not O(n log n).*/

#include <bits/stdc++.h>
using namespace std;

int parent (int i) { 
    return (i - 1) / 2; 
}

int leftChild (int i) { 
    return 2 * i + 1; 
}

int rightChild (int i) { 
    return 2 * i + 2; 
}

void heapifyDown (vector<int>& heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap.size() && heap[left] < heap[smallest])
        smallest = left;

    if (right < heap.size() && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp (vector<int>& heap, int i) {
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void insertHeap (vector<int>& heap, int val) {
    heap.push_back(val);
    heapifyUp(heap, heap.size() - 1);
}

void deleteAtIndex (vector<int>& heap, int i) {
    if (i < 0 || i >= heap.size()) {
        cout << "Invalid index\n";
        return;
    }

    heap[i] = heap.back();
    heap.pop_back();

    if (i < heap.size()) {
        heapifyUp(heap, i);
        heapifyDown(heap, i);
    }
}

void printHeap (const vector<int>& heap) {
    for (int x : heap)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> heap;

    insertHeap(heap, 10);
    insertHeap(heap, 5);
    insertHeap(heap, 20);
    insertHeap(heap, 2);
    insertHeap(heap, 8);

    printHeap(heap);

    deleteAtIndex(heap, 2);

    printHeap(heap);

    return 0;
}