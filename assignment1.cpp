/*
===============================
Name      : Assignment1.cpp
Author    : Ye Yuan
Student ID: 260921269
*/
#include <iostream>
#include <cstdlib>
using namespace std;

//Constant array for phonetic translating
const char *dict[26] = {"Alfa", "Bravo", "Charlie",
                        "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
                        "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar",
                        "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform",
                        "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};
//Constant value of row and col
const int rows = 5;
const int cols = 5;

//Question1
void checkPassword()
{
    string pswd;
    cout << "Please enter your password" << endl;
    cin >> pswd;
    //Check the length of password
    if (pswd.length() < 8)
    {
        cout << "Your password is less than 8 characters" << endl;
    }
    //No duplicates more than twice
    for (int i = 0; i < pswd.length(); i++)
    {
        int count = 0;
        for (int j = i + 1; j < pswd.length(); j++)
        {
            if (pswd.at(i) == pswd.at(j))
            {
                count++;
            }
        }
        if (count > 1)
        {
            cout << "Your repeated a letter too many times" << endl;
            break;
        }
    }
    //At least one number
    bool containNum = false;
    for (int i = 0; i < pswd.length(); i++)
    {
        if (pswd.at(i) <= '9' && pswd.at(i) >= '0')
        {
            containNum = true;
        }
    }
    if (!containNum)
    {
        cout << "At least 1 number is required" << endl;
    }
    //At least one special char
    bool containSpe = false;
    for (int i = 0; i < pswd.length(); i++)
    {
        if (pswd.at(i) == '*' || pswd.at(i) == '#' || pswd.at(i) == '$')
        {
            containSpe = true;
        }
    }
    if (!containSpe)
    {
        cout << "At least 1 special character is required" << endl;
    }
}

void convertPhonetic()
{
    string input;
    cout << "Please enter a word: " << endl;
    cin >> input;
    string lower = "";
    //Change the whole string to lower case
    for (int i = 0; i < input.length(); i++)
    {
        char c = input.at(i);
        char cl = tolower(c);
        lower += cl;
    }
    //Look each character up in the dictionary
    string result = "";
    for (int i = 0; i < lower.length(); i++)
    {
        int index = lower.at(i) - 'a';
        result += dict[index];
        if (i != lower.length() - 1)
        {
            result += " ";
        }
    }
    cout << result << endl;
}

void fillMatrix(int matrix[rows][cols])
{
    //Set the random seed by current time
    srand(rand());
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //Take the remainder after dividing by 26 wiil ensure we get a number from 0 to 25
            matrix[i][j] = rand() % 26;
        }
    }
}

void printMatrix(int matrix[rows][cols])
{
    string div = "------------------------------";
    for (int i = 0; i < rows; i++)
    {
        string line = "";
        for (int j = 0; j < cols; j++)
        {
            int num = matrix[i][j];
            line += to_string(num);
            if (j != cols - 1)
            {
                line += "  |  ";
            }
        }
        cout << line << endl;
        cout << div << endl;
        cout << endl;
    }
}

//Write three helper functions to help completing the multiply matrices
//Get an entire row of a matrix of the specified row index
void getRow(int matrix[rows][cols], int rowIndex, int row[cols])
{
    for (int i = 0; i < rows; i++)
    {
        row[i] = matrix[rowIndex][i];
    }
}
//Get an entire column of a matrix of the specified column index
void getCol(int matrix[rows][cols], int colIndex, int column[rows])
{
    for (int i = 0; i < rows; i++)
    {
        column[i] = matrix[i][colIndex];
    }
}

//Calculate the dot product of two vectors
int getProduct(int v1[rows], int v2[cols])
{
    int product = 0;
    for (int i = 0; i < rows; i++)
    {
        product += (v1[i] * v2[i]);
    }
    return product;
}

void multiplyMatrices(int matrix_left[rows][cols], int matrix_right[rows][cols], int matrix_result[rows][cols])
{
    int tempCol[rows];
    int tempRow[cols];
    for (int i = 0; i < rows; i++)
    {
        getRow(matrix_left, i, tempRow);
        for (int j = 0; j < cols; j++)
        {
            getCol(matrix_right, j, tempCol);
            int product = getProduct(tempRow, tempCol);
            matrix_result[i][j] = product;
        }
    }
}

int main()
{
    checkPassword();
    convertPhonetic();
    int matrix[rows][cols];
    int matrix2[rows][cols];
    int matrix_result[rows][cols];
    fillMatrix(matrix);
    fillMatrix(matrix2);
    printMatrix(matrix);
    printMatrix(matrix2);
    multiplyMatrices(matrix, matrix2, matrix_result);
    printMatrix(matrix_result);
    return 0;
}
