Design principles are guidelines which helps us improve the quality of our application. They are preferred solutions for commonly occurring problems which when not dealt properly leads to a bad design.

We will be discussing on some of the design principles for Object oriented programming which every developer should be aware of. These Design principles go beyond the core object oriented concepts like Inheritance, Encapsulation, Abstraction and Polymorphism.

In this article i’ll be discussing some of the foundational design principle which I had used in my web development journey to solve some common problems.

Some of these Design Principles are,
“Encapsulate what varies”
“Favor composition”
“Program to interfaces”
“Loose coupling”
SOLID principles
Design Patterns vs Design Principles
Design Principles are general guidelines that can guide your class structure and relationships. On the other hand, Design Patterns are proven solutions that solve commonly reoccurring problems. Having said that, most of the practical implementations of these design principles are mostly done using one or more design patterns.

1. “Encapsulate what varies”
Considered as the foundational design principles, this principle is found at work in almost all design patterns.

This principle suggests, Identify the aspects of your applications that vary and separate them from what stays the same. If a component or module in your application is bound to change frequently, then it’s a good practice to separate this part of code from the stable ones so that later we can extend or alter the part that varies without affecting those that don’t vary.

Most design patterns like Strategy, Adapter, Facade, Decorator, Observer, etc follow this principle.

For example, Assume we are designing an app for a company that provides online service of household equipments. In our applications core we have this method processServiceRequest(), the purpose of which is to create instance of a OnlineService class based on the serviceType and process the request. This is a heavy duty method as shown below

public void processServiceRequest(String serviceType) {
     OnlineService service;
     if(service.equals("AirConditioner"))
       service = new ACService();
     else if(service.equals("WashingMachine"))
       service = new WMService();
     else if(service.equals("Refrigerator"))
       service = new RFService();
     else
       service = new GeneralService();
     service.getinfo();
     service.assignServiceRequest();
     service.assignAgent();
     service.processRequest();
}
Here, the type of service is a functionality which is bound to change at anytime. We might remove some services or add new and every such change in implementations would require to change this piece of code.

So, by the guidelines of “Encapsulate what varies” we need to find the code which is bound to vary and separate it so that any error in the same would not effect the important piece of code.

We can remove the code that creates instances and create a class which would work as a factory class that is only there to provide required type of instances. We are going to follow the Factory design pattern here and we will be having only one method getOnlineService() in this class which would do our job

public class OnlineServiceFactory {
   public OnlineService getOnlineService(String type) {
       OnlineService service;
       if(service.equals("AirConditioner"))
           service = new ACService();
       else if(service.equals("WashingMachine"))
           service = new WMService();
       else if(service.equals("Refrigerator"))
           service = new RFService();
       else
           service = new GeneralService();
       return service;
   }
}
now we can refactor our previous code as,

public void processServiceRequest(String serviceType) {
       OnlineService service = new OnlineServiceFactory().getOnlineService(serviceType);
       service.getinfo();
       service.assignServiceRequest();
       service.assignAgent();
       service.processRequest();
}
Now any changes with the service types wont affect the rest of the code.

2. “Favor Composition over Inheritance”
Object oriented programming provides 2 types of relationships between classes and its instances. has-a (composition) and is-a (inheritance). This design principle essentially suggests us that “has-a relationship should be preferred over is-a relationship”.

Most developers including me tend to lean over inheritance as their first resort in most cases to avoid code duplication and maintain reusability. Though a good practice, sometimes Inheritance when overused makes our code more rigid and not extensible.

Let’s take the example from the previous case, we have used is-a relationship to manage the OnlineService class with inherited service implementation classes like ACService, WMService, RFService, etc. Consider that the company decides to expand their business massively by adding more services like BikeService, CarService, TVService, LaptopService and many other household services. The above implementation would still hold good with inheritance model. But the complicated part here is that now they have planned to include multiple service models together like say a request for having multiple kitchen appliances serviced along with AC. This would lead to creating new classes for separate combination like ACAndFridgeService, ACAndTVServices. Which is not feasible and is literally a bad design. And more the combination more vulnerable this design would be to break.

Hence, we would want to go with a has-a relationship implementation. Where in each and every service in itself is a single class and based on the request we could combine those together and build our ultimate request.

We could use Builder design pattern here and return a compound object with each service requested by the user.


3. “Loose Coupling”
Loose coupling is a principle which suggests that “components interacting with each others should be independent of each others, relying on the knowledge of other component as little as possible”.

This is one principle we follow in a microservice architecture. The services interacting with each others are independent of each others. The interaction is strictly based on the data contracts.

Implementation of loose coupling would vary from scenario to scenario based on the problem we are trying to solve. But for our example let’s take a simple real time scenario.

Imagine we are designing a frontend application for a non monolithic architecture. We have a form for sign up which would get the user input, perform client side validations, sends request to the server via rest apis, get the response and based on the response it decides to show success or failure messages to the user.


