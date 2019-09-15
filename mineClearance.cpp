#include "header.h"
#pragma comment(lib,"winmm.lib")
extern HWND hwnd;
int win; // �㿪���ֵĸ���
#define ROW 13 //��
#define COL 13 //��
#define NUM 10 //�׵ĸ���
#define SIZE 60//һ��ͼƬ�Ŀ��

IMAGE img[12];  //����һ�����飬�������12��ͼƬ��
int mine = 0; //�����ų��ĵ��׵�����
int map[ROW + 2][COL + 2]; //��Ϸ���Լ�������,1-10��Ϊ��Ϸ����0��11�Ǹ�����
//��ʼ��
void GameInit()
{
	win = 0;
	srand((unsigned int)time(NULL));
	//��ά�����ʼ�� ȫ����ʼ��
	for (int i = 0; i < ROW + 2; i++) {
		for (int j = 0; j < COL + 2; j++)
		{
			map[i][j] = 0;
		}
	}
	//ʲô����  -1������ ���ٸ��� 10 ��ȫ�����ڸ�����
	for (int i = 0; i < NUM;)
	{
		int r = rand() % ROW + 1; //�������1~10
		int c = rand() % COL + 1;//�������1~10

		if (map[r][c] == 0) //ȫ�µĲ��ظ���Ԫ��
		{
			map[r][c] = -1;//����һ���� ѭ��һ��
			i++;
		}
	}

	//������Ϸ�������в����׵�Ԫ�أ��˴���ɨ�׵Ļ���˼�룩
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			if (map[i][j] != -1)//������
			{
				//�����Ź���
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)//����һ����
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}
	//Ҫ����Ϸ��ÿһ��Ԫ�ض�+20
	for (int i = 1; i < ROW + 1; i++)
	{
		for (int j = 1; j < COL + 1; j++)
		{
			map[i][j] += 20;
		}
	}
}
//��ʾ��
void GamePaint()
{
	//��ά�����ӡ
	for (int i = 1; i < ROW + 1; i++) {
		for (int j = 1; j < COL + 1; j++)
		{
			if (map[i][j] == -1)//��
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[9]);
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)//����
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)//����
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[10]);
			}
			//19-28 ��һ�� +10000  �ٵ�һ�� -10000
			else if (map[i][j] > 30)//С����
			{
				putimage((i - 1)*SIZE, (j - 1)*SIZE, &img[11]);
			}
		}
		printf("\n");
	}
}
// һɨһ��Ƭ�Ĺ���
void ClickBlank(int x, int y)
{
	if (map[x][y] - 20 == 0)
	{
		map[x][y] -= 20;
		win++;
		if ((x - 1) > 0 && (y - 1) > 0 && (map[x - 1][y - 1] >= 19))
			ClickBlank(x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (map[x - 1][y] >= 19))
			ClickBlank(x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (map[x - 1][y + 1] >= 19))
			ClickBlank(x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (map[x][y - 1] >= 19))
			ClickBlank(x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (map[x][y + 1] >= 19))
			ClickBlank(x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (map[x + 1][y - 1] >= 19))
			ClickBlank(x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (map[x + 1][y] >= 19))
			ClickBlank(x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (map[x + 1][y + 1] >= 19))
			ClickBlank(x + 1, y + 1);
	}
	else {
		map[x][y] -= 20;
		win++;
	}
}
//��
int GamePlay()
{
	MOUSEMSG msg = { 0 };
	int n;
	while (1) {
		msg = GetMouseMsg();//���ϵػ�ȡ�����Ϣ

		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			PlaySound("./res/Click.wav", NULL, SND_ASYNC | SND_FILENAME);
			n = map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			if (n == 20)
			{
				int a = msg.x / SIZE + 1;
				int b = msg.y / SIZE + 1;
				ClickBlank(a, b);
			}
			else if (n >= 19 && n <= 28)//����Ǽ��ܵ�
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] -= 20;
				win++;
			}

			return map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			break;
		case WM_RBUTTONDOWN:
			//1 19-28
			PlaySound("./res/rightClick.wav", NULL, SND_ASYNC | SND_FILENAME);
			n = map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			if (n >= 19 && n <= 28)
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] += 10000;
				if (n == 19) {
					mine++;
				}
			}
			else if (n > 30)
			{
				map[msg.x / SIZE + 1][msg.y / SIZE + 1] -= 10000;
				if (n - 10000 == 19) {
					mine--;
				}
			}
			return map[msg.x / SIZE + 1][msg.y / SIZE + 1];
			break;
		}
	}
}

void LoadimageScan() {
	loadimage(&img[0], "./res/0.jpg", SIZE, SIZE);
	loadimage(&img[1], "./res/1.jpg", SIZE, SIZE);
	loadimage(&img[2], "./res/2.jpg", SIZE, SIZE);
	loadimage(&img[3], "./res/3.jpg", SIZE, SIZE);
	loadimage(&img[4], "./res/4.jpg", SIZE, SIZE);
	loadimage(&img[5], "./res/5.jpg", SIZE, SIZE);
	loadimage(&img[6], "./res/6.jpg", SIZE, SIZE);
	loadimage(&img[7], "./res/7.jpg", SIZE, SIZE);
	loadimage(&img[8], "./res/8.jpg", SIZE, SIZE);
	loadimage(&img[9], "./res/9.jpg", SIZE, SIZE);
	loadimage(&img[10], "./res/10.jpg", SIZE, SIZE);
	loadimage(&img[11], "./res/11.jpg", SIZE, SIZE);
}

int StartScan()
{
	LoadimageScan();

	mciSendString("open ./res/start.mp3 alias start", 0, 0, 0);

	while (1)
	{
		mciSendString("open ./res/start.mp3 alias start", 0, 0, 0);
		GameInit();
		while (1)
		{

			GamePaint();
			if (GamePlay() == -1)
			{
				GamePaint();
				MessageBox(hwnd, "���ź����㲢û���ų����������е������", "", MB_OK);
				return mine;
				break;
			}
			if (ROW*COL - NUM == win)
			{
				MessageBox(hwnd, "Ը�����ϵ��ٹ�����������Ұ�����ʵ��δ������ͬ��", "", MB_OK);
				return 10;
				break;
			}
		}
		if (MessageBox(hwnd, "��Ҫ�ٴ���սһ��ô��", "", MB_RETRYCANCEL) == IDCANCEL)
			break;
		mciSendString("close start", 0, 0, 0);
	}
	getchar();
}
