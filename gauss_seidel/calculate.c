/*************/
/* calculate.c */
/*************/

#include <stdio.h>

#include "gauss_seidel.h"
#include "calculate.h"

/* �v�Z */
int calculate(int flag_matrix, double a[ROW][COLUMN], double b[ROW], double x[ROW] )
{
	/**
	* �A����������x�ɂ��ĕό`�������̂Ƃ���Ɍv�Z����
	* < �� : 3�~3 >
	* x[1] = ( b[1] - a[1][2] * x[2] - a[1][3] * x[3] ) / a[1][1]
	* x[2] = ( b[2] - a[2][1] * x[1] - a[2][3] * x[3] ) / a[2][2]
	* x[3] = ( b[3] - a[3][1] * x[1] - a[3][2] * x[2] ) / a[3][3]
	*/

	/* for���p�ϐ� */
	int i, j, k, m;

	/* �s��X�̈�O�̒l��ۑ� */
	double x_pre[ROW];

	/* ����p�t���O  */
	int flag_diff = 0;

	/* �s���i�񐔁j�ɔ�Ⴕ���� �J��Ԃ� */
	for (k = 0; k < (flag_matrix * T) + 1; k++) {

		/* ������ */
		flag_diff = 0;

		/* ���ʏo�� */
		printf(" round : %d ", k);
		for (m = 0; m < flag_matrix; m++) {
			printf(" %12.10f", x[m]);
			/* ��O�̒l��� */
			x_pre[m] = x[m];
		}
		printf("\n");

		/* �s����J��Ԃ� */
		for (j = 0; j < flag_matrix; j++) {

			/* ���ɏo�Ă���Ƃ���A�܂�b[j]������� */
			x[j] = b[j];

			/* �񐔉�J��Ԃ� */
			for (i = 0; i < flag_matrix; i++) {

				/* �W��a�̗�ԍ����s�ԍ��Ɠ����ł͂Ȃ��Ƃ��� */
				/* ���̌W��������������x[j]������� */
				if (i != j) {
					x[j] -= a[j][i] * x[i];
				}
			}//for_i

			 /* �Ō�Ɋ���i0����̏����͍ς�ł���j */
			x[j] /= a[j][j];

			/* �������Ă��邩��O�̂Ƃ̍���蔻�� */
			if ( !((x[j] - x_pre[j]) < 0.00000000001 && (x[j] - x_pre[j]) > -0.00000000001)) {
				flag_diff = 1;
			}

		}//for_j

		if (flag_diff == 0) {
			return 1;    /* ������������I�� */
		}

	}//for_k

	return 0;
}
