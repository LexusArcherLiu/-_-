#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#define MAXSTAR 100    //ͼƬ������
#define MAXSTAR1 1000  //�������

//����
struct STAR
{
	int x, y;//����
	int step;//�ƶ����ٶ�
	int style; //��ʽ

}star[MAXSTAR];
//�ǿ�

//�ṹ����������洢��ͬ���͵Ķ�������
//���Խ���ͬ���͵���������
struct STAR1
{
	int x, y;
	int step;
	int color;
}star1[MAXSTAR1];

IMAGE img;

void initStar1(int i);
void initStar(int i);
void moveStar1(int i);
void moveStar();
void drawStar();

void initData(int weight);

void initData(int weight)
{
	srand((unsigned int)time(NULL));
	loadimage(&img, "�ز�/2.jpg", 60, 60);
	//ͼƬ���������
	int i = 0;
	for (i = 0; i < MAXSTAR1; i++)
	{
		initStar1(i);
		star1[i].x = rand() % (60*14);
	}
	//��ʼ������
	for (i = 0; i < MAXSTAR; i++)
	{
		initStar(i);
	}
}
void initStar1(int i)
{
	star1[i].x = 0;
	star[i].y = rand() % (60*13);	//0-599
	star[i].step = rand() % 5;  //0-4  ��������ֳ��ƶ�
	star1[i].color = RGB(star1[i].step * 51, star1[i].step * 51, star1[i].step * 51);//RGB�ķ�Χ��0-255����ɫ��ʾ������Ĺ��̣�
}
void initStar(int i)
{
	star[i].x = rand() % (60*14) - 640;//-640--639
	star[i].y = -144;
	do {
		star[i].step = rand() % 30 + 1;  // 1-30
	} while (star[i].step < 5);
	star[i].style = rand() & 3 + 1;    //���ü���ͼƬһ�������

}
void moveStar1(int i)
{
	putpixel(star1[i].x, star1[i].y, 0);
	star1[i].x += star1[i].step;
	if (star1[i].x > 60*14)
	{
		initStar1(i);
	}
	putpixel(star1[i].x, star1[i].y, star1[i].color);
}
void moveStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		star[i].x += star[i].step;
		star[i].y += star[i].step * 0.7;
	}
}
void drawStar()
{
	for (int i = 0; i < MAXSTAR; i++)
	{
		putimage(star[i].x, star[i].y, &img, SRCPAINT);//����ͼ��ʹͼ��͸�������ᱻ�����ڵ���������ֿ��壻
	}
}