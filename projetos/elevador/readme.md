# Projeto de um circuito de controle para elevadores
# Elevator control circuit project

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| André Guilherme da Luz  | 231343  | Eng. Elétrica|
| Gabriel Vianna Serra  | 258555  | Eng. Elétrica|


## Descrição do Projeto
A ideia do projeto consiste em desenvolver um circuito controlador para elevadores, a fim de tomar decisões como a escolha de qual elevador deve subir, descer ou manter-se no lugar com base no andar atual, prioridade de chamada, distância do andar solicitado e situações de segurança, por exemplo. Nosso contexto de concepção desse projeto veio do motivo de que é algo muito útil e presente no dia a dia de pessoas, bem como factível de ser projetado durante o semestre da disciplina, permitindo nos desafiar com as possíveis variáveis de desenvolvimento sem sobrecarregar os esforços dentro do tempo estipulado.

Outro lado positivo do projeto é que seu custo não tende a ser alto, levando em conta que a lógica pode ser desenvolvida sem a necessidade de processamento muito avançado, e os demais dispositivos que podem ser possivelmente usados não tendem a ser caros (alguns sensores e circuitos básicos para mudança de direção do motor). Dessa forma, levando em conta um investimento que requer pouca manutenção (o principal serviço é o software envolvido no controle dos elevadores e o microprocessador do mesmo, que tende a ter boa durabilidade), pouco capital e que proporciona um controle útil e necessário na logística dos elevadores, temos um projeto viável e de custo acessível.

O projeto consiste em um produto já estabelecido no mercado, que visa garantir um transporte vertical eficiente, seguro e confiável, ao mesmo tempo em que buscamos a redução dos custos. O sistema tende a beneficiar tanto prédios residenciais, ocorrendo uma valorização do imóvel, quanto comerciais, ocorrendo uma melhora da produtividade dos funcionários.

## Descrição Funcional

### Funcionalidades
O sistema de controle de elevadores deverá ser capaz de executar as seguintes tarefas:
  - Chamadas do elevador: receber e registrar chamadas de todos os andares do prédio.
  - Registrar as solicitações dentro do elevador.
  - Organizar as chamadas com base na localização, direção e disponibilidade.
  - Gerenciar a abertura e fechamento das portas.
  - Controle de sobrecarga: impedir o movimento do elevador se estiver sobrecarregado.
  - Responder imediatamente a situações de emergência.
  - Diagnosticar problemas mecânicos e elétricos.
  - Fornecer feedback aos passageiros sobre o andar que está.    

### Configurabilidade
O sistema possui os seguintes estados:
  - Subindo:
    O elevador está se deslocando para cima, pois recebeu uma chamada de algum andar mais elevado ou algum passageiro solicitou parada em um andar acima.
  - Descendo:
    O elevador está se deslocando para baixo, pois recebeu uma chamada de algum andar ou algum passageiro solicitou parada em um andar abaixo de sua posição.
  - Parado:
    O elevador está em um andar específico.
    - Portas abertas:
      O elevador está parado em um andar específico e com a porta aberta para entrada e saída de passageiros.
    - Portas fechadas:
      O elevador está fechada as portas após um tempo específico para entrada e saída dos passageiros e verificação de que não há passageiros se locomovendo pra dentro ou pra fora, bem como verificação de que não há possíveis falhas mecânicas e elétricas.

Ao receber chamadas de andares, o elevador (com portas fechadas) muda para o estado "subindo" ou "descendo", assim como quando o passageiro seleciona o andar desejado. Ao chegar no andar, o elevador muda para o modo "parado", inicialmente de portas fechadas, e rapidamente muda para o modo "portas abertas". Após um determinado tempo para entrarem e saírem passageiros, há a mudança de estado para "portas fechadas" novamente, se as condições de segurança forem satisfeitas. Assim, novas chamadas ocorrem, reiniciando. 
Há algumas mudanças de estado fora do funcionamento padrão. Ao verificar problemas mecânicos ou elétricos, sobrecarga ou outras emergências, ele passa automaticamente para o modo "parado". Se está parado devido a problemas de segurança, suas portas podem permanecer abertas ou fechadas de acordo com a ocasião.

