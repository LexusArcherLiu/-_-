#include "header.h"


char dialog_init[][100] = { "......,"
							,"........,"
							,"......,"
							,"ͷ����"
							,"......,"
							,".........,"
							,"�����Ķ���"
							,"�Ҳ��ǵ�����ǰ���ô��"
							,"�����׵ľ��鰡���Ҵ�Խ����������"
							,"�����ˣ������������ӳ������ط���"
							,"�Ҹող�Լ���ҵ���÷����ȥ��������"
							,"ȥ�ǿ��½�����Щ������֪��������"
							,"......,"
							,".........,"
							,"ǰ��������ˣ�����ȥ������"
};

char dialog_first[][100] = { "�ܸ��˼����㣬������"
								,"���������������������в��������Ҫ��İ���"
								,"������̫��С�ˣ����޸���֮���������������ѱ���"
								,"��̸�α������ˣ��ػ�����"
								,"������������һ����������һ�ݻ�Ե��"
								,"���������ų��������ħ�������Ļ���"
								,"�㽫������Ӧ�ĳ�ʼֵ����,"
								,"������ô˵����������磬"
								,"ֻ��ӵ���������ܻ���Լ���Ҫ��"
								,"����㲻���������赲סħ������"
								,"ħ������������������"
								,"��һ��������������ˣ���ʱ��˭���赲������"
};

char dialog_second[][100] = { "����ͷ���������ͷ����β��"
								,"��֪�����ոն��Ҹ���ʲô"
								,"���Ǻ����������ֵ�����ˣ�"
								,"����ȴû��һ�����ֵ�����"
								,"Ӧ����������Թ������ҵ��ɣ�"
								,"������������"
								,"��������������"
								,"��Ϊʲô����ô��������"
								,"�����ˣ���һ����һ����"
								,"һ��Ҫ��ħ����������"
								,"��һ��Ҫʵ�ֺ���ȥ���������Ը��"
};

char dialog_search[][100] = { "����Ǵ�Ŵ�˵�����ĵط�ô��"
								,"�ѹ�����ô�಻Ӧ����������ħ�����������ػ�"
								,"һ��Ҫ�ڶ��ħ���ӵ�ǰ���»��"
								,"���Ҿ�˵ҹ��֮���ͱ�Ǿޱ֮�ܻ��Ǵ����������"
								,"��˵�е�������ֻ���ֳֻ�Կ�׵�ѡ��֮�˲��ܻ�ȡ"
								,"�����ڵ�һ�����Կ��"
								,"û��Ե�ֵĻ����ܺ��Ѽ����⴫˵�е�����"
								,"����˵������ͬʱ�����"
								,"ֻҪ��ã����ܻ�ú�ħ��һ��ǿ�������"
								,"�����ܻ�õ�������ļӳ�"
								,"��û���װ��֮ǰ������Զ�������ߵĵذ��"
								,"ʲô���޷��������ˣ�ʲô���޷��õ�"
								,"�����£�������"
};

char Dialogue_Boss[][100] = {"��ǿ������������������û���˴�˵װ��"
								,"��Ȼ�������䶼�����Һ���һ����"
								,"......."
								,"............"
								,"ħ�������������ˣ�����"
								,"ħ�������������ˣ�����"
								,"ħ����Ҳ������ܼ�ֵ�������"
								,"ħ�������ҿ����㵽���м���ʵ��"
								,"ħ������������ǰ���Q����"
								,"���ߣ���**�ϻ����ҵ���һ���Ѿ����˺ܾ���"
								,"���ߣ�����"
								,"���ߣ�ɱ���㣬���ܻؼ���"
								,"ħ�����Ǻǣ�����֮��"
};

char Ending_dialogue[][100] = { "���ڽ�����ô"
								,"����װ�����������;�ֵҲ�����˰�"
								,"��Ҳ���˼����˰�"
								,"���кúñ��������������ô"
								,"����п��������������"
								,"......."
								,"�Բ����ˣ�Լ���޷�ʵ����"
								,"Ҫ��������Ļ�ֻ�ܵ��Ժ��˰�...."
								,"�ټ���......"
};
int k = 0;
int Dialogue0(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_init[k++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return k;
}
int i = 0;
int Dialogue1(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_first[i++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return i;
}
int j = 0;
int Dialogue2(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_search[j++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return j;
}
int m = 0;
int Dialogue3(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, dialog_second[m++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return m;
}
int n = 0;
int Dialogue4(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, Dialogue_Boss[n++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return n;
}
int p = 0;
int Dialogue5(IMAGE bg) {
	//char cUser;
	//cUser = _getch();
	MOUSEMSG msg = { 0 };
	msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "��������");
	setcolor(BLACK);
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		putimage(0, 8 * 60, &bg);
		outtextxy(60 * 1, 60 * 9, Ending_dialogue[p++]);
		break;
	case WM_RBUTTONDOWN:
		return -1;
	}
	settextstyle(12, 0, "��������");
	setcolor(WHITE);
	return p;
}
	/*if (cUser == 13) {
		putimage(0, 0, &bg);
		setbkmode(TRANSPARENT);
		settextstyle(60, 0, "��������");
		outtextxy(60 * 5, 60 * 6, "��¥�С�������");
		setcolor(RED);
	}*/


