# C++ STL (Standard Template Library)

- ## Containers
    ### Sequential Containers
    * Vector
        - Dynamic: Data is stored as in an array, but it is dynamic, or resizeable. Vectors can increase or decrease their size at runtime.
        - Initialization:
            - ```vector<datatype> name = {data};``` A vector with values (data)
               Ex: ```vector<int> vec1 = {1, 2, 3, 4, 5};```
            - ```vector<datatype> name(size, values);``` A vector with a size and values on every index
               Ex: ```vector<int> vec2(3, 10);``` => Output: [10, 10, 10]
            - ```vector<datatype> name(other_vector);``` A vector initialized with elements of another vector
               Ex: ```vector<int> vec2(vec1);``` => Output: [1, 2, 3, 4, 5]
        - Functions:
            - * TC = O(1)
            - size() - returns the size of the vector (number of elements stored in the vector)
            - capacity() - returns the capacity of the vector (number of elements a vector can currently hold)
            - push_back(data to be stored) - insert element at the end (assumes that data is already of the same type as of      vector)
            - emplace_back(data to be stored) - insert element at the end (create inplace objects of the required datatype)
            - pop_back() - delete element at the end
            - at(index) or [index] - returns data at the required location/position/index
            - front() - returns the first/front element
            - beack() - returns the last/back element
            - clear() - used to clear (delete all values) the vector
            - empty() - used to check whether the vector is empty or not
            - * TC = O(n), changes the size, but not capacity
            - erase(iterator_position) - used to erase an or a range of element in the vector
            - insert(position_iterator, value) - used to insert an element at a position in the vector
        - When we insert any data into a vector, a double sized new vector is created in the memory, the previous data is copied into the appropriate locations, and then the new data is inserted into the new vector. 
        Example: 
            vector size: 1
            new element is inserted 
            vector size will be doubled, new vector with size: 2
            previous data is copied into the new vector
            new element is inserted into the new vector
            next time, vector size will be doubled to 4

    * Vector - Iterators
        - begin: return begining iterator, imagine it like a pointer. It will point to first element's memory location
        - end: return ending iterator, imagine it like a pointer. It will point to last(next to n-1) element's memory location
            we can use derefrencing operator * to get the value.
        - rbegin: return begining iterator from last index
        - rend: return ending iterator from one previous to the start(i.e. befor 0th index)

        - Why we use iterators?
           . We use iterators to loop through the vectors
           . Create iterator: ```vector<datatype>::iterator iterator_name;```
           . Create reverse iterator: ```vector<datatype>::reverse_iterator iterator_name;```
           . creating a for loop will be like this: ```for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)```
           . Modern C++ gives us a feasability to write auto instead of defining the whole type of iterator
           . Write this ```for (auto it = vec.begin(); it != vec.end(); it++)```
           . It will understand the type of iterator variable from begin/rbegin
           . Loop through the vector using iterator
    
    * List
        - A sequntial container like vectors. 
        - Internally implemented as Double Linked List. Can be pushed/emplaced or popped from front and back.
        - Random access is not possible, such as ```li[3]``` will giev an error
        - initialization:
            - initialization of list can also be done like in vectors
        - Functions:
            - push_back: push elements at back 
            - push_front: push elements at front
            - emplace_back: push elements (create inplace object) at back 
            - emplace_front: push elements(create inplace object) at front
            - all other functions: size, erase, clear, begin, end, rbegin, rend, insert, fron, back, also exist in list
            - capacity function does not exist

    * Deque - Double Ended Queue:
        - Very similar to a list
        - Dequeue - this means to pop an element from a normal queue
        - Deque is implemented as dynamic arrays
        - Random access is possible, such as: ```dq[3]```
        - Initialization:
            ```deque<int> d = {1, 2, 3};```
        - Functions:
            - all functions: push_back, push_front, emplace_back, emplace_front, size, erase, clear, begin, end, rbegin, rend, insert, front, back, also exist in deque
            - capacity function does not exist
    
    ### Non-sequential Containers:
    * Pair:
        - Part of C++ utility libraries, can be created directly
        - Can be used to store two values of different types(or same)
        - We can use pair as a dataype such as, we need a pair of integer and pair of character and float
        - Initialization:
            - ```pair<int, int> p = {3, 2};```
            - ```pair<char, int> p = {'a', 1};```
            - ```pair<int, pair<char, float>> p = {1, {'d', 4.5f}};```
        - Attributes:
            - first, second -> returns the first and secont element of the pair

    * Stack:
        - LIFO - Last In First Out Structure
        - Inserts elements from top/front
        - Deletes elements from top/front
        - Initialization/Creation:
            - ```stack<datatype> name;``` => ```stack<int> s;```
        - Functions:
            - push, empalce: used to insert element at the top
            - top: to check which element is at the top of the stack
            - empty: checks if the stack is empty or not
            - size: returns the size of stack
            - swap: swaps one stack to another stack

    * Queue:
        - FIFO - First In First Out Structure
        - Inserts elements from rear/end/last
        - Deletes elements from front
        - Initialization/Creation:
            - ```queue<datatype> name;``` => ```queue<int> q;```
        - Functions:
            - push, empalce: used to insert element at the rear/end
            - front: to check which element is at the front of the queue
            - pop: removes element from front
            - empty: checks if the queue is empty or not
            - size: returns the size of queue
            - swap: swaps one queue to another queue

    * Priority Queue:
        - Internally, it use Max/Min Heap Structure that are complete binary trees
        - Max heap has the largest element at its root node 
        - Min heap has the smallest element at its root node 
        - At top/front, highest priority element will be stored(by default, larget value)
        - Initialization/Creation:
            - ```priority_queue<datatype> name;``` => 
                ```priority_queue<int> pq;``` creates a largest value priority queue
                ```priority_queue<int, vector<int>, greater<int>> pq;``` creates a smallest value priority queue
                    ```greater<int>``` is a functor: A functor is a function object, we pass it to do some work. It is like a comparator like a function whcih tells the logic for how to compare, we use them when we have to sort the data to ascending or descending order
        - Functions:
            - push, empalce: used to insert element at the rear/end, according to the priority(larget/smallest) of the value - TC = O(logn)
            - top: to check which element is at the top of the queue - TC = O(1)
            - pop: removes element from front - TC = O(logn)
            - empty: checks if the priority queue is empty or not
            - size: returns the size of priority queue

    * Map:
        - Specifically used to store key value pairs
        - Keys are unique values, such as registration number
        - Map stores the key values pairs in lexicographic order of keys. Sort the data in ascending order by default
        - Maps ar internally implemented as a self balancing tree
        - Initialization/Creation:
            ```map<key type, value type> name;``` => ```map<string, key> m;```
            To insert or change values in a map we use this syntax => ```m[key] = value```
        - Functions:
            - insert: emplace: used to insert new key value pairs in the map
            - count: returns the number of a specific key exists in map, takes parameter key
            - erase: erase any key value pair of specific key, takes parameter key
            - find: returns an iterator pointing to the key value pair if the key exists in map else returns end iterator
            - size: returns size of the map
            - empty: checks if the map is empty or not
            - TC = O(logn) for insert, erase, count

        - Types of Map:
            - 1. Multi Map: It is a map that can have multiple values for a single key
                - We can create duplicate keys, we do not use [] to insert data e.g. ```m["tv"] = 10;``` is not allowed
                - ALl other functionalities are same
            - 2. Unordered Map: It is a map that can have multiple values for a single key
                - Stores data in a random order
                - TC = O(1) for insert, erase, count, rarely it is O(n)

    * Set:
        - Similar to map, store unique values, in particular sorted order
        - if we try to insert duplicate data into a set, it will be stored only once, sets has unique data
        - Set also uses a self balancing tree internally
        - Initialization/Creation:
            ```set<datatype> name;``` => ```set<int> s;```
        - Functions:
            - insert, emplace: to insert data in a set
            - count, erase, find, size, empty works same as map
            - TC = O(logn) for insert, erase, count
            - lower_bound: we pass any value as a parameter in this function, it'll return an iteartor to that value if it exists in the set else it will return just greater value's iterator than the required one. It basically sets a condition that minimum value is required or just next greater of it, and if no value exits then it returns end iterator
            should not be less than key(paramter)
            - upper_bound: we pass any value as a parameter in this function, it'll return an iteartor to the value just next/greater to it
            greater than key

        - Types of set
            - 1. Multi Set: ```multiset<int> ms;```, it can store multiple elements, store duplicates, sorted
            - 2. Unordered Set: ```unordered_set<int> us;``` Random order, TC = O(1), rarely O(n), stores unique values, unsorted, no lower/upper bound
            

- ## Algorithms
    * Sorting
        - ```sort(arr, arr+n);```: Used to sort the array. Parameters: start and end(next to n-1) of the array, for vectors we can pass begin and end iteartors
        - By default, it sort in ascending order
        - ```sort(arr, arr + n, greater<int>());```: TO sort in descending order, we pass functor which is a comparator which basically is a function that tells the logic for camparison
        - To sort a vector of pairs, be default sort function sort it on the basis of the first values in the pairs
        - If we want to sort them using 2nd values, we will make custom comparators
        - Custom Comparator:
            - We make a custome function to comapre second values of two pairs. The logic would be as follows:
                ```bool cmparator(pair<int, int> p1, pair<int, int> p2) {```
                        ```if (p1.second < p2.second) return true;```
                        ```else return false;```
                    ```}```
                ```sort(vec.begin(), vec.end(), comparator);```
            - We can make any logic, like if second values are equal the compare first values etc. 
