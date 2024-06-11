# Tabela de Componentes

| Nome | Interface | Datasheet | Motivo |
|--|--|--|--|
| Display | I2C |  [display](https://www.handsontec.com/dataspecs/module/I2C_1602_LCD.pdf) | Menor display que atende as mensagens que deseja-se mostrar e com menor custo, quando comparado a displays OLED, por exemplo. |
| Buzzer ativo | GPIO | [buzzer](datasheets/DatasheetBuzzer.pdf) | Apenas para realizar um aviso simples, buzzer ativo para não precisar gerar uma onda como entrada |
| GPS | I2C | [gps](https://content.u-blox.com/sites/default/files/products/documents/NEO-6_DataSheet_%28GPS.G6-HW-09005%29.pdf) | Dispositivo simples de GPS e com precisão suficiente para o projeto, existem variações na família porém a de pior velocidade e resolução já excede o que é necessário para o projeto. |
| Bússula de três eixos | I2C | [bussola](datasheets/DatasheetBussola.PDF) | Baixo custo e precisão suficiente para que a torre seja capaz de distinguir entre as duas direções da pista. |
| ELM327 | USB | [ELM327](datasheets/DatasheetELM327.PDF) | Dispositivo mais comum para este tipo de interface com o carro pela porta ODB |
| ATtiny204 | USART, I2C e GPIO | [ATtiny204](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATtiny202-04-402-04-06-Auto-DataSheet-DS40002159A.pdf) | Microcontroladora com capacidade de processamento adequada, memória de 128B de ram e 2kB de memória flash, quantidades de pinos suficientes para as interfaces de comunicação USART, I2C e GPIO.
| CI USB para UART |
| Fontes? |


Ainda é necessário definir um circuito integrado para realizar a conversão de USB para UART:

https://www.robocore.net/placa-robocore/conversor-usb-uart-serial?gad_source=1&gclid=CjwKCAjw65-zBhBkEiwAjrqRMObe5zUvp36WrZWvNaRK8-VYZHb3ZwGSFpaqQcBzrzoXxW0TxdiKfxoCj0wQAvD_BwE

https://produto.mercadolivre.com.br/MLB-888531608-modulo-conversor-usb-serial-rs232-ttl-pl2303hx-arduino-mini-_JM?matt_tool=40343894&matt_word=&matt_source=google&matt_campaign_id=14303413655&matt_ad_group_id=133855953276&matt_match_type=&matt_network=g&matt_device=c&matt_creative=584156655519&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=548401642&matt_product_id=MLB888531608&matt_product_partition_id=2268053647630&matt_target_id=pla-2268053647630&cq_src=google_ads&cq_cmp=14303413655&cq_net=g&cq_plt=gp&cq_med=pla&gad_source=1&gclid=CjwKCAjw65-zBhBkEiwAjrqRMHxyvLDfR1NV82ms9TZJ7FPBEV66p5uODvTE4HwpQpcpa17BDAimyhoCyLQQAvD_BwE

https://br.mouser.com/ProductDetail/FTDI/USB-RS232-PCBA?qs=KXh8wMBzxN%2FcahZl632E2w%3D%3D&mgh=1&utm_id=17633168520&gad_source=1&gclid=CjwKCAjw65-zBhBkEiwAjrqRME8nWklg6pf99nYnWpxOPDH2SaXTflr8HpTJLm8EiDGeOq3wnI2biBoCLJ0QAvD_BwE
