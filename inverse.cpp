#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int Matrix_Order;
    cout << "In this Programme we find Matrix Inverse" << endl
         << "Say me, How much order matrix are you have?" << endl;
    cin >> Matrix_Order;
    while (Matrix_Order <= 0)
    {
        cout << "Matrix Order can't be Less than Equal Zero non-integer;" << endl
             << "Enter Some Non-zero Positive Integer Value -->";
        cin >> Matrix_Order;
    }

    cout << endl
         << "Sure, Let's say your " << Matrix_Order;
    if (Matrix_Order == 1)
    {
        cout << "st";
    }
    else if (Matrix_Order == 2)
    {
        cout << "nd";
    }
    else if (Matrix_Order == 3)
    {
        cout << "rd";
    }
    else
    {
        cout << "th";
    }
    cout << " order Matrix" << endl
         << endl;

    float Matrix[Matrix_Order][Matrix_Order];
    int i, j, m, n, p, q;

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            cout << "Let's say value of A_" << i + 1 << j + 1 << " -->> ";
            cin >> Matrix[i][j]; // check diagonal element non-zero
        }
    }

    cout << endl
         << "We are receive your Matrix" << endl
         << endl
         << "Your Matrix is -->>" << endl;
    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    float CloneMatrix[Matrix_Order][2 * Matrix_Order];

    for (i = 0; i < Matrix_Order; i++)

    {
        for (j = 0; j < Matrix_Order; j++)
        {
            CloneMatrix[i][j] = Matrix[i][j];
        }
    }

    // ADD IDENTITY MATRIX
    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            int Temp_Zero_One;
            int Temp_j = Matrix_Order + j;
            if (i == j)
            {
                Temp_Zero_One = 1;
            }
            else
            {
                Temp_Zero_One = 0;
            }
            CloneMatrix[i][Matrix_Order + j] = Temp_Zero_One;
        }
    }

    cout << endl
         << "We Add Identity Matrix. Now Matrix show as -->" << endl;

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < (2 * Matrix_Order); j++)
        {
            cout << CloneMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    float Temp_CloneMatrix[Matrix_Order][(2 * Matrix_Order)];

    for (i = 0; i < Matrix_Order; i++)
    {

        // Diagonal Element Zero or No-zero Check
        float Temp_Div = CloneMatrix[i][i];
        if (Temp_Div == 0)
        {
            // Find non-zero row below and swap
            int nonZeroRow = -1;
            for (int k = i + 1; k < Matrix_Order; k++)
            {
                if (CloneMatrix[k][i] != 0)
                {
                    nonZeroRow = k;
                    break;
                }
            }

            if (nonZeroRow == -1)
            {
                cout << "Inverse Does Not Exist" << endl;
                return 0;
            }

            // Swap rows
            for (int p = 0; p < Matrix_Order; p++)
            {
                float temp = CloneMatrix[nonZeroRow][p];
                CloneMatrix[nonZeroRow][p] = CloneMatrix[i][p];
                CloneMatrix[i][p] = temp;
            }
        }

        // Division by diagonal element
        for (j = 0; j < (2 * Matrix_Order); j++)
        {

            CloneMatrix[i][j] = CloneMatrix[i][j] / Temp_Div;
        }

        // float Temp_CloneMatrix[i][j];
        for (m = 0; m < Matrix_Order; m++)
        {
            if (m == i)
            {
                // Skip
            }
            else
            {

                float Temp_Mul = CloneMatrix[m][i];
                for (n = 0; n < (2 * Matrix_Order); n++)
                {
                    Temp_CloneMatrix[i][n] = Temp_Mul * CloneMatrix[i][n];
                    CloneMatrix[m][n] = CloneMatrix[m][n] - Temp_CloneMatrix[i][n];
                }
            }
        }
    }

    cout << "After operation -->" << endl;

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < (2 * Matrix_Order); j++)
        {
            cout << CloneMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "Your Inverse Matrix -->" << endl;

    // Cut Identity Matrix
    float Inverse_Matrix[Matrix_Order][Matrix_Order];
    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            Inverse_Matrix[i][j] = CloneMatrix[i][(j + Matrix_Order)];
        }
    }
    // Print Inverse
    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            cout << Inverse_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Matrix Multiplication
    float Mult_Matrix[Matrix_Order][Matrix_Order];

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            Mult_Matrix[i][j] = 0;
            for (int k = 0; k < Matrix_Order; k++)
            {
                Mult_Matrix[i][j] += (Matrix[i][k] * Inverse_Matrix[k][j]);
            }
        }
    }

    float Final_Matrix[Matrix_Order][Matrix_Order];
    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            Final_Matrix[i][j] = round(Mult_Matrix[i][j]);
        }
    }

    cout << endl
         << "Your  Matrix and Inverse Matrix Multiplication -->" << endl;

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            cout << Mult_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "Your  Matrix and Inverse Matrix Multiplication by Round-->" << endl;

    for (i = 0; i < Matrix_Order; i++)
    {
        for (j = 0; j < Matrix_Order; j++)
        {
            cout << Final_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
