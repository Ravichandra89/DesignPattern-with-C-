# Design Principle 1: Encapsulate what varies
## Description:
Considered as the foundational design principles, this principle is found at work in almost all design patterns.

This principle suggests, Identify the aspects of your applications that vary and separate them from what stays the same. If a component or module in your application is bound to change frequently, then it’s a good practice to separate this part of code from the stable ones so that later we can extend or alter the part that varies without affecting those that don’t vary.

Most design patterns like Strategy, Adapter, Facade, Decorator, Observer, etc follow this principle.

For example, Assume we are designing an app for a company that provides online service of household equipments. In our applications core we have this method processServiceRequest(), the purpose of which is to create instance of a OnlineService class based on the serviceType and process the request. This is a heavy duty method as shown below

```bash
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
```
Here, the type of service is a functionality which is bound to change at anytime. We might remove some services or add new and every such change in implementations would require to change this piece of code.

So, by the guidelines of “Encapsulate what varies” we need to find the code which is bound to vary and separate it so that any error in the same would not effect the important piece of code.

We can remove the code that creates instances and create a class which would work as a factory class that is only there to provide required type of instances. We are going to follow the Factory design pattern here and we will be having only one method getOnlineService() in this class which would do our job

```bash
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
```

# 2. “Favor Composition over Inheritance”
Object oriented programming provides 2 types of relationships between classes and its instances. has-a (composition) and is-a (inheritance). This design principle essentially suggests us that “has-a relationship should be preferred over is-a relationship”.

Most developers including me tend to lean over inheritance as their first resort in most cases to avoid code duplication and maintain reusability. Though a good practice, sometimes Inheritance when overused makes our code more rigid and not extensible.

Let’s take the example from the previous case, we have used is-a relationship to manage the OnlineService class with inherited service implementation classes like ACService, WMService, RFService, etc. Consider that the company decides to expand their business massively by adding more services like BikeService, CarService, TVService, LaptopService and many other household services. The above implementation would still hold good with inheritance model. But the complicated part here is that now they have planned to include multiple service models together like say a request for having multiple kitchen appliances serviced along with AC. This would lead to creating new classes for separate combination like ACAndFridgeService, ACAndTVServices. Which is not feasible and is literally a bad design. And more the combination more vulnerable this design would be to break.

Hence, we would want to go with a has-a relationship implementation. Where in each and every service in itself is a single class and based on the request we could combine those together and build our ultimate request.

We could use Builder design pattern here and return a compound object with each service requested by the user.

![image](https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/cb3a0e83-0f94-4c23-9548-8c8682529b69)

# 3. “Loose Coupling”
Loose coupling is a principle which suggests that “components interacting with each others should be independent of each others, relying on the knowledge of other component as little as possible”.

This is one principle we follow in a microservice architecture. The services interacting with each others are independent of each others. The interaction is strictly based on the data contracts.

Implementation of loose coupling would vary from scenario to scenario based on the problem we are trying to solve. But for our example let’s take a simple real time scenario.

Imagine we are designing a frontend application for a non monolithic architecture. We have a form for sign up which would get the user input, perform client side validations, sends request to the server via rest apis, get the response and based on the response it decides to show success or failure messages to the user.

![image](https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/96c8575b-f0e1-44dc-b51d-3d933f7a77d3)


Here, we can split the functionality into two based on its ownership. Ideally, anything specific to the client side should be decoupled from the server side operations. That is, the chunk of code responsible for form display, client side validations and displaying messages to the user should have nothing to do with the part of code which makes api requests, processes the response and return status.

![image](https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/e25bd641-0324-4f81-9910-fe2f2e3a6b94)

# 4. “Program to interfaces, Not Implementations”
This design principle guides us to make use of abstract types not concrete ones. “Program to interfaces” actually mean program to a super type like an interface or abstract class in java. We are implementing polymorphism by programming to a super type so that the actual runtime object isn’t locked into your code.

Assume a database accessor layer in your application which is used to perform CRUD operations on your DB. Let’s consider that we implement a Service class which calls the DatabaseClient class (However practically we should have a DataAccessor class between Service and DatabaseClient). The DatabaseClient is concrete class programmed to access postgres DB. The DatabaseClient is a heavy duty class with all helper methods required to access the DB. Assume that the client decides to switch to a NoSQL database like MongoDB or add it as a secondary database for some specific purposes. This would lead to rewriting the DatabaseClient which would complicate things.

Solution? As this principle states, any such modules should have an abstract super type like an interface. The basic methods should be made available in the interface. Specific implementations should be implement the interface.

![image](https://github.com/Ravichandra89/LLD-DesignPattern/assets/134200599/d3d0385d-5952-4097-a1d5-1faae6196c65)

```bash
ServiceClass service = new ServiceClass();
if(dbType == "POSTGRES") {
    service.db = new PostgresDBClient();
} else if(dbType == "MYSQL") {
    service.db = new MySQLDBClient();
}
```

# Conclusion:
The design principles which covered in this article are kind of the fundamental and foundational one’s. There are few more such principles like DRY, AHA, KISS which I wanted to cover but I don’t feel could be explained in more specific way since they are mostly situational and varies based on the problems we are trying to solve.

DRY stands for Don’t Repeat Yourself which states that “Every piece of knowledge must have a single, unambiguous, authoritative representation within a system”. In other words it mean that every module must be unique in itself.
AHA stands for Avoid Hasty Abstractions which basically suggests us that sometimes abstractions can lead to a rigid codebase. And when it does, its better to avoid it.
KISS stands for Keep It Simple Stupid which as the acronym suggests that our implementation should be as simple as possible. Anything introducing complications in the implementation should be decoupled using any of the above principles.
