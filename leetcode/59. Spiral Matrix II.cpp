// PROBLEM :

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]


// SOLUTION :

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Result matrix initialized with 0
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        // Boundary pointers
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        int num = 1; // Number to be filled

        // Continue until all layers are filled
        while (top <= bottom && left <= right) {

            // 1️⃣ Traverse from left to right on the top row
            for (int col = left; col <= right; col++) {
                matrix[top][col] = num++;
            }
            top++; // Move top boundary down

            // 2️⃣ Traverse from top to bottom on the right column
            for (int row = top; row <= bottom; row++) {
                matrix[row][right] = num++;
            }
            right--; // Move right boundary left

            // 3️⃣ Traverse from right to left on the bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    matrix[bottom][col] = num++;
                }
                bottom--; // Move bottom boundary up
            }

            // 4️⃣ Traverse from bottom to top on the left column
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    matrix[row][left] = num++;
                }
                left++; // Move left boundary right
            }
        }

        return matrix;
    }
};


