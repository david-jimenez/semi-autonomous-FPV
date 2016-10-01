import numpy as np
import scipy.linalg
from numpy import genfromtxt
import datetime

def LQR():
	#startTime = datetime.datetime.now()
	A = genfromtxt('A.csv', delimiter=',')
	B = genfromtxt('B.csv', delimiter=',')
	Q = genfromtxt('Q.csv', delimiter=',')
	R = genfromtxt('R.csv', delimiter=',')
	#print(A)
	#print(B)
	#print(Q)
	#print(R)
	X = np.matrix(scipy.linalg.solve_continuous_are(A, B, Q, R))
	#print(X) 
	K = np.matrix(scipy.linalg.inv(R)*(B.T*X)) 
	np.savetxt('K.csv', K, delimiter=',')
	#print(datetime.datetime.now()-startTime)
	#print(K)
	return
