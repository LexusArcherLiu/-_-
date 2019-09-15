//ͼ�ο�Ļ������
#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

extern char dialog_first[12][100];
extern char dialog_second[11][100];
extern char Ending_dialogue[9][100];
extern int StartScan();
extern int Dialogue1(IMAGE bg);
extern int Dialogue3(IMAGE bg);
extern int Dialogue5(IMAGE bg);
int length1 = sizeof(dialog_first) / sizeof(dialog_first[0]);
int length3 = sizeof(dialog_second) / sizeof(dialog_second[0]);
int length5 = sizeof(Ending_dialogue) / sizeof(Ending_dialogue[0]);
extern void writefile1(int map[13][13]);
extern int **readfile1();
extern void writefile2(int map[13][13]);
extern int **readfile2();
HWND hwnd;//��ȡ���ھ���
int property = 0;

int map_floorOne[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 9, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 8, 1, 1, 16, 1, 0, 5, 6, 1, 0, 1, 0 },
	{ 0, 1, 12, 1, 0, 1, 0, 4, 8, 1, 0, 1, 0 },
	{ 0, 0, 16, 0, 0, 1, 0, 0, 0, 16, 0, 1, 0 },
	{ 0, 6, 1, 1, 0, 1, 16, 10, 11, 10, 0, 1, 0 },
	{ 0, 1, 13, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 16, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 0, 16, 0, 0, 0, 16, 0, 0 },
	{ 0, 8, 1, 6, 0, 6, 1, 6, 0, 1, 10, 1, 0 },
	{ 0, 8, 1, 6, 0, 1, 18, 1, 0, 2, 14, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int map_init[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 19, 0, 22, 0, 20, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0 }
};
int map_floorFin[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 21, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 21, 21, 21, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 21, 21, 23, 21, 21, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 21, 21, 21, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 21, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 0 },
	{ 0, 24, 24, 24, 24, 24, 24, 24, 24, 24, 26, 24, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int map_floorSword[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 21, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 24, 0, 24, 0, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 19, 0, 1, 1, 1, 1, 0 },
	{ 0, 21, 1, 1, 0, 24, 17, 24, 0, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 21, 1, 1, 21, 1, 0 },
	{ 0, 1, 21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 21, 1, 1, 1, 18, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int map_floorShield[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 21, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 24, 0, 24, 0, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 20, 0, 1, 1, 1, 1, 0 },
	{ 0, 21, 1, 1, 0, 24, 17, 24, 0, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 21, 1, 1, 21, 1, 0 },
	{ 0, 1, 21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 1, 21, 1, 1, 1, 25, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

IMAGE wall, Floor, gslime, rslime, bcrystal, rcrystal, bkey, ykey, lrpotion, lbpotion
, ladder, lbat, lwizard, bskeleton, skeleton, bdoor, ydoor, irondoor, actor, message, background,sword
, shield, boss_inside, boss_outside, boss_final,logo,dialogue1,dialogue2, dialogue5, actor1,actor2;

char str[20] = "";


void LogIn() {
	putimage(0, 0, &background);
	setbkmode(TRANSPARENT);//����͸������
	settextstyle(60, 0, "��������");
	outtextxy(60 * 5, 60 * 6, "��¥�С�������");
	setcolor(RED);
	settextstyle(20, 0, "��������");
	outtextxy(60 * 4, 60 * 10, "ע�����¥�ݵķ���һ��������о�ϲ");
	settextstyle(30, 0, "��������");
	outtextxy(60 * 3, 60 * 12, "������������Ԩ��ʱ��,��ԨҲ����������");
	setcolor(WHITE);
	settextstyle(12, 0, "��������");
}

void excessive0() {
	putimage(0, 0, &background);
	setbkmode(TRANSPARENT);//����͸������
	settextstyle(60, 0, "��������");
	outtextxy(60 * 5, 60 * 6, "������......");
	setcolor(WHITE);
	settextstyle(12, 0, "��������");
}

void excessive1() {
	putimage(0, 0, &background);
	setbkmode(TRANSPARENT);//����͸������
	settextstyle(50, 0, "��������");
	outtextxy(60 * 1, 60 * 6, "���������㣬��������ȥ�˺ܾ�......");
	setcolor(RED);
	settextstyle(30, 0, "��������");
	outtextxy(60 * 5, 60 * 12, "���ڵ������һ��");
	setcolor(WHITE);
	settextstyle(12, 0, "��������");
}

struct gameRole {
	char actorName[20];
	int blood;
	int magic;
	int defense;
	int attact;
	int blueKey;
	int yelloKey;
	int level;
	int experience;
	int status;
}role;

struct monster {
	int blood;
	int attack;
	int defense;
	int experience;
};

//����ͬ�Ĺ����ʼ�� 
struct monster Mgslime = { 50,10,12,100 };
struct monster Mrslime = { 150,50,12,500 };
struct monster Mlbat = { 100,30,9,400 };
struct monster Mlwizard = { 20,10,9,50 };
struct monster Mbskeleton = { 200,80,20,800 };
struct monster Mskeleton = { 150,60,15,600 };
struct monster Boss_inside = { 1500,600,150,6000 };
struct monster Boss_final = { 15000,6000,1500,60000 };

struct medicine
{
	int sign;	//�������
	int add;
};

struct medicine Mlrpotiop = { 0,100 };

struct medicine Mlbpotion = { 1,100 };

void createUser()
{
	printf("\t\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");
	printf("\t\t\t��                          *��Ϸ*                       ��\n");
	printf("\t\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("\t\t\t������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*     ��ɫ�趨    *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
	printf("\t\t\t������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t�������ɫ��������");
	scanf_s("%s", role.actorName, 20);
	role.level = 0;
	role.defense = 30;
	role.attact = 50;
	role.yelloKey = 0;
	role.blueKey = 0;
	role.blood = 500;
	role.magic = 250;
	role.status = 18;
	role.experience = 0;
}

void menu_select() //�˵�ѡ��ϵͳ����  
{
	char c;
	do {
		system("cls");  
		printf("\n");
		printf("\t\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");
		printf("\t\t\t��                          *��Ϸ*                       ��\n");
		printf("\t\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
		printf("\t\t\t������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*    1,��ɫ�趨   *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*    2,������Ϸ   *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t��*-*-*-*-*-*-*-*-*-*                 *-*-*-*-*-*-*-*-*-*��\n");
		printf("\t\t\t������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t����ѡ��(1,2):");
		c = getchar();
	} while (c<'0' || c>'3');
	if (c - '0' == 1)//�ַ���ȥ'0'�õ�������������//  
	{
		system("cls");
		createUser();
	}
	else {
		printf("\t\t\tû���ý�ɫ�����޷���ʼ����ɫ��Ϣ");
		Sleep(1000);
		//system("cls");
		menu_select();
	}
}

void loadResourse() {
	loadimage(&wall, "�ز�/ǽ.jpg", 60, 60);
	loadimage(&Floor, "�ز�/�ذ�.jpg", 60, 60);
	loadimage(&gslime, "�ز�/��ʷ��ķ.jpg", 60, 60);
	loadimage(&rslime, "�ز�/��ʷ��ķ.jpg", 60, 60);
	loadimage(&bcrystal, "�ز�/��ˮ��.jpg", 60, 60);
	loadimage(&rcrystal, "�ز�/��ˮ��.jpg", 60, 60);
	loadimage(&bkey, "�ز�/��Կ��.jpg", 60, 60);
	loadimage(&ykey, "�ز�/��Կ��.jpg", 60, 60);
	loadimage(&lrpotion, "�ز�/С��ҩˮ.jpg", 60, 60);
	loadimage(&lbpotion, "�ز�/С��ҩˮ.jpg", 60, 60);
	loadimage(&ladder, "�ز�/����.jpg", 60, 60);
	loadimage(&lbat, "�ز�/С����.jpg", 60, 60);
	loadimage(&lwizard, "�ز�/С��ʦ.jpg", 60, 60);
	loadimage(&bskeleton, "�ز�/�����ñ�.jpg", 60, 60);
	loadimage(&skeleton, "�ز�/���ñ�.jpg", 60, 60);
	loadimage(&bdoor, "�ز�/����.jpg", 60, 60);
	loadimage(&ydoor, "�ز�/����.jpg", 60, 60);
	loadimage(&actor, "�ز�/��.jpg", 60, 60);
	loadimage(&irondoor, "�ز�/����.jpg", 60, 60);
	loadimage(&sword, "�ز�/ҹ��֮��.jpg", 60, 60);
	loadimage(&shield, "�ز�/��Ǿޱ֮��.jpg", 60, 60);
	loadimage(&boss_inside, "�ز�/Boss-inside.jpg", 60, 60);
	loadimage(&boss_outside, "�ز�/Boss-outside.jpg", 60, 60);
	loadimage(&boss_final, "�ز�/Boss-final.jpg", 60, 60);
	loadimage(&actor1, "�ز�/actor1.jpg", 60, 60);
	loadimage(&actor2, "�ز�/actor2.jpg", 60, 60);
	loadimage(&logo, "�ز�/logo.jpg", 60, 60);
	loadimage(&background, "�ز�/bg.jpg", 60 * 14, 60 * 13);
	loadimage(&dialogue1, "�ز�/dialogue1.jpg", 60 * 13, 60 * 5);
	loadimage(&dialogue2, "�ز�/dialogue2.jpg", 60 * 13, 60 * 5);
	loadimage(&dialogue5, "�ز�/dialogue5.jpg", 60 * 13, 60 * 5);
	loadimage(&message, "�ز�/��Ϣ.jpg");
}

char* intToWchar(int number)//����ǿ��ת�� ֻ�ܸ�ʽ��ת�� 
{
	sprintf(str, "%d", number);
	return str;
}

//pk����:---��������ô�����˺�
void bloodPk(struct monster M)
{
	//����+����+�����ʣ���Ϸ����Ȥ��
	role.blood -= M.blood;
	if (role.blood > 0)
		role.experience += M.experience;
	else
	{
		role.experience = 0;
		role.blood = 0;
		int ID = MessageBox(hwnd, "�˱�ɱ���ͻ������������������ǻ��ŵ���һ����ʽ", "�Ƿ��ڣ�", MB_YESNO);//�������Ƿ�ȷ��
		if (ID == IDNO)
		{
			ID = MessageBox(hwnd, "��Ȼ����������������", "To or Not To BE", MB_OK);
			putimage(0, 0, &background);
			setbkmode(TRANSPARENT);//����͸������
			settextstyle(60, 0, "��������");
			outtextxy(60 * 5, 60 * 6, "�����������£���������һ���ֻذ���");
			settextstyle(30, 0, "��������");
			outtextxy(60 * 4, 60 * 10, "ʱ����ת��Ը���������֮����������");
			settextstyle(12, 0, "��������");
			Sleep(3000);
			closegraph();
		}
		else {
			closegraph();
		}
	}
}

//void init_map_floorOneGameUI()
void init_mapGameUI(int map[13][13])
{
	int i, j;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			switch (map[i][j])
			{
			case 0:
				putimage(j * 60, i * 60, &wall);
				break;
			case 1:
				putimage(j * 60, i * 60, &Floor);
				break;
			case 2:
				putimage(j * 60, i * 60, &gslime);
				break;
			case 3:
				putimage(j * 60, i * 60, &rslime);
				break;
			case 4:
				putimage(j * 60, i * 60, &bcrystal);
				break;
			case 5:
				putimage(j * 60, i * 60, &rcrystal);
				break;
			case 6:
				putimage(j * 60, i * 60, &bkey);
				break;
			case 7:
				putimage(j * 60, i * 60, &ykey);
				break;
			case 8:
				putimage(j * 60, i * 60, &lrpotion);
				break;
			case 9:
				putimage(j * 60, i * 60, &ladder);
				break;
			case 10:
				putimage(j * 60, i * 60, &lbat);
				break;
			case 11:
				putimage(j * 60, i * 60, &lwizard);
				break;
			case 12:
				putimage(j * 60, i * 60, &skeleton);
				break;
			case 13:
				putimage(j * 60, i * 60, &bskeleton);
				break;
			case 14:
				putimage(j * 60, i * 60, &lbpotion);
				break;
			case 15:
				putimage(j * 60, i * 60, &irondoor);
				break;
			case 16:
				putimage(j * 60, i * 60, &bdoor);
				break;
			case 17:
				putimage(j * 60, i * 60, &ydoor);
				break;
			case 18:
				putimage(j * 60, i * 60, &actor);
				break;
			case 19:
				putimage(j * 60, i * 60, &sword);
				break;
			case 20:
				putimage(j * 60, i * 60, &shield);
				break;
			case 21:
				putimage(j * 60, i * 60, &boss_inside);
				break;
			case 22:
				putimage(j * 60, i * 60, &boss_outside);
				break;
			case 23:
				putimage(j * 60, i * 60, &boss_final);
				break;
			case 24:
				putimage(j * 60, i * 60, &logo);
				break;
			case 25:
				putimage(j * 60, i * 60, &actor1);
				break;
			case 26:
				putimage(j * 60, i * 60, &actor2);
				break;
			}
		}
	}
	putimage(60 * 13, 0, &message);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 12, 100, role.actorName);
	//outtextxy ֻ�ܴ�ӡ�ַ���
	outtextxy(60 * 13 + 12, 180, intToWchar(role.level));
	outtextxy(60 * 13 + 12, 235, intToWchar(role.experience));
	outtextxy(60 * 13 + 12, 362, intToWchar(role.blood));
	outtextxy(60 * 13 + 12, 425, intToWchar(role.magic));
	outtextxy(60 * 13 + 12, 517, intToWchar(role.attact));
	outtextxy(60 * 13 + 12, 567, intToWchar(role.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(role.yelloKey));
	outtextxy(60 * 13 + 12, 759, intToWchar(role.blueKey));
}

//void init_map_initGameUI() {
//	int i, j;
//	for (i = 0; i < 13; i++)
//	{
//		for (j = 0; j < 13; j++)
//		{
//			switch (map_init[i][j])
//			{
//			case 0:
//				putimage(j * 60, i * 60, &wall);
//				break;
//			case 1:
//				putimage(j * 60, i * 60, &floor);
//				break;
//			case 8:
//				putimage(j * 60, i * 60, &lrpotion);
//				break;
//			case 9:
//				putimage(j * 60, i * 60, &ladder);
//				break;
//			case 14:
//				putimage(j * 60, i * 60, &lbpotion);
//				break;
//			case 15:
//				putimage(j * 60, i * 60, &irondoor);
//				break;
//			case 18:
//				putimage(j * 60, i * 60, &actor);
//				break;
//			case 19:
//				putimage(j * 60, i * 60, &sword);
//				break;
//			case 20:
//				putimage(j * 60, i * 60, &shield);
//				break;
//			case 22:
//				putimage(j * 60, i * 60, &boss_outside);
//				break;
//			}
//		}
//	}
//	putimage(60 * 13, 0, &message);
//	setbkmode(TRANSPARENT);
//	outtextxy(60 * 13 + 12, 100, role.actorName);
//	//outtextxy ֻ�ܴ�ӡ�ַ���
//	outtextxy(60 * 13 + 12, 180, intToWchar(role.level));
//	outtextxy(60 * 13 + 12, 235, intToWchar(role.experience));
//	outtextxy(60 * 13 + 12, 362, intToWchar(role.blood));
//	outtextxy(60 * 13 + 12, 425, intToWchar(role.magic));
//	outtextxy(60 * 13 + 12, 517, intToWchar(role.attact));
//	outtextxy(60 * 13 + 12, 567, intToWchar(role.defense));
//	outtextxy(60 * 13 + 12, 689, intToWchar(role.yelloKey));
//	outtextxy(60 * 13 + 12, 759, intToWchar(role.blueKey));
//}
//key_down

bool temp = true;

bool playGame(int map[13][13])
{
	char cUser;			//���������û��İ���
	int i = 0, j = 0;
	while (1)			//��ѭ��ȥ����Ϸ
	{
		//ȷ�������λ�� ----�������е���5���Ǹ��ط������ߵ���8
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 13; j++)
				if (map[i][j] == 18)
					break;
			if (map[i][j] == 18)
				break;
			//����˫��ѭ��
		}
		init_mapGameUI(map);
		cUser = _getch();//ʹ�ò��ɼ�����
		switch (cUser)
		{
			//������ϣ�����ֵ���ϣ�72 �£�80 ��75 �ң�77
			//���
		case 75:	//�����ϵķ����
		case 'a':
		case 'A':
			//������һ�� i��j-1 �ж�����ط��ܲ�����
			//�ܲ�����:�ǿյغ�Ŀ�ĵ�
			if (map[i][j - 1] == 1)
			{
				//ԭ����λ�������ˣ�ֵ-5
				map[i][j] -= 17;//18-17 = 1
				map[i][j - 1] += 17;
			}
			else if (map[i][j - 1] == 6)
			{
				role.blueKey++;//����Կ�ף�
				map[i][j] -= 17;// 18-17=1
				map[i][j - 1] += 12; //6 +? =18
			}
			else if (map[i][j - 1] == 16 && role.blueKey > 0)
			{
				role.blueKey--;
				map[i][j] -= 17;// 18-17=1
				map[i][j - 1] += 2; //16 +? =18
			}
			else if (map[i][j - 1] == 2) {
				int ID = MessageBox(hwnd, "������ʷ��ķ", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Mgslime);
					map[i][j] -= 17;
					map[i][j - 1] += 16;//2 + �� =18
				}
			}
			else if (map[i][j - 1] == 3) {
				int ID = MessageBox(hwnd, "����������ʷ��ķ", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Mrslime);
					map[i][j] -= 17;
					map[i][j - 1] += 15;
				}
			}
			else if (map[i][j - 1] == 10)
			{
				//�������Թ����๥���Ĺ���
				int ID = MessageBox(hwnd, "����С����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Mlbat);
					map[i][j] -= 17;
					map[i][j - 1] += 8;
				}
			}
			else if (map[i][j - 1] == 9) {
				return true;
			}
			return false;
			break;
			//�ұ�
		case 77:
		case 'd':
		case 'D':
			if (map[i][j + 1] == 1)
			{
				map[i][j] -= 17;//18-17 = 1
				map[i][j + 1] += 17;
			}
			else if (map[i][j + 1] == 6)
			{
				role.blueKey++;//����Կ�ף�
				map[i][j] -= 17;// 18-17=1
				map[i][j + 1] += 12; //6 +? =18
			}
			else if (map[i][j + 1] == 16 && role.blueKey > 0)
			{
				role.blueKey--;
				map[i][j] -= 17;// 18-17=1
				map[i][j + 1] += 2; //16 +? =18   
			}
			else if (map[i][j + 1] == 10)
			{
				//�������Թ����๥���Ĺ���
				int ID = MessageBox(hwnd, "����С����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Mlbat);
					map[i][j] -= 17;
					map[i][j + 1] += 8;
				}
			}
			else if (map[i][j + 1] == 9) {
				return true;
			}
			return false;
			break;
			//�ϱ�
		case 72:
		case 'w':
		case 'W':
			if (map[i - 1][j] == 1)
			{
				map[i][j] -= 17;//18-17 = 1
				map[i - 1][j] += 17;
			}
			else if (map[i - 1][j] == 6)
			{
				role.blueKey++;//����Կ�ף�
				map[i][j] -= 17;// 18-17=1
				map[i - 1][j] += 12; //6 +? =18
			}
			else if (map[i - 1][j] == 16 && role.blueKey > 0)
			{
				role.blueKey--;
				map[i][j] -= 17;// 18-17=1
				map[i - 1][j] += 2; //16 +? =18
			}
			else if (map[i - 1][j] == 9) {
				return true;
			}
			return false;
			break;
			//�±�
		case 80:
		case 's':
		case 'S':
			if (map[i + 1][j] == 1)
			{
				map[i][j] -= 17;//18-17 = 1
				map[i + 1][j] += 17;
			}
			else if (map[i + 1][j] == 7)
			{
				role.yelloKey++;//����Կ�ף�
				map[i][j] = 1;// 18-17=1
				map[i + 1][j] = 18; //6 +? =18
			}
			else if (map[i + 1][j] == 6)
			{
				role.blueKey++;//����Կ�ף�
				map[i][j] -= 17;// 18-17=1
				map[i + 1][j] += 12; //6 +? =18
			}
			else if (map[i + 1][j] == 16 && role.blueKey > 0)
			{
				role.blueKey--;
				map[i][j] -= 17;// 18-17=1
				map[i + 1][j] += 2; //16 +? =18
			}
			else if (map[i + 1][j] == 8) {
				role.blood += Mlrpotiop.add;
				map[i][j] -= 17;
				map[i + 1][j] += 10;//8 + ? = 18
			}
			else if (map[i + 1][j] == 14) {
				role.magic += Mlbpotion.add;
				map[i][j] -= 17;
				map[i + 1][j] += 4;//14+ ? =18
			}
			else if (map[i + 1][j] == 22) {
				while (1) {
					if (Dialogue1(dialogue1) == length1) {
						Sleep(1000);
						break;
					}
					else if (Dialogue1(dialogue1) == -1) {
						break;
					}
				}
				Sleep(1000);
				property = StartScan();
				map[i][j] -= 17; //22- =1
				map[i + 1][j] -= 4;//22-4 = 18
				role.attact = role.attact + property * 100;
				role.level = role.level + property * 200;
				role.blood = role.blood + property * 200;
			 	role.defense = role.defense + property * 200;
				role.magic = role.magic + property * 200;
				init_mapGameUI(map);
				while (1) {
					if (Dialogue3(dialogue1) == length3) {
						Sleep(1000);
						break;
					}
					else if (Dialogue3(dialogue1) == -1) {
						break;
					}
				}
				Sleep(1000);
				temp = false;
			}
			else if (map[i + 1][j] == 9) {
				return true;
			}
			return false;
			break;
		case 'q':
			int ID = MessageBox(hwnd, "ȷ���˳���Ϸô��", "��Ϸ�Ƴ�", MB_YESNO);
			if (ID == IDYES) {
				for (int i = 0; i < 10; i++)
					MessageBox(hwnd, "warnning", "wainning", MB_YESNO);
				MessageBox(hwnd, "��Ȼ���������ˣ����������ܣ��Ǹ�ʲô������", "???", MB_YESNO);
			}
			break;
		}
	}
}

