import os 
import sys 


class AVLNode:
    def __init__(self, val):
        self.val = val 
        self.left = None 
        self.right = None 
        self.height = 1


class AVLTree:
    def __init__(self):
        super().__init__()