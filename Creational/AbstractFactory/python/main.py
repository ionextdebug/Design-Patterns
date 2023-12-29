from abc import ABC, abstractmethod

class AbstractProductA(ABC):
    
    @abstractmethod
    def useful_method_a(self)->str:
        pass


class AbstractProductB(ABC):
    
    @abstractmethod
    def useful_method_b(self)->str:
        pass

    @abstractmethod
    def another_useful_method_b(self, collaborator: AbstractProductA)->str:
        pass


class AbstractFactory(ABC):
    
    @abstractmethod
    def create_product_a(self)->AbstractProductA:
        pass
    
    def create_product_b(self)->AbstractProductB:
        pass


class ConcreteProductA1(AbstractProductA):
    
    def useful_method_a(self)->str:
        return "Product A1"

class ConcreteProductA2(AbstractProductA):
    
    def useful_method_a(self)->str:
        return "Product A2"


class ConcreteProductB1(AbstractProductB):

    def useful_method_b(self)->str:
        return "Product B1"

    def another_useful_method_b(self, collaborator: AbstractProductA)->str:
        result = collaborator.useful_method_a()
        return f"B1 collaborating with {result}"


class ConcreteProductB2(AbstractProductB):

    def useful_method_b(self)->str:
        return "Product B2"

    def another_useful_method_b(self, collaborator: AbstractProductA)->str:
        result = collaborator.useful_method_a()
        return f"B2 collaborating with {result}"


class ConcreteFactory1(AbstractFactory):
    
    def create_product_a(self)->AbstractProductA:
        return ConcreteProductA1()

    def create_product_b(self)->AbstractProductA:
        return ConcreteProductB1()


class ConcreteFactory2(AbstractFactory):
    def create_product_a(self)->AbstractProductA:
        return ConcreteProductA2()

    def create_product_b(self)->AbstractProductA:
        return ConcreteProductB2()


def client_code(factory: AbstractFactory)->None:
    
    product_a = factory.create_product_a()
    product_b = factory.create_product_b()

    print(product_b.another_useful_method_b(product_a))


if __name__ == "__main__":
    client_code(ConcreteFactory1())
    client_code(ConcreteFactory2())