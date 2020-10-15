import keras
from keras.layers.core import Dense, Activation
from keras.models import Sequential
from keras.models import Sequential
from keras.layers import Dense, Embedding, LSTM

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt


def process(path):
	df = pd.read_csv(path,header=0)
	print(df.head())
	Y=df["class"]
	X = df.drop("class", 1)
	
	X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.20)
	
	# one-hot encode the labels
	num_classes =3
	Y_train_D_hot = keras.utils.to_categorical(Y_train-1, num_classes)
	Y_test_D_hot = keras.utils.to_categorical(Y_test-1, num_classes)
	
	# break training set into training and validation sets
	(X_train, X_valid) = X_train[40:], X_train[:40]
	(Y_train, Y_valid) = Y_train_D_hot[40:], Y_train_D_hot[:40]
	X_test = X_test
	Y_test = Y_test_D_hot
	
	# print shape of training set
	print('x_train shape:', X_train.shape)
	
	# print number of training, validation, and test images
	print(X_train.shape[0], 'train samples')
	print(X_test.shape[0], 'test samples')
	print(X_valid.shape[0], 'validation samples')

	embed_dim = 128
	lstm_out = 196
	batch_size = 32
	
	model = Sequential()
	model.add(Embedding(2000, embed_dim,input_length = X_train.shape[1], dropout = 0.2))
	model.add(LSTM(lstm_out, dropout_U = 0.2, dropout_W = 0.2))
	model.add(Dense(3,activation='softmax'))
	model.compile(loss = 'categorical_crossentropy', optimizer='adam',metrics = ['accuracy'])
	print(model.summary())


	hist = model.fit(X_train, Y_train, batch_size=32, epochs=10,validation_data=(X_valid, Y_valid),verbose=1, shuffle=True)
	
	model.save("RNN.hdf5")
	
	
	model.load_weights('RNN.hdf5')  
	#train and validation loss
	plt.plot(hist.history['loss'])
	plt.plot(hist.history['val_loss'])
	plt.title('Model Loss')
	plt.ylabel('Loss')
	plt.xlabel('Epoch')
	plt.legend(['train','Validation'],loc='upper left')
	plt.savefig('results/RNN Model Loss.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()

	#train and validation accuracy
	plt.plot(hist.history['acc'])
	plt.plot(hist.history['val_acc'])
	plt.title('Model Accuracy')
	plt.ylabel('Accuracy')
	plt.xlabel('Epoch')
	plt.legend(['train','Validation'],loc='upper left')
	plt.savefig('results/RNN Model Accuracy.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()

	ac=[]
	
	score = model.evaluate(X_train, Y_train, verbose=0)
	ac.append(score[1])
	print('\n', 'RNN train accuracy:', score[1])

	# evaluate and print test accuracy
	score = model.evaluate(X_test, Y_test, verbose=0)
	ac.append(score[1])

	print('\n', 'RNN Test accuracy:', score[1])
	
	
	score = model.evaluate(X_valid, Y_valid, verbose=0)
	ac.append(score[1])

	print('\n', 'RNN validation accuracy:', score[1])          
	print(ac)
	
	colors = ["#1f77b4", "#ff7f0e", "#2ca02c", "#d62728", "#8c564b"]
	explode = (0.1, 0, 0, 0, 0)  
	alc=["TRAIN SET","TEST SET","VALIDATION SET"]
	fig = plt.figure()
	plt.bar(alc, ac,color=colors)
	plt.xlabel('Parameter')
	plt.ylabel('Value')
	plt.title('RNN Accuracy Value')
	fig.savefig('results/RNNAccuracyValue.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()
	
#process()	
