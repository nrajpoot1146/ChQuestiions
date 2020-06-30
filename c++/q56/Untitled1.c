typedef struct{
    int data;
    struct vector *next;
}vector;

void destruct(vector *v)
{
//todo: destruct a vector (free the allocated memory)
free(vec_char)
vectorFree(vec_char);
}
void extend(vector *v)
{
//todo: make the vector as twice long as it is now
realloc(vector, 2*size*sizeof(*v));
}
void contract(vector *v)
{
//todo: make the vector as half long as it is now
}

void push_back(vector *v, int element)
{
//todo: push a new element to the back of the vector
// remember to extend the vector if its size reaches the limit

if(limit >= size-1) vectorFull();
vector[++limit] = item;

}

void pop_back(vector *v)
{
//todo: remove the last element
// remember to contract the vector if its
// size reaches half of the limit

}

int get(vector *v, unsigned int index)
{
//todo: get the element of the vector at index
// if the index exceeds the size, return 0;
}

void change(vector *v, unsigned int index, int element)
{
//todo: change the term of the vector at the index to element.
// if the index exceeds the size, do nothing;

}

void print(vector *v)
{
//todo: print all the elements in the vector in a inline
// and then make a new line
}

void main(){
}
