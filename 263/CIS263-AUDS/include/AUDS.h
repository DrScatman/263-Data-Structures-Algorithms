/*****************************************************************
For this assignment you will create an Almost Useless Data
Structure (AUDS). This data structure will hold any type of
object, through the use of a class template.
 
@author Jake Miller
@version Winter 2018
 *****************************************************************/
#include <iostream>
#include<string>
#include <stdlib.h>
#include <time.h>

/** Makes a template of type generic type T */
template <typename T>
class AUDS{
	public:

	        /**************************************************
 		Default constructor that creates the array of type
		T and sets its size.
                **************************************************/
		AUDS(){
			arr = new T[maxSize];
		} 
		/***************************************************
		This is the copy constructor. It will take as a 
		parameter a reference to another AUDS object and 
		will perform a DEEP copy of the object.
		
		@param AUDS& reference to AUDS
                ***************************************************/
		AUDS(const AUDS &other){
			maxSize = other.maxSize;
			cSize = other.cSize;
			arr = new T[maxSize];
			for(int c = 0; c < maxSize; c++){
				arr[c] = other.arr[c];
			}
		}
		/***************************************************i
                This is the copy operator=. It will perform the 
		copy-and-swap we learned about in class to set one 
		object equal to another. It also performs a DEEP 
		copy.

		@param AUDS another copy of AUDS
 		@return Returns the new array
                ***************************************************/
		AUDS& operator=(AUDS other){
			swap(cSize, other.cSize);
			swap(maxSize, other.maxSize);
			swap(arr, other.arr);
			return *this;
		}
		/***************************************************
                This is the destructor. It will give back any 
		memory we borrowed from the OS to hold the data we 
		stored.
                ***************************************************/
		~AUDS(){
                       delete[] arr;
                }
		/***************************************************
                Returns the current number of objects we are 
		holding.

		@return int - The current size of the array
                ***************************************************/
		int size(){
			return cSize;
		}
		/***************************************************
                Adds the generic element to the data structure.
  		@param T the element to add to the array
                @return none
                ***************************************************/
		void push(T x){
			if(cSize == maxSize){
				maxSize = cSize + (maxSize / 2);                  
				T* temp = new T[maxSize];
				for(int c = 0; c < cSize; c++){
					temp[c] = arr[c]; 
				}
				delete[] arr;
				arr = temp;
			}
			arr[cSize] = x;
			cSize++;
		}
		/***************************************************
                Removes a random item from the list. Moves the last
		item in the array to the spot that was occupied by 
		the element we removed.

                @return element remved from array
                ***************************************************/	
		T pop(){
			// Learned from http://www.cplusplus.com/forum/beginner/26611/
			srand ( time(NULL) ); //initialize the random seed
			int r = rand() % cSize; //generates a random number between 0 and cSize
			T elm = arr[r];
			arr[r] = arr[cSize-1];
			cSize--;
			return elm;
		}
		
	private:
		/** Pointer of type T */
		T* arr;
		/** Current size of array */
		int cSize = 0;
		/** Max size of the array */
		int maxSize = 100;
};

