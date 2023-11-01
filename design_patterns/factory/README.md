### Factory
Em programação orientada a objetos, o termo fábrica (factory) refere-se a uma classe responsável por criar objetos de outros tipos. Geralmente, a classe que atua como uma fábrica tem um objeto e métodos associados a ela. O cliente chama esse método com determinados parâmetros, e os objetos dos tipos desejados são criados e devolvidos ao cliente pela fábrica. Suas vantagens são:
- A criação de um objeto pode ser independente da implementação da classe.
- O cliente não precisa conhecer a classe que cria o objeto, que, por sua vez, é utilizado pelo cliente. É necessário conhecer apenas a interface, os métodos e os parâmetros que devem ser passados para criar os objetos do tipo desejado. Isso simplifica as implementações para o cliente.
- Adicionar outra classe à fábrica para criar objetos de outro tipo pode ser facilmente implementado sem que o cliente altere o código. No mínimo, o cliente precisará passar apenas mais um parâmetro.
- A fábrica também pode reutilizar objetos existentes. Por outro lado, se o cliente criar objetos diretamente, um novo objeto sempre será criado.



#### Padrão Simple Factory
- Permite que as interfaces criem objetos sem expor a lógica de sua criação.
- No trecho de código a seguir, criamos um produto Abstract chamado Animal. Animal é uma classe-base abstrata (ABCMeta é a metaclasse especial de Python para criar uma classe `Abstract`) e tem o método `do_say()`.
- Criamos dois produtos (Cat e Dog) a partir da interface Animal e implementamos `do_say()` com os sons apropriados produzidos por esses animais. ForestFactory é uma fábrica que tem o método `make_sound()`. De acordo com o tipo de argumento passado pelo cliente, uma instância apropriada de Animal será criada em tempo de execução.
- [Code](simple_factory.py)


#### Padrão Factory Method
- Permite que as interfaces criem objetos, mas adia a decisão para que as subclasses determinem a classe para a criação do objeto.

#### Padrão Abstract Factory
- Uma Abstract Factory é uma interface para criar objetos relacionados sem especificar/expor suas classes; o padrão fornece objetos de outra fábrica que, internamente, cria outros objetos.

