//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"
#include "stdlib.h"
//########## マクロ定義 ##########
#define GAME_WIDTH			928	//画面の横の大きさ
#define GAME_HEIGHT			800	//画面の縦の大きさ
#define GAME_COLOR			32	//画面のカラービット

#define GAME_WINDOW_BAR		0					//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME	"Two for One"		//ウィンドウのタイトル

//#define FONT_PATH_MAX      255//255文字まで
//
//#define FONT_PIX_PATH     TEXT(".\\FONT\\PixelMplus10-Bold.ttf")
//#define FONT_PIX_NAME     TEXT("PixelMplus10")
//
//#define FONT_INSTALL_ERR_TITLE    TEXT("フォントインストールエラー")
//#define FONT_CREATE_ERR_TITLE     TEXT("フォント作成エラー")

//キーボードの種類
#define KEY_CODE_KIND		256	//256種類

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")
#define IMAGE_LOAD_ERR_END	    TEXT("画像読み込みエラー")

//画像のパス
#define IMAGE_player_A_PATH		    TEXT(".\\IMAGE\\player_A.png")	    //プレイヤーAの画像
#define IMAGE_player_B_PATH		    TEXT(".\\IMAGE\\player_B.png")	    //プレイヤーBの画像
#define IMAGE_enemy_1_PATH		    TEXT(".\\IMAGE\\enemy1.png")	    //敵１の画像
#define IMAGE_enemy_2_PATH		    TEXT(".\\IMAGE\\enemy2.png")	    //敵２の画像
#define IMAGE_enemy_3_PATH		    TEXT(".\\IMAGE\\enemy3.png")	    //敵3の画像
#define IMAGE_TITLE_BK_PATH			TEXT(".\\IMAGE\\titleBK.png")		//タイトル背景の画像
#define IMAGE_TITLE_ROGO_PATH		TEXT(".\\IMAGE\\title_rogo.png")	//タイトルロゴの画像
#define IMAGE_TITLE_START_PATH		TEXT(".\\IMAGE\\title_button.png")	//タイトルスタートの画像
#define IMAGE_END_DEATH_PATH        TEXT(".\\IMAGE\\end_death.png")

//マップの情報
#define GAME_FLOOR_MAX      2   //フロアの数
#define GAME_MAP_TATE_MAX	25	//マップの縦の数
#define GAME_MAP_YOKO_MAX	29	//マップの横の数
#define GAME_MAP_KIND_MAX	1	//マップの種類の数
#define GAME_MAP_PATH			TEXT(".\\IMAGE\\MAP\\mapchip.png")		//マップの画像
#define MAP_DIV_WIDTH		32	//画像を分割する幅サイズ
#define MAP_DIV_HEIGHT		32	//画像を分割する高さサイズ
#define MAP_DIV_TATE		18	//画像を縦に分割する数
#define MAP_DIV_YOKO		2	//画像を横に分割する数
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//画像を分割する総数

//エラーメッセージ
#define START_ERR_TITLE		    TEXT("スタート位置エラー")
#define START_ERR_CAPTION_A	    TEXT("Aのスタート位置が決まっていません")
#define START_ERR_CAPTION_B     TEXT("Bのスタート位置が決まっていません")
#define START_ERR_CAPTION_E1	TEXT("敵1のスタート位置が決まっていません")
#define START_ERR_CAPTION_E2	TEXT("敵2のスタート位置が決まっていません")
#define START_ERR_CAPTION_E3	TEXT("敵3のスタート位置が決まっていません")
#define START_ERR_CAPTION_W1_1  TEXT("ステージ1のワープ1の位置が決まっていません")
#define START_ERR_CAPTION_W2_1  TEXT("ステージ1のワープ2の位置が決まっていません")
#define START_ERR_CAPTION_W1_2  TEXT("ステージ2のワープ1の位置が決まっていません")
#define START_ERR_CAPTION_W2_2  TEXT("ステージ2のワープ2の位置が決まっていません")
#define START_ERR_CAPTION_W1_3  TEXT("ステージ3のワープ1の位置が決まっていません")
#define START_ERR_CAPTION_W2_3  TEXT("ステージ3のワープ2の位置が決まっていません")


#define GOAL_ERR_TITLE      TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION_A  TEXT("Aのゴール位置が決まっていません")
#define GOAL_ERR_CAPTION_B  TEXT("Bのゴール位置が決まっていません")

//ロゴ画像動作用
#define IMAGE_TITLE_ROGO_ROTA		0.1		    //拡大率
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0			//拡大率MAX
#define IMAGE_TITLE_ROGO_X_SPEED	3			//X移動速度
#define IMAGE_TITLE_START_CNT		1			//点滅カウンタ
#define IMAGE_TITLE_START_CNT_MAX	40			//点滅カウンタMAX

//エンドコンプ画面用
#define IMAGE_END_COMP_PATH        TEXT(".\\IMAGE\\mission_complete.png") //エンドコンプロゴ画像
#define IMAGE_TITLE_END_PATH		TEXT(".\\IMAGE\\end_button.png")	//エンドボタンの画像
#define IMAGE_END_COMP_CNT         1       //点滅カウンタ
#define IMAGE_END_COMP_CNT_MAX     70      //点滅カウンタMAX(点滅の速さ)

//キャラ画像動作用
#define IMAGE_DIV_WIDTH    32
#define IMAGE_DIV_HEIGHT   32

#define IMAGE_DIV_TATE     2
#define IMAGE_DIV_YOKO     4

#define IMAGE_DIV_NUM      IMAGE_DIV_TATE * IMAGE_DIV_YOKO

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE	   TEXT("音楽読み込みエラー")

//BGMパス指定
#define MUSIC_BGM_PATH              TEXT(".\\MUSIC\\play_BGM.mp3")                  //プレイ画面のBGM
#define MUSIC_BGM_TITLE_PATH		TEXT(".\\MUSIC\\title_BGM.mp3")	                //タイトルのBGM
#define MUSIC_BGM_COMP_PATH			TEXT(".\\MUSIC\\end_BGM.mp3")				    //コンプリートBGM
#define MUSIC_BGM_FAIL_PATH			TEXT(".\\MUSIC\\GameOver.mp3")					//フォールトBGM
#define MUSIC_SE_ATACK_PATH         TEXT(".\\MUSIC\\Atack.mp3")                     //攻撃音
#define MUSIC_SE_SWITCH_PATH        TEXT(".\\MUSIC\\SwitchOn.mp3")                  //スイッチ音
#define MUSIC_SE_KEY_PATH           TEXT(".\\MUSIC\\KeyGet.mp3")                    //鍵入手音
#define MUSIC_SE_WEAPON_PATH        TEXT(".\\MUSIC\\WeaponGet.mp3")                 //武器入手音

//フォントのパスの長さ
#define FONT_PATH_MAX			255	//255文字まで

//フォント
#define FONT_Pixel_PATH			TEXT(".\\FONT\\PixelMplus12-Bold.ttf")	//フォントの場所
#define FONT_Pixel_NAME			TEXT("PixelMplus12")			//フォントの名前

//エラーメッセージ
#define FONT_INSTALL_ERR_TITLE	TEXT("フォントインストールエラー")
#define FONT_CREATE_ERR_TITLE	TEXT("フォント作成エラー")

//BGM音量
#define MUSIC_VOLUME             50   //BGMの音量（0~100）
//閉じるボタンを押したとき
#define MSG_CLOSE_TITLE			TEXT("終了メッセージ")
#define MSG_CLOSE_CAPTION		TEXT("ゲームを終了しますか？")

//デバッグモードのオンオフ（ON:オン　OFF:オフ）
#define DEBUG   TEXT("OFF")

//当たり判定の対象の識別
#define TRUE_t     0
#define TRUE_k     1
#define TRUE_s1    6
#define TRUE_m1    7
#define TRUE_s2    8
#define TRUE_m2    9
#define TRUE_ag    3
#define TRUE_bg    5
#define TRUE_s3    10
#define TRUE_m3    11
#define TRUE_s4    12
#define TRUE_m4    13
#define TRUE_ki    14
#define TRUE_kl    15
#define TRUE_br    16
#define TRUE_sp    17
#define TRUE_ca    18
#define TRUE_st    19
#define TRUE_w1    20
#define TRUE_w2    21
#define TRUE_e1    22
#define TRUE_e2    23
#define TRUE_e3    24
#define TRUE_k1    25
#define TRUE_k2    26
#define TRUE_k3    27

//スイッチが押されたかどうかの識別（1:押された　0:押されてない）
int s1_check = 0;  //スイッチ1用
int s2_check = 0;  //スイッチ2用
int s3_check = 0;  //スイッチ3用
int s4_check = 0;  //スイッチ4用

//鍵をとっているかどうかの識別（1:取っている　0:取っていない）
int ki_check = 0;

//武器をとっているかどうかの識別（1:取っている　0:取っていない）
int br_check = 0;
int sp_check = 0;
int ca_check = 0;

//今どのステージにいるかの識別（3:ステージ3  2:ステージ2  1:ステージ1）
int st_check = 1;

//今どの階層にいるかの識別（1:別階層 0:初期階層）
int fl_check = 0;

//フロアを移動したかどうかの識別（1:移動した 0:移動していない）
int move_floor = 0;

//死んだかどうかの識別（1:生きてる　0:死んでる）
int player_live = 1;
int enemy1_live = 1;
int enemy2_live = 1;
int enemy3_live = 1;

//敵の行動用ランダム数
int enemy_rand = 0;

//フェード用変数
int c = 0;

enum GAME_MAP_KIND
{
	n = -1,	//(NONE)未定
	k = 1,	 //壁
	t = 0,	 //通路
	as = 2,	 //プレイヤーAスタート
    ag = 3,	 //プレイヤーAゴール
	bs = 4,  //プレイヤーBスタート
	bg = 5,  //プレイヤーBゴール
	s1 = 6,  //スイッチ1
	m1 = 7,  //ギミック1
	s2 = 8,  //スイッチ2
	m2 = 9,  //ギミック2
	s3 = 10, //スイッチ3
	m3 = 11, //ギミック3
	s4 = 12, //スイッチ4
	m4 = 13, //ギミック4
	ki = 14, //鍵アイテム
	kl = 15, //鍵扉
	br = 16, //剣
	sp = 17, //槍
	ca = 18, //杖
	st = 23, //階段
	w1 = 24, //ワープ入口１
	w2 = 25, //ワープ入口２
	e1 = 26, //敵１スタート
	e2 = 27, //敵２スタート
	e3 = 28, //敵3スタート
	k1 = 29, //エネミー壁１
	k2 = 30, //エネミー壁２
	k3 = 31  //エネミー壁３
	
};	//マップの種類

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_INIT_PLAY,
	GAME_SCENE_PLAY,
	GAME_INIT_PLAY_SECOND,
	GAME_SCENE_PLAY_SECOND,
	GAME_INIT_PLAY_THIRD,
	GAME_SCENE_PLAY_THIRD,
	GAME_SCENE_OVER,
	GAME_SCENE_END,
};	//ゲームのシーン

//int型のPOINT構造体
typedef struct STRUCT_I_POINT
{
	int x = 0;	//第1座標を初期化
	int y = 0;	//第1座標を初期化
	int x2 = 0; //第2座標を初期化
	int y2 = 0; //第2座標を初期化
	int x3 = 0; //第3座標を初期化
	int y3 = 0; //第3座標を初期化
}iPOINT;

//フォント構造体
typedef struct STRUCT_FONT
{
	char path[FONT_PATH_MAX];	//パス
	char name[FONT_PATH_MAX];	//フォント名
	int handle;					//ハンドル
	int size;					//大きさ
	int bold;					//太さ
	int type;					//タイプ

}FONT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int x;				    //X位置
	int y;					//Y位置
	int width;					//幅
	int height;					//高さ
	BOOL IsDraw = FALSE;		//描画できるか
}IMAGE;	//画像構造体

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE構造体
	RECT coll;
	iPOINT collBeforePt;
	int floor = 0;
	int floor2 = 0;
	int floor3 = 0;

}CHARA;	//プレイヤー、敵の構造体

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//パス
	int handle[MAP_DIV_NUM];			//分割したマップの画像ハンドルを取得
	int kind[MAP_DIV_NUM];				//マップの種類
	int width;							//幅
	int height;							//高さ
}MAPCHIP;	//MAP_IMAGE構造体

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//マップの種類
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
}MAP;	//MAP構造体

typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE構造体
	double angle;		//回転率
	double angleMAX;	//回転率MAX
	double rate;		//拡大率
	double rateMAX;		//拡大率MAX
}IMAGE_ROTA;	//回転拡大する画像の構造体

typedef struct STRUCT_IMAGE_BLINK
{
	IMAGE image;		//IMAGE構造体
	int Cnt;			//点滅カウンタ
	int CntMAX;			//点滅する時間MAX
	BOOL IsDraw;		//描画できるか？
}IMAGE_BLINK;  //点滅する画像の構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
}MUSIC;//音楽構造体

//ゲーム関連
int GameScene;		//ゲームシーンを管理

IMAGE       ImageTitleBK;               //タイトル背景の画像
IMAGE_ROTA  ImageTitleROGO;             //タイトルロゴの画像
IMAGE_BLINK ImageTitleSTART;            //タイトルスタートの画像

IMAGE       ImageEndDeath;             //ゲームオーバー画面の画像

IMAGE_BLINK ImageEndCOMP;              //エンドコンプの画像
IMAGE_BLINK ImageTitleEND;             //エンドボタンの画像

//フォント関連
FONT FontPixel32;	//たぬき油性マジック：大きさ32　のフォント構造体

//音楽関連
MUSIC BGM;  //ゲームのBGM
MUSIC BGM_TITLE;	//タイトルのBGM
MUSIC BGM_COMP;		//コンプリートのBGM
MUSIC BGM_FAIL;		//フォールトのBGM
MUSIC SE_ATACK;     //攻撃のSE
MUSIC SE_SWITCH;    //スイッチのSE
MUSIC SE_KEY;       //鍵入手のSE
MUSIC SE_WEAPON;    //武器入手のSE

//画像関連
IMAGE ImageBack;
CHARA player_A;		//プレイヤーA
CHARA player_B;		//プレイヤーB
CHARA enemy_1;
CHARA enemy_2;
CHARA enemy_3;

