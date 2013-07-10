#include<iostream>
#include<stdlib.h> 
#include<time.h> 
#include <curses.h>
using namespace std;
int x,y,Step=0;
bool flag=0;
int Flag=1;
char Switch;
char map[16][16][3]={
{"┌","┬","┬","┬","┬","┬","┬","┬","┬","┬","┬","┬","┬","┬","┬","┐"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"├","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┤"},
{"└","┴","┴","┴","┴","┴","┴","┴","┴","┴","┴","┴","┴","┴","┴","┘"}};
char copymap[16][16][3];
float Computer[16][16][4];
float Player[16][16][4];
int Table[16][16];
int Showboard(),Play(),Interface(),unitboard(),judgewin(),Per_Com(),ComPlay(),unitdata(),unitboard();
int deuce(),See(),Recoverboard(); 
bool legal(),Overflow();
int Interface()
{
	char a;
	cout << "\n\n		  CHESS 5 GAMES!\n \t\t──────────\n		 制作人：蔡智聪（200542095）\n\t\t──────────────── \n";
	cout << "		～～～～～～～～～～～～～～～～～～～～～～～～～～～～" << endl;
	cout << "		~~                                                    ~~" << endl;
	cout << "		~~        1：Two Person Games                         ~~" << endl;
	cout << "		~~          （人人对战）                              ~~" << endl;
	cout << "		~~                                                    ~~" << endl;
	cout << "		~~        2：Person Vs Computer                       ~~" << endl;
	cout << "		~~          （人机大战）                              ~~" << endl;
	cout << "		~~                                                    ~~" << endl;
	cout << "		~~        3: To be Spectator                          ~~" << endl;
	cout << "		~~          （观众模式）                              ~~" << endl;
	cout << "		~~                                                    ~~" << endl;
	cout << "		~~        4: Exit                                     ~~" << endl;
	cout << "		~~          （退出）                                  ~~" << endl;
	cout << "		~~                                                    ~~" << endl;
	cout << "		～～～～～～～～～～～～～～～～～～～～～～～～～～～～" << endl;
	cout << "\n		Please select(请选择):";
	cin >> a;
	if(a=='1')	Play();
	else if(a=='3')
	{
		unitdata(); 
		See(); 
	} 
	else if(a=='4')	
	{ 
		cout << "\n\nThank you for your using this soft!（谢谢使用！）\n"; 
		cout << "Please Enter anykeys to exit!";
		getch();		
		return 0;
	}
	else
	{	
		Step=0;
		cout << "If you want to go first ,please enter 1. Or not enter any other key.";
		cin >> a;
		if(a!='1')	Flag=1;
		else Flag=0;
		unitdata();
		Per_Com();
	}
}
int unitdata()
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			Table[i][j]=0;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			for(int k=0;k<4;k++)
			{
				Computer[i][j][k]=0;
				Player[i][j][k]=0;
			}
}
int deuce()
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			if(Table[i][j]==0)	return 0;
	return 1;
}
int Recoverboard()
{
	Step=0;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			map[i][j][0]=copymap[i][j][0];
		 	map[i][j][1]=copymap[i][j][1];
		}
}
int CopyB()
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			copymap[i][j][0]=map[i][j][0];
			copymap[i][j][1]=map[i][j][1];
		}
}

