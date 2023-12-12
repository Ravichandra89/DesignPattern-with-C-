# Builder Pattern

## Overview

The Builder Pattern is a creational design pattern that separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

This repository provides an example implementation of the Builder Pattern in C++, along with an algorithmic representation to help understand its structure and usage.

## Problem

Imagine a complex object that requires laborious, step-by-step initialization of many fields and nested objects. Such initialization code is usually buried inside a monstrous constructor with lots of parameters, leading to code that is hard to read, maintain, and extend. For example, let’s consider the scenario of creating a `House` object. To build a simple house, you need to construct four walls and a floor, install a door, fit a pair of windows, and build a roof. However, as the complexity grows, like wanting a bigger house with a backyard and additional features (heating system, plumbing, electrical wiring), the code becomes unwieldy.

<img width="726" alt="Screenshot 2023-12-12 at 9 51 35 AM" src="https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/1fa241e5-13e0-4410-b46a-1496ec8cc0b4">

The typical solutions involve either creating a hierarchy of subclasses for different combinations of parameters or having a giant constructor in the base `House` class with all possible parameters, leading to its own set of issues.

## Solution: Builder Pattern

The Builder pattern suggests that you extract the object construction code out of its own class and move it to separate objects called builders. The pattern organizes object construction into a set of steps (`buildWalls`, `buildDoor`, etc.). To create an object, you execute a series of these steps on a builder object. The key advantage is that you only need to call the steps necessary for producing a particular configuration of an object.

<img width="653" alt="Screenshot 2023-12-12 at 9 52 43 AM" src="https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/1ebecb30-f808-42ef-969d-9b8cc2eecfde">


Some construction steps might require different implementations when building various representations of the product. For example, the walls of a cabin may be built of wood, while castle walls must be built with stone. In this case, you can create several different builder classes implementing the same set of building steps but in different manners. These builders can then be used in the construction process to produce different kinds of objects.

## Director Class

You can go further and extract a series of calls to the builder steps used to construct a product into a separate class called a director. The director class defines the order in which to execute the building steps, while the builder provides the implementation for those steps. The director knows which building steps to execute to get a working product.

While having a director class is not strictly necessary, it offers advantages like reusability across the program. The director class hides the details of product construction from the client code, allowing the client to associate a builder with a director, launch the construction with the director, and retrieve the result from the builder.

## Example Code

The `main.cpp` file in this repository provides a practical example demonstrating the usage of the Builder Pattern in C++. The example showcases the creation of a `House` object using different builders and a director to control the construction process.

## Implementation

### 1. Product Class

The `Product` class represents the complex object being constructed. It may include properties and methods relevant to the final product.

### 2. Builder Interface

The `Builder` interface declares methods for each step involved in constructing the product. It also includes a method to get the constructed product.

```cpp
class Builder {
public:
    virtual void buildStep1() = 0;
    virtual void buildStep2() = 0;
    // ... (other steps)
    virtual Product* getResult() = 0;
};
```
3. ConcreteBuilder Classes
ConcreteBuilder classes implement the Builder interface. They provide specific implementations for each step in constructing the product and keep a reference to the product being constructed.

class ConcreteBuilder : public Builder {
public:
    void buildStep1() override { /* ... */ }
    void buildStep2() override { /* ... */ }
    // ... (implement other steps)
    Product* getResult() override { /* return the constructed product */ }
};

4. Director Class
The Director class is responsible for directing the construction process using a specific builder. It holds a reference to the Builder interface.

class Director {
private:
    Builder* builder;

public:
    void setBuilder(Builder* newBuilder) {
        builder = newBuilder;
    }

    void constructProduct() {
        builder->buildStep1();
        builder->buildStep2();
        // ... (invoke other steps)
    }
};

5. Client Code
In the client code, choose a ConcreteBuilder based on the desired product variation. Create an instance of the Director and set the chosen ConcreteBuilder. Use the Director to construct the product, invoking the builder's methods step by step. Retrieve the constructed product from the builder.

ConcreteBuilder concreteBuilder;
Director director;
director.setBuilder(&concreteBuilder);
director.constructProduct();
Product* product = concreteBuilder.getResult();


