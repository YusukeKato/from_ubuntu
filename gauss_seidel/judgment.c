/*************/
/* judgment.c */
/*************/

#include <stdio.h>
#include <math.h>

#include "gauss_seidel.h"
#include "judgment.h"

/* 収束判定 */
void judgment_condition(int flag_matrix, double a[ROW][COLUMN])
{
	/* 十分条件を満たしているか判定 */

	/* for文用変数 */
	int i, j;

	/* 判定フラグ */
	int flag_judgment;

	/* j == i のときの値を格納 */
	double val[ROW];

	/* 合計 */
	double sum[ROW];

	/* 行数回繰り返す */
	for (j = 0; j < flag_matrix; j++) {
		/* 初期化 */
		val[j] = 0;
		sum[j] = 0;
		/* 列数回繰り返す */
		for (i = 0; i < flag_matrix; i++) {

			/* j==iの値とそれ以外の値の合計の比較 */
			if (j == i) {
				val[j] = fabs(a[j][i]);
			}
			else {
				sum[j] += fabs(a[j][i]);
			}
		}
	}

	/* 十分条件 */
	printf("\n <判定>\n");
	/* 初期値代入 */
	flag_judgment = 0;
	for (j = 0; j < flag_matrix; j++) {
		if (val[j] <= sum[j]) {    /* 条件を満たさない */
			flag_judgment = 1;    /* フラグを立てる */
			printf(" %d ", j+1);    /* 条件を満たしていない行 */
		}
	}
	if (flag_judgment == 0) {    /* フラグが一回も立たなかった */
		printf(" ・条件より収束する\n");
	}
	else if (flag_judgment == 1) {    /* フラグが一度でも立った */
		printf(" 行目が狭義対角優位ではない\n"
			   " ・よって条件は満たしていない\n");
	}
}
