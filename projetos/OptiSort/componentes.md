# Optisort: Componentes
## Componentes Principais
* **STM32H747AII6 (UFGBA169)**: O microcontrolador utilizado dentro deste projeto, escolhido pelos mótivos apresentados na descrição estrutural. url: https://www.alldatasheet.com/datasheet-pdf/pdf/1277966/STMICROELECTRONICS/STM32H747AIT6TR.html
* **GC2145**: Câmera de luz visível. Foi escolhido utilizar a versão retirada do módulo Arducam-GC2145 pelo fato que ela fornece uma pinagem mais organizada e pronta para ser acoplada na nossa placa.
url_camera: https://www.uctronics.com/download/Datasheet/Arducam-GC2145.pdf
url_arducam: https://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/968/GC2145-CSP-DataSheet-release-V1.0_5F00_20131201.pdf
* **FLIR Lepton 2.5**: Câmera de luz infravermelho. url: https://flir.netx.net/file/asset/13333/original/attachment
* **MAX485EESA+**: Escolhido devido a ser o componente utilizado para o projeto de módulos comuns de interface entre TTL e RS485. Esta versão foi escolhida pelo fato de ser SMD, com um empacotamento SOIC-8, que irá permitir sua implementação direta no esquemático. url: https://www.analog.com/media/en/technical-documentation/data-sheets/MAX1487E-MAX491E.pdf 

## Componentes de conexão:
* **Borne 3T (5,08mm)**: Escolhido por possuir o pitch de 5,08 mm especificamente, o que permitiu sua inclusão no projeto sem necessidade de desenvolver um footprint próprio. url: https://www.phoenixcontact.com/en-us/products/printed-circuit-board-terminal-mkkdsnh-15-3-508-1731831?type=pdf
* **Borne 2T (5,08mm)**: Escolhido por possuir o pitch de 5,08 mm. url: https://www.phoenixcontact.com/en-us/products/printed-circuit-board-terminal-mkdsn-15-2-508-1729128?type=pdf

