#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int fillArray(int** arr, int cols, int rows, int count_lines) {

    int lines = 0;

    string s;
    ifstream in("C:\\Users\\vante\\source\\repos\\PathFinder\\PathFinder\\in.txt");

    while (lines != count_lines)
    {
        getline(in, s);
        lines++;
    }

    for (int i = 0; i < rows; i++) // Заполняем края пустыми клетками
    {
        for (int j = 0; j < cols; j++)
        {

            if ((i == 0) or (j == 0) or (i == (rows - 1)) or (j == (cols - 1)))
            {
               arr[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++) // Переносим поле из файла в матрицу
    {
        int elem = 1, cnt = 0;
        getline(in, s);

        for (int j = 1; j < cols; j++)
        {
            if ((i > 0) and (j > 0) and (i < (rows - 1)) and (j < (cols - 1)))
            {
                if (s.substr(cnt, elem) == ".")
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = 1;
                }
                cnt++;
            }
        }
    }
    return **arr;
}
int pathFind(int** arr, int start_x, int start_y, int finish_x, int finish_y) {
    int cnt = 0, size = 0;
    int* stack = new int[size];

}

int main()
{
    string s;
    int rows, cols, count_lines = 0;
    int start_x, start_y, finish_x, finish_y;

    ifstream in("C:\\Users\\vante\\source\\repos\\PathFinder\\PathFinder\\in.txt"); // ПОМЕНЯТЬ ПУТЬ К ФАЙЛУ!!!

    getline(in, s);
    count_lines++;

    cols = stoi(s) + 2;

    rows = stoi(s.substr(2)) + 2;  


    int **arr = new int* [rows];   //
                                   // 
    for (int i = 0; i < rows; i++) // Создаём динамическую матрицу
    {                              //
        arr[i] = new int[cols];    //
    }                          

    fillArray(arr, cols, rows, count_lines);

    count_lines -= 2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;

        if (count_lines >=0 && count_lines <= rows - 1)
        {
            getline(in, s); 
        }
        count_lines++;
    }

    while (!in.eof())
    {
        start_x = stoi(s.substr(0));
        start_y = stoi(s.substr(2));
        finish_x = stoi(s.substr(4));
        finish_y = stoi(s.substr(6));
        cout << arr[start_y][start_x] << " " << arr[finish_y][finish_x] << endl;
        cout << start_x << " " << start_y << " " << finish_x << " " << finish_y << endl;
        getline(in, s);
    }


    for (int i = 0; i < rows; i++) //
    {                              //
        delete[] arr[i];           // Удаляем динамическу матрицу
    }                              // Во избежание утечки памяти  
                                   //
    delete[] arr;                  //

    in.close();
}
