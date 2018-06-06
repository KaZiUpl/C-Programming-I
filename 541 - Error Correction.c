#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int matrix_size;
    int i,j;
    int sum;
    int odd_row_counter,odd_col_counter;
    int row_pointer,col_pointer;

    while(scan("%d",&matrix_size) == 1 && matrix_size != 0)
    {
        int matrix[matrix_size+1][matrix_size+1];
        /* insterting data and summing rows*/
        FOR(i,0,matrix_size)
        {
            sum = 0;
            FOR(j,0,matrix_size)
            {
                scan("%d",&matrix[i][j]);
                sum += matrix[i][j];
            }
            matrix[i][matrix_size] = sum;
        }

        /* summing columns */
        FOR(i,0,matrix_size)
        {
            sum = 0;
            FOR(j,0,matrix_size)
            {
                sum += matrix[j][i];
            }
            matrix[matrix_size][i] = sum;
        }

        odd_row_counter = odd_col_counter = 0;
        FOR(i,0,matrix_size)
        {
            if(matrix[matrix_size][i]%2 == 1) odd_col_counter++;
        }
        FOR(i,0,matrix_size)
        {
            if(matrix[i][matrix_size]%2 == 1) odd_row_counter++;
        }

        if(odd_col_counter > 1 || odd_row_counter > 1) print("Corrupt\n");
        else if(odd_col_counter+odd_row_counter == 0) print("OK\n");
        else
        {
            row_pointer = col_pointer = -1;
            FOR(i,0,matrix_size)
            {
                if(matrix[matrix_size][i]%2 == 1) col_pointer = i+1;
            }
            FOR(i,0,matrix_size)
            {
                if(matrix[i][matrix_size]%2 == 1) row_pointer = i+1;
            }

            print("Change bit (%d,%d)\n",row_pointer,col_pointer);
        }
    }


    return 0;
}
