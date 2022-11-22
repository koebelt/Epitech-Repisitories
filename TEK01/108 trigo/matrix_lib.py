##
## EPITECH PROJECT, 2021
## Visual Studio Live Share (Workspace)
## File description:
## matrix_lib
##

from math import *

def identity_matr(n):
    tmp = []
    for i in range(n):
        ident = []
        for j in range(n):
            ident.append(1 if j == i else 0)
        tmp.append(ident)
    return tmp

def initiation_matr(n, k):
    tmp = []
    for i in range(n):
        ident = []
        for j in range(n):
            ident.append(k)
        tmp.append(ident)
    return tmp

def multiplication_matr(mat1, mat2):
    tmp = []
    for i in range(len(mat1)):
        mult = []
        for j in range(len(mat2[0])):
            a = 0
            for k in range(len(mat1[0])):
                a += mat1[i][k] * mat2[k][j]
            mult.append(a)
        tmp.append(mult)
    return tmp

def power_matr(mat, n):
    tmp = mat
    for i in range(n - 1):
        tmp = multiplication_matr(tmp, mat)
    return tmp

def divide_matr(mat, k):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            mat[i][j] /= k
    return mat

def addition_matr(mat1, mat2):
    tmp = []
    for i in range(len(mat1)):
        c = []
        for j in range(len(mat1[0])):
            c.append(mat1[i][j] + mat2[i][j])
        tmp.append(c)
    return tmp

def substract_matr(mat1, mat2):
    tmp = []
    for i in range(len(mat1)):
        c = []
        for j in range(len(mat1[0])):
            c.append(mat1[i][j] - mat2[i][j])
        tmp.append(c)
    return tmp
