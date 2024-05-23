# `Rodovias Fluidas: Sistema de Redução de Congestionamentos`
# `Smooth Highways: Trafic Jam Reduction System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Kevin Caio Marques dos Santos  | 247218  | Eng. de Computação|
 | Thiago Maximo Pavão  | 247381  | Eng. de Computação|


## Descrição do Projeto

O projeto foi idealizado para abordar um problema comum enfrentado pelos motoristas hoje em dia: congestionamentos em rodovias. Muitas vezes, atribui-se esse problema à ocorrência de acidentes que bloqueiam uma das vias, forçando o tráfego a se concentrar na outra via. No entanto, em muitos casos de congestionamento, não há acidente aparente ou outra explicação clara, o que levanta questões para os motoristas mais perspicazes.

Durante uma investigação sobre essa questão, foi encontrado um [vídeo](https://www.youtube.com/watch?v=iHzzSao6ypE) que explicava a causa de muitos congestionamentos. O principal fator identificado foi a grande disparidade de velocidades entre os veículos na mesma via, juntamente com ultrapassagens realizadas por veículos mais lentos. Isso faz com que outros motoristas tenham que reduzir sua velocidade, criando uma espécie de "onda de lentidão" que se propaga ao longo da rodovia. Eventualmente, essa onda de lentidão pode levar alguns carros a pararem completamente para evitar colisões.

Diante desse contexto, o objetivo do projeto é reduzir a propagação dessa onda de lentidão, diminuindo assim a extensão dos congestionamentos, especialmente nos pontos onde os motoristas são obrigados a parar completamente. O objetivo final é evitar que o congestionamento se agrave.

A prejudicialidade dos congestionamentos está muito além do atraso que gera para os motoristas em suas trajetórias diárias. Alguns exemplos de consequências são:

 - Estresse dos motoristas
 - Acidentes
 - Maior consumo de combustível
 - Maior poluição
 - Maior prejuízo para a saúde dos motoristas expostos a poluição gerada pelos carros

Nesse sentido, o Rodovias Fluídas® visa solucionar todos esses problemas ao monitorar o surgindo desses engarrafamentos e enviar informações aos motoristas que vem atrás para reduzirem a velocidade, de modo ao chegarem ao local do suposto congestionamento, ele ja tenha desaparecido. Com a implementação desse sistema, prevê-se que haja um significativo retorno econômico ao reduzir o consumo de combustível e a prevenção de acidentes.

## Descrição Funcional

O objetivo do projeto é identificar congestionamentos nas rodovias e avisar os motoristas que trafegam na mesma rodovia para reduzirem a velocidade, de modo que ao chegarem ao local em que existia o engarrafamento ele já tenha se resolvido.

### Funcionalidades

- Medir a velocidade do veículo
- Medir a posição do veículo na rodovia
- Mostrar mensagens em um display sobre congestionamentos e informar qual velocidade o motorista deve trafegar.
- Reproduzir avisos sonoros quando novas informações estão disponíveis
- Detectar a localização e o tamanho de congestionamentos
- Determinar a velocidade adequada em reação a um congestionamento à frente
- Capacidade de distribuição das informações sobre congestionamentos para os carros trafegando na rodovia 

### Configurabilidade

Como configuração, o usuário que possuir o dispositivo em seu carro pode optar por desabilitar o aviso sonoro e ao invés disso o display de informações deve piscar algumas vezes para chamar a atenção do motorista.

### Eventos

#### Módulo Móvel

1. Inicialização do sistema
2. Conexão do Módulo com uma torre dentro do seu alcance
3. Monitoramento da velocidade do veículo (periódico, 3 segundos)
4. Falha na comunicação com os periféricos
5. Recebimento de informações da torre
6. Perda de conexão com a torre

#### Módulo Fixo (Torre)

1. Inicialização do sistema
2. Nova conexão com um carro
3. Fim de uma conexão com um carro
4. Recebimento de dados (posição, direção e velocidade) de um carro
5. Notificação de condição de tráfego por outras torres
6. Atualização nas condições de tráfego da via (por algoritmo interno)

### Tratamento de Eventos

#### Módulo Móvel

1. Inicializa todos os periféricos e verifica por erros
2. Mostra a mensagem de conectado no visor lcd e inicializa um timer
3. Coleta a velocidade do veículo e compara com a última velocidade enviada a torre, se essa diferença for maior que um limite, envia as informações atuais de velocidade, direção e posição para a torre, e atualiza a última velocidade enviada para a atual
4. Para o timer, encerra a conexão com a torre se houver e mostra uma mensagem de erro no visor lcd se o erro não for no visor
5. Verifica a mensagem recebida, se for de congestionamento, mostra no visor a mensagem de cosgestionamento e a velocidade maxima fornecida pela torre, se não for de congestionamento apenas mostra a velocidade máxima recebida. Além disso, se a velocidade máxima recebida for diferente da última recebida, emite um alerta sonoro
6. Mostra a mensagem de disconectado no visor e para o timer 

#### Módulo Fixo (Torre)

1. Cria estruturas de dados para armazenamento das informações recebidas pelos carros e outras torres. Além disso, se conecta com as outras torres.
2. Informa a velocidade máxima da via, e cria entrada na tabela para armazenar dados enviados pelo carro.
3. Remove a entrada na tabela do carro desconectado.
4. Calcula a posição em que o carro se encontra na rodovia (o kilômetro) e atualiza os dados na tabela na posição relativa ao carro que gerou o evento.
5. Atualiza tabela de informações enviadas por outras torres. E propaga as informações recebidas para a torre vizinha.
6. Envia cada carro a velocidade que ele deve trafegar, avisando também se um congestionamento foi detectado. Além dos carros, avisa também torres vizinhas sobre as novas condições.

## Descrição Estrutural do Sistema

O sistema será composto por dois tipos de dispositivos: Módulos móveis, que estão presentes nos carros dos usuários do sistema e módulos fixos, presentes ao longo das rodovias, principalmente em trechos em que congestionamentos são comuns.

Os módulos móveis tem como objetivo monitorar a velocidade do carro e informar ao motorista quando deve reduzir sua velocidade. Ele baseia essa decisão em sinais recebidos pelo módulos fixo mais próximo. Além disso, tem o papel de informar a velocidade do carro para o módulo fixo mais próximo.

Os dispostivos fixos são torres colocadas ao longo da via, e tem como objetivo detectar congestionamentos, recebendo informações de velocidade dos motoristas mais próximos, e repassar a informação para torres anteriores na via, que por sua vez avisam sobre as condições ao módulos móveis proxímos a elas.

![Alt text here](diagramas/diagrama-estrutural.png)

## Especificações

### Brainstorm

- Mapa nas torres
- Bússula pra identificar direção
- Estado de standy by do dispostivo móvel até mensagem de uma torre
- Tomada de decisão pela torre, de acordo com a posição do móvel, pra saber se o carro está na rodovia ou em uma rua paralela
- GPS para saber a posição do carro
- Consulta dos dispositivos móveis para as torres da posição atual em caso de congestionamento

### Especificação Estrutural

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

A realização do projeto completo só é possível com a definição da forma de comunicação entre os dispositivos, as torres (módulo fixo) precisam ser capazes de realizar conexão com todos os carros em seu alcance e também com torres vizinhas. Para simplificar o projeto, nos limitamos a pesquisar algumas tecnlogias existentes ou em desenvolvimento que possam ser utilizadas para realizar essa comunicação, e portanto não especificamos aqui componentes nem os algoritmos necessários para tornar essa comunicação possível.

#### Módulo móvel

// Componentes e especificoes de operação do módulo móvel

#### Módulo fixo

// Componentes e especificoes de operação do módulo fixo OU não especificar componentes


### Especificação de Algoritmos 

> (Se preferir, adicione um link para o documento de especificação de algoritmos).
> 
> Deve ser elaborado para CADA evento o algoritmo de tratamento deste evento. Com base no
> tamanho de cada algoritmo, estima-se o tamanho de memória necessária para armazenar todos
> os programas e os dados associados. Isso permitirá especificar a memória a ser utilizada e o
> espaço onde serão armazenados os programas. O algoritmo de tratamento de evento pode
> ser representado graficamente por um fluxograma. Recomenda-se usar símbolos gráficos consistentes 
> com a norma internacional ISO 1028-1973 e IS0 2972-1979.

Como já explicado, não realizamos a especificação do circuito utilizado para possibilitar a comunicação entre os módulos, mas supomos aqui que qualquer tecnologia utilizada seja capaz de gerar os seguintes eventos: conexão de um novo dispositivo, perca da conexão, recebimento de dados e envio de dados. Apenas supondo estes princípios de inter-comunicação foram gerados os algoritmos mostrados a seguir. 

#### Algoritmos do módulo móvel

```
// Evento 1: Ao inicializar
function setup() {
  status = initLCD();
  if(status == ERROR) {
    errorBeep();
    stop();
  }
  
  status = initGPS();
  if(status == ERROR) {
    showMessageLCD(INTERNAL_ERROR);
    errorBeep();
    stop();
  }

  status = initCompass();
  if(status == ERROR) {
    showMessageLCD(INTERNAL_ERROR);
    errorBeep();
    stop();
  }

  status = initCarCommunication();
  if(status == ERROR) {
    showMessageLCD(CAR_COMM_ERROR);
    errorBeep();
    stop();
  }
}

// Evento 2: Quando entra no alcance de uma torre, e se conecta a ela
function onConnect() {
  showMessageLCD(CONNECTED);
  startTimer();
}

// Evento 3: Quando o timer reinicia, curto período para detectar grandes variações na velocidade e notificar a torre
function timerInterrupt() {
  velocity = getCarVelocity();

  if(abs(velocity - lastSentVelocity) > TRESHOLD * velocity  or  currentTime - lastSentTime > MAX_PERIOD) {
    lastSentVelocity = velocity;
    gpsData = readGPS();
    compassData = readCompass();

    sendData(velocity, gpsData, compassData);
  }
}

// Evento 4: Ao ocorrer um erro de conexão com algum periferico, mostra mensagem de erro, se possível, e finaliza conexao com torre se necessário
function peripheralError(errorMessage){
  if(errorMessage != commTower){
     stopConnection();
  }
  if(errorMessage != commLCD) {
     showMessageLCD(DISCONNECTED);
  }
  errorBeep();
  stop();
}

// Evento 5: Ao receber um dado da torre. Informação sobre a velocidade máxima a se andar e se há congestionamento à frente
function receiveData(reponse) {
  if(response.trafficJam == True) {
    showMessageLCD(TRAFFIC_JAM, response.maxVelocity);
  }
  else {
    showMessageLCD(CONNECTED, response.maxVelocity);
  }

  if(lastMaxVelocity != response.maxVelocity) {
    alertBeep();
    lastMaxVelocity = response.maxVelocity;
  }
}

// Evento 6: Ao sair do alcance da torre
function onDisconnect() {
  showMessageLCD(DISCONNECTED);
  stopTimer();
}
```
Para este módulo não há grande necessidade de memória raaaaaaaaam,será preciso armazenar temporariamente as informações de velocidade atual, velocidade enviada anteriormente, posição atual do veículo e direção. Além de pequenas informações informações de status e retornos de funções, porém tais variáveis serão apenas alguns bytes e por hora não serão contabilizadas, só serão levadas em consideração durante a estimativa final, a qual considerará uma quantidade a mais de armazenamento para tais variáveis.

mensagens na flash 

#### Algoritmos do módulo fixo

```
// Evento 1: Ao inicializar
function setup() {
  initCarsInfoTable();
  initTowersInfoTable();

  connectNeighboringTowers();
}

// Evento 2: Carro se conecta à torre ao entrar em seu alcance
function onCarConnect(car) {
  addEntryOnCarTable(car);
  car.sendData(ROAD_MAX_VELOCITY);
}

// Evento 3: Recebimento de dados (posição, direção e velocidade) de um carro
function receiveCarData(data) {
  roadPosition = calculateCarPositionOnRoad(data.position);
  updateEntryOnCarTable(roadPosition, data.direction, data.speed);
}

// Evento 4: Carro se desconecta da torre (fora do range)
function onCarDisconnect(car) {
  removeEntryFromCarTable(car);
}

// Evento 5: Ao receber mensagens de outras torres com atualizações
function onTrafficConditionNotification(trafficCondition) {
  updateTowerTable(trafficCondition);
  propagateNotification();
}

// Evento 6: Ao detectar internamente uma atualização nas condições de tráfego
function onTrafficConditionUpdate(trafficCondition) {
  for(car in table) {
    maxVelocity = calculateMaxVelocity(car.position, car.direction, trafficCondition);
    car.sendData(TRAFFIC_JAM, maxVelocity);
  }

  notifyNeighboringTowers(trafficCondition);
}
```

A lógica mais complexa do programa está na função de análise dos dados coletados dos carros e informações recebidas das outras torres, a ideia é que essa análise seja feita continuamente em segundo plano por algum algoritmo potencialmente sofisticado. Uma ideia é que isso poderia até ser feito por algum algoritmo de inteligência artificial, mas ela vem com o custo da necessidade de um processador mais poderoso. Também poderia ser interessante utilizar um processador com mais de um núcleo, para que as tarefas de comunicação com os veículos e com as outras torres (e outras tarefas acopladas à estas) possam ser feitas de forma independente da análise dos dados em tempo real.

Uma análise de memória que pode ser feita a partir dos algoritmos mostrados é a seguinte. Temos duas tabelas de dados que devem ser armazenadas na memória RAM, o tamanho máximo de cada uma delas depende da quantidade de carros suportada por cada torre e da quantidade de informações relativas à outras torres que cada uma armazenará.

Supondo que 

- Cada torre tenha um alcance de 1 km
- Para o algoritmo de prevenção de congestionamento seja necessário ter as informações de tráfego de 21 km à frente
- Cada torre suporte atender 100 carros

A tabela de informações das torres terá portanto conhecimento de um total de 21 km * 2 = 42 km (bidirecional) e então cada torre precisa se comunicar e armazenar informações de outras 20.
Supondo que o pacote de informações de cada uma seja de 10 bytes, detalhando bem o estado do tráfego precisariamos de 20 * 10 = 200 bytes de memória RAM para essa tabela.

Sobre cada carro conectado, a torre deve armazenar informações sobre sua posição, velocidade e direção e portanto a quantidade de bits para cada carro é dada por

- Posição: especificar em um espaço de 2 km, com precisão de 100m, temos 20 possibilidades, necessitando de 5 bits.
- Velocidade: de 0 - 120 km/h com precisão de 5 km/h, temos 24 possibilidades, que necessita de 5 bits.
- Direção: O carro pode estar andando apenas em um dos dois sentidos na via, portanto é apenas necessário um bit.

Isso totaliza 11 bits por carro, e portanto 1100 bits ~ 138 bytes.

Além disso, cada torre precisa armazenar um mapa para conseguir associar a posição dada pelo GPS de cada módulo móvel à uma posição na pista (o kilômetro da posição, por exemplo).
O mapa das torres pode ser representado como uma lista de coordenadas e o kilômetro equivalente para a coordenada em questão. Considerando 4 bytes para longitude e latitude, mais 5 bits para especificação da posição relativa ao alcance da torre. Temos então 69 bits por linha, o que totaliza aproximadamente 173 bytes.

Temos então os requisitos de memória...


## Referências

- Vídeo motivador do projeto: https://www.youtube.com/watch?v=iHzzSao6ypE
