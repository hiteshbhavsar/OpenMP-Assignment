/*******************************************************************************
	OpenMP Assignment 
	(Demonstrates a matrix multiply using OpenMP.)
	File: OpenMPAssignment.cpp
	Author: Hitesh Bhavsar 
	Last Revised: 05/15/2020
******************************************************************************/

	// OpenMP Code for matrix multiplication
	// to compute the multiplication of two arrays in parallel
	#include "stdafx.h"
	#include<iostream>
	#include<stdio.h>
	#include < omp.h >
	#include<conio.h>
	#define cols1 100
	#define rows1 100
	#define cols2 100
	#define rows2 100
	int main()
	{

	int i, j, k;
	if (cols1 != rows2)
	{
		printf("The dimension of the array defined are incorrect. Please check!");
		return -1;
	}
	int a[rows1][cols1] = { 0 };
	for (i = 0; i < rows1; i++)
	{
		for (j = 0; j < cols1; j++)
		{
			a[i][j] = rand();
		}
	}
	int b[rows2][cols2] = { 0 };
	for (i = 0; i < rows2; i++)
	{
		for (j = 0; j < cols2; j++)
		{
			b[i][j] = rand();
		}
	}

	int result[rows1][cols2] = { 0 };


	double time;
	omp_set_num_threads(4);
	time = -omp_get_wtime();

	#pragma omp parallel shared(a,b,result) private(i,j,k)
	{
		#pragma omp for schedule (static)
		for (i = 0; i < rows1; i++)
		{
			for (j = 0; j < cols2; j++)
			{
				result[i][j] = 0;
				for (k = 0; k < cols1; k++)
				{
				result[i][j] += a[i][k] * b[k][j];
				}
			}

		}
	}
	time = omp_get_wtime() + time;
	printf("Time Required for the function execution is %lf micro seconds.\n", time* 1000000);
	getch();
	return 0;
	}

