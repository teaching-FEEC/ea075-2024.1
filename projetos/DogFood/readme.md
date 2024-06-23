# DogFood

## Apresentação
O presente projeto foi originado no contexto das atividades da disciplina de graduação EA075 - Introdução ao Projeto de Sistemas Embarcados, oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Fernando H. Velmae Nicchio  | 197003  | Eng. de Computação|
 | Rafael Cristian Nascimento  | 223622  | Eng. Elétrica|
 | Victor Potença Macchini | 225205  | Eng.  de Computação |

## Arquivos Importantes


## Descrição do Projeto
Muitas vezes, pessoas que têm animais de estimação se encontram em uma situação onde precisam se ausentar de sua residência por alguns dias; nessas situações, a preocupação com a alimentação do pet é uma dor inevitável. O projeto é pensado para resolver esse problema,  garantindo a alimentação do animal de estimação de forma automática, regulada, segura e livre de desperdícios - evitando a dor de cabeça do dono com a gestão da ração.

Existem hoje alguns dispositivos até mesmo caseiros que tentam solucionar esse problema, porém, não lidam tão bem com situações adversas: a não-presença do pet em casa, o horário de refeição restrito, a quantidade de porções servidas e o desperdício da comidinha - > fatores que podem comprometer a saúde do animal.

O nosso sistema garante que o animal será servido a porção ideal de sua necessidade, quando lhe for necessária, seguindo pré-programação do usuário. O animal será servido apenas se estiver perto do dispositivo e for chamado para isso - o que garante a adestração do pet e o não desperdício de ração. A quantidade de ração não comida pelo pet é também armazenada, após sua refeição, para prevenir a infestação de insetos.

Dispositivos com propostas semelhantes estão em torno de R$300,00 no mercado hoje. Acreditamos que os diferenciais do produto permitem a entrada do mesmo nessa faixa de preço inicial.



## Descrição Funcional e Descrição Estrutural do Sistema
<img src="\dogfood_diagr.png">

### Funcionalidades
- configurar porções (em gramas) por refeição
- configurar horários de refeição
- ~~configurar horários de recolhimento de restos de ração~~ --> E3: Foi decidido que o horário de recolhimento será fixo de 50 minutos após servida a comida, por simplicidade de uso do dispositivo pelo usuário final. O usuário não configura o horário de recolhimento.
- liberar ração em horário configurado
- detectar presença do pet por tag na coleira
- detectar a quantidade de ração restante e aviso
- identificar quantidade de ração liberada
- microfone para gravação de voz
- reprodução de áudio


### Configurabilidade
- quantidade de ração a ser liberada
- voz gravada para reprodução
- horário de liberação da refeição
- ~~horário de recolhimento de restos de ração~~ --> E3: tempo de recolhimento é fixo 50min, não configurável
- ~~intervalo de chamada do pet quando em horário de refeição~~ --> E3: intervalo é fixo 3min, não configurável


### Eventos
O sistema deve tratar sobre os seguintes eventos/inputs:
1. Janela de horário de refeição (periódico)
2. Horário de fim do dia (periódico)
3. Aproximação do pet (não-periódico)
4. Baixo peso de comida no reservatório (não periódico)
5. Variação do peso de comida no reservatório (não periódico)
6. Horário/tempo de recolhimento de restos de ração (periódico)

### Tratamento de Eventos
- Indicar SE baixa quantidade de comida restante - EVENTO 4
- ~~Reproduzir áudio de chamada do pet em horário específico, dependendo da configuração do usuário, repetição a cada X minutos segundo configurado - EVENTO 1~~ --> E3: Reproduzir áudio de chamada do pet em horário específico, repetição a cada 3 minutos - EVENTO 1
- Liberar ração SE em horário de refeição E pet está próximo E enquanto a quantidade total de porções não for liberada - EVENTO 1, EVENTO 3 e EVENTO 5
- Liberar comida pelo menos 1 vez ao dia - sistema de segurança para caso evento principal não funcionar - EVENTO 2 e EVENTO 5
- Recolher a ração restante no pote SE passado tempo de recolhimento de restos de ração - EVENTO 6

## Especificações

### Especificação Estrutural

#### Para o projeto, foi pensado nos seguintes componentes que irão compor:
##### Obtenção de peso/sensor de peso:
 - Célula de carga fina + Amplificador de instrumentação HX711 ( Protocolo 2 - Wire Serial):

https://pt.aliexpress.com/item/1005002937997868.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005002937997868&netw=x&device=c&albpg=&albpd=pt1005002937997868&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYRGehXTtspwNVskHUFuc1mfH2A00fBgz_DDGlJimxvi-jeKrE_2LtRoCYBUQAvD_BwE&gclsrc=aw.ds&aff_fcid=de7b9b6c73c34f0689d0c223d42e8937-1714939331446-04013-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=de7b9b6c73c34f0689d0c223d42e8937-1714939331446-04013-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

##### Gravação e reprodução de voz:
- Módulo de gravação - ISD1820(10s de gravação) ( GPIO Digital Output Model):

https://pt.aliexpress.com/item/1005002704344165.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=18736772764&albag=&trgt=&crea=pt1005002704344165&netw=x&device=c&albpg=&albpd=pt1005002704344165&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYZaBUzQLTxdDntmrVyY9pu7ErHc-hT9fNscnh-hkeQkaj9Hb57paQhoCEtMQAvD_BwE&gclsrc=aw.ds&aff_fcid=ac01cc00485b482284fb0e77babc408c-1714939576449-03603-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=ac01cc00485b482284fb0e77babc408c-1714939576449-03603-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

