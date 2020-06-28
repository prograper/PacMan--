#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include <mmsystem.h>
#include <math.h>

#pragma comment(lib,"Winmm.lib")

#define PI 3.1415926

//����
#define UP 0  
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//С�ַ���
#define UP_S -2  
#define DOWN_S 2
#define LEFT_S -1
#define RIGHT_S 1


#define WALL_NUM 88
#define POINT_NUM 242
#define BIG_NUM 6


/**
* @param ǽ�����꣬�ж��ٶ�,��һ��[2]�������,�ڶ���[2]��xy����
* @author �ν���
*/
int WALL[WALL_NUM][2][2] = {
	{{56,43},{276,43}},
	{{276,43},{316,43}},
	{{316,43},{536,43}},
	{{56,43},{56,83}},
	{{276,43},{276,83}},
	{{316,43},{316,83}},
	{{536,43},{536,83}},
	{{56,83},{96,83}},
	{{96,83},{96,123}},
	{{96,83},{176,83}},
	{{176,83},{176,123}},
	{{216,83},{216,123}},
	{{216,83},{276,83}},
	{{316,83},{376,83}},
	{{376,83},{376,123}},
	{{416,83},{416,123}},
	{{416,83},{496,83}},
	{{496,83},{496,123}},
	{{496,83},{536,83}},
	{{56,123},{96,123}},
	{{56,123},{56,163}},
	{{136,123},{176,123}},
	{{136,123},{136,163}},
	{{176,123},{216,123}},
	{{216,123},{276,123}},
	{{276,123},{276,163}},
	{{316,123},{316,163}},
	{{316,123},{376,123}},
	{{376,123},{416,123}},
	{{416,123},{456,123}},
	{{456,123},{456,163}},
	{{496,123},{536,123}},
	{{536,123},{536,163}},
	{{56,163},{136,163}},
	{{136,163},{176,163}},
	{{176,163},{216,163}},
	{{176,163},{176,223}},
	{{216,163},{276,163}},
	{{216,163},{216,223}},
	{{276,163},{316,163}},
	{{316,163},{376,163}},
	{{376,163},{416,163}},
	{{376,163},{376,223}},
	{{416,163},{456,163}},
	{{416,163},{416,223}},
	{{456,163},{536,163}},
	{{36,223},{176,223}},
	{{176,223},{216,223}},
	{{176,223},{176,283}},
	{{216,223},{216,283}},
	{{376,223},{416,223}},
	{{376,223},{376,283}},
	{{416,223},{556,223}},
	{{416,223},{416,283}},
	{{56,283},{136,283}},
	{{56,283},{56,323}},
	{{136,283},{176,283}},
	{{136,283},{136,323}},
	{{216,283},{276,283}},
	{{276,283},{276,323}},
	{{316,283},{376,283}},
	{{316,283},{316,323}},
	{{416,283},{456,283}},
	{{456,283},{536,283}},
	{{456,283},{456,323}},
	{{536,283},{536,323}},
	{{56,323},{136,323}},
	{{56,323},{56,403}},
	{{136,323},{216,323}},
	{{136,323},{136,403}},
	{{216,323},{276,323}},
	{{216,323},{216,363}},
	{{276,323},{316,323}},
	{{316,323},{376,323}},
	{{376,323},{456,323}},
	{{376,323},{376,363}},
	{{456,323},{536,323}},
	{{456,323},{456,403}},
	{{536,323},{536,403}},
	{{216,363},{276,363}},
	{{276,363},{316,363}},
	{{276,363},{276,403}},
	{{316,363},{376,363}},
	{{316,363},{316,403}},
	{{56,403},{136,403}},
	{{136,403},{276,403}},
	{{316,403},{456,403}},
	{{456,403},{536,403}},					
};


