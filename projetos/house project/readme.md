# `<Projeto de Casa Inteligente>`
# `<Smart Home Project>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Daniel Alexander Ortega Rodriguez  | 261261  | Eng. Elétrica|
> | Luciano Cardoso Ferreira Filho     | 240276  | Eng. Elétrica|

## Arquivos Importantes

[Placa PCB e esquematico](https://github.com/EndlessLight9/ea075-2024.1-dolc/tree/main/projetos/house%20project/pdf)

Lista de Componentes:
- 6 Sensores de Presença HC-SR501
- 5 Sensores de Gás e Fumaça MQ-2
- 1 Sensor de Temperatura DS18B20
- Painel de LEDs com 5 LEDs 5 mm
- Buzzer Piezoelétrico Ativo 5V
- Alto-falante Visaton SC 5.9
- Display LCD
- Microcontrolador ATmega32
- 5 Resistores de 220 Ohms
- 3 Resistores de de 10k Ohms
- 1 Resistor de 4,7k Ohms
- 2 Capacitores de 100nF
- 2 Capacitores de 22pF
- Cristal de 16 MHz
- Conectores
- Conversor 110V/220V para 5V
  
## Descrição do Projeto
 O objetivo principal deste projeto é criar um sistema de segurança eficiente, focado em casas de menor porte, mas que também possa ser otimizado para residências maiores. O sistema de segurança proporciona 
 eficiência energética e conforto aos moradores. Ele inclui funcionalidades como: sensor de presença conectado a um LED, permitindo monitoramento conforme desejado pelo usuário e podendo também acionar um alarme 
 sonoro, se desejado (por exemplo, ao sair de casa); sensor de gás com alarme sonoro, ativado ao detectar níveis potencialmente perigosos, sensor de fumaça, que aciona um alarme sonoro ao detectar altos níveis 
 de fumaça e sensor de temperatura, utilizado para vizualização da temperatura dos cômodos.


A crescente preocupação com a segurança residencial, aliada ao aumento de incidentes envolvendo gases inflamáveis e incêndios domésticos, motiva a criação deste sistema. Nosso projeto busca atender à demanda por soluções acessíveis e eficientes para a segurança doméstica, que sejam fáceis de instalar e operar. Estamos abordando a necessidade crítica de monitoramento e resposta rápida a situações de risco em ambientes residenciais, como presença de intrusos, vazamentos de gás, fumaça e temperaturas anômalas. Este sistema pretende reduzir os riscos de acidentes graves e melhorar a sensação de segurança dos moradores. Este sistema é ideal proprietários de residências pequenas e médias que desejam um sistema de segurança integrado e fácil de usar. Também é adequado para idosos que vivem sozinhos, famílias com crianças e qualquer pessoa preocupada com a segurança e a eficiência energética de sua casa. Nosso sistema tem potencial para gerar valor econômico significativo, tanto na redução de custos com danos residenciais quanto na diminuição de despesas com energia, devido à automação inteligente e monitoramento contínuo. Além disso, ao prevenir incidentes graves, ele pode reduzir gastos médicos e de seguros, proporcionando um retorno financeiro positivo para os usuários e investidores.


 
## Descrição Funcional

Sensor de Presença:
 O sensor de presença é responsável por detectar movimento em áreas específicas da casa. Este sensor está conectado a um LED, que indica visualmente a detecção de movimento. Quando o sensor capta a presença de 
 alguém, o LED acende, permitindo que os moradores saibam que há movimento no ambiente monitorado. Além disso, o sistema permite que o usuário configure a ativação de um alarme sonoro ao detectar presença. Esta 
 funcionalidade é particularmente útil quando os moradores estão ausentes, oferecendo uma camada adicional de segurança ao alertar sobre movimentos inesperados.

 Sensor de Gás e Fumaça:
 O sensor de gás é projetado para detectar a presença de gases potencialmente perigosos no ambiente, como gás de cozinha. Quando o sensor detecta níveis elevados de gás, um alarme sonoro é imediatamente acionado 
 para alertar os moradores. Esta função é essencial para prevenir incidentes graves, como explosões ou intoxicações, garantindo a segurança dos habitantes da casa. O sensor é calibrado para identificar 
 concentrações de gás que ultrapassem limites seguros, proporcionando uma resposta rápida e segura em situações de risco.


 Sensor de Temperatura :
   O sensor de temperatura desempenha um papel crucial ao fornecer informações essenciais aos moradores. Ele monitora atentamente a temperatura de cada cômodo e apresenta, de forma clara e precisa, os resultados em um display LCD.

Microcontrolador ATmega32: 
O ATmega32 é o núcleo do sistema, coordenando a operação de todos os sensores e atuadores. Este microcontrolador oferece várias portas I/O, alta capacidade de processamento e flexibilidade para futuras expansões. Ele facilita a integração de múltiplos sensores e dispositivos de saída, garantindo que o sistema seja robusto e escalável.

### Funcionalidades


Detecção de Presença: Utilizando sensores de movimento, o sistema pode identificar a presença de indivíduos em áreas específicas da casa. Isso permite a ativação de alertas visuais (LEDs) e sonoros para notificar os moradores sobre atividades suspeitas.

Detecção de Gás: O sistema possui sensores que monitoram continuamente a presença de gases potencialmente perigosos. Ao detectar níveis elevados, um alarme sonoro é acionado para alertar os moradores, permitindo uma resposta rápida para evitar acidentes.

Detecção de Fumaça: Sensores de fumaça instalados em pontos estratégicos da residência detectam a presença de fumaça, acionando imediatamente um alarme sonoro. Esta funcionalidade é crucial para a detecção de incêndios, possibilitando a evacuação e a chamada dos serviços de emergência.

Detecção de Temperatura: Sensores de temperatura instalados em cada cômodo, com exceção do banheiro e quintal, captam as variações térmicas do ambiente e as apresentam aos moradores por meio de um display LCD intuitivo a atualização de dados é feita a cada 2 segundos. Essa funcionalidade essencial mantém os residentes constantemente informados sobre as condições climáticas internas, capacitando-os a realizar ajustes imediatos e precisos para assegurar um ambiente confortável e acolhedor em casa.

Monitoramento em Tempo Real: Todos os sensores são integrados a um sistema central que permite o monitoramento em tempo real. Os moradores podem visualizar o status dos sensores e receber notificações instantâneas em caso de anomalias.

### Configurabilidade

Configuração de Alarmes: É possível definir quando os alarmes sonoros devem ser ativados, como por exemplo, apenas quando a casa está vazia ou durante determinados horários.

Notificações Personalizadas: Os moradores podem configurar o sistema para receber notificações alerta via LED ou alarme sonoro.

Unidades de Medida: Permite a configuração para exibir a temperatura em graus Celsius ou Fahrenheit. 

Integração com Outros Sistemas: O sistema pode ser integrado com outros dispositivos de automação residencial, como câmeras de segurança, sistemas de iluminação, sprinklers e controles de acesso, permitindo uma gestão centralizada da segurança da casa.

### Eventos

#### Eventos Periódicos:

Verificação de Níveis de Gás e Fumaça : Monitoramento contínuo dos níveis de gás e fumaça no ambiente.

Leitura de Temperatura: O sensor realiza leituras de temperatura em intervalos regulares de 2 segundos.

Atualização da temperatura mostrada no display LCD

#### Eventos Não Periódicos:

Detecção de Presença: Ativado quando um movimento é detectado.

Alerta de Gás: Ativado ao detectar níveis perigosos de gás.

Alerta de Fumaça: Ativado ao detectar níveis elevados de fumaça.



### Tratamento de Eventos


#### Detecção e Notificação:

Quando um sensor detecta um evento (presença, gás, fumaça ou temperatura), ele envia imediatamente um sinal ao sistema central.
O sistema central processa o sinal e ativa os alarmes sonoros e visuais correspondentes.


##### Ação Imediata:

Para Detecção de Presença: O LED é aceso e o alarme sonoro é ativado (se configurado). Os moradores são notificados para verificar a situação. Prioridade 3

Para Detecção de Gás: O alarme sonoro é ativado e uma notificação de emergência é enviada. Os moradores devem ventilar a área e evacuar se necessário. Prioridade 1

Para Detecção de Fumaça: O alarme sonoro é ativado e uma notificação de emergência é enviada. Os moradores devem evacuar imediatamente e chamar os bombeiros. Prioridade 2

Para Detecção de Temperatura: As informações lidas pelo sensor são atualizadas no display de LCD. Prioridade 4




## Descrição Estrutural do Sistema

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165414259/cd5ead5f-4a14-476b-9c84-77e12367fa5d)


