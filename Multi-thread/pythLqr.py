import numpy as np
import scipy.linalg
from numpy import genfromtxt
import datetime

def LQR():
	#startTime = datetime.datetime.now()
	A = genfromtxt('CSV/A.csv', delimiter=',')
	B = genfromtxt('CSV/B.csv', delimiter=',')
	Q = genfromtxt('CSV/Q.csv', delimiter=',')
	R = genfromtxt('CSV/R.csv', delimiter=',')
	#print(A)
	#print(B)
	#print(Q)
	#print(R)
	X = np.matrix(scipy.linalg.solve_continuous_are(A, B, Q, R))
	#np.savetxt('P.csv', X, delimiter=',')	
	#print(X) 
	K = np.matrix(scipy.linalg.inv(R)*(B.T*X)) 
	np.savetxt('CSV/K.csv', K, delimiter=',')
	#print(datetime.datetime.now()-startTime)
	#print(K)
	return
