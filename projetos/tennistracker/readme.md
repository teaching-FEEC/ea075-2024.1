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
- **Fixar na raquete**: o sistema pode ser afixado na raquete de tênis.
- **Armazenar os dados aquisitados**: o sistema é capaz de salavar na memória os dados dos sensores.
- **Medir a aceleração de translação**: o sistema consegue medir a aceleração de translação em três eixos.
- **Medir a velocidade angular e a orientação**: o sistema consegue medir a velocidade angular de rotação e a orientação em torno dos três eixos.
- **Salvar dados em cartão SD**: o sistema salva os dados coletados em um cartão SD que pode ser removido e inserido em um computador para leitura e análise dos dados.
- **Peso reduzido**: o sistema é leve, para que não influencie nas jogadas.
- **Sinalizar o nível de bateria**: o é capaz de sinalizar baixa bateria.
- **Armazenamento de energia (bateria)**: o sistema é capaz de funcionar com bateria.

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

### Eventos
|Eventos  | 
|--|
| Ligar (Chave on/off)  | 
| Desligar (Chave on/off)  |

### Tratamento de Eventos

|Eventos  | Tratamento  | 
|--|--|
| Ligar (Chave On/Off)  | Iniciar medições de grandezas (posição, velocidade, aceleração, etc.) (periódico com taxa de amostragem de 1kHz) + Ativar LED (aceso continuo)  |
| Desligar (Chave On/Off)  | Interromper as medições e o fornecimento de energia + apagar LED |
| Baixa Bateria  |  Quando ligado ativar LED piscante para sinalizar baixa bateria. |
| Bateria Desconectada |  Com a bateria desligada a alimentação do circuito é desconectada, sendo assim todo o dispositivo fica desenergizado. |

## Descrição Estrutural do Sistema

Atuadores:
- LED

Sensores:
- Acelerômetro e Giroscópio [MPU-6050](datasheets/MPU-6050.pdf)

Botões:
- Chave On/Off

Memória:
- Armazenamento dos dados coletados é feita atravez de cartão SD que, uma vez preenchido, pode ser retirado do dispositivo para passar os dados para um computador.

### Diagrama Estrutural:

