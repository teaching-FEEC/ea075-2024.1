# `Monitor de Vagas de Estacionamento`
# `Parking Lots Monitor`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Eduardo Pereira Tejada  | 183451  | Eng. Elétrica|
| Gabriel Dias Vasconcelos  | 248134  | Eng. Elétrica|


## Arquivos Importantes
[PDF do Esquemático](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Esquem%C3%A1tico.pdf)

[PDF da PCB](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/PCB.pdf)

Print do projeto da PCB no Altium Designer:
![Print do projeto da PCB no Altium Designer](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/PCB_img.png?raw=true)

## Descrição do Projeto
O projeto visa solucionar o problema de encontrar espaços de estacionamento disponíveis. Oferecendo uma solução automatizada e inteligente para melhorar a experiência dos usuários, bem como a eficiência no uso das vagas. Podem se beneficiar dessa ideia diversos estabelecimentos comerciais como shoppings e supermercados e ainda leva vantagens aos motoristas individuais. O monitor de vagas agrega valor econômico às empresas aumentando o fluxo de clientes, que perderão menos tempo presos no estacionamento procurando um lugar vago e portanto ficarão mais propensos à retornarem ao estabelecimento futuramente, além poder vir a ser útil para a segurança e extração de dados sobre o padrão de uso do estacionamento.


## Descrição Funcional
O sistema de controle de vagas de estacionamento opera em uma lógica de sensores de proximidade em campo que se comunicam com uma central de comandos conectada a um painel de led encarregado de mostrar o número de vagas disponíveis na totalidade do recinto. os sensores em campo utilizam de comunicação via ondas de rádio LoRa para com a central, dessa forma, os riscos de danificação do sistema por intempéries a fiações é minimizado, já que a maior parte das conexões físicas são por parte das conexões dos dispositivos na placa de circuito impressa. É também um projeto de baixa necessidade de mantenção e configuração, operando sempre em uma mesma lógica.
![Diagrama funcional do sistema](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Diagrama_funcional_vf.drawio.png)


### Funcionalidades
O sistema deve ser capaz de identificar quais vagas estão ocupadas através de um sensor de presença, computar quantos espaços ainda se encontram disponíveis e reportar esses resultados para os usuários do estacionamento através de um painel LED.

### Eventos
Evento 1: novo carro solicitar um lugar pra estacionar;\
Evento 2: carro desocupar uma vaga do estacionamento;\
Evento 3: estacionamento lotado;\
Evento 4: estacionamento deixa de estar lotado.

### Tratamento de Eventos
Evento 1: verificar se existem vagas disponíveis, reportar o resultado e marcar a vaga como ocupada;\
Evento 2: registrar vaga como liberada no sistema;\
Evento 3: na entrada, reportar que o estacionamento está lotado direcionando para um estacionamento na rua;\
Evento 4: reportar a liberação de vagas na entrada.

## Descrição Estrutural do Sistema
1. Sensores de Ultrassom Detectam a presença ou ausência de veículos no estacionamento
2. Módulos de Comunicação LoRa Transmitem os dados enviados pela MCU à central de comando via ondas de rádio
3. Central de Comandos gerenciada pelo MCU pic16f877a trata os dados enviados pelas unidades LoRa em campo e envia sinais para o painel de LED
4. Painel de LED exibe o número de vagas disponíveis no setor especificado do estacionamento fornecendo uma interface visual para os motoristas
5. Alimentação e Infraestrutura Elétrica individual para cada subsistema por baterias
![Diagrama de blocos do sistema](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Descri%C3%A7%C3%A3o%20Estrutural%20do%20Sistema%20(1).jpg?raw=true)

## Especificações

### Especificação Estrutural

#### Sensores detectores de vaga