/**
* @param �������꣬
* @args ���������±�ֱ���x y������Ƿ����
* @author �ν���
*/ 
int bean[POINT_NUM][3] = {
	/*50*/
	{56,43,1},{76,43,1},{96,43,1},{116,43,1},{136,43,1},{156,43,1},{176,43,1},{196,43,1},{216,43,1},{236,43,1},
	{256,43,1},{276,43,1},{296,43,1},{316,43,1},{336,43,1},{356,43,1},{376,43,1},{396,43,1},{416,43,1},{436,43,1},
	{476,43,1},{496,43,1},{516,43,1},{536,43,1},{56,63,1},{56,83,1},{76,83,1},{96,83,1},{116,83,1},{136,83,1},
	{156,83,1},{176,83,1},{276,63,1},{276,83,1},{316,63,1},{316,83,1},{536,63,1},{536,83,1},{96,83,1},{96,103,1},
	{96,123,1},{176,103,1},{176,123,1},{216,83,1},{236,83,1},{256,83,1},{276,83,1},{216,103,1},{216,123,1},{336,83,1},
	/*49*/
	{376,83,1},{376,103,1},{376,123,1},{416,83,1},{436,83,1},{456,83,1},{476,83,1},{416,103,1},{416,123,1},
	{496,83,1},{516,83,1},{536,83,1},{496,103,1},{496,123,1},{56,123,1},{76,123,1},{96,123,1},{56,143,1},{56,163,1},
	{136,123,1},{156,123,1},{196,123,1},{136,143,1},{136,163,1},{216,123,1},{236,123,1},{256,123,1},{276,123,1},{276,143,1},
	{276,163,1},{316,123,1},{316,143,1},{316,163,1},{336,123,1},{356,123,1},{376,123,1},{396,123,1},{416,123,1},{436,123,1},
	{456,123,1},{456,143,1},{456,163,1},{496,123,1},{516,123,1},{536,123,1},{536,143,1},{536,163,1},{76,163,1},{96,163,1},
	/*48*/
	{116,163,1},{156,163,1},{176,163,1},{176,183,1},{176,203,1},{176,223,1},{196,163,1},{216,163,1},{216,183,1},{216,203,1},
	{236,163,1},{256,163,1},{276,163,1},{296,163,1},{316,163,1},{336,163,1},{356,163,1},{376,163,1},{376,183,1},
	{376,203,1},{376,223,1},{396,163,1},{416,163,1},{416,183,1},{416,203,1},{416,223,1},{436,163,1},{456,163,1},
	{496,163,1},{516,163,1},{536,163,1},{176,223,1},{196,223,1},{216,223,1},{176,243,1},{176,263,1},{176,283,1},{196,223,1},
	{216,223,1},{216,243,1},{216,263,1},{216,283,1},{376,223,1},{376,243,1},{376,263,1},{376,283,1},{396,223,1},{416,223,1},
	/*49*/
	{416,243,1},{416,263,1},{416,283,1},{56,283,1},{56,303,1},{56,323,1},{76,283,1},{96,283,1},{116,283,1},{136,283,1},
	{136,283,1},{136,303,1},{136,323,1},{156,283,1},{176,283,1},{236,283,1},{256,283,1},{276,283,1},{276,303,1},{276,323,1},
	{316,303,1},{316,323,1},{336,283,1},{356,283,1},{376,283,1},{416,283,1},{436,283,1},{456,283,1},{456,303,1},
	{456,323,1},{476,283,1},{496,283,1},{516,283,1},{536,283,1},{536,303,1},{536,323,1},{56,323,1},{56,343,1},{56,363,1},
	{56,383,1},{56,403,1},{76,323,1},{96,323,1},{116,323,1},{136,323,1},{136,343,1},{136,363,1},{136,383,1},{136,403,1},
	/*46*/
	{156,323,1},{176,323,1},{196,323,1},{216,323,1},{216,343,1},{216,363,1},{236,323,1},{256,323,1},{296,323,1},{336,323,1},
	{376,323,1},{376,343,1},{376,363,1},{396,323,1},{416,323,1},{436,323,1},{456,343,1},{456,363,1},{456,383,1},
	{456,403,1},{476,323,1},{496,323,1},{516,323,1},{536,323,1},{536,343,1},{536,363,1},{536,383,1},{536,403,1},{76,403,1},
	{96,403,1},{116,403,1},{156,403,1},{176,403,1},{196,403,1},{216,403,1},{236,403,1},{256,403,1},{336,403,1},{356,403,1},
	{376,403,1},{396,403,1},{416,403,1},{436,403,1},{476,403,1},{496,403,1},{516,403,1}
};


