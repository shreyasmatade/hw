# Description
## Problem:   
Write a function that removes all duplicates from an unsorted list of email addresses, while leaving the remaining list in the original order. Prove that this function can handle 100,000 email addresses containing 50% randomly placed duplicates, in under 1 second on a typical laptop.

## Approach:
We have to remove the duplicates from the unordered list and also preserve the original order. 
So we can loop thourgh the list in O(n) time, and as we go we will keep track of items in a temperory container 
If next item in the list is already present in container then it is a duplicate, so we will remove from the list; if item does not exist in container then it is unique and we will add it to container.
## Selection of Data Structure
Since we need to remove items from the list, that tells us we need to have constant time removal of item.
so lets use std::list which is linked list implementation to hold list of emails.
Also, for temporary container we need to perform frequent checks so we need container with constant time lookup and also hold only unique items.
so std::set fits the bill.

# Build and Run Steps
## Prerequisite
gcc version 9.3.0.
## Compilation Steps
`gcc main.cpp -o main` - This compiles the code and creates executable "main"
## Running the executable 
`./main `

# Sample output 
No Duplication Test Passed - Time Taken :0.224512 Seconds  
Half Duplication Test Passed - Time Taken :0.136747 Seconds  
All Duplication Test Passed - Time Taken :0.020916 Seconds   

