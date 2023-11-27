#include "vector.h"

// TODO: implement the reallocate, back, push_back, and vector_destroy functions. 
// If you have extra time, complete pop_back and insert.

typedef struct v {
    int* _arr;
    unsigned int _sz;
    unsigned int _cap;
} vector;

// Completed for you.
// Initializes v_ptr with empty array, 0 size and capacity.
void vector_init(vector* v_ptr) {
    // Consider this after completing 
    v_ptr->_arr = malloc(0);
    v_ptr->_sz = 0;
    v_ptr->_cap = 0;
}

// Completed for you.
// Returns vector size.
unsigned int vector_get_size(vector* v_ptr) {
    return v_ptr->_sz;
}

// Completed for you.
// Returns vector capacity.
unsigned int vector_get_capacity(vector* v_ptr) {
    return v_ptr->_cap;
}

// TODO: complete this function.

// vector_reallocate should do the following:
    // 1. Allocates a new array that has double the capacity of current _cap value.
    // 2. Copies the contents of the current internal array into the new array.
    // 3. Points the member variable _arr to the new array.
    // 4. Frees the old (no longer pointed to) array.
// HINT: since you are using an int* vector, keep in mind that ints are 4 bytes 
// (on most modern machines like the ones you are using).
void vector_reallocate(vector* v_ptr) {

}

// TODO: complete this function.

// vector_back should return the last element in the vector.
int vector_back(vector* v_ptr) {

}

// TODO: complete this function.

// vector_push_back should do the following:
    // If adding one element would exceed capacity, call vector_reallocate. 
    // Add the element to the back of the vector.
        // HINT: think about what index this element should have. You should
        // try to express this index with a variable.
void vector_push_back(vector* v_ptr, int x) {

}

// TODO: complete this function.

// vector_destroy should free any dynamically allocated memory.
void vector_destroy(vector* v_ptr) {

}

// TODO: If you have extra time, complete this function.

// vector_pop_back should "remove" an element. 
// HINT: think about what should happen if you are about to exceed capacity,
// call vector_pop_back, then call vector_push_back. Should capacity double?
void vector_pop_back(vector* v_ptr) {

}

// TODO: If you have extra time, complete this function.

// vector_insert should insert x before position idx in the array.
    // For example, with a vector with values 
    // {0, 1, 2, 3, 5}
    // calling vector_insert(v_ptr, 4, 4) would mutate the array into
    // {0, 1, 2, 3, 4, 5}
// HINT: How do you move elements backwards in an array?
// HINT: When do you need to reallocate?
void vector_insert(vector* v_ptr, int x, unsigned int idx) {

}

// Very, very simple test case. Feel free to adjust this as you see fit.
int main() {
    vector v;
    vector* v_ptr = &v;
    vector_init(v_ptr);
    printf("Initialized vector with size %d and capacity %d\n", 
                    vector_get_size(v_ptr), vector_get_capacity(v_ptr));

    // By the end of this main function, _sz should increase to 9 
    // and _cap should increase to 16.
    vector_push_back(v_ptr, 1);
    vector_push_back(v_ptr, 2);
    printf("Vector should have size 2 and capacity 2, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));
    vector_push_back(v_ptr, 3);
    printf("Vector should have size 3 and capacity 4, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));
    vector_push_back(v_ptr, 4);
    printf("Vector should have size 4 and capacity 4, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));
    vector_push_back(v_ptr, 5);
    printf("Vector should have size 5 and capacity 8, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));
    vector_push_back(v_ptr, 6);
    vector_push_back(v_ptr, 7);
    vector_push_back(v_ptr, 8);
    printf("Vector should have size 8 and capacity 8, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));
    vector_push_back(v_ptr, 9);
    printf("Vector should have size 9 and capacity 16, has size %d and capacity %d\n", 
                vector_get_size(v_ptr), vector_get_capacity(v_ptr));

    vector_destroy(v_ptr);
}
