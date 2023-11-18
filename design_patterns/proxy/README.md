### Proxy
Em termos gerais, o Proxy é um sistema que serve de intermediário entre o solicitante (seeker) e o provedor (provider). O solicitante é quem faz a requisição, e o provedor entrega os recursos em resposta à requisição. 

O padrão de projeto Proxy faz essencialmente o seguinte:
- fornece um substituto para outro objeto para que você possa controlar o acesso ao objeto original;
- é usado como uma camada ou interface que oferece suporte a acesso distribuído;
- acrescenta delegação e protege o componente real de consequências indesejadas.

Há três participantes principais nesse padrão: 
- Proxy: mantém uma referência que lhe permite acessar o objeto real; oferece uma interface idêntica a Subject para que o Proxy possa substituir o objeto real. Os Proxies também são responsáveis por criar e apagar o RealSubject.
- Subject: oferece uma representação tanto para RealSubject quanto para Proxy. Como Proxy e RealSubject implementam Subject, Proxy pode ser usado em qualquer lugar que RealSubject seja esperado.
- RealSubject: define o objeto real representado pelo Proxy.

O código a seguir representa uma situação onde voê foi ao shopping center e gostaria de comprar uma camisa.
- O seu comportamento é representado pela classe You – o cliente.
- Para comprar a camisa, o método make_payment() é fornecido pela classe.
- O método especial \_\_init\_\_() chama o Proxy e o instancia.
- O método make_payment() chama o método do Proxy internamente para fazer o pagamento.
- O método \_\_del\_\_() retorna caso o pagamento seja bem-sucedido.
- A classe Subject é uma interface implementada pelo Proxy e por RealSubject. Essa classe é Payment. É uma classe-base abstrata e representa uma interface. Payment contém o método `do_pay()` que deve ser implementado por Proxy e por RealSubject.
- A classe Bank representa a RealSubject que fará realmente o pagamento, passando o valor de sua conta para a conta do comerciante.
- A classe DebitCard é o Proxy, nesse caso. Quando você (You) quiser fazer um pagamento, o método `do_pay()` deve ser chamado. Isso é porque você (You) não quer ir até o banco para sacar o dinheiro e pagar o comerciante.


[Code](code.py)