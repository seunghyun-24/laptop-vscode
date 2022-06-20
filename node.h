#ifndef NODE_H
#define NODE_H

typedef struct Node 
{ 
	unsigned char	data;	// 문자	
	int				freq; 	// 빈도
	struct Node 	*left;	// 왼쪽 서브트리 포인터
	struct Node 	*right; // 오른쪽 서브트리 포인터
} tNode;

#endif
