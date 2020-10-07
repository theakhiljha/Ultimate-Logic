import keras
from keras.models import Sequential
from keras.layers import Conv1D, MaxPooling1D, Flatten, Dense, Dropout
from keras.callbacks import ModelCheckpoint

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
	
	X_train=np.array(X_train).reshape(X_train.shape[0],X_train.shape[1],1)
	X_valid=np.array(X_valid).reshape(X_valid.shape[0],X_valid.shape[1],1)
	X_test=np.array(X_test).reshape(X_test.shape[0],X_test.shape[1],1)


	model = Sequential()
	#1
	model.add(Conv1D(filters=16, kernel_size=64,strides = 16, padding='same', activation='relu',input_shape=(X_train.shape[1], 1)))
	model.add(MaxPooling1D(pool_size=1))
	#2
	model.add(Conv1D(filters=16, kernel_size=3, strides = 1, padding='same', activation='relu'))
	model.add(MaxPooling1D(pool_size=1))
	#3
	model.add(Conv1D(filters=32, kernel_size=3, strides = 1, padding='same', activation='relu'))
	model.add(MaxPooling1D(pool_size=1))
	model.add(Dropout(0.2))
	#4
	model.add(Conv1D(filters=32, kernel_size=3, strides = 1, padding='same', activation='relu'))
	model.add(MaxPooling1D(pool_size=1))
	model.add(Dropout(0.2))
	#5
	model.add(Conv1D(filters=32, kernel_size=3, strides = 1, padding='same', activation='relu'))
	model.add(MaxPooling1D(pool_size=1))  

	model.add(Flatten())
	model.add(Dense(50, activation='relu'))
	model.add(Dropout(0.2))
	model.add(Dense(3, activation='softmax'))

	model.summary()


	# compile the model
	model.compile(loss='categorical_crossentropy', optimizer='rmsprop',metrics=['accuracy'])

	# train the model
	checkpointer = ModelCheckpoint(filepath='CNN.hdf5', verbose=1,save_best_only=True)

	hist = model.fit(X_train, Y_train, batch_size=32, epochs=10,validation_data=(X_valid, Y_valid), callbacks=[checkpointer],verbose=1, shuffle=True)

	# load the weights that yielded the best validation accuracy
	model.load_weights('CNN.hdf5')

	#train and validation loss
	plt.plot(hist.history['loss'])
	plt.plot(hist.history['val_loss'])
	plt.title('Model Loss')
	plt.ylabel('Loss')
	plt.xlabel('Epoch')
	plt.legend(['train','Validation'],loc='upper left')
	plt.savefig('results/CNN Model Loss.png') 
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
	plt.savefig('results/CNN Model Accuracy.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()

	# evaluate and print test accuracy
	score = model.evaluate(X_test, Y_test, verbose=0)
	print('\n', 'CNN Test accuracy:', score[1])
	
	score = model.evaluate(X_train, Y_train, verbose=0)
	print('\n', 'CNN train accuracy:', score[1])
	
	score = model.evaluate(X_valid, Y_valid, verbose=0)
	print('\n', 'CNN validation accuracy:', score[1])
	
	ac=[]
	
	score = model.evaluate(X_train, Y_train, verbose=0)
	ac.append(score[1])
	print('\n', 'CNN train accuracy:', score[1])

	# evaluate and print test accuracy
	score = model.evaluate(X_test, Y_test, verbose=0)
	ac.append(score[1])

	print('\n', 'CNN Test accuracy:', score[1])
	
	
	score = model.evaluate(X_valid, Y_valid, verbose=0)
	ac.append(score[1])

	print('\n', 'CNN validation accuracy:', score[1])          
	print(ac)
	
	colors = ["#1f77b4", "#ff7f0e", "#2ca02c", "#d62728", "#8c564b"]
	explode = (0.1, 0, 0, 0, 0)  
	alc=["TRAIN SET","TEST SET","VALIDATION SET"]
	fig = plt.figure()
	plt.bar(alc, ac,color=colors)
	plt.xlabel('Parameter')
	plt.ylabel('Value')
	plt.title('CNN Accuracy Value')
	fig.savefig('results/CNNAccuracyValue.png') 
	plt.pause(5)
	plt.show(block=False)
	plt.close()
	