## Componentes Eletrônicos
* **Resistor CRCW060322R1FKEA (22,1Ω)**: Escolhido por conta do seu tamanho (0603 pol). Sua classificação energética (100mW) não será atingida pelos circuitos que ele liga. url: https://www.vishay.com/docs/20035/dcrcwe3.pdf
* **Resistor CRCW0201110RFKED (110Ω)**: Escolhido por conta do seu tamanho (0603 pol). Sua classificação energética (50mW) não será atingida pelos circuitos que ele liga. url: https://www.vishay.com/docs/20052/crcw0201e3.pdf
* **Resistor CRCW0201464RFKED (464Ω)**: Escolhido por conta do seu tamanho (0603 pol). Sua classificação energetica (50mW) não será atingida pelos circuitos que ele liga. url: https://www.vishay.com/docs/20052/crcw0201e3.pdf
* **Resistor CRCW060310K0JNEAHP (10kΩ)**: Escolhido por conta do seu tamanho (0603 pol). Sua classificação energética (330mW) muito dificilmente será atingida pelos circuitos que ele liga. Neste projeto ele é bastante usado como resistor de pull-down de um sinal. url: https://www.vishay.com/docs/20035/dcrcwe3.pdf
* **Resistor CRCW0603100KFKEE (100kΩ)**: Escolhido por conta do seu tamanho (0603 pol). Sua classificação energética (330mW) muito dificilmente será atingida pelos circuitos que ele liga. url: https://www.vishay.com/docs/20035/dcrcwe3.pdf
* **Capacitor MLAST105SB5104KFNA01 (0,1uF)**: Escolhido por ter encapsulamento SMD, pelo seu tamanho (0402 pol) e por suportar as tensões com as quais ele terá contato. url: https://br.mouser.com/datasheet/2/396/ML_mlcc_all_e-3369844.pdf
* **Capacitor TMK105BJ105MV-F (1uF)**: Escolhido por ter encapsulamento SMD, pelo seu tamanho (0402 pol) e por suportar as tensões com as quais ele terá contato. url: https://br.mouser.com/datasheet/2/396/mlcc02_e-1307760.pdf
* **Capacitor MLASE105AB5225KFNA01 (2,2uF)**: Escolhido por ter encapsulamento SMD, pelo seu tamanho (0402 pol) e por suportar as tensões com as quais ele terá contato. url: https://br.mouser.com/datasheet/2/396/ML_mlcc_all_e-3369844.pdf
* **Capacitor JMK105BBJ475MV8F (4,7uF)**: Escolhido por ter encapsulamento SMD, pelo seu tamanho (0402 pol). Este componente tem como regime de tensão 6,3V. url: https://br.mouser.com/datasheet/2/396/mlcc06_hq_AUTO_e-1901145.pdf
* **Capacitor MEASJ105CB5106MF1A01 (10uF)**: Escolhido por ter encapsulamento SMD, pelo seu tamanho (0402 pol). Interessantemente, este capacitor tem como foco ser usado em dispositivos móveis. url: https://br.mouser.com/datasheet/2/396/Taiyo_Yuden_2_8_2024_MEASJ105CB5106MF1A01_SS-3395943.pdf
* **Diodo 1N4148W-7-F**: Escolhido para ser usado com diodo flyback, ele aguenta a tensão de operação do solenoide (12V). Seu empacotamento é url: https://br.mouser.com/datasheet/2/115/ds30086-3214660.pdf
* **Transistor MOS FQP30N06L**: Escolhido para realizar o chaveamento do sinal que controla o solenoide do pistão pneumático. Sua tensão de ativação (2,0V), que é baixa o suficiente como para ser controlado mediante lógica TTL. url: https://br.mouser.com/datasheet/2/308/1/FQP30N06L_D-2314160.pdf

  
## Bill of Materials
Todos os sites foram acessados em 24/06/2024.
* *STM32H747AII6*: $18,74 url: https://br.mouser.com/ProductDetail/STMicroelectronics/STM32H747AII6?qs=vLWxofP3U2xKTIBLp63b7g%3D%3D
* *Arducam GC2145*: $6,99 url: https://www.arducam.com/product/2mp-gc2145-color-dvp-camera-module-for-arduino-giga-r1-wifi-board/
* *FLIR Lepton 2.5*: $209.95 url: https://www.sparkfun.com/products/16465
* *MAX485EESA+*: $6,78 url: https://br.mouser.com/ProductDetail/Analog-Devices-Maxim-Integrated/MAX487EESA%2b?qs=1THa7WoU59F%252BN4QTTVMhEw%3D%3D
* *Borne 2T*: $0,77 url: https://br.mouser.com/ProductDetail/Phoenix-Contact/1729128?
* *Borne 3T*: $1,74 url: https://br.mouser.com/ProductDetail/Phoenix-Contact/1731831?qs=o3rrLWFGhRnv%252Ba3%2FC%252B10UQ%3D%3D
* *Resistor 22,1*: $0,10 url: https://br.mouser.com/ProductDetail/Vishay-Dale/CRCW060322R1FKEA?qs=zWI4UZgPOoTm0WgHtMVBQw%3D%3D
* *Resistor 110*: $0,22 url: https://br.mouser.com/ProductDetail/Vishay-Dale/CRCW0201110RFKED?qs=3bSaU8eFeoF0Lvza98Drvw%3D%3D
* *Resistor 464*: $0,25 url: https://br.mouser.com/ProductDetail/Vishay-Dale/CRCW0201464RFKED?qs=3bSaU8eFeoHkvoGgNiUkCQ%3D%3D
* *Resistor 10k*: $0,10 url: https://br.mouser.com/ProductDetail/Vishay-Dale/CRCW060310K0JNEAHP?qs=k2%2FDWSARqgH8Om6O4X312A%3D%3D
* *Resistor 100k*: $0,10 url: https://br.mouser.com/ProductDetail/Vishay-Dale/CRCW0603100KFKEE?qs=%252B6g0mu59x7I1D%252BO0qMg%252Bjg%3D%3D
* *Capacitor 0.1uF*: $0,10 url: https://br.mouser.com/ProductDetail/TAIYO-YUDEN/MLAST105SB5104KFNA01?qs=tlsG%2FOw5FFgoCYoXnQxViA%3D%3D
* *Capacitor 1uF*: $0,10 url: https://br.mouser.com/ProductDetail/TAIYO-YUDEN/TMK105BJ105MV-F?qs=%252BAZVS4b%2FkgIaRFkNK4F9Wg%3D%3D
* *Capacitor 2,2uF*: $0,16 url: https://br.mouser.com/ProductDetail/TAIYO-YUDEN/MLASE105AB5225KFNA01?qs=tlsG%2FOw5FFj9m%252Br72rkbgg%3D%3D
* *Capacitor 4,7uF*: $0,16 url: https://br.mouser.com/ProductDetail/TAIYO-YUDEN/JMK105BBJ475MV8F?qs=hWgE7mdIu5TAqzIi0KjAXw%3D%3D
* *Capacitor 10uF*: $0,19 url: https://br.mouser.com/ProductDetail/TAIYO-YUDEN/MEASJ105CB5106MF1A01?qs=Z%252BL2brAPG1LB%252BwvREar%252BZA%3D%3D
* *Diodo 1N4148W-7-F*: $0,13 url: https://br.mouser.com/ProductDetail/Diodes-Incorporated/1N4148W-7-F?qs=LHX0FizJzg7Ae9ZM8LTAWw%3D%3D&utm_id=12168397652&gad_source=1&gclid=Cj0KCQjwsuSzBhCLARIsAIcdLm6crf8T9OdxRbaR2RrF6ghz7rSSXXY6n8mEHdbXS6ePBsVzwyIpTXYaAqM_EALw_wcB
* *Transistor MOS FQP30N06L*: $0,78 url: https://www.makerhero.com/produto/transistor-mosfet-fqp30n06l-60v/



