# `<Comedouro Inteligente>`
# `<Smart Feeder>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
>|--|--|--|
> | Alice Nunes Oliveira  | 214181  | Eng. Elétrica|
> | José Henrique Araújo de Oliveira  | 239753  | Eng. Elétrica|

## Arquivos Importantes



## Descrição do Projeto
O SmartFeeder representa uma revolução na forma como cuidamos dos nossos pets. O dispenser de comida para animais de estimação é controlado por um aplicativo intuitivo, proporcionando conveniência e tranquilidade para os donos preocupados com a alimentação de seus amigos peludos. Com o SmartFeeder, é possível programar horários precisos de alimentação, garantindo que o animal receba suas refeições na hora certa, mesmo quando o dono estiver longe de casa. Seja durante o período de trabalho ou  durante uma viagem, pode-se monitorar e controlar a alimentação do seu pet remotamente, garantindo que ele esteja sempre bem alimentado e saudável. Além disso, uma série de recursos inteligentes são pensados para auxiliar no monitoramento do seu pet: como notificações em tempo real sobre alimentação, controle preciso das porções servidas e até mesmo qual a massa específica consumida pelo pet. Além disso, o SmartFeeder possui também um vasilhame d'água, com reposição automática, para que seu pet tenha sempre água para beber.

## O Produto

<img src="\images\logo1.png">

<img src="\images\Layout Smart feeder.png" width="65%" height="65%">

## Descrição Funcional
O projeto contempla dois funcionamentos distintos: Comedouro e Bebedouro, assim, cada função foi tratada separadamente, pois independem em funcionamento.
### Funcionalidades
 O projeto tem como principais funcionalidades:
- Alimentação de pets através do ajuste wireless (pelo usuário - dono) dos horários e quantidades das porções diárias que fazem parte da dieta do mesmo;
- Medição do nível do reservatório de comida e na tigela de alimentação (cheia vs. vazia)
- Mecanismo de dispenser da comida, com volume/massa regulável;
- Aviso ao usuário (via mobile) quando o nível de comida no reservatório estiver baixo;
- Monitoramento da alimentação do pet a fim de acompanhar o rendimento da ração.
- Monitoramento da ingestão de água
- Mecanismo de enchimento da vasilha de água do pet.

### Configurabilidade
Quanto a configurabilidade do sistema, o usuário será responsável pera personalização do sistema de acordo com suas necessidades, definindo, via mobile, quantas porções fazem parte da dieta do pet, definindo tanto horários para acionamento do dispenser quanto a quantidade de cada porção.


### Eventos
Quanto aos eventos, enquanto o sistema estiver em configuração, a alimentação será interrompida. Deverá então ser definido os horários para acionamento do dispenser e as quantidades a serem liberadas em cada uma. A partir disso o sistema irá periodicamente acionar a alimentaçãp do pet.
Deverá também acionar avisos distintos ao usuário via mobile quando o reservatório estiver com sua capacidade abaixo do limitdefinido pelo usuário e quando a tigela de alimentação estiver vazia, contabilizando uma refeição do animal.
Quando o sensor detectar que o nível do bebedouro estiver abaixo de um determinado nível de BIAS_VAZIO, ele enche o pote com água até um nível BIAS_CHEIO.


### Tratamento de Eventos
Os comportamentos para tratamento dos eventos descritos serão:

 *COMEDOURO*
 - Detectou reservatório vazio
 - Detectou reservatório com cheio após configurações setadas
 - Relógio comparador chegou ao horário definido para refeição
 - Detectou prato vazio no horário setado
 - Detectou prato com sobra no horário setado
 - Recebeu configuração do horário e de porção: aciona periodicamente a alimentação do animal através do acionamento do dispenser.

 *BEBEDOURO*
 - Detecta nível de água baixo e enche
 - Detecta nível alto de água e para de encher

## Descrição Estrutural do Sistema
Os dois sistemas (bebedouro e comedouro) descritos:
 - Função de Bebedouro:
<img src="\images\bebedouro.drawio.png">

 - Função de Comedouro:
<img src="\images\comedouro1.drawio.png">

## Especificação Estrutural
O sistema proposto para o *Smart Feeder* é composto por dois módulos paralelos de funcionamento; um da função de bebedouro e outro de comedouro.
Esse produto consiste estruturalmente em um reservatório de comida acoplado a um filtro d'água dois potes de 1,2 L, em formato circular com as dimensões: 

- Altura: 9 cm

- Diâmetro: 25 cm