GAME_MAP_KIND mapDatafirst[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]
{ 
	{
	//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
		k ,st,k ,t ,t ,t ,k ,t ,t ,k ,t ,k ,k ,ag,k ,bg,k ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,st,k , //1
		k ,t ,k ,t ,k ,t ,k ,t ,t ,k ,t ,k ,k ,k2,k ,k3,k ,k ,t ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k , //2
		k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k , //3
		k ,t ,k ,t ,t ,t ,t ,t ,k ,k ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,k ,t ,k ,k , //4
		k ,k ,k ,k ,k ,k ,k ,t ,t ,t ,t ,k ,k ,k ,k ,k ,k ,k ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k , //5
		k ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,k ,t ,t ,k ,t ,t ,k ,k ,k ,k ,t ,t ,t ,k ,t ,k ,t ,k , //6
		k ,t ,t ,t ,t ,t ,t ,t ,m4,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k , //7
		k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k , //8
		k ,t ,t ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k , //9
		k ,e2,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,sp,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,s4,k , //10
		k ,k ,k ,k ,k ,k ,k ,m1,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,m2,k ,k ,k ,k ,k ,k ,k , //11
		k ,e1,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,br,k , //12
		k ,k ,k ,k ,k ,t ,k ,s2,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,k ,s1,k ,t ,k ,k ,k ,k ,k , //13
		k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k , //14
		k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k , //15
		k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,k ,k ,t ,k ,t ,k ,k ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k , //16
		k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,t ,k ,t ,t ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //17
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //18
		k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //19
		k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k , //20
		k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k , //21
		k ,t ,k ,t ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,k ,t ,k , //22
		k ,as,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,bs,k , //23
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	},
	{
	//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
		k ,st,t ,s3,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,st,k , //1
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,ki,k ,t ,t ,t ,t ,t ,t ,k ,k ,k ,t ,k , //2
		k ,w1,k ,t ,t ,t ,t ,t ,t ,t ,k ,ca,k ,t ,k ,t ,k ,k ,t ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k , //3
		k ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,kl,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k , //4
		k ,t ,t ,t ,k ,t ,k ,t ,k ,w2,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //5
		k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //6
		k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,k ,k ,t ,t ,t ,k ,t ,k , //7
		k ,t ,k ,t ,k ,k ,k ,t ,k ,k ,t ,k ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k , //8
		k ,t ,k ,k ,k ,t ,k ,t ,t ,k ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k ,t ,k ,t ,k , //9
		k ,t ,k ,t ,t ,t ,k ,k ,t ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //10
		k ,t ,t ,t ,k ,t ,k ,k ,t ,t ,t ,t ,k ,t ,k ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //11
		k ,t ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,t ,k ,k ,t ,t ,e3,t ,t ,t ,t ,k ,t ,k , //12
		k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,m3,t ,k , //13
		k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k , //14
		k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,k ,t ,t ,k ,k ,t ,t ,k ,k ,k , //15
		k ,t ,t ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,k ,k ,k , //16
		k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k ,k ,k , //17
		k ,t ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k , //18
		k ,t ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,k ,k ,t ,t ,k ,t ,t ,t ,t ,k ,k ,k , //19
		k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,k ,t ,t ,t ,k ,k ,t ,t ,t ,k ,k ,k , //20
		k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,k ,t ,t ,t ,t ,k ,k ,t ,t ,k ,k ,k , //21
		k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k ,k ,k , //22
		k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,k ,k ,k ,k ,k ,k , //23
		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	}
};

//ゲームマップの階層初期化用
GAME_MAP_KIND mapDatafirstInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//ゲームマップの第２ステージ
GAME_MAP_KIND mapDatasecond[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]
{
	{
		//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
			k ,as,t ,t ,t ,t ,t ,k ,t ,s4,k ,t ,k ,t ,t ,t, k ,t ,t ,t ,t ,t ,t ,t ,e3,k ,w1,t ,k , //1
			k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //2
			k ,t ,t ,t ,t ,k ,t ,k ,t ,k ,k ,t ,k ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //3
			k ,t ,k ,k ,t ,k ,t ,k ,t ,k ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //4
			k ,t ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //5
			k ,t ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //6
			k ,t ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,st,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //7
			k ,t ,k ,k ,w2,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,kl,k ,k , //8
			k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k1,k1,k1,k1,k1,k1,k1,k1,k ,k3,k ,k , //9
			k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,k , //10
			k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,ag,k , //11
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //12
			k ,bg,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,k , //13
			k ,k2,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,t ,k , //14
			k ,e2,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,k ,t ,k ,st,t ,t ,k ,t ,t ,k , //15
			k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,t ,k ,k ,k ,k ,k ,t ,t ,k , //16
			k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,k ,k ,t ,m3,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //17
			k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,k ,k ,t ,k ,k ,k ,m4,k ,k ,k ,k ,k ,k ,k ,k ,t ,t ,k , //18
			k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,k ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //19
			k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,t ,k ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,t ,t ,k , //20
			k ,t ,t ,t ,t ,t ,k ,t ,t ,k ,t ,ca,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,k ,t ,t ,k , //21
			k ,k ,k ,m1,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,t ,k , //22
			k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,sp,t ,t ,t ,k ,t ,bs,k , //23
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	},
	{
		//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
			k ,t ,t ,k ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,k ,k ,k ,t ,t ,t ,k ,k ,k ,k , //1
			k ,k ,t ,k ,k ,t ,t ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,t ,t ,t ,t ,k ,k ,k , //2
			k ,k ,t ,t ,k ,k ,t ,k ,k ,t ,k ,t ,t ,t ,k ,t ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,k , //3
			k ,k ,k ,t ,k ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //4
			k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //5
			k ,k ,k ,t ,k ,k ,k ,t ,t ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //6
			k ,t ,t ,t ,t ,t ,k ,k ,k ,k ,k ,t ,k ,br,k ,st,t ,m2,t ,t ,t ,t ,t ,t ,t ,t ,e1,s3,k , //7
			k ,t ,k ,k ,k ,t ,t ,t ,k ,t ,t ,t ,k ,k ,k ,k ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //8
			k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,t ,k ,t ,s1,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //9
			k ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k , //10
			k ,k ,t ,k ,t ,k ,t ,t ,t ,k ,k ,t ,k ,k ,t ,k ,t ,t ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,k , //11
			k ,k ,t ,t ,t ,k ,t ,k ,k ,k ,k ,t ,k ,k ,t ,k ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,k ,k ,k , //12
			k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,k ,k ,k ,k ,t ,t ,t ,k ,k ,k ,k , //13
			k ,k ,k ,k ,k ,k ,m2,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //14
			k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,s2,t ,st,k ,k ,k ,k ,k , //15
			k ,t ,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k , //16
			k ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,k , //17
			k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,k , //18
			k ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k , //19
			k ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,t ,k , //20
			k ,k ,t ,t ,t ,k ,t ,k ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k ,k ,t ,k , //21
			k ,k ,k ,k ,t ,k ,t ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,t ,k , //22
			k ,ki,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k , //23
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	}
};

//ゲームマップの第２ステージ初期化用
GAME_MAP_KIND mapDatasecondInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//ゲームマップの第３ステージ
GAME_MAP_KIND mapDatathird[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]
{
	{
		//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
			k ,sp,t ,t ,t ,t ,k ,ag,k ,t ,t ,k ,t ,e2,k ,t ,k ,t ,t ,t ,k ,bg,k ,t ,t ,t ,t ,e3,k , //1
			k ,k ,k ,k ,k ,t ,k ,k2,k ,t ,k ,t ,t ,k ,k ,t ,t ,t ,k ,t ,k ,k3,k ,t ,k ,t ,k ,t ,k , //2
			k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k ,k ,t ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k , //3
			k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,k ,k ,t ,k ,t ,t ,t ,k ,t ,t ,k ,t ,k ,t ,t ,k , //4
			k ,t ,k ,k ,k ,t ,m3,t ,k ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,t ,k ,k ,t ,k , //5
			k ,t ,k ,t ,t ,t ,k ,t ,t ,k ,t ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k , //6
			k ,t ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,t ,k ,t ,t ,k , //7
			k ,t ,k ,t ,k ,t ,t ,t ,k ,k ,k ,t ,t ,k ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,k ,k ,t ,k , //8
			k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,m4,t ,t ,t ,t ,t ,t ,t ,k , //9
			k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,t ,k , //10
			k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k , //11
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //12
			k ,st,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,t ,st,k , //13
			k ,t ,k ,t ,t ,t ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,k ,k , //14
			k ,t ,k ,t ,k ,k ,k ,t ,t ,s4,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k , //15
			k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,t ,k , //16
			k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,k , //17
			k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k , //18
			k ,k ,k ,k ,k ,t ,t ,t ,t ,k ,t ,t ,t ,t ,k ,t ,t ,t ,k ,t ,k ,t ,t ,t ,t ,t ,k ,t ,k , //19
			k ,t ,t ,t ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,k ,k ,k ,k ,k ,t ,k , //20
			k ,t ,k ,t ,t ,t ,t ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k ,t ,t ,t ,k , //21
			k ,t ,k ,t ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k , //22
			k ,bs,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,t ,s3,k ,t ,k ,t ,t ,t ,k ,t ,t ,as,k , //23
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	},
	{
		//  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7, 8
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //0
			k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,w2,k ,k , //1
			k ,t ,k ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,t ,k ,k ,m2,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k , //2
			k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k , //3
			k ,t ,k ,t ,t ,k ,t ,t ,k ,t ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k , //4
			k ,s1,k ,k ,t ,k ,t ,k ,k ,k ,k ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,t ,t ,k ,k ,t ,k ,t ,k , //5
			k ,k ,k ,k ,t ,k ,t ,t ,k ,t ,t ,t ,k ,k ,t ,t ,t ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,k , //6
			k ,t ,k ,t ,t ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,k , //7
			k ,t ,k ,e1,k ,k ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,k ,k ,t ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k , //8
			k ,t ,t ,t ,t ,t ,k ,t ,k ,t ,k ,t ,k ,t ,k ,t ,t ,t ,t ,k ,k ,t ,t ,k ,t ,t ,t ,k ,k , //9
			k ,t ,k ,t ,k ,k ,k ,t ,k ,t ,t ,t ,k ,t ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,t ,k ,t ,k ,k , //10
			k ,t ,k ,t ,t ,t ,t ,t ,k ,st,k ,k ,k ,t ,t ,t ,t ,k ,k ,st,k ,t ,t ,k ,t ,k ,t ,k ,k , //11
			k ,k ,k ,t ,k ,t ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,t ,k ,t ,k ,k , //12
			k ,t ,t ,t ,k ,k ,k ,k ,t ,t ,k ,k ,br,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,t ,k , //13
			k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k , //14
			k ,t ,k ,t ,k ,k ,t ,t ,k ,k ,k ,t ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,t ,t ,t ,k , //15
			k ,t ,k ,t ,k ,t ,t ,k ,k ,t ,k ,t ,k ,t ,k ,t ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,t ,k , //16
			k ,t ,t ,t ,t ,t ,k ,k ,k ,t ,m1,t ,k ,t ,k ,t ,k ,t ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,k , //17
			k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k , //18
			k ,t ,k ,t ,k ,k ,k ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //19
			k ,t ,k ,k ,k ,t ,t ,t ,t ,t ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,t ,k , //20
			k ,ca,k ,k ,t ,t ,k ,k ,k ,k ,k ,k ,t ,t ,t ,t ,t ,t ,t ,k ,ki,t ,t ,t ,k ,t ,t ,t ,k , //21
			k ,k ,k ,k ,t ,k ,k ,t ,t ,t ,t ,k ,k ,k ,t ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,k , //22
			k ,k ,w1,kl,t ,k ,s2,t ,k ,k ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k , //23
			k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k   //24
	}
};

//ゲームマップの第３ステージ初期化用
GAME_MAP_KIND mapDatathirdInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップチップの画像を管理
MAPCHIP mapChip;

