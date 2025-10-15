"""
15.10.2025
Author: Ali ÇİNE
Description: My solution for 48.Question from Leetcode top 150 Interview Questions. I realized that when we rotate square 90 Degrees, then 0 index of all lists in matrix are moving in 0. list of matrix, all 1. indexes in 1. list, all 2. indexes in 2.list etc.

For example here all 0 indexed elements moved in 0 indexed list:
[->1, 2, 3]  90 deg   [->7,->4,->1]
[->4, 5, 6] --------> [  8,  5,  2]
[->7, 8, 9]           [  9,  6,  3]
  
 When i loop the matrix from end then it gives me automatically the positions of element in list to move.
0, 1 and 2 are indexes (i start from end to loop):
    0 1 2
2 [[1,2,3],
1 [4,5,6],
0 [7,8,9]]

For element 6 it is (1,2)
Element 6 is moved in 2. list and 1. position in that list.
"""
import copy
from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        old_matrix = copy.deepcopy(matrix)
        for index_x,x in enumerate(old_matrix[::-1]):
            for index_y, y in enumerate(x):
                matrix[index_y][index_x] = y
