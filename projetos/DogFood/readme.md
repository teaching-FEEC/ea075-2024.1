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
<img src="\images\dogfood_diagr.png">

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

#### Para o projeto, foi pensado nos seguintes componentes que irão cumprir cada necessidade do sistema
A lista de componentes, com respectivos Datasheets e justificativas para sua escolha pode ser acessada em [components.md](components.md).
##### Obtenção de peso/sensor de peso:
 - Célula de carga fina + Amplificador de instrumentação HX711 ( Protocolo 2 - Wire Serial).

##### Gravação e reprodução de voz:
- Módulo de gravação - ISD1820(10s de gravação) ( GPIO Digital Output Model).

##### Abertura e fechamento de recipientes:
- Servo motores + Driver (Protocolo I2C).

##### Reconhecer a presença do animal:
- Sensor de tag RFID(GPIO Digital Input Mode)(1º opção).
- Sensor magnético + super imã permanente na coleira (GPIO Digital Input Mode)(2ª opção).

##### Unidade microcontroladora:
- Arduino nano.

#### Restrições físicas:
- Área de trabalho do produto: Em torno de 60cm x 50cm x 40cm (teste em protótipos necessário para chegar nas dimensões exatas)
- Peso máximo suportado pelo dispenser de ração: ~~10Kg~~ --> E3: 2Kg (melhor estimativa para o tamanho pensado).
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
- Armazenamento do programa (estipulado para 150 linhas de código, compilado): ~~50kB~~ --> E3: 32kB (melhor estimativa para utilizar o Arduíno)

## Referências
https://www.google.com/search?sca_esv=7b4f5aad248322ac&sca_upv=1&rlz=1C1GCEB_enBR1053BR1053&q=alimentador+de+pet+automatico&tbm=isch&source=lnms&prmd=isvnbmtz&sa=X&ved=2ahUKEwiAr_nVmZqFAxUZppUCHSt9C3cQ0pQJegQIGBAB&biw=1280&bih=559&dpr=3
https://www.lucidchart.com/pages/pt/exemplos/diagrama-de-blocos-online
