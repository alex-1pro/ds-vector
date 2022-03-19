#include <stdio.h>
#include "vector.h"
#include <stdlib.h>

int main()
{
	//d_vector  *v_ptr = Create(5 , sizeof(int));
	d_vector  *v_ptr = Create(1 , sizeof(double));
	
	Reserve	(v_ptr, 2);
	
	printf("capacity %zu\n",GetCapacity(v_ptr));
	
	
	//int x[] = {5,4,9,100};
	double x[] = {5.2, 4.15, 9.51, 100.71};
	double *acc_value, *pop_value;
	if(v_ptr == NULL)
	{
		printf("some thing going wrong\n");
		return 1;
	}
	else 
	{
		printf("succeeded!\n");
	}
	PushBack(v_ptr,&x[0]);
	PushBack(v_ptr,&x[1]);
	PushBack(v_ptr,&x[2]);
	
	printf("occupied %zu\n",GetOccupied(v_ptr));
	
	pop_value = (double*)PopBack(v_ptr);
	printf("pop= %f\n",*pop_value);
	
	acc_value = (double*)Access(v_ptr,1);
	printf("access to element 1 = %f\n",*acc_value);
	printf("capacity %zu\n",GetCapacity(v_ptr));
	
	
	Shrink(v_ptr);
	
	printf("after shrink capacity %zu\n",GetCapacity(v_ptr));
	printf("occupied shrink %zu\n",GetOccupied(v_ptr));
	free(acc_value);
	free(pop_value);
	Destroy(v_ptr);
	
	
	return 1;
	
}	
