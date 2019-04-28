#!/usr/bin/python2.7
# -*- coding: UTF-8 -*-

import matplotlib.pyplot as plt
import math
import os
import numpy as np

def pre_result_data():
	i = 0		   
	lists=["a","b","c","d","e"]				#abcde corresponds to The number of temporal iterations,
	result = list()		   					#The number of spatial foldings,The number of total iterations,
	#gen vary		   						#Total Runtime,Total Energy
	for i in range(6):
	    globals()['v'+str(i)]=list()
	    result.append(globals()['v'+str(i)])

	result_file = open("result" ,"r")
	strs = result_file.readlines()	
	for line in strs:
		i += 1
		line=line.strip('\n')

		if not (i-1)%5:
			line=int(line)
			v1.append(line)
		elif not (i-2)%5:
			line=int(line)
			v2.append(line)
		elif not (i-3)%5:
			line=int(line)
			v3.append(line)
		elif not (i-4)%5:
			line=int(line)
			v4.append(line)
		elif not (i-5)%5:
			ss = line.split("e+")
			num = float(ss[0])
			exp = int(ss[1])
			line=num * math.pow(10, exp) 
			v5.append(line)
	return result

def pre_var_data():
	var_file= open('./var','r')
	strs = var_file.readlines()
	x=list()
	for line in strs:
		line_buffer = line.split(' ',1)
		num = int(line_buffer[1])
		x.append(num)
	return x

def plot(x,y):
	fig = plt.figure()
	for i in range(1,6):
		i2s=str(i)
		canvas = int("15"+i2s)
		ax = fig.add_subplot(canvas)
		ax.axis('auto')
		ax.plot(x, y[i])

	plt.title('The impact of the feature map on the results') 
	plt.xlabel('Size of IFmap')
	plt.ylabel('y')
	plt.show()

def bar():
	labels   = ['ws','sd','rs','nlr','maeri']
	quants   = [368640, 1105920, 69120, 2488320, 1105920]
	width = 0.4
	ind = np.linspace(0.5,9.5,5)
	fig = plt.figure(1)
	ax  = fig.add_subplot(111)
	print ind-width/2
	ax.bar(ind-width/2,quants,width,color='green')
	ax.set_xticks(ind)
	ax.set_xticklabels(labels)
	ax.set_xlabel('Dataflow')
	ax.set_ylabel('The number of temporal iterations')
	ax.set_title('The impact of different dataflow on The number of temporal iterations', bbox={'facecolor':'0.8', 'pad':5})
	plt.grid(True)
	plt.savefig("bar.jpg")
	plt.show()

 

def main():
	result = pre_result_data()
	x = pre_var_data()
#	plot(x,result)
	bar()


if __name__ == "__main__":
	main()
