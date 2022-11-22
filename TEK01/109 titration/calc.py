##
## EPITECH PROJECT, 2021
## B-MAT-200-STG-2-1-109titration-thomas.koebel
## File description:
## calc
##

import sys
import math

def calc_pns(data, derive):
	base = 0.0
	liste = []
	liste.append(1)
	liste.append(0)
	for i in range(1, len(data) - 1):
		if base < derive[i]:
			base = derive[i]
			liste[0] = data[i][0]
			liste[1] = i
	return liste

def calc_second_derivative_estimation(derive, data):
	pns = calc_pns(data, derive)
	recursive = pns[0]
	key = pns[1]
	it = data[key - 1][0]
	value = 0
	first = 0
	tab = []
	tab.append(it)
	if not key - 2 < 0:
		value = (derive[key] - derive[key - 2])
		value /= (data[key][0] - data[key - 2][0])
		first = value
	tab.append(value)
	tab.append(first)
	second = (derive[key + 1] - derive[key - 1])
	second /= (data[key + 1][0] - data[key - 1][0])
	tab.append(second)
	res = (second - first)
	res /= (10 * (data[key][0] - data[key - 1][0]))
	tab.append(recursive)
	while tab[0] - 0.05 < data[key][0]:
		print("%.1f ml -> %.2f" % (tab[0], tab[2]))
		if math.fabs(tab[1]) > math.fabs(tab[2]) and key + 3 < len(data):
			tab[1] = tab[2]
			tab[4] = tab[0]
		tab[2] += res
		tab[0] += 0.1
	calc_second_derivative_estimation_last(tab, derive, data)

def calc_second_derivative_estimation_last(tab, derive, data):
	pns = calc_pns(data, derive)
	key = pns[1]
	it = tab[0]
	value = tab[1]
	first = tab[2]
	second = tab[3]
	recursive = tab[4]
	res = 0
	if key + 3 >= len(derive):
		res = -second / 10
	else:
		first = (derive[key + 2] - derive[key])
		first /= (data[key + 2][0] - data[key][0])
		res = (first - second)
		res /= (10 * (data[key + 1][0] - data[key][0]))
	second += res
	while it - 0.05 < data[key + 1][0]:
		print("%.1f ml -> %.2f" % (it, second))
		second += res
		it += 0.1
		if math.fabs(value) > math.fabs(second) and key + 3 < len(data):
			value = second
			recursive = it
	print("\nEquivalent point at %.1f ml" % recursive)

def calc_derivative(data):
	change = []
	change.append(0)
	print("Derivative:")
	for i in range(1, len(data) - 1):
		calc = data[i + 1][1] - data[i - 1][1]
		calc /= (data[i + 1][0] - data[i - 1][0])
		change.append(calc)
		print("%.1f ml -> %.2f" % (data[i][0], change[i]))
	pns = calc_pns(data, change)
	change.append(0)
	print("\nEquivalent point at %.1f ml\n" % pns[0])
	return change

def calc_second_derivative(derive, data):
	print("Second derivative:")
	for i in range(1, len(derive) - 3):
		value = (derive[i + 2] - derive[i])
		value /= (data[i + 2][0] - data[i][0])
		print("%.1f ml -> %.2f" % (data[i + 1][0], value))
	print("\nSecond derivative estimated:")
