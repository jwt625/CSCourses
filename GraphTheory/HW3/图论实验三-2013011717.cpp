//*********************//
//**Huffman Coding**//
//By  jwt 2013011717//
//*********************//
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;
class HuffTree
{
private:
	HuffTree* LeftChild;
	HuffTree* RightChild;
	float m_Priority;
	char m_ch;
public:
	HuffTree(){LeftChild = NULL; RightChild = NULL; m_Priority = 0; m_ch = NULL;}
	HuffTree(HuffTree* pLeft, HuffTree* pRight, char ch, float pri){LeftChild = pLeft; RightChild = pRight; m_ch = ch; m_Priority = pri;}
	~HuffTree(){delete LeftChild; delete RightChild;}
	void changeHuffTree(HuffTree* pLeft, HuffTree* pRight, char ch, float pri){LeftChild = pLeft; RightChild = pRight; m_ch = ch; m_Priority = pri;}
	HuffTree* getLeftChild()const{return LeftChild;}
	HuffTree* getRightChild()const{return RightChild;}
	float getPriority()const{return m_Priority;}
	char getChar()const{return m_ch;}
};
class compareNode
{
public:
	bool operator() (HuffTree* HT1, HuffTree* HT2)
	{
		return HT1->getPriority() > HT2->getPriority();
	}
};
HuffTree* creatTreeNode(HuffTree* pLeft = NULL, HuffTree* pRight = NULL, char ch = NULL, float pri = 0)
{
	HuffTree* tempHT = new HuffTree;
	tempHT->changeHuffTree(pLeft, pRight, ch, pri);
	return tempHT;
}
int findChar(char* tempChar, int len, char chToFind);
int getFileLen();
char* getFullFile();
int countChar(char* tempChar, char chToCount, int len);
HuffTree* creatTree(char* diffChar, int* diffCharCount, int numOfDiffChar);
int getLen(HuffTree* tempNode, int depth);
int main()
{
	ofstream outFile("2013011717.txt", ios::out);
	char* FullFile = getFullFile();								//读入文件中的所有字符
	int FileLen = getFileLen();								//	计算总文件的字符数
	//cout<<FileLen<<endl;
	if(FileLen == 1)
	{
		outFile<<0;
		outFile.close();
		return 0;
	}
	if(FileLen == 2)
	{
		outFile<<1;
		outFile.close();
		return 0;
	}
	system("pause");
	/*for(int i =0; i<FileLen-1; i++)
	{
		outFile<<FullFile[i];
	}*/
	char* diffChar = new char[FileLen];
	for(int i =0; i<FileLen-1; i++)
		diffChar[i] = 0;
	int* diffCharCount = new int[FileLen];
	int numOfDiffChar = 0;
	for(int i =0; i<FileLen-1; i++)
	{
		if(!findChar(diffChar,FileLen,FullFile[i]))
		{
			diffChar[numOfDiffChar] = FullFile[i];
			diffCharCount[numOfDiffChar] = countChar(FullFile, FullFile[i], FileLen);
			numOfDiffChar++;
		}
	}
	/*cout<<endl;
	int tempcount = 0;
	for(int i = 0; i < numOfDiffChar; i++)
	{
		cout<<diffChar[i]<<":"<<diffCharCount[i]<<endl;
		tempcount += diffCharCount[i];
	}
	cout<<tempcount<<endl;*/
	HuffTree* rootNode = creatTree(diffChar, diffCharCount, numOfDiffChar);
	/*cout<<rootNode->getPriority()<<endl;
	int newFileLen = getLen(rootNode, 0);
	cout<<newFileLen<<endl;*/
	outFile<<getLen(rootNode, 0);
	//system("pause");
	outFile.close();
	return 0;
}
int findChar(char* tempChar, int len, char chToFind)
{
	for(int i = 0; i < len; i++)
	{
		if(tempChar[i] == chToFind)
			return i+1;
	}
	return 0;
}
int getFileLen()
{
	ifstream inFileTemp("input.txt", ios::in);
	if(!inFileTemp.is_open())					//判断打开文件是否成功
	{
		cout<<"Could not open the file input.txt\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	int FileLength = 0;					//获取文件总长度
	while(inFileTemp && !inFileTemp.eof())
	{
		char chTemp;
		chTemp = inFileTemp.get();
		FileLength++;
	}
	inFileTemp.close();
	return FileLength;
}
char* getFullFile()
{
	int FileLength = getFileLen();
	//cout<<FileLength;
	//system("pause");
	char *FullFile= new char[FileLength];	

	ifstream inFile("input.txt", ios::in);

	if(!inFile.is_open())					//判断打开文件是否成功
	{
		cout<<"Could not open the file input.txt\n";
		system("pause");
		exit(EXIT_FAILURE);
	}

	char ch;
	ch = inFile.get();
	int tempCount = 0;
	FullFile[tempCount] = ch;
	while(inFile && !inFile.eof())
	{
		ch = inFile.get();
		tempCount++;
		FullFile[tempCount] = ch;
	}	

	inFile.close();
	return FullFile;
}
int countChar(char* tempChar, char chToCount, int len)
{
	int count = 0;
	for(int i =0 ; i < len - 1; i++)
	{
		if(tempChar[i] == chToCount)
			count++;
	}
	return count;
}
HuffTree* creatTree(char* diffChar, int* diffCharCount, int numOfDiffChar)
{
	priority_queue<HuffTree*, vector<HuffTree*>, compareNode> treeQueue;
	for(int i = 0; i < numOfDiffChar; i++)
		treeQueue.push(new HuffTree(NULL, NULL, diffChar[i], diffCharCount[i]));

	while(treeQueue.size()>1)
	{
		HuffTree* leftChild = treeQueue.top();
		treeQueue.pop();
		HuffTree* rightChild = treeQueue.top();
		treeQueue.pop();
		/*int tempDepth = max(leftChild->getDepth(), rightChild->getDepth());
		leftChild->changeDepth(tempDepth);
		rightChild->changeDepth(tempDepth);
		cout<<leftChild->getChar()<<" : prio: "<<leftChild->getPriority()<<" : dep: "<<leftChild->getDepth()<<endl;
		cout<<rightChild->getChar()<<" : prio: "<<rightChild->getPriority()<<" : dep: "<<rightChild->getDepth()<<endl;*/
		treeQueue.push(new HuffTree(leftChild, rightChild, NULL, leftChild->getPriority() + rightChild->getPriority()));
	}
	return treeQueue.top();
}
int getLen(HuffTree* tempNode, int depth)
{
	if(tempNode == NULL)
		return 0;
	if((tempNode->getLeftChild() == NULL)&&(tempNode->getRightChild() == NULL))
	{
		//cout<<tempNode->getChar()<<": priority: "<<tempNode->getPriority()<<" : depth: "<<depth<<endl;
		return tempNode->getPriority()*depth;
	}
	return getLen(tempNode->getLeftChild(), depth + 1)+getLen(tempNode->getRightChild(), depth + 1);
}