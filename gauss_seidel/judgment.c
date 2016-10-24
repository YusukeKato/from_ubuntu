/*************/
/* judgment.c */
/*************/

#include <stdio.h>
#include <math.h>

#include "gauss_seidel.h"
#include "judgment.h"

/* �������� */
void judgment_condition(int flag_matrix, double a[ROW][COLUMN])
{
	/* �\�������𖞂����Ă��邩���� */

	/* for���p�ϐ� */
	int i, j;

	/* ����t���O */
	int flag_judgment;

	/* j == i �̂Ƃ��̒l���i�[ */
	double val[ROW];

	/* ���v */
	double sum[ROW];

	/* �s����J��Ԃ� */
	for (j = 0; j < flag_matrix; j++) {
		/* ������ */
		val[j] = 0;
		sum[j] = 0;
		/* �񐔉�J��Ԃ� */
		for (i = 0; i < flag_matrix; i++) {

			/* j==i�̒l�Ƃ���ȊO�̒l�̍��v�̔�r */
			if (j == i) {
				val[j] = fabs(a[j][i]);
			}
			else {
				sum[j] += fabs(a[j][i]);
			}
		}
	}

	/* �\������ */
	printf("\n <����>\n");
	/* �����l��� */
	flag_judgment = 0;
	for (j = 0; j < flag_matrix; j++) {
		if (val[j] <= sum[j]) {    /* �����𖞂����Ȃ� */
			flag_judgment = 1;    /* �t���O�𗧂Ă� */
			printf(" %d ", j+1);    /* �����𖞂����Ă��Ȃ��s */
		}
	}
	if (flag_judgment == 0) {    /* �t���O�����������Ȃ����� */
		printf(" �E��������������\n");
	}
	else if (flag_judgment == 1) {    /* �t���O����x�ł������� */
		printf(" �s�ڂ����`�Ίp�D�ʂł͂Ȃ�\n"
			   " �E����ď����͖������Ă��Ȃ�\n");
	}
}
