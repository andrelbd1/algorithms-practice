### Template Method
O padrão Template Method é um padrão de projeto comportamental que define o esqueleto do programa ou um algoritmo em um método chamado Método Template. Os principais objetivos do padrão Template Method são: 
- definir o esqueleto de um algoritmo com operações primitivas; 
- redefinir determinadas operações na subclasse sem alterar a estrutura do algoritmo; 
- reutilizar código e evitar esforços duplicados;
- tirar proveito de interfaces ou implementações comuns.

O padrão Template Method trabalha com os seguintes termos: AbstractClass, ConcreteClass, Método Template e Client.
- `AbstractClass`: declara uma interface para definir os passos do algoritmo.
- `ConcreteClass`: define passos específicos da subclasse. 
- `template_method()`: define o algoritmo chamando os métodos dos passos.

O exemplo de código a seguir serve para compreender o padrão com todos os participantes envolvidos:

- [Code](code.py)

Suponha o caso de uma agência de viagens, Dev Travels. Essas agência define várias viagens para diversos locais e apresenta um pacote de feriado para você. Um pacote é essencialmente uma viagem que você, como cliente, faz. Uma viagem tem detalhes como os lugares a ser visitados, o transporte a ser usado e outros fatores que definem o itinerário. Essa mesma viagem pode ser personalizada de modo diferente de acordo com as necessidades dos clientes.

A viagem deve conter vários métodos abstratos que definem o transporte usado, os lugares visitados em day1, day2 e day3, supondo que seja uma viagem de três dias em um fim de semana prolongado, além de definir a viagem de volta. O Método Template `itinerary()` define realmente o itinerário da viagem. Devemos definir ConcreteClasses, que nos ajudarão a personalizar as viagens de acordo com as necessidades do cliente. 

O objeto abstrato é representado pela classe `Trip`. É uma interface (classe-base abstrata de Python) que define detalhes como o transporte usado e os lugares a ser visitados em dias diferentes. `setTransport` é um método abstrato que deve ser implementado por ConcreteClass para definir o meio de transporte. Os métodos abstratos `day1()`, `day2()` e `day3()` definem os lugares a ser visitados no dia especificado. O Método Template `itinerary()` cria o itinerário completo (o algoritmo – nesse caso, a viagem). A sequência da viagem consiste em definir primeiro o meio de transporte e depois os lugares a ser visitados a cada dia e o `returnHome`. As classes que representam a classe concreta são `VeniceTrip` e `MaldivesTrip`, que implementam a interface Trip. A classe `TravelAgency` representa o objeto client nesse exemplo.

- [Code](real.py)

### [Back](../../README.md#design-patterns)