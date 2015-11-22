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
Варіант 1. Квадратна матриця дробових чисел
Розмір задає користувач перед початком сесії.
Команди:
    - !null              Обнулити всі елементи матриці
    - !random            Заповнити випадковими числами у діапазоні, що ввів користувач
    - !change            Змінити елемент масиву за введеним індексом на введене значення
    - !hor               Відобразити горизонтально
    - !secdia            Відобразити відносно побічної діагоналі
    - !rotate            Повернути так як у домашньому завданні (відповідно Вашому варіанту)
    - !sumall            Вивести суму елементів матриці
    - !sumcol            Вивести суму елементів заданого стовпця
    - !sumund            Вивести суму елементів під головною діагоналлю (з врахуванням елементів діагоналі)
    - !min1max1          Поміняти перший мінімальний і перший максимальний елементи у матриці місцями
    - !minlmaxl          Поміняти останній мінімальний і останній максимальний елементи у матриці місцями
    - !cmcm              Поміняти місцями стовпці з найбільшою сумою елементів і з найменшою сумою елементів
    - !help
    - !exit
*/
