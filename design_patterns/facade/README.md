### Façade
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/pOL8R6GMXdY/1.jpg)](http://www.youtube.com/watch?v=pOL8R6GMXdY)
- O Façade (ou Fachada) oculta as complexidades do sistema interno e oferece uma interface ao cliente para que este possa acessar o sistema de forma bem simplificada. O padrão de projeto Façade faz essencialmente o seguinte:
  - Oferece uma interface unificada para um conjunto de interfaces em um subsistema e define uma interface de alto nível que ajuda o cliente a usar o subsistema de forma fácil.
  - O Façade procura fazer a representação de um subsistema complexo com um único objeto de interface. Ela não encapsula o subsistema, mas, na verdade, combina os subsistemas subjacentes.
  - Promove o desacoplamento da implementação com vários clientes.

- O princípio de design empregado por trás do padrão Façade é o princípio do conhecimento mínimo, o que nos orienta no sentido de reduzir as interações entre os objetos a apenas alguns amigos que sejam próximos a você. Em termos reais, isso significa o seguinte:
  - Quando fizermos o design de um sistema, para todo objeto criado, devemos observar o número de classes com que essa classe interage e o modo como a interação ocorre.
  - Seguindo o princípio, certifique-se de evitar situações em que haja muitas classes criadas que estejam altamente acopladas umas às outras.
  - Se houver muitas dependências entre as classes, o sistema será difícil de manter. Qualquer mudança em uma parte do sistema poderá resultar em alterações não intencionais em outras partes, o que significa que o sistema estará exposto a regressões, e isso deve ser evitado.

#### Cenário 1
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/PMGOpbSPKV8/1.jpg)](http://www.youtube.com/watch?v=PMGOpbSPKV8)
- [Code](code.py)

### [Back](../../README.md#design-patterns)