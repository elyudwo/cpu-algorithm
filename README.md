# cpu-algorithm
## A조
## 허프만 코드

```
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode* left, * right;
}TreeNode;

typedef struct {
	TreeNode* ptree;//TreeNod와 연결//
	char ch;//문자//
	int key;//문자 빈도수,=weight//
}element;
//element들이 모여서 트리가됨//

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;//유효 원소개수 1부터시작시킴//
}HeapType;
//힙은 트리의 종류//

HeapType * create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;

	}
	h->heap[i] = item;

}
element delete_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if((child<h->heap_size)&&(h->heap[child].key>h->heap[child+1].key))
			child++;
		if (temp.key < h->heap[child].key)break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
//이진 트리 생성 함수//
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}
//이진 트리 제거 함수//
void destroy_tree(TreeNode* root)
{
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}
int is_leaf(TreeNode* root) {
	//leaf가 끝자락, 자식노드가 있는지 없는지 판단하는 함수//
	return !(root->left) && !(root->right);
}
void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {
	//1을 저장하고 순환호출//
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	//0을 저장하고 순환호출//
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}
	if (is_leaf(root)) {
		printf("%c ", root->ch);
		print_array(codes, top);
	}
}

//허프만 코드 생성함수//
void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		//최솟값을 가지는 두개의 노드 삭제//
		e1 = delete_heap(heap);
		e2 = delete_heap(heap);
		//두개의 노드를 합친다!//
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d + %d-> %d\n", e1.key, e2.key, e.key);
		insert_heap(heap, e);
	}
	e = delete_heap(heap);
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);



}


int main() {
	char ch_list[] = { 's','i','n','t','e' };
	int freq[] = { 4,6,8,12,15 };
	huffman_tree(freq, ch_list, 5);
	return 0;

}
```