#### Blocos Funcionais
##### Sensores:

Sensor de Presença: Detecta movimento e envia sinais ao controlador central.

Sensor de Gás: Monitora a concentração de gás e fumaça no ambiente e envia um sinal ao controlador quando níveis perigosos são detectados.


Sensor de Temperatura: Monitora a Temperatura do ambiente e envia um sinal para controlador da informação lida.

#### Controlador Central

Microcontrolador: O núcleo do sistema, responsável por receber sinais dos sensores, processar esses sinais e tomar decisões com base na programação interna. 

#### Unidades de Alerta

LED de Indicação: Acende para indicar a detecção de presença.

Alarmes Sonoros: Ativados pelo controlador central em resposta a sinais dos sensores de gás e fumaça, ou conforme configurado pelo usuário para o sensor de presença.

Display de LCD: Apresenta de forma clara e instantânea a temperatura ambiente aos moradores.

#### Relacionamento entre Blocos e Sinais de Comunicação

Sensor de Presença para Microcontrolador: Envia um sinal digital quando detecta movimento.

Sensor de Gás e Fumaça para Microcontrolador: Envia um sinal analógico  quando os níveis de gás são perigosos.

Sensor de Temperatura para Microcontrolador: Envia um sinal digital da temperatura lida.

#### Sinais do Controlador Central para Unidades de Alerta

