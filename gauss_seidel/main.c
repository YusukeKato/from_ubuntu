/*********/
/* main.c */
/*********/

#include <stdio.h>

#include "gauss_seidel.h"
#include "error.h"
#include "calculate.h"
#include "judgment.h"

/* メイン関数 */
int main(void)
{
	/********** 入力 ここから **********/

	/* 行列のサイズの指定 [（例）2×2なら 2 を入力] */
	int flag_matrix = 10;

	/* 行列A 最大10×10 可変 */
	double a[ROW][COLUMN] = {
		1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		1.0, 2.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 3.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 4.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 1.0, 5.0, 1.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 1.0, 6.0, 1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 7.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 8.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 9.0, 1.0,
		0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 10.0
	};

	/* 行列B 最大10×1 可変 */
	double b[ROW] = {
		19.0, 36.0, 40.0, 42.0, 42.0, 40.0, 36.0, 30.0, 22.0, 12.0
	};

	/* 行列X 初期値入力 最大10×1 可変 */
	double x[ROW] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
	};

	/********** 入力 ここまで **********/

	/* 収束フラグ */
	int flag_judg = 0;

	/* エラーが起きたとき用のフラグ */
	int flag_main = 0;

	/* エラー処理 */
	flag_main = error(flag_matrix, a);

	if (flag_main == 0) {

		/* 計算 */
		flag_judg = calculate(flag_matrix, a, b, x);

		/* 判定（条件より） */
		judgment_condition(flag_matrix, a);

		/* 判定（結果より） */
		if (flag_judg == 1) {
			printf(" ・結果より収束する\n");
		}
	}

	return 0;
}
