#include <stdio.h>
//#include <math.h>

void main(void)
{
	unsigned int shuki, hogaku, shinko, teishi;	//入力値である周期、進行方向、進行、停止の変数
	unsigned int nanboku, tozai, offset;		//計算結果となる南北、東西、オフセットの変数

	while(1)
	{
		//進行方向を取得する
		printf("進行方向（1:南北 / 0:東西 / 9:プログラム終了）：");
		scanf("%d", &hogaku);
		if(!(hogaku == 0 || hogaku == 1 || hogaku == 9))	//指定以外の数値はエラーと表示
		{
			printf("進行方向数値エラー！終了します\n");
			break;
		}
		else if(hogaku == 9)					//9入力でプログラム終了
		{
			printf("プログラムを終了します\n");
			break;
		}

		//信号周期を取得する
		printf("信号周期：");
		scanf("%d", &shuki);

		//進行タイミングを取得する
		printf("進行タイミング：");
		scanf("%d", &shinko);

		//停止タイミングを取得する
		printf("停止タイミング");
		scanf("%d", &teishi);

		if(hogaku ==  1)
		{
			//南北方向進行の場合
			nanboku = (teishi - shinko) % shuki;		//南北の値を求める
			tozai = (shuki - (teishi - shinko)) % shuki;	//東西の値を求める
			offset = (shuki - shinko) % shuki;		//オフセットの値を求める
			printf("計算結果\n");
			printf("南北：%d , 東西：%d , オフセット：%d\n", nanboku, tozai, offset);
		}
		else if(hogaku == 0)
		{
			//東西方向進行の場合
			tozai = (teishi - shinko) % shuki;		//東西の値を求める
			nanboku = (shuki - (teishi - shinko)) % shuki;	//南北の値を求める
			offset = (shuki - teishi) % shuki;		//オフセットの値を求める
			printf("計算結果\n");
			printf("南北：%d , 東西：%d , オフセット：%d\n", nanboku, tozai, offset);
		}
//		else
//		{
//		}
	}
}