//マップ1の場所と表示する画像を管理
MAP map[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップ2の場所と表示する画像を管理
MAP map2[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップ3の場所と表示する画像を管理
MAP map3[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//スタートの位置(プレイヤーと敵のそれぞれの座標）
iPOINT startPt_A;
iPOINT startPt_B;
iPOINT startEPt_1;
iPOINT startEPt_2;
iPOINT startEPt_3;

//それぞれのワープの位置
iPOINT w1_where;
iPOINT w2_where;

//マップ1の当たり判定
RECT mapColl[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//マップ1の当たり判定初期化用
RECT mapCollInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップ2の当たり判定
RECT mapCollSecond[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//マップ2の当たり判定初期化用
RECT mapCollSecondInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップ3の当たり判定
RECT mapCollThird[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//マップ3の当たり判定初期化用
RECT mapCollThirdInit[GAME_FLOOR_MAX][GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//ゴールしたかの判定
RECT GoalRect_A = { -1,-1,-1,-1 };  //プレイヤーA用
RECT GoalRect_B = { -1,-1,-1,-1 };  //プレイヤーB用

//フォント用
//FONT FontPixel;

//########## プロトタイプ宣言 ##########
VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);	//スタート画面の処理
VOID MY_START_DRAW(VOID);	//スタート画面の描画

VOID MY_PLAY_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY(VOID);			//プレイ画面
VOID MY_PLAY_PROC(VOID);	//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	//プレイ画面の描画

VOID MY_PLAY_SECOND_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY_SECOND(VOID);  //2プレイ画面
VOID MY_PLAY_SECOND_DRAW(VOID);	//2プレイ画面の描画

VOID MY_PLAY_THIRD_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY_THIRD(VOID);  //3プレイ画面
VOID MY_PLAY_THIRD_DRAW(VOID);	//3プレイ画面の描画

VOID MY_OVER(VOID);         //ゲームオーバー画面
VOID MY_OVER_PROC(VOID);    //ゲームオーバー画面の処理
VOID MY_OVER_DRAW(VOID);    //ゲームオーバー画面の描画

VOID MY_END(VOID);			//エンド画面
VOID MY_END_PROC(VOID);		//エンド画面の処理
VOID MY_END_DRAW(VOID);		//エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);		//画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);		//画像をまとめて削除する関数

BOOL MY_LOAD_MUSIC(VOID);		//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);		//音楽をまとめて削除する関数

int MY_CHECK_MAP1_PLAYER_COLL(RECT);   //マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);    //領域の当たり判定をする関数

BOOL MY_FONT_INSTALL_ONCE(VOID);
VOID MY_FONT_UNINSTALL_ONCE(VOID);
BOOL MY_FONT_CREATE(VOID);
VOID MY_FONT_DELETE(VOID);

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	SetOutApplicationLogValidFlag(FALSE);				//Log.txtを出力しない
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);				//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	SetWindowUserCloseEnableFlag(FALSE);				//閉じるボタンで、勝手にウィンドウが閉じないようにする

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//フォントを一時的にインストール
	if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }

	//フォントハンドルを作成
	if (MY_FONT_CREATE() == FALSE) { return -1; }

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から
	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//プレイヤーAの第１スタート位置を探す
				if (mapDatafirst[0][tate][yoko] == as)
				{
					//プレイヤーAのスタート位置を計算
					startPt_A.y = mapChip.height * tate;	//Y座標を取得
					startPt_A.x = mapChip.width * yoko;	//X座標を取得

				}

				//プレイヤーAの第２スタート位置を探す
				if (mapDatasecond[0][tate][yoko] == as)
				{
					//プレイヤーAのスタート位置を計算
					startPt_A.y2 = mapChip.height * tate;	//Y座標を取得
					startPt_A.x2 = mapChip.width * yoko;	//X座標を取得

				}

				//プレイヤーAの第３スタート位置を探す
				if (mapDatathird[0][tate][yoko] == as)
				{
					//プレイヤーAのスタート位置を計算
					startPt_A.y3 = mapChip.height * tate;	//Y座標を取得
					startPt_A.x3 = mapChip.width * yoko;	//X座標を取得
				}


				//プレイヤーBの第１スタート位置を探す
				if (mapDatafirst[0][tate][yoko] == bs)
				{
					//プレイヤーBのスタート位置を計算
					startPt_B.x = mapChip.width * yoko;	//X座標を取得
					startPt_B.y = mapChip.height * tate;	//Y座標を取得
				}

				//プレイヤーBの第２スタート位置を探す
				if (mapDatasecond[0][tate][yoko] == bs)
				{
					//プレイヤーBのスタート位置を計算
					startPt_B.x2 = mapChip.width * yoko;	//X座標を取得
					startPt_B.y2 = mapChip.height * tate;	//Y座標を取得
				}

				//プレイヤーBの第３スタート位置を探す
				if (mapDatathird[0][tate][yoko] == bs)
				{
					//プレイヤーBのスタート位置を計算
					startPt_B.x3 = mapChip.width * yoko;	//X座標を取得
					startPt_B.y3 = mapChip.height * tate;	//Y座標を取得
				}

				//敵１の第１スタート位置を探す
				if (mapDatafirst[floor][tate][yoko] == e1)
				{
					//敵１のスタート位置を計算
					startEPt_1.x = mapChip.width * yoko;	//X座標を取得
					startEPt_1.y = mapChip.height * tate;	//Y座標を取得
					enemy_1.floor = floor;
				}

				//敵１の第２スタート位置を探す
				if (mapDatasecond[floor][tate][yoko] == e1)
				{
					//敵１のスタート位置を探す
					startEPt_1.x2 = mapChip.width * yoko;	//X座標を取得
					startEPt_1.y2 = mapChip.height * tate;	//Y座標を取得
					enemy_1.floor2 = floor;
				}

				//敵１の第３スタート位置を探す
				if (mapDatathird[floor][tate][yoko] == e1)
				{
					//敵１のスタート位置を探す
					startEPt_1.x3 = mapChip.width * yoko;	//X座標を取得
					startEPt_1.y3 = mapChip.height * tate;	//Y座標を取得
					enemy_1.floor3 = floor;
				}

				//敵2の第１スタート位置を探す
				if (mapDatafirst[floor][tate][yoko] == e2)
				{
					//敵2のスタート位置を計算
					startEPt_2.x = mapChip.width * yoko;	//X座標を取得
					startEPt_2.y = mapChip.height * tate;	//Y座標を取得
					enemy_2.floor = floor;
				}

				//敵2の第２スタート位置を探す
				if (mapDatasecond[floor][tate][yoko] == e2)
				{
					//敵2のスタート位置を計算
					startEPt_2.x2 = mapChip.width * yoko;	//X座標を取得
					startEPt_2.y2 = mapChip.height * tate;	//Y座標を取得
					enemy_2.floor2 = floor;
				}

				//敵2の第3スタート位置を探す
				if (mapDatathird[floor][tate][yoko] == e2)
				{
					//敵2のスタート位置を計算
					startEPt_2.x3 = mapChip.width * yoko;	//X座標を取得
					startEPt_2.y3 = mapChip.height * tate;	//Y座標を取得
					enemy_2.floor3 = floor;
				}

				//敵3の第１スタート位置を探す
				if (mapDatafirst[floor][tate][yoko] == e3)
				{
					//敵3のスタート位置を計算
					startEPt_3.x = mapChip.width * yoko;	//X座標を取得
					startEPt_3.y = mapChip.height * tate;	//Y座標を取得
					enemy_3.floor = floor;
					enemy_3.floor = floor;
				}

				//敵3の第２スタート位置を探す
				if (mapDatasecond[floor][tate][yoko] == e3)
				{
					//敵3のスタート位置を計算
					startEPt_3.x2 = mapChip.width * yoko;	//X座標を取得
					startEPt_3.y2 = mapChip.height * tate;	//Y座標を取得
					enemy_3.floor2 = floor;
				}

				//敵3の第３スタート位置を探す
				if (mapDatasecond[floor][tate][yoko] == e3)
				{
					//敵3のスタート位置を計算
					startEPt_3.x3 = mapChip.width * yoko;	//X座標を取得
					startEPt_3.y3 = mapChip.height * tate;	//Y座標を取得
					enemy_3.floor3 = floor;
				}

				//プレイヤーAのゴール位置を探す
				if (mapDatafirst[0][tate][yoko] == ag)
				{
					GoalRect_A.left = mapChip.width * yoko;
					GoalRect_A.top = mapChip.height * tate;
					GoalRect_A.right = mapChip.width * (yoko + 1);
					GoalRect_A.bottom = mapChip.height * (tate + 1);
				}

				//プレイヤーBのゴール位置を探す
				if (mapDatafirst[0][tate][yoko] == bg)
				{
					GoalRect_B.left = mapChip.width * yoko;
					GoalRect_B.top = mapChip.height * tate;
					GoalRect_B.right = mapChip.width * (yoko + 1);
					GoalRect_B.bottom = mapChip.height * (tate + 1);
				}

				//ステージ１のワープ１の位置を探す
				if (mapDatafirst[floor][tate][yoko] == w1)
				{
					//ワープ１の位置を計算
					w1_where.y = mapChip.height * tate;	//Y座標を取得
					w1_where.x = mapChip.width * yoko;	//X座標を取得
				}

				//ステージ２のワープ１の位置を探す
				if (mapDatasecond[floor][tate][yoko] == w1)
				{
					//ワープ１の位置を計算
					w1_where.y2 = mapChip.height * tate; //Y座標を取得
					w1_where.x2 = mapChip.width * yoko;	 //X座標を取得
				}

				//ステージ３のワープ１の位置を探す
				if (mapDatathird[floor][tate][yoko] == w1)
				{
					//ワープ１の位置を計算
					w1_where.y3 = mapChip.height * tate; //Y座標を取得
					w1_where.x3 = mapChip.width * yoko;	 //X座標を取得
				}

				//ステージ１のワープ２の位置を探す
				if (mapDatafirst[floor][tate][yoko] == w2)
				{
					//ワープ２の位置を計算
					w2_where.y = mapChip.height * tate;	//Y座標を取得
					w2_where.x = mapChip.width * yoko;	//X座標を取得
				}

				//ステージ２ワープ２の位置を探す
				if (mapDatasecond[floor][tate][yoko] == w2)
				{
					//ワープ２の位置を計算
					w2_where.y2 = mapChip.height * tate; //Y座標を取得
					w2_where.x2 = mapChip.width * yoko;	 //X座標を取得
				}

				//ステージ３ワープ２の位置を探す
				if (mapDatathird[floor][tate][yoko] == w2)
				{
					//ワープ２の位置を計算
					w2_where.y3 = mapChip.height * tate; //Y座標を取得
					w2_where.x3 = mapChip.width * yoko;	 //X座標を取得
				}
			}

			//スタートやワープ位置が決まっていれば、ループ終了
			if (startPt_A.x != 0 && startPt_A.y != 0 &&        //プレイヤーAのステージ1のスタート位置
				startPt_A.x2 != 0 && startPt_A.y2 != 0 &&      //プレイヤーAのステージ2のスタート位置
				startPt_A.x3 != 0 && startPt_A.y3 != 0 &&      //プレイヤーAのステージ3のスタート位置

				startPt_B.x != 0 && startPt_B.y != 0 &&       //プレイヤーBのステージ1のスタート位置
				startPt_B.x2 != 0 && startPt_B.y2 != 0 &&     //プレイヤーBのステージ2のスタート位置
				startPt_B.x3 != 0 && startPt_B.y3 != 0 &&     //プレイヤーBのステージ3のスタート位置

				startEPt_1.x != 0 && startEPt_1.y != 0 &&     //敵1のステージ1のスタート位置
				startEPt_1.x2 != 0 && startEPt_1.y2 != 0 &&   //敵1のステージ2のスタート位置
				startEPt_1.x3 != 0 && startEPt_1.y3 != 0 &&   //敵1のステージ3のスタート位置

				startEPt_2.x != 0 && startEPt_2.y != 0 &&     //敵2のステージ1のスタート位置
				startEPt_2.x2 != 0 && startEPt_2.y2 != 0 &&   //敵2のステージ2のスタート位置
				startEPt_2.x3 != 0 && startEPt_2.y3 != 0 &&   //敵2のステージ3のスタート位置

				startEPt_3.x != 0 && startEPt_3.y != 0 &&     //敵3のステージ1のスタート位置
				startEPt_3.x2 != 0 && startEPt_3.y2 != 0 &&   //敵3のステージ2のスタート位置
				startEPt_3.x3 != 0 && startEPt_3.y3 != 0 &&   //敵3のステージ3のスタート位置
				
				w1_where.x != 0 && w1_where.y != 0 &&         //ワープ1のステージ1の位置
				w1_where.x2 != 0 && w1_where.y2 != 0 &&       //ワープ1のステージ2の位置
				w1_where.x3 != 0 && w1_where.y3 != 0 &&       //ワープ1のステージ3の位置
				
				w2_where.x != 0 && w2_where.y != 0 &&         //ワープ2のステージ1の位置
				w2_where.x2 != 0 && w2_where.y2 != 0 &&       //ワープ2のステージ2の位置
				w2_where.x3 != 0 && w2_where.y3 != 0)         //ワープ2のステージ3の位置
			{
				break;
			}
		}
	}

	//Aのスタートが決まっていなければ
	if (startPt_A.x == 0 || startPt_A.y == 0 || startPt_A.x2 == 0 || startPt_A.y2 == 0 || startPt_A.x3 == 0 || startPt_A.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_A, START_ERR_TITLE, MB_OK);	return -1;
	}
	//Bのスタートが決まっていなければ
	if (startPt_B.x == 0 || startPt_B.y == 0 || startPt_B.x2 == 0 || startPt_B.y2 == 0 || startPt_B.x3 == 0 || startPt_B.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_B, START_ERR_TITLE, MB_OK);	return -1;
	}

	//敵１のスタートが決まっていなければ
	if (startEPt_1.x == 0 || startEPt_1.y == 0 || startEPt_1.x2 == 0 || startEPt_1.y2 == 0 || startEPt_1.x3 == 0 || startEPt_1.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E1, START_ERR_TITLE, MB_OK);	return -1;
	}

	//敵2のスタートが決まっていなければ
	if (startEPt_2.x == 0 || startEPt_2.y == 0 || startEPt_2.x2 == 0 || startEPt_2.y2 == 0 || startEPt_2.x3 == 0 || startEPt_2.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E2, START_ERR_TITLE, MB_OK);	return -1;
	}

	//敵3のスタートが決まっていなければ
	if (startEPt_3.x == 0 || startEPt_3.y == 0 || startEPt_3.x2 == 0 || startEPt_3.y2 == 0 || startEPt_3.x3 == 0 || startEPt_3.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_E3, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ１のワープ1の位置が決まっていなければ
	if (w1_where.x == 0 || w1_where.y == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W1_1, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ２のワープ1の位置が決まっていなければ
	if (w1_where.x2 == 0 || w1_where.y2 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W1_2, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ３のワープ1の位置が決まっていなければ
	if (w1_where.x3 == 0 || w1_where.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W1_3, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ１のワープ2の位置が決まっていなければ
	if (w2_where.x == 0 || w2_where.y == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W2_1, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ２のワープ2の位置が決まっていなければ
	if (w2_where.x2 == 0 || w2_where.y2 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W2_2, START_ERR_TITLE, MB_OK);	return -1;
	}

	//ステージ３のワープ2の位置が決まっていなければ
	if (w2_where.x3 == 0 || w2_where.y3 == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_W2_3, START_ERR_TITLE, MB_OK);	return -1;
	}

	//Aのゴールが決まっていなければ
	if (GoalRect_A.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_A, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//Bのゴールが決まっていなければ
	if (GoalRect_B.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_B, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//プレイヤーAの画像座標を第１初期位置に設定
	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;

	//プレイヤーAの画像座標を第１初期位置に設定
	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;

	//敵１の画像座標を第１初期位置に設定
	enemy_1.image.x = startEPt_1.x;
	enemy_1.image.y = startEPt_1.y;

	//敵2の画像座標を第１初期位置に設定
	enemy_2.image.x = startEPt_2.x;
	enemy_2.image.y = startEPt_2.y;

	//敵3の画像座標を第１初期位置に設定
	enemy_3.image.x = startEPt_3.x;
	enemy_3.image.y = startEPt_3.y;

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		//画面の閉じるボタンを押されたとき
		if (GetWindowUserCloseFlag(TRUE))
		{
			//終了ダイアログを表示
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YESなら、ゲームを中断する
		}

		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;

		case GAME_INIT_PLAY:
			MY_PLAY_INIT();  //1プレイ画面の初期化
			GameScene = GAME_SCENE_PLAY;
			break;

		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;

		case GAME_INIT_PLAY_SECOND:
			MY_PLAY_SECOND_INIT();  //2プレイ画面の初期化
			GameScene = GAME_SCENE_PLAY_SECOND;
			break;

		case GAME_SCENE_PLAY_SECOND:
			MY_PLAY_SECOND();	//2プレイ画面
			break;

		case GAME_INIT_PLAY_THIRD:  //3プレイ画面の初期化
			MY_PLAY_THIRD_INIT();
			GameScene = GAME_SCENE_PLAY_THIRD;
			break;

		case GAME_SCENE_PLAY_THIRD:
			MY_PLAY_THIRD();	//2プレイ画面
			break;

		case GAME_SCENE_OVER:
			MY_OVER(); //ゲームオーバー画面
			break;

		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		}
		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画
	}

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	//フォントハンドルを破棄
	MY_FONT_DELETE();

	//一時的にインストールしたフォントをアンインストール
	MY_FONT_UNINSTALL_ONCE();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画

	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_TITLE.handle);	//MUSIC_VOLUMEで音量調節
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//エンターキーを押したら、プレイシーンへ移動する
	if (CheckHitKey(KEY_INPUT_RETURN) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_TITLE.handle) != 0)
		{
			StopSoundMem(BGM_TITLE.handle);	//BGMを止める
		}

		//プレイ画面を初期化する
		GameScene = GAME_INIT_PLAY;

		return;  //強制的にプレイ画面へ
	}

	//タイトルロゴを拡大
	if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	{
		ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	}

	//タイトルロゴを移動
	if (ImageTitleROGO.image.x < GAME_WIDTH / 2)
	{
		ImageTitleROGO.image.x += IMAGE_TITLE_ROGO_X_SPEED;
	}
	else
	{
		//タイトルロゴが移動しきったら

		//スタートを点滅
		if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
		{
			ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;
		}
		else
		{
			//描画する/しないを決める
			if (ImageTitleSTART.IsDraw == FALSE)
			{
				ImageTitleSTART.IsDraw = TRUE;
			}
			else if (ImageTitleSTART.IsDraw == TRUE)
			{
				ImageTitleSTART.IsDraw = FALSE;
			}
			ImageTitleSTART.Cnt = 0;
		}
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//タイトルロゴを拡大しながら描画
	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,	//画像の座標
		ImageTitleROGO.rate,							//画像の拡大率
		ImageTitleROGO.angle,							//画像の回転率
		ImageTitleROGO.image.handle, TRUE);				//画像のハンドル

	//点滅
	if (ImageTitleSTART.IsDraw == TRUE)
	{
		//タイトルスタートの描画
		DrawGraph(ImageTitleSTART.image.x, ImageTitleSTART.image.y, ImageTitleSTART.image.handle, TRUE);
	}

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		//DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(255, 255, 255));
		//フォントハンドルで文字を描画
		DrawStringToHandle((GAME_WIDTH/2) - 64, 0, "Hello World", GetColor(255, 255, 255), FontPixel32.handle);
	}

	return;
}

