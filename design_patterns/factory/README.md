### Factory
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/42QT-s78vkU/1.jpg)](http://www.youtube.com/watch?v=42QT-s78vkU)
- Em programação orientada a objetos, o termo fábrica (factory) refere-se a uma classe responsável por criar objetos de outros tipos. Geralmente, a classe que atua como uma fábrica tem um objeto e métodos associados a ela. O cliente chama esse método com determinados parâmetros, e os objetos dos tipos desejados são criados e devolvidos ao cliente pela fábrica. Suas vantagens são:
  - A criação de um objeto pode ser independente da implementação da classe.
  - O cliente não precisa conhecer a classe que cria o objeto, que, por sua vez, é utilizado pelo cliente. É necessário conhecer apenas a interface, os métodos e os parâmetros que devem ser passados para criar os objetos do tipo desejado. Isso simplifica as implementações para o cliente.
  - Adicionar outra classe à fábrica para criar objetos de outro tipo pode ser facilmente implementado sem que o cliente altere o código. No mínimo, o cliente precisará passar apenas mais um parâmetro.
  - A fábrica também pode reutilizar objetos existentes. Por outro lado, se o cliente criar objetos diretamente, um novo objeto sempre será criado.


#### Padrão Simple Factory
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/lCzHv4RhvwQ/1.jpg)](http://www.youtube.com/watch?v=lCzHv4RhvwQ)
- Permite que as interfaces criem objetos sem expor a lógica de sua criação.
- No código a seguir, criamos um produto Abstract chamado Animal. Animal é uma classe-base abstrata (ABCMeta é a metaclasse especial de Python para criar uma classe `Abstract`) e tem o método `do_say()`.
- Criamos dois produtos (Cat e Dog) a partir da interface Animal e implementamos `do_say()` com os sons apropriados produzidos por esses animais. ForestFactory é uma fábrica que tem o método `make_sound()`. De acordo com o tipo de argumento passado pelo cliente, uma instância apropriada de Animal será criada em tempo de execução.
- [Code](simple_factory.py)


#### Padrão Factory Method
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/JBRm_tCCJsM/1.jpg)](http://www.youtube.com/watch?v=JBRm_tCCJsM)
- Permite que as interfaces criem objetos, mas adia a decisão para que as subclasses determinem a classe para a criação do objeto.
- Definimos uma interface para criar objetos, mas, em vez de a fábrica ser responsável pela criação dos objetos, a responsabilidade é passada para a subclasse, que decidirá a classe a ser instanciada.
- A criação do Factory Method não é feita por instanciação, mas por herança.
- O Factory Method deixa o design mais personalizável. Ele pode devolver a mesma instância ou subclasse no lugar de um objeto de determinado tipo (como no método de Simple Factory).
- No código a seguir, imagine que gostaríamos de criar perfis de tipos diferentes em redes sociais como LinkedIn e Facebook para uma pessoa ou uma empresa. Cada um desses perfis deve ter determinadas seções. No LinkedIn, você teria uma seção de patentes que um indivíduo requisitou ou publicações que ele(a) escreveu. No Facebook, você verá seções para um álbum de fotos de uma viagem recente que você fez em um feriado. Além do mais, nesses dois perfis, haveria uma seção comum de informações pessoais. Portanto, resumindo, queremos criar perfis de tipos diferentes com as seções corretas adicionadas ao perfil.
- [Code](factory_method.py)


#### Padrão Abstract Factory
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/j5853xJM55w/1.jpg)](http://www.youtube.com/watch?v=j5853xJM55w)
- Uma Abstract Factory é uma interface para criar objetos relacionados sem especificar/expor suas classes; o padrão fornece objetos de outra fábrica que, internamente, cria outros objetos.
- Enquanto o Factory Method adia a criação da instância para as subclasses, o objetivo do método Abstract Factory é criar famílias de objetos relacionados. Com efeito, os padrões Abstract Factory garantem que o cliente esteja isolado da criação dos objetos, mas permite que ele utilize os objetos criados. O cliente tem a capacidade de acessar os objetos somente por meio de uma interface. Se os produtos de uma família tiverem de ser usados, o padrão Abstract Factory ajudará o cliente a utilizar os objetos de uma família de cada vez.
- No código a seguir, suponha que criamos uma pizzaria em que são servidas pizzas indianas e americanas deliciosas. Para isso, inicialmente criamos uma classe-base abstrata `PizzaFactory`. A classe `PizzaFactory` tem dois métodos abstratos, `createVegPizza()` e `createNonVegPizza()`, que devem ser implementados por ConcreteFactory. Nesse exemplo, criamos duas fábricas concretas, que são `IndianPizzaFactory` e `USPizzaFactory`.
- [Code](abstract_factory.py)

### [Back](../../README.md#design-patterns)