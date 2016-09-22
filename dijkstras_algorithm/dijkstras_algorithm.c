/**
 * 9.19.2016
 * 9.22.2016
 * ダイクストラ法
 * 最短経路探索
 * Yusuke Kato
 */
 
 /*
  * 自分なりに考えたのもので、最適ではない
  * 関数分けたほうがいいけど、短いから今のところはほっとく
  */

#include <stdio.h>

#define NODE 8	 //ノード数 行列の大きさを変えるならここも変える
#define MAX 10000//無限の代わり

int main(void) {
	/* 設定ここから */
	//ノードの構造体
	struct Node {
		int flag;//フラグ
		int cost;//そのノードでの最低コスト
		int next[NODE];//次のノード
		int edges_cost[NODE];//そのノードへのコスト
		int before;//前のノード
	};
	struct Node node[NODE];//ノード数分作成
	//隣接行列、重みづけ
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
	int i, j;//for文回し用変数
	int n;//配列番号用
	int point = -1;//ループ条件
	int flag2 = 0;//配列用
	int flag3 = 0;//終了フラグ
	int flag4 = 0;//例外終了フラグ、全部-1だった場合
	int flag5 = 0;//行列が何行目まであるか
	//設定値代入
	//2つのfor文は一緒にはできない
	for(i = 0; i < NODE; i++){
		node[i].flag = 0;//確定したらフラグを立てる
		node[i].cost = MAX;//最低コスト入れる
		for(j = 0; j < NODE; j++){
			node[i].next[j] = -1;//初期化
		}
	}
	for(i = 0; i < NODE; i++){
		flag2 = 0;//初期化
		for(j = 0; j < NODE; j++){
			if(cost_array[i][j] != -1){//cost_arrayに値があれば
				node[i].next[flag2] = j;//次のノード番号を取得
				node[i].edges_cost[flag2] = cost_array[i][j];//そのノードへのコスト
				flag2++;//配列番号管理
			}
		}
	}
	node[0].before = 0;//一応
	node[0].cost = 0;//スタートノードはコスト0
	/* 設定ここまで */
	/* 本文ここから */
	n = 0;//初期化
	point = 0;//ループ条件
	for(;point != 2;){//ループ大ここから
		for(i = 0; i < NODE && point != 3; i++) {//フラグ立っているノードの確認
			if(node[i].flag == 1) {//ノードのフラグが立っているか
				n = i;//n決定
				point = 3;//このループ終了
			}
		}
		flag2 = 0;//初期化
		flag4 = 0;//初期化
		point = 0;//ループ条件
		for(;point != 1;){//ループ小ここから、一つのノードの総当たりを行う
			if(node[n].next[flag2] != -1){//-1ならとばす
				//現在のノードに設定されているコストより、今取得したコストが低いなら、新しく登録する
				if(node[node[n].next[flag2]].cost > node[n].edges_cost[flag2] + node[n].cost){
					node[node[n].next[flag2]].cost = node[n].edges_cost[flag2] + node[n].cost;//代入
					node[node[n].next[flag2]].flag = 1;//次のノードのフラグを立てる
					node[node[n].next[flag2]].before = n;//前のノード保存
					flag4 = 1;//次があるかどうかのフラグ
				}
				flag2++;//配列の番号管理
			} else {
				point = 1;//ループ小終了条件
			}
		flag5 = n;//現在の行数
		//c = getchar();
		}//ループ小ここまで
		if(node[NODE - 1].flag == 1){//ゴールまでのルートが確定したら終了
			flag3 = 1;//初期化
			for(i = 0; i < NODE - 1; i++) {
				if(node[i].flag == 1) {//ゴール以外のノードにフラグが立っていたら終了できない
					flag3 = 0;//終了条件
				}
			}
		}
		if(flag3 == 1 || flag4 == 0) {
			point = 2;//ループ大終了条件
		}
		node[n].flag = 0;//一度そのノードで総当たりしたらフラグを降ろす
	}//ループ大ここまで
	/* 本文ここまで */
	/* 出力ここから */
	printf("\n ルート: ");//ルート表示
	printf(" %d ", flag5);//ゴールのノード
	for(i = flag5; i != 0;) {//i = flag5ゴールからたどっていく
		printf(" %d ", node[i].before);
		i = node[i].before;//そのノードの前のノードを順番にたどる
	}
	printf("\n");//見た目のための改行
	for(i = 0; i < NODE; i++) {//各ノードの最低コスト表示
		printf(" node[%d].cost : %d\n", i, node[i].cost);
	}
	printf("\n total cost : %d\n", node[flag5].cost);//最低コスト値出力
	/* 出力ここまで */
	return 0;//なんとなく返す
}