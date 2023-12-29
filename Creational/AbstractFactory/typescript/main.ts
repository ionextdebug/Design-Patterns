interface AbstractProductA{
    usefulMethodA(): string;
}

interface AbstractProductB{
    usefulMethodB(): string;
    anotherUsefulMethodB(collaborator: AbstractProductA): string;
}

interface AbstractFactory{
    createProductA(): AbstractProductA;
    createProductB(): AbstractProductB;
}

class ConcreteProductA1 implements AbstractProductA{

    public usefulMethodA(): string {
        return "Product A1";
    }

}

class ConcreteProductA2 implements AbstractProductA{

    public usefulMethodA(): string {
        return "Product A2";
    }

}

class ConcreteProductB1 implements AbstractProductB{

    public usefulMethodB(): string {
        return "Product B1";
    }

    public anotherUsefulMethodB(collaborator: AbstractProductA): string {
        const result = collaborator.usefulMethodA();
        return `Product B1 with ${result}`;
    }

}

class ConcreteProductB2 implements AbstractProductB{

    public usefulMethodB(): string {
        return "Product B2";
    }

    public anotherUsefulMethodB(collaborator: AbstractProductA): string {
        const result = collaborator.usefulMethodA();
        return `Product B2 with ${result}`;
    }

}

class ConcreteFactory1 implements AbstractFactory{

    public createProductA(): AbstractProductA {
        return new ConcreteProductA1();
    }

    public createProductB(): AbstractProductB {
        return new ConcreteProductB1();
    }

}

class ConcreteFactory2 implements AbstractFactory{

    public createProductA(): AbstractProductA {
        return new ConcreteProductA2();
    }

    public createProductB(): AbstractProductB {
        return new ConcreteProductB2();
    }

}

function clientCode(factory: AbstractFactory){

    const productA = factory.createProductA();
    const productB = factory.createProductB();

    console.log(productB.anotherUsefulMethodB(productA));

}

clientCode(new ConcreteFactory1())
clientCode(new ConcreteFactory2());