#include <stdio.h>
int current[11] = {0}, result[2680][11] = {{0}}, sol = 0;

void solve(int row, int col)
{
    for (int i = 0; i < col; i++){
        int flag = 1;
        for (int j = 0; j < row; j++){
            if (i == current[j] || i == current[j] + row - j ||
                i == current[j] - (row - j))
            {
                flag = 0;
                break;
            }
        }
        if (flag){
            current[row] = i;
            if (row == (col - 1)){
                for (int k = 0; k < col; k++)
                    result[sol][k] = current[k];

                sol++;
                break;
            }
            solve(row + 1, col);
        }
    }
}

int main()
{
    int length = 0; scanf("%d", &length);
    long long board[11][11], largest2[2] = {-1e12, -1e12};
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            scanf("%lld", &board[i][j]);
    
    solve(0, length);
    for (int k = 0; k < sol; k++){
        long long currentAns = 0;
        for (int j = 0; j < length; j++)
            currentAns += board[j][result[k][j]];
        
        if(currentAns != largest2[0] && currentAns != largest2[1]){
            if (currentAns > largest2[1]){
                largest2[0] = largest2[1];
                largest2[1] = currentAns;
            }
            else if(currentAns > largest2[0])
                largest2[0] = currentAns;
        }
    }
    (largest2[0] == -1e12) ? printf("Invalid\n") : printf("%lld\n", largest2[0]);
    return 0;
}