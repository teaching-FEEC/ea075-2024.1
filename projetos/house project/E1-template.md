# `<Projeto de Casa Inteligente>`
# `<Smart Home Project>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Daniel Alexander Ortega Rodriguez  | 261261  | Eng. Elétrica|
> | Luciano Cardoso Ferreira Filho     | xxxxxx  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?
O objetivo principal desse projeto é poder fazer criar uma forma que posso ajudar a uma casa a operar de uma forma inteligente de uma forma eficiente, podendo assim
ajudar desde casas menores de poucas pessoas até casas com uma familia grande, trazendo confiança, segurança e eficiência ao lar de cada individuo. O projeto inclui
algumas coisas como sistema de segurança para evitar roubos ou até alertar algum vazamento de gâs na casa, sensor de temperatura para poder agir conforme os moradores
escolham melhor, sensores de presença para evitar coisas simples como deixar a luz acessa do quarto sem ninguém estar usando ele entre outras funcionalidades.

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar
Sistema de Segurança: Alertar ao sentir uma presença não desejada com uso do sensor de presença (Do estilo home alone caso ninguém esteja em casa) ou mediante quebra de porta/janela.
Sistema de Sensor de Temperatura: Caso a casa chegar a uma temperatura indesejada, ligar o aquecedor ou ar condicionado de acordo ao que o operador deseja (precisaria um sistema pra saber se tem alguem em casa pra não gastar energia)
Sistema de sensor de vazamento de gâs: Principalmente na cozinha, caso chegar nums niveis elevados de gâs, fazer um alerta que possa ligar para os bombeiros, caso alguem tenha esquecido o gâs aberto ou um vazamento.
Sistema de sensor de fumaça: Detector de fumaça na casa com ligação automática aos bombeiros

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
if sistema de segurança on:
  case quebraram janela
  case porta invadida
  case tem alguma presença sendo que não deveria ter ninguem em casa
if sensor de temperatura too high
  if tem alguem em casa
    liga ar condicionado
if sensor de temperatura too low
  if tem alguem em casa
    liga aquecedor
if gas level high
  soa alarme e liga para os bombeiros
if smoke level high
  soa alarme, liga water dispenser e liga para os bombeiros
if sensor de presença detects presence (na vdd acho que a temperatura estaria dentro disto)
  if luz desligada
    liga luz
if sensor de presença no presence 
  if luz ligada
    desliga luz
Talvez isto esteja incluido no sistema de segurança?
Periodos
provavelmente poderiamos manter o sensor de presença se atualizar cada 2s já que não é um sistema complicado, nem caro (acredito eu) 
gas, fumaça e segurança deveria ser prioridade de atualização já que estamos tratando com segurança dos moradores, entre mais rapido agirmos, melhor
temperatura poderia ser ajustado de acordo ao que os moradores desejam, podendo assim ser ajustado para varios tipos de moradores, casas, sem importar o clima da região onde morem



### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
Tratei um pouco disso acima, depois corrigimos para aqui 

## Descrição Estrutural do Sistema
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
