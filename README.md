English-language slidedeck and code files for lab 7 in AL Basics of Programming class.

# Instructions for class

**READ** the section below on the C++ `vector` class before proceeding.

You should need to **add all files (.h and .c) to the project** in CodeBlocks; otherwise, you will be unable to correctly run your code. Ask Kevin for help if necessary.

---

Download all files in this repository and upload them to a CodeBlocks project. Complete the warmup functions in `warmup.c` and the member functions of `vector` in `vector.c`. You can use the main function in `lab07.c` for testing.

If you would like to run these files in a Unix environment outside of CodeBlocks, you can run `make lab07` in the command line. This will compile and execute your program for you. You will need to ensure that `make` and `gcc` are both installed in your environment. 

Solution file will be uploaded after class, exact time / date TBD.

---

The concepts covered here are typically part of the second year of classes for a student at the University of Michigan. I have explained the core theoretical parts here and simplified a lot of the code; however, I still expect this to be your most difficult assignment from me.

## The C++ vector

For our purposes, C++ is C with extra functionality. There is a lot more to this, especially with changes to the C++ language from 2011 onwards, but they require more time and effort to discuss than what would be appropriate for this class.

C++ uses something called classes to implement data structures - read more here in English ([https://learn.microsoft.com/en-us/cpp/cpp/class-cpp?view=msvc-170](https://learn.microsoft.com/en-us/cpp/cpp/class-cpp?view=msvc-170)) or Polish ([https://learn.microsoft.com/pl-pl/cpp/cpp/class-cpp?view=msvc-170](https://learn.microsoft.com/pl-pl/cpp/cpp/class-cpp?view=msvc-170)). `vector` is one of these data structures, and you will be implementing some of the basic functionality of `vector` for this lab.

`vector` acts as an extension of C arrays. The main difference is that `vector` does not have a fixed size like arrays do; the programmer can add as many elements as they want, and `vector` will resize itself to fit those elements. The resizing process relies on dynamic memory allocation as follows.

### Growing a C++ vector with dynamic allocation

First, let's distinguish **size** and **capacity**. 

```c
int arr[10];
arr[0] = 2;
arr[1] = 1;
```

The above array has a **size** of 2 and a **capacity** of 10. It is capable of holding 10 elements, but currently only holds 2. So size == how many elements are currently inside, capacity == how many elements *can* be inside if you filled it up.

Each `vector` object has an array member variable. (If you don't remember what a member variable is, feel free to review Lab 6 or look up online sources.) Here, I will refer to this as the "internal array" of a `vector` object. When you initialize a `vector` object ("initialize" is a coding term for "create"), the internal array starts with size and capacity of 0 by default.

```
|
```

Let's add one element. In C++, we do this using a function named `push_back`. 

```
|x|
```

When adding elements, we care about the current capacity of the vector and whether adding an element pushes us over capacity. In this case, it did - our capacity was 0. So we will increase our capacity to 1.

From here on, **every time we find that we do not have enough capacity, we will double the capacity**.

Let's push back another element.

```
|x|x|
```

The capacity has doubled to 2. Let's push back another element.

```
|x|x|x| |
```

Capacity has doubled once again. We have a size of 3 but a capacity of 4; we don't need to increase the capacity if we push back one more time. Let's push back again and observe:

```
|x|x|x|x|
```

Capacity is still 4. Let's push back now and exceed capacity:

```
|x|x|x|x|x| | | |
```

From here the pattern becomes pretty clear. We can push back three times without exceeding capacity. When we push back a fourth time afterward, we will double the capacity again to 16. This is how the vector looks if we push back 4 times:

```
|x|x|x|x|x|x|x|x|x| | | | | | | |
```

### Implementing the reallocation step

The diagrams above are an oversimplification. When we exceed capacity, we actually run a `reallocate` function that does these things in order:

1. Allocates a new array with double the capacity of the current internal array.

2. Copies the contents of the current internal array into the new array.

3. Points the member variable to the new array.

4. Frees / deletes the old (no longer pointed to) array.

See lab 7 slides if you need a refresher on dynamic memory allocation.

You will be implementing this reallocate function, along with `back` (gets the last element in the vector), `push_back`, and `destroy` (destroys the vector and any dynamically allocated memory associated with it.) 

### Why?

You may be wondering why we use this doubling mechanism instead of something conceptually simpler. For example, why not reallocate and increase the array's size every time we insert? This would result in less code and be easier to understand. 

This is a good question to ask, and the answer requires some basic understanding of something called *computational complexity*. This is a way to mathematically describe the efficiency of your code. For now, think of it like this: if we allocate . With our doubling mechanism, we only need to copy over the array when we fill

Understanding computational complexity is one of the first quintessential differences between just "programming" or "IT" and genuine computer *science*. Real computer science forces you to think and make smart decisions. If you can correctly explain to someone else why the capacity doubling method for `vector` is efficient and the "increase size by one each time" method is not, you will start to become dramatically more useful and valuable as a programmer.

### A note on sources

I am actually unable to find a source for this that I'm satisfied with. If you would like to run some C++ code that demonstrates the doubling algorithm, run the main function in `vector_example.cpp`. The rest of the note gets into some subjects that are beyond this course.

It seems like the exact algorithm used for reallocation is dependent on the specific compiler. My machine runs `g++` and appears to follow this doubling behavior for the first 9 insertions. A little bit of digging into either cplusplus.com or cppreference.com suggests that the C++ standard leaves the exact details up to implementation, so long as the end result is that `push_back` is amortized O(1). The algorithm I presented above is probably the simplest way to achieve this O(1) complexity; I'm sure that somewhere out there is a more advanced method that works better in *some* cases (although I'd be surprised if there was something theoretically or empirically proven to be better in the average case).   