Microcontrolador para LED de Indicação: Envia um sinal para acender o LED.

Microcontrolador para Alarmes Sonoros: Envia sinais para ativar os alarmes em resposta à detecção de gás ou fumaça, ou conforme configuração para presença.

Microcontrolador para Display: Atualiza os valores medidos pelo sensor de temperatura no display.



## Especificações 

### Especificação Estrutural

#### Sensores 

Sensores de Presença:
O sensor escolhido é o HC-SR501, um sensor infravermelho com alimentação recomendada de 5V DC. Sua saída é um pulso digital: 1 (3,3V) quando detecta movimento e 0 (0V) quando não há movimento. A sensibilidade do sensor é configurável, permitindo distinguir entre a movimentação de objetos e de pessoas. O principal motivo para sua escolha é o alcance, que chega a 7 metros, com um ângulo de 120 graus, permitindo cobrir todo o cômodo e uma parte principal do quintal ou da entrada da casa. O sensor possui um baixo consumo de energia, aproximadamente 65mA, e funciona em uma faixa de temperatura de -20 a 80 graus Celsius, sendo adequado para uso no Brasil e em outras regiões com condições climáticas variadas.

Sensor de Gás e Fumaça:
O sensor escolhido é o MQ-2 possui alimentação recomendada de 5V DC, ele monitora ocorrências de vazamento de gás e de fumaça, sendo especialmente benéfico para nosso projeto em áreas como a cozinha. O ajuste de sensibilidade é feito via potenciômetro, facilitando seu uso. Possui analógica baseada na variação de resistencia sendo necessário um conversor ADC, permitindo uma comunicação mais simples com a unidade de controle. Consome pouca energia, contribuindo para a eficiência energética do sistema. É um sensor de baixo custo, o que é vantajoso para a viabilidade econômica do projeto.

Sensor de Temperatura

O sensor escolhido é o  DS18B20, um sensor de temperatura . Ele possui uma alimentação recomendada de 5V DC e sua saída é digital, com uma resolução de 9 a 12 bits.
O DS18B20 tem uma faixa de medição que vai de -55 a +125 graus Celsius. O principal motivo para a escolha deste sensor é sua precisão de ±0,5 graus nas medições de -10 a 80 graus Celsius, podendo ter uma resolução maior ao escolher a quantidade de bits de comunicação, que atende aos requisitos do nosso projeto, além de possuir o protocolo One-Wire, no qual é possível conectar varios sensores na mesma porta digital, podendo assim ser mais facil para espandir o projeto. 

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/28c4457c-86fc-479e-9f09-121f3273a25b)


#### Atuadores

Painel de LEDs: O sistema proposto consiste em um Painel de LEDs para identificação visual de movimentação em cada cômodo da casa, com base nas informações dos sensores de presença. Quando movimento é detectado em um determinado cômodo, os LEDs correspondentes a esse cômodo são acionados, permitindo uma visualização rápida da atividade em diferentes áreas da casa.

Alarme Sonoro: um Alarme Sonoro será ativado em caso de possíveis invasões quando os donos não estiverem na residência, ou se for identificada uma alta concentração de fumaça ou gás de cozinha. Isso fornecerá um alerta audível para os ocupantes da casa ou para vizinhos, indicando uma situação de emergência.
Teremos 2 diferentes alarmes sonoros, 1 será um buzzer piezoelétrico ativo, que será alimentado quando o sensor de gâs/fumaça detectar a presença de qualquer um, acionando um alarme sonoro e ativando um LED correspondente a onde ele detectou esse gâs. O sistema de segurança contará com o alto-falante Visaton SC 5.9 que permitirá um alarme potente ser acionado junto com o uso de um relê para a ativação do mesmo.

