//자료 구조를 접목하여 수정 필요
//배열사이즈를 1920 x 1080일때도 먹힐지 확인 필요함
//배열사이즈가 커질 경우 Clustered배열에 담기는 값이 매우 커질것임. 이것을 줄이기 위한 작업도 필요함.

#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;


#define WIDTH 1000
#define HEIGHT 1000
#define DEPTH 3
int Cluster_cnt = 1;
int another_Cluster = 0;

int graph[WIDTH * HEIGHT] = //list 자료구조 대체 가능할듯
{
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	// 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
	// 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
int Visited[WIDTH * HEIGHT] = 
{
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};     
int Clustered[WIDTH * HEIGHT] = 
{
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};   

unsigned char BMP[WIDTH * HEIGHT * DEPTH] = 
{
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
}; 

int DFS(int i, int mCluster_cnt) 
{


	if (graph[i] == 1 && Visited[i] == 0) 
	{   
		another_Cluster = 1;
		//cout << "* C i : " <<  i <<endl;
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
		//cout << "* N i : " <<  i <<endl;
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
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hinfo;

	int width = 0, height = 0;
	FILE* f = NULL;
	f = fopen("C:\\Users\\MAUV3\\source\\repos\\DFS\\x64\\Release\\REALDATA.bmp", "r");
	if (f == NULL)
	{
		printf("fail to read file");
		return NULL; 
	}
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, f);
	fread(&hinfo, sizeof(BITMAPINFOHEADER), 1, f);

	width = hinfo.biWidth;
	height = hinfo.biHeight;

	printf("2. Width :%d \t Height :%d\t Image Size :%d\n", width, height, hinfo.biSizeImage);

	BYTE* InputImg = NULL;

	InputImg = (BYTE*)malloc(sizeof(BYTE) * hinfo.biSizeImage);
	fread(InputImg, sizeof(BYTE), hinfo.biSizeImage, f);

	fclose(f);

	if (hf.bfType == 0x4D42)
	{
		printf("bmp format image\n");
	}
	else
	{
		printf("wrong file type input\n");
	}

	for(int i  = 0 ; i <  WIDTH * HEIGHT; i++)
	{
		if( InputImg[i*3] > 240)
			graph[i] = 1;
		else
			graph[i] = 0;
	}

	int j = 0;
	// while(1)
	{
		for(int i = 0 ; i < WIDTH * HEIGHT; i++)
			DFS(i, Cluster_cnt);

		cout << "test :  " << j <<  endl;

		for(int i  = 0 ; i <  WIDTH * HEIGHT * DEPTH; i+=3)
		{

			if( Clustered[i/3] != 0)
			{
				// cout << "i : " << i << endl;
				Clustered[i/3] = 255;

				BMP[i] = Clustered[i/3];
				BMP[i+1] = Clustered[i/3];
				BMP[i+2] = Clustered[i/3];
			}
			else
			{
				BMP[i] = 0;
				BMP[i + 1] = 0;
				BMP[i + 2] = 0;
			}

		}
		j++;
	}

	
	

	// 파일에 다시 기록..
	f = fopen("C:\\Users\\MAUV3\\source\\repos\\DFS\\x64\\Release\\test.bmp", "w");
	fwrite(&hf, sizeof(unsigned char), sizeof(BITMAPFILEHEADER), f);
	fwrite(&hinfo, sizeof(unsigned char), sizeof(BITMAPINFOHEADER), f);
	fwrite(BMP, sizeof(unsigned char), hinfo.biSizeImage, f);
	fclose(f);
		
	return 0;
}