### Eventos
Os eventos de mudança de estado:
  - Chamada de um andar (evento não-periódico, passa do estado "parado" para "subindo" ou "descendo").
  - Chegada do elevador a um andar solicitado (evento não-periódico, passa do estado "subindo" ou "descendo" para "parado").
  - Ao parar, abertura das portas (evento não-periódico, passa do estado "parado" para o sub estado "portas abertas").
  - Fechamento das portas após um tempo para entrada e saída de passageiros, bem como garantia de segurança (evento não-periódico, passa do sub estado "portas abertas" para "portas fechadas").
  - Pressionamento do botão de fechada de portas (evento não-periódico, passa do estado "portas abertas" para "portas fechadas").
  - Pessoa entre a porta (evento não-periódico, mantém-se no sub estado "portas abertas").
  - Detecção de sobrecarga (evento não-periódico, mantém-se no sub estado "portas abertas").
  - Detecção de falha (evento não-periódico, passa do estado  "subindo" ou "descendo" para "parado").

### Tratamento de Eventos
  - Chamada de um andar:
    Ao receber uma chamada, o sistema deve organizar as chamadas da melhor maneira, de forma que não fique subindo e descendo várias vezes.
  - Chegada do elevador a um andar solicitado:
    Ao chegar em um andar, o sistema deve alinhar corretamente o chão do elevador com o andar.
  - Ao parar, abertura das portas:
    Após o alinhamento correto do chão do elevador e do andar, o sistema deve mandar um sinal para abertura da porta correta.
  - Fechamento das portas após um tempo para entrada e saída de passageiros:
    Após um tempo previamente definido de abertura das portas, o sistema deve enviar um sinal para o fechamento das portas se as condições de segurança forem satisfeitas.
  - Pressionamento do botão de fechada de portas:
    Caso esteja pressionado o botão, o sistema deve enviar um sinal para fechamento da porta.
  - Pessoa entre a porta:
    O sistema, ao detectar que há algo no local de fechamento da porta, deve enviar o sinal para manter a porta aberta ou cancelar o fechamento.
  - Detecção de sobrecarga:
    Ao detectar sobre carga, o sistema deve manter-se parado.
  - Detecção de falha:
    Ao detectar falha, o sistema deve interromper o movimento e ficar parado.

## Descrição Estrutural do Sistema
O sistema se baseia em um fluxo de estados onde definimos se um elevador sobe, desce ou se mantém parado com base nas solicitações internas e externas do elevador, bem como nas condições de segurança que devem ser satisfeitas. O diagrama abaixo retrata melhor os o fluxo de decisões:

