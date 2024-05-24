### Command
O padrão Command é um padrão de projeto comportamental, em que um objeto é usado para encapsular todas as informações necessárias para executar uma ação ou disparar um evento posteriormente. Essas informações incluem: 
- o nome do método;
- um objeto que seja dono do método;
- valores para os parâmetros do método.

O Command trabalha com os seguintes termos: Command, Receiver, Invoker e Client. Um objeto Command conhece os objetos Receiver e invoca um método desse objeto. Os valores dos parâmetros do método receptor (receiver) são armazenados no objeto Command. O chamador ou invocador (invoker) sabe como executar um comando. O cliente cria um objeto Command e define o seu receptor.  

Os principais objetivos do padrão Command são: 
- encapsular uma requisição como um objeto;
- possibilitar a parametrização dos clientes com diferentes requisições;
- permitir salvar as requisições em uma fila (discutiremos isso mais adiante neste capítulo);
- oferecer uma callback orientada a objetos. 

O fluxo é simples. O cliente pede que um comando seja executado. O chamador (invoker) toma o comando, o encapsula e o insere em uma fila. A classe `ConcreteCommand` é responsável pelo comando solicitado e pede que o receptor execute a ação especificada. O exemplo de código a seguir serve para compreender o padrão e apresenta todos os participantes envolvidos:

- [Code](code.py)

Suponha que queiramos desenvolver um assistente para instalação ou, popularmente, um instalador. Em geral, uma instalação implica copiar ou mover arquivos no sistema de arquivos de acordo com as escolhas feitas por um usuário. No exemplo a seguir, no código do cliente, começamos criando o objeto Wizard e usamos o método `preferences()`, que armazena as escolhas feitas pelo usuário nas várias telas do assistente. No assistente, quando o botão Finish (Fim) for clicado, o método `execute()` será chamado. Esse método toma as preferências e inicia a instalação.

- [Code](wizard.py)

Tomaremos um exemplo com a Bolsa de Valores. Você, como usuário da Bolsa, cria pedidos para comprar ou vender ações. Geralmente, você não as compra nem vende. É o agente ou o corretor que desempenha o papel de intermediário entre você e a Bolsa de Valores. O agente é responsável por levar sua requisição à Bolsa de Valores e fazer o trabalho. Suponha que você queira vender uma ação na segunda-feira de manhã, quando a Bolsa abre. Você ainda pode fazer a solicitação de vender as ações no domingo à noite ao seu agente, mesmo que a Bolsa não esteja aberta ainda. O agente então coloca essa requisição na fila para que seja executada na segunda-feira de manhã, quando a Bolsa estiver aberta para negociações. Este é um caso clássico para o padrão Command.

Devemos definir classes `ConcreteCommand` para comprar ou vender uma ação. Uma classe também deve ser definida para a Bolsa de Valores. Devemos definir a classe Receiver, que realmente executará a negociação, e o agente (conhecido como chamador), que invoca o pedido e faz com que ele seja executado pelo receptor. Começaremos pelo objeto Command, que é `Order`. O objeto `Command` é representado pela classe `Order`, que oferece uma interface (classe-base abstrata de Python) para que `ConcreteCommand` possa implementar o comportamento. O método `execute()` é o método abstrato que deve ser definido pelas classes `ConcreteCommand` para executar a classe `Order`.

Também desenvolvemos duas classes concretas principais: `BuyStockOrder` e `SellStockOrder`, que implementam a interface `Order`. As duas classes ConcreteCommand utilizam o objeto do sistema de negociação de ações para que possam definir as ações apropriadas para o sistema. O método `execute()` de cada uma dessas classes ConcreteCommand utiliza o objeto da Bolsa de Valores para executar as ações de comprar e vender.

A classe `StockTrade` representa o objeto Receiver nesse exemplo. Ela define vários métodos (ações) para executar as requisições apresentadas pelos objetos ConcreteCommand. Os métodos `buy()` e `sell()` são definidos pelo receptor e são chamados por BuyStockOrder e SellStockOrder respectivamente para comprar ou vender a ação na Bolsa.

A classe `Agent` representa o chamador. O agente é o intermediário entre o cliente e StockExchange, e executa os pedidos apresentados pelo cliente. • O agente define um membro de dado, __orderQueue (uma lista), que atua como uma fila. Qualquer nova requisição feita pelo cliente é adicionada na fila. O método `placeOrder()` de Agent é responsável por colocar as requisições na fila e executá-las.

- [Code](real.py)

### [Back](../../README.md#design-patterns)