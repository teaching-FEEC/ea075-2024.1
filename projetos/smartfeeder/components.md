# `Componentes do Projeto`

## Microcontrolador:
### ESP32
O ESP32 foi a escolha para o projeto do SmartFeeder devido à sua conectividade Wi-Fi e Bluetooth integrada, permitindo fácil configuração via aplicativo móvel. Com um processador dual-core, ele oferece desempenho poderoso e suporte a multitarefa, essenciais para gerenciar sensores, motores e comunicação simultaneamente. Seus múltiplos GPIOs, conversores Analógico-Digitais e suporte a PWM garantem flexibilidade na integração dos sensores e atuadores. Além disso, o ESP32 é eficiente em termos de consumo de energia, possui suporte de aplicativos disponíveis gratuitamente, e é uma solução economicamente viável, por não possuir um custo elevado.

- [Link do datasheet - ESP32](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
- [Link de compra do microcontrolador](https://pt.aliexpress.com/item/1005001627605230.html?src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005001627605230&netw=x&device=c&albpg=&albpd=pt1005001627605230&gad_source=1&aff_fcid=10ff2be7156b4d3e9c7d2f4fb1933b0f-1716399480646-09717-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=10ff2be7156b4d3e9c7d2f4fb1933b0f-1716399480646-09717-UneMJZVf&terminal_id=57b0948c82b44f7685bed38bf9809434&afSmartRedirect=y)
  
## Sensores de Pressão (Função de Balança)
### HX711 + Load Cell
O HX711 é um amplificador de precisão para células de carga, de fácil integração com microcontroladores como o ESP32. Possui alta precisão e é comumente utilizado em aplicações de balança.

- [Link do datasheet - HX711](https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf)
- [Link de compra do HX711 + Load Cell](https://pt.aliexpress.com/item/1005006293517345.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.1.7c8fOWFPOWFPRo&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=a9e49e7e-c76e-4265-a1fc-220758a4834b&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:a9e49e7e-c76e-4265-a1fc-220758a4834b,tpp_buckets:668%232846%238110%231995&pdp_npi=4%40dis%21BRL%2117.44%214.99%21%21%2122.32%216.38%21%402101e9ec17192663794496234e2205%2112000036640070164%21rec%21BR%21%21AB&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A)
## Motor para dispersão de comida
### TowerPro MG90S
O TowerPro MG90S foi escolhido, pois oferece um bom equilíbrio entre força, precisão e tamanho compacto. Ele se integra bem com o ESP32 e pode ser controlado facilmente usando sinais PWM. Dentre suas qualidades podemos destacar:

> |Característica  | Faixa/Valores |
> |--|--|
> | Torque Máximo  | 2.2 kg/cm (4.8V)  |
> | Velocidade  | 0.11 s/60° (4.8V) |
> | Tensão de Operação  | 4.8V - 6.0V |

- [Link do datasheet - MG90S](https://www.electronicoscaldas.com/datasheet/MG90S_Tower-Pro.pdf)
- [Link de compra do MG90S](https://pt.aliexpress.com/item/1005005850316099.html?spm=a2g0o.productlist.main.1.721eqLDJqLDJZn&algo_pvid=c5bea2a6-a45a-4419-9868-02af43845375&algo_exp_id=c5bea2a6-a45a-4419-9868-02af43845375-0&pdp_npi=4%40dis%21BRL%2113.54%2113.54%21%21%2117.33%2117.33%21%40210308a417192673266407147ecc36%2112000035298772732%21sea%21BR%210%21AB&curPageLogUid=fnH53M4UAkIU&utparam-url=scene%3Asearch%7Cquery_from%3A)

## Sensor para detectar o nível de água
### Sensor HC-SR04
O sensor ultrassônico HC-SR04 foi escolhido para monitorar o nível de água devido à sua precisão em uma faixa de 2 cm a 400 cm, adequada para o recipiente definido pro SmartFeeder. Além disso, o HC-SR04 integra-se facilmente ao ESP32 com apenas dois pinos, simplificando a conexão e a programação, sendo econômico e amplamente disponível, com boa documentação e suporte, facilitando o desenvolvimento do projeto. Sua robustez e confiabilidade em condições ambientais diversas, incluindo resistência a poeira e umidade, tornam-no adequado para ambientes próximos a água e ração, oferecendo, assim, uma excelente relação custo-benefício, precisão e simplicidade.

- [Link do datasheet - HC-SR04](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- [Link de compra do HC-SR04](https://pt.aliexpress.com/item/1005005636789307.html?spm=a2g0o.productlist.main.41.7ffb4e0a1Jgtnx&algo_pvid=986ea335-1e7b-43c6-ab31-907905f6c244&algo_exp_id=986ea335-1e7b-43c6-ab31-907905f6c244-20&pdp_npi=4%40dis%21BRL%219.78%216.50%21%21%2112.52%218.32%21%40210308a417192716632716355ecb7f%2112000033859091113%21sea%21BR%210%21AB&curPageLogUid=ogNzMf9UvrDU&utparam-url=scene%3Asearch%7Cquery_from%3A)


## Boia de nível de água
Boia mecânica simples para enchimento do pote de água, com baixo custo.

- [Link de compra da boia](https://www.aliexpress.us/item/3256806126055027.html?spm=a2g0o.productlist.main.1.34cf4748UOK5nF&algo_pvid=c1aa8fd7-88c9-46f1-8287-feaa28648d91&algo_exp_id=c1aa8fd7-88c9-46f1-8287-feaa28648d91-0&pdp_npi=4%40dis%21USD%215.33%210.99%21%21%2138.60%217.12%21%40210324c817192777472847179e73f3%2112000036719545555%21sea%21US%210%21AB&curPageLogUid=gSCHCoWySgas&utparam-url=scene%3Asearch%7Cquery_from%3A)