//プレイ画面初期化
VOID MY_PLAY_INIT(VOID)
{
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//マップを初期化
				map[floor][tate][yoko].kind = mapDatafirstInit[floor][tate][yoko];

				//マップの当たり判定の初期化
				mapColl[floor][tate][yoko].left = mapCollInit[floor][tate][yoko].left;
				mapColl[floor][tate][yoko].top = mapCollInit[floor][tate][yoko].top;
				mapColl[floor][tate][yoko].right = mapCollInit[floor][tate][yoko].right;
				mapColl[floor][tate][yoko].bottom = mapCollInit[floor][tate][yoko].bottom;
			}
		}
	}

	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;
	player_A.collBeforePt.x = startPt_A.x;
	player_A.collBeforePt.y = startPt_A.y;

	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;
	player_B.collBeforePt.x = startPt_B.x;
	player_B.collBeforePt.y = startPt_B.y;

	enemy_1.image.x = startEPt_1.x;
	enemy_1.image.y = startEPt_1.y;
	enemy_1.collBeforePt.x = startEPt_1.x;
	enemy_1.collBeforePt.y = startEPt_1.y;

	enemy_2.image.x = startEPt_2.x;
	enemy_2.image.y = startEPt_2.y;
	enemy_2.collBeforePt.x = startEPt_2.x;
	enemy_2.collBeforePt.y = startEPt_2.y;

	enemy_3.image.x = startEPt_3.x;
	enemy_3.image.y = startEPt_3.y;
	enemy_3.collBeforePt.x = startEPt_3.x;
	enemy_3.collBeforePt.y = startEPt_3.y;

	s1_check = 0;
	s2_check = 0;
	s3_check = 0;
	s4_check = 0;

	ki_check = 0;
	br_check = 0;
	sp_check = 0;
	ca_check = 0;

	st_check = 1;
	fl_check = 0;
	move_floor = 0;

	player_live = 1;
	enemy1_live = 1;
	enemy2_live = 1;
	enemy3_live = 1;

	return;
}

//2プレイ画面の初期化
VOID MY_PLAY_SECOND_INIT(VOID)
{
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//マップを初期化
				map2[floor][tate][yoko].kind = mapDatasecondInit[floor][tate][yoko];

				//マップの当たり判定の初期化
				mapCollSecond[floor][tate][yoko].left = mapCollSecondInit[floor][tate][yoko].left;
				mapCollSecond[floor][tate][yoko].top = mapCollSecondInit[floor][tate][yoko].top;
				mapCollSecond[floor][tate][yoko].right = mapCollSecondInit[floor][tate][yoko].right;
				mapCollSecond[floor][tate][yoko].bottom = mapCollSecondInit[floor][tate][yoko].bottom;
			}
		}
	}

	player_A.image.x = startPt_A.x2;
	player_A.image.y = startPt_A.y2;
	player_A.collBeforePt.x = startPt_A.x2;
	player_A.collBeforePt.y = startPt_A.y2;

	player_B.image.x = startPt_B.x2;
	player_B.image.y = startPt_B.y2;
	player_B.collBeforePt.x = startPt_B.x2;
	player_B.collBeforePt.y = startPt_B.y2;

	enemy_1.image.x = startEPt_1.x2;
	enemy_1.image.y = startEPt_1.y2;
	enemy_1.collBeforePt.x = startEPt_1.x2;
	enemy_1.collBeforePt.y = startEPt_1.y2;

	enemy_2.image.x = startEPt_2.x2;
	enemy_2.image.y = startEPt_2.y2;
	enemy_2.collBeforePt.x = startEPt_2.x2;
	enemy_2.collBeforePt.y = startEPt_2.y2;

	enemy_3.image.x = startEPt_3.x2;
	enemy_3.image.y = startEPt_3.y2;
	enemy_3.collBeforePt.x = startEPt_3.x2;
	enemy_3.collBeforePt.y = startEPt_3.y2;

	s1_check = 0;
	s2_check = 0;
	s3_check = 0;
	s4_check = 0;

	ki_check = 0;
	br_check = 0;
	sp_check = 0;
	ca_check = 0;

	st_check = 2;
	fl_check = 0;
	move_floor = 0;

	enemy1_live = 1;
	enemy2_live = 1;
	enemy3_live = 1;

	return;
}

//3プレイ画面の初期化
VOID MY_PLAY_THIRD_INIT(VOID)
{
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//マップを初期化
				map3[floor][tate][yoko].kind = mapDatathirdInit[floor][tate][yoko];

				//マップの当たり判定の初期化
				mapCollThird[floor][tate][yoko].left = mapCollThirdInit[floor][tate][yoko].left;
				mapCollThird[floor][tate][yoko].top = mapCollThirdInit[floor][tate][yoko].top;
				mapCollThird[floor][tate][yoko].right = mapCollThirdInit[floor][tate][yoko].right;
				mapCollThird[floor][tate][yoko].bottom = mapCollThirdInit[floor][tate][yoko].bottom;
			}
		}
	}

	player_A.image.x = startPt_A.x3;
	player_A.image.y = startPt_A.y3;
	player_A.collBeforePt.x = startPt_A.x3;
	player_A.collBeforePt.y = startPt_A.y3;

	player_B.image.x = startPt_B.x3;
	player_B.image.y = startPt_B.y3;
	player_B.collBeforePt.x = startPt_B.x3;
	player_B.collBeforePt.y = startPt_B.y3;

	enemy_1.image.x = startEPt_1.x3;
	enemy_1.image.y = startEPt_1.y3;
	enemy_1.collBeforePt.x = startEPt_1.x3;
	enemy_1.collBeforePt.y = startEPt_1.y3;

	enemy_2.image.x = startEPt_2.x3;
	enemy_2.image.y = startEPt_2.y3;
	enemy_2.collBeforePt.x = startEPt_2.x3;
	enemy_2.collBeforePt.y = startEPt_2.y3;

	enemy_3.image.x = startEPt_3.x3;
	enemy_3.image.y = startEPt_3.y3;
	enemy_3.collBeforePt.x = startEPt_3.x3;
	enemy_3.collBeforePt.y = startEPt_3.y3;

	s1_check = 0;
	s2_check = 0;
	s3_check = 0;
	s4_check = 0;

	ki_check = 0;
	br_check = 0;
	sp_check = 0;
	ca_check = 0;

	st_check = 3;
	fl_check = 0;
	move_floor = 0;

	enemy1_live = 1;
	enemy2_live = 1;
	enemy3_live = 1;

	return;
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画

	return;
}

//2プレイ画面
VOID MY_PLAY_SECOND(VOID)
{
	MY_PLAY_PROC();	//2プレイ画面の処理
	MY_PLAY_SECOND_DRAW();	//プレイ画面の描画

	return;
}

