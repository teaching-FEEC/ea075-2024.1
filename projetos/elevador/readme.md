# Projeto de um circuito de controle para elevadores
# Elevator control circuit project

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| André Guilherme da Luz  | 231343  | Eng. Elétrica|
| Gabriel Vianna Serra  | 258555  | Eng. Elétrica|

## Arquivos Importantes

Esquemático --  

Lista de Componentes -- https://github.com/gaserra/ea075-2024.1/blob/99e6916becb7f16d3520f543a689d3d09d11a9cd/projetos/elevador/componentes.md

PCB -- 

## Descrição do Projeto
A ideia do projeto consiste em desenvolver um circuito controlador para elevadores, a fim de tomar decisões como a escolha de que o elevador deve subir, descer ou manter-se no lugar com base no andar atual, prioridade de chamada e situações de segurança, por exemplo. Nosso contexto de concepção desse projeto veio do motivo de que é algo muito útil e presente no dia a dia de pessoas, bem como factível de ser projetado durante o semestre da disciplina, permitindo nos desafiar com as possíveis variáveis de desenvolvimento sem sobrecarregar os esforços dentro do tempo estipulado.

Outro lado positivo do projeto é que seu custo não tende a ser alto, levando em conta que a lógica pode ser desenvolvida sem a necessidade de processamento muito avançado, e os demais dispositivos que podem ser possivelmente usados não tendem a ser caros (alguns sensores e circuitos básicos para mudança de direção do motor). Dessa forma, levando em conta um investimento que requer pouca manutenção (o principal serviço é o software envolvido no controle dos elevadores e o microprocessador do mesmo, que tende a ter boa durabilidade), pouco capital e que proporciona um controle útil e necessário na logística dos elevadores, temos um projeto viável e de custo acessível.

O projeto consiste em um produto já estabelecido no mercado, que visa garantir um transporte vertical eficiente, seguro e confiável, ao mesmo tempo em que buscamos a redução dos custos. O sistema tende a beneficiar tanto prédios residenciais, ocorrendo uma valorização do imóvel, quanto comerciais, ocorrendo uma melhora da produtividade dos funcionários.

## Descrição Funcional

### Funcionalidades
O sistema de controle de elevadores deverá ser capaz de executar as seguintes tarefas:
  - Chamadas do elevador: receber e registrar chamadas de todos os andares do prédio.
  - Registrar as solicitações dentro do elevador.
  - Organizar as chamadas com base em uma fila de prioridade.
  - Gerenciar a abertura e fechamento das portas.
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
      O elevador está parado em um andar com as portas fechadas, que ocorre após um tempo específico para entrada e saída dos passageiros e verificação de que não há passageiros se locomovendo pra dentro ou pra fora, bem como verificação de que não há possíveis falhas mecânicas e elétricas.

Ao receber chamadas de andares, o elevador (com portas fechadas) muda para o estado "subindo" ou "descendo", assim como quando o passageiro seleciona o andar desejado. Ao chegar no andar, o elevador muda para o modo "parado", inicialmente de portas fechadas, e rapidamente muda para o modo "portas abertas". Após um determinado tempo para entrarem e saírem passageiros, há a mudança de estado para "portas fechadas" novamente, se as condições de segurança forem satisfeitas. Assim, novas chamadas ocorrem, reiniciando. 
Há algumas mudanças de estado fora do funcionamento padrão. Ao verificar problemas mecânicos ou elétricos ou outras emergências, ele passa automaticamente para o modo "parado". Se está parado devido a problemas de segurança, suas portas podem permanecer abertas ou fechadas de acordo com a ocasião.

### Eventos
Os eventos de mudança de estado:
  - Chamada de um andar (evento não-periódico, passa do estado "parado" para "subindo" ou "descendo").
  - Chegada do elevador a um andar solicitado (evento não-periódico, passa do estado "subindo" ou "descendo" para "parado").
  - Ao parar, abertura das portas (evento não-periódico, passa do estado "parado" para o sub estado "portas abertas").
  - Fechamento das portas após um tempo para entrada e saída de passageiros, bem como garantia de segurança (evento não-periódico, passa do sub estado "portas abertas" para "portas fechadas").
  - Pressionamento do botão de fechada de portas (evento não-periódico, passa do estado "portas abertas" para "portas fechadas").
  - Pessoa entre a porta (evento não-periódico, mantém-se no sub estado "portas abertas").
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
  - Detecção de falha:
    Ao detectar falha, o sistema deve interromper o movimento e ficar parado.

## Descrição Estrutural do Sistema
O sistema se baseia em um fluxo de estados onde definimos se um elevador sobe, desce ou se mantém parado com base nas solicitações internas e externas do elevador, bem como nas condições de segurança que devem ser satisfeitas. O diagrama abaixo retrata melhor os o fluxo de decisões:

