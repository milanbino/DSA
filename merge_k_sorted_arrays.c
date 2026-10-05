#include <stdio.h>

#define K 3
#define SIZE 4

typedef struct {
    int value;
    int list;
    int index;
} Node;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < n && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void buildHeap(Node heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

int main()
{
    int lists[K][SIZE] = {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    Node heap[K];
    int heapSize = K;

    for (int i = 0; i < K; i++) {
        heap[i].value = lists[i][0];
        heap[i].list = i;
        heap[i].index = 0;
    }

    buildHeap(heap, heapSize);

    printf("Merged list:\n");

    while (heapSize > 0) {

        Node root = heap[0];

        printf("%d ", root.value);

        if (root.index + 1 < SIZE) {

            heap[0].value =
                lists[root.list][root.index + 1];

            heap[0].list = root.list;
            heap[0].index = root.index + 1;

            heapify(heap, heapSize, 0);
        }
        else {
            heap[0] = heap[heapSize - 1];
            heapSize--;

            heapify(heap, heapSize, 0);
        }
    }

    return 0;
}
