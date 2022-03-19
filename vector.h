#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct d_vector
{
    void *start;
    size_t capacity;
    size_t occupied;
    size_t size_element;
} d_vector,vector;




//Create Vector
d_vector* Create(size_t size, size_t size_type);

//Delete and free Vector
int Destroy(vector *v_ptr);


//Add new value to vactor and increase size
int PushBack(vector *v_ptr , void *item);

//Get and remove last value from vector
void *PopBack(vector *v_ptr);

//Get the value of specific index in vector
void *Access(vector *v_ptr , size_t index);

//Get Size of used cells
size_t GetOccupied(vector *v_ptr);

//Get total size of the vector
size_t GetCapacity(vector *v_ptr);

//Increase vector with extra size
int Reserve(vector *v_ptr,size_t size);

//Free empty cells
int Shrink(vector *v_ptr);


#endif
