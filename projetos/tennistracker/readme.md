# `Monitor de Desempenho de Jogadores de Tênis`
# `TennisTracker`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).


|Nome  | RA | Curso|
|--|--|--|
| Nathan Shen Baldon  | 242448 | Eng. Elétrica|
| Gabriel Buzzi Sanches  | 256389  | Eng. Elétrica|


## Descrição do Projeto

O Tênis é conhecido por ser um esporte difícil de se praticar pela exigência de cordenação física e agilidade nos movimentos. Sabendo disso os feedbacks de cada jogada são de extrema importância para quem está aprendendo ou quer melhorar no esporte. Pensando nisso nosso objetivo é entregar esses feedbacks tirando proveito da mecânida dos movimentos da raquete do jogador durante uma partida, assim excluindo também qualquer viés devido a um observador terceiro (professor ou treinador) e ainda oferencendo uma base fixa para comparação dos resultados. Para isso um sistema eletrônico embarcado será projetado para ficar fixado na raquete do jogador enquanto ele prática o esporte aquisitando e armazenando dados variados que posteriormente podem ser analisados em cumputador. Inicialmente qualquer processamento em tempo real é deixado de lado, focando apenas na aquisição dos dados, mas o projeto do sistema irá considerar como uma medida de escalabilidade a capacidade de realizar processamentos em tempo real e retornar respostas mesmo durante a jogatina.  

##### Potenciais usuários
- Jogadores de tênis (desde iniciantes até profissionais) que desejam acompanhar sua jornada e desenvolvimento no esporte.
- Treinadores que desejam coletar dados para validar seu método de treinamento.
- Uso pela mídia e entidades do esporte em partidas oficiais para levantamento de estatísticas.
  
##### Valor econômico associado  

O dispositivo poderia ser vendido para qualquer pessoa interessada em monitorar seu desempenho no esporte Tênis.

## Descrição Funcional

### Funcionalidades
- **Fixar na raquete**: o sistema deve poder ser afixado na raquete de tênis.
- **Armazenar os dados aquisitados**: o sistema deve ser capaz de salavar na memória os dados dos sensores.
- **Medir a velocidade da raquete**: o sistema deve adquirir dados que permitam estimar velocidade.
- **Medir a intensidade das colisões com a bolinha**: o sistema deve adquirir dados que permitam estimar a intensidade de colisões com a bola.
- **Medir o ângulo com a horizontal da raquete**: o sistema deve adquirir dados que permitam estimar o ângulo da raquete em relação ao solo.
- **Interface para controlar quando começar quando parar aquisição**: deve ser possível controlar quando interromper as medições.
- **Interface para exportar os dados**: deve ser possível exportar os dados para análise externa.
- **Peso reduzido**: o sistema deve ser leve, para que não influencie nas jogadas.
- **Sinalizar o nível de bateria**: o sistema deve ser capaz de exibir o nível da bateria.
- **Armazenamento de energia (bateria)**: o sistema deve ser capaz de funcionar sem necessidade de cabos de energia.

### Funcionalidade de análise:
Uma vez que o dados forem aquisitados, via software poderemos executar:
- Contar o número de golpes
- Medir o tempo jogado
- Estimar a qualidade dos golpes
- Identificar golpes
- Encontrar correlações entre a varáveis medidas e desempenho na partida
- Avaliar o rendimento físico do atleta
- Avaliar caracteristicas dos golpes que resultam em pontos na partida

### Configurabilidade
- Aquisição
- Carregamento
- Carregamento + Transferência de Dados

### Eventos
|Eventos  | 
|--|
| Ligar (botão on/off)  | 
| Desligar (botão on/off)  |

### Tratamento de Eventos

|Eventos  | Tratamento  | 
|--|--|
| Ligar (Chave On/Off)  | Iniciar medições de grandezas (posição, velocidade, aceleração, etc.) (periódico com taxa de amostragem de 1kHz) + Ativar LED (aceso continuo)  |
| Desligar (Chave On/Off)  | Interromper as medições e o fornecimento de energia + apagar LED |
| Baixa Bateria  |  Ativar LED (piscante) para sinalizar baixa bateria. O dispositivo continua funcionando se estiver ligado. |
| Bateria Desconectada |  Com a bateria desligada a alimentação do circuito é desconectada, sendo assim todo o dispositivo fica desenergizado. |

