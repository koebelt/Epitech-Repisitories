##
## EPITECH PROJECT, 2021
## Visual Studio Live Share (Workspace)
## File description:
## 108trigo_functions
##

from matrix_lib import *

def do_exp(tab):
    tmp_matr = identity_matr(len(tab))
    for i in range(1, 50):
        tmp_matr = addition_matr(tmp_matr, divide_matr(power_matr(tab, i), factorial(i)))
    return tmp_matr

def do_cos(tab):
    tmp_matr = identity_matr(len(tab))
    for i in range(1, 40):
        if i % 2 == 0:
            tmp_matr = addition_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i), factorial(2 * i)))
        else:
            tmp_matr = substract_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i), factorial(2 * i)))
    return tmp_matr

def do_sin(tab):
    tmp_matr = tab
    for i in range(1, 40):
        if i % 2 == 0:
            tmp_matr = addition_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i + 1), factorial(2 * i + 1)))
        else:
            tmp_matr = substract_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i + 1), factorial(2 * i + 1)))
    return tmp_matr

def do_cosh(tab):
    tmp_matr = identity_matr(len(tab))
    for i in range(1, 40):
        tmp_matr = addition_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i), factorial(2 * i)))
    return tmp_matr

def do_sinh(tab):
    tmp_matr = tab
    for i in range(1, 40):
        tmp_matr = addition_matr(tmp_matr, divide_matr(power_matr(tab, 2 * i + 1), factorial(2 * i + 1)))
    return tmp_matr