Para o armazenamento da ração, contamos com um tanque de 6 L (aproximadamente 3kg de ração), com as dimensões:
- Comprimento: 21,5 cm
  
- Largura: 21,5 cm
  
- Altura: 38 cm

Alimentação:
Para garantir a alimentação ininterrupta do dispositivo, oferecemos duas opções. Primeiramente, a fonte principal é um adaptador AC que pode ser facilmente conectado a uma tomada padrão, garantindo uma fonte de energia estável e confiável. Além disso, o dispositivo foi projetado com uma funcionalidade de dupla fonte de energia, permitindo que seja alimentado por pilhas. Esta característica é especialmente útil para situações em que você está quer utilizar o dispositivo em um ambiente sem tomadas, ou em caso de queda de energia, garantindo que seu pet seja alimentado mesmo em circunstâncias adversas.
Quando o dispositivo está operando com alimentação por pilhas, a capacidade de configuração é desativada, e o último *setup* utilizado é mantido. Essa medida visa preservar a vida útil das pilhas no sistema e assegurar o funcionamento contínuo, mesmo em situações de queda de energia ou falta de conexão Wi-Fi na residência.

*MICROCONTROLADOR*

O microcontrolador escolhido foi o ESP32, uma vez uqe possui as funcionalidades desejadas de conectividade bluetooth, Wi-fi, diversidade de antenas e fácil integração com apps já exixtentes, como o Tasmota, ESPEasy e ESPHome.
Desta forma, escolhemos um módulo ESP32, que conta com uma memória Flash suficiente para os arquivos de programa e configurações. Tal módulo conta com a pinagem descrita no diagrama abaixo:

<img src="\images\ESP32-Pinout.jpg">

*BEBEDOURO*

Para garantir que o bebedouro funcione corretamente, vamos implementar um sensor de nível que pode detectar quando o nível da água está abaixo de um valor específico (chamado de BIAS). Isso nos permite monitorar o consumo de água do seu animal de estimação ao longo do tempo, dados que estarão disponíevis no aplicativo que integra o conjunto de funcionalidades do *Smart Feeder*. O controle do enchimento do bebedouro será feito por uma boia de nível, que estará conectada diretamente a uma fonte de água, como uma torneira. Além disso, o sistema incluirá um filtro de carvão ativo para garantir que a água fornecida ao seu animal seja de alta qualidade.

*COMEDOURO*

Já no esquemático do comedouro, são implementados dois sensores de pressão:
- 1 sensor de pressão (função de balança) localizado no reservatório para aferir a massa de ração disponível.
  
- 1 sensor de pressão (função de balança) localizado no pratinho, de forma a medir a ração que foi liberada, e fazer o *tracking* da alimentação do pet.
  
- Sistema dispersor com motor.

## Especificação de Algoritmos

*Função Bebedouro*

<img src="\images\E3 - algoritmo - água.drawio.png">

*Função Comedouro*

<img src="\images\E3 - Algoritmo - comida1.drawio.png">

## Referências

ALIEXPRESS. ESP32-WROOM-32D. Disponível em: https://pt.aliexpress.com/item/1005001627605230.html?src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005001627605230&netw=x&device=c&albpg=&albpd=pt1005001627605230&gad_source=1&aff_fcid=10ff2be7156b4d3e9c7d2f4fb1933b0f-1716399480646-09717-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=10ff2be7156b4d3e9c7d2f4fb1933b0f-1716399480646-09717-UneMJZVf&terminal_id=57b0948c82b44f7685bed38bf9809434&afSmartRedirect=y

ALIEXPRESS. 4PCS Human Scale Load Cell Weight Sensors + HX711 AD Module Weight Sensor Electronic Scale Weighing Pressure Sensor DIY Kit. Disponível em: https://www.aliexpress.us/item/3256806107202593.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.1.7c8fOWFPOWFPRo&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=a9e49e7e-c76e-4265-a1fc-220758a4834b&_t=gps-id%3ApcDetailTopMoreOtherSeller%2Cscm-url%3A1007.40050.354490.0%2Cpvid%3Aa9e49e7e-c76e-4265-a1fc-220758a4834b%2Ctpp_buckets%3A668%232846%238110%231995&pdp_npi=4%40dis%21BRL%2117.44%214.99%21%21%2122.32%216.38%21%402101e9ec17192663794496234e2205%2112000036640070164%21rec%21BR%21%21AB&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A&gatewayAdapt=glo2usa4itemAdapt

