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
// argv[1] : 입력 텍스트 파일
// argv[2] : encoded 파일
int main( int argc, char **argv)
{
	FILE *infp, *outfp;
	int ch_freq[256] = {0,}; // 문자별 빈도
	char *codes[256]; // 문자별 허프만 코드 (ragged 배열)
	tNode *huffman_tree; // 허프만 트리
	
	if (argc != 3)
	{
		fprintf( stderr, "%s input-file encoded-file\n", argv[0]);
		return 1;
	}

	////////////////////////////////////////
	// 입력 텍스트 파일
	infp = fopen( argv[1], "rt");
	if (infp == NULL)
	{
		fprintf( stderr, "Error: cannot open file [%s]\n", argv[1]);
		return 1;
	}

	// 텍스트 파일로부터 문자별 빈도 저장
	int num_bytes = read_chars( infp, ch_freq);

	fclose( infp);

	// 문자별 빈도 출력 (only for debugging)
	//print_char_freq( ch_freq);
	
	// 허프만 트리 생성
	huffman_tree = make_huffman_tree( ch_freq);
	
	// 허프만 코드 생성
	make_huffman_code( huffman_tree, codes);

	// 허프만 코드 출력 (stdout)
	print_huffman_code( codes);
	
	////////////////////////////////////////
	// 입력: 텍스트 파일
	infp = fopen( argv[1], "rt");
	
	// 출력: 바이너리 코드
	outfp = fopen( argv[2], "wb");

	// 허프만코드를 이용하여 입력 파일을 인코딩(압축)
	int encoded_bytes = encoding( codes, ch_freq, infp, outfp);

	
	//fclose( infp);
	fclose( outfp);

	// 허프만 코드 메모리 해제
	free_huffman_code( codes);

	// 허프만 트리 메모리 해제
	destroyTree( huffman_tree);
	
	////////////////////////////////////////
	printf( "# of bytes of the original text = %d\n", num_bytes);
	printf( "# of bytes of the compressed text = %d\n", encoded_bytes);
	printf( "compression ratio = %.2f\n", ((float)num_bytes - encoded_bytes) / num_bytes * 100);
	
	return 0;
}
