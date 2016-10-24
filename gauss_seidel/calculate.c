/*************/
/* calculate.c */
/*************/

#include <stdio.h>

#include "gauss_seidel.h"
#include "calculate.h"

/* 計算 */
int calculate(int flag_matrix, double a[ROW][COLUMN], double b[ROW], double x[ROW] )
{
	/**
	* 連立方程式をxについて変形した式のとおりに計算する
	* < 例 : 3×3 >
	* x[1] = ( b[1] - a[1][2] * x[2] - a[1][3] * x[3] ) / a[1][1]
	* x[2] = ( b[2] - a[2][1] * x[1] - a[2][3] * x[3] ) / a[2][2]
	* x[3] = ( b[3] - a[3][1] * x[1] - a[3][2] * x[2] ) / a[3][3]
	*/

	/* for文用変数 */
	int i, j, k, m;

	/* 行列Xの一つ前の値を保存 */
	double x_pre[ROW];

	/* 判定用フラグ  */
	int flag_diff = 0;

	/* 行数（列数）に比例した回数 繰り返す */
	for (k = 0; k < (flag_matrix * T) + 1; k++) {

		/* 初期化 */
		flag_diff = 0;

		/* 結果出力 */
		printf(" round : %d ", k);
		for (m = 0; m < flag_matrix; m++) {
			printf(" %12.10f", x[m]);
			/* 一つ前の値代入 */
			x_pre[m] = x[m];
		}
		printf("\n");

		/* 行数回繰り返す */
		for (j = 0; j < flag_matrix; j++) {

			/* 式に出てくるとおり、まずb[j]をいれる */
			x[j] = b[j];

			/* 列数回繰り返す */
			for (i = 0; i < flag_matrix; i++) {

				/* 係数aの列番号が行番号と同じではないときに */
				/* その係数を持った項をx[j]から引く */
				if (i != j) {
					x[j] -= a[j][i] * x[i];
				}
			}//for_i

			 /* 最後に割る（0割りの処理は済んでいる） */
			x[j] /= a[j][j];

			/* 収束しているか一つ前のとの差より判定 */
			if ( !((x[j] - x_pre[j]) < 0.00000000001 && (x[j] - x_pre[j]) > -0.00000000001)) {
				flag_diff = 1;
			}

		}//for_j

		if (flag_diff == 0) {
			return 1;    /* 収束したから終了 */
		}

	}//for_k

	return 0;
}