//3プレイ画面
VOID MY_PLAY_THIRD(VOID)
{
	MY_PLAY_PROC();	//3プレイ画面の処理
	MY_PLAY_THIRD_DRAW();	//プレイ画面の描画

	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	//スペースキーを押したら、エンドシーンへ移動する
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGMを止める
		}

		GameScene = GAME_SCENE_END;

		return;	//強制的にエンド画面に飛ぶ
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM.handle);	//MUSIC_VOLUMEで音量調節

		//BGMを流す
		//DX_PLAYTYPE_NORMAL:　ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}

	//プレイヤーAを操作する
	if (CheckHitKey(KEY_INPUT_W)) { player_A.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_S)) { player_A.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_A)) { player_A.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_D)) { player_A.image.x += MAP_DIV_WIDTH; }

	//プレイヤーBを操作する
	if (CheckHitKey(KEY_INPUT_UP)) { player_B.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_DOWN)) { player_B.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_LEFT)) { player_B.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_RIGHT)) { player_B.image.x += MAP_DIV_WIDTH; }

	enemy_rand = rand() % 4 + 1;
	if ((enemy_1.floor == fl_check && st_check == 1) || (enemy_1.floor2 == fl_check && st_check == 2) || (enemy_1.floor3 == fl_check && st_check == 3))
	{
		//敵１のランダム動作設定
		if (enemy_rand == 1) { enemy_1.image.y -= MAP_DIV_HEIGHT; }
		if (enemy_rand == 2) { enemy_1.image.y += MAP_DIV_HEIGHT; }
		if (enemy_rand == 3) { enemy_1.image.x -= MAP_DIV_WIDTH; }
		if (enemy_rand == 4) { enemy_1.image.x += MAP_DIV_WIDTH; }
	}

	if ((enemy_2.floor == fl_check && st_check == 1) || (enemy_2.floor2 == fl_check && st_check == 2) || (enemy_2.floor3 == fl_check && st_check == 3))
	{
		//敵2のランダム動作設定
		if (enemy_rand == 1) { enemy_2.image.y -= MAP_DIV_HEIGHT; }
		if (enemy_rand == 4) { enemy_2.image.y += MAP_DIV_HEIGHT; }
		if (enemy_rand == 2) { enemy_2.image.x -= MAP_DIV_WIDTH; }
		if (enemy_rand == 3) { enemy_2.image.x += MAP_DIV_WIDTH; }
	}

	if ((enemy_3.floor == fl_check && st_check == 1) || (enemy_3.floor2 == fl_check && st_check == 2) || (enemy_3.floor3 == fl_check && st_check == 3))
	{
		//敵3のランダム動作設定
		if (enemy_rand == 4) { enemy_3.image.y -= MAP_DIV_HEIGHT; }
		if (enemy_rand == 3) { enemy_3.image.y += MAP_DIV_HEIGHT; }
		if (enemy_rand == 1) { enemy_3.image.x -= MAP_DIV_WIDTH; }
		if (enemy_rand == 2) { enemy_3.image.x += MAP_DIV_WIDTH; }
	}


	//-----------------------当たり判定関係ここから------------------------
	//プレイヤーAの当たり判定の設定
	player_A.coll.left = player_A.image.x;
	player_A.coll.top = player_A.image.y;
	player_A.coll.right = player_A.image.x + mapChip.width;
	player_A.coll.bottom = player_A.image.y + mapChip.height;

	//プレイヤーBの当たり判定の設定
	player_B.coll.left = player_B.image.x;
	player_B.coll.top = player_B.image.y;
	player_B.coll.right = player_B.image.x + mapChip.width;
	player_B.coll.bottom = player_B.image.y + mapChip.height;

	//敵１の当たり判定の設定
	enemy_1.coll.left = enemy_1.image.x;
	enemy_1.coll.top = enemy_1.image.y;
	enemy_1.coll.right = enemy_1.image.x + mapChip.width;
	enemy_1.coll.bottom = enemy_1.image.y + mapChip.height;

	//敵2の当たり判定の設定
	enemy_2.coll.left = enemy_2.image.x;
	enemy_2.coll.top = enemy_2.image.y;
	enemy_2.coll.right = enemy_2.image.x + mapChip.width;
	enemy_2.coll.bottom = enemy_2.image.y + mapChip.height;

	//敵3の当たり判定の設定
	enemy_3.coll.left = enemy_3.image.x;
	enemy_3.coll.top = enemy_3.image.y;
	enemy_3.coll.right = enemy_3.image.x + mapChip.width;
	enemy_3.coll.bottom = enemy_3.image.y + mapChip.height;

	BOOL IsMove_A = TRUE;
	BOOL IsMove_B = TRUE;
	BOOL IsMove_E1 = TRUE;
	BOOL IsMove_E2 = TRUE;
	BOOL IsMove_E3 = TRUE;

	//▼▼▼▼▼▼▼▼プレイヤーA当たり判定ここから▼▼▼▼▼▼▼▼▼▼▼▼
	//プレイヤーAと壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m4)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとエネミー壁１が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとエネミー壁２が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとエネミー壁３が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAがスイッチ1に当たっていたら
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s1)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//スイッチ音が流れていないなら
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s1_check == 0)
						{
							//スイッチ音の音量を下げる
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}

						if (st_check == 1)
						{
							//ギミック1を通路にして消す
							if (map[floor][tate][yoko].kind == m1)
							{
								map[floor][tate][yoko].kind = t;
								s1_check = 1;
							}
						}
						else if (st_check == 2)
						{
							//ギミック1を通路にして消す
							if (map2[floor][tate][yoko].kind == m1)
							{
								map2[floor][tate][yoko].kind = t;
								s1_check = 1;
							}
						}
						else if (st_check == 3)
						{
							//ギミック1を通路にして消す
							if (map3[floor][tate][yoko].kind == m1)
							{
								map3[floor][tate][yoko].kind = t;
								s1_check = 1;
							}
						}
					}
				}
			}
		}

	//プレイヤーAがスイッチ2に当たっていたら
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s2)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//スイッチ音が流れていないなら
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s2_check == 0)
						{
							//スイッチ音の音量を下げる
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}

						if (st_check == 1)
						{
							//ギミック2を通路にして消す
							if (map[floor][tate][yoko].kind == m2)
							{
								map[floor][tate][yoko].kind = t;
								s2_check = 1;

							}
						}
						else if (st_check == 2)
						{
							//ギミック2を通路にして消す
							if (map2[floor][tate][yoko].kind == m2)
							{
								map2[floor][tate][yoko].kind = t;
								s2_check = 1;
							}
						}
						else if (st_check == 3)
						{
							//ギミック2を通路にして消す
							if (map3[floor][tate][yoko].kind == m2)
							{
								map3[floor][tate][yoko].kind = t;
								s2_check = 1;
							}
						}
					}
				}
			}
		}

	//プレイヤーAがスイッチ3に当たっていたら
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s3)
		{
			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						//スイッチ音が流れていないなら
						if (CheckSoundMem(SE_SWITCH.handle) == 0 && s3_check == 0)
						{
							//スイッチ音の音量を下げる
							ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
							PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
						}
						if (st_check == 1)
						{
							//ギミック2を通路にして消す
							if (map[floor][tate][yoko].kind == m3)
							{
								map[floor][tate][yoko].kind = t;
								s3_check = 1;

							}
						}
						else if (st_check == 2)
						{
							//ギミック2を通路にして消す
							if (map2[floor][tate][yoko].kind == m3)
							{
								map2[floor][tate][yoko].kind = t;
								s3_check = 1;
							}
						}
						else if (st_check == 3)
						{
							//ギミック2を通路にして消す
							if (map3[floor][tate][yoko].kind == m3)
							{
								map3[floor][tate][yoko].kind = t;
								s3_check = 1;
							}
						}
					}
				}
			}
		}

	//プレイヤーAがスイッチ4に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s4)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//スイッチ音が流れていないなら
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s4_check == 0)
					{
						//スイッチ音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//ギミック2を通路にして消す
						if (map[floor][tate][yoko].kind == m4)
						{
							map[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}
					else if (st_check == 2)
					{
						//ギミック2を通路にして消す
						if (map2[floor][tate][yoko].kind == m4)
						{
							map2[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}
					else if (st_check == 3)
					{
						//ギミック2を通路にして消す
						if (map3[floor][tate][yoko].kind == m4)
						{
							map3[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーAと鍵扉が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//プレイヤーAの座標を１つ前の座標に置き換える
			player_A.image.x = player_A.collBeforePt.x;
			player_A.image.y = player_A.collBeforePt.y;

			IsMove_A = FALSE;
		}
		else if (ki_check == 1) {

			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						if (st_check == 1)
						{
							//鍵扉を通路にして消す
							if (map[floor][tate][yoko].kind == kl)
							{
								map[floor][tate][yoko].kind = t;
							}
						}
						else if (st_check == 2)
						{
							if (map2[floor][tate][yoko].kind == kl)
							{
								map2[floor][tate][yoko].kind = t;
							}
						}
						else if (st_check == 3)
						{
							if (map3[floor][tate][yoko].kind == kl)
							{
								map3[floor][tate][yoko].kind = t;
							}
						}
					}
				}
			}
		}
	}

	//プレイヤーAが鍵に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ki)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//鍵入手音が流れていないなら
					if (CheckSoundMem(SE_KEY.handle) == 0 && ki_check == 0)
					{
						//鍵入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_KEY.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_KEY.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//鍵を通路にして消す
						if (map[floor][tate][yoko].kind == ki)
						{
							map[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == ki)
						{
							map2[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == ki)
						{
							map3[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーAが剣に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_br)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && br_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//鍵を通路にして消す
						if (map[floor][tate][yoko].kind == br)
						{
							map[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == br)
						{
							map2[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == br)
						{
							map3[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーAが槍に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_sp)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && sp_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//鍵を通路にして消す
						if (map[floor][tate][yoko].kind == sp)
						{
							map[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == sp)
						{
							map2[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == sp)
						{
							map3[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーAが杖に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ca)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1 ; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && ca_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//杖を通路にして消す
						if (map[floor][tate][yoko].kind == ca)
						{
							map[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == ca)
						{
							map2[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == ca)
						{
							map3[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーAがワープ１に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_w1 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (st_check == 1)
				{
					move_floor = 0;
					player_A.image.x = w2_where.x;
					player_A.image.y = w2_where.y;
				}
				else if (st_check == 2)
				{
					move_floor = 0;
					player_A.image.x = w2_where.x2;
					player_A.image.y = w2_where.y2;
				}
				else if (st_check == 3)
				{
					move_floor = 0;
					player_A.image.x = w2_where.x3;
					player_A.image.y = w2_where.y3;
				}
			}
		}
	}

	//プレイヤーAがワープ2に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_w2 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (st_check == 1)
				{
					move_floor = 0;
					player_A.image.x = w1_where.x;
					player_A.image.y = w1_where.y;
				}
				else if (st_check == 2)
				{
					move_floor = 0;
					player_A.image.x = w1_where.x2;
					player_A.image.y = w1_where.y2;
				}
				else if (st_check == 3)
				{
					move_floor = 0;
					player_A.image.x = w1_where.x3;
					player_A.image.y = w1_where.y3;
				}
			}
		}
	}

	//プレイヤーAが敵１に当たっていたら
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_1.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_1.floor == fl_check && st_check == 1) || (enemy_1.floor2 == fl_check && st_check == 2) || (enemy_1.floor3 == fl_check && st_check == 3))
					{
						//剣を持っていて、敵１が生きていたら
						if (br_check == 1 && enemy1_live == 1)
						{
							enemy1_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

						}
						//剣を持っていなかったら、
						else if (br_check == 0)
						{
							//プレイヤー画像を死亡用に書き換える

							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}

	//プレイヤーAが敵２に当たっていたら
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_2.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_2.floor == fl_check && st_check == 1) || (enemy_2.floor2 == fl_check && st_check == 2) || (enemy_2.floor3 == fl_check && st_check == 3))
					{
						//槍を持っていて、敵２が生きていたら
						if (sp_check == 1 && enemy2_live == 1)
						{
							enemy2_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

							//ステージ１だったら、
							if (st_check == 1)
							{
								if (map[floor][tate][yoko].kind == k2)
								{
									//ステージ１のエネミー壁２を通路にして消す
									map[floor][tate][yoko].kind = t;
								}
							}
							//ステージ２だったら、
							else if (st_check == 2)
							{
								if (map2[floor][tate][yoko].kind == k2)
								{
									//ステージ２のエネミー壁２を通路にして消す
									map2[floor][tate][yoko].kind = t;
								}
							}
							//ステージ３だったら、
							else if (st_check == 3)
							{
								if (map3[floor][tate][yoko].kind == k2)
								{
									//ステージ３のエネミー壁２を通路にして消す
									map3[floor][tate][yoko].kind = t;
								}
							}

						}
						//槍を持っていなかったら、
						else if (sp_check == 0)
						{
							//プレイヤー画像を死亡用に書き換える


							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}

	//プレイヤーAが敵3に当たっていたら
	if (MY_CHECK_RECT_COLL(player_A.coll, enemy_3.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_3.floor == fl_check && st_check == 1) || (enemy_3.floor2 == fl_check && st_check == 2) || (enemy_3.floor3 == fl_check && st_check == 3))
					{
						//杖を持っていて、敵3が生きていたら
						if (ca_check == 1 && enemy3_live == 1)
						{
							enemy3_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

							//ステージ１だったら、
							if (st_check == 1)
							{
								if (map[floor][tate][yoko].kind == k3)
								{
									//ステージ１のエネミー壁３を通路にして消す
									map[floor][tate][yoko].kind = t;
								}
							}
							//ステージ２だったら、
							else if (st_check == 2)
							{
								if (map2[floor][tate][yoko].kind == k3)
								{
									//ステージ２のエネミー壁３を通路にして消す
									map2[floor][tate][yoko].kind = t;
								}
							}
							//ステージ３だったら、
							else if (st_check == 3)
							{
								if (map3[floor][tate][yoko].kind == k3)
								{
									//ステージ３のエネミー壁３を通路にして消す
									map3[floor][tate][yoko].kind = t;
								}
							}

						}
						//杖を持っていなかったら、
						else if (ca_check == 0)
						{
							//プレイヤー画像を死亡用に書き換える

							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}

	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲プレイヤーA当たり判定ここまで▲▲▲▲▲▲▲▲▲▲▲▲



	//▼▼▼▼▼▼▼▼プレイヤーB当たり判定ここから▼▼▼▼▼▼▼▼▼▼▼▼
	//プレイヤーBと壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k)
	{
		//プレイヤーBの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m4)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとエネミー壁１が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとエネミー壁２が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとエネミー壁３が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBがスイッチ1に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s1)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (st_check == 1)
					{
						//ギミック1を通路にして消す
						if (map[floor][tate][yoko].kind == m1)
						{
							map[floor][tate][yoko].kind = t;
							s1_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == m1)
						{
							map2[floor][tate][yoko].kind = t;
							s1_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == m1)
						{
							map3[floor][tate][yoko].kind = t;
							s1_check = 1;
						}
					}

					//スイッチ音が流れていないなら
					if (CheckSoundMem(SE_SWITCH.handle) == 0  && s1_check == 0)
					{
						//スイッチ音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//プレイヤーBがスイッチ2に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s2)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (st_check == 1)
					{
						//ギミック2を通路にして消す
						if (map[floor][tate][yoko].kind == m2)
						{
							map[floor][tate][yoko].kind = t;
							s2_check = 1;

						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == m2)
						{
							map2[floor][tate][yoko].kind = t;
							s2_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == m2)
						{
							map3[floor][tate][yoko].kind = t;
							s2_check = 1;
						}
					}

					//スイッチ音が流れていないなら
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s2_check == 0)
					{
						//スイッチ音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//プレイヤーBがスイッチ3に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s3)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (st_check == 1)
					{
						//ギミック3を通路にして消す
						if (map[floor][tate][yoko].kind == m3)
						{
							map[floor][tate][yoko].kind = t;
							s3_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == m3)
						{
							map2[floor][tate][yoko].kind = t;
							s3_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == m3)
						{
							map3[floor][tate][yoko].kind = t;
							s3_check = 1;
						}
					}
					//スイッチ音が流れていないなら
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s3_check == 0)
					{
						//スイッチ音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//プレイヤーBがスイッチ4に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s4)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (st_check == 1)
					{
						//ギミック4を通路にして消す
						if (map[floor][tate][yoko].kind == m4)
						{
							map[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == m4)
						{
							map2[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == m4)
						{
							map3[floor][tate][yoko].kind = t;
							s4_check = 1;
						}
					}

					//スイッチ音が流れていないなら
					if (CheckSoundMem(SE_SWITCH.handle) == 0 && s4_check == 0)
					{
						//スイッチ音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_SWITCH.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_SWITCH.handle, DX_PLAYTYPE_BACK, TRUE);
					}
				}
			}
		}
	}

	//プレイヤーBと鍵扉が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//プレイヤーBの座標を１つ前の座標に置き換える
			player_B.image.x = player_B.collBeforePt.x;
			player_B.image.y = player_B.collBeforePt.y;

			IsMove_B = FALSE;
		}
		else if (ki_check == 1)
		{

			for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
			{
				for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
				{
					for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
					{
						if (st_check == 1)
						{
							//鍵扉を通路にして消す
							if (map[floor][tate][yoko].kind == kl)
							{
								map[floor][tate][yoko].kind = t;
							}
						}
						else if (st_check == 2)
						{
							if (map2[floor][tate][yoko].kind == kl)
							{
								map2[floor][tate][yoko].kind = t;
								s4_check = 1;
							}
						}
						else if (st_check == 3)
						{
							if (map3[floor][tate][yoko].kind == kl)
							{
								map3[floor][tate][yoko].kind = t;
								s4_check = 1;
							}
						}
					}
				}
			}
		}
	}

	//プレイヤーBが鍵に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_ki)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//鍵入手音が流れていないなら
					if (CheckSoundMem(SE_KEY.handle) == 0 && ki_check == 0)
					{
						//鍵入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_KEY.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_KEY.handle, DX_PLAYTYPE_BACK, TRUE);
					}
					
					if (st_check == 1)
					{
						//鍵を通路にして消す
						if (map[floor][tate][yoko].kind == ki)
						{
							map[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == ki)
						{
							map2[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == ki)
						{
							map3[floor][tate][yoko].kind = t;
							ki_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーBが剣に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_br)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && br_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//剣を通路にして消す
						if (map[floor][tate][yoko].kind == br)
						{
							map[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == br)
						{
							map2[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == br)
						{
							map3[floor][tate][yoko].kind = t;
							br_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーBが槍に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_sp)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && sp_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//槍を通路にして消す
						if (map[floor][tate][yoko].kind == sp)
						{
							map[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == sp)
						{
							map2[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == sp)
						{
							map3[floor][tate][yoko].kind = t;
							sp_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーBが杖に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_ca)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//武器入手音が流れていないなら
					if (CheckSoundMem(SE_WEAPON.handle) == 0 && ca_check == 0)
					{
						//武器入手音の音量を下げる
						ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 70, SE_WEAPON.handle); //MUSIC_VOLUMEで音量調節
						PlaySoundMem(SE_WEAPON.handle, DX_PLAYTYPE_BACK, TRUE);
					}

					if (st_check == 1)
					{
						//杖を通路にして消す
						if (map[floor][tate][yoko].kind == ca)
						{
							map[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
					else if (st_check == 2)
					{
						if (map2[floor][tate][yoko].kind == ca)
						{
							map2[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
					else if (st_check == 3)
					{
						if (map3[floor][tate][yoko].kind == ca)
						{
							map3[floor][tate][yoko].kind = t;
							ca_check = 1;
						}
					}
				}
			}
		}
	}

	//プレイヤーBがワープ１に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_w1 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (st_check == 1)
				{
					move_floor = 0;
					player_B.image.x = w2_where.x;
					player_B.image.y = w2_where.y;
				}
				else if (st_check == 2)
				{
					move_floor = 0;
					player_B.image.x = w2_where.x2;
					player_B.image.y = w2_where.y2;
				}
				else if (st_check == 3)
				{
					move_floor = 0;
					player_B.image.x = w2_where.x3;
					player_B.image.y = w2_where.y3;
				}
			}
		}
	}

	//プレイヤーBがワープ2に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_w2 && move_floor == 1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (st_check == 1)
				{
					move_floor = 0;
					player_B.image.x = w1_where.x;
					player_B.image.y = w1_where.y;
				}
				else if (st_check == 2)
				{
					move_floor = 0;
					player_B.image.x = w1_where.x2;
					player_B.image.y = w1_where.y2;
				}
				else if (st_check == 3)
				{
					move_floor = 0;
					player_B.image.x = w1_where.x3;
					player_B.image.y = w1_where.y3;
				}
			}
		}
	}

	//プレイヤーBが敵１に当たっていたら
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_1.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_1.floor == fl_check && st_check == 1) || (enemy_1.floor2 == fl_check && st_check == 2) || (enemy_1.floor3 == fl_check && st_check == 3))
					{
						//剣を持っていて、敵１が生きていたら
						if (br_check == 1 && enemy1_live == 1)
						{
							enemy1_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

						}
						//剣を持っていなかったら、
						else if (br_check == 0)
						{
							//プレイヤー画像を死亡用に書き換える

							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}

	//プレイヤーBが敵２に当たっていたら
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_2.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_2.floor == fl_check && st_check == 1) || (enemy_2.floor2 == fl_check && st_check == 2) || (enemy_2.floor3 == fl_check && st_check == 3))
					{
						//槍を持っていて、敵２が生きていたら
						if (sp_check == 1 && enemy2_live == 1)
						{
							enemy2_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

						}
						//槍を持っていなかったら、
						else if (sp_check == 0)
						{
							//プレイヤー画像を死亡用に書き換える

							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}

	//プレイヤーBが敵3に当たっていたら
	if (MY_CHECK_RECT_COLL(player_B.coll, enemy_3.coll) == TRUE)
	{
		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if ((enemy_3.floor == fl_check && st_check == 1) || (enemy_3.floor2 == fl_check && st_check == 2) || (enemy_3.floor3 == fl_check && st_check == 3))
					{
						//杖を持っていて、敵3が生きていたら
						if (ca_check == 1 && enemy3_live == 1)
						{
							enemy3_live = 0;

							//攻撃音が流れていないなら
							if (CheckSoundMem(SE_ATACK.handle) == 0)
							{
								//攻撃音の音量を下げる
								ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, SE_ATACK.handle); //MUSIC_VOLUMEで音量調節
								PlaySoundMem(SE_ATACK.handle, DX_PLAYTYPE_BACK, TRUE);
							}

						}
						//杖を持っていなかったら、
						else if (ca_check == 0)
						{
							//BGMが流れているなら
							if (CheckSoundMem(BGM.handle) != 0)
							{
								StopSoundMem(BGM.handle);	//BGMを止める
							}

							//ゲームオーバーを表示する
							GameScene = GAME_SCENE_OVER;
						}
					}
				}
			}
		}
	}
	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲プレイヤーB当たり判定ここまで▲▲▲▲▲▲▲▲▲▲▲▲

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼敵１当たり判定ここから▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//敵１と壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_k || MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_k1 ||
		MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_k2 || MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_k3)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//敵１とギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m1)
	{
		//敵１の座標を１つ前の座標に置き換える
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//敵１とギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m2)
	{
		//敵１の座標を１つ前の座標に置き換える
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//敵１とギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m3)
	{
		//敵１の座標を１つ前の座標に置き換える
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//敵１とギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_1.coll) == TRUE_m4)
	{
		//敵１の座標を１つ前の座標に置き換える
		enemy_1.image.x = enemy_1.collBeforePt.x;
		enemy_1.image.y = enemy_1.collBeforePt.y;

		IsMove_E1 = FALSE;
	}

	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲敵１当たり判定ここまで▲▲▲▲▲▲▲▲▲▲▲▲

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼敵２当たり判定ここから▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//敵２と壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_k || MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_k1 ||
		MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_k2 || MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_k3)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//敵2とギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m1)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//敵2とギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m2)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//敵2とギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m3)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//敵2とギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_2.coll) == TRUE_m4)
	{
		//敵2の座標を１つ前の座標に置き換える
		enemy_2.image.x = enemy_2.collBeforePt.x;
		enemy_2.image.y = enemy_2.collBeforePt.y;

		IsMove_E2 = FALSE;
	}

	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲敵２当たり判定ここまで▲▲▲▲▲▲▲▲▲▲▲▲

	//▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼敵3当たり判定ここから▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//敵3と壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_k || MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_k1 || 
		MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_k2 || MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_k3)
	{
		//敵3の座標を１つ前の座標に置き換える
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//敵3とギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m1)
	{
		//敵3の座標を１つ前の座標に置き換える
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//敵3とギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m2)
	{
		//敵3の座標を１つ前の座標に置き換える
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//敵3とギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m3)
	{
		//敵3の座標を１つ前の座標に置き換える
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//敵3とギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(enemy_3.coll) == TRUE_m4)
	{
		//敵3の座標を１つ前の座標に置き換える
		enemy_3.image.x = enemy_3.collBeforePt.x;
		enemy_3.image.y = enemy_3.collBeforePt.y;

		IsMove_E3 = FALSE;
	}

	//▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲敵3当たり判定ここまで▲▲▲▲▲▲▲▲▲▲▲▲


	//プレイヤーAとBがフロアを移動したら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_t && MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_t)
	{
		move_floor = 1;
	}

	//プレイヤーAとBが階段に当たっていたら
		if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_st && MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_st) {
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (move_floor == 1)
					{
						if (fl_check == 0)
						{
							fl_check = 1;
							move_floor = 0;
						}
						else if (fl_check == 1)
						{
							fl_check = 0;
							move_floor = 0;
						}
					}
				}
			}

			return;
		}

		for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
		{
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//ステージ１だったら、
					if (st_check == 1)
					{
						//敵１がいなかったら
						if (enemy1_live == 0)
						{
							if (map[floor][tate][yoko].kind == k1)
							{
								//ステージ１のエネミー壁1を通路にして消す
								map[floor][tate][yoko].kind = t;
							}
						}
						//敵２がいなかったら
						if (enemy2_live == 0)
						{
							if (map[floor][tate][yoko].kind == k2)
							{
								//ステージ１のエネミー壁２を通路にして消す
								map[floor][tate][yoko].kind = t;
							}
						}
						//敵3がいなかったら
						if (enemy3_live == 0)
						{
							if (map[floor][tate][yoko].kind == k3)
							{
								//ステージ１のエネミー壁３を通路にして消す
								map[floor][tate][yoko].kind = t;
							}
						}

					}
					//ステージ２だったら、
					else if (st_check == 2)
					{
						//敵１がいなかったら
						if (enemy1_live == 0)
						{
							if (map2[floor][tate][yoko].kind == k1)
							{
								//ステージ2のエネミー壁1を通路にして消す
								map2[floor][tate][yoko].kind = t;
							}
						}
						//敵２がいなかったら
						if (enemy2_live == 0)
						{
							if (map2[floor][tate][yoko].kind == k2)
							{
								//ステージ2のエネミー壁２を通路にして消す
								map2[floor][tate][yoko].kind = t;
							}
						}
						//敵3がいなかったら
						if (enemy3_live == 0)
						{
							if (map2[floor][tate][yoko].kind == k3)
							{
								//ステージ2のエネミー壁３を通路にして消す
								map2[floor][tate][yoko].kind = t;
							}
						}
					}
					//ステージ３だったら、
					else if (st_check == 3)
					{
						//敵１がいなかったら
						if (enemy1_live == 0)
						{
							if (map3[floor][tate][yoko].kind == k1)
							{
								//ステージ3のエネミー壁1を通路にして消す
								map3[floor][tate][yoko].kind = t;
							}
						}
						//敵２がいなかったら
						if (enemy2_live == 0)
						{
							if (map3[floor][tate][yoko].kind == k2)
							{
								//ステージ3のエネミー壁２を通路にして消す
								map3[floor][tate][yoko].kind = t;
							}
						}
						//敵3がいなかったら
						if (enemy3_live == 0)
						{
							if (map3[floor][tate][yoko].kind == k3)
							{
								//ステージ3のエネミー壁３を通路にして消す
								map3[floor][tate][yoko].kind = t;
							}
						}
					}
				}
			}
		}

	//プレイヤーAとBがゴールに当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ag) {
		if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_bg) {

			//BGMが流れているなら
			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);	//BGMを止める
			}

			if (st_check == 1)
			{
				GameScene = GAME_INIT_PLAY_SECOND;
			}
			else if (st_check == 2)
			{
				GameScene = GAME_INIT_PLAY_THIRD;
			}
			else if (st_check == 3)
			{
				GameScene = GAME_SCENE_END;
			}

			return;
		}
	}

	
	//プレイヤーAが移動先に動けるなら
	if (IsMove_A == TRUE)
	{
		//当たっていない時のプレイヤーAの座標を取得
		player_A.collBeforePt.x = player_A.image.x;
		player_A.collBeforePt.y = player_A.image.y;
	}

	//プレイヤーBが移動先に動けるなら
	if (IsMove_B == TRUE)
	{
		//当たっていない時のプレイヤーBの座標を取得
		player_B.collBeforePt.x = player_B.image.x;
		player_B.collBeforePt.y = player_B.image.y;
	}

	//敵１が移動先に動けるなら
	if (IsMove_E1 == TRUE)
	{
		//当たっていない時の敵１の座標を取得
		enemy_1.collBeforePt.x = enemy_1.image.x;
		enemy_1.collBeforePt.y = enemy_1.image.y;
	}

	//敵2が移動先に動けるなら
	if (IsMove_E2 == TRUE)
	{
		//当たっていない時の敵１の座標を取得
		enemy_2.collBeforePt.x = enemy_2.image.x;
		enemy_2.collBeforePt.y = enemy_2.image.y;
	}

	//敵3が移動先に動けるなら
	if (IsMove_E3 == TRUE)
	{
		//当たっていない時の敵１の座標を取得
		enemy_3.collBeforePt.x = enemy_3.image.x;
		enemy_3.collBeforePt.y = enemy_3.image.y;
	}
	//-----------------------当たり判定関係ここまで------------------------
	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (fl_check == 0)
				{
					//初期階層マップを描画
					DrawGraph(
						map[0][tate][yoko].x,
						map[0][tate][yoko].y,
						mapChip.handle[map[0][tate][yoko].kind],
						TRUE);
				}
				else if(fl_check == 1 )
				{
					//別階層マップを描画
					DrawGraph(
						map[1][tate][yoko].x,
						map[1][tate][yoko].y,
						mapChip.handle[map[1][tate][yoko].kind],
						TRUE);
				}
			}
		}


	if (ki_check == 1) {
		//鍵取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 12,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[19],
			TRUE);
	}

	if (br_check == 1) {
		//剣取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 13,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[20],
			TRUE);
	}

	if (sp_check == 1) {
		//槍取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 14,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[21],
			TRUE);
	}

	if (ca_check == 1) {
		//杖取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 15,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[22],
			TRUE);
	}

	//プレイヤーAを描画する
	strcpy_s(ImageBack.path, IMAGE_player_A_PATH);
	LoadGraphScreen(player_A.image.x , player_A.image.y, ImageBack.path, FALSE);

	//プレイヤーBを描画する
	strcpy_s(ImageBack.path, IMAGE_player_B_PATH);
	LoadGraphScreen(player_B.image.x , player_B.image.y, ImageBack.path, FALSE);

	if (enemy1_live == 1 && enemy_1.floor == fl_check)
	{
		//敵１を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_1_PATH);
		LoadGraphScreen(enemy_1.image.x, enemy_1.image.y, ImageBack.path, FALSE);
	}

	if (enemy2_live == 1 && enemy_2.floor == fl_check)
	{
		//敵2を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_2_PATH);
		LoadGraphScreen(enemy_2.image.x, enemy_2.image.y, ImageBack.path, FALSE);
	}

	if (enemy3_live == 1 && enemy_3.floor == fl_check)
	{
		//敵3を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_3_PATH);
		LoadGraphScreen(enemy_3.image.x, enemy_3.image.y, ImageBack.path, FALSE);
	}
	WaitTimer(60);

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		//当たり判定の描画（デバッグ用）
			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					if (fl_check == 0)
					{
						//壁ならば壁用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == k)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
						}

						//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m1 && s1_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m2 && s2_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m3 && s3_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m4 && s4_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == kl && ki_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//通路ならば通路用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == t)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
						}

						//スイッチ1ならばスイッチ1用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s1)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ2ならばスイッチ2用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s2)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ3ならばスイッチ3用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s3)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ4ならばスイッチ4用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s4)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//鍵ならば鍵用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == ki)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
						}

						//階段ならば階段の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == st)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
						}
					}
					else if (fl_check == 1)
					{
						//壁ならば壁用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == k)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
						}

						//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m1 && s1_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m2 && s2_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m3 && s3_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == m4 && s4_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == kl && ki_check == 0)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
						}

						//通路ならば通路用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == t)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
						}

						//スイッチ1ならばスイッチ1用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s1)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ2ならばスイッチ2用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s2)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ3ならばスイッチ3用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s3)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//スイッチ4ならばスイッチ4用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == s4)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
						}

						//鍵ならば鍵用の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == ki)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
						}

						//階段ならば階段の当たり判定を描画
						if (mapDatafirst[fl_check][tate][yoko] == st)
						{
							DrawBox(mapColl[fl_check][tate][yoko].left, mapColl[fl_check][tate][yoko].top, mapColl[fl_check][tate][yoko].right, mapColl[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
						}
					}

					DrawString(0, 0, "プレイ画面(スペースキーを押して下さい)", GetColor(255, 255, 255));
				}
			}

		//プレイヤーAの当たり判定の描画（デバッグ用）
		DrawBox(player_A.coll.left, player_A.coll.top, player_A.coll.right, player_A.coll.bottom, GetColor(255, 0, 0), FALSE);

		//プレイヤーBの当たり判定の描画（デバッグ用）
		DrawBox(player_B.coll.left, player_B.coll.top, player_B.coll.right, player_B.coll.bottom, GetColor(255, 0, 0), FALSE);

	}

	//DrawString(0, 0, "プレイヤーA：WASDで操作\nプレイヤーB：方向キーで操作", GetColor(255, 255, 255));
	return;
}

