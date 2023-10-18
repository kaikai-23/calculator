#include <stdio.h>

void print_menu(void);

int main(int argc, char *argv[])
{
	int	choice = -1;//初期化
	if (argc == 1)
	{
		while (1)
		{
			print_menu();

			// ユーザーの選択の取得
			if (scanf("%d", &choice) != 1)
			{
				printf("無効な入力です。もう一度やり直してください\n");
				printf("\n");
				while (getchar() != '\n'); // バッファクリア（データが残ってしまわないようにクリアする）
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
			default:
				printf("無効な選択です。もう一度お試しください\n");
				printf("\n");
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
