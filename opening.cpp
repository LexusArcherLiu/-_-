#include "header.h"

extern int Dialogue1(IMAGE bg);

void opening() {
	setbkcolor(BLACK);
	cleardevice();
	Sleep(4000);
	setbkcolor(WHITE);
	cleardevice();
	Sleep(1000);
	settextstyle(60, 0, "��������");
	setbkcolor(BLACK);
	cleardevice();
	Sleep(4000);
	outtextxy(280, 170, "�����������Ķ���");
	Sleep(2000);
	cleardevice();
	outtextxy(100, 450, "�ҵ�ͷ����....");
	outtextxy(100, 560, "������������");
	Sleep(2000);
	cleardevice();
	outtextxy(200, 250, "......");
	Sleep(2000);
	Sleep(1000);
	cleardevice();
	setbkcolor(WHITE);
	//putimage(0, 0, &bg);
	settextstyle(60, 0, "��������");
	setbkmode(TRANSPARENT);
	outtextxy(150, 250, "�Һ������˵�ʲô...");
	Sleep(2000);
	setcolor(BLACK);
	cleardevice();
	outtextxy(200, 250, "...");
	Sleep(2000);
	cleardevice();
	outtextxy(200, 350, ".....");
	Sleep(3000);
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextstyle(12, 0, "��������");
}