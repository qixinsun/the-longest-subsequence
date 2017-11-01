/********************************
* use m colors for map coloring *
* date: 20171101                *
* author: sunqixin              *
*********************************/

#include <iostream>

using namespace std;
int length = 0;
void LCS(int i, int j, char*x, int **b)
{  //output the LCS
    if(i==0||j==0)
        return;
    if(b[i][j]==1)  //upper left
    {
        LCS(i-1, j-1, x, b);  //reverse to output the CLS, because we reverse to find the longest subsequence
        cout << x[i] << " ";
        length++;
    }
    if(b[i][j]==2)  //if the value of this point is 2, it means that the length of this sub-sequence is from the upper side
    {
        LCS(i-1, j, x, b);
    }
    if(b[i][j]==3)  //left side
    {
        LCS(i, j-1, x, b);
    }

}

void LCSlength(int m, int n, char x[], char y[])
{
    int c[m+1][n+1];
    int **b;
    b = new int* [m+1];
    for(int i=0; i<m+1; i++)
        b[i] = new int[n+1];
    for(int i=0; i<n+1; i++)  //initialization, if the length of the subsequence is zero, the longest subsequence is zero.
        c[0][i] = 0;
    for(int i=0; i<m+1; i++)
        c[i][0] = 0;

    for(int i=1; i<m+1; i++)
        for(int j=1; j<n+1; j++)
    {  //recursive relationship formula
        if(x[i]==y[j])  //i advise you to see video lecture on mooc to get the formula, then you wiil be easy to understand this part
        {
            c[i][j] = c[i-1][j-1] + 1;
            b[i][j] = 1;
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j] = c[i-1][j];
            b[i][j] = 2;
        }
        else
        {
            c[i][j] = c[i][j-1];
            b[i][j] = 3;
        }
    }
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    LCS(m, n, x, b);
    cout << "\nthe lengthLCS is " << length;
}
int main()
{
    char x[] = {'\0','a', 'b', 'c', 'd'};  //we add a null char in the first position of x and y, this is determined by our formula
    char y[] = {'\0','b', 'd'};
    LCSlength(4, 2, x, y);
}


