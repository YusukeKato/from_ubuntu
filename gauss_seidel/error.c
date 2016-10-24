/*********/
/* error.c */
/*********/

#include <stdio.h>

#include "gauss_seidel.h"
#include "error.h"

/* エラー処理 */
int error(int flag_matrix, double a[ROW][COLUMN])
{
	int i, j;

	/* このプログラムは対角成分に0があるとエラー */
	for (j = 0, i = 0; j < flag_matrix; j++, i++) {
		if (a[j][i] == 0) {
			printf("\n このプログラムは対角成分に0があるとエラー\n");
			return -1;    /* エラーにより終了 */
		}
	}

	return 0;    /* 正常 */
}
