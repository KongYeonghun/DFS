//자료 구조를 접목하여 수정 필요
//배열사이즈를 1920 x 1080일때도 먹힐지 확인 필요함
//배열사이즈가 커질 경우 Clustered배열에 담기는 값이 매우 커질것임. 이것을 줄이기 위한 작업도 필요함.

#include <stdio.h>
#include <iostream>

using namespace std;


#define WIDTH 10
#define HEIGHT 10
int Cluster_cnt = 1;
int another_Cluster = 0;

int graph[WIDTH * HEIGHT] = //list 자료구조 대체 가능할듯
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
int Visited[WIDTH * HEIGHT] = 
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};     
int Clustered[WIDTH * HEIGHT] = 
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};   

int DFS(int i, int mCluster_cnt) 
{


	if (graph[i] == 1 && Visited[i] == 0) 
	{   
		another_Cluster = 1;
		cout << "* C i : " <<  i <<endl;
		Visited[i] = 1;
		Clustered[i] = mCluster_cnt;

		int cnt1 = i + 1;
		int cnt2 = i - 1;
		int cnt3 = i + 10;
		int cnt4 = i - 10;

		if (cnt1 > 0 && cnt1 < WIDTH * HEIGHT)
			DFS(cnt1, mCluster_cnt);

		if (cnt2 > 0 && cnt2 < WIDTH * HEIGHT)
			DFS(cnt2, mCluster_cnt);

		if (cnt3 > 0 && cnt3 < WIDTH * HEIGHT)
			DFS(cnt3, mCluster_cnt);

		if (cnt4 > 0 && cnt4 < WIDTH * HEIGHT)
			DFS(cnt4, mCluster_cnt);
	}
	else
	{
		cout << "* N i : " <<  i <<endl;
		Visited[i] = 1;
		if(another_Cluster == 1)
		{
			Cluster_cnt++;
			another_Cluster = 0;
		}

	}

	return Clustered[i];
}

int main()
{
	for(int i = 0 ; i < WIDTH * HEIGHT; i++)
		DFS(i, Cluster_cnt);

	for(int i = 1 ; i <= WIDTH * HEIGHT; i++)
	{
		cout << Clustered[i-1] << " ";
		if(i%10== 0 && i > 9)
			cout << endl;
	}
		
	return 0;
}