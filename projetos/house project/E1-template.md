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

## Descrição Funcional
![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/f6f2a04e-b437-436f-868a-ebb4185268f3)

Sistema de Segurança: Ao ser ativado, os sensores de presença, ao detectar alguma presença, irá alertar os donos via mensagem e tocará um alarme na própia casa.

Sistema de Controle de Temperatura: Pode ser ativado ou desativado conforme desejado pelo usuário, quando ativado o o sistema irá adotar as configurações exigidas pelo usuário e ficará ativo até ser desligado novamente.

Sistema de Alerta de Gâs: Ligado constantemente, enviará um sinal de alerta aos donos ao ser detectado um nivel elevado de gâs na cozinha. 

Sistema de Alerta de Fumaça: Ligado constantemente, enviará um sinal de alerta aos donos ao ser detectado um nivel elevado de fumaça e ligação aos bombeiros caso necessário.


### Funcionalidades


Sistema de Segurança: Alertar ao sentir uma presença não desejada com uso do sensor de presença ou mediante quebra de porta/janela.

Sistema de Controle de Temperatura: Caso a casa chegar a uma temperatura indesejada, ligar o aquecedor ou ar condicionado de acordo ao que o operador deseja 

Sistema de Alerta de Gâs: Principalmente na cozinha, caso detectado vazamento de gás, fazer um alerta para os donos da casa.

Sistema de Alerta de Fumaça: Detector de fumaça na casa com ligação automática aos bombeiros caso necessário


### Configurabilidade


Sistema de Segurança: Sistema ligado ou desligado mediante vontade do usuário.

Sistema de Controle de temperatura: Sistema ligado ou desligado com especificações estabelecidas pelo usuário (Por exemplo, limiares de temperatura, horário).

Sistema de Alerta de Gâs: Ligado permanentemente

Sistema de Alerta de Fumaça: Ligado permanentemente


### Eventos


Sistema de Segurança: Evento não periodico. Caso o sistema de segurança  esteja ligado, se o sensor de presença for ativado, gera uma interrupção.

Sistema de Controle de temperatura: Evento não periodico. Caso o sistema de controle de temperatura esteja ligado, ele detectará temperaturas estabelecidas pelo usuário e agirá caso a temperatura esteja fora do limiar.

Sistema de Alerta de Gâs: Evento não periodico. Gera interrupção caso decetar um nivel elevado de gâs

Sistema de Alerta de Fumaça: Evento não periodico. Gera interrupção caso decetar um nivel elevado de fumaça






### Tratamento de Eventos


Sistema de Segurança: Após a interrupção, será acionado um alarme sonoro na casa e será avisado aos usuários a detecção de presença não desejada.

Sistema de Controle de temperatura: Após a interrupção, agirá de acordos aos niveis de temperatura desejados, podendo ligar o aquecedor ou ar condicionado até chegar no nivel de temperatura desejado.

Sistema de Alerta de Gâs: Gerará um sinal de alerta ao usuário.

Sistema de Alerta de Fumaça: Gerará um sinal de alerta ao usuário e aos bombeiros.


## Descrição Estrutural do Sistema

![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/8c178a6c-19a0-4361-89dd-12dc569bd164)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/3ab0f4d3-79ff-4416-8ff3-fe9ff33925c7)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/823c3a2e-a3e5-49d6-942e-efd07fbb6f29)


![image](https://github.com/EndlessLight9/ea075-2024.1-dolc/assets/165411886/ab8c8509-dfe5-456d-87a2-f8170f2da8da)


> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.
> 

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
