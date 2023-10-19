#include "main.h"

void print_help();

int basic_calculator(void)
{
	double result = 0.0;
	double num;
	char operator;
	char buffer[BUFFER_SIZE];
	int flag = 0;//数字が入力されたら0、演算子が入力されたら1

	printf("＜四則演算モード＞\n");
	printf("こちらのモードでは、基本的な四則演算が可能です。\n");
	printf("初期値は%gに設定されています\n", result);
	printf("四則演算モードを終了する場合は、'q'または'Q'を入力してください\n");
	printf("ヘルプを表示したい方は、'h'または'H'を入力してください\n");
	printf("演算子もしくは数値を入力してください\n");

	while (1)
	{
		printf("%g\n", result);
		//読み込み時にエラー発生
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("読み取りエラーが発生しました\n");
			return -1;
		}
		//終了判定
		if (strcmp(buffer, "q\n") == 0 || strcmp(buffer, "Q\n") == 0)
		{
			printf("四則演算モードを終了します\n");
			return 0;
		}
		//ヘルプの表示
		if (strcmp(buffer, "h\n") == 0 || strcmp(buffer, "H\n") == 0)
		{
			print_help();
			continue;
		}
		//ACキー
		if (strcmp(buffer, "AC\n") == 0)
		{
			result = 0.0;
			continue;
		}
		//flagによる条件分岐
		if (flag == 0)
		{

		}
	}
	return 0;
}

void print_help()
{
	printf("helpが呼び出されました");
}
