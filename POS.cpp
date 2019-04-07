#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <algorithm>
#define Max 50
long column ; // number of elemenst
long row ;
//long combination;
using namespace std;
void decToBinary(long n, long binaryNumArray[],long *size)
{
	long binaryNum[n];
	long* tempbinaryNumArray;
	tempbinaryNumArray = new long[n];
	// counter for binary array
	long i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	long k=0;
	// prlonging binary array in reverse order
	for (long j = i - 1; j >= 0; j--)
	{
		tempbinaryNumArray[k]=binaryNum[j];
		k++;
	}
	*size=k;
	for (long q=0;q<k;q++)
		binaryNumArray[q]=tempbinaryNumArray[k-q-1];
}
//=========================MAIN PROGRAM=========================//
int main ()
{
	//-- Fetch File--//
	column = 0; // number of elemenst
	row = 0; // number of rows of the function
	ifstream data;
	string data1;
	data.open("first1.txt");
	// getline (istream& is, string& str, char delim);
	while (	 getline (data, data1, ')'))
	{
		if (row == 0)
		{
			for (long i =0; i< data1.size(); i++ )
			{
				if (data1[i] == ',')
				{
					column++;
				}
			}
		}
		row++;
	}
	row = row -1;
	//-- 2d array created using dynamic array--//
	long** input;
	long** input1;
	input = new long*[row];
	input1 = new long*[row];
	for (long i =0; i < row; i++)
	{
		input[i] = new long[column];
		input1[i] = new long[column];
	}
	data.close();
	data.clear();
	//-- collecting and inputing data longo array--//
	data.open("first1.txt");
	long r =0, col = 0; // r for row and col for column counter
	while(getline(data, data1))
	{
		for( long i = 0; i <data1.size(); i++)
		{
			if (data1[i] == '0')
			{
				input[r][col] = 0;
				col++;
			}
			else if (data1[i] == '1')
			{
				input[r][col] = 1;
				col++;
			}
			else if (data1[i] == '-')
			{
				input[r][col] = -1;
				col+=1;
				i++;
			}
			if (col >= column)
			{
				r++;
				col = col - column;
			}
		}
	}
	data.close();
	// -- Prlonged collected data-//
	for (long i = 0; i < row; i++)
	{
		for(long j = 0; j < column; j++ )
		{
			input1[i][j]=input[i][column-j-1];

		}
		cout<< endl;
	}
	cout << "numer of column = "<< column << endl;
	cout << "number of rows = "<< row << endl;
	//--Determine combination--//*/
	long combination= pow (2, column);/// total number of combination
	cout << "total number of combinations = " << combination << endl;

	long binarray[combination],size;

	long** combarray;
	combarray = new long*[combination];

	for (long i =0; i < row; i++)
	{
		combarray[i] = new long [column];
	}

	decToBinary(combination,binarray,&size);

	for (long rows=0;rows<combination;rows++)
	{
		decToBinary(rows,binarray,&size);
		for( long cols=0; cols<column;cols++)
		{
			combarray[rows][cols]=binarray[cols];
			//	cout << "     " << combarray[rows][cols];
		}
		//	cout << endl;
	}
	cout<<endl<<"The number of combinations:"<<combination;
	//--array for first processed data--//

	//=========================================
	long** element1;
	element1 = new long*[row];
	for (long i =0; i < row; i++)
	{
		element1[i] = new long[column];
	}


	cout << endl;
	// combination vs function
	//for (long i = 0; i< row; i++)
	//	{
	bool flag = false;
	int* element2;
	element2 = new int[row];

	/*for (long x = 0; x < row; x++)
		{
		element2[x] =0;
		}cout << endl;*/
	cout << " input[x][y] "<< endl;
	for (long x = 0; x < row; x++)
	{
		for(long y = 0; y < column; y++ )
		{
			cout << input[x][y];

		}cout << endl;
	}
	cout << endl;
	cout << " combarray[x][y] "<< endl;

	for (long x = 0; x < combination; x++)
	{
		for(long y = 0; y < column; y++ )
		{
			cout << combarray[x][y];

		}cout << endl;
	}
	cout << endl;
	int s = 1;
	for (long i = 0; i< combination ; i++)
	{
		for (long x = 0; x < row; x++)
		{
			element2[x] =0;
			for(long y = 0; y < column; y++ )
			{

				if (input[x][y] == 1)
				{
					element1[x][y] = combarray[i][y];
				}
				else if (input[x][y] == -1)
				{
					if(combarray[i][y] == 0)
					{
						element1[x][y] = 1;
					}
					else if(combarray[i][y] == 1)
						element1[x][y] = 0;
				}


				else
				{
					element1[x][y] = 0;
				}
				cout <<"  " <<  element1[x][y];

				element2[x] = element2[x]+ element1[x][y];
				//cout <<" e  " <<  element2[x];

			}cout << endl;
			if(element2[x] >= 1)
			{
				element2[x] = 1;
			}
			else
				element2[x] = 0;
			//cout <<endl <<"elementk " << element2[x];

		}
		for (long x = 0; x < row; x++)
		{
			cout << element2[x];

			s = s* element2[x];

		}cout << endl;
		if (s== 1)
		{
			cout << "true  at ";
			for(int a = i; a < i+1; a++)
			{
				for(int x = 0; x< column; x++)
				{
					cout << combarray[i][x];

				}

			}return 0;
		}
		cout << " end of comb loop" << i << endl;
	}
	cout  <<"system is false " ;
	return 0;
}