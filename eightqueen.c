// ��������飨�С��С�б�ߣ������������
// ��������ά�������ʺ�λ�á���ά������ȷ����Ĵ�š�����������顢


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define N 8
int array_line[N];     // �����
int first[2 * N - 1];  // ���Խ���
int second[2 * N - 1]; // ���Խ���
FILE *file;
int count = 0;
int board[N][N] = {0};



/*��������
void guideline();
void backqueen(int board[N][N], int row);
int issafe(int row, int line);
void Printboard(int board[N][N]);
void errornum();
void finish();
void serval();
int nqueen(int n);
void Printboard_n(int **board, int n);
void backqueen_n(int **board, int row, int *array_line, int *first, int *second, int n);
void menu();
void Return();

*/




// ������������
void errornum()
{
    printf("          ���ݴ���\n");
    printf("          ����������󷵻ز˵�\n");
    Sleep(3000);
}




/// @brief
void Return()
{
    printf("          ���»س������ز˵�\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // ������뻺����
    getchar(); // �ȴ��û�����һ���س�
}

void guideline()
{
    printf("\n\n              �˻ʺ�����Ĺ�������һ��8x8�������Ϸ��ð˸��ʺ�\n              ʹ���κ������ʺ��ܴ���ͬһ��,ͬһ�л�ͬһб����\n\n\n");
    Return();
}




// ����˻ʺ�����
int issafe(int row, int line)
{
    if (array_line[line] == 1) 
        return 0;
    if (first[row - line + N - 1] == 1)
        return 0;
    if (second[row + line] == 1)
        return 0;
    return 1;
}




void Printboard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(file, "%3d", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}



void backqueen(int board[N][N], int row)
{
    if (row == N)
    {
        Printboard(board);
        count++;
        return;
    }
    int line;
    for (line = 0; line < N; line++)
    {
        if (issafe(row, line) == 1)
        {
            board[row][line] = 1;
            array_line[line] = 1;
            first[row - line + N - 1] = 1;
            second[row + line] = 1;    // �ɹ������
            backqueen(board, row + 1); // ��ת��һ��
            board[row][line] = 0;      // ��һ��ʧ�ܺ󷵻���һ��
            array_line[line] = 0;
            first[row - line + N - 1] = 0;
            second[row + line] = 0;
        }
    }
}



void finish()
{
    file = fopen("display.txt", "w+");
    if (file == NULL)
    {
        printf("          ���ļ�����");
        Return();
        return;
    }
    backqueen(board, 0);
    fclose(file);
    printf("          ����%d�ֽⷨ\n", count);
    printf("          �Ѿ������д�д��display.txt��\n");
    printf("          ������Զ����ز˵�");
    count=0;
    Sleep(3000);
    return;
}




// ���´�����n�ʺ�����

int issafe_n(int row, int line, int *array_line, int *first, int *second, int n)
{
    if (array_line[line] == 1)
        return 0;
    if (first[row - line + n - 1] == 1)
        return 0;
    if (second[row + line] == 1)
        return 0;
    return 1;
}



void Printboard_n(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(file, "%3d", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}




void backqueen_n(int **board, int row, int *array_line, int *first, int *second, int n)
{
    if (row == n)
    {
        Printboard_n(board, n);
        count++;
        return;
    }
    for (int line = 0; line < n; line++)
    {
        if (issafe_n(row, line, array_line, first, second, n))
        {
            board[row][line] = 1;
            array_line[line] = 1;
            first[row - line + n - 1] = 1;
            second[row + line] = 1;
            backqueen_n(board, row + 1, array_line, first, second, n);
            board[row][line] = 0;
            array_line[line] = 0;
            first[row - line + n - 1] = 0;
            second[row + line] = 0;
        }
    }
}



int nqueen(int n)
{
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
        memset(board[i], 0, n * sizeof(int));
    }

    int *array_line = (int *)malloc(n * sizeof(int));
    int *first = (int *)malloc((2 * n - 1) * sizeof(int));
    int *second = (int *)malloc((2 * n - 1) * sizeof(int));
    memset(array_line, 0, n * sizeof(int));
    memset(first, 0, (2 * n - 1) * sizeof(int));
    memset(second, 0, (2 * n - 1) * sizeof(int));

    file = fopen("another_display.txt", "w+");
    if (file == NULL)
    {
        printf("          ���ļ�����\n");
        return 0;
    }
    count = 0;
    backqueen_n(board, 0, array_line, first, second, n);
    fclose(file);

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
    free(array_line);
    free(first);
    free(second);

    printf("          ����%d�ֽⷨ\n", count);
    if(count!=0)
        printf("          �Ѿ������д�д�� another_display.txt ��\n");
    else{
        printf("          �������޽�\n");
    }
    count=0;
    Return();
    return 0;
}



void serval()
{
    int n;
    printf("          ��������Ҫ�����N�ʺ�����,N��ֵΪ:");
    if (scanf("%d", &n) != 1)
    {
        errornum();
        return;
    }
    while (getchar() != '\n')
        ;
    if (n > 9 || n < 3)
    {
        errornum();
        return;
    }
    nqueen(n);
}

int quit()
{
    printf("          ���ڹرճ���\n");
    Sleep(1500);
    return 0;
}
          


// ���˵�
void menu()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("          ***************************************************************************************************          \n");
    printf("          *\033[1;31m                                        �� �� �� �� ��                                           \033[0m*          \n");
    printf("          *                                        1. ���н������                                          *          \n");
    printf("          *                                        2. ��ʺ����� (3-9)                                      *          \n");
    printf("          *                                        3. ��Ϸ����                                              *          \n");
    printf("          *                                        0. �˳�����                                              *          \n");
    printf("          *                                                                                                 *          \n");
    printf("          *                             ��ʾ: �ڱ�������, 1 ����ʺ�, 0 ����ո�                            *          \n");
    printf("          ***************************************************************************************************          \n");
    printf("          ����������ѡ��");
}



int main()
{
    int choice;
    do
    {
        menu();
        if (scanf("%d", &choice) != 1)
        {
            errornum();
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            finish();
            break;
        case 2:
            serval();
            break;
        case 3:
            guideline();
            break;
        case 0:
            quit();
            break;
        default:
            errornum();
            break;
        }
    } while (choice != 0);
    return 0;
}