void move_monster(int map[13][13], int i , int j , int monsterOrder) {
	srand(time(NULL));
	int RandNum;
	int array[5]= {0};
	int flag = 0, t = 0;
	while (1)
	{
		flag = 0;
		if (t == 5)
			break;
		RandNum = (rand() % (5 - 0)) + 0;
		for (int m = 0; m < t; m++)
		{
			if (array[m] == RandNum)
				flag = 1;
		}
		if (flag != 1)
		{
			array[t] = RandNum;
			t++;
		}
	}
	for (int k = 0; k < 5; k++) {
		switch (array[k])
		{
		case 0:
			return;
		case 1:
			if (map[i - 1][j] == 1)
			{
				map[i][j] = 1;//18-17 = 1
				map[i - 1][j] = monsterOrder;
				return;
			}
		case 2:
			if (map[i + 1][j] == 1)
			{
				map[i][j] = 1;//18-17 = 1
				map[i + 1][j] = monsterOrder;
				return;
			}
		case 3:
			if (map[i][j - 1] == 1)
			{
				//ԭ����λ�������ˣ�ֵ-5
				map[i][j] = 1;//18-17 = 1
				map[i][j - 1] = monsterOrder;
				return;
			}
		case 4:
			if (map[i][j + 1] == 1)
			{
				map[i][j] = 1;//18-17 = 1
				map[i][j + 1] = monsterOrder;
				return;
			}
		}
	}
};

