# Tabela de Componentes

| Nome | Interface | Datasheet | Motivo |
|--|--|--|--|
| Display LCD-016N002B | - |  [display](https://www.vishay.com/docs/37484/lcd016n002bcfhet.pdf) | Menor display (16x2) que atende as mensagens que deseja-se mostrar e com menor custo, quando comparado a displays OLED, por exemplo. |
| PCF8574A | I2C | [PCF8574A](https://www.ti.com/lit/ds/symlink/pcf8574a.pdf) | Circuito integrado necessário para possibilitar a comunicação I2C com o display LCD. |
| Buzzer ativo | - | [buzzer](datasheets/DatasheetBuzzer.pdf) | Apenas para realizar um aviso simples, buzzer ativo para não precisar gerar uma onda PWM como entrada |
| Transistor PN2222A | base conectada à porta GPIO | [PN2222A](https://users.ece.utexas.edu/~valvano/Datasheets/PN2222-D.pdf) | Para controle do buzzer, como chave liga e desliga, de forma que a corrente necessária não seja fornecida diretamente pela MCU. |
| GPS NEO-6M | I2C | [gps](https://content.u-blox.com/sites/default/files/products/documents/NEO-6_DataSheet_%28GPS.G6-HW-09005%29.pdf) | Dispositivo simples de GPS e com precisão suficiente para o projeto, existem variações na família porém a de pior velocidade e resolução já excede o que é necessário para o projeto. |
| Antena ativa para GPS | RF | [Antena](https://www.mouser.com/datasheet/2/447/Yageo_04_18_2024_ANT1212JB27B1575A-3440976.pdf) | Antena que cumpre os requisitos de ganho e de ruído especificados pelo datasheet do chip GPS NEO-6M. Sinal enviado por conector coaxial. |
| Bússula de três eixos (HMC5883L) | I2C | [bussola](datasheets/DatasheetBussola.PDF) | Baixo custo e precisão suficiente para que a torre seja capaz de distinguir entre as duas direções da pista. |
| ELM327 | USB | [ELM327](datasheets/DatasheetELM327.PDF) | Dispositivo mais comum para este tipo de interface com o carro pela porta ODB. Utilizado para obter com precisão a velocidade do veículo. |
| CP2120N | USB, USART | [CP2120N](https://www.mouser.com/datasheet/2/368/cp2102n_datasheet-1634912.pdf) | Conversor de comunicações seriais USB para USART. Será utilizado para converter o sinal USB enviado pelo modulo ELM327 para a interface USART, para ser lido pelo microcontrolador. |
| ATtiny202 | USART, I2C e GPIO | [ATtiny202](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATtiny202-04-402-04-06-Auto-DataSheet-DS40002159A.pdf) | Microcontroladora com capacidade de processamento adequada, memória de 128B de ram e 2kB de memória flash, quantidades de pinos suficientes para as interfaces de comunicação USART, I2C e GPIO. |

## Observações adicionais

### Uso dos circuitos
Dos dispositivos e circuitos integrados inseridos na tabela, dois deles não serão utilizados de forma direta, mas como parte de um outro produto, que se conecta ao sistema embarcado projetado. São eles:

- ELM327 é o circuito integrado responsável pelo gerenciamento da comunicação com a porta OBD2, no entanto é necessário um conector para se encaixar diretamente nesta porta. Optamos então por um [produto](https://pt.aliexpress.com/item/1005004078281314.html) que contém já o chip e possibilita a comunicação por uma interface USB, desta também será obtida a energia necessária para ligar os outros componentes do sistema.

![Produto ELM327, interface USB](imgs/produto_elm327.png)

- O chip da bússula de 3 eixos exige um circuito relativamente complexo para ser conectado ao resto do circuito, em parte devido ao seu funcionamento em 1.8V. Optamos por utilizar um [produto](https://pt.aliexpress.com/item/1005006291063452.html) que implementa o circuito necessário. Em nosso sistema, há um conector para um dispositivo como esse.

![Circuito com chip da bússula de 3 eixos](imgs/produto_bussula.png)

### Energização do sistema

No sistema, existem componentes que precisam de uma alimentação de 5V e outros que precisam de 3v3, ou aceitam faixas de tensão que incluem algum desses valores. O sistema receberá energia através da interface USB, que provê 5V.

Além disso, o circuito integrado utilizado para realizar a conversão USB-UART (CP2120N) conta com um regulador da tensão recebida no USB para 3v3, portanto estas duas linhas serão utilizadas para fornecer alimentação ao resto dos componentes, não sendo necessária a adição de um circuito dedicado para isto.

### Circuito Buzzer

Para o projeto do circuito de controle do Buzzer mediado pelo transistor PN2222A foi necessário utilizar um resistor entre a base do transistor e o pino GPIO para limitar a corrente, o cálculo de sua resistência pode ser visto abaixo.

Corrente do buzzer ativo = 30 mA = Ic

De acordo com o datasheet, neste ponto de operação, temos hfe = aprox 50

Então a corrente de base é Ib = Ic / hfe = 0.6 mA

Logo, é necessário o seguinte resistor de base

Rb = (Vgpio - Vb) / Ib = (3.3V - 0.7V) / 0.6mA = 4.3 k Ohm
