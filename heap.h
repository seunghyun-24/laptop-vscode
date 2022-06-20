#ifndef HEAP_H
#define HEAP_H

#include "node.h"

////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int	last;		// 힙에 저장된 마지막 element의 index (0부터 저장됨)
	int	capacity;	// heapArr의 크기
	tNode **heapArr;
} HEAP;

// 힙 생성
// 배열을 위한 메모리 할당 (capacity)
// last = -1
HEAP *heapCreate( int capacity); 

// 힙에 원소 삽입
int heapInsert( HEAP *heap, tNode *data);

// 최소값 제거
tNode *heapDelete( HEAP *heap);

// 힙 메모리 해제
void heapDestroy( HEAP *heap);

#endif