void Seek_monster(int map[13][13], int monsterOrder) {
	int i, j;
	for (i = 0; i < 13; i++){
		for (j = 0; j < 13; j++) {
			if (map[i][j] == monsterOrder) {
				move_monster(map, i, j, monsterOrder);
			}
		}
	}
}

bool playGame_search(int map[13][13]) {
	char cUser;			//���������û��İ���
	int i = 0, j = 0;
	while (1)			//��ѭ��ȥ����Ϸ
	{
		//ȷ�������λ�� ----�������е���5���Ǹ��ط������ߵ���8
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 13; j++)
				if (map[i][j] == 18 || map[i][j] == 25 || map[i][j] == 26)
					break;
			if (map[i][j] == 18 || map[i][j] == 25 || map[i][j] == 26)
				break;
			//����˫��ѭ��
		}
		init_mapGameUI(map);
		cUser = _getch();//ʹ�ò��ɼ�����
		switch (cUser)
		{
			//������ϣ�����ֵ���ϣ�72 �£�80 ��75 �ң�77
			//���
		case 75:	//�����ϵķ����
		case 'a':
		case 'A':
			//������һ�� i��j-1 �ж�����ط��ܲ�����
			//�ܲ�����:�ǿյغ�Ŀ�ĵ�
			if (map[i][j - 1] == 24)
			{
				int ID = MessageBox(hwnd, "���ܵ������������ߵ�����", "�Ƿ�Ҫǿ��ǰȥ", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					role.blood = role.blood - 1000;
					if (role.blood <= 0) {
						MessageBox(hwnd, "���ź������Ѿ�����", "��������", MB_YESNO);
						closegraph();
					}
				}
			}
			else if (map[i][j - 1] == 1 && map[i][j] == 18){
				map[i][j] = 1;//18-17 = 1
				map[i][j - 1] = 18;
			}
			else if (map[i][j - 1] == 1 &&  map[i][j] == 25) {
				map[i][j] = 1;//18-17 = 1
				map[i][j - 1] = 25;
			}
			else if (map[i][j - 1] == 1 &&  map[i][j] == 26) {
				map[i][j] = 1;//18-17 = 1
				map[i][j - 1] = 26;
			}
			else if (map[i][j - 1] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map[i][j] = 1; //18->24
					map[i][j - 1] = role.status;// 21 -> 18
				}
			}
			else if (map[i][j - 1] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map[i][j] = 1;
					map[i][j - 1] = role.status;//23-24
				}
			}
			else if (map[i][j - 1] == 9) {
				return true;
			}
			return false;
			break;
			//�ұ�
		case 77:
		case 'd':
		case 'D':
			if (map[i][j + 1] == 24)
			{
				int ID = MessageBox(hwnd, "���ܵ������������ߵ�����", "�Ƿ�Ҫǿ��ǰȥ", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					role.blood = role.blood - 1000;
					if (role.blood <= 0) {
						MessageBox(hwnd, "���ź������Ѿ�����", "��������", MB_YESNO);
							closegraph();
					}
				}
			}
			else if (map[i][j + 1] == 1 && map[i][j] == 18){
				map[i][j] = 1;//18-17 = 1
				map[i][j + 1] = 18;
			}
			else if (map[i][j + 1] == 1 &&  map[i][j] == 25) {
				map[i][j] = 1;//18-17 = 1
				map[i][j + 1] = 25;
			}
			else if (map[i][j + 1] == 1 &&  map[i][j] == 26) {
				map[i][j] = 1;//18-17 = 1
				map[i][j + 1] = 26;
			}
			else if (map[i][j + 1] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map[i][j] = 1; //18->24
					map[i][j + 1] = role.status;// 21 -> 18
				}
			}
			else if (map[i][j + 1] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map[i][j] = 1;
					map[i][j + 1] = role.status;//23-24
				}
			}
			else if (map[i][j + 1] == 9) {
				return true;
			}
			return false;
			break;
			//�ϱ�
		case 72:
		case 'w':
		case 'W':
			if (map[i - 1][j] == 1  && map[i][j] == 18)
			{
				map[i][j] = 1;//18-17 = 1
				map[i - 1][j] = 18;
			}
			else if (map[i - 1][j] == 1 &&  map[i][j] == 25){
				map[i][j] = 1;//18-17 = 1
				map[i - 1][j] = 25;
			}
			else if (map[i - 1][j] == 1 &&  map[i][j] == 26) {
				map[i][j] = 1;//18-17 = 1
				map[i - 1][j] = 26;
			}
			else if (map[i - 1][j] == 17 && role.yelloKey >= 1)
			{
				map[i][j] = 1;//18-17 = 1
				map[i - 1][j] = role.status;
				role.yelloKey--;
			}
			else if (map[i - 1][j] == 19) {
				map[i - 1][j] = 25;
				role.status = 25;
				map[i][j] = 1;
				role.blood += 10000;
			}
			else if (map[i - 1][j] == 20) {
				role.status = 26;
				map[i - 1][j] = 26;
				map[i][j] = 1;
				role.blood += 10000;
			}
			else if (map[i - 1][j] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map[i][j] = 1; //18->24
					map[i - 1][j] = role.status;// 21 -> 18
				}
			}
			else if (map[i - 1][j] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map[i][j] = 1;
					map[i - 1][j] = role.status;//23-24
				}
			}
			else if (map[i - 1][j] == 9) {
				return true;
			}
			return false;
			break;
			//�±�
		case 80:
		case 's':
		case 'S':
			if (map[i + 1][j] == 1 && map[i][j] == 18)
			{
				map[i][j] = 1;//18-17 = 1
				map[i + 1][j] = 18;
			}
			else if (map[i + 1][j] == 1 && map[i][j] == 25) {
				map[i][j] = 1;//18-17 = 1
				map[i + 1][j] = 25;
			}
			else if (map[i + 1][j] == 1 && map[i][j] == 26) {
				map[i][j] = 1;//18-17 = 1
				map[i + 1][j] = 26;
			}
			else if (map[i + 1][j] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map[i][j] = 1; //18->24
					map[i + 1][j] = role.status;// 21 -> 18
				}
			}
			else if (map[i + 1][j] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map[i][j] = 1;
					map[i + 1][j] = role.status;//23-24
				}
			}
			else if (map[i + 1][j] == 9) {
				return true;
			}
			return false;
			break;
		}
		Seek_monster(map, 21);
	}
}

