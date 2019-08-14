# Ising
Ising with Sparse Matrix

========================================================================
Introduction
========================================================================

This project includes classes and samples to compute energy 
using Ising Model. It also illustrates the basic use of Boost.Test. 

http://www.boost.org/doc/libs/1_61_0/libs/test/doc/html/index.html.

========================================================================
Prerequisites
========================================================================

The samples were developed on ubuntu.
------------------------------------------
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=14.04
DISTRIB_CODENAME=trusty
DISTRIB_DESCRIPTION="Ubuntu 14.04.3 LTS"
-------------------------------------------

They also require:
- g++ (for building)
- Boost 1.58.0 (possibly later versions),
  installed in the system include and library paths.

========================================================================
Folder Structure
========================================================================
--|
  |
  -/Example => This folder has examples to show how to use various classes.
  |
  -/src => Class definitins.
  |
  -/inc => header files or class declarations.
  |
  -/UnitTests => For unit testing.
  
Please pass '--log_level=test_suite' as command-line argument to unit test 
for the detailed output.


For Example:
./Ising_UnitTest --log_level=test_suite
========================================================================
Building and Running
========================================================================

To build the samples, run make:

$ root/Example/make -f makefile

This creates Ising executable.

$ root/UnitTests/make -f makefile

This will execute all the unit tests.

========================================================================
Main Classes
========================================================================
DataHelper : This class has static method that can generate random matrix 
             and 'S' vector.
MatrixEntry : This class basically represents a cell in matrix. 
SMNormalizer : This class has a method that can normalize the 
             sparse matrix.
IsingModel : to compute the energy.