Here, we can split the functionality into two based on its ownership. Ideally, anything specific to the client side should be decoupled from the server side operations. That is, the chunk of code responsible for form display, client side validations and displaying messages to the user should have nothing to do with the part of code which makes api requests, processes the response and return status.


4. “Program to interfaces, Not Implementations”
This design principle guides us to make use of abstract types not concrete ones. “Program to interfaces” actually mean program to a super type like an interface or abstract class in java. We are implementing polymorphism by programming to a super type so that the actual runtime object isn’t locked into your code.

Assume a database accessor layer in your application which is used to perform CRUD operations on your DB. Let’s consider that we implement a Service class which calls the DatabaseClient class (However practically we should have a DataAccessor class between Service and DatabaseClient). The DatabaseClient is concrete class programmed to access postgres DB. The DatabaseClient is a heavy duty class with all helper methods required to access the DB. Assume that the client decides to switch to a NoSQL database like MongoDB or add it as a secondary database for some specific purposes. This would lead to rewriting the DatabaseClient which would complicate things.

Solution? As this principle states, any such modules should have an abstract super type like an interface. The basic methods should be made available in the interface. Specific implementations should be implement the interface.


ServiceClass service = new ServiceClass();
if(dbType == "POSTGRES") {
    service.db = new PostgresDBClient();
} else if(dbType == "MYSQL") {
    service.db = new MySQLDBClient();
}
5. SOLID Principles
SOLID is a set of 5 principles which forms the acronym.

a.) Single responsibility principle:

A class should have only one reason to change. This principle suggests that the responsibilities of a class should be limited. It’s not a clear guideline because we don’t have a specific instruction on which basis to judge this. However, the basic idea when designing using this principle should be to check if the methods inside a class are cohesive i.e. do they really need to be together?

For example, a class which is required to create a rectangle which gets the area and draw the same on the screen.


This implementation violates the Single responsibility principle as calculating the area and drawing are separate actions and can be decoupled.

b.) Open closed principle:

This principle states that our design should be open for extension but closed for modifications. But what if we want to add a new implementation in our design? We can approach this in 2 ways.

We extend the existing functionality to a new class and add the implementations there
Use composition to accept new behaviours
Imagine that we have a class for auditioning singers.

public class Singers {
   String name;
   int age;
   String ratings;
   String typeOfSinging;
}
However, we decide to increase the scope of the contest to dancing as well, then we cannot have this concrete implementation. What we could do is, according to this principle, have our implementation abstracted and extended ass below.

public abstract class Contestants {
   String name;
   int age;
   String ratings;
}
public class Singer implements Contestants {
   String name;
   int age;
   String ratings;
   String typeOfMusic;
   public void sing() {
     ...
   }
}
public class Dancer implements Contestants {
   String name;
   int age;
   String ratings;
   String typeOfDance;
   public void dance() {
     ...
   }
}
By introducing inheritance, we solve the above complexity using Open closed principle.

c.) Liskov’s substitution principle:

Sometimes inheritance can break the system when we substitute our derived class with the parent class. Liskov’s principle essentially suggests that, “You should always be able to substitute subtypes for their base class.”

For example, If we have a ChildClass that extends a ParentClass, then our system should not break when our parent type instance is substituted with child class.

ClassA classA = new ClassA();
classA.doSomething();  // should work fine
ClassA = new ClassB();
classA.doSomething();  // should work fine
d.) Interface segregation principle:

This principle suggests that an “interface should always be cohesive”. That is, the components of the interface should be highly relatable. Any component that is not related to each other must be separated and segregated.

e.) Dependency inversion principle:

The Dependency inversion principle is used to decouple software modules. It states that “the high level modules should not depend on the low level modules. Instead both should depend on abstraction”.

For example, consider a Notifier class which sends SMS notification from SMSMessenger class as below.


Now assume that we want to add 2 more notification modes email and whatsapp. Since the Notifier class is tightly coupled to the SMSMessenger class, we cannot implement new messengers without changing the existing code.

How do we solve this? As this principle states, we need to decouple the dependency of the low level module SMSMessenger over high level module Notifier and have both modules depend on an abstraction. In this case, on abstraction of Messenger types.

We can do that as below.


Conclusion:
The design principles which covered in this article are kind of the fundamental and foundational one’s. There are few more such principles like DRY, AHA, KISS which I wanted to cover but I don’t feel could be explained in more specific way since they are mostly situational and varies based on the problems we are trying to solve.

DRY stands for Don’t Repeat Yourself which states that “Every piece of knowledge must have a single, unambiguous, authoritative representation within a system”. In other words it mean that every module must be unique in itself.
AHA stands for Avoid Hasty Abstractions which basically suggests us that sometimes abstractions can lead to a rigid codebase. And when it does, its better to avoid it.
KISS stands for Keep It Simple Stupid which as the acronym suggests that our implementation should be as simple as possible. Anything introducing complications in the implementation should be decoupled using any of the above principles.
