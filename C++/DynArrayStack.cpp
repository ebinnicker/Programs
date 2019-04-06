//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                              DynArrayStack                               //
//                            DynArrayStack.cpp                             //
//                                                                          //
// Written By :                         Environment : Mac OS X 10.13.3      //
// Date ......: 2018/04/01              Compiler ...: Homebrew GCC 6.3.0_1  //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                 Includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "DynArrayStack.h"

//////////////////////////////////////////////////////////////////////////////
//                     Public Interface Implementation                      //
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
*                       DynArrayStack::DynArrayStack()                       *
*                                                                            *
*                                                                            *
* Written By :                          Environment : Mac OS X 10.13.3       *
* Date ......:  2018/04/01              Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
DynArrayStack::DynArrayStack() : capacity{init_size}, top{0}, v{nullptr}
{
    v = new char[init_size];
}

/*****************************************************************************
*                      DynArrayStack::~DynArrayStack()                       *
*                                                                            *
* Written By :                          Environment : Mac OS X 10.13.3       *
* Date ......:  2018/04/01              Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
DynArrayStack::~DynArrayStack()
{
    delete v;
}

/*****************************************************************************
*                      void DynArrayStack::push(char c)                      *
*                                                                            *
* Written By :                          Environment : Mac OS X 10.13.3       *
* Date ......:  2018/04/01              Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
void DynArrayStack::push(char c)
{
	if (top <= 0) throw Underflow ();
	
	else if (top <= (capacity/2)){
		char *a = new char[2*capacity];
		
		for (int i=0; i<capacity; ++i){
			cpy[i] = v[i];
		}
	} 
	delete[] v;
	v = cpy;
	capacity = 2*capacity;
	}
	v[top] = c;
    top += 1;
	
	return v[top];
	
	
}

/*****************************************************************************
*                         char DynArrayStack::pop()                          *
*                                                                            *
* Written By :                          Environment : Mac OS X 10.13.3       *
* Date ......:  2018/04/01              Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
char DynArrayStack::pop()
{
    if (top <= 0) throw Underflow();
    top -= 1;
    return v[top];
}

DynArrayStack::DynArrayStack(char c) DynArrayStack::DynArrayStack() : capacity{init_size}, top{0}, v{nullptr}{
	v = new char[init_size];
	push(c);	
}

//////////////////////////////////////////////////////////////////////////////
//                      Private Method Implementations                      //
//////////////////////////////////////////////////////////////////////////////