ALIEXPRESS. Mitoot MG90S 360 Metal gear Digital Servo For tower pro Rc Helicopter Plane Boat Car MG90 servo mg90s. Disponível em: https://www.aliexpress.us/item/3256805664001347.html?spm=a2g0o.productlist.main.1.721eqLDJqLDJZn&algo_pvid=c5bea2a6-a45a-4419-9868-02af43845375&algo_exp_id=c5bea2a6-a45a-4419-9868-02af43845375-0&pdp_npi=4%40dis%21BRL%2113.54%2113.54%21%21%2117.33%2117.33%21%40210308a417192673266407147ecc36%2112000035298772732%21sea%21BR%210%21AB&curPageLogUid=fnH53M4UAkIU&utparam-url=scene%3Asearch%7Cquery_from%3A&gatewayAdapt=bra2usa4itemAdapt

ALIEXPRESS. TZT HC-SR04 HCSR04 to world Ultrasonic Wave Detector Ranging Module HC-SR04 HC SR04 HCSR04 Distance Sensor. Disponível em: https://www.aliexpress.us/item/3256805450474555.html?spm=a2g0o.productlist.main.41.7ffb4e0a1Jgtnx&algo_pvid=986ea335-1e7b-43c6-ab31-907905f6c244&algo_exp_id=986ea335-1e7b-43c6-ab31-907905f6c244-20&pdp_npi=4%40dis%21BRL%219.78%216.50%21%21%2112.52%218.32%21%40210308a417192716632716355ecb7f%2112000033859091113%21sea%21BR%210%21AB&curPageLogUid=ogNzMf9UvrDU&utparam-url=scene%3Asearch%7Cquery_from%3A&gatewayAdapt=bra2usa4itemAdapt

ALIEXPRESS. 1/4 Inch Float Ball Valve For RO Water Purifier Aquarium Auto Water Changer Float Valve Plastic White Water Level Controller. Disponível em: https://www.aliexpress.us/item/3256806126055027.html?spm=a2g0o.productlist.main.1.34cf4748UOK5nF&algo_pvid=c1aa8fd7-88c9-46f1-8287-feaa28648d91&algo_exp_id=c1aa8fd7-88c9-46f1-8287-feaa28648d91-0&pdp_npi=4%40dis%21USD%215.33%210.99%21%21%2138.60%217.12%21%40210324c817192777472847179e73f3%2112000036719545555%21sea%21US%210%21AB&curPageLogUid=gSCHCoWySgas&utparam-url=scene%3Asearch%7Cquery_from%3A

COBASI. Comedouro Alumínio Pesado. Disponível em: https://www.cobasi.com.br/comedouro-aluminio-pesado-nf-pet-3936367/p?idsku=936413&gad_source=1

DOGIS. Alimentador Automático. Disponível em: https://www.dogis.com.br/som-e-video/alimentador-automatico-pet-dogis-da010br-com-camera-full-hd-wi-fi-aplicativo-capacidade-de-6-litros?parceiro=4972&gad_source=1&gclid=CjwKCAjwtqmwBhBVEiwAL-WAYek92ZZTHrK0SYdxBEBao9r93Kz1aHOxFH06iLSiU2fGpBTl1r9t4hoCixwQAvD_BwE

ELECTRONICOSCALDAS. MG90S Datasheet. Disponível em: https://www.electronicoscaldas.com/datasheet/MG90S_Tower-Pro.pdf

ESPRESSIF. ESP32 Series. Disponível em: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf

MADOG. Comedouro Automático. Disponível em: https://www.madog.com.br/MLB-2161381341-comedouro-automatico-inteligente-madog-com-gravador-voz-_JM

NINHO DO PET. Comedouro Automático Eletrônico para Cães e Gatos. Disponível em: https://www.ninhodopet.com.br/produtos/comedouro-automatico-eletronico-para-caes-e-gatos/

ROBOCORE. ESP32 - WiFi + Bluetooth. Disponível em: https://www.robocore.net/wifi/esp32-wifi-bluetooth

SPARKFUN. HX711 Datasheet. Disponível em: https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf

SPARKFUN. Ultrasonic Ranging Module HC - SR04. Disponível em: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf 

WEASY. Weasy Oasis. Disponível em: https://www.weasy.com.br/products/weasy-oasis?variant=32277452783695&currency=BRL&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gad_source=1&gclid=Cj0KCQjw2a6wBhCVARIsABPeH1sAXLDyqX-aO8CgqyUsDRRZeY-H1G8rfBFdN8DTA2uM9PdB25bSHzEaAvQEEALw_wcB

