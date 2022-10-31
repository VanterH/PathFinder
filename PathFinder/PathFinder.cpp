#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
    string s;
    int rows, cols;

    ifstream in("C:\\Users\\vante\\source\\repos\\PathFinder\\PathFinder\\in.txt"); // ПОМЕНЯТЬ ПУТЬ К ФАЙЛУ!!!

    getline(in, s);

    cols = stoi(s) + 2;

    rows = stoi(s.substr(2)) + 2;  

    int **arr = new int* [rows];   //
                                   // 
    for (int i = 0; i < rows; i++) // Создаём динамическую матрицу
    {                              //
        arr[i] = new int[cols];    //
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

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) //
    {                              //
        delete[] arr[i];           // Удаляем динамическу матрицу
    }                              // Во избежание утечки памяти  
                                   //
    delete[] arr;                  //
}