//２プレイ画面の描画
VOID MY_PLAY_SECOND_DRAW(VOID)
{
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (fl_check == 0)
			{
				//初期階層マップを描画
				DrawGraph(
					map2[0][tate][yoko].x,
					map2[0][tate][yoko].y,
					mapChip.handle[map2[0][tate][yoko].kind],
					TRUE);
			}
			else if (fl_check == 1)
			{
				//別階層マップを描画
				DrawGraph(
					map2[1][tate][yoko].x,
					map2[1][tate][yoko].y,
					mapChip.handle[map2[1][tate][yoko].kind],
					TRUE);
			}
		}
	}


	if (ki_check == 1) {
		//鍵取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 12,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[19],
			TRUE);
	}

	if (br_check == 1) {
		//剣取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 13,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[20],
			TRUE);
	}

	if (sp_check == 1) {
		//槍取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 14,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[21],
			TRUE);
	}

	if (ca_check == 1) {
		//杖取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 15,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[22],
			TRUE);
	}

	//プレイヤーAを描画する
	strcpy_s(ImageBack.path, IMAGE_player_A_PATH);
	LoadGraphScreen(player_A.image.x, player_A.image.y, ImageBack.path, FALSE);

	//プレイヤーBを描画する
	strcpy_s(ImageBack.path, IMAGE_player_B_PATH);
	LoadGraphScreen(player_B.image.x, player_B.image.y, ImageBack.path, FALSE);

	if (enemy1_live == 1 && enemy_1.floor2 == fl_check)
	{
		//敵１を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_1_PATH);
		LoadGraphScreen(enemy_1.image.x, enemy_1.image.y, ImageBack.path, FALSE);
	}

	if (enemy2_live == 1 && enemy_2.floor2 == fl_check)
	{
		//敵2を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_2_PATH);
		LoadGraphScreen(enemy_2.image.x, enemy_2.image.y, ImageBack.path, FALSE);
	}

	if (enemy3_live == 1 && enemy_3.floor2 == fl_check)
	{
		//敵3を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_3_PATH);
		LoadGraphScreen(enemy_3.image.x, enemy_3.image.y, ImageBack.path, FALSE);
	}
	WaitTimer(60);

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		//当たり判定の描画（デバッグ用）
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (fl_check == 0)
				{
					//壁ならば壁用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == k)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
					}

					//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m1 && s1_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m2 && s2_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m3 && s3_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m4 && s4_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == kl && ki_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//通路ならば通路用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == t)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
					}

					//スイッチ1ならばスイッチ1用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s1)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ2ならばスイッチ2用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s2)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ3ならばスイッチ3用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s3)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ4ならばスイッチ4用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s4)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//鍵ならば鍵用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == ki)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
					}

					//階段ならば階段の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == st)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
					}
				}
				else if (fl_check == 1)
				{
					//壁ならば壁用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == k)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
					}

					//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m1 && s1_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m2 && s2_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m3 && s3_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == m4 && s4_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == kl && ki_check == 0)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//通路ならば通路用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == t)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
					}

					//スイッチ1ならばスイッチ1用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s1)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ2ならばスイッチ2用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s2)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ3ならばスイッチ3用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s3)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ4ならばスイッチ4用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == s4)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//鍵ならば鍵用の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == ki)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
					}

					//階段ならば階段の当たり判定を描画
					if (mapDatasecond[fl_check][tate][yoko] == st)
					{
						DrawBox(mapCollSecond[fl_check][tate][yoko].left, mapCollSecond[fl_check][tate][yoko].top, mapCollSecond[fl_check][tate][yoko].right, mapCollSecond[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
					}
				}

				DrawString(0, 0, "プレイ画面(スペースキーを押して下さい)", GetColor(255, 255, 255));
			}
		}

		//プレイヤーAの当たり判定の描画（デバッグ用）
		DrawBox(player_A.coll.left, player_A.coll.top, player_A.coll.right, player_A.coll.bottom, GetColor(255, 0, 0), FALSE);

		//プレイヤーBの当たり判定の描画（デバッグ用）
		DrawBox(player_B.coll.left, player_B.coll.top, player_B.coll.right, player_B.coll.bottom, GetColor(255, 0, 0), FALSE);

	}

	//DrawString(0, 0, "プレイヤーA：WASDで操作\nプレイヤーB：方向キーで操作", GetColor(255, 255, 255));
	return;
}

