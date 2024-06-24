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


> |Nome  | RA |
> |--|--|
> | Torque Máximo  | 2.2 kg/cm (4.8V)  |
> | Velocidade  | 0.11 s/60° (4.8V) |
> | Tensão de Operação  | 4.8V - 6.0V |

