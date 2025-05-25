#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
포켓몬 rpg
데미지: (3*공격 종족값 + 기술의 위력)/50 * 상성값
lv 1업마다 공격력 1.7% 체력 2%
n레벨에서n+1레벨로 오를 때 필요하 exp의 양은 200*(1+ (체력 + 공격력)*0.0003)^n이다.
locId : 내 위치표시
locList: 위치목록
0. 집
1.광장
2. 태초마을 포켓몬센터
3.태초마을 상점
4.태초의 나무숲
5.태초의 갈대숲
6.태초마을 불타입 체육관
7.태초마을 풀타입 체육관
8.태초마을 물타입 체육관
9.신오지방역
10.신오지방 포켓몬센터
11.신오지방 상점
12.신오의 나무숲
13.신오의 갈대숲
14.시간의방
15. 공간의방
16.시간과 공간의방
17.신오지방 바위타입 체육관
18.신오지방 에스퍼 타입 체육관
19.신오지방 페어리 타입 체육관

item list 내가 가지고있는 아이템목록
*/
int square(double a, int b) {
	double c = 1;
	for (int i = 0; b > i; i++) {
		c = c * a;
	}
	return c;
}

typedef struct Poketmon {
	char name[20];
	int atk;
	int hp;
	int nhp;
	int lv;
	int exp;
	int nexp;
}Pkm;

typedef struct _origin {
	char name[20];
	int atk;
	int hp;
	int exp;
} Origin;
typedef struct _user {
	char name[40];
	int bag[50];
	Pkm myPkm[6];
	int locId;

}User;

int** initMap() {
	int m[9][9] = {0};
	m[0][1] = 1;
	m[2][1] = 1;
	m[3][1] = 1;
	m[4][1] = 1;
	m[5][1] = 1;
	m[6][1] = 1;
	m[7][1] = 1;
	m[8][1] = 1;
	m[0][1] = 1;
	m[1][0] = 1;
	m[1][2] = 1;
	m[1][3] = 1;
	m[1][4] = 1;
	m[1][5] = 1;
	m[1][6] = 1;
	m[1][7] = 1;
	m[1][8] = 1;
	m[4][2] = 1;
	m[5][2] = 1;
	m[6][2] = 1;
	m[7][2] = 1;
	m[8][2] = 1;
	
	return m;
};
char* getMapName(int m) {
	switch (m) {
	case 0:
		return "집";
		break;
	case 1:
		return "광장";
		break;
	case 2:
		return "태초마을 포켓몬센터";
		break;
	case 3:
		return "태초마을 상점";
		break;
	case 4:
		return "태초마을 나무숲";
		break;
	case 5:
		return "태초마을 갈대숲";
		break;
	case 6:
		return "태초마을 불타입 체육관";
		break;
	case 7:
		return "태초마을 풀타입 체육관";
		break;
	case 8:
		return "태초마을 물타입 체육관";
		break;
	default:
		return "잘못된 입력입니다.";
	}
}
typedef struct _map {
	int data[9][9];
} Map;
Pkm newPoketmon(int a, Origin O) {
	Pkm empty;
	empty.lv = a;
	empty.atk = O.atk * square(1.017, a);
	empty.hp = O.hp * square(1.02, a);
	empty.exp = O.exp * square(1.023, a);
}
void scan(const char* s, char* to) {
	rewind(stdin);
	scanf(s, to);
	rewind(stdin);
}

