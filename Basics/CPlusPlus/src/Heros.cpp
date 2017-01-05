#include"Heros.h"

void HEROS::insertHero(int size, char* tempName, int tempTime)
{
	int order;
	for(order = 0; (order < 3)&&(tempTime > m_heros[size][order].GameTime); order++);
	int i;
	for(i = 2; i > order; i-- )
	{
		int len;
		for(len = 0; m_heros[size][i-1].m_name[len] != '\0'; len++)
			m_heros[size][i].m_name[len] = m_heros[size][i-1].m_name[len];
		m_heros[size][i].m_name[len] = '\0';
		m_heros[size][i].GameTime = m_heros[size][i-1].GameTime;
	}
	int len;
	for(len = 0; tempName[len] != '\0'; len++)
		m_heros[size][i].m_name[len] = tempName[len];
	m_heros[size][i].m_name[len] = '\0';
	m_heros[size][i].GameTime = tempTime;
}
int HEROS::getHeroList()
{
	ifstream infile("heroList.txt");
	if(!infile.is_open())				//判断打开文件是否成功
	{
		return 0;
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			infile.getline(m_heros[i][j].m_name,22);
			/*infile.get(rubbish,1);
			for(int p = 0; p<9; p++)
			cout<<"rubbish:"<<rubbish[p];
			cout<<"  endofrub"<<endl;
			cout<<"name:"<<m_heros[i][j].m_name<<"  name end"<<endl;*/
			char temp[10];
			infile.getline(temp,22);
			int tempTime = 0;
			for(int p = 0; temp[p] != '\0'; p++)
				tempTime = tempTime*10 + temp[p] - 48;
			m_heros[i][j].GameTime = tempTime;
		}
	}
	infile.close();
	return 1;
}
int HEROS::getAndPrintHeroList()
{
	ifstream infile("heroList.txt");
	if(!infile.is_open())				//判断打开文件是否成功
	{
		cout<<"\n\t空空如也，赶快玩一把吧！";
		return 0;
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			infile.getline(m_heros[i][j].m_name,22);
			/*infile.get(rubbish,1);
			for(int p = 0; p<9; p++)
			cout<<"rubbish:"<<rubbish[p];
			cout<<"  endofrub"<<endl;
			cout<<"name:"<<m_heros[i][j].m_name<<"  name end"<<endl;*/
			char temp[10];
			infile.getline(temp,22);
			int tempTime = 0;
			for(int p = 0; temp[p] != '\0'; p++)
				tempTime = tempTime*10 + temp[p] - 48;
			m_heros[i][j].GameTime = tempTime;
		}
	}
	infile.close();
	int minute, second;
	for(int i = 0; i < 3; i++)
	{
		switch(i)
		{
		case 0:
			cout<<"\n\t初级：\n\n";
			break;
		case 1:
			cout<<"\n\t中级：\n\n";
			break;
		case 2:
			cout<<"\n\t高级：\n\n";
			break;
		}
		for(int j = 0; j < 3; j++)
		{
			switch(j)
			{
			case 0:
				cout<<"\t第一名：";
				break;
			case 1:
				cout<<"\t第二名：";
				break;
			case 2:
				cout<<"\t第三名：";
				break;
			}			
			if(((m_heros[i][j].m_name[0] == 'N')&&(m_heros[i][j].m_name[1] == 'U')&&(m_heros[i][j].m_name[2] == 'L')&&(m_heros[i][j].m_name[3] == 'L'))||(m_heros[i][j].m_name[0] == '\0'))
				cout<<"\t空空如也！"<<endl;
			else
			{
				cout<<"姓名：";
				for(unsigned int k = 0;m_heros[i][j].m_name[k] != '\0'; k++)
					cout<<m_heros[i][j].m_name[k];
				minute = m_heros[i][j].GameTime/60;
				second = m_heros[i][j].GameTime%60;
				cout<<"\n\t\t游戏时间："<<minute<<" 分 "<<second<<" 秒"<<endl;
			}
		}
	}
	return 1;
}
string HEROS::getName(int size, int order)const
{
	return m_heros[size][order].m_name;
}
int HEROS::getTime(int size, int order)const
{
	return m_heros[size][order].GameTime;
}
void HEROS::writeHeroList()const
{
	ofstream outfile("herolist.txt");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(unsigned int p = 0;  HEROS::getName(i, j)[p] != '\0' ; p++)
				outfile<<HEROS::getName(i, j)[p];
			outfile<<endl<<HEROS::getTime(i, j)<<endl;
		}
	}
	outfile.close();
}