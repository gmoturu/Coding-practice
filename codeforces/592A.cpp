#include<iostream>
#define N 8
using namespace std;

int main()
{
	int board[N+1][N+1];
	for(int i=0;i<N+1;i++)
		for(int j=0;j<N+1;j++)
			board[i][j]=0;

	string lines;
	for(int i=0;i<N;i++)
	{
		cin>>lines;

		int j=0;
		for(const char *ptr=lines.c_str();*ptr!='\0';ptr++,j++)
		{
			if(*ptr=='B')
				board[i+1][j+1]=-1;
			else if(*ptr=='W')
				board[i+1][j+1]=1;
		}
	}

	for(int i=1;i<N+1;i++)
	{
		for(int j=1;j<N+1;j++)
			cout<<board[i][i]<<" ";
		cout<<"\n";
	}

/*
	for(int i=1;i<N+1;i++)
		if(!white_pawns[i])
			for(int j=i-1;j>0;j--)
				if(black_pawns[i]==white_pawns[i])
				{
					black_pawns[i]=white_pawns[i];
					i--;
				}
	int sum_white=0,sum_black=0;
	for(int i=1;i<N+1;i++)
	{
		if(!white_pawns[i])
			sum_white+=white_pawns[i]-1;
		if(!black_pawns[i])
			sum_black+=N-black_pawns[i];
	}

	cout<<sum_white<<" "<<sum_black<<endl;
*/
	return 0;

}
