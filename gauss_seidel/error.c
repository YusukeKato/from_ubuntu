/*********/
/* error.c */
/*********/

#include <stdio.h>

#include "gauss_seidel.h"
#include "error.h"

/* �G���[���� */
int error(int flag_matrix, double a[ROW][COLUMN])
{
	int i, j;

	/* ���̃v���O�����͑Ίp������0������ƃG���[ */
	for (j = 0, i = 0; j < flag_matrix; j++, i++) {
		if (a[j][i] == 0) {
			printf("\n ���̃v���O�����͑Ίp������0������ƃG���[\n");
			return -1;    /* �G���[�ɂ��I�� */
		}
	}

	return 0;    /* ���� */
}
