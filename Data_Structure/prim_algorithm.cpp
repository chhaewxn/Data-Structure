#include <stdio.h>
#define MAX_VERTICES 8
#define MAX_ELEMENT 200
#define INF 1000L
#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
	int index;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

int weight[MAX_VERTICES][MAX_VERTICES] =
{ {0, 3, INF, INF, INF, INF, INF, 14},
{3, 0, 8, INF, INF, INF, INF, 10},
{INF, 8, 0, 15, 2, INF, INF, INF},
{INF, INF, 15, 0, INF, INF, INF, INF},
{INF, INF, 2, INF, 0, 9, 4, 5},
{INF, INF, INF, INF, 9, 0, INF, INF},
{INF, INF, INF, INF, 4, INF, 0, 6},
{14, 10, INF, INF, 5, INF, 6, 0} };
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];

int isInHeap(HeapType* h, int index)
{
	for (int i = 1; i <= h->heap_size; i++)
		if (h->heap[i].index == index)
			return 1;
	return 0;
}

// Delete the root at heap h, (# of elements: heap_size)
element delete_min_heap(HeapType* h)
{
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];
	int parent = 1;
	int child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;
}

void build_min_heap(HeapType* h)
{
	element temp;
	int parent, child;

	int half_size = h->heap_size / 2;
	for (int i = half_size; i > 0; i--)
	{
		temp = h->heap[i];

		parent = i;
		child = 2 * i;

		while (child <= h->heap_size) {
			if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
				child++;
			if (temp.key <= h->heap[child].key)
				break;

			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}

		h->heap[parent] = temp;
	}
}

// decrease the element i's value to 'key'
void Decrease_key_min_heap(HeapType* h, int i, int key)
{
	if (key >= h->heap[i].key)
		printf("New key is smaller than current key\n");

	while (i > 1 && h->heap[i].key < h->heap[parent[i]].key)
	{
		element temp = h->heap[i];
		h->heap[i] = h->heap[parent[i]];
		h->heap[parent[i]] = temp;
		i = parent[i];
	}

	h->heap[i].key = key;
}

void prim(HeapType* h, int s, int n)
{
	int i, v, u;
	element min;
	for (i = 2; i <= n; i++)
	{
		dist[i] = INF;
		h->heap[i].key = dist[i];
		h->heap[i].index = i;
		parent[i] = -1;
	}

	dist[s + 1] = 0;
	h->heap[s + 1].key = dist[s + 1];
	h->heap[s + 1].index = 1;
	parent[s + 1] = -1;

	h->heap_size = n;
	build_min_heap(h);

	for (i = 0; i < n; i++) {
		min = delete_min_heap(h);
		u = min.index;

		for (v = u + 1; v <= n; v++)
			if (weight[u - 1][v - 1] != INF)
				if (isInHeap(h, v) && weight[u - 1][v - 1] < dist[v])
				{
					dist[v] = weight[u - 1][v - 1];
					parent[v] = u;
					Decrease_key_min_heap(h, v, dist[v]);
				}
		build_min_heap(h);
	}
}

void print_prim(HeapType* h, int s, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (parent[j] == i)
				printf("Vertex %d -> %d		edge: %d\n", i - 1, j - 1, dist[j]);
}

void main()
{
	HeapType distance;
	prim(&distance, 0, MAX_VERTICES);
	print_prim(&distance, 0, MAX_VERTICES);
}