![Diagrama Elevador drawio](https://github.com/andreglz/ea075-2024.2/assets/106714171/39f5be4c-cc7e-47d6-ad00-41ed6804440f)

Note que o mesmo funciona tanto para uma pessoa que solicita o elevador pelo lado de fora, quanto para alguém que aperta o botão de um andar já dentro do elevador. O diagrama mostra a situação em condições típicas e síncronas de funcionamento, mas haverá também a necessidade de uma verificação assíncrona em casos de falhas durante o trajeto do elevador, onde o mesmo deve parar e acionar suporte/segurança.
A fila também tem um papel importante, conforme explicado na sessão "Especificação de algoritmos", para saber se o elevador sobe ou desce de acordo com a ordem apertada e se para ou não em outro andar no caminho. De forma resumida, após alguma solicitação que entra em uma fila com uma determinada prioridade, a ideia é que o elevador se movimente baseado nessa fila para atender aos chamados.

## Especificações 

### Especificação Estrutural

O projeto possui dois atuadores, ambos motores CC, para controle de abertura e fechamento das portas do elevador e para subir e descer a cabine. O motor utilizado para o deslocamento vertical da cabine apresenta bastante torque, portanto, sua potência é alta. Com isso, a alimentação é feita utilizando um conversor AC/DC RAC20-K, que entrega 48V para alimentação do circuito do motor. O controle do sentido e da velocidade  é feito na saída do retificador utilizando uma ponte H L298N, conectada também ao microcontrolador, que consegue fazer o controle de ambos os motores paralelamente. Com isso, a ponte H entrega ao motor 44V de tensão contínua e 20A de corrente, com uma potência total de 880W. Assim, levando em conta um motor com eficiência de 90% e a velocidade de 0.2m/s de transporte, a carga máxima que o motor consegue transportar é de 404 kg.

A ideia do controle da parada correta da cabine do elevador é utilizar dois sensores fotoelétricos em cada andar (um para a parte inferior do piso e outro para a parte superior), sendo que o modelo em consideração é o E3Z-F da Omron. Assim, ao passar pelo sensor, o sistema saberá em que andar está a cabine e o momento correto para iniciar a frenagem. Outra importante função desse periférico é estacionar a cabine de forma extremamente precisa, alinhando o piso do elevador com o andar. Os dados dos sensores serão utilizados para comunicação com um display que mostrará ao passageiro o andar que a cabine está.

A porta possui quatro sensores de infravermelho, sendo utilizados dois para cada altura pré-determinada, dispostos em ambos os lados da porta. O papel desses sensores é detectar se há algum objeto entre as portas. O modelo escolhido foi o E18-D80NK-N, que possui um alcance de 6 a 80 cm. Quando um objeto for detectado, o sensor envia ao microcontrolador um sinal de nível lógico baixo. Com a leitura do nível lógico, um comando é enviado para o motor manter a porta aberta.

O elevador irá se locomover por quatro andares, assim, teremos quatro push buttons dentro do elevador para o passageiro indicar o destino desejado. Cada andar possuirá um push button para chamar o veículo. Logo, teremos oito no sistema, que, ao serem pressionados, enviam um sinal que será armazenado na memória estruturada em pilha. Na seção de especificação do algoritmo, o modo de funcionamento dos chamados é explicado de forma a otimizar o trajeto do elevador. Cada push bottom será conectado à uma porta GPIO do microcontrolador.

O microcontrolador escolhido para o sistema foi RP2040 desenvolvido pela Raspbarry Pi. A escolha ocorreu devido à quantidade de portas necessárias para todo o controle do sistema, e como o projeto não precisa uma compexidade alta, este microcontrolador atende os requisitos, além de possuir um custo acessível. Para a comunicação serial, a comunicação do tipo I2C foi escolhida, pois não há necessidade de uma alta velocidade de comunicação que vença em detrimento da menor complexidade.

### Especificação de Algoritmos 
Para a gestão de fila dos andares, o projeto se baseia no seguinte fluxograma:
![Fila Elevador](https://github.com/andreglz/ea075-2024.2/assets/106714171/826400fe-9c3d-46b8-b4a3-8262b10adffc)

Os eventos relacionados à abertura e ao fechamento de portas, bem como detecção de falha, sobrecarga e pessoa entre as portas são tratados no fluxograma da seção "_Descrição Estrutural do Sistema_", e tais eventos se relacionam diretamente com este acima no que resumimos pela tomada de decisão "Verificações de segurança ok?". Dessa forma, o algoritmo como um todo deve tratar dos dois fluxogramas, sendo que o primeiro diagrama se encaixa dentro do segundo para simplificarmos a visualização.

O microcontrolador apresenta memórias integradas, ROM, Flash e SRAM, que trabalham com palavras de 32 bits, assim é mais que sufiente para nosso projeoto, visto que projetaremos um controle para elevadores com até 4 andares (suficientemente representados por 2 bits), usando 2 sensores de nível por andar (mais 8 bits para monitoramento), e outras funções de controle como abertura das portas, detecção de movimento, etc, estimamos que seria necessário em torno de 16 bits para tal. O microcontrolador possibilita o uso de memórias externas, porém visto a demanda do projeto, não há necessidade da utilização.

## Referências
http://www.electrical-knowhow.com/2012/04/elevator-control-system.html

http://fpgaparatodos.com.br/2011/08/04/exemplo-de-exemplo/

https://cpi.com.ar/info_productos/pdf/E3Z-F.pdf

https://www.watelectronics.com/e18-d80nk-adjustable-infrared-sensor/
