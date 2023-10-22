/*
 * Main.cpp
 *
 *  Created on: October 18, 2023
 *      Author: Anjay Bhandari
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
static const int MAX_SIZE = 100;


void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void ReadMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const string filename, bool isSecondMatrix );		
void addTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]);
void multiplyTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]); 
void subTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]);

int main() {
	static int matrix1[MAX_SIZE][MAX_SIZE];
	static int matrix2[MAX_SIZE][MAX_SIZE];
	static int matrix3[MAX_SIZE][MAX_SIZE];
	
	int size = 0;
	const string filename = "matrix_input.txt";
	bool isSecondMatrix = false;
	
	cout << "Anjay Bhandari" << endl << "Lab #6: Matrix manipulation" << endl << endl;
	
	cout << "Matrix A: " << endl;
	ReadMatrixFromFile(matrix1,size,filename, isSecondMatrix);
	displayMatrix(matrix1,size);
	
	cout << "Matrix B: " << endl;
	isSecondMatrix = true;
	ReadMatrixFromFile(matrix2,size,filename, isSecondMatrix);
	displayMatrix(matrix2,size);
	
	cout << "Matrix Sum (A + B): " << endl;
	addTwoMatricies(matrix1,matrix2, size, matrix3);
	displayMatrix(matrix3, size);
	
	cout << "Matrix Product (A * B):  " << endl;
	multiplyTwoMatricies(matrix1,matrix2, size, matrix3);
	displayMatrix(matrix3, size);
	
	cout << "Matrix Difference (A - B):  " << endl;
	subTwoMatricies(matrix1,matrix2, size, matrix3);
	displayMatrix(matrix3, size);

	
return 0;
}


void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
	}
	cout << endl;
	}
	cout << endl;
	
}


void ReadMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const string filename, bool isSecondMatrix ) {
	ifstream file(filename);
		if (file.is_open()) {
		file >> size;
		if(!isSecondMatrix) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					file >> matrix[i][j];
				}
			}	
		}
		 else {
			//skips first matrix if bool isSecondMatrix is true
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					int temp;
					file >> temp;
				}
			}
			
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					file >> matrix[i][j];
					
				}
			}
			
		}
		file.close();
	}
}
	
void addTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
					
				}
			}
}

void multiplyTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix3[i][j] = 0;
			for (int k = 0; k < size; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
					
				}
			}
}

void subTwoMatricies(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size, int matrix3[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
					
				}
			}
}
	
	
