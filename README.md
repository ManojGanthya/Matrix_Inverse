# Matrix_Inverse # Manoj Ganthya

Matrix Inverse Calculator

This C++ program calculates the inverse of a square matrix. It prompts the user to enter the order of the matrix and the values of its elements. The program then performs several operations to find the inverse matrix.

The program begins by checking the validity of the matrix order entered by the user. If the order is less than or equal to zero, the program prompts the user to enter a non-zero positive integer value.

Once the matrix order is validated, the program accepts the values of the matrix elements from the user.

The program then adds an identity matrix to the given matrix to prepare for finding the inverse. It creates a clone of the original matrix and adds the identity matrix to the right side of it.

Next, the program performs row operations to transform the left side of the matrix into the identity matrix. It divides each row by its diagonal element and subtracts the appropriate multiple of each row from other rows to make their corresponding elements zero.

After the row operations, the program extracts the right side of the matrix, which is the inverse matrix. It stores it in a separate matrix called "Inverse_Matrix".

The program also performs matrix multiplication to verify the correctness of the inverse matrix. It multiplies the original matrix by the inverse matrix and stores the result in the "Mult_Matrix" matrix.

Finally, the program displays the inverse matrix, the matrix multiplication result, and the rounded matrix multiplication result.

Please note that this program assumes the existence of an inverse for the given matrix. If the matrix is singular or non-invertible, the program will display an appropriate message indicating that the inverse does not exist.

This code can be useful for anyone working with linear algebra and needing to calculate the inverse of a matrix.
