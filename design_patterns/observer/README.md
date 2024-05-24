### Observer
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/TBdLr83xVrs/1.jpg)](http://www.youtube.com/watch?v=TBdLr83xVrs)
- No padrão de projeto Observer, um objeto (Subject, ou Sujeito/Assunto/Observável) mantém uma lista de dependentes (Observers, ou Observadores) de modo que o Sujeito possa notificar todos os Observadores acerca das mudanças pelas quais ele passa usando qualquer um dos métodos definidos pelo Observador. Os principais objetivos do padrão Observer são estes:
  - Ele define uma dependência de um para muitos (one-to-many) entre os objetos, de modo que qualquer mudança em um objeto será notificada aos demais objetos dependentes automaticamente.
  - Encapsula o componente nuclear, isto é, o Sujeito.

- O padrão Observer possibilita um design de objetos em que o Subject e o Observer têm baixo acoplamento. Designs com baixo acoplamento nos permitem construir sistemas orientados a objetos flexíveis, capazes de lidar com mudanças, pois reduzem a dependência entre vários objetos. A arquitetura com baixo acoplamento garante as seguintes características:
  - reduz o risco de que uma mudança em um elemento possa gerar um impacto imprevisto em outros elementos;
  - simplifica os testes, a manutenção e a resolução de problemas;
  - o sistema pode ser facilmente separado em elementos definidos.

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/Nhd0oeNnSoM/1.jpg)](http://www.youtube.com/watch?v=Nhd0oeNnSoM)
- [Code](code.py)

#### Cenário 1
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/dOMPjgIpsuE/1.jpg)](http://www.youtube.com/watch?v=dOMPjgIpsuE)
- Vamos considerar o caso de uma agência de notícias a fim de demonstrar o cenário do mundo real para o padrão Observer. As agências de notícias geralmente reúnem notícias de vários locais e as publicam para que os assinantes tenham acesso a elas. Com informações enviadas/recebidas em tempo real, uma agência de notícias deve ser capaz de publicar as notícias aos seus assinantes assim que for possível.
  - O comportamento do Sujeito é representado pela classe `NewsPublisher`, que oferece uma interface com a qual os assinantes podem trabalhar.
  - O método `attach()` é usado pelo Observer para se registrar junto a NewsPublisher, e o método `detach()` ajuda na remoção da assinatura de Observer.
  - O método `subscriber()` devolve a lista de todos os assinantes que já se registraram junto a Subject.
  - O método `notifySubscriber()` itera por todos os assinantes que se registraram junto a NewsPublisher.
  - O método `addNews()` é usado pela agência de notícias para criar novas notícias, e `getNews()` é usado para devolver as notícias mais recentes; então o Observer é notificado.

- [Code](real.py)

### [Back](../../README.md#design-patterns)