Display LCD: um Display será utilizado para exibir a temperatura medida pelo sensore de temperatura. Isso permitirá que os ocupantes monitorem a temperatura em tempo real, o que pode ser útil para garantir o conforto e a segurança, especialmente em situações como controle de temperatura ambiente ou detecção de superaquecimento em determinadas áreas.


#### Microcontrolador

O microcontrolador escolhido é o ATmega32, um microcontrolador AVR de 8 bits. Ele possui uma capacidade de memória flash de 32 KB, 2 KB de SRAM e 1 KB de EEPROM, oferecendo espaço suficiente para o armazenamento do código e dos dados necessários para o nosso sistema e inclusive um pouco mais caso for desejada expansão no futuro. Ele opera a uma velocidade de clock de até 16 MHz e suporta uma ampla gama de periféricos, incluindo conversores ADC de 10 bits, PWM, timers/counters, interfaces de comunicação SPI, USART e I2C. Com 32 linhas de I/O programáveis, ele permite a conexão de múltiplos sensores e atuadores, tornando-o altamente versátil para diversas aplicações. O ATmega32 também é conhecido por suas características de baixo consumo de energia, suporte a modos de economia de energia e ampla faixa de tensão de operação de 4.5V a 5.5V. A extensa documentação, bibliotecas disponíveis e a grande comunidade de desenvolvedores AVR facilitam o desenvolvimento e a implementação de novas funcionalidades.



### Especificação de Algoritmos 

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165414259/e3c52f2f-ec1e-4222-b857-c56fa12b6fc0)

Para o sensor de presença, é necessário apenas 1 bit para identificar a movimentação. Considerando que serão utilizados 6 sensores distribuídos pela casa (2 quartos, 1 banheiro, 1 sala de estar, 1 cozinha e 1 quintal), serão necessários 6 bits de memória para registrar os dados desses sensores.
Além disso, será necessário 1 bit adicional de memória para o alarme sonoro e mais 6 bits para a ativação do painel de LEDs.
Portanto, no total, serão necessários 13 bits de memória para armazenar o estado dos sensores de presença, ativar o alarme sonoro e controlar o painel de LEDs.

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165414259/9875c154-cf96-4b50-a5e2-d5c835bcde4e)

Para o sensor de gás e fumaça, juntamente com um conversor ADC, precisaremos de 1 bit para identificar se há alta concentração de gás/fumaça ou não. Considerando que serão utilizados 5 sensores distribuídos pela casa (2 quartos, 1 cozinha, 1 sala de estar e 1 banheiro), será necessário 5 bits de armazenamento para registrar os dados desses sensores. Além disso, será necessário 1 bit adicional para ativar o alarme sonoro.
Portanto, no total, precisaremos de 6 bits de memória para armazenar o estado dos sensores de gás e fumaça, bem como para ativar o alarme sonoro.

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165414259/1a6b275f-ee80-4e4d-a321-b54577b86b2a)

Os sensores de temperatura comunicam-se utilizando 9 até 12 bits de dados. Considerando que planejamos utilizar 1 sensor necessitaremos de apenas 9 bits que será suficiente para termos uma boa precisão
Além disso, contamos com um display de LCD em nosso sistema. que requer 32 bits para armazenar os dados a serem exibidos. Portanto, o total de bits necessários, incluindo os dados dos sensores e os dados a serem exibidos nos displays, será de 41 bits.

Pensando no uso de bibiotecas e código base temos que será necessário cerca de 10Kbytes de memória ROM, para as variaveis envolvendo variaveis globais para armazenamento de dados dos sensores e buffers para o display LCD aproximadamente 1,5Kbyte será necessário de memória RAM




## Referências

https://components101.com/sensors/hc-sr501-pir-sensor (Sensor movimento hc-Sr 501)

https://www.mouser.com/datasheet/2/321/605-00008-MQ-2-Datasheet-370464.pdf (Sensor de Gás e Fumaça)

https://pdf1.alldatasheet.com/datasheet-pdf/view/227472/DALLAS/DS18B20.html (Sensor de Temperatura)

https://components101.com/diodes/5mm-round-led (LED)

https://www.usinainfo.com.br/buzzer/buzzer-ativo-5v-bip-continuo-pci-12mm-2988.html (Buzzer Piezoelétrico)

https://www.visaton.de/en/products/drivers/fullrange-systems/sc-59-om-8-ohm (alto-falante Visaton SC 5.9)

https://ww1.microchip.com/downloads/en/DeviceDoc/doc2503.pdf (ATMega32)


