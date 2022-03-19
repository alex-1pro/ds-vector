#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

#define SUCCEEDED 1
#define FAILED 0
 

d_vector* Create(size_t size, size_t size_type)
{
	if(size <= 0 || size_type <= 0 )
	{
		printf("number of items or size of item illegal\n");
		return NULL; 
	}
	d_vector *n_vector = (d_vector *)malloc(sizeof(d_vector));
	
	//malloc return void* pointer
	n_vector->start = malloc( size_type * size);
	if(n_vector->start == NULL)
	{
		return NULL;
	}
	n_vector->capacity = size;
	n_vector->occupied = 0;
	n_vector->size_element = size_type;
	
	return n_vector;
	
}

int Destroy(vector *v_ptr )
{
	free(v_ptr->start);
	v_ptr->start = NULL;
	free(v_ptr);
	v_ptr = NULL;
	return SUCCEEDED;
}


int Resize(vector *v_ptr, int new_capacity)
{
// increase size of elements 
	void *i_elements = realloc(v_ptr->start, v_ptr->size_element*(v_ptr->capacity * new_capacity));
	if(i_elements)
	{
		v_ptr->start = i_elements;
		v_ptr->capacity=v_ptr->capacity * new_capacity;
		return SUCCEEDED;
	}
	else 
	return FAILED;	
}

int PushBack(vector *v_ptr , void *item)
{
	int status;
	void *new_place_ptr = NULL;
	if(v_ptr->occupied == v_ptr->capacity)
	{
       status = Resize(v_ptr,2);
       if(status == FAILED)
       {
       	  printf("\nAdd new element failed\n");
	   	  return FAILED;
	   }
	}
	new_place_ptr =(char *)v_ptr->start + (v_ptr->occupied * v_ptr->size_element);
	
	//void *memcpy(void *dest, const void * src, size_t n)	
	memcpy(new_place_ptr, item, v_ptr->size_element);
	v_ptr->occupied++;
	//v_ptr->capacity--;
	return status;
}

void *PopBack(vector *v_ptr)
{
	if(v_ptr->occupied == 0)
	{
		return NULL;
	}
	void *item = malloc(v_ptr->size_element);
	void *current_item; 
	v_ptr->occupied--;
	//v_ptr->capacity++;
	current_item = (char*)v_ptr->start + (v_ptr->occupied * v_ptr->size_element);
	printf("current_item: %p ,item: %p\n",current_item,item);
	memcpy(item ,current_item, v_ptr->size_element);
	printf("current_item: %p ,item: %p\n",current_item,item);	
	current_item = NULL;
	return item;
}

void *Access(vector *v_ptr , size_t index)
{
	void *current_item;
	void *item = malloc(v_ptr->size_element);
	 if ( index < v_ptr->occupied)
     {
       current_item  = (char*)v_ptr->start + (index * v_ptr->size_element);
       memcpy(item ,current_item, v_ptr->size_element);	
       return item;
     }
    return NULL;
}


size_t GetCapacity(vector *v_ptr)
{
	return v_ptr->capacity - v_ptr->occupied;
}



size_t GetOccupied(vector *v_ptr)
{
	return v_ptr->occupied;
}


int Reserve(vector *v_ptr, size_t size)
{
	void *i_elements = realloc(v_ptr->start, v_ptr->size_element*(v_ptr->capacity + size));
	if(i_elements)
	{
		v_ptr->start = i_elements;
		v_ptr->capacity=v_ptr->capacity + size;
		return SUCCEEDED;
	}
	else 
	return FAILED;	
}


int Shrink(vector *v_ptr)
{
	void *tmp = realloc(v_ptr->start, v_ptr->occupied * v_ptr->size_element);
	if(tmp)
	{
		v_ptr->start = tmp;
		v_ptr->capacity = v_ptr->occupied;
		return SUCCEEDED;
	}
	return FAILED;
}