/**
* @param ����������鶨��
* @args ���������±�ֱ��Ǵ������x,y,�Ƿ����
* @author ���
*/
int big[BIG_NUM][3]={
	{456,43,1},
	{356,83,1},
	{216,223,1},
	{316,283,1},
	{356,323,1},
	{476,163,1}
};

/**
* @param �Զ��˵Ľṹ�嶨��
* @author �׿
*/
struct pac {
	int x;   //x����
	int y;   //y����
	int lastx;
	int lasty;
	bool isActive;   //�Ƿ����
	bool isStrong;    //�Ƿ�Ե��˴�����
	int newPosition;    //�·���    0,1,2,3������������
	int oldPosition;    //�ɷ���
}it;

/**
* @param С�ֵĽṹ��
* @author �׿
*/
struct mon {
	int x;    //x����
	int y;    //y����
	int position;    //����
	int isDie;
}Monster[4];



void move();//    
int choose(int direct);
void movePlus(int direct);
void isPoint();  //�Ƿ�Ե�����
void isBig();  //�Ƿ�Ե�������
void printBean();  //��ӡ����
int isLive(int);  //�Ƿ�����С��
void startPac(void*);

//////////////////////////

void moveMonster(int x);
int chooseMonster(int direct,int x);
void moveMonsterPlus(int direct,int x);
void startMonster(void*);
int isTouchPoint(int x);  //�Ƿ���������
int isTouchBig(int x);//    �Ƿ�����������
void startBlinking();//    ��ʼҳ��Ķ���Ч��
//////////////////////////////////////

HANDLE h_startPacThread;//    �洢�Զ����̵߳ľ��
HANDLE h_startMonsterThread;//    �洢����С�ֵ��̵߳ľ��
HANDLE h_startMonsterThread2;
HANDLE h_startMonsterThread3;

unsigned pacThreadId;//    �Զ����̵߳��߳�id
unsigned monThreadId;//    С���̵߳��߳�id
unsigned monThreadId2;
unsigned monThreadId3;
CRITICAL_SECTION keyBlocks;//    �ؼ�����ζ���

/**
* @param �Զ����̵߳��̺߳���
* @args void* ����Ϊ�գ�����Ҫ���ݲ���
* @return ����0
* @author �׿
*/
unsigned __stdcall pacThreadDemo(void*) {
	startPac(NULL);
	return 0;
}

/**
* @param С���̵߳��̺߳���
* @args ����С�������±꣬ע��ʹ��(void*)ǿ��ת����_beginthreadex()����ֻ�ܵ��ò���Ϊvoid*���͵ĺ���
* @return ����0
* @author �׿
*/
unsigned __stdcall monThreadDemo1(void *args) {
	startMonster(args);
	return 0;
}


int monId[4] = {0,1,2,3};//    ����С�ֵ������±�
int pointSum = 242;//    ��������

char s[5];
int score = 0;  //��Ϸ�ܷ�
int timeStart = 0;  //�Դ�����Ŀ�ʼʱ��

int main()
{

		/*��ʼ������*/
	initgraph(586, 437);
	startBlinking();
	loadimage(NULL,"Χǽ����\\tests.jpg");
	printBean();
	//    ����ؼ������
	InitializeCriticalSection(&keyBlocks);

	//    �����Զ��˺�С�ֵ��߳�
	h_startPacThread = (HANDLE) _beginthreadex(NULL,0,pacThreadDemo,NULL,0,&pacThreadId);
	h_startMonsterThread = (HANDLE) _beginthreadex(NULL,0,monThreadDemo1,&monId[0],0,&monThreadId);
	h_startMonsterThread2 = (HANDLE) _beginthreadex(NULL,0,monThreadDemo1,&monId[1],0,&monThreadId2);
	h_startMonsterThread3 = (HANDLE) _beginthreadex(NULL,0,monThreadDemo1,&monId[2],0,&monThreadId3);

	//    ��main�����ȴ������ĸ��̣߳�����INFINITEΪ��Զ��ֱ���߳̽�����
	WaitForSingleObject(h_startPacThread,INFINITE);
	WaitForSingleObject(h_startMonsterThread,INFINITE);
	WaitForSingleObject(h_startMonsterThread2,INFINITE);
	WaitForSingleObject(h_startMonsterThread3,INFINITE);

	//    �ĸ��߳̽�����رվ��
	CloseHandle(h_startPacThread);
	CloseHandle(h_startMonsterThread);
	CloseHandle(h_startMonsterThread2);
	CloseHandle(h_startMonsterThread3);

	//    ɾ���ؼ������
	DeleteCriticalSection(&keyBlocks);
	getch();

	return 0;
}