## Descrição Estrutural do Sistema

Atuadores:
- LED

Sensores:
- Acelerômetro e Giroscópio [MPU-6050](https://www.makerhero.com/produto/acelerometro-e-giroscopio-3-eixos-6-dof-mpu-6050/?utm_source=google&utm_medium=organic&utm_campaign=shopping&utm_content=surfaces_across_google&gad_source=1&gclid=CjwKCAjwtqmwBhBVEiwAL-WAYQ2EM5FQUUMtuxIyKFbXBxsoUhK2dI_2Ud5VmFDbftmgO3FnrXPz_hoCWkoQAvD_BwE#tab-blogrelacionados)

Botões:
- Chave On/Off

Comunicação:
- Comunicação dos dados coletados é feita atravez de cartão SD que, uma vez preenchido, pode ser retirado do dispositivo para passar os dados para um computador.

### Diagrama Estrutural:

[![diagrama_estrutural.svg editável](/projetos/tennistracker/diagrama_estrutural.svg)](https://app.diagrams.net/?libs=general;#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama_estrutural.svg#%7B%22pageId%22%3A%2290a13364-a465-7bf4-72fc-28e22215d7a0%22%7D)

### Diagrama de Estados:

[![diagrama.svg editável](/projetos/tennistracker/diagrama.svg)](https://app.diagrams.net/#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama.svg#%7B%22pageId%22%3A%2242789a77-a242-8287-6e28-9cd8cfd52e62%22%7D)

| Estado  | Função | 
|--|--|
| Desligado  | Neste estado, o produto está em modo dormente: o LED fica apagado, o sensor fica desabilitado e o microcontrolador entra em modo de baixa potência. A saída deste estado ocorre quando a chave é posicinada em On, passando para o estado de Aquisição |
| Aquisição  | Neste modo, o dispositivo está fazendo sua atividade-fim: adquirindo dados do sensor de movimento e salvando no cartão SD. Para indicar que está ativo, o LED fica aceso continuo. Para sair do estado de aquisição, a chave deve ser posicionada em Off, o que leva o dispositivo ao estado 'desligado'  |

## Especificações

### Especificação Estrutural

#### Elementos do Sistema
- [Microcontrolador Atmega48P](projetos/tennistracker/datasheets/ATmega48P_datasheet.pdf)
    - Descrição: é um microcontrolador de baixa potência (48P é a versão mais econômica) de 8 bits, com arquitetura Harvard e instruções RISC. O interesse nesse microcontrolador para este projeto é a presença de módulos para comunicação I2C e SPI, necessários para interface com sensores e memória externa, além de sua ampla disponibilidade. Além disso, também possui um módulo de timer que pode ser configurado como RTC (real time counter, configurável no módulo Timer/Counter2), que é útil para medição do tempo nas partidas de tênis. 
    - **Interfaces necessárias:** SPI (pinos PORTB: PB2 = SS, PB3 = MOSI, PB4 = MISO, PB5 = SCK) e _ 2-wire Serial Interface_, que é compatível com o protocolo I2C (pinos PORTC: PC4 = SDA, PC5 = SCL)
    - **Outros módulos úteis:** Timer/Counter2 configurável como RTC (real time counter), para registro de tempo.
    - **Alimentação:** 1.8 - 5.5V (pretende-se usar alimentação em 2 V - segundo o datasheet, nessa tensão, a corrente máxima necessária é: 0,3 mA (funcionando) ou 0,06 mA (idle))
- [Acelerômetro e Giroscópio MPU-6050](projetos/tennistracker/datasheets/MPU-6000-Datasheet1.pdf)
    - **Descrição:** sensor de movimento de 6 eixos (acelerômetro de 3-eixos + giroscópio de 3 eixos) com processamento embutido. A interface de comunicação do disposito é a I2C e a velocidade máxima do barramento de comunicação é 400kHz, atendendo os requisitos do projeto (taxa de amostragem: 1kHz). Cada sensor (acelerômetro/giroscópio) tem um conversor AD dedicado de 16 bits, de forma que 32 bits são necessários por amostra.
    - **Interface:** I2C
    - **Alimentação:** 2.375V-3.46V
- [**Leitor de cartão micro SD**](https://produto.mercadolivre.com.br/MLB-3647392309-modulo-leitor-de-carto-tf-micro-sd-_JM) + [**cartão micro SD**](https://www.mercadolivre.com.br/carto-de-memoria-sandisk-ultra-com-adaptador-sd-64gb-modelo-sdsquns-064g/p/MLB8859356?pdp_filters=category:MLB7475#searchVariation=MLB8859356&position=11&search_layout=stack&type=product&tracking_id=fca81df3-afef-41e0-8763-50f8cef294a5)
    - **Descrição**: o cartão micro SD é uma memória FLASH e será destinado ao armazenamento dos dados coletados no acelerômetro e giroscópio. Sua velocidade de escrita é maior que o a taxa de amostragem dos sensores (32bits X 1kHz = 32kb/s) e a maioria dos cartões disponíveis tem espaço suficietne para armazenar dados de várias horas de treino (necessário: aproximadamente 100Mb/h). Para conexão com o microcontrolador, é utilizado um módulo leitor de cartão micro SD. Nele, há os pinos da interface SPI (CLK, MOSI, MISO, CS) e dois pinos de alimentação (no módulo escolhido: 3.3V). Assim, para cada treinho, um arquivo com os dados pode ser criado e editado pelo microcontrolador e, depois, o usuário pode simplesmente remover o cartão micro SD para leitura dos dados no computador. Sua vantagem em relação a uma EEPROM é a capacidade de armazenamento (FLASH: mais densa e mais barata) e facilidade de remoção e troca pelo usuário. 
    - **Interface**: SPI
    - **Alimentação:**: 3.3V
    - **Armazenamento mínimo**: ~100Mb por hora de treino
    - **Velocidade mínima de escrita**: ~32kb/s

#### Circuitos de Interface
  A bateria deve alimentar todo o dispositivo atravez de um power rail de onde podem derivar se necessário reguladores de tensão para nivelar a tensão de acordo com cada dispositivo. O LED não será conectado a bateria e sim diretamente a uma das saídas digitais do microcontrolador. O conversor AD interno do microcontrolador será utilizado para monitorar a tensão de alimentação de forma que com uma lógica programada o LED começe a piscar quando a tensão abaixar de um certo valor, indicando que a bateria está com baixa capacidade remanescente.

#### Restrições Físicas
  O dispositivo deve ter dimensões de no máximo 4cmX4cmX0,5cm para que sua fixação na raquete não comprometa as caracteristicas da raquete. Sua fixação deve ser firme o suficiente para suportar impactos a altas velocidades, por isso seu pedo também deve ser reduzido, idealmente por volta de 5 a 10g. Considerando que o disitivo não vai operar com altas correntes justamente pela sua caracteristica de paixa potência, a dissipação térmica não será um problema.

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

> (Se preferir, adicione um link para o documento de especificação de algoritmos).
> 
> Deve ser elaborado para CADA evento o algoritmo de tratamento deste evento. Com base no
> tamanho de cada algoritmo, estima-se o tamanho de memória necessária para armazenar todos
> os programas e os dados associados. Isso permitirá especificar a memória a ser utilizada e o
> espaço onde serão armazenados os programas. O algoritmo de tratamento de evento pode
> ser representado graficamente por um fluxograma. Recomenda-se usar símbolos gráficos consistentes 
> com a norma internacional ISO 1028-1973 e IS0 2972-1979.


## Referências
[1] Motion Processing Unit – MPU9250 for RTPT https://paulplusx.wordpress.com/2016/03/04/rtpts_mpu/

[2] Arduino and MPU6050 Accelerometer and Gyroscope Tutorial https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/

[3] E. van der Kruk and M. M. Reijne, “Accuracy of human motion capture systems for sport applications; state-of-the-art review,” European journal of sport science, vol. 18, no. 6, pp. 806–819, 2018, doi: https://doi.org/10.1080/17461391.2018.1463397.
