#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

void print_menu(void);
void clear_buffer(void);

int main(int argc, char *argv[])
{
	int	choice = -1;//初期化
	char buffer[BUFFER_SIZE];

	if (argc == 1)
	{
		while (1)
		{
			print_menu();

			//読み取り失敗のエラーハンドリング
			if ((fgets(buffer, sizeof(buffer), stdin)) == NULL)
			{
				printf("読み取りエラーが発生しました\n");
				return 1;
			}
			//fgetsでは\0を最後に入れるため99文字までしかbuffeeには取得されない。
			//buffer[98]は少なくとも\nになることが期待される
			size_t len = strlen(buffer);
			if ((BUFFER_SIZE == len + 1) && (buffer[len - 1] != '\n'))
			{
				printf("入力文字数が上限を超えています。もう一度やり直してください\n");
				printf("\n");
				clear_buffer();
				continue;
			}
			// ユーザーの選択の取得
			if (sscanf(buffer, "%d", &choice) != 1)
			{
				printf("無効な入力です。もう一度やり直してください\n");
				printf("\n");
				// clear_buffer();
				continue; // スキップしてループに戻る(メニューに戻る)
			}
			switch (choice)
			{
			case 1:
				//四則演算パートへ
				printf("%c\n", 'A');
				break;
			case 2:
				//他の機能
				break;
			case 0:
				//終了
				printf("プログラムは終了しました\n");
				return 0;
				break;
			default:
				printf("無効な選択です。もう一度お試しください\n");
				printf("\n");
				break;
			}
		}
	}
	return 0;
}

//メニューを表示する関数
void print_menu(void)
{
	printf("＜電卓メニュー＞\n");
	printf("1. 四則演算\n");
	printf("0. 終了\n");
	printf("選択してください (0 - 1): ");
}

// void clear_buffer(void)
// {
//     while (getchar() != '\n');
// }
void clear_buffer(void) {
    int c;
	c = getchar();//cのASCIIを取得
	while (c != '\n' && c != EOF)//改行かstdinの最終を表すEOF(End Of File)に到達してるかチェック
	{
		c = getchar();
	}
}
