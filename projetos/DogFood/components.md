# Lista de componentes elétricos utilizados para montagem do projeto:

## Obtenção de peso/sensor de peso:
 - Célula de carga fina + Amplificador de instrumentação HX711 ( Protocolo 2 - Wire Serial).
   - [Link datasheet do Chip](datasheets/Célula_carga_fina_HX711.pdf).
   - [Link do produto no AliExpress - célula e sensores](https://pt.aliexpress.com/item/1005002937997868.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005002937997868&netw=x&device=c&albpg=&albpd=pt1005002937997868&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYRGehXTtspwNVskHUFuc1mfH2A00fBgz_DDGlJimxvi-jeKrE_2LtRoCYBUQAvD_BwE&gclsrc=aw.ds&aff_fcid=de7b9b6c73c34f0689d0c223d42e8937-1714939331446-04013-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=de7b9b6c73c34f0689d0c223d42e8937-1714939331446-04013-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
   - Justificativa: Baixo custo, compatível com controlador Arduino

## Gravação e reprodução de voz:
- Módulo de gravação - ISD1820(10s de gravação) ( GPIO Digital Output Model).
  - [Link datasheet](datasheets/modulo_gravacao_ISD1820.pdf).
  - [Link do produto no AliExpress](https://pt.aliexpress.com/item/1005002704344165.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=18736772764&albag=&trgt=&crea=pt1005002704344165&netw=x&device=c&albpg=&albpd=pt1005002704344165&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYZaBUzQLTxdDntmrVyY9pu7ErHc-hT9fNscnh-hkeQkaj9Hb57paQhoCEtMQAvD_BwE&gclsrc=aw.ds&aff_fcid=ac01cc00485b482284fb0e77babc408c-1714939576449-03603-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=ac01cc00485b482284fb0e77babc408c-1714939576449-03603-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
  - Justificativa: Cumpre 10 segundos máximo de mensagem estipulada. Compatibilidade de controle pelo Arduino para controle de gravação e reprodução. Gravação e reprodução no mesmo módulo.

## Abertura e fechamento de recipientes:
- Servo motores + Driver (Protocolo I2C).
  - [Link datasheet](datasheets/Motor_MG996R.pdf).
  - [Link do produto no AliExpress](https://pt.aliexpress.com/item/1005004635272899.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005004635272899&netw=x&device=c&albpg=&albpd=pt1005004635272899&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYdny76c2EqZJTNfVzMmznkt0t-7nc24DXPKSnwfdZxo2tTC3FR5QjxoC1cYQAvD_BwE&gclsrc=aw.ds&aff_fcid=382a0e3b0d61429fa40ef586e037f3bf-1714941085660-06892-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=382a0e3b0d61429fa40ef586e037f3bf-1714941085660-06892-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
  - Justificativa: Baixo custo. Torque atende o propósito. Compatível com Arduino.

## Reconhecer a presença do animal:
- Sensor de tag RFID(GPIO Digital Input Mode)(1º opção).
  - [Link datasheet](datasheets/Sensor_RFID_MFRC522.pdf).
  - [Link do produto no AliExpress](https://pt.aliexpress.com/item/1005006629654871.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=17364768653&albag=&trgt=&crea=pt1005006629654871&netw=x&device=c&albpg=&albpd=pt1005006629654871&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3woOMucpQwsIxdRB9m06N8ggAO-eRsb2vqzGIqlnW64eDq4NSmVibBUaAojjEALw_wcB&gclsrc=aw.ds&aff_fcid=13e410193ec2479297dbe6567cf2fc9f-1716514140591-01671-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=13e410193ec2479297dbe6567cf2fc9f-1716514140591-01671-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
  - Justificativa: Possibilidade de ativação em médias distâncias - atende o ideal do projeto. Controlável por Arduíno. CONTRA (alto impacto): alto custo que inviabilizaria o preço de produto final estipulado inicialmente.
- Sensor magnético + super imã permanente na coleira (GPIO Digital Input Mode)(2ª opção).
  - [Link datasheet sensor](datasheets/Sensor_Magnetico_MC38.pdf), [Link informacoes imã](datasheets/Ima_neodimio.pdf).
  - [Link do produto no WJ Componentes - Sensor e imã](https://www.wjcomponentes.com.br/sensor-mc-37?parceiro=6298&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3woI4ijoYCaGIUjOzMTRTMOqhkjNWsH7YAL87XvFT12BhyF4fgBBF4waAqaIEALw_wcB%20+%20https://pt.aliexpress.com/item/1005004685830211.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19639392923&albag=&trgt=&crea=pt1005004685830211&netw=x&device=c&albpg=&albpd=pt1005004685830211&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3wpQ0dnnthJ7Kx2YZVJR-eIah9MO3mKc-hu7Q5qzpO-56gmFITltgLoaArbdEALw_wcB&gclsrc=aw.ds&aff_fcid=e733aef517d04fa385c0979992d75d4f-1716515382192-04796-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=e733aef517d04fa385c0979992d75d4f-1716515382192-04796-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
  - Justificativa: Baixo custo e controlável pelo Adruino. Atende o esperado do produto para curtas distâncias. CONTRA: opera apenas para distâncias muito próximas.

## Unidade microcontroladora:
- Arduino nano 3.
  - [Link datasheet](datasheets/Arduino_nano_3.pdf).
  - [Link do produto no AliExpress](https://pt.aliexpress.com/item/1005002197241012.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005002197241012&netw=x&device=c&albpg=&albpd=pt1005002197241012&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3wqTbNoTqbXYXB13uq3B4xDzB8ZSmqupx1SxVXr3UkpXwHsQbzIFYqgaAgyAEALw_wcB&gclsrc=aw.ds&aff_fcid=631af40bd8d842b08ae06513d1c34077-1716513627600-09798-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=631af40bd8d842b08ae06513d1c34077-1716513627600-09798-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y)
  - Justificativa: Baixo custo. Facilidade de implementação e programação. Permite fácil troca de demais componentes na etapa de consolidação e construção do produto, por ter alta compatibilidade com diversos dispositivos.