/**
* @param �Զ��˵��ڲ���Ϳ��ƺ���
* @args NULL
* @author ���
*/
void startPac(void *args) {

	/*��ʼ���Զ���*/
	it.x = 56;
	it.lastx = 56;
	it.y = 43;
	it.lasty = 43;
	it.newPosition = RIGHT;
	it.oldPosition = LEFT;
	it.isActive = 1;

	setlinecolor(YELLOW);
    setfillcolor(YELLOW);
    fillcircle(it.x, it.y,10);

	char c = 0;
	//Monster *man[4];
    while(c != 27)
    {
		c = 0;
        // ��ȡ����
		if(kbhit())
			c = getch();
         
        // �������룬�����µ�����
        switch(c)
        {
                case 'a': 
					it.oldPosition = it.newPosition;
					it.newPosition = LEFT;
					break;

                case 'd': 
					it.oldPosition = it.newPosition;
					it.newPosition = RIGHT;
					break;

				case 'w': 
					it.oldPosition = it.newPosition;
					it.newPosition = UP;
					break;

				case 's':
					it.oldPosition = it.newPosition;
					it.newPosition = DOWN;
					break;
                case 27: break;
        }

		// ����ؼ������
		EnterCriticalSection(&keyBlocks);

		// �Ȳ����ϴ���ʾ�ľ�ͼ��
        setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(it.x, it.y,10);

		//    �ƶ�����
        move();

        // �����µ�ͼ��
		if(it.isStrong)
		{
			setlinecolor(YELLOW);
			setfillcolor(RED);
			fillcircle(it.x, it.y,10);
		}
		else
		{
			setlinecolor(YELLOW);
			setfillcolor(YELLOW);
			fillcircle(it.x, it.y,10);
			//pacManMOD(0,0,it.oldPosition);
		}
        
		if(!it.isActive)
		{
			break;
		}

		//    �뿪�ؼ������
		LeaveCriticalSection(&keyBlocks);

		sprintf(s,"%d",score);
		outtextxy(70, 0, s);
        // ��ʱ
		if(it.isStrong) {
			Sleep(7);
		}else {
			Sleep(10);
		}
    }
	getch();
	closegraph();

	//    ����������رյ��ô˺������߳�
	_endthreadex(0);
}

/**
* @param �Զ����ƶ�����غ���
* @author ���
*/
void move()
{
	int isMove;  //�·����Ƿ����ƶ���Ĭ����
	int isOldMove = 0;  //�ɷ����Ƿ����ƶ�

	isMove = choose(it.newPosition);  //�ж��·���
	/*if(isMove  && (!isOldMove))
	{
		MessageBox(NULL,"2","�������ڵı���",0);
	}*/ 

	if(!isMove)
	{
		isOldMove = choose(it.oldPosition);  //�жϾɷ���
	}

	if(isMove)
	{
		movePlus(it.newPosition);  //���·����ƶ�
	}
	else if(isOldMove)
	{
		movePlus(it.oldPosition);  //���ɷ����ƶ�
	}
	
	isPoint();  //�Ƿ�Զ���
	isBig();  //�Ƿ�Դ�����
	//isLive();  //�Ƿ�����С��
	if(GetTickCount()-timeStart>=5000)  //ʱ�䵽���������Ч����ʧ
	{
		it.isStrong = 0;
	}

}


