# Interview
[![Build Status](https://travis-ci.org/czchen/interview.svg?branch=master)](https://travis-ci.org/czchen/interview)

Interview coding question collection.

# What You Must Know

## Data Structure

*   Linked Lists
*   Binary Trees
*   Tries Binary
*   Stacks
*   Queues
*   Vectors / ArrayLists
*   Hash Tables

## Algorithm

*   Breadth First Search
*   Depth First Search
*   Binary Search
*   Merge Sort
*   Quick Sort
*   Tree Insert / Find / etc

## Concept

*   Bit Manipulation
*   Singleton Design Pattern
*   Factory Design Pattern
*   Memory (Stack vs Heap)
*   Recursion
*   Big-O Time

# Algorithm Approach

## Examplify

Write out specific examples of the problem, and see if you can figure out a
general rule.

## Pattern Matching

Consider what problems the algorithm is similar to, and figure out if you can
modify the solution to develop an algorithm for this problem.

## Simplify & Generalize

Change a constraint (data type, size, etc) to simplify the problem. Then try to
solve it. Once you have an algorithm for the “simplified” problem, generalize
the problem again.

## Base Case And Build

Solve the algorithm first for a base case (e.g., just one element). Then, try
to solve it for elements one and two, assuming that you have the answer for
element one. Then, try to solve it for elements one, two and three, assuming
that you have the answer to ele- ments one and two.

## Data Structure Brainstorm

This is hacky, but it often works. Simply run through a list of data structures
and try to apply each one.

# Whiteboard Tips

*   State your assumption.
    *   Assume the caller does not pass `NULL` to any parameter.
    *   Assume there is no integer overflow.
    *   Assume upper and lower case are distinct.
*   For integral type, ensure using `signed` and `unsigned` correctly.
    *   Cast `char` to `unsigned char` when using it as array index.
*   Ensure string is NULL-terminated.

# Reference

*   [Cracking the Coding Interview, fourth edition](http://www.amazon.com/Cracking-Coding-Interview-Fourth-Edition/dp/145157827X)