int See()
{
	char a; 
	cout << " \n\t由于时间有限！\n\t正在建设中......\n\t是否返回主界面？(y/n):"; 
	cin >> a;
	if(a=='n')	return 0;
	else Interface(); 
} 
int Per_Com()
{
	unitboard();
	//Step++;
	Showboard();
	ComPlay();
	while(cin >> x >> y)
	{
		if(x==0&&y==0)	
		{
			Recoverboard();
			Interface();
			break;
		}
		if(Overflow()) continue;
		if(!legal())
		{
			cout << "此位置已有子！请重新输入：";
			continue;
		}
		x--;y--;
		map[x][y][0]=-95;
		map[x][y][1]=-15;
		Step++;
		Showboard();
		flag=0;
		if(judgewin())	
		{	
			cout << "You win! Again?(y/n)" ;
			break;
		}
		if(deuce())	
		{
			cout << "You are equal to Computer! Again?(y/n)";
			break;
		}
		cout << endl;
		Table[x][y]=1;
		int result=ComPlay();
		if(result==2)
		{
			cout << "You lose! Again?(y/n)";	
			break;
		}
		if(result==3)	
		{
			cout << "You are equal to Computer! Again?(y/n)";
			break;
		}
	}
	
	cin >> Switch;
	if(Switch!='n')	
		Interface();
	return 1;
}
int ComPlay()
{//人工智能算法 
	int cx=7,cy=8;
	if(Flag==1)	
	{//computer先走 
		cx=rand()%5+4;
		cy=rand()%5+4;
		map[cx][cy][0]=-95;
		map[cx][cy][1]=-16;
		Showboard();
		cout << "Your turns(Good luck!):";
		Table[cx][cy]=2;
		Flag=7;
		return 7;
	}
	if(Flag==0)	
	{ //人先走 
		cout << "Your turns(Good luck!):";
		Flag=8;
		return 8;
	}
	float log=0;
	if(Flag==7)
	{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
			{
				int k,t;
				log=0;
				for(k=j+1;Table[i][k]==2&&k<16;k++)
					log++;
				if(k==16)	log-=0.5;
				else if(Table[i][k]==1)	log-=0.5;
				for(k=j-1;Table[i][k]==2&&k>=0;k--)
					log++;
				if(k==-1)	log-=0.5;
				else if(Table[i][k]==1)	log-=0.5;
				Computer[i][j][0]=log;
				if(Computer[i][j][0]==2.5)	log+=0.5;
				for(k=i+1;Table[k][j]==2&&k<16;k++)
					log++;
				if(k==16)	log-=0.5;
				else if(Table[k][j]==1)	log-=0.5;
				for(k=i-1;Table[k][j]==2&&k>=0;k--)
					log++;
				if(k==16)	log-=0.5;
				else if(Table[k][j]==1)	log-=0.5;
				Computer[i][j][1]=log;
				if(Computer[i][j][1]==2.5)	log+=0.5;
				log=0;
				for(k=i-1,t=j-1;Table[k][t]==2&&k>=0&&t>=0;k--,t--)
					log++;
				if(k==-1||t==-1)	log-=0.5;
				else if(Table[k][t]==1)	log-=0.5;
				for(k=i+1,t=j+1;Table[k][t]==2&&k<16&&t<16;k++,t++)
					log++;
				if(k==16||t==16)	log-=0.5;
				else if(Table[k][t]==1)	log-=0.5;
				Computer[i][j][2]=log;
				if(Computer[i][j][2]==2.5)	log+=0.5;
				log=0;
				for(k=i-1,t=j+1;Table[k][t]==2&&k>=0&&t<16;k--,t++)
					log++;
				if(k==-1||t==16)	log-=0.5;
				else if(Table[k][t]==1)	log-=0.5;
				for(k=i+1,t=j-1;Table[k][t]==2&&t>=0&&k<16;k++,t--)
					log++;
				if(k==16||t==-1)	log-=0.5;
				else if(Table[k][t]==1)	log-=0.5;
				Computer[i][j][3]=log;
				if(Computer[i][j][3]==2.5)	log+=0.5;
				
				
				
				log=0;
				for(k=j+1;Table[i][k]==1&&k<16;k++)
					log++;
				if(k==16)	log-=0.5;
				else if(Table[i][k]==2)	log-=0.5;
				for(k=j-1;Table[i][k]==1&&k>=0;k--)
					log++;
				if(k==-1)	log-=0.5;
				else if(Table[i][k]==2)	log-=0.5;
				Player[i][j][0]=log;
				
				log=0;
				for(k=i+1;Table[k][j]==1&&k<16;k++)
					log++;
				if(k==16)	log-=0.5;
				else if(Table[k][j]==2)	log-=0.5;
				for(k=i-1;Table[k][j]==1&&k>=0;k--)
					log++;
				if(k==-1)	log-=0.5;
				else if(Table[k][j]==2)	log-=0.5;
				Player[i][j][1]=log;

				log=0;
				for(k=i-1,t=j-1;Table[k][t]==1&&k>=0&&t>=0;k--,t--)
					log++;
				if(k==-1||t==-1)	log-=0.5;
				else if(Table[k][t]==2)	log-=0.5;
				for(k=i+1,t=j+1;Table[k][t]==1&&k<16&&t<16;k++,t++)
					log++;
				if(k==16||t==16)	log-=0.5;
				else if(Table[k][t]==2)	log-=0.5;
				Player[i][j][2]=log;
				
				log=0;
				for(k=i-1,t=j+1;Table[k][t]==1&&k>=0&&t<16;k--,t++)
					log++;
				if(k==-1||t==16)	log-=0.5;
				else if(Table[k][t]==2)	log-=0.5;
				for(k=i+1,t=j-1;Table[k][t]==1&&t>=0&&k<16;k++,t--)
					log++;
				if(k==16||t==-1)	log-=0.5;
				else if(Table[k][t]==2)	log-=0.5;
				Player[i][j][3]=log;
			}
		}
	log=0;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
				for(int k=0;k<4;k++)
				{
					if(Computer[i][j][k]>=log)	
					{
						log=Computer[i][j][k];
						cx=i;
						cy=j;
					}
				}
		}
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
				for(int k=0;k<4;k++)
					if(Player[i][j][k]>=2.5)
						if(Player[i][j][k]>=log)	
						{
							log=Player[i][j][k];
							cx=i;
							cy=j;
						}
					else
						if(Player[i][j][k]>log)	
						{
							log=Player[i][j][k];
							cx=i;
							cy=j;
						}
		}
	}
	if(Flag==8)
	{
		for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
			{
				int k,t;
				log=0;
				for(k=j+1;Table[i][k]==2&&k<16;k++)
					log++;
				for(k=j-1;Table[i][k]==2&&k>=0;k--)
					log++;
				Computer[i][j][0]=log;
				for(k=i+1;Table[k][j]==2&&k<16;k++)
					log++;
				for(k=i-1;Table[k][j]==2&&k>=0;k--)
					log++;
				Computer[i][j][1]=log;
				log=0;
				for(k=i-1,t=j-1;Table[k][t]==2&&k>=0&&t>=0;k--,t--)
					log++;
				for(k=i+1,t=j+1;Table[k][t]==2&&k<16&&t<16;k++,t++)
					log++;
				Computer[i][j][2]=log;
				log=0;
				for(k=i-1,t=j+1;Table[k][t]==2&&k>=0&&t<16;k--,t++)
					log++;
				for(k=i+1,t=j-1;Table[k][t]==2&&t>=0&&k<16;k++,t--)
					log++;
				Computer[i][j][3]=log;
				
				
				log=0;
				for(k=j+1;Table[i][k]==1&&k<16;k++)
					log++;
				for(k=j-1;Table[i][k]==1&&k>=0;k--)
					log++;
				Player[i][j][0]=log;
				log=0;
				for(k=i+1;Table[k][j]==1&&k<16;k++)
					log++;
				for(k=i-1;Table[k][j]==1&&k>=0;k--)
					log++;
				Player[i][j][1]=log;
				log=0;
				for(k=i-1,t=j-1;Table[k][t]==1&&k>=0&&t>=0;k--,t--)
					log++;
				for(k=i+1,t=j+1;Table[k][t]==1&&k<16&&t<16;k++,t++)
					log++;
				Player[i][j][2]=log;
				log=0;
				for(k=i-1,t=j+1;Table[k][t]==1&&k>=0&&t<16;k--,t++)
					log++;
				for(k=i+1,t=j-1;Table[k][t]==1&&t>=0&&k<16;k++,t--)
					log++;
				Player[i][j][3]=log;
			}
		}
	log=0;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
				for(int k=0;k<4;k++)
					if(Computer[i][j][k]>log)	
					{
						log=Computer[i][j][k];
						cx=i;
						cy=j;
					}
		}
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			if(Table[i][j]==0)
				for(int k=0;k<4;k++)
					if(Player[i][j][k]>=log)	
					{
						log=Player[i][j][k];
						cx=i;
						cy=j;
					}
		}
	}
	map[cx][cy][0]=-95;
	map[cx][cy][1]=-16;
	//system("PAUSE");  
	Showboard();
	cout << "Your turns:(Good luck!)";
	Table[cx][cy]=2;
	flag=1;
	x=cx;
	y=cy;
	if(judgewin())	return 2;
	if(deuce())	return 3;
	return 1;
}
int unitboard()
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
			map[i][j][0]=copymap[i][j][0];
			map[i][j][1]=copymap[i][j][1];
		}
	return 1;
}
int judgewin()
{
	int cx,cy,dx,dy;
	char a0=-95;
	char a1=-16;
	if(flag==0)
	{
		a1=-15;
	}
	cx=x;cy=y;dx=x;dy=y;
	while(map[cx][cy][0]==a0&&map[cx][cy][1]==a1)
	{
		cx--;cy--;
		if(cx<0||cy<0)	break;
	}
	while(map[dx][dy][0]==a0&&map[dx][dy][1]==a1)
	{
		dx++;dy++;
		if(dx>15||dy>15)	break;
	}
	if(dx>=(cx+6)||dy>=(cy+6))	return 1;
	cx=x;cy=y;dx=x;dy=y;
	while(map[cx][cy][0]==a0&&map[cx][cy][1]==a1)
	{
		cx--;
		if(cx<0)	break;
	}
	while(map[dx][dy][0]==a0&&map[dx][dy][1]==a1)
	{
		dx++;
		if(dx>15)	break;
	}
	if(dx>=(cx+6))	return 1;
	cx=x;cy=y;dx=x;dy=y;
	while(map[cx][cy][0]==a0&&map[cx][cy][1]==a1)
	{
		cy--;
		if(cy<0)	break;
	}
	while(map[dx][dy][0]==a0&&map[dx][dy][1]==a1)
	{
		dy++;
		if(dy>15)	break;
	}
	if(dy>=(cy+6))	return 1;
	cx=x;cy=y;dx=x;dy=y;
	while(map[cx][cy][0]==a0&&map[cx][cy][1]==a1)
	{
		cx++;cy--;
		if(cx>15||cy<0)	break;
	}
	while(map[dx][dy][0]==a0&&map[dx][dy][1]==a1)
	{
		dx--;dy++;
		if(dx<0||dy>15)	break;
	}
	if(cx>=(dx+6)||dy>=(cy+6))	return 1;
	return 0;
}
int Showboard()
{
	//system("CLS");
	cout << "   ";
	for(int s=1;s<=16;s++)
	{
		if(s>=10) cout << s-10 << " "; 
		else cout << s << " "; 
	}
	cout << endl;
	for(int i=0;i<16;i++)
	{
		printf("%2d",i+1);
		for(int j=0;j<16;j++)				
			cout << map[i][j];
		if(i==6)	cout << "退出：输入: 0 0 ";
		if(i==8)	cout << "步数(Step)：" << Step;
		if(i==10)	cout << "版本信息：1.0.0。";
		if(i==12)	cout << "制作人：Caizhicong。"; 
		if(i==14)	cout << "请输入棋子的纵坐标、横坐标下子！" ; 
		cout << endl;
		
	}
	return(1);
}
bool legal()
{
	if((map[x-1][y-1][0]==-95&&map[x-1][y-1][1]==-16)||(map[x-1][y-1][0]==-95&&map[x-1][y-1][1]==-15))
		return 0;
	else 
		return 1;	 
}
bool Overflow()
{
	if(x>16||x<1||y>16||y<1)	
		{
			cout << "It is imlegal!Please Reenter:\n(此位置不合法！请重新输入：)";
			return 1;
		} 
	else 
		return 0;
}
int Play()
{//人人对战 
	Showboard();
	cout << "白方下:";
	while(cin >> x >> y)
	{
		if(x==0&&y==0)	
		{
			Recoverboard();
			Interface();
			break;
		}
		if(Overflow())	continue;
		if(legal()) 
		{
			x--;y--;
			map[x][y][0]=-95;
			if(flag==1)
			{
				map[x][y][1]=-16;
				Step++;
				Showboard();
				if(judgewin())
				{
					cout << "\n黑方胜利了！\n" ; 
					cout << "Game over! ---Again?(y/n)";
					cin >> Switch;
					if(Switch!='n')	
					{
						unitboard();
						Play();
					}
					else  return 1;
				}
				cout << "黑方下:";
				flag=0;
			}
			else
			{
				map[x][y][1]=-15;
				Step++;
				Showboard();
				if(judgewin())
				{
					cout << "\n白方胜利了！" << endl;
					cout << "Game over! ---Again?(y/n)";
					cin >> Switch;
					if(Switch!='n')	
					{
						unitboard();
						Play();
					}
				 	else return 1;
				}
				cout << "白方下:";
				flag=1;
			}
		}
		else 
		{
			cout << "It already have a chessman!Please Reenter:\n此位置已有子!请重新输入：";
		}
	}
}
int main()
{
	CopyB();
	Interface();
}
