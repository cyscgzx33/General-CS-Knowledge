#include <stdio.h>

void* dummyFunc(void* x)
{	
	printf("Address returned from dummyFunc.\n");
}

int dummy_int_glb;

int* dummyFunc2(void* x)
{
	printf("Address returned from dummyFunc2.\n");
	return &dummy_int_glb;
}

// just an alias, to make invoke easier
typedef void* (*dummyFuncPtr)(void*); 

void dummyInvoker(dummyFuncPtr dummy_func_ptr)
{
	// invoke the deferenced dummy_func_ptr
	void* addr_dummy_func = (*dummy_func_ptr)(NULL);
	// print out the void* address returned by the dereference function
	printf("%s%p\n","The address returned is: ", addr_dummy_func); 
}

// for clarity, no typedef version
void dummyInvoker2( void* (*dummy_func_ptr)(void*) )
{	
	// invoke the deferenced dummy_func_ptr
	void* addr_dummy_func = (*dummy_func_ptr)(NULL);
	// print out the void* address returned by the dereference function
	printf("%s%p\n","The address returned is: ", addr_dummy_func);
}

int main(void)
{
	dummyFuncPtr example_func_ptr = &dummyFunc;  // create a function pointer
                                                 // '&' is actually redundant,
                                                 // w/o '&' it's also legal
	dummyInvoker(example_func_ptr);
	dummyInvoker2(&dummyFunc2);
	return 0;
}