[![diagrama_estrutural.svg editável](/projetos/tennistracker/images/diagrama_estrutural.svg)](https://app.diagrams.net/?libs=general;#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama_estrutural.svg#%7B%22pageId%22%3A%2290a13364-a465-7bf4-72fc-28e22215d7a0%22%7D)

### Diagrama de Estados:

[![diagrama.svg editável](/projetos/tennistracker/images/diagrama.svg)](https://app.diagrams.net/#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Fdiagrama.svg#%7B%22pageId%22%3A%2242789a77-a242-8287-6e28-9cd8cfd52e62%22%7D)

| Estado  | Função | 
|--|--|
| Desligado  | Neste estado, o produto está em modo dormente: o LED fica apagado, o sensor fica desabilitado e o microcontrolador entra em modo de baixa potência. A saída deste estado ocorre quando a chave é posicinada em On, passando para o estado de Aquisição |
| Aquisição  | Neste modo, o dispositivo está fazendo sua atividade-fim: adquirindo dados do sensor de movimento e salvando no cartão SD. Para indicar que está ativo, o LED fica aceso continuo. Para sair do estado de aquisição, a chave deve ser posicionada em Off, o que leva o dispositivo ao estado 'desligado'  |

## Especificações

### Especificação Estrutural

#### Elementos do Sistema
- [**Microcontrolador Atmega48P**](datasheets/ATmega48P.pdf)
    - Descrição: é um microcontrolador de baixa potência (48P é a versão mais econômica) de 8 bits, com arquitetura Harvard e instruções RISC. O interesse nesse microcontrolador para este projeto é a presença de módulos para comunicação I2C e SPI, necessários para interface com sensores e memória externa, além de sua ampla disponibilidade. Além disso, também possui um módulo de timer que pode ser configurado como RTC (real time counter, configurável no módulo Timer/Counter2), que é útil para medição do tempo nas partidas de tênis. 
    - **Interfaces necessárias:** SPI (pinos PORTB: PB2 = SS, PB3 = MOSI, PB4 = MISO, PB5 = SCK) e _ 2-wire Serial Interface_, que é compatível com o protocolo I2C (pinos PORTC: PC4 = SDA, PC5 = SCL)
    - **Outros módulos úteis:** Timer/Counter2 configurável como RTC (real time counter), para registro de tempo.
    - **Alimentação:** 1.8 - 5.5V (pretende-se usar alimentação em 2 V - segundo o datasheet, nesta tensão, a corrente típica necessária é: 0,3 mA (funcionando) ou 0,06 mA (idle))
- [**Acelerômetro e Giroscópio MPU-6050**](datasheets/MPU-6050.pdf)
    - **Descrição:** sensor de movimento de 6 eixos (acelerômetro de 3-eixos + giroscópio de 3 eixos) com processamento embutido. A interface de comunicação do disposito é a I2C e a velocidade máxima do barramento de comunicação é 400kHz, atendendo os requisitos do projeto (taxa de amostragem: 1kHz). Cada sensor (acelerômetro/giroscópio) tem um conversor AD dedicado de 16 bits, de forma que 32 bits são necessários por amostra.
    - **Interface:** I2C
    - **Alimentação:** 2.375V-3.46V / 3,8 mA típico
- [**Leitor de cartão micro SD**](https://produto.mercadolivre.com.br/MLB-3647392309-modulo-leitor-de-carto-tf-micro-sd-_JM) + [**cartão micro SD**](https://www.mercadolivre.com.br/carto-de-memoria-sandisk-ultra-com-adaptador-sd-64gb-modelo-sdsquns-064g/p/MLB8859356?pdp_filters=category:MLB7475#searchVariation=MLB8859356&position=11&search_layout=stack&type=product&tracking_id=fca81df3-afef-41e0-8763-50f8cef294a5)
    - **Descrição**: o cartão micro SD é uma memória FLASH e será destinado ao armazenamento dos dados coletados no acelerômetro e giroscópio. Sua velocidade de escrita é maior que o a taxa de amostragem dos sensores (32bits X 1kHz = 32kb/s) e a maioria dos cartões disponíveis tem espaço suficietne para armazenar dados de várias horas de treino (necessário: aproximadamente 100Mb/h). Para conexão com o microcontrolador, é utilizado um módulo leitor de cartão micro SD. Nele, há os pinos da interface SPI (CLK, MOSI, MISO, CS) e dois pinos de alimentação (no módulo escolhido: 3.3V). Assim, para cada treinho, um arquivo com os dados pode ser criado e editado pelo microcontrolador e, depois, o usuário pode simplesmente remover o cartão micro SD para leitura dos dados no computador. Sua vantagem em relação a uma EEPROM é a capacidade de armazenamento (FLASH: mais densa e mais barata) e facilidade de remoção e troca pelo usuário. 
    - **Interface**: SPI
    - **Alimentação:**: 3.3V
    - **Armazenamento mínimo**: ~100Mb por hora de treino
    - **Velocidade mínima de escrita**: ~32kb/s
- [**Bateria LR44**](datasheets/bateria_lr44.pdf) + [**Contatos elétricos para bateria**](https://pt.aliexpress.com/item/1005003653489918.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&isSmbAutoCall=false&needSmbHouyi=false&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=pt1005003653489918&ds_e_product_merchant_id=109139790&ds_e_product_country=BR&ds_e_product_language=pt&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19639392923&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=CjwKCAjw7NmzBhBLEiwAxrHQ-fnqVuuvNvoQg-XtbdGzZpf212cEHeSA4qzC3V2jcb424mBHsuvUrxoCtm0QAvD_BwE&aff_fcid=61534da5cb624ba9b464e5f80048f2dc-1719065829563-09911-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=61534da5cb624ba9b464e5f80048f2dc-1719065829563-09911-UneMJZVf&terminal_id=90e96157b48e4cc0b4ec8227361a3fb2&afSmartRedirect=y)
    - **Descrição**: A bateria LR44 é uma bateria do tipo botão com dimensões de 11.36mm(d)/5.4mm. Serão usadas quatro baterias em série, para se obter 6V de alimentação. Sua tensão de _cut-off_ é de 1.2V, de forma que a menor tensão fornecida na alimentação será 4.8V. Sua capacidade de corrente é suficiente para o projeto, uma vez que é previsto consumo menor que 110mA (a 6V) quando todos os componentes estão ativos.
    - **Tensão disponível:**: 4 X 1.5 = 6 V
    - **Capacidade**: 130 mAh
- [**Regulador de tensão - saída fixa 3.3V**](datasheets/regulador_LM1117.pdf)
    - **Descrição**: Cada componente escolhido possui uma faixa de tensão de alimentação distinta. No entanto, o valor de 3.3V é comum a todos. Assim, é necessário um regulador de tensão step-down para converter a tensão da bateria de 6V para uma saída estável de 3.3V, robusta também à descarga da bateria. O LM1117 foi escolhido por ser simples de ser utilizado e por ter a faixa de tensão de entrada desejada (tensão de dropout típica: 1.1V).
    - **Tensão de entrada**: ~ 4.4 - 15V
    - **Tensão de saída:**: 3.3V
    
#### Circuitos de Interface
  Será apenas necessário o regulador de tensão LM1117, para converter a tensão de 6V da bateria para 3.3V. Também será necessária a conversão analógico-digital dos valores de tensão da bateria e valores do sensor de movimento, mas o microcontrolador e o MPU-6050 já possuem conversores internamente. Por fim, serão necessário resistores de _pull-up_ no barramento I2C entre o microcontrolador e o sensor de movimento.

#### Restrições Físicas
  O dispositivo deve ter dimensões de no máximo 7cmX7cmX0,5cm para que sua fixação na raquete não comprometa as caracteristicas da raquete. Sua fixação deve ser firme o suficiente para suportar impactos a altas velocidades, por isso seu pedo também deve ser reduzido, idealmente por volta de 5 a 10g. Considerando que o disitivo não vai operar com altas correntes justamente pela sua caracteristica de paixa potência, a dissipação térmica não será um problema.

### Especificação de Algoritmos 

- O programa inicia com a configuração dos módulos do microcontrolador e seus pinos: escolha da fonte de sinais de relógio, funções dos pinos e fluxo do sinal (entrada ou saída, caso função seja GPIO), configuração dos timers e habilitação das interrupções por overflow dos timers.

- O timer1 é configurado com um período de contagem de 1ms (f=1kHz) e é habilitada sua interrupção a cada overflow do contador. Depois da configuração básica, o programa fica em um loop, aguardando chamadas da rotina de interrupção do timer1. Dentro desta rotina, chamada a cada 1ms, é feita a conversão do ADC0 (tensão da bateria) e a leitura e armazenamento dos dados do sensor de movimento. 

- O valor binário lido ('ADC_result') pode ser convertido para valor de tensão ('battery_level') com a equação a seguir: "battery_level = (ADC_result/1024)*(3.3*22/32);"

- Essa equação leva em conta que: (i) ADC é de 10 bits e, portanto, o valor máximo é 1024; (ii) VCC = 3.3V; (iii) são usados resistores de 10kOhm e 22kOhm no divisor de tensão na entrada do ADC. 

- Se a bateria tiver tensão menor que BATTERY_THRESHOLD=3.9V (aproximadamente 15% de capacidade restante), o LED deve piscar. O LED pisca com período de 500ms (toggle a cada 250ms). Como o timer1 já tem período de 1ms, a cada overflow seu, é incrementada a variável 'blink_counter' que, quando igual a 250 (250ms decorridos), ocasiona o toggle do LED.

- Fluxograma:

[![fluxchart_int.svg editável](/projetos/tennistracker/images/fluxchart_int.svg)](https://app.diagrams.net/#Hshen-n%2Fea075-2024.1%2Fmain%2Fprojetos%2Ftennistracker%2Ffluxchart_int.drawio#%7B%22pageId%22%3A%22C5RBs43oDa-KdzZeNtuy%22%7D)

## Referências

[1] Arduino and MPU6050 Accelerometer and Gyroscope Tutorial https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/

[2] E. van der Kruk and M. M. Reijne, “Accuracy of human motion capture systems for sport applications; state-of-the-art review,” European journal of sport science, vol. 18, no. 6, pp. 806–819, 2018, doi: https://doi.org/10.1080/17461391.2018.1463397.

[3] J. Tan, “Guide: Batteries for Embedded Devices,” Latest Open Tech From Seeed, Jan. 20, 2021. https://www.seeedstudio.com/blog/2021/01/20/guide-to-batteries-for-embedded-devices/.

[4] “PCB Trace Width Calculator | Trace Width Vs. Current Table,” mcl, Jun. 18, 2018. https://www.mclpcb.com/blog/pcb-trace-width-vs-current-table/.

[5] “How much current does a microSD card use?,” Electrical Engineering Stack Exchange. https://electronics.stackexchange.com/questions/33472/how-much-current-does-a-microsd-card-use.
