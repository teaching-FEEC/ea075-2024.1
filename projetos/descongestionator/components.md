# Tabela de Componentes

| Nome | Interface | Datasheet | Motivo |
|--|--|--|--|
| Display LCD-016N002B | - |  [display](https://www.vishay.com/docs/37484/lcd016n002bcfhet.pdf) | Menor display que atende as mensagens que deseja-se mostrar e com menor custo, quando comparado a displays OLED, por exemplo. |
| Buzzer ativo | GPIO | [buzzer](datasheets/DatasheetBuzzer.pdf) | Apenas para realizar um aviso simples, buzzer ativo para não precisar gerar uma onda como entrada |
| GPS | I2C | [gps](https://content.u-blox.com/sites/default/files/products/documents/NEO-6_DataSheet_%28GPS.G6-HW-09005%29.pdf) | Dispositivo simples de GPS e com precisão suficiente para o projeto, existem variações na família porém a de pior velocidade e resolução já excede o que é necessário para o projeto. |
| Bússula de três eixos | I2C | [bussola](datasheets/DatasheetBussola.PDF) | Baixo custo e precisão suficiente para que a torre seja capaz de distinguir entre as duas direções da pista. |
| ELM327 | USB | [ELM327](datasheets/DatasheetELM327.PDF) | Dispositivo mais comum para este tipo de interface com o carro pela porta ODB |
| ATtiny204 | USART, I2C e GPIO | [ATtiny204](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATtiny202-04-402-04-06-Auto-DataSheet-DS40002159A.pdf) | Microcontroladora com capacidade de processamento adequada, memória de 128B de ram e 2kB de memória flash, quantidades de pinos suficientes para as interfaces de comunicação USART, I2C e GPIO.
| CP2120N | USB, USART | [CP2120N](https://www.mouser.com/datasheet/2/368/cp2102n_datasheet-1634912.pdf) | Conversor de comunicações seriais USB para USART. Será utilizado para converter o sinal USB enviado pelo modulo ELM327 para a interface USART, para ser lido pelo microcontrolador.  
| PCF8574A | I2C | [PCF8574A](https://www.ti.com/lit/ds/symlink/pcf8574a.pdf) | Circuito integrado necessário para a comunicação I2C com o display LCD.  