![Diagrama Elevador](https://github.com/gaserra/ea075-2024.1/assets/106714171/aa069ecc-fe73-4d3b-894f-7fdff017ff25)

Note que o mesmo funciona tanto para uma pessoa que solicita o elevador pelo lado de fora, quanto para alguém que aperta o botão de um andar já dentro do elevador. O diagrama mostra a situação em condições típicas e síncronas de funcionamento, mas haverá também a necessidade de uma verificação assíncrona em casos de falhas durante o trajeto do elevador, onde o mesmo deve parar e acionar suporte/segurança.
A fila também necessita ser desenvolvida, para saber se o elevador sobe ou desce de acordo com a ordem apertada, mas também pode levar a conta a distância, caso o prédio tenha muitos andares e haja necessidade de definir prioridades. De qualquer forma, de forma resumida, após alguma solicitação que entra em uma fila com uma determinada prioridade, a ideia é que o elevador se movimente baseado nessa fila para atender aos chamados.

## Especificações (⚠️ NOVO ⚠️)

### Especificação Estrutural

O projeto possuirá dois atuadores, sendo ambos motores CC, para controle de abertura e fechamento das portas do elevador e para subir e descer a cabine. O motor utilizado para o deslocamento vertical da cabine necessita possuir bastante torque, portanto a potência dele será maior. Com isso, a alimentação precisará ser feita utilizando um retificador controlado com tiristores. Para controle do sentido e velocidade do motor será utilizado na saída do retificador uma ponte H utilizando transistores MOSFET. Já o motor CC da porta, pode ser utilizada uma fonte de menor potência, e seu controle é feito por uma ponte H.

Para o controle da parada correta da cabine do elevador, serão usados sensores magnéticos, ainda não definido o modelo exato para o projeto, em cada andar. Assim, ao passar pelo sensor, o sistema saberá o andar que está e o momento correto para iniciar a frenagem. Esse sensor será importante para a cabine estacionar exatamente no local, alinhando o piso do elevador com o andar.

A porta possuirá quatro sensores de infra vermelho, sendo utilizados dois em cada nível, um em cada lado da porta, que dectará caso haja algum objeto entre as portas. O sensor utilizado será E18-D80NK-N, que possui um alcance de 6 a 80 cm. Quando um objeto for dectado, o sensor envia ao microcontrolador um sinal de nível lógico baixo. Com a leitura do nível lógico, o microcontrolador envia comando para o motor da porta mantê-la aberta.

O elevador irá se locomover por quatro andares, portanto teremos quatro push buttons dentro do elevador, para o passageiro indicar o andar desejado. Cada andar possuíra um push button para chamar o elevador. Portanto, teremos oito push buttons no sistema, que ao serem pressionados entram em uma memória em estrutura de pilha, para o microcontrolador definir os andares para parar. Na seção de especificação de algorítmo, o modo de funcionamento dos chamados é explicado.

O microcontrolador utilizado ainda não foi definido. A ideia é utilizar comunicação I2C no sistema.

> (Se preferir, adicione um link para o documento de especificação estrutural)
> 
> Entende-se por estrutural a descrição tanto das características elétricas e temporais como das restrições físicas de cada bloco funcional.
> Nessa etapa do projeto, ainda não será solicitado o diagrama elétrico mas espera-se que já estejam identificados os componentes e circuitos integrados propostos
> para implementação do sistema embarcado proposto.
> 
> Como o projeto de um sistema embarcado é centralizado nas tarefas, recomenda-se iniciar com a definição dos periféricos de entrada e saída (atuadores e/ou sensores) apropriados para o
> sistema. Pode ser necessário definir um endereço distinto para cada um deles. 
> Este endereço será utilizado pela unidade micro-controladora para acessá-los tanto para leitura como para escrita.

> Nesta etapa do projeto espera-se que a unidade micro-controladora seja definida.
> Tendo definidos os periféricos e a memória, é possível projetar um decodificador de endereços
> que converte o endereço referenciado no programa em sinal *Chip Select – CS* do dispositivo
> correspondente, habilitando-o para realizar um ciclo de leitura ou de escrita.
> 
> Nesta etapa do projeto espera-se que sejam identificada também a eventual necessidade do projeto de circuitos de interface para os periféricos do projeto.
> Assim, devem ser incluídos na especificação, se necessário:
> - conversores AD e DA;
> - padrões de comunicação a serem adotados;
> - circuitos de sincronização de sinais temporais.
> 
> Finalmente, deve-se especificar as restrições físicas e ambientais de funcionamento do circuito, tais como limites mecânicos
> (altura, largura, profundidade) e limites de dissipação térmica.

### Especificação de Algoritmos 
Para a gestão de fila dos andares, o projeto se baseia no seguinte fluxograma:
![Fila Elevador](https://github.com/andreglz/ea075-2024.2/assets/106714171/826400fe-9c3d-46b8-b4a3-8262b10adffc)

Os eventos relacionados à abertura e ao fechamento de portas, bem como detecção de falha, sobrecarga e pessoa entre as portas são tratados no fluxograma da seção "_Descrição Estrutural do Sistema_", e tais eventos se relacionam diretamente com este acima no que resumimos pela tomada de decisão "Verificações de segurança ok?". Dessa forma, o algoritmo como um todo deve tratar dos dois fluxogramas, sendo que o primeiro diagrama se encaixa dentro do segundo para simplificarmos a visualização.

Com isso podemos estimar que seria necessário **...............................**


> (Se preferir, adicione um link para o documento de especificação de algoritmos).
> 
> Deve ser elaborado para CADA evento o algoritmo de tratamento deste evento. Com base no
> tamanho de cada algoritmo, estima-se o tamanho de memória necessária para armazenar todos
> os programas e os dados associados. Isso permitirá especificar a memória a ser utilizada e o
> espaço onde serão armazenados os programas. O algoritmo de tratamento de evento pode
> ser representado graficamente por um fluxograma. Recomenda-se usar símbolos gráficos consistentes 
> com a norma internacional ISO 1028-1973 e IS0 2972-1979.

## Referências
http://www.electrical-knowhow.com/2012/04/elevator-control-system.html

http://fpgaparatodos.com.br/2011/08/04/exemplo-de-exemplo/
