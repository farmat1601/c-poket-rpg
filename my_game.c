#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
���ϸ� rpg
������: (3*���� ������ + ����� ����)/50 * �󼺰�
lv 1������ ���ݷ� 1.7% ü�� 2%
n��������n+1������ ���� �� �ʿ��� exp�� ���� 200*(1+ (ü�� + ���ݷ�)*0.0003)^n�̴�.

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
	printf("����� �̸���? \n:");
	scan("%s", _id);
	printf("���ڻ�:%s! �������̱���!\n ������ ������ �غ� �Ǿ���?\n", _id);
	if (ynSelect() == 1) {
		printf("���ڻ�: ������ ���ϸ��� �����?\n...%s, ���� ���� �� ���ڴ�? \n�����ִ� ���ϸ��� ��ī��ۿ� ������ n/n\n", _id);
	}
	else {
		printf("���ڻ�: ����! �β������! \n ��縻�� �� �׷� %s,������ ���ϸ��� �����?\n...%s, ���� ���� �� ���ڴ�? \n�����ִ� ���ϸ��� ��ī��ۿ� ������\n n/n\n", _id, _id);

	}
	scan("%c", &qa);
	printf("���ڻ�: ��... �׷��ٸ� ��¿ �� ������. ��, ������\n     �ų���! ��ī�� ��� ���ͺ��� �޾Ҵ�!\n");
	scan("%c", &qa);
	printf("���� ������ ħ�뿴��. ���� �ڻ���� �������� ������!\n ��, �׷� ������ �����غ���?\n");
}
int select(const char* options[], int n) {
	//ù��° ���  = 1;
	for (int i = 1; i < n + 1; i++) {
		printf("%d. %s\n", i, options[i-1]);
	}
	int answer;
	scanf("%d", &answer);
	if (answer < 1 || answer > n) {
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���\n");
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
int goArea() {
	const char* citys[2];
	citys[0] = "���ʸ���";
	citys[1] = "�ſ�����";
	int answer;
	answer = select(citys, 2);
	printf("'''''''''''' %s���� ���� ��'''''''''''''", citys[answer - 1]);
	return answer;
}
int menu() {
	const char* act[4];
	act[0] = "���ϸ�";
	act[1] = "����";
	act[2] = "�̵�";
	act[3] = "����";
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
int main() {
	char id[15];

	printf("��� �亯�� 1(yes)Ȥ�� 2(no)�θ� �� �� ������ ���������� �������� ����Ű�� �����ž��մϴ�.\n");
	Pkm pikachu;
	pikachu.atk = 28;
	pikachu.hp = 120;
	pikachu.lv = 1;
	strcpy(pikachu.name, "pikachu");


	//poketmoninfo(&pikachu);

	startingSeen(id);//���̵� �����Ѵ�.
	int loc;
	loc = goArea();

	int pick = menu();
	if (pick == 1) {
		rvis
	};
	
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