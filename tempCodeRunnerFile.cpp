
        for (int j = n - 1; j > 0; j--)
        {
            res += mat[i][j];
            printf("mat[%d][%d]=%d mat[%d][%d]=%d\n", i, j, mat[i][j], i + 1, j - 1, mat[i + 1][j - 1]);
            n--;
            break;
            // res += mat[i][j] + mat[i + 1][j - 1];
            // printf("res=%d\n", res);
            // i++;
            // res -= mat[i][j - 1];
        }