//３プレイ画面の描画
VOID MY_PLAY_THIRD_DRAW(VOID)
{
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			if (fl_check == 0)
			{
				//初期階層マップを描画
				DrawGraph(
					map3[0][tate][yoko].x,
					map3[0][tate][yoko].y,
					mapChip.handle[map3[0][tate][yoko].kind],
					TRUE);
			}
			else if (fl_check == 1)
			{
				//別階層マップを描画
				DrawGraph(
					map3[1][tate][yoko].x,
					map3[1][tate][yoko].y,
					mapChip.handle[map3[1][tate][yoko].kind],
					TRUE);
			}
		}
	}


	if (ki_check == 1) {
		//鍵取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 12,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[19],
			TRUE);
	}

	if (br_check == 1) {
		//剣取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 13,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[20],
			TRUE);
	}

	if (sp_check == 1) {
		//槍取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 14,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[21],
			TRUE);
	}

	if (ca_check == 1) {
		//杖取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 15,
			MAP_DIV_HEIGHT * 24,
			mapChip.handle[22],
			TRUE);
	}

	//プレイヤーAを描画する
	strcpy_s(ImageBack.path, IMAGE_player_A_PATH);
	LoadGraphScreen(player_A.image.x, player_A.image.y, ImageBack.path, FALSE);

	//プレイヤーBを描画する
	strcpy_s(ImageBack.path, IMAGE_player_B_PATH);
	LoadGraphScreen(player_B.image.x, player_B.image.y, ImageBack.path, FALSE);

	if (enemy1_live == 1 && enemy_1.floor3 == fl_check)
	{
		//敵１を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_1_PATH);
		LoadGraphScreen(enemy_1.image.x, enemy_1.image.y, ImageBack.path, FALSE);
	}

	if (enemy2_live == 1 && enemy_2.floor3 == fl_check)
	{
		//敵2を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_2_PATH);
		LoadGraphScreen(enemy_2.image.x, enemy_2.image.y, ImageBack.path, FALSE);
	}

	if (enemy3_live == 1 && enemy_3.floor3 == fl_check)
	{
		//敵3を描画する
		strcpy_s(ImageBack.path, IMAGE_enemy_3_PATH);
		LoadGraphScreen(enemy_3.image.x, enemy_3.image.y, ImageBack.path, FALSE);
	}
	WaitTimer(60);

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		//当たり判定の描画（デバッグ用）
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				if (fl_check == 0)
				{
					//壁ならば壁用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == k)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
					}

					//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m1 && s1_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m2 && s2_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m3 && s3_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m4 && s4_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == kl && ki_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//通路ならば通路用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == t)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
					}

					//スイッチ1ならばスイッチ1用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s1)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ2ならばスイッチ2用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s2)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ3ならばスイッチ3用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s3)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ4ならばスイッチ4用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s4)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//鍵ならば鍵用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == ki)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
					}

					//階段ならば階段の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == st)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
					}
				}
				else if (fl_check == 1)
				{
					//壁ならば壁用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == k)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
					}

					//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m1 && s1_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m2 && s2_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m3 && s3_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == m4 && s4_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//鍵扉であり、なおかつ鍵をとっていない（s4_check=0）ならばギミック用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == kl && ki_check == 0)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
					}

					//通路ならば通路用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == t)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
					}

					//スイッチ1ならばスイッチ1用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s1)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ2ならばスイッチ2用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s2)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ3ならばスイッチ3用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s3)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//スイッチ4ならばスイッチ4用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == s4)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
					}

					//鍵ならば鍵用の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == ki)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(255, 255, 0), FALSE);
					}

					//階段ならば階段の当たり判定を描画
					if (mapDatathird[fl_check][tate][yoko] == st)
					{
						DrawBox(mapCollThird[fl_check][tate][yoko].left, mapCollThird[fl_check][tate][yoko].top, mapCollThird[fl_check][tate][yoko].right, mapCollThird[fl_check][tate][yoko].bottom, GetColor(0, 0, 0), FALSE);
					}
				}

				DrawString(0, 0, "プレイ画面(スペースキーを押して下さい)", GetColor(255, 255, 255));
			}
		}

		//プレイヤーAの当たり判定の描画（デバッグ用）
		DrawBox(player_A.coll.left, player_A.coll.top, player_A.coll.right, player_A.coll.bottom, GetColor(255, 0, 0), FALSE);

		//プレイヤーBの当たり判定の描画（デバッグ用）
		DrawBox(player_B.coll.left, player_B.coll.top, player_B.coll.right, player_B.coll.bottom, GetColor(255, 0, 0), FALSE);

	}

	//DrawString(0, 0, "プレイヤーA：WASDで操作\nプレイヤーB：方向キーで操作", GetColor(255, 255, 255));
	return;
}

//ゲームオーバー画面
VOID MY_OVER(VOID)
{
	MY_OVER_PROC();  //処理
	MY_OVER_DRAW();  //描画

	return;
}

//ゲームオーバー画面の処理
VOID MY_OVER_PROC(VOID)
{
	//エスケープキーを押したら、スタートシーンへ移動する
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_FAIL.handle) != 0)
		{
			StopSoundMem(BGM_FAIL.handle);	//BGMを止める
		}
		SetDrawBright(255, 255, 255);
		GameScene = GAME_SCENE_START;
		return;
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_FAIL.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_FAIL.handle); //MUSIC_VOLUMEで音量調節
		PlaySoundMem(BGM_FAIL.handle, DX_PLAYTYPE_LOOP);
	}

	//コンプリートの点滅
	if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
	{
		ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
	}
	else
	{
		//描画する/しないを決める
		if (ImageEndCOMP.IsDraw == FALSE)
		{
			ImageEndCOMP.IsDraw = TRUE;
		}
		else if (ImageEndCOMP.IsDraw == TRUE)
		{
			ImageEndCOMP.IsDraw = FALSE;
		}
		ImageEndCOMP.Cnt = 0;
	}

	return;
}

//ゲームオーバー画面の描画
VOID MY_OVER_DRAW(VOID)
{
		ClearDrawScreen();                   // 裏画面のデータを全て削除

		if (c >= 0 && c < 128)                    //cが0~256の時
			SetDrawBright(c*2, c*2, c*2);        //段々あかるく(c= 0->255)
		if (c >= 128 && c < 300)                  //cが256~400の時
			SetDrawBright(255, 255, 255);  //通常の明るさ

		//ゲームオーバー背景の描画
		DrawGraph(ImageEndDeath.x, ImageEndDeath.y, ImageEndDeath.handle, TRUE);

		//コンプリートロゴの描画
		//DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);

		if (c <= 128)
		{
			c++;                                  //cをカウントアップ
		}

		if (c >= 128)
		{
			//点滅
			if (ImageEndCOMP.IsDraw == TRUE)
			{
				//エンドタイトルの描画
				DrawGraph(ImageTitleEND.image.x, ImageTitleEND.image.y, ImageTitleEND.image.handle, TRUE);
			}
		}

	return;
}


//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画

	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	//エスケープキーを押したら、スタートシーンへ移動する
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_COMP.handle) != 0)
		{
			StopSoundMem(BGM_COMP.handle);	//BGMを止める
		}
		GameScene = GAME_SCENE_START;
		return;
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_COMP.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_COMP.handle); //MUSIC_VOLUMEで音量調節
		PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_LOOP);
	}

	//コンプリートの点滅
	if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
	{
		ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
	}
	else
	{
		//描画する/しないを決める
		if (ImageEndCOMP.IsDraw == FALSE)
		{
			ImageEndCOMP.IsDraw = TRUE;
		}
		else if (ImageEndCOMP.IsDraw == TRUE)
		{
			ImageEndCOMP.IsDraw = FALSE;
		}
		ImageEndCOMP.Cnt = 0;
	}

	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//エンド背景の描画

	//点滅
	if (ImageEndCOMP.IsDraw == TRUE)
	{
		//コンプリートロゴの描画
		DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);

		//エンドタイトルの描画
		DrawGraph(ImageTitleEND.image.x, ImageTitleEND.image.y, ImageTitleEND.image.handle, TRUE);
	}

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		DrawString(0, 0, "エンド画面(エスケープキーを押して下さい)", GetColor(255, 0, 255));
	}
	return;
}

