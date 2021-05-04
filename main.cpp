#include <iostream>
#include <list>

class Json{
public:
    std::string type;
    int height;
    int length;
    int width;

    void display(){
        std::cout<< "type: "<< type<< ", height: "<<height<<", length: "<<length <<", width: "<<width <<std::endl;
    }
};

class Chair{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual std::string getType() const=0;
    virtual ~Chair(){};

};

class VictorianChair: public Chair{
public:
    int getHeight() const {return 10;}
    int getLength() const {return 24;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }

};

class ModernChair: public Chair{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 33;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Modern";
    }

};

class ArtDecoChair: public Chair{
public:
    int getHeight() const {return 11;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArtDeco";
    }

};

class Sofa{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual ~Sofa(){};
    virtual std::string getType() const = 0;
};

class VictorianSofa: public Sofa{
public:
    int getHeight() const {return 10;}
    int getLength() const {return 29;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }
};

class ModernSofa: public Sofa{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 30;}
    int getWidth() const {return 27;}
    std::string getType() const override{
        return "Modern";
    }
};

class ArtDecoSofa: public Sofa{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArtDeco";
    }

};

class CoffeeTable{
public:
    virtual int getHeight() const=0;
    virtual int getLength() const=0;
    virtual int getWidth() const=0;
    virtual ~CoffeeTable(){};
    virtual std::string getType() const = 0;
};

class VictorianCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 11;}
    int getLength() const {return 20;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Victorian";
    }

};

class ModernCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 15;}
    int getLength() const {return 36;}
    int getWidth() const {return 25;}
    std::string getType() const override{
        return "Modern";
    }

};

class ArtDecoCoffeeTable: public CoffeeTable{
public:
    int getHeight() const {return 40;}
    int getLength() const {return 26;}
    int getWidth() const {return 39;}
    std::string getType() const override{
        return "ArteDeco";
    }

};

class Factory{
public:
    virtual Chair *CreateChair() const =0;
    virtual Sofa *CreateSofa() const =0;
    virtual CoffeeTable *CreateCoffeeTable() const =0;

};

class VictorianFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new VictorianChair();
    }
    Sofa *CreateSofa() const override{
        return new VictorianSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new VictorianCoffeeTable();
    }

};

class ModernFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new ModernChair();
    }
    Sofa *CreateSofa() const override{
        return new ModernSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new ModernCoffeeTable();
    }

};

class ArtDecoFabric: public Factory{
public:
    Chair *CreateChair() const override{
        return new ArtDecoChair();
    }
    Sofa *CreateSofa() const override{
        return new ArtDecoSofa();
    }
    CoffeeTable *CreateCoffeeTable() const override{
        return new ArtDecoCoffeeTable();
    }

};

void clientCode(const Factory &factory){

    Json dictioneryChair;
    const Chair *chair = factory.CreateChair();
    dictioneryChair.type = chair->getType();
    dictioneryChair.width = chair->getWidth();
    dictioneryChair.height = chair->getHeight();
    dictioneryChair.length = chair->getLength();
    dictioneryChair.display();
    delete chair;

    Json dictionerySofa;
    const Sofa *sofa = factory.CreateSofa();
    dictionerySofa.type = sofa->getType();
    dictionerySofa.width = sofa->getWidth();
    dictionerySofa.height = sofa->getHeight();
    dictionerySofa.length = sofa->getLength();
    dictionerySofa.display();
    delete sofa;

    Json dictioneryCoffeeTable;
    const CoffeeTable *coffeeTable = factory.CreateCoffeeTable();
    dictioneryCoffeeTable.type = coffeeTable->getType();
    dictioneryCoffeeTable.width = coffeeTable->getWidth();
    dictioneryCoffeeTable.height = coffeeTable->getHeight();
    dictioneryCoffeeTable.length = coffeeTable->getLength();
    dictioneryCoffeeTable.display();
    delete coffeeTable;

}


int main() {

    std::cout<< "TEST" <<std::endl;
    VictorianFabric *Vf = new VictorianFabric();
    clientCode(*Vf);
    delete Vf;

    return 0;
}
/*
 * UWAGI:
 * Ze wzgledu na fakt, że program został napisany w języku C++ napotkałam problem z implementacją biblioteki JSON.
 * Niestety po wielu próbach nie udało mi się w dobry sposób podpiąć biblioteki jsona pod CMake'a, dlatego też zastosowałam
 * swoją własną klasę Json, która prowizorycznie ma za zadanie przechowywać wartości, tak jakby to robiła biblioteka Json.
 *
 */