Existem diversas maneiras de fazer a verificação acerca de quais vagas estão ou não disponíveis no estacionamento em um determinado momento, tais como: sensor ultrassônico, infravermelho, magnético, entre outros. O projeto visa atuar principalmente em ambientes externos, portanto lida com variações de luz, temperatura e umidade. Com isso, acredita-se que o candidato que melhor se adequa aos requisitos é o sensor ultrassônico, que lida bem com as variações citadas possuindo um baixo custo.
O modelo escolhido de sensor ultrassônico escolhido foi o HC-SR04 dado sua alta disponibilidade no mercado, confiabilidade, precisão, facilidade na programação e o seu preço. É importante ressaltar, contudo, que o sensor não possui uma resistência mecânica suficiente para ser usado em ambiente externo, é necessário envolvê-lo com uma caixa.
O princípio de funcionamento do sensor ultrassônico é simples, ele envia um pulso ultrassônico que bate em um determinado objeto a uma distância D e volta para o receptor. Sabendo a velocidade do som V e o tempo T que leva para o pulso ir e voltar até o receptor é possível estimar a distância do objeto encontrado por D = V / (T/2).
![Sensor Ultrassônico](https://cdn.shopify.com/s/files/1/0559/1970/6265/files/Blog_Images_90d67d8f-efb0-4d0d-ada5-4bf17847f6cd_2048x2048.gif?v=1715342134)

#### Atuadores

Precisa-se de um atuador para mostrar a quantidade de vagas na entrada do estacionamento. Diferente dos sensores, não há uma pluralidade de opções. Foram escolhidos dois displays de 7 segmentos para reportar um número de 00 a 99, possuem baixo custo, facilidade de uso e dispõem de boa visibilidade.

![Display de 7 segmentos](https://www.msseletronica.com.br/imagens/976_203.gif)

#### Comunicação sensor - MCU

É possível fazer a comunicação dos sensores ultrassônicos com o microcontrolador principal por fio, porém, a depender do tamanho do estacionamento seria caro, os fios podem se romper mais facilmente com o tempo, entre outros problemas.
Portanto, dentre outras possibilidades foi escolhido o módulo de comunicação LoRa da empresa EBYTE, que possui uma tecnologia de comunicação sem fio que funciona através de rádio frequência e um software de configuração próprio, além de bibliotecas para seu uso com a IDE do arduino. Esse módulo utiliza comunicação serial UART para comunicação com microcontrolador e possui dois pinos de configuração de quatro estados: normal; apenas recepção; economia de energia e sleep mode/configuração.

![Módulo LoRa](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Screenshot%20from%202024-05-23%2020-29-21.png?raw=true)
![LoRa Dimensões](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/dimensoes_LoRa.png?raw=true)
![Exemplo código transmissor](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/transmissor.png?raw=true)

#### Microcontrolador

Como é possível verificar na seção de Especificação de Algoritmos, estima-se que o código em questão não precisa de grandes memórias tanto de programa quanto de dados. Além disso, o sistema em questão não é crítico, precisa ser capaz de enviar e receber os pulsos de TRIG e ECHO de múltiplos sensores ultrassônicos (no mínimo 10 μS) e também de enviar e receber dados através dos módulos LoRa. Compilamos na IDE do Arduino um código de transmissão de dados e outro de recepção, com uma biblioteca otimizada para o módulo e uma biblioteca de configuração de portas seriais e o resultado foi códigos que ocupam em média 8300 bytes de memória. Como o sistema não precisa lidar com armazenamento de um grande número de dados, é possível utilizar microcontroladores mais simples. Dados os requisitos do projeto, a família de MCU’s que melhor se adequa são processadores de entrada de famílias como a Intel 8051 ou os PIC’s produzidos pela Microchip Technology, por serem simples e efetivos. A escolha do microcontrolador PIC16F877A se alinha com os requisitos de simplicidade, eficiência e baixo custo do projeto. Sua ampla gama de funcionalidades e a capacidade de memória o tornam uma escolha robusta e adequada para o sistema de controle de vagas de estacionamento, garantindo a operação eficiente e confiável dos sensores ultrassônicos e módulos de comunicação LoRa.
A escolha do microcontrolador PIC16F877A se alinha com os requisitos de simplicidade, eficiência e baixo custo do projeto. Sua ampla gama de funcionalidades e a capacidade de memória o tornam uma escolha robusta e adequada para o sistema de controle de vagas de estacionamento, garantindo a operação eficiente e confiável dos sensores ultrassônicos e módulos de comunicação LoRa. o microcontrolador possui 14KB de memória flash, apresentando certa margem de programação além dos 8KB estipulados para o código do LoRa, também possui oscilador interno capaz de operar em 20MHz, viabilizando a comunicação com o sensor ultrassônico.


#### Diagrama
![Diagrama da Especificação Estrutural](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Especifica%C3%A7%C3%A3o%20Estrutural.jpg?raw=true)

### Especificação de Algoritmos 
![Fluxograma](https://github.com/EduardoTejada/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/Especifica%C3%A7%C3%A3o%20do%20Algoritmo.jpg?raw=true)

## Referências
  Notas de aula de EA075 \
  https://www.sofit4.com.br/blog/controle-de-entrada-e-saida-de-veiculos/ \
  https://autopark.com.br/tecnologia-e-automatizacao-para-estacionamentos/
  https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
  https://www.handsontec.com/dataspecs/HC-SR04-Ultrasonic.pdf
  https://cdn.standards.iteh.ai/samples/5500/6b28378512604ff7bdaace506be7dc0c/ISO-1028-1973.pdf
  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
  https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus
  https://en.wikipedia.org/wiki/ATmega328
  https://robocraze.com/blogs/post/what-is-ultrasonic-sensor
  https://www.msseletronica.com.br/detalhes/display-de-7-segmentos-0-56-catodo-comum-vermelho-gnd-comum_pid976.html
  https://www.cdebyte.com/pdf-down.aspx?id=3044
  https://www.ti.com/lit/ds/symlink/cd4511b.pdf
  https://www.build-electronic-circuits.com/4000-series-integrated-circuits/ic-4511/
  https://cdn.awsli.com.br/945/945993/arquivos/E220-900T22D_UserManual_EN_v1.0.pdf
  https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/39582C.pdf
  https://www.theengineeringprojects.com/2015/03/pic-microcontroller-projects.html
  
