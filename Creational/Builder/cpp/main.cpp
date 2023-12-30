#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Builder{

    public:
    virtual ~Builder(){}
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;

};

class Product1{

    public:
        vector<string> parts_;
        void ListParts() const{
            cout << "Listing parts:\n";
            for(size_t i = 0; i<parts_.size(); i++){
                if(parts_[i]==parts_.back()){
                    cout << parts_[i];
                }else{
                    cout << parts_[i] << ", ";
                }
            }
            cout << "\n\n";
        };

};

class ConcreteBuilder1 : public Builder{

    private:
        Product1* product;

    public:

        ConcreteBuilder1(){
            this->Reset();
        }

        ~ConcreteBuilder1(){
            delete product;
        }

        void Reset(){
            this->product = new Product1();
        }

        void ProducePartA() const override{
            this->product->parts_.push_back("PartA1");
        }

        void ProducePartB() const override{
            this->product->parts_.push_back("PartB1");
        }

        void ProducePartC() const override{
            this->product->parts_.push_back("PartC1");
        }

        Product1* GetProduct(){
            Product1* result = this->product;
            this->Reset();
            return result;
        }

};

class Director{

    private:
        Builder* builder;

    public:

        void set_builder(Builder* builder){
            this->builder = builder;
        };

        void BuildMVP(){
            this->builder->ProducePartA();
        };

        void BuildFullFeaturedProduct(){
            this->builder->ProducePartA();
            this->builder->ProducePartB();
            this->builder->ProducePartC();
        };

};


void ClientCode(Director& director){

    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    director.BuildMVP();
    director.BuildFullFeaturedProduct();
    builder->GetProduct()->ListParts();


}

int main()
{
    Director* director = new Director();
    ClientCode(*director);
    delete director;
}