//画像をまとめて読み込む関数
BOOL MY_LOAD_IMAGE(VOID)
{
	//プレイヤーAの画像
	strcpy_s(player_A.image.path, IMAGE_player_A_PATH);		//パスの設定
	player_A.image.handle = LoadGraph(player_A.image.path);	//読み込み
	if (player_A.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_player_A_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイヤーBの画像
	strcpy_s(player_B.image.path, IMAGE_player_B_PATH);		//パスの設定
	player_B.image.handle = LoadGraph(player_B.image.path);	//読み込み
	if (player_B.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_player_B_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//敵１の画像
	strcpy_s(enemy_1.image.path, IMAGE_enemy_1_PATH);		//パスの設定
	enemy_1.image.handle = LoadGraph(enemy_1.image.path);	//読み込み
	if (enemy_1.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_1_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//敵2の画像
	strcpy_s(enemy_2.image.path, IMAGE_enemy_2_PATH);		//パスの設定
	enemy_2.image.handle = LoadGraph(enemy_2.image.path);	//読み込み
	if (enemy_2.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_2_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//敵3の画像
	strcpy_s(enemy_3.image.path, IMAGE_enemy_3_PATH);		//パスの設定
	enemy_3.image.handle = LoadGraph(enemy_3.image.path);	//読み込み
	if (enemy_3.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_enemy_3_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトル背景
	strcpy_s(ImageTitleBK.path, IMAGE_TITLE_BK_PATH);			//パスの設定
	ImageTitleBK.handle = LoadGraph(ImageTitleBK.path);			//読み込み
	if (ImageTitleBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleBK.handle, &ImageTitleBK.width, &ImageTitleBK.height);	//画像の幅と高さをf取得
	ImageTitleBK.x = GAME_WIDTH / 2 - ImageTitleBK.width / 2;		//左右中央揃え
	ImageTitleBK.y = GAME_HEIGHT / 2 - ImageTitleBK.height / 2;		//上下中央揃え

	//タイトルロゴ
	strcpy_s(ImageTitleROGO.image.path, IMAGE_TITLE_ROGO_PATH);					//パスの設定
	ImageTitleROGO.image.handle = LoadGraph(ImageTitleROGO.image.path);			//読み込み
	if (ImageTitleROGO.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleROGO.image.handle, &ImageTitleROGO.image.width, &ImageTitleROGO.image.height);	//画像の幅と高さを取得
	ImageTitleROGO.image.x = GAME_WIDTH / 2;			    //中央寄せ
	ImageTitleROGO.image.y = GAME_HEIGHT / 2;				//中央寄せ
	ImageTitleROGO.angle = DX_PI * 2;						//回転率
	ImageTitleROGO.angleMAX = DX_PI * 2;					//回転率MAX
	ImageTitleROGO.rate = 0.0;								//拡大率
	ImageTitleROGO.rateMAX = IMAGE_TITLE_ROGO_ROTA_MAX;		//拡大率MAX

	//タイトルスタート
	strcpy_s(ImageTitleSTART.image.path, IMAGE_TITLE_START_PATH);					//パスの設定
	ImageTitleSTART.image.handle = LoadGraph(ImageTitleSTART.image.path);			//読み込み
	if (ImageTitleSTART.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_START_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleSTART.image.handle, &ImageTitleSTART.image.width, &ImageTitleSTART.image.height);	//画像の幅と高さを取得
	ImageTitleSTART.image.x = GAME_WIDTH / 2 - ImageTitleSTART.image.width / 2;					//左右中央揃え
	ImageTitleSTART.image.y = ImageTitleROGO.image.y + ImageTitleROGO.image.height / 2 + 10;	//ロゴの下に表示
	ImageTitleSTART.Cnt = 0.0;								//カウンタ
	ImageTitleSTART.CntMAX = IMAGE_TITLE_START_CNT_MAX;		//カウンタMAX
	ImageTitleSTART.IsDraw = FALSE;							//描画させない

	//エンドデス背景
	strcpy_s(ImageEndDeath.path, IMAGE_END_DEATH_PATH);			//パスの設定
	ImageEndDeath.handle = LoadGraph(ImageEndDeath.path);			//読み込み
	if (ImageEndDeath.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_END_DEATH_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageEndDeath.handle, &ImageEndDeath.width, &ImageEndDeath.height);	//画像の幅と高さを取得
	ImageEndDeath.x = GAME_WIDTH / 2 - ImageEndDeath.width / 2;		//左右中央揃え
	ImageEndDeath.y = GAME_HEIGHT / 2 - ImageEndDeath.height / 2;		//上下中央揃え

	//エンドコンプ
	strcpy_s(ImageEndCOMP.image.path, IMAGE_END_COMP_PATH);
	ImageEndCOMP.image.handle = LoadGraph(ImageEndCOMP.image.path);
	if (ImageEndCOMP.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(ImageEndCOMP.image.handle, &ImageEndCOMP.image.width, &ImageEndCOMP.image.height);	//画像の幅と高さを取得
	ImageEndCOMP.image.x = GAME_WIDTH / 2 - ImageEndCOMP.image.width / 2;			//左右中央揃え
	ImageEndCOMP.image.y = GAME_HEIGHT / 2 - ImageEndCOMP.image.height / 2;			//上下中央揃え
	ImageEndCOMP.Cnt = 0.0;									//カウンタ
	ImageEndCOMP.CntMAX = IMAGE_END_COMP_CNT_MAX;			//カウンタMAX
	ImageEndCOMP.IsDraw = TRUE;							//描画させない

	//エンドタイトル
	strcpy_s(ImageTitleEND.image.path, IMAGE_TITLE_END_PATH);					//パスの設定
	ImageTitleEND.image.handle = LoadGraph(ImageTitleEND.image.path);			//読み込み
	if (ImageTitleEND.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleEND.image.handle, &ImageTitleEND.image.width, &ImageTitleEND.image.height);	//画像の幅と高さを取得
	ImageTitleEND.image.x = GAME_WIDTH / 2 - ImageTitleEND.image.width / 2 + 10;					//左右中央揃え
	ImageTitleEND.image.y = ImageEndCOMP.image.y + ImageEndCOMP.image.height / 2 + 200;	//ロゴの下に表示
	ImageTitleEND.Cnt = 0.0;								//カウンタ
	ImageTitleEND.CntMAX = IMAGE_END_COMP_CNT_MAX;		    //カウンタMAX
	ImageTitleEND.IsDraw = FALSE;							//描画させない

	//マップの画像を分割する
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//マップのパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//マップを分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip.handle[0]);								//分割した画像が入るハンドル

	if (mapRes == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//マップデータ初期化用に情報をコピー
				mapDatafirstInit[floor][tate][yoko] = mapDatafirst[floor][tate][yoko];

				mapDatasecondInit[floor][tate][yoko] = mapDatasecond[floor][tate][yoko];

				mapDatathirdInit[floor][tate][yoko] = mapDatathird[floor][tate][yoko];

				//マップ1の種類をコピー
				map[floor][tate][yoko].kind = mapDatafirst[floor][tate][yoko];

				//マップ2の種類をコピー
				map2[floor][tate][yoko].kind = mapDatasecond[floor][tate][yoko];

				//マップ2の種類をコピー
				map3[floor][tate][yoko].kind = mapDatathird[floor][tate][yoko];

				//マップの幅と高さをコピー
				map[floor][tate][yoko].width = mapChip.width;
				map[floor][tate][yoko].height = mapChip.height;

				map2[floor][tate][yoko].width = mapChip.width;
				map2[floor][tate][yoko].height = mapChip.height;

				map3[floor][tate][yoko].width = mapChip.width;
				map3[floor][tate][yoko].height = mapChip.height;

				//マップの座標を設定
				map[floor][tate][yoko].x = yoko * map[floor][tate][yoko].width;
				map[floor][tate][yoko].y = tate * map[floor][tate][yoko].height;

				map2[floor][tate][yoko].x = yoko * map2[floor][tate][yoko].width;
				map2[floor][tate][yoko].y = tate * map2[floor][tate][yoko].height;

				map3[floor][tate][yoko].x = yoko * map3[floor][tate][yoko].width;
				map3[floor][tate][yoko].y = tate * map3[floor][tate][yoko].height;
			}
		}
	}

	//マップの当たり判定を設定する
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//マップの当たり判定を設定
				mapColl[floor][tate][yoko].left = (yoko + 0) * mapChip.width + 1;
				mapColl[floor][tate][yoko].top = (tate + 0) * mapChip.height + 1;
				mapColl[floor][tate][yoko].right = (yoko + 1) * mapChip.width - 1;
				mapColl[floor][tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

				mapCollSecond[floor][tate][yoko].left = (yoko + 0) * mapChip.width + 1;
				mapCollSecond[floor][tate][yoko].top = (tate + 0) * mapChip.height + 1;
				mapCollSecond[floor][tate][yoko].right = (yoko + 1) * mapChip.width - 1;
				mapCollSecond[floor][tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

				mapCollThird[floor][tate][yoko].left = (yoko + 0) * mapChip.width + 1;
				mapCollThird[floor][tate][yoko].top = (tate + 0) * mapChip.height + 1;
				mapCollThird[floor][tate][yoko].right = (yoko + 1) * mapChip.width - 1;
				mapCollThird[floor][tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

				//マップの初期状態を設定
				mapCollInit[floor][tate][yoko].left = mapColl[floor][tate][yoko].left;
				mapCollInit[floor][tate][yoko].top = mapColl[floor][tate][yoko].top;
				mapCollInit[floor][tate][yoko].right = mapColl[floor][tate][yoko].right;
				mapCollInit[floor][tate][yoko].bottom = mapColl[floor][tate][yoko].bottom;

				mapCollSecondInit[floor][tate][yoko].left = mapCollSecond[floor][tate][yoko].left;
				mapCollSecondInit[floor][tate][yoko].top = mapCollSecond[floor][tate][yoko].top;
				mapCollSecondInit[floor][tate][yoko].right = mapCollSecond[floor][tate][yoko].right;
				mapCollSecondInit[floor][tate][yoko].bottom = mapCollSecond[floor][tate][yoko].bottom;

				mapCollThirdInit[floor][tate][yoko].left = mapCollThird[floor][tate][yoko].left;
				mapCollThirdInit[floor][tate][yoko].top = mapCollThird[floor][tate][yoko].top;
				mapCollThirdInit[floor][tate][yoko].right = mapCollThird[floor][tate][yoko].right;
				mapCollThirdInit[floor][tate][yoko].bottom = mapCollThird[floor][tate][yoko].bottom;

			}
		}
	}

	return TRUE;
}

//画像をまとめて削除する関数
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageTitleBK.handle);           //タイトル背景削除
	DeleteGraph(ImageTitleROGO.image.handle);   //タイトルロゴ削除
	DeleteGraph(ImageTitleSTART.image.handle);  //タイトル文字削除
	DeleteGraph(ImageEndCOMP.image.handle);     //エンドコンプロゴ削除
	DeleteGraph(ImageTitleEND.image.handle);     //エンドタイトル削除
	DeleteGraph(ImageBack.handle);              //プレイ背景削除
	DeleteGraph(player_A.image.handle);           //プレイヤーA画像削除
	DeleteGraph(player_B.image.handle);           //プレイヤーB画像削除
	DeleteGraph(enemy_1.image.handle);           //敵1画像削除
	DeleteGraph(enemy_2.image.handle);           //敵2画像削除
	DeleteGraph(enemy_3.image.handle);           //敵3画像削除

	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }

	return;
}

//音楽をまとめて読み込む関数
BOOL MY_LOAD_MUSIC(VOID)
{
	//プレイ画面のBGM
	strcpy_s(BGM.path, MUSIC_BGM_PATH);
	BGM.handle = LoadSoundMem(BGM.path);
	if (BGM.handle == -1) {
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトルのBGM
	strcpy_s(BGM_TITLE.path, MUSIC_BGM_TITLE_PATH);				//パスの設定
	BGM_TITLE.handle = LoadSoundMem(BGM_TITLE.path);			//読み込み
	if (BGM_TITLE.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_TITLE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//コンプリートBGM
	strcpy_s(BGM_COMP.path, MUSIC_BGM_COMP_PATH);				//パスの設定
	BGM_COMP.handle = LoadSoundMem(BGM_COMP.path);				//読み込み
	if (BGM_COMP.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//ゲームオーバーBGM
	strcpy_s(BGM_FAIL.path, MUSIC_BGM_FAIL_PATH);				//パスの設定
	BGM_FAIL.handle = LoadSoundMem(BGM_FAIL.path);				//読み込み
	if (BGM_FAIL.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_FAIL_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//攻撃音
	strcpy_s(SE_ATACK.path, MUSIC_SE_ATACK_PATH);				//パスの設定
	SE_ATACK.handle = LoadSoundMem(SE_ATACK.path);				//読み込み
	if (SE_ATACK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_SE_ATACK_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//スイッチ音
	strcpy_s(SE_SWITCH.path, MUSIC_SE_SWITCH_PATH);				//パスの設定
	SE_SWITCH.handle = LoadSoundMem(SE_SWITCH.path);				//読み込み
	if (SE_SWITCH.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_SE_SWITCH_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//鍵入手音
	strcpy_s(SE_KEY.path, MUSIC_SE_KEY_PATH);				//パスの設定
	SE_KEY.handle = LoadSoundMem(SE_KEY.path);				//読み込み
	if (SE_KEY.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_SE_KEY_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//武器入手音
	strcpy_s(SE_WEAPON.path, MUSIC_SE_WEAPON_PATH);				//パスの設定
	SE_WEAPON.handle = LoadSoundMem(SE_WEAPON.path);				//読み込み
	if (SE_WEAPON.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_SE_WEAPON_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//音楽をまとめて削除する関数
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);

	return;
}

//フォントをこのソフト用に、一時的にインストール
BOOL MY_FONT_INSTALL_ONCE(VOID)
{
	//フォントを一時的に読み込み(WinAPI)
	if (AddFontResourceEx(FONT_Pixel_PATH, FR_PRIVATE, NULL) == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), FONT_Pixel_NAME, FONT_INSTALL_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//フォントをこのソフト用に、一時的にアンインストール
VOID MY_FONT_UNINSTALL_ONCE(VOID)
{
	//一時的に読み込んだフォントを削除(WinAPI)
	RemoveFontResourceEx(FONT_Pixel_PATH, FR_PRIVATE, NULL);

	return;
}

BOOL MY_FONT_CREATE(VOID)
{
	//↓↓↓ピクセルフォントを作成↓↓↓

	//フォントデータを作成
	strcpy_s(FontPixel32.path, sizeof(FontPixel32.path), FONT_Pixel_PATH);	//パスをコピー
	strcpy_s(FontPixel32.name, sizeof(FontPixel32.name), FONT_Pixel_NAME);	//フォント名をコピー
	FontPixel32.handle = -1;								//ハンドルを初期化
	FontPixel32.size = 128;								//サイズは32
	FontPixel32.bold = 1;								//太さ1
	FontPixel32.type = DX_FONTTYPE_ANTIALIASING_EDGE;	//アンチエイリアシング付きのフォント

	//フォントハンドル作成
	FontPixel32.handle = CreateFontToHandle(FontPixel32.name, FontPixel32.size, FontPixel32.bold, FontPixel32.type);
	//フォントハンドル作成できないとき、エラー
	if (FontPixel32.handle == -1) { MessageBox(GetMainWindowHandle(), FONT_Pixel_NAME, FONT_CREATE_ERR_TITLE, MB_OK); return FALSE; }

	//↑↑↑ピクセルフォントを作成↑↑↑

	return TRUE;
}

//フォントを削除する関数
VOID MY_FONT_DELETE(VOID)
{
	//フォントデータを削除
	DeleteFontToHandle(FontPixel32.handle);	//フォントのハンドルを削除

	return;
}

//マップとプレイヤーの当たり判定をする関数
int MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int floor = 0; floor <= GAME_FLOOR_MAX - 1; floor++)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ステージ１だった場合
				if (st_check == 1)
				{
					//プレイヤーとマップが当たっているとき
					if (MY_CHECK_RECT_COLL(player, mapColl[floor][tate][yoko]) == TRUE)
					{
						//通路の時
						if (map[fl_check][tate][yoko].kind == t) { return TRUE_t; }

						//壁の時
						if (map[fl_check][tate][yoko].kind == k) { return TRUE_k; }

						//ギミック1の時
						if (map[fl_check][tate][yoko].kind == m1) { return TRUE_m1; }

						//ギミック2の時
						if (map[fl_check][tate][yoko].kind == m2) { return TRUE_m2; }

						//ギミック3の時
						if (map[fl_check][tate][yoko].kind == m3) { return TRUE_m3; }

						//ギミック4の時
						if (map[fl_check][tate][yoko].kind == m4) { return TRUE_m4; }

						//エネミー壁1の時
						if (map[fl_check][tate][yoko].kind == k1) { return TRUE_k1; }

						//エネミー壁2の時
						if (map[fl_check][tate][yoko].kind == k2) { return TRUE_k2; }

						//エネミー壁3の時
						if (map[fl_check][tate][yoko].kind == k3) { return TRUE_k3; }

						//スイッチ1の時
						if (map[fl_check][tate][yoko].kind == s1) { return TRUE_s1; }

						//スイッチ2の時
						if (map[fl_check][tate][yoko].kind == s2) { return TRUE_s2; }

						//スイッチ3の時
						if (map[fl_check][tate][yoko].kind == s3) { return TRUE_s3; }

						//スイッチ4の時
						if (map[fl_check][tate][yoko].kind == s4) { return TRUE_s4; }

						//鍵の時
						if (map[fl_check][tate][yoko].kind == ki) { return TRUE_ki; }

						//鍵扉の時
						if (map[fl_check][tate][yoko].kind == kl) { return TRUE_kl; }

						//剣の時
						if (map[fl_check][tate][yoko].kind == br) { return TRUE_br; }

						//槍の時
						if (map[fl_check][tate][yoko].kind == sp) { return TRUE_sp; }

						//杖の時
						if (map[fl_check][tate][yoko].kind == ca) { return TRUE_ca; }

						//プレイヤーA用のゴールの時
						if (map[fl_check][tate][yoko].kind == ag) { return TRUE_ag; }

						//プレイヤーB用のゴールの時
						if (map[fl_check][tate][yoko].kind == bg) { return TRUE_bg; }

						//階段の時
						if (map[fl_check][tate][yoko].kind == st) { return TRUE_st; }

						//ワープ入口１の時
						if (map[fl_check][tate][yoko].kind == w1) { return TRUE_w1; }

						//ワープ入口２の時
						if (map[fl_check][tate][yoko].kind == w2) { return TRUE_w2; }
					}
				}
				//ステージ２だった場合
				else if (st_check == 2)
				{
					//プレイヤーとマップが当たっているとき
					if (MY_CHECK_RECT_COLL(player, mapCollSecond[floor][tate][yoko]) == TRUE)
					{
						//通路の時
						if (map2[fl_check][tate][yoko].kind == t) { return TRUE_t; }

						//壁の時
						if (map2[fl_check][tate][yoko].kind == k) { return TRUE_k; }

						//ギミック1の時
						if (map2[fl_check][tate][yoko].kind == m1) { return TRUE_m1; }

						//ギミック2の時
						if (map2[fl_check][tate][yoko].kind == m2) { return TRUE_m2; }

						//ギミック3の時
						if (map2[fl_check][tate][yoko].kind == m3) { return TRUE_m3; }

						//ギミック4の時
						if (map2[fl_check][tate][yoko].kind == m4) { return TRUE_m4; }

						//エネミー壁1の時
						if (map2[fl_check][tate][yoko].kind == k1) { return TRUE_k1; }

						//エネミー壁2の時
						if (map2[fl_check][tate][yoko].kind == k2) { return TRUE_k2; }

						//エネミー壁3の時
						if (map2[fl_check][tate][yoko].kind == k3) { return TRUE_k3; }

						//スイッチ1の時
						if (map2[fl_check][tate][yoko].kind == s1) { return TRUE_s1; }

						//スイッチ2の時
						if (map2[fl_check][tate][yoko].kind == s2) { return TRUE_s2; }

						//スイッチ3の時
						if (map2[fl_check][tate][yoko].kind == s3) { return TRUE_s3; }

						//スイッチ4の時
						if (map2[fl_check][tate][yoko].kind == s4) { return TRUE_s4; }

						//鍵の時
						if (map2[fl_check][tate][yoko].kind == ki) { return TRUE_ki; }

						//鍵扉の時
						if (map2[fl_check][tate][yoko].kind == kl) { return TRUE_kl; }

						//剣の時
						if (map2[fl_check][tate][yoko].kind == br) { return TRUE_br; }

						//槍の時
						if (map2[fl_check][tate][yoko].kind == sp) { return TRUE_sp; }

						//杖の時
						if (map2[fl_check][tate][yoko].kind == ca) { return TRUE_ca; }

						//プレイヤーA用のゴールの時
						if (map2[fl_check][tate][yoko].kind == ag) { return TRUE_ag; }

						//プレイヤーB用のゴールの時
						if (map2[fl_check][tate][yoko].kind == bg) { return TRUE_bg; }

						//階段の時
						if (map2[fl_check][tate][yoko].kind == st) { return TRUE_st; }

						//ワープ入口１の時
						if (map2[fl_check][tate][yoko].kind == w1) { return TRUE_w1; }

						//ワープ入口２の時
						if (map2[fl_check][tate][yoko].kind == w2) { return TRUE_w2; }
					}
				}
				//ステージ３だった場合
				else if (st_check == 3)
				{
					//プレイヤーとマップが当たっているとき
					if (MY_CHECK_RECT_COLL(player, mapCollThird[floor][tate][yoko]) == TRUE)
					{
						//通路の時
						if (map3[fl_check][tate][yoko].kind == t) { return TRUE_t; }

						//壁の時
						if (map3[fl_check][tate][yoko].kind == k) { return TRUE_k; }

						//ギミック1の時
						if (map3[fl_check][tate][yoko].kind == m1) { return TRUE_m1; }

						//ギミック2の時
						if (map3[fl_check][tate][yoko].kind == m2) { return TRUE_m2; }

						//ギミック3の時
						if (map3[fl_check][tate][yoko].kind == m3) { return TRUE_m3; }

						//ギミック4の時
						if (map3[fl_check][tate][yoko].kind == m4) { return TRUE_m4; }

						//エネミー壁1の時
						if (map3[fl_check][tate][yoko].kind == k1) { return TRUE_k1; }

						//エネミー壁2の時
						if (map3[fl_check][tate][yoko].kind == k2) { return TRUE_k2; }

						//エネミー壁3の時
						if (map3[fl_check][tate][yoko].kind == k3) { return TRUE_k3; }

						//スイッチ1の時
						if (map3[fl_check][tate][yoko].kind == s1) { return TRUE_s1; }

						//スイッチ2の時
						if (map3[fl_check][tate][yoko].kind == s2) { return TRUE_s2; }

						//スイッチ3の時
						if (map3[fl_check][tate][yoko].kind == s3) { return TRUE_s3; }

						//スイッチ4の時
						if (map3[fl_check][tate][yoko].kind == s4) { return TRUE_s4; }

						//鍵の時
						if (map3[fl_check][tate][yoko].kind == ki) { return TRUE_ki; }

						//鍵扉の時
						if (map3[fl_check][tate][yoko].kind == kl) { return TRUE_kl; }

						//剣の時
						if (map3[fl_check][tate][yoko].kind == br) { return TRUE_br; }

						//槍の時
						if (map3[fl_check][tate][yoko].kind == sp) { return TRUE_sp; }

						//杖の時
						if (map3[fl_check][tate][yoko].kind == ca) { return TRUE_ca; }

						//プレイヤーA用のゴールの時
						if (map3[fl_check][tate][yoko].kind == ag) { return TRUE_ag; }

						//プレイヤーB用のゴールの時
						if (map3[fl_check][tate][yoko].kind == bg) { return TRUE_bg; }

						//階段の時
						if (map3[fl_check][tate][yoko].kind == st) { return TRUE_st; }

						//ワープ入口１の時
						if (map3[fl_check][tate][yoko].kind == w1) { return TRUE_w1; }

						//ワープ入口２の時
						if (map3[fl_check][tate][yoko].kind == w2) { return TRUE_w2; }
					}
				}
			}
		}
	}

	return FALSE;
}

//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top 
		)
	{
		return TRUE;  //当たっている
	}

	return FALSE;     //当たっていない
}