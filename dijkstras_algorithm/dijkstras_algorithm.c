/**
 * 9.19.2016
 * 9.22.2016
 * �_�C�N�X�g���@
 * �ŒZ�o�H�T��
 * Yusuke Kato
 */
 
 /*
  * �����Ȃ�ɍl�����̂��̂ŁA�œK�ł͂Ȃ�
  * �֐��������ق����������ǁA�Z�����獡�̂Ƃ���͂ق��Ƃ�
  */

#include <stdio.h>

#define NODE 8	 //�m�[�h�� �s��̑傫����ς���Ȃ炱�����ς���
#define MAX 10000//�����̑���

int main(void) {
	/* �ݒ肱������ */
	//�m�[�h�̍\����
	struct Node {
		int flag;//�t���O
		int cost;//���̃m�[�h�ł̍Œ�R�X�g
		int next[NODE];//���̃m�[�h
		int edges_cost[NODE];//���̃m�[�h�ւ̃R�X�g
		int before;//�O�̃m�[�h
	};
	struct Node node[NODE];//�m�[�h�����쐬
	//�אڍs��A�d�݂Â�
	int cost_array[NODE][NODE] = {
		/*  A  B  C  D  E  F  G  H */
		  {-1, 2,-1,-1,-1,-1,-1,-1},//A = 0
		  {-1,-1, 1, 2,-1,-1,-1,-1},//B = 1
		  {-1,-1,-1,-1, 3,-1,-1,-1},//C = 2
		  {-1,-1,-1,-1, 1,-1,-1,-1},//D = 3
		  {-1,-1,-1,-1,-1, 2,-1,-1},//E = 4
		  {-1,-1,-1,-1,-1,-1,-1,-1},//F = 5
		  {-1,-1,-1,-1,-1,-1,-1,-1},//G = 6
		  {-1,-1,-1,-1,-1,-1,-1,-1} //H = 7
	};
	int i, j;//for���񂵗p�ϐ�
	int n;//�z��ԍ��p
	int point = -1;//���[�v����
	int flag2 = 0;//�z��p
	int flag3 = 0;//�I���t���O
	int flag4 = 0;//��O�I���t���O�A�S��-1�������ꍇ
	int flag5 = 0;//�s�񂪉��s�ڂ܂ł��邩
	//�ݒ�l���
	//2��for���͈ꏏ�ɂ͂ł��Ȃ�
	for(i = 0; i < NODE; i++){
		node[i].flag = 0;//�m�肵����t���O�𗧂Ă�
		node[i].cost = MAX;//�Œ�R�X�g�����
		for(j = 0; j < NODE; j++){
			node[i].next[j] = -1;//������
		}
	}
	for(i = 0; i < NODE; i++){
		flag2 = 0;//������
		for(j = 0; j < NODE; j++){
			if(cost_array[i][j] != -1){//cost_array�ɒl�������
				node[i].next[flag2] = j;//���̃m�[�h�ԍ����擾
				node[i].edges_cost[flag2] = cost_array[i][j];//���̃m�[�h�ւ̃R�X�g
				flag2++;//�z��ԍ��Ǘ�
			}
		}
	}
	node[0].before = 0;//�ꉞ
	node[0].cost = 0;//�X�^�[�g�m�[�h�̓R�X�g0
	/* �ݒ肱���܂� */
	/* �{���������� */
	n = 0;//������
	point = 0;//���[�v����
	for(;point != 2;){//���[�v�傱������
		for(i = 0; i < NODE && point != 3; i++) {//�t���O�����Ă���m�[�h�̊m�F
			if(node[i].flag == 1) {//�m�[�h�̃t���O�������Ă��邩
				n = i;//n����
				point = 3;//���̃��[�v�I��
			}
		}
		flag2 = 0;//������
		flag4 = 0;//������
		point = 0;//���[�v����
		for(;point != 1;){//���[�v����������A��̃m�[�h�̑���������s��
			if(node[n].next[flag2] != -1){//-1�Ȃ�Ƃ΂�
				//���݂̃m�[�h�ɐݒ肳��Ă���R�X�g���A���擾�����R�X�g���Ⴂ�Ȃ�A�V�����o�^����
				if(node[node[n].next[flag2]].cost > node[n].edges_cost[flag2] + node[n].cost){
					node[node[n].next[flag2]].cost = node[n].edges_cost[flag2] + node[n].cost;//���
					node[node[n].next[flag2]].flag = 1;//���̃m�[�h�̃t���O�𗧂Ă�
					node[node[n].next[flag2]].before = n;//�O�̃m�[�h�ۑ�
					flag4 = 1;//�������邩�ǂ����̃t���O
				}
				flag2++;//�z��̔ԍ��Ǘ�
			} else {
				point = 1;//���[�v���I������
			}
		flag5 = n;//���݂̍s��
		//c = getchar();
		}//���[�v�������܂�
		if(node[NODE - 1].flag == 1){//�S�[���܂ł̃��[�g���m�肵����I��
			flag3 = 1;//������
			for(i = 0; i < NODE - 1; i++) {
				if(node[i].flag == 1) {//�S�[���ȊO�̃m�[�h�Ƀt���O�������Ă�����I���ł��Ȃ�
					flag3 = 0;//�I������
				}
			}
		}
		if(flag3 == 1 || flag4 == 0) {
			point = 2;//���[�v��I������
		}
		node[n].flag = 0;//��x���̃m�[�h�ő������肵����t���O���~�낷
	}//���[�v�傱���܂�
	/* �{�������܂� */
	/* �o�͂������� */
	printf("\n ���[�g: ");//���[�g�\��
	printf(" %d ", flag5);//�S�[���̃m�[�h
	for(i = flag5; i != 0;) {//i = flag5�S�[�����炽�ǂ��Ă���
		printf(" %d ", node[i].before);
		i = node[i].before;//���̃m�[�h�̑O�̃m�[�h�����Ԃɂ��ǂ�
	}
	printf("\n");//�����ڂ̂��߂̉��s
	for(i = 0; i < NODE; i++) {//�e�m�[�h�̍Œ�R�X�g�\��
		printf(" node[%d].cost : %d\n", i, node[i].cost);
	}
	printf("\n total cost : %d\n", node[flag5].cost);//�Œ�R�X�g�l�o��
	/* �o�͂����܂� */
	return 0;//�Ȃ�ƂȂ��Ԃ�
}