##### Abertura e fechamento de recipientes:
- Servo motores + Driver (Protocolo I2C):

https://pt.aliexpress.com/item/1005004635272899.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005004635272899&netw=x&device=c&albpg=&albpd=pt1005004635272899&gad_source=1&gclid=CjwKCAjw3NyxBhBmEiwAyofDYdny76c2EqZJTNfVzMmznkt0t-7nc24DXPKSnwfdZxo2tTC3FR5QjxoC1cYQAvD_BwE&gclsrc=aw.ds&aff_fcid=382a0e3b0d61429fa40ef586e037f3bf-1714941085660-06892-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=382a0e3b0d61429fa40ef586e037f3bf-1714941085660-06892-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

##### Reconhecer a presença do animal:
- Sensor de tag RFID(GPIO Digital Input Mode)(1º opção):

https://pt.aliexpress.com/item/1005006629654871.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=17364768653&albag=&trgt=&crea=pt1005006629654871&netw=x&device=c&albpg=&albpd=pt1005006629654871&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3woOMucpQwsIxdRB9m06N8ggAO-eRsb2vqzGIqlnW64eDq4NSmVibBUaAojjEALw_wcB&gclsrc=aw.ds&aff_fcid=13e410193ec2479297dbe6567cf2fc9f-1716514140591-01671-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=13e410193ec2479297dbe6567cf2fc9f-1716514140591-01671-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

- Sensor magnético + super imã permanente na coleira (GPIO Digital Input Mode)(2ª opção):

https://www.wjcomponentes.com.br/sensor-mc-37?parceiro=6298&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3woI4ijoYCaGIUjOzMTRTMOqhkjNWsH7YAL87XvFT12BhyF4fgBBF4waAqaIEALw_wcB
+
https://pt.aliexpress.com/item/1005004685830211.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19639392923&albag=&trgt=&crea=pt1005004685830211&netw=x&device=c&albpg=&albpd=pt1005004685830211&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3wpQ0dnnthJ7Kx2YZVJR-eIah9MO3mKc-hu7Q5qzpO-56gmFITltgLoaArbdEALw_wcB&gclsrc=aw.ds&aff_fcid=e733aef517d04fa385c0979992d75d4f-1716515382192-04796-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=e733aef517d04fa385c0979992d75d4f-1716515382192-04796-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

##### Unidade microcontroladora:
- Arduino nano:

https://pt.aliexpress.com/item/1005002197241012.html?src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=19505955113&albag=&trgt=&crea=pt1005002197241012&netw=x&device=c&albpg=&albpd=pt1005002197241012&gad_source=1&gclid=Cj0KCQjw0ruyBhDuARIsANSZ3wqTbNoTqbXYXB13uq3B4xDzB8ZSmqupx1SxVXr3UkpXwHsQbzIFYqgaAgyAEALw_wcB&gclsrc=aw.ds&aff_fcid=631af40bd8d842b08ae06513d1c34077-1716513627600-09798-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=631af40bd8d842b08ae06513d1c34077-1716513627600-09798-UneMJZVf&terminal_id=74fd28b9fc36469bb5d951ec78224d83&afSmartRedirect=y

#### Restrições físicas:
- Área de trabalho do produto: Em torno de 60cm x 50cm x 40cm (teste em protótipos necessário para chegar nas dimensões exatas)
- Peso máximo suportado pelo dispenser de ração: 10Kg
- Temperatura de trabalho: Temperatura suportada por animais domésticos (-10°C à 30°C)

### Especificação de Algoritmos 
#### Diagrama de tratamento de eventos do algoritmo (desenvolvido com o _board_ Miro):
https://miro.com/app/board/uXjVKGq-ktg=/?share_link_id=296110568841
Atualizações realizadas na entrega E3: 
- tempo de chamada do pet (reprodução do áudio) é agora fixo de 3 minutos, e não configurável pelo usuário. Decisão visa simplificar configuração do dispositivo pelo usuário final.
- tempo de recolhimento da ração é agora fixo de 50 minutos, e não configurável pelo usuário. Decisão visa simplificar configuração do dispositivo pelo usuário final.

#### Estimativa de memória necessária para especificação de algoritmos
Total de memória necessária estimada para armazenamento de todo o algorítmo 170kB. Composição:
- Arquivo de audio : 125kB
- Display de led: 6 bytes
- Variáveis usadas no algoritmo e armazenamento de leituras dos sensores:  ~ 116 bytes
- Armazenamento do programa (estipulado para 150 linhas de código, compilado): ~50kB

## Referências
https://www.google.com/search?sca_esv=7b4f5aad248322ac&sca_upv=1&rlz=1C1GCEB_enBR1053BR1053&q=alimentador+de+pet+automatico&tbm=isch&source=lnms&prmd=isvnbmtz&sa=X&ved=2ahUKEwiAr_nVmZqFAxUZppUCHSt9C3cQ0pQJegQIGBAB&biw=1280&bih=559&dpr=3
https://www.lucidchart.com/pages/pt/exemplos/diagrama-de-blocos-online
