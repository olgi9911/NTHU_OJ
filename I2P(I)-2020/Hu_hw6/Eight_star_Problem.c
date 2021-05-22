#include <stdio.h>
int current[10] = {0}, result[724][10] = {{0}}, sol = 0;

void EightStar(int row, int col)
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
            EightStar(row + 1, col);
        }
    }
}

int main()
{
    int length = 0;
    scanf("%d", &length);
    long long board[10][10] = {{0}}, ans = -10000000000;
    EightStar(0, length);
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            scanf("%lld", &board[i][j]);
    for (int k = 0; k < sol; k++){
        long long currentAns = 0;
        for (int j = 0; j < length; j++)
            currentAns += board[j][result[k][j]];

        if (currentAns > ans)
           ans = currentAns;
    }
    (sol == 0) ? printf("no solution\n") : printf("%lld\n", ans);
    return 0;
}