bool playGame_final() {
	char cUser;			//���������û��İ���
	int i = 0, j = 0;
	while (1)			//��ѭ��ȥ����Ϸ
	{
		//ȷ�������λ�� ----�������е���5���Ǹ��ط������ߵ���8
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 13; j++)
				if (map_floorFin[i][j] == role.status)
					break;
			if (map_floorFin[i][j] == role.status)
				break;
			//����˫��ѭ��
		}
		init_mapGameUI(map_floorFin);
		cUser = _getch();//ʹ�ò��ɼ�����
		switch (cUser)
		{
		case 75:	//�����ϵķ����
		case 'a':
		case 'A':
			if (map_floorFin[i][j - 1] == 24)
			{
				//ԭ����λ�������ˣ�ֵ-5
				map_floorFin[i][j] = 24;//  18-24
				map_floorFin[i][j - 1] = role.status;//24 - 18
			}
			else if (map_floorFin[i][j - 1] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map_floorFin[i][j] = 24; //18->24
					map_floorFin[i][j - 1] = role.status;// 21 -> 18
				}
			}
			else if (map_floorFin[i][j - 1] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map_floorFin[i][j] = 24;
					map_floorFin[i][j - 1] = role.status;//23-24
					role.status = 18;
				}
			}
			return false;
			break;
			//�ұ�
		case 77:
		case 'd':
		case 'D':
			if (map_floorFin[i][j + 1] == 24)
			{
				map_floorFin[i][j] = 24;//18-17 = 1
				map_floorFin[i][j + 1] = role.status;
			}
			else if (map_floorFin[i][j + 1] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map_floorFin[i][j] = 24; //18->24
					map_floorFin[i][j + 1] = role.status;// 21 -> 18
				}
			}
			else if (map_floorFin[i][j + 1] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map_floorFin[i][j] = 24;
					map_floorFin[i][j + 1] = role.status;//23-24
					role.status = 18;
				}
			}
			return false;
			break;
			//�ϱ�
		case 72:
		case 'w':
		case 'W':
			if (map_floorFin[i - 1][j] == 24)
			{
				map_floorFin[i][j] = 24;
				map_floorFin[i - 1][j] = role.status;
			}
			else if (map_floorFin[i - 1][j] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map_floorFin[i][j] = 24; //18->24
					map_floorFin[i - 1][j] = role.status;// 21 -> 18
				}
			}
			else if (map_floorFin[i - 1][j] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map_floorFin[i][j] = 24;
					map_floorFin[i - 1][j] = role.status;//23-24
					role.status = 18;
				}
			}
			return false;
			break;
			//�±�
		case 80:
		case 's':
		case 'S':
			if (map_floorFin[i + 1][j] == 24)
			{
				map_floorFin[i][j] = 24;//18-17 = 1
				map_floorFin[i + 1][j] = role.status;
			}
			else if (map_floorFin[i + 1][j] == 21) {
				int ID = MessageBox(hwnd, "����Boss�Ľ�����", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_inside);
					map_floorFin[i][j] = 24; //18->24
					map_floorFin[i + 1][j] = role.status;// 21 -> 18
				}
			}
			else if (map_floorFin[i + 1][j] == 23) {
				int ID = MessageBox(hwnd, "����Boss", "�Ƿ񹥻�", MB_YESNO);//�������Ƿ�ȷ��
				if (ID == IDYES)
				{
					bloodPk(Boss_final);
					map_floorFin[i][j] = 24;
					map_floorFin[i + 1][j] = role.status;//23-24
					role.status = 18;
				}
			}
			return false;
			break;
		}
		int m;
		int n;
		bool Temp = false;
		for (m = 0; m < 13; m++)
		{
			for (n = 0; n < 13; n++)
				if (map_floorFin[m][n] == 23)
					Temp = true;
		}
		if (Temp == false) {
			while (1) {
				if (Dialogue5(dialogue5) == length5) {
					Sleep(1000);
					break;
				}
				else if (Dialogue5(dialogue5) == -1) {
					break;
				}
			}
			return true;
		}
	}
}