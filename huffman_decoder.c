#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"

////////////////////////////////////////////////////////////////////////////////
// 문자별 빈도 출력 (for debugging)
void print_char_freq( int ch_freq[])
{
	int i;

	for (i = 0; i < 256; i++)
	{
		printf( "%d\t%d\n", i, ch_freq[i]); // 문자인덱스, 빈도
	}
}

////////////////////////////////////////////////////////////////////////////////
// argv[1] : encoded 파일
// argv[2] : decoded 파일
int main( int argc, char **argv)
{
	FILE *infp, *outfp;
	int ch_freq[256] = {0,}; // 문자별 빈도
	tNode *huffman_tree; // 허프만 트리
	/*
	if (argc != 3)
	{
		fprintf( stderr, "%s encoded-file decoded-file\n", argv[0]);
		return 1;
	}

	// 입력 파일 (바이너리)
	infp = fopen( argv[1], "rb");

	// 256개의 정수
	get_char_freq( infp, ch_freq);

	// 문자별 빈도 출력 (only for debugging)
	//print_char_freq( ch_freq);
	
	// 허프만 트리 생성
	huffman_tree = make_huffman_tree( ch_freq);
	
	// 출력: 텍스트 파일
	outfp = fopen( argv[2], "wt");

	// 허프만 트리를 이용하여 디코딩
	decoding( huffman_tree, infp, outfp);

	// 허프만 트리 메모리 해제
	destroyTree( huffman_tree);

	fclose( infp);
	fclose( outfp);
	*/
	return 0;
}