void poketmoninfo(struct Poketmon* p) {
	printf("name:%s\nHP:%d", p->name, p->hp);
}
void startingSeen(char* _id) {
	char qa;
	printf("당신의 이름은? \n:");
	scan("%s", _id);
	printf("오박사:%s! 오랜만이구나!\n 모험을 시작할 준비가 되었니?\n", _id);
	if (ynSelect() == 1) {
		printf("오박사: 오늘의 포켓몬은 뭘까요?\n...%s, 내일 와줄 수 없겠니? \n남아있는 포켓몬이 피카츄밖에 없구나 n/n\n", _id);
	}
	else {
		printf("오박사: 하하! 부끄럽기는! \n 사양말고 자 그럼 %s,오늘의 포켓몬은 뭘까요?\n...%s, 내일 와줄 수 없겠니? \n남아있는 포켓몬이 피카츄밖에 없구나\n n/n\n", _id, _id);

	}
	scan("%c", &qa);
	printf("오박사: 흠... 그렇다면 어쩔 수 없구나. 자, 받으렴\n     신난다! 피카츄가 담긴 몬스터볼을 받았다!\n");
	scan("%c", &qa);
	printf("눈을 떠보니 침대였다. 역시 박사님의 마취총은 굉장해!\n 자, 그럼 여행을 시작해볼까?\n");
}
int select(const char* options[], int n) {
	//첫번째 경우  = 1;
	for (int i = 1; i < n + 1; i++) {
		printf("%d. %s\n", i, options[i-1]);
	}
	int answer;
	scanf("%d", &answer);
	if (answer < 1 || answer > n) {
		printf("잘못 입력하셨습니다. 다시 입력하세요\n");
		return select(options, n);
	}
	return answer;
}
int ynSelect() {
	const char* option[2];
	option[0] = "Yes";
	option[1] = "No";
	return select(option, 2);
}
int goArea(int loc) {
	const char* citys[2];
	citys[0] = "태초마을";
	citys[1] = "신오지방";
	int answer;
	answer = select(citys, 2);
	printf("'''''''''''' %s으로 가는 중'''''''''''''\n", citys[answer - 1]);
	return answer;
}
int menu() {
	const char* act[4];
	act[0] = "포켓몬";
	act[1] = "가방";
	act[2] = "이동";
	act[3] = "종료";
	int answer;
	answer = select(act, 4);
	return answer;
}
void defineOrigin() {
	Origin pikachu;
	pikachu.atk = 28;
	pikachu.hp = 120;
	pikachu.exp = 4;

	Origin eve;
	eve.atk = 26;
	eve.hp = 105;
	eve.exp = 1;
	strcpy(eve.name, "");

	Origin Arceus;
	Arceus.atk = 108;
	Arceus.hp = 318;
	Arceus.exp = 1;

	Origin Charmander;
	Charmander.atk = 38;
	Charmander.hp = 122;
	Charmander.exp = 1;

	Origin Bulbasaur;
	Bulbasaur.atk = 26;
	Bulbasaur.hp = 134;
	Bulbasaur.exp = 1;

	Origin Blastoise;
	Blastoise.atk = 36;
	Blastoise.hp = 118;
	Blastoise.exp = 1;

	Origin Nidoran;
	Nidoran.atk = 30;
	Nidoran.hp = 130;
	Nidoran.exp = 1;

	Origin Poliwag;
	Poliwag.atk = 10;
	Poliwag.hp = 50;
	Poliwag.exp = 1;

	Origin Bellsprout;
	Bellsprout.atk = 50;
	Bellsprout.hp = 65;
	Bellsprout.exp = 1;

 }
void myPkm() {
	printf("나의 포켓몬정보가 출력");
}
void myBag() {
	printf("내 가방의 정보가 출력");
}
void movement() {
	printf("같은 지방으로만 갈 수 있다");
}
int main() {
	char id[15];

	printf("모든 답변은 1(yes)혹은 2(no)로만 할 수 있으며 다음전개로 갈때에는 엔터키를 누르셔야합니다.\n");
	Pkm pikachu;
	pikachu.atk = 28;
	pikachu.hp = 120;
	pikachu.lv = 1;
	strcpy(pikachu.name, "pikachu");


	//poketmoninfo(&pikachu);

	startingSeen(id);//아이디를 저장한다.
	int loc;
	loc = goArea();

	int pick = menu();
	if (pick == 1) {
		myPkm();
	}
	else if (pick == 2) {
		myBag();
	}
	else if (pick == 3) {
		movement();
	}
	else if (pick == 4) {
		printf("엔터키를 누르면 게임이 종료됩니다");
		getchar();
		return 0;
	}
	
	struct Poketmon eve;
	eve.atk = 26;
	eve.hp = 105;
	eve.lv = 1;
	strcpy(eve.name, "");

	struct Poketmon Arceus;
	Arceus.atk = 108;
	Arceus.hp = 318;
	Arceus.lv = 1;

	struct Poketmon Charmander;
	Charmander.atk = 38;
	Charmander.hp = 122;
	Charmander.lv = 1;

	struct Poketmon Bulbasaur;
	Bulbasaur.atk = 26;
	Bulbasaur.hp = 134;
	Bulbasaur.lv = 1;

	struct Poketmon Blastoise;
	Blastoise.atk = 36;
	Blastoise.hp = 118;
	Blastoise.lv = 1;

	struct Poketmon Nidoran;
	Nidoran.atk = 30;
	Nidoran.hp = 130;
	Nidoran.lv = 1;

	struct Poketmon Poliwag;
	Poliwag.atk = 10;
	Poliwag.hp = 50;
	Poliwag.lv = 1;

	struct Poketmon Bellsprout;
	Bellsprout.atk = 50;
	Bellsprout.hp = 65;
	Bellsprout.lv = 1;
	
	return 0;
}