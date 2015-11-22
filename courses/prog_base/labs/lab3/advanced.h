void showzone(int size);
void printmatrix(int size, float mat[size][size]);
void printmatrixsum(int size, float mat[size][size]);
void printmatrixcol(int size, float mat[size][size], int col);
void printmatrixch(int size, float mat[size][size], int indexl, int indexc);
void printmatrixund(int size, float mat[size][size]);

/*
    - !null             to zero all elements of the matrix
    - !random           to fill with random numbers in the range that the user entered
    - !change           to change the array element at index entered by the value entered
    - !hor              to flip horizontally
    - !secdia           to display relative to the secondary diagonal
    - !rotate           to rotate the matrix clockwise by 180 degrees
    - !sumall           to output the sum of elements of a matrix
    - !sumcol           to output the sum of a specified column
    - !sumund           to output the sum of elements below the main diagonal
    - !min1max1         to change the first minimum and the first maximum element in the matrix sometimes
    - !minlmaxl         to change the last minimum and last maximum elements in the matrix sometimes
    - !cmcm             to swap the columns with the largest sum of elements and the least amount of elements
*/

/*
������ 1. ��������� ������� �������� �����
����� ���� ���������� ����� �������� ���.
�������:
    - !null              �������� �� �������� �������
    - !random            ��������� ����������� ������� � �������, �� ��� ����������
    - !change            ������ ������� ������ �� �������� �������� �� ������� ��������
    - !hor               ³��������� �������������
    - !secdia            ³��������� ������� ������ �������
    - !rotate            ��������� ��� �� � ���������� ������� (�������� ������ �������)
    - !sumall            ������� ���� �������� �������
    - !sumcol            ������� ���� �������� �������� �������
    - !sumund            ������� ���� �������� �� �������� ��������� (� ����������� �������� �������)
    - !min1max1          ������� ������ ��������� � ������ ������������ �������� � ������� ������
    - !minlmaxl          ������� ������� ��������� � ������� ������������ �������� � ������� ������
    - !cmcm              ������� ������ ������� � ��������� ����� �������� � � ��������� ����� ��������
    - !help
    - !exit
*/
