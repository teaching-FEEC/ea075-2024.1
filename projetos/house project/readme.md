# `<Projeto de Casa Inteligente>`
# `<Smart Home Project>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Daniel Alexander Ortega Rodriguez  | 261261  | Eng. Elétrica|
> | Luciano Cardoso Ferreira Filho     | 240276  | Eng. Elétrica|


## Descrição do Projeto
  O objetivo principal desse projeto é poder criar um sistema de segurança eficiente, podendo assim ajudar desde casas menores de poucas pessoas até casas com uma familia grande, trazendo confiança, segurança e eficiência ao lar de cada individuo. O projeto inclui algumas coisas como sistema de segurança para evitar roubos ou até alertar algum vazamento de gâs na casa, sensor de temperatura para poder agir conforme os moradores escolham melhor, sensores de presença para evitar coisas simples como deixar a luz acessa do quarto sem ninguém estar usando ele entre outras funcionalidades.

 DESCRIÇÃO NOVA
 O objetivo principal deste projeto é criar um sistema de segurança eficiente, focado em casas de menor porte, mas que também possa ser otimizado para residências maiores. O sistema de segurança proporciona 
 eficiência energética e conforto aos moradores. Ele inclui funcionalidades como: sensor de presença conectado a um LED, permitindo monitoramento conforme desejado pelo usuário e podendo também acionar um alarme 
 sonoro, se desejado (por exemplo, ao sair de casa); sensor de gás com alarme sonoro, ativado ao detectar níveis potencialmente perigosos; e sensor de fumaça, que aciona um alarme sonoro ao detectar altos níveis 
 de fumaça.
 
## Descrição Funcional
![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/f6f2a04e-b437-436f-868a-ebb4185268f3)

Sistema de Segurança: Ao ser ativado, os sensores de presença, ao detectar alguma presença, irá alertar os donos via mensagem e tocará um alarme na própia casa.

Sistema de Controle de Temperatura: Pode ser ativado ou desativado conforme desejado pelo usuário, quando ativado o o sistema irá adotar as configurações exigidas pelo usuário e ficará ativo até ser desligado novamente.

Sistema de Alerta de Gâs: Ligado constantemente, enviará um sinal de alerta aos donos ao ser detectado um nivel elevado de gâs na cozinha. 

Sistema de Alerta de Fumaça: Ligado constantemente, enviará um sinal de alerta aos donos ao ser detectado um nivel elevado de fumaça e ligação aos bombeiros caso necessário.

DESCRIÇÃO NOVA:

Sensor de Presença:
 O sensor de presença é responsável por detectar movimento em áreas específicas da casa. Este sensor está conectado a um LED, que indica visualmente a detecção de movimento. Quando o sensor capta a presença de 
 alguém, o LED acende, permitindo que os moradores saibam que há movimento no ambiente monitorado. Além disso, o sistema permite que o usuário configure a ativação de um alarme sonoro ao detectar presença. Esta 
 funcionalidade é particularmente útil quando os moradores estão ausentes, oferecendo uma camada adicional de segurança ao alertar sobre movimentos inesperados.

 Sensor de Gás:
 O sensor de gás é projetado para detectar a presença de gases potencialmente perigosos no ambiente, como gás de cozinha. Quando o sensor detecta níveis elevados de gás, um alarme sonoro é imediatamente acionado 
 para alertar os moradores. Esta função é essencial para prevenir incidentes graves, como explosões ou intoxicações, garantindo a segurança dos habitantes da casa. O sensor é calibrado para identificar 
 concentrações de gás que ultrapassem limites seguros, proporcionando uma resposta rápida e segura em situações de risco.

* Sensor de Fumaça:
 O sensor de fumaça é fundamental para a detecção precoce de incêndios. Este sensor monitora continuamente os níveis de fumaça no ambiente e, ao identificar concentrações elevadas, aciona um alarme sonoro. A 
 rápida detecção de fumaça permite que os moradores tomem medidas imediatas para evacuar a área e chamar os serviços de emergência ou até mesmo ser conectado junto com um sprinkler (porém o sprinkler não está 
 incluido no projeto ainda), minimizando danos e salvaguardando vidas. O sensor é sensível a variações súbitas na quantidade de fumaça, garantindo que qualquer início de incêndio seja rapidamente percebido.



### Funcionalidades


Sistema de Segurança: Alertar ao sentir uma presença não desejada com uso do sensor de presença ou mediante quebra de porta/janela.

Sistema de Controle de Temperatura: Caso a casa chegar a uma temperatura indesejada, ligar o aquecedor ou ar condicionado de acordo ao que o operador deseja 

Sistema de Alerta de Gâs: Principalmente na cozinha, caso detectado vazamento de gás, fazer um alerta para os donos da casa.

Sistema de Alerta de Fumaça: Detector de fumaça na casa com ligação automática aos bombeiros caso necessário

TEXTO NOVO:

