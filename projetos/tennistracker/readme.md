# `TennisTracker`
# `TennisTracker`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).


> |Nome  | RA | Curso|
> |--|--|--|
> | Nathan Shen Baldon  | 242448 | Eng. Elétrica|
> | Gabriel Buzzi Sanches  | 256389  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.

O Tênis é conhecido por ser um esporte difícil de se praticar pela exigência de cordenação física e agilidade nos movimentos. Sabendo disso os feedbacks de cada jogada são de extrema importância para quem está aprendendo ou quer melhorar no esporte. Pensando nisso nosso objetivo é entregar esses feedbacks tirando proveito da mecânida dos movimentos da raquete do jogador durante uma partida, assim excluindo também qualquer viés devido a um observador terceiro (professor ou treinador) e ainda oferencendo uma base fixa para comparação dos resultados. Para isso um sistema eletrônico embarcado será projetado para ficar fixado na raquete do jogador enquanto ele prática o esporte aquisitando e armazenando dados variados que posteriormente podem ser analisados em cumputador. Inicialmente qualquer processamento em tempo real é deixado de lado, focando apenas na aquisição dos dados, mas o projeto do sistema irá considerar como uma medida de escalabilidade a capacidade de realizar processamentos em tempo real e retornar respostas mesmo durante a jogatina.  

> Qual problema vocês pretendem solucionar?
- Análise quantitativa do desempenho de jogadores de tênis em treinos e partidas.
- Acompanhamento da qualidade e consistência de jogadas ao longo do tempo.
  
> Quem são os potenciais usuários?
- Jogadores de tênis (desde iniciantes até profissionais) que desejam acompanhar sua jornada e desenvolvimento no esporte.
- Treinadores que desejam coletar dados para validar seu método de treimamento.
- Uso pela mídia e entidades do esporte em partidas oficiais para levantamento de estatísticas.
  
> É possível estabelecer um valor econômico associado?  

Sim, o dispositivo poderia ser vendido para qualquer possoa interessada em monitorar seu desempenho no esporte Tênis.

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar  
Funcionalidade do dispositivo:
- Fixar na raquete
- Armazenar os dados aquisitados
- Medir a velocidade da raquete
- Medir a intensidade das colisões com a bolinha
- Medir a altura da raquete
- Media o ângulo com a horizontal da raquete
- Interface para controlar quando começar quando parar aquisição
- Interface para exportar os dados
- Peso reduzido
- Sinalizar o nível de bateria
- Armazenamento de energia (bateria)

Funcionalidade de análise:
- Contar o número de golpes
- Medir o tempo jogado
- Estimar a qualidade dos golpes

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.
- ligar/desligar

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
1. Ligar (botão on/off)
2. Desligar (botão on/off)
3. Exportação de dados solicitada
4. Conectar o carregador

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
O número de cada item da lista é referente a um evento da lista anterior.
1. Iniciar medições de grandezas (posição, velocidade, aceleração, etc.) (periódico com taxa de amostragem) + acender led
2. Interromper as medições e o fornecimento de energia + apagar led
3. Ligar no modo de comunicação
4. Desligar os sensores e carregar a bateria

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