/**
* @param ���ƳԶ��������ƶ�������任
* @args �Զ��˵��ƶ�����0��1��2��3�����ϡ��¡�����
* @author ���
*/
void movePlus(int direct)
{
	
	switch(direct)
	{
		case UP: 
			it.lasty = it.y;
			it.y--; 
			break;

		case DOWN: 
			it.lasty = it.y;
			it.y++; 
			break;

		case LEFT: 
			it.lastx = it.x;
			it.x--; 
			break;

		case RIGHT:
			it.lastx = it.x;
			it.x++; 
			break;
	}
	//������
	if(it.y==223 && it.x == 36)
	   	it.x = 556;
    else if(it.y==223 && it.x == 556)
	   	it.x = 36;
}

/**
* @param �жϴ˷����Ƿ�����ƶ�
* @args �Զ����ƶ�����0��1��2��3�����ϡ��¡�����
* @return �����ƶ�����1�����򷵻�0
* @author ���
*/
int choose(int direct)
{
	int i,next;  //next������������
	int isOk = 0;
	switch(direct)
	{
		case UP:
			for(i=0; i<WALL_NUM; i++)
			{
				next = it.y - 1;
				/*�����ں��߷�Χ��*/
				if(next >= WALL[i][0][1] && next <= WALL[i][1][1] && it.x >= WALL[i][0][0] && it.x <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case DOWN:
			for(i=0; i<WALL_NUM; i++)
			{
				next = it.y + 1;
				/*�����ں��߷�Χ��*/
				if(next >= WALL[i][0][1] && next <= WALL[i][1][1] && it.x >= WALL[i][0][0] && it.x <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case LEFT:
			for(i=0; i<WALL_NUM; i++)
			{
				next = it.x - 1;
				/*�����ں��߷�Χ��*/
				if(it.y >= WALL[i][0][1] && it.y <= WALL[i][1][1] && next >= WALL[i][0][0] && next <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case RIGHT:
			for(i=0; i<WALL_NUM; i++)
			{
				next = it.x + 1;
				/*�����ں��߷�Χ��*/
				if(it.y >= WALL[i][0][1] && it.y <= WALL[i][1][1] && next >= WALL[i][0][0] && next <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;
	}
}

/**
* @param �Զ��˳Է�Ե�����
* @author ���
*/
void isPoint()
{
	int i;
	for(i=0; i<POINT_NUM; i++)
	{
		if(it.x == bean[i][0] && it.y == bean[i][1] && bean[i][2]==1)
		{
			score+=10;
			bean[i][2]=0;
			//    ������������
			pointSum --;
			//ȥ��break�ͻ�©������
		}
	}
}

/**
* @param �Զ����Ƿ�Ե�������
* @author ���
*/
void isBig()
{
	int i;
	for(i=0; i<BIG_NUM; i++)
	{
		if(it.x == big[i][0] && it.y == big[i][1] && big[i][2]==1)
		{
			big[i][2] = 0;
			score+=50;
			it.isStrong = 1;
			timeStart = GetTickCount();
			break;
		}
	}
}

/**
* @param С�ֳԷ������Զ���
* @args С�ֵ������±�
* @return �����������0�����򷵻�1
* @author ��骡��׿��release. Ϊ����Ӧ���̣߳����Զ��˼��С�ָĳ�С�ּ��Զ��ˣ�
*/
int isLive(int i)  //�Ƿ�����С��
{
	//     ����ؼ������
	EnterCriticalSection(&keyBlocks);
	int live = 1;
//	for (i = 0; i<3; i++)
//	{
		if(it.x == Monster[i].x && it.y == Monster[i].y)  //��������غ�
		{
			if(it.isStrong)  //�д�����Թ�
			{
				score + 100;
				Monster[i].x = 136;
				Monster[i].y = 283;
				//Sleep(1000);

			}
			else  //�޴�����ֳ�
			{
				it.isActive = 0;
				live = 0;
				SuspendThread(h_startPacThread);
				Sleep(1000);
				IMAGE pSrcImg;
				loadimage(&pSrcImg,"test\\game over.png");
				putimage(200,320,&pSrcImg);
				Sleep(3000);
			//	break;
				exit(1);
			}
		}
		if(0 == pointSum) {
			it.isActive = 0;
				live = 0;
				SuspendThread(h_startPacThread);
				Sleep(1000);
				IMAGE pSrcImg;
				loadimage(&pSrcImg,"test\\game over.png");
				putimage(200,320,&pSrcImg);
				Sleep(3000);
			//	break;
				exit(1);
		}
//	}
	//    �뿪�ؼ������
	LeaveCriticalSection(&keyBlocks);
	return live;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @param С�ֵ��Զ������
* @args ����С�������±꣬���ڿ���ָ��С�ֵ��ڴ�ռ���ں˶���
* @author ��骡��׿��release. Ϊ����Ӧ���̣߳�����ѡ���ض�С�������±�ȣ�
*/
void startMonster(void *args)
{

	IMAGE img;
	IMAGE imgBlack;
	
	//    �����ݽ����ģ�void*�����ͺ���ǿ��ת��Ϊint���ͣ�����С�������±�
	int num = *(int*)args;

	//    ѡ��С�ֵ���ɫ�������ض�ͼƬ
	if(0 == num) {
		getimage(&imgBlack, 560, 407, 20, 18);
		loadimage(&img,"PacMan Material\\Pic\\PacManMonster\\BlueMonster.png");
		/*��ʼ��С��*/
		Monster[num].x = 136;
		Monster[num].y = 283;
		Monster[num].position = RIGHT_S;
	}else if(1 == num) {
		getimage(&imgBlack, 560, 407, 20, 18);
		loadimage(&img,"PacMan Material\\Pic\\PacManMonster\\RedMonster.png");
		/*��ʼ��С��*/
		Monster[num].x = 236;
		Monster[num].y = 323;
		Monster[num].position = RIGHT_S;
	}else if(2 == num) {
		getimage(&imgBlack, 560, 407, 20, 18);
		loadimage(&img,"PacMan Material\\Pic\\PacManMonster\\OrangeMonster.png");
		/*��ʼ��С��*/
		Monster[num].x = 216;
		Monster[num].y = 123;
		Monster[num].position = RIGHT_S;
	}
	

    while(1)
    {
		//    ����ؼ������
		EnterCriticalSection(&keyBlocks);
		// �Ȳ����ϴ���ʾ�ľ�ͼ��
		putimage(Monster[num].x-10,Monster[num].y-9, &imgBlack);
        moveMonster(num);

        // �����µ�ͼ��
        putimage(Monster[num].x-10,Monster[num].y-9, &img);

		//ÿ�μ�����ж��Ӻʹ������Ƿ����
		for(int i = 0; i<POINT_NUM; i++)
		{
			if(bean[i][2])
			{
				setlinecolor(RGB(255,192,203));
				setfillcolor(RGB(255,192,203));
				fillcircle(bean[i][0],bean[i][1],2);
			}
		}

		for(i=0; i<BIG_NUM; i++)
		{
			if(big[i][2])
			{
				setlinecolor(RGB(238,2,3));
				setfillcolor(RGB(238,2,3));
				fillcircle(big[i][0],big[i][1],3);
			}
		}
		if(! isLive(num)) {
			_endthreadex(0);
			Sleep(5000);
			exit(-1);
		}

		//    �뿪�ؼ������    
		LeaveCriticalSection(&keyBlocks);

        // ��ʱ
		if(it.isStrong) {
			Sleep(12);
		}else {
			Sleep(9);
		}
    }
	//    ����������ʱ���������ô˺������߳�
	_endthreadex(0);
}

/**
* @param ��ӡ��ͼ�����л����ڵĶ���
* @author ���
*/
void printBean()
{
	settextstyle(16, 0, _T("����"));
	outtextxy(37, 0, _T("�÷֣�"));

//	EnterCriticalSection(&keyBlocks);
	/*������*/
	int i,j;
	for(j=0; j<POINT_NUM; j++)
	{
		setlinecolor(RGB(255,192,203));
		setfillcolor(RGB(255,192,203));
		fillcircle(bean[j][0],bean[j][1],2);
	}

	/*��������*/
	for(i=0; i<BIG_NUM; i++)
	{
		setlinecolor(RGB(238,2,3));
		setfillcolor(RGB(238,2,3));
		fillcircle(big[i][0],big[i][1],3);
	}
//	LeaveCriticalSection(&keyBlocks);
}

/**
* @param С���Զ���Ѱ�ҿ���·��������һֱ�ߺ���
* @args С�������±�
* @author ��骡��׿��release. ����С�������±�����������ض�С�ֵ��ڴ棩
*/
void moveMonster(int x)
{
	//    ����ؼ������
	EnterCriticalSection(&keyBlocks);
	srand(time(NULL));
	int lastOne,lastTwo;
	int lastThree = Monster[x].position;
	int num[4] = {0,0,0,0};  //���ܵ�·��
	int sum = 0;
	int i;

	for(i=-2;i<3;i++)
		if(i!=0)
		{
			if(chooseMonster(i,x))
			{
				num[sum] = i;
				sum++;
			}
		}
	/*���������·*/
	if(sum>=2)
	{
		if(sum == 2)  //����·
		{
			/*1.1 �������·�߶���Ϊ֮ǰ��·�ߣ���սǣ���ѡ����·��*/
			if(num[0] != Monster[x].position && num[1] != Monster[x].position)
			{
				lastOne = -num[0];  //����
				lastTwo = -num[1];
				if(lastOne == Monster[x].position)
					Monster[x].position = num[1];
				else if(lastTwo == Monster[x].position)
					Monster[x].position = num[0];
			}
			/*1.2 �����ֱ���ϣ��ͼ�����֮ǰ��·��*/
			else if(num[0] == Monster[x].position && num[1] != Monster[x].position)
			{
				Monster[x].position = num[0];
			}

			else if(num[0] != Monster[x].position && num[1] == Monster[x].position)
			{
				Monster[x].position = num[1];
			}
		}

		else if(sum == 3 || sum == 4)  //��/����·
		{
			/*2.1 �������ķ�����󲻵���֮ǰ��·�ߣ���ѭ������*/
			while(lastThree == Monster[x].position)
			{
				i = rand()%sum;
				lastThree = -num[i];
			}
			Monster[x].position = num[i];
		}
	}

	//    �뿪�ؼ������
	LeaveCriticalSection(&keyBlocks);

	moveMonsterPlus(Monster[x].position,x);

}


/**
* @param �ж��·����Ƿ�����ƶ�
* @args �����С�������±�
* @return ��������߾ͷ���1�����򷵻�0
* @author ���
*/
int chooseMonster(int direct,int x)
{
//	EnterCriticalSection(&keyBlocks);
	int i,next;  //next������������
	int isOk = 0;
	switch(direct)
	{
		case UP_S:
			for(i=0; i<WALL_NUM; i++)
			{
				next = Monster[x].y - 1;
				/*�����ں��߷�Χ��*/
				if(next >= WALL[i][0][1] && next <= WALL[i][1][1] && Monster[x].x >= WALL[i][0][0] && Monster[x].x <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case DOWN_S:
			for(i=0; i<WALL_NUM; i++)
			{
				next = Monster[x].y + 1;
				/*�����ں��߷�Χ��*/
				if(next >= WALL[i][0][1] && next <= WALL[i][1][1] && Monster[x].x >= WALL[i][0][0] && Monster[x].x <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case LEFT_S:
			for(i=0; i<WALL_NUM; i++)
			{
				next = Monster[x].x - 1;
				/*�����ں��߷�Χ��*/
				if(Monster[x].y >= WALL[i][0][1] && Monster[x].y <= WALL[i][1][1] && next >= WALL[i][0][0] && next <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;

		case RIGHT_S:
			for(i=0; i<WALL_NUM; i++)
			{
				next = Monster[x].x + 1;
				/*�����ں��߷�Χ��*/
				if(Monster[x].y >= WALL[i][0][1] && Monster[x].y <= WALL[i][1][1] && next >= WALL[i][0][0] && next <= WALL[i][1][0])
					return 1;
				else
					isOk = 1;
			}
			if(isOk) return 0;
	}
//	LeaveCriticalSection(&keyBlocks);
}

/**
* @param �任С�ֵ�����
* @args С�ֵ�ǰ�ƶ�����0��1��2��3�ֱ��Ӧ�ϡ��¡����ң�num����ǰС�������±�
* @author ���
*/
void moveMonsterPlus(int direct,int num)
{
	switch(direct)
	{
		case UP_S: Monster[num].y--; break;
		case DOWN_S: Monster[num].y++; break;
		case LEFT_S: Monster[num].x--; break;
		case RIGHT_S:Monster[num].x++; break;
	}
	//������
	if(Monster[num].y==223 && Monster[num].x == 36)
		Monster[num].x = 556;
	else if(Monster[num].y==223 && Monster[num].x == 556)
		Monster[num].x = 36;
}

/**
* @param �Ƿ���������
* @args С�������±�
* @return ��������˷���1�����򷵻�0
* @author ��骡��׿��release.����С�������±꣬���������
*/
int isTouchPoint(int x)
{
	//    ����ؼ������
	EnterCriticalSection(&keyBlocks);
	int i,isOk = 0;
	for(i=0; i<POINT_NUM; i++)
	{
		if(Monster[x].x == bean[i][0] && Monster[x].y == bean[i][1] && bean[i][2]==1)
		{
			isOk = 1;
			break;
		}
	}

	//    �뿪�ؼ������
	LeaveCriticalSection(&keyBlocks);
	if(isOk)
		return 1;
	else
		return 0;
}

/*�Ƿ�����������*/
/**
* @param �Ƿ�����������
* @args С�ֵ������±�
* @return ��������˷���1�����򷵻�0
* @author ��骣��׿��release. ���������±꣩
*/
int isTouchBig(int x)
{
	//    ����ؼ������
	EnterCriticalSection(&keyBlocks);
	int i,isOk;
	for(i=0; i<BIG_NUM; i++)
	{
		if(Monster[x].x == big[i][0] && Monster[x].y == big[i][1] && big[i][2]==1)
		{
			isOk = 1;
			break;
		}
	}
	//    �뿪�ؼ������
	LeaveCriticalSection(&keyBlocks);
	if(isOk)
		return 1;
	else
		return 0;
}

/**
* @param ��ӡ��ʼҳ�涯���Ͳ��ű�������
* @author �ν���
*/
void startBlinking() 
{
	//    �������ļ�������ָ��ʹ���豸����
	mciSendString("open PacManMusic\\pacman_beginning.wav",NULL,0,NULL);
	mciSendString("play PacManMusic\\pacman_beginning.wav",NULL,0,NULL);
	//PlaySound("C:\\Users\\29389\\Desktop\\PacManMusic\\pacman_beginning.wav",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	while(1)
	{

		//    ѭ������60֡ͼƬ�γɶ�̬Ч��
		loadimage(NULL, _T("gif\\test_1.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_2.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_3.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_4.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_5.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_6.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_7.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_8.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_9.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_10.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_11.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_12.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_13.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_14.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_15.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_16.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_17.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_18.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_19.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_20.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_21.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_22.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_23.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_24.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_25.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_26.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_27.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_28.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_29.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_30.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_31.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_32.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_33.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_34.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_35.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_36.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_37.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_38.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_39.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_40.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_41.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_42.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_43.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_44.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_45.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_46.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_47.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_48.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_49.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_50.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_51.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_52.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_53.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_54.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_55.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_56.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_57.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_58.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_59.png"));
		Sleep(50);
		loadimage(NULL, _T("gif\\test_60.png"));

		//    ����а�������͹رղ��Ŷ��������ֲ���
		if(kbhit())
		{
			mciSendString("stop PacManMusic\\pacman_beginning.wav",NULL,0,NULL);
			mciSendString("close PacManMusic\\pacman_beginning.wav",NULL,0,NULL);
			break;
		}
		Sleep(5);
	}
}



