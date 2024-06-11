# Tabela de Componentes

| Nome | Interface | Datasheet | Motivo |
|--|--|--|--|
| Display | I2C |  [display](https://www.handsontec.com/dataspecs/module/I2C_1602_LCD.pdf) | Menor display que atende as mensagens que deseja-se mostrar e com menor custo, quando comparado a displays OLED, por exemplo. |
| Buzzer ativo | GPIO | [buzzer](datasheets/DatasheetBuzzer.pdf) | Apenas para realizar um aviso simples, buzzer ativo para não precisar gerar uma onda como entrada |
| GPS | I2C | [gps](https://content.u-blox.com/sites/default/files/products/documents/NEO-6_DataSheet_%28GPS.G6-HW-09005%29.pdf) | Dispositivo simples de GPS e com precisão suficiente para o projeto, existem variações na família porém a de pior velocidade e resolução já excede o que é necessário para o projeto. |
| Bússula de três eixos | I2C | [bussola](https://pdf1.alldatasheet.com/datasheet-pdf/download/428790/HONEYWELL/HMC5883L.html) | Baixo custo e precisão suficiente para que a torre seja capaz de distinguir entre as duas direções da pista. |
| ELM327 | USB | [ELM327]() | Dispositivo mais comum para este tipo de interface com o carro pela porta ODB |
| ATtiny204 | USART, I2C e GPIO | [ATtiny204](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATtiny202-04-402-04-06-Auto-DataSheet-DS40002159A.pdf) | Microcontroladora com capacidade de processamento adequada, memória de 128B de ram e 2kB de memória flash, quantidades de pinos suficientes para as interfaces de comunicação USART, I2C e GPIO.
| CI USB para UART |



Ainda é necessário definir um circuito integrado para realizar a conversão de USB para UART
