// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int randing = 9; //формир матрицу c элементами 0-9

void randomiseMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = random(randing); 
        }
    }
    return;
}

//объявить свои функции
int** matrixMulti(int** matrix1, int n1, int m1, int** matrix2, int n2, int m2);//традиционный способ циклом


void setup() {
  randomSeed(analogRead(0)); // автоматическая рандомизация
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 2);
  // Print a message to the LCD.

  int n1 = 2, n2 = 2, m1 = 2, m2 = 2;

    //Матрица n1 x m1
    int** matrix1;
    //Матрица n2 x m2
    int** matrix2;

    matrix1 = (int**)malloc(sizeof(int*) * n1);
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int*)malloc(sizeof(int) * m1);
    }
    matrix2 = (int**)malloc(sizeof(int*) * n2);
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int*)malloc(sizeof(int) * m2);
    }

    //Генерируем случайные матрицы для умножения
    randomiseMatrix(matrix1, n1, m1);
    randomiseMatrix(matrix2, n2, m2);

   //данные матрицы 1
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            lcd.setCursor(0 + (j * 2), i);
            lcd.print(String(matrix1[i][j]) + " ");
        }
    }
    lcd.setCursor(4, 0);
    lcd.print("*");
    lcd.setCursor(4, 1);
    lcd.print("*");
    //данные матрицы 2
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            lcd.setCursor(5 + (j * 2), i);
            lcd.print(String(matrix2[i][j]) + " ");
        }
    }
    lcd.setCursor(9, 0);
    lcd.print("=");
    lcd.setCursor(9, 1);
    lcd.print("=");    
    //Матрица с результатом
    int** matrixres;

    matrixres = matrixMulti(matrix1, n1, m1, matrix2, n2, m2);

    lcd.setCursor(10, 0);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            lcd.setCursor(10 + (j * 3), i);
            lcd.print(String(matrixres[i][j]) + " ");
        }
    }

  delete[] matrix1, matrix2, matrixres;
}

void loop() {
  // передвигающийся текст к последнему заданию
  delay(700); 
  lcd.scrollDisplayLeft();
}

//Производит умножение матрицы размером n1 x m1
//на матрицу размером n2 x m2
int** matrixMulti(int** matrix1, int n1, int m1, int** matrix2, int n2, int m2) {
    //Если матрицы не согласованы, то не выполняем умножение
    if (m1 != n2) {
        return NULL;
    }
    //Выделяем память под результат умножения
    int** result;
    result = (int**)malloc(sizeof(int*) * n1);
    for (int i = 0; i < n1; i++) {
        result[i] = (int*)malloc(sizeof(int) * m2);
    }
    //Умножение по формуле
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    return result;
}