Detecção de Presença: Utilizando sensores de movimento, o sistema pode identificar a presença de indivíduos em áreas específicas da casa. Isso permite a ativação de alertas visuais (LEDs) e sonoros para notificar os moradores sobre atividades suspeitas.

Detecção de Gás: O sistema possui sensores que monitoram continuamente a presença de gases potencialmente perigosos. Ao detectar níveis elevados, um alarme sonoro é acionado para alertar os moradores, permitindo uma resposta rápida para evitar acidentes.

*Detecção de Fumaça: Sensores de fumaça instalados em pontos estratégicos da residência detectam a presença de fumaça, acionando imediatamente um alarme sonoro. Esta funcionalidade é crucial para a detecção de incêndios, possibilitando a evacuação e a chamada dos serviços de emergência (ou sprinkler?).

Monitoramento em Tempo Real: Todos os sensores são integrados a um sistema central que permite o monitoramento em tempo real. Os moradores podem visualizar o status dos sensores e receber notificações instantâneas em caso de anomalias.

### Configurabilidade


Sistema de Segurança: O usuário tem controle total sobre a ativação ou desativação do sistema conforme sua vontade.

Sistema de Controle de Temperatura: O usuário pode definir as especificações de ligar ou desligar o sistema, como limiares de temperatura ou horários específicos.

Sistema de Alerta de Gás: Este sistema permanece permanentemente ligado para detectar qualquer presença de gás.

Sistema de Alerta de Fumaça: Da mesma forma, este sistema também permanece permanentemente ligado para detectar qualquer indício de fumaça.

TEXTO NOVO:

*Ajuste de Sensibilidade dos Sensores: Os usuários podem ajustar a sensibilidade dos sensores de presença, (explicar como? ou nao?) gás e fumaça para evitar falsos alarmes e garantir uma detecção precisa.

Configuração de Alarmes: É possível definir quando os alarmes sonoros devem ser ativados, como por exemplo, apenas quando a casa está vazia ou durante determinados horários.

Notificações Personalizadas: Os moradores podem configurar o sistema para receber notificações alerta via LED ou alarme sonoro.

*Integração com Outros Sistemas: O sistema pode ser integrado com outros dispositivos de automação residencial, como câmeras de segurança, sistemas de iluminação, sprinklers e controles de acesso, permitindo uma gestão centralizada da segurança da casa.

### Eventos


Sistema de Segurança : Em eventos não periódicos, caso o sistema de segurança esteja ativado, a ativação do sensor de presença gera uma interrupção.

Sistema de Controle de Temperatura : Em eventos não periódicos, se o sistema de controle de temperatura estiver ativo, ele monitora as temperaturas definidas pelo usuário e toma medidas se a temperatura estiver fora dos limites estabelecidos.

Sistema de Alerta de Gás : Em eventos não periódicos, uma interrupção é gerada se for detectado um nível elevado de gás pelo sistema de alerta de gás.

Sistema de Alerta de Fumaça : Em eventos não periódicos, uma interrupção é gerada se for detectado um nível elevado de fumaça pelo sistema de alerta de fumaça.

TEXTO NOVO:

Eventos Periódicos:

Verificação de Níveis de Gás e Fumaça: Monitoramento contínuo dos níveis de gás e fumaça no ambiente.

Eventos Não Periódicos:

Detecção de Presença: Ativado quando um movimento é detectado.
Alerta de Gás: Ativado ao detectar níveis perigosos de gás.
Alerta de Fumaça: Ativado ao detectar níveis elevados de fumaça.



### Tratamento de Eventos


Sistema de Segurança (Prioridade Nível 1): Após a detecção de uma intrusão, um alarme sonoro será ativado na residência e os usuários serão notificados sobre a presença não autorizada.

Sistema de Controle de Temperatura (Prioridade Nível 4): Após a detecção de uma variação fora dos níveis de temperatura desejados, o sistema ajustará o ambiente conforme necessário, ligando o aquecedor ou o ar condicionado até que a temperatura desejada seja alcançada.

Sistema de Alerta de Gás (Prioridade Nível 2): Emitirá um sinal de alerta para os usuários ao detectar a presença de gás.

Sistema de Alerta de Fumaça (Prioridade Nível 3): Emitirá um sinal de alerta para os usuários e para os bombeiros ao detectar a presença de fumaça.

TEXTO NOVO:

Detecção e Notificação:

Quando um sensor detecta um evento (presença, gás ou fumaça), ele envia imediatamente um sinal ao sistema central.
O sistema central processa o sinal e ativa os alarmes sonoros e visuais correspondentes.

Ação Imediata:

Para Detecção de Presença: O LED é aceso e o alarme sonoro é ativado (se configurado). Os moradores são notificados para verificar a situação. Prioridade 1
Para Detecção de Gás: O alarme sonoro é ativado e uma notificação de emergência é enviada. Os moradores devem ventilar a área e evacuar se necessário. Prioridade 2
Para Detecção de Fumaça: O alarme sonoro é ativado e uma notificação de emergência é enviada. Os moradores devem evacuar imediatamente e chamar os bombeiros. Prioridade 3




