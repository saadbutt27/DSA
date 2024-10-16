## C++ STL (Standard Template Library)

- Containers
    * Vector
        - Dynamic: Data is stored as in an array, but it is dynamic, or resizeable. Vectors can increase or decrease their size at runtime.
        - Initialization:
            - vector<datatype> name = {data}; A vector with values (data)
               Ex: vector<datatype> vec1 = {1, 2, 3, 4, 5};
            - vector<datatype> name(size, values); A vector with a size and values on every index
               Ex: vector<datatype> vec2(3, 10); => Output: [10, 10, 10]
            - vector<datatype> name(other_vector); A vector initialized with elements of another vector
               Ex: vector<datatype> vec2(vec1); => Output: [1, 2, 3, 4, 5]
        - Functions:
            - * TC = O(1)
            - size() - returns the size of the vector (number of elements stored in the vector)
            - capacity() - returns the capacity of the vector (number of elements a vector can currently hold)
            - push_back(data to be stored) - insert element at the end (data is already of the same type as of vector??)
            - emplace_back(data to be stored) - insert element at the end (create inplace / emplace objects)
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
           . Create iterator: vector<datatype>::iterator iterator_name;
           . Create reverse iterator: vector<datatype>::reverse_iterator iterator_name;
           . creating a for loop will be like this: for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
           . Modern C++ gives us a feasability to write auto instead of defining the whole type of iterator
           . Write this for (auto it = vec.begin(); it != vec.end(); it++)
           . It will understand the type of iterator variable from begin/rbegin
           . Loop through the vector using iterator
    
    * List
        - A sequntial container like vectors. 
        - Internally implemented as Double Linked List. Can be pushed/emplaced or popped from front and back.
        - Random access is not possible, such as li[3] will giev an error
        - initialization:
            - initialization of list can also be done like in vectors
        - Functions:
            - push_back: push elements at back 
            - push_front: push elements at front
            - emplace_back: push elements (create implace/inplace object) at back 
            - emplace_front: push elements(create implace/inplace object) at front
            - all other functions: size, erase, clear, begin, end, rbegin, rend, insert, fron, back, also exist in list

    * Deque - Double Ended Queue:
        - Very similar to a list
        - Dequeue - this means to pop an element from a normal queue
        - Deque is implemented as dynamic arrays
        - Random access is possible, such as : dq[3]
        - Initialization:
            deque<int> d = {1, 2, 3};
        - Functions:
            - all functions: push_back, push_front, emplace_back, emplace_front, size, erase, clear, begin, end, rbegin, rend, insert, front, back, also exist in deque
- Algorithms
- Functors