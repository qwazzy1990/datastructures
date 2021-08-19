import os
import sys
import numpy as np
import math


class Node:
    def __init__(self, val):
        self.val = val
        self.leftChild = None 
        self.rightChild = None

class SegmentTree:

    def __init__(self, arr):
        self.tree = []
        self.tree.append(np.max(arr))
        self.createTree(self.tree, arr)

    def createTree(self, tree, arr):

        # if the array is of size 1
        if len(arr) == 1:
            return

        mid = int(math.floor(len(arr)/2))
        print(mid)
        left = arr[0:mid]
        right = arr[mid:len(arr)]
        print(left, right)
        self.tree.append(np.max(left))
        self.tree.append(np.max(right))
        self.createTree(tree, left)
        self.createTree(tree, right)


if __name__ == "__main__":

    arr = [2, 1, 7, -1, 8, 6]
    s = SegmentTree(arr)
    print(s.tree)
