# `Rodovias Fluidas: Sistema de Redução de Congestionamentos`
# `Smooth Highways: Trafic Jam Reduction System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Kevin Caio Marques dos Santos  | 247218  | Eng. de Computação|
 | Thiago Maximo Pavão  | 247381  | Eng. de Computação|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?

O projeto foi idealizado para abordar um problema comum enfrentado pelos motoristas hoje em dia: congestionamentos em rodovias. Muitas vezes, atribui-se esse problema à ocorrência de acidentes que bloqueiam uma das vias, forçando o tráfego a se concentrar na outra via. No entanto, em muitos casos de congestionamento, não há acidente aparente ou outra explicação clara, o que levanta questões para os motoristas mais perspicazes.

Durante uma investigação sobre essa questão, foi encontrado um vídeo que explicava a causa de muitos congestionamentos. O principal fator identificado foi a grande disparidade de velocidades entre os veículos na mesma via, juntamente com ultrapassagens realizadas por veículos mais lentos. Isso faz com que outros motoristas tenham que reduzir sua velocidade, criando uma espécie de "onda de lentidão" que se propaga ao longo da rodovia. Eventualmente, essa onda de lentidão pode levar alguns carros a pararem completamente para evitar colisões.

Diante desse contexto, o objetivo do projeto é reduzir a propagação dessa onda de lentidão, diminuindo assim a extensão dos congestionamentos, especialmente nos pontos onde os motoristas são obrigados a parar completamente. O objetivo final é evitar que o congestionamento se agrave.

A prejudicialidade dos congestionamentos está muito além do atraso que gera para os motoristas em suas trajetórias diárias. Alguns exemplos de consequências são:

 - Estresse dos motoristas
 - Acidentes
 - Maior consumo de combustível
 - Maior poluição
 - Maior prejuízo para a saúde dos motoristas expostos a poluição gerada pelos carros

Nesse sentido, o Rodovias Fluídas® visa solucionar todos esses problemas ao monitorar o surgindo desses engarrafamentos e enviar informações aos motoristas que vem atrás para reduzirem a velocidade, de modo ao chegarem ao local do suposto congestionamento, ele ja tenha desaparecido. Com a implementação desse sistema, prevê-se que haja um significativo retorno econômico ao reduzir o consumo de combustível e a prevenção de acidentes.

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

- Medir a velocidade do veículo
- Medir a posição do veículo na rodovia
- Mostrar mensagens em um display sobre congestionamentos e informar qual velocidade o motorista deve trafegar.
- Reproduzir avisos sonoros quando novas informações estão disponíveis
- Detectar a localização e o tamanho de congestionamentos
- Determinar a velocidade adequada em reação a um congestionamento à frente
- Capacidade de distribuição das informações sobre congestionamentos para os carros trafegando na rodovia 

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

Como configuração, o usuário que possuir o dispositivo em seu carro pode optar por desabilitar o aviso sonoro e ao invés disso o display de informações deve piscar algumas vezes para chamar a atenção do motorista.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

Eventos esperados em fluxo normal

- Recebimento de informação de posição e velocidade de carro na via (periódico, 30 segundos)
- Detecção do surgimento de um congestionamento
- Detecção do fim de um congestionamento, volta do fluxo normal
- Recebimento de informações sobre congestionamentos na via
- Entrada/Saída do veículo de uma rodovia com suporte do sistema

Eventos de erro, inesperados

- Falha na obtenção da velocidade do veículo
- Falha na obtenção da posição do veículo
- Falha na comunicação com o sistema (envio/recebimento de mensagens) 

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

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

O sistema será composto por dois tipos de dispositivos: Módulos móveis, que estão presentes nos carros dos usuários do sistema e módulos fixos, presentes ao longo das rodovias, principalmente em trechos em que é congestionamentos são comuns.

Os módulos móveis tem como objetivo monitorar a velocidade do carro e informar ao motorista quando deve reduzir sua velocidade. Ele baseia essa decisão em sinais recebidos pelo módulos fixo mais próximo. Além disso, tem o papel de informar a velocidade do carro para o módulo fixo mais próximo.

Os dispostivos fixos são torres colocadas ao longo da via, e tem como objetivo detectar congestionamentos, recebendo inforamações de velocidade dos motoristas mais próximos, e repassar a inforamção para torres anteriores na via, que por sua vez avisam sobre as condições ao módulos móveis proxímos a elas.

![Alt text here](diagramas/diagrama-estrutural.png)

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
