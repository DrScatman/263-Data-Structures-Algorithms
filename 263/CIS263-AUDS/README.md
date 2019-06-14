# CIS263-AUDS
For this assignment you will create an Almost Useless Data Structure (AUDS).  This data structure will hold any type of object, through the use of a class template.  The data structure will operate as follows:

- The class will be called ```AUDS```
- The constructor will take no parameters
- The data structure will ensure all instance variables and the stored data is private.
- The data structure will store objects in an array
- The data structure will initially have space for 100 items
- The data structure will automatically resize by 50% whenever a user inserts an item that puts it over the currently full value

Additionally, the data structure must implement the following methods:

- ```AUDS(const AUDS &other);``` - This is the copy constructor.  It will take as a parameter a reference to another AUDS object and will perform a DEEP copy of the object.
- ```AUDS& operator=(AUDS other);``` - This is the copy operator=.  It will perform the copy-and-swap we learned about in class to set one object equal to another.  It also performs a DEEP copy.
- ```~AUDS();``` - This is the destructor.  It will give back any memory we borrowed from the OS to hold the data we stored.
- ```int size();``` - Returns the current number of objects we are holding.
- ```void push(T x);``` - Adds the generic element to the data structure.
> Be sure to adjust the size!
- ```T pop();``` - Removes a random item from the list.  Moves the last item in the array to the spot that was occupied by the element we removed.
> Be sure to adjust the size! 
- You will likely need various helper methods as well.  Feel free to write whatever is needed, but protect your data!  Helper methods generally shouldn't be visible outside our class.

## Grading

Grading rubric is as follows:
- **80 Points** - Passes all tests
- **10 Points** - There are a few functions I can't easily write tests for (i.e. the Destructor).  I will look at these individually and grade their correctness.
- **10 Points** - Adheres to style guide


