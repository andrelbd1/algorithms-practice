### Singleton
- Garantir que um e somente um objeto da classe seja criado;
- Oferecer um ponto de acesso para um objeto que seja global no programa;
- Controlar o acesso concorrente a recursos compartilhados.

#### Classic Singleton
- No Classic Singleton, sobrescrevemos o método __new__ (método especial de Python para instanciar objetos) para controlar a criação do objeto. O objeto s é criado com o método __new__, mas antes disso é feita uma verificação para saber se o objeto já existe. O método hasattr (método especial de Python para saber se um objeto tem determinada propriedade) é usado para verificar se o objeto cls tem a propriedade instance, que confere se a classe já tem um objeto. No momento em que o objeto s1 é solicitado, hasattr() detecta que um objeto já existe e, então, s1 aloca a instância do objeto existente.
- [Code](classic.py)

#### Lazy Singleton
- No LazySingleton, quando fazemos s=Singleton(), o método __init__ é chamado, mas nenhum objeto novo é criado. Entretanto a criação propriamente dita do objeto ocorre quando chamamos Singleton.getInstance().
- [Code](lazy.py)

#### Monostate Singleton
- O conceito de Monostate é que a instancia deve ter o mesmo estado e comportamento, e não a mesma identidade.
- No código atribuímos a variável de classe \_\_shared_state à variável \_\_dict\_\_ (uma variável especial em Python). Python usa \_\_dict\_\_ para armazenar o estado de todos os objetos de uma classe. No código a seguir, atribuímos __shared_state propositalmente a todas as instâncias criadas. Então, se criarmos duas instâncias 'b' e 'b1', teremos dois objetos distintos, de modo diferente do Singleton, em que temos apenas um objeto. Entretanto os estados dos objetos, b.\_\_dict\_\_ e b1.\_\_dict\_\_, são iguais. Mesmo que a variável x do objeto mude para o objeto b, a mudança será copiada para a variável \_\_dict\_\_ compartilhada entre todos os objetos, e até mesmo b1 obterá a mudança de x de um para quatro.
- [Code](monostate.py)

#### Cenário 1
