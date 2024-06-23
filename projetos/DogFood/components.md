# Lista de componentes elétricos utilizados para montagem do projeto:

## Obtenção de peso/sensor de peso:
 - Célula de carga fina + Amplificador de instrumentação HX711 ( Protocolo 2 - Wire Serial). [Link datasheet](datasheets/Célula_carga_fina_HX711.pdf).
 - Justificativa: Baixo custo, compatível com controlador Arduino

## Gravação e reprodução de voz:
- Módulo de gravação - ISD1820(10s de gravação) ( GPIO Digital Output Model). [Link datasheet](datasheets/modulo_gravacao_ISD1820.pdf).
- Justificativa: Cumpre 10 segundos máximo de mensagem estipulada. Compatibilidade de controle pelo Arduino para controle de gravação e reprodução. Gravação e reprodução no mesmo módulo.
   
## Abertura e fechamento de recipientes:
- Servo motores + Driver (Protocolo I2C). [Link datasheet](datasheets/Motor_MG996R.pdf).
- Justificativa: Baixo custo. Torque atende o proposto. Compatível com Arduino.

## Reconhecer a presença do animal:
- Sensor de tag RFID(GPIO Digital Input Mode)(1º opção). [Link datasheet](datasheets/Sensor_RFID_MFRC522.pdf).
- Justificativa: Possibilidade de ativação em médias distâncias - atende o ideal do projeto. Controlável por Arduíno. CONTRA (alto impacto): alto custo que inviabilizaria o preço de produto final estipulado inicialmente.
- Sensor magnético + super imã permanente na coleira (GPIO Digital Input Mode)(2ª opção). [Link datasheet sensor](datasheets/Sensor_Magnetico_MC38.pdf), [Link informacoes imã](datasheets/Ima_neodimio.pdf).
- Justificativa: Baixo custo e controlável pelo Adruino. Atende o esperado do produto para curtas distâncias. CONTRA: opera apenas para distâncias muito curtas.

## Unidade microcontroladora:
- Arduino nano. [Link datasheet](datasheets/Arduino_nano_3.pdf).
- Justificativa: Baixo custo. Facilidade de implementação e programação. Permite fácil troca de demais componentes na etapa de consolidação e construção do produto, por ter alta compatibilidade com diversos dispositivos.