## Descrição Estrutural do Sistema

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/8c178a6c-19a0-4361-89dd-12dc569bd164)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/3ab0f4d3-79ff-4416-8ff3-fe9ff33925c7)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/823c3a2e-a3e5-49d6-942e-efd07fbb6f29)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/ab8c8509-dfe5-456d-87a2-f8170f2da8da)

Sistema de Segurança: Este sistema é composto por sensores de presença distribuídos pelos cômodos da casa, acompanhados por uma interface física na parede para a ativação. Após a ativação, os sensores entram em modo de vigilância. Quando uma interrupção é detectada, um alerta sonoro é ativado por meio do sistema de som da residência, e uma notificação é enviada via internet para o usuário.

Sistema de Controle de Temperatura: Este sistema é composto por sensores de temperatura localizados nos diferentes cômodos da casa. O usuário pode definir uma faixa de temperatura desejada através de uma interface fixa. Os sensores monitoram constantemente a temperatura ambiente e, ao detectarem uma variação em relação à faixa definida, ativam o aquecedor ou o ar-condicionado conforme necessário. Uma vez que a temperatura atinge a faixa desejada, o sistema desliga automaticamente o dispositivo de climatização.


Sistema de Alerta de Gás: Este sistema é preferencialmente instalado na cozinha e permanece sempre ativo. Quando uma concentração elevada de gás é detectada, o sistema emite um alerta para o usuário e aciona um sinal sonoro discreto.

Sistema de Alerta de Fumaça: Este sistema é instalado em todos os cômodos e permanece permanentemente ativo. Após detectar uma quantidade elevada de fumaça, o sistema emite um sinal sonoro audível e simultaneamente alerta os bombeiros e o usuário.


Todos esses sistemas são controlados por um microcontrolador, com a escolha entre Arduino ou ESP32 a ser determinada.

*NOVA DESCRIÇÃO: To fazendo sem temperatura mas acredito que estrtuturalmente nao iria mudar muito

# Blocos Funcionais
Sensores:

Sensor de Presença: Detecta movimento e envia sinais ao controlador central.
Sensor de Gás: Monitora a concentração de gás no ambiente e envia um sinal ao controlador quando níveis perigosos são detectados.
Sensor de Fumaça: Detecta a presença de fumaça e envia um sinal ao controlador ao identificar concentrações elevadas.

# Controlador Central

*Microcontrolador: O núcleo do sistema, responsável por receber sinais dos sensores, processar esses sinais e tomar decisões com base na programação interna. (adicionar qual)

# Unidades de Alerta

LED de Indicação: Acende para indicar a detecção de presença.
Alarmes Sonoros: Ativados pelo controlador central em resposta a sinais dos sensores de gás e fumaça, ou conforme configurado pelo usuário para o sensor de presença.

* # Fonte de Alimentação (Temos que pensar em qual fonte mas acho que não precisamos disso agora)

Unidade de Alimentação: Fornece energia para todos os componentes do sistema, garantindo operação contínua.

# Relacionamento entre Blocos e Sinais de Comunicação
*Sinais dos Sensores para o Controlador Central (Dependendo do sensor que escolhemos podemos precisar ou não de DAC então a gente modifica aqui quando tivermos certeza qual usaremos)

Sensor de Presença para Microcontrolador: Envia um sinal digital quando detecta movimento.
Sensor de Gás para Microcontrolador: Envia um sinal analógico ou digital quando os níveis de gás são perigosos.
Sensor de Fumaça para Microcontrolador: Envia um sinal digital quando a fumaça é detectada.

Sinais do Controlador Central para Unidades de Alerta

Microcontrolador para LED de Indicação: Envia um sinal para acender o LED.
Microcontrolador para Alarmes Sonoros: Envia sinais para ativar os alarmes em resposta à detecção de gás ou fumaça, ou conforme configuração para presença.

*Em questão de blocos vou fazer um rascunho por enquanto, vê se concorda:

                | SENSORES |
                | PRESENÇA |
                | GAS      |
                | FUMAÇA   |
                    | 
                    |
                |CONTROLADOR|
                |ARDUINDO   |
                |EVENTOS    |
                    |
                    |
           ---------------------
           |                   |
           |                   |
           |                   |
    |ALERTAS|           |CONFIGURAÇÃO|
    |LED    |           |STATUS TALVEZ?|
    |ALARME |
           --------------------
                    |
                    |
                    FONTE 
## Referências

https://components101.com/sensors/hc-sr501-pir-sensor (Sensor movimento hc-Sr 501)
Ideias, pesquisa e depois alteração: indicativo de presença via LED (dois tipos de alarmes), pensar em uma casa para se fazer o projeto ( 2 quartos 1 sala 1 cozinha 1 banheiro e 1 quintal), pesquisar sensores faltantes ( gaz e fumaça, temperatura e microcontrolador), atualizar diagramas de blocos e fazer diagrama funcional, Alterar todo as descrições  

