import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from time import sleep
import os
import pyeeg
import warnings
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import make_moons, make_circles, make_classification
from sklearn.neural_network import MLPClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.gaussian_process import GaussianProcessClassifier
from sklearn.gaussian_process.kernels import RBF
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
import seaborn as sbn


def table(table):
    big_table = None
    for ta in table:
        big_table = pd.concat([big_table, ta],axis=1)
    return big_table

# creat a matrix
def creat_mat(mat,head):
    matx = np.zeros((len(mat),(len(head))))
    for i in range(len(head)):
        matx[:,i] = mat[head[i]]
        sleep(0.01)
    return matx

def features(mat):
    Kmax = 5
    Tau  = 4
    DE   = 10
    M    = 10
    R    = 0.3
    Band = np.arange(1,86)
    Fs   = 173
    DFA                = pyeeg.dfa(mat)
    HFD                = pyeeg.hfd(mat,Kmax)
    SVD_Entropy        = pyeeg.svd_entropy(mat,Tau,DE)
    Fisher_Information = pyeeg.fisher_info(mat,Tau,DE)
    PFD                = pyeeg.pfd(mat)
    sleep(0.01)
    
    return (DFA,HFD,SVD_Entropy,Fisher_Information,PFD)

def process():
	# import each and every file
	dirB="./Datasets/setB/"
	tempB = []
	for file in os.listdir(dirB):
	    fl = dirB + file
	    tempB.append(fl)
	tempB = sorted(tempB)    # class: 1     val:  -1

	dirC="./Datasets/setC/"
	tempC = []
	for file in os.listdir(dirC):
	    fl = dirC + file
	    tempC.append(fl)
	tempC = sorted(tempC)   # class:2       val: 0
    
	dirE="./Datasets/setE/"
	tempE = []
	for file in os.listdir(dirE):
	    fl = dirE + file
	    tempE.append(fl)
	tempE = sorted(tempE)   # class: 3        val: 1

	print(tempB)
	print(tempC)
	print(tempE)



	tb=[]
	st = 'A'
	for i in range(len(tempB)):
	    x = pd.read_table(tempB[i],header=None)
	    x.columns=[st+str(i)]
	    tb.append(x)
    
	tc=[]
	st = 'A'
	for i in range(len(tempC)):
	    x = pd.read_table(tempC[i],header=None)
	    x.columns=[st+str(i)]
	    tc.append(x)
    
	te=[]
	st = 'A'
	for i in range(len(tempE)):
	    x = pd.read_table(tempE[i],header=None)
	    x.columns=[st+str(i)]
	    te.append(x)
    
	bigB = table(tb)
	bigC = table(tc)
	bigE = table(te)
	head = list(bigB.columns.values)
	print(len(bigB.columns))
	print(bigB.head(10))




	# every mat contain probs mat[:,i] total 28 start form mat1

	matB = creat_mat(bigB,head) # : refers to healthy data
	matC = creat_mat(bigC,head) # : refers to Inter-ictal (transition between healthy to seizure)
	matE = creat_mat(bigE,head) # : of ictal or seizures

	matB = np.nan_to_num(matB) # matB[:,0] --- > channel 0, matB[:,1] --- > channel 1 like that
	matC = np.nan_to_num(matC)
	matE = np.nan_to_num(matE)

	hl,      = plt.plot(matB[0],label='healthy')
	trans,   = plt.plot(matC[0],label='Inter-ictal')
	seizure, = plt.plot(matE[0],label='seizures')
	plt.legend(handles=[hl,trans,seizure])
	plt.savefig('results/Chart.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()



	#Compute the features of datasets
	'''
	# this is three classification proble
	# class1: healthy       +1
	# class2: transition     0
	# class3: dieases       -1

	'''
	# this is three classification proble\n# class1: healthy       +1\n# class2: transition     0\n# class3: dieases       -1\n\n'

	# create features of class I
	f1_B    = np.zeros((100,1))
	f2_B    = np.zeros((100,1))
	f3_B    = np.zeros((100,1))
	f4_B    = np.zeros((100,1))
	f5_B    = np.zeros((100,1)) 
	cl_B    = np.ones((100,1)) # 1


	for i in range(100):
	    [f1_B[i,0],f2_B[i,0],f3_B[i,0],f4_B[i,0],f5_B[i,0]]=features(matB[:,i])

	# create features of class II
	f1_C    = np.zeros((100,1))
	f2_C    = np.zeros((100,1))
	f3_C    = np.zeros((100,1))
	f4_C    = np.zeros((100,1))
	f5_C    = np.zeros((100,1))
	cl_C    = np.zeros((100,1)) # transition means 0

	for i in range(100):
	    [f1_C[i,0],f2_C[i,0],f3_C[i,0],f4_C[i,0],f5_C[i,0]]=features(matC[:,i])

	# create features of class III
	f1_E    = np.zeros((100,1))
	f2_E    = np.zeros((100,1))
	f3_E    = np.zeros((100,1))
	f4_E    = np.zeros((100,1))
	f5_E    = np.zeros((100,1))
	cl_E    = np.negative(np.ones((100,1))) # -1

	for i in range(100):
	    [f1_E[i,0],f2_E[i,0],f3_E[i,0],f4_E[i,0],f5_E[i,0]]=features(matE[:,i])
    
    
	#create Feature and class matrix for each Classes

	MftB = np.concatenate([f1_B,f2_B,f3_B,f4_B,f5_B,cl_B],axis=1)
	MftC = np.concatenate([f1_C,f2_C,f3_C,f4_C,f5_C,cl_C],axis=1)
	MftE = np.concatenate([f1_E,f2_E,f3_E,f4_E,f5_E,cl_E],axis=1)

	FCM_B = pd.DataFrame(MftB,columns=['f1','f2','f3','f4','f5','class'])
	FCM_C = pd.DataFrame(MftC,columns=['f1','f2','f3','f4','f5','class'])
	FCM_E = pd.DataFrame(MftE,columns=['f1','f2','f3','f4','f5','class'])
	print(FCM_B.head(4))
	print(len(FCM_B))


	TotalDataset = pd.concat([FCM_B,FCM_C,FCM_E],ignore_index=True)
	TotalDataset.to_csv("dataset.csv",index=False)
	visDat = TotalDataset.copy(deep=True)
	visDat['class'] = visDat['class'].map({1:'healthy',0:'transation',-1:'seizure'})

	sbn.set(style="whitegrid", palette="muted")
	print(visDat.head(5))

	sbn.pairplot(visDat,hue='class',palette="husl")
	plt.savefig('results/SBN.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()


#process()
