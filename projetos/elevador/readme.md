# Projeto de um circuito de controle para elevadores
# Elevator control circuit project

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| André Guilherme da Luz  | 231343  | Eng. Elétrica|
| Gabriel Vianna Serra  | 258555  | Eng. Elétrica|


## Descrição do Projeto
A ideia do projeto consiste em desenvolver um circuito controlador para elevadores, a fim de tomar decisões como a escolha de qual elevador deve subir, descer ou manter-se no lugar com base no andar atual, prioridade de chamada, distância do andar solicitado e situações de segurança, por exemplo. Nosso contexto de concepção desse projeto veio do motivo de que é algo muito útil e presente no dia a dia de pessoas, bem como factível de ser projetado durante o semestre da disciplina, permitindo nos desafiar com as possíveis variáveis de desenvolvimento sem sobrecarregar os esforços dentro do tempo estipulado.

Outro lado positivo do projeto é que seu custo não tende a ser alto, levando em conta que a lógica pode ser desenvolvida sem a necessidade de processamento muito avançado, e os demais dispositivos que podem ser possivelmente usados não tendem a ser caros (alguns sensores e circuitos básicos para mudança de direção do motor). Dessa forma, levando em conta um investimento que requer pouca manutenção (o principal serviço é o software envolvido no controle dos elevadores e o microprocessador do mesmo, que tende a ter boa durabilidade), pouco capital e que proporciona um controle útil e necessário na logística dos elevadores, temos um projeto viável e de custo acessível.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?


## Descrição Funcional

### Funcionalidades
O sistema de controle de elevadores deverá ser capaz de executar as seguintes tarefas:
  - Chamadas do elevador: receber e registrar chamadas de todos os andares do prédio.
  - Registrar as solicitações dentro do elevador.
  - Organizar as chamadas com base na localização, direção e disponibilidade.
  - Gerenciar a abertura e fechamento das portas.
  - Controle de sobrecarga: impedir o movimento do elevador se estiver sobrecarregado.
  - Responder imediatamente a situações de emergência.
  - Diagnosticar problemas mecânicos e elétricos.
  - Fornecer feedback aos passageiros sobre o andar que está.    

### Configurabilidade
O sistema possui os seguintes estados:
  - Subindo:
    O elevador está se deslocando para cima, pois recebeu uma chamada de algum andar mais elevado ou algum passageiro solicitou parada em um andar acima.
  - Descendo:
    O elevador está se deslocando para baixo, pois recebeu uma chamada de algum andar ou algum passageiro solicitou parada em um andar abaixo de sua posição.
  - Parado:
    O elevador está em um andar específico.
    - Portas abertas:
      O elevador está parado em um andar específico e com a porta aberta para entrada e saída de passageiros.
    - Portas fechadas:
      O elevador está fechada as portas após um tempo específico para entrada e saída dos passageiros e verificação de que não há passageiros se locomovendo pra dentro ou pra fora, bem como verificação de que não há possíveis falhas mecânicas e elétricas.

Ao receber chamadas de andares, o elevador (com portas fechadas) muda para o estado "subindo" ou "descendo", assim como quando o passageiro seleciona o andar desejado. Ao chegar no andar, o elevador muda para o modo "parado", inicialmente de portas fechadas, e rapidamente muda para o modo "portas abertas". Após um determinado tempo para entrarem e saírem passageiros, há a mudança de estado para "portas fechadas" novamente, se as condições de segurança forem satisfeitas. Assim, novas chamadas ocorrem, reiniciando. 
Há algumas mudanças de estado fora do funcionamento padrão. Ao verificar problemas mecânicos ou elétricos, sobrecarga ou outras emergências, ele passa automaticamente para o modo "parado". Se está parado devido a problemas de segurança, suas portas podem permanecer abertas ou fechadas de acordo com a ocasião.

### Eventos
Os eventos de mudança de estado:
  - Chamada de um andar (evento não-periódico, passa do estado "parado" para "subindo" ou "descendo").
  - Chegada do elevador a um andar solicitado (evento não-periódico, passa do estado "subindo" ou "descendo" para "parado").
  - Ao parar, abertura das portas (evento não-periódico, passa do estado "parado" para o sub estado "portas abertas").
  - Fechamento das portas após um tempo para entrada e saída de passageiros, bem como garantia de segurança (evento não-periódico, passa do sub estado "portas abertas" para "portas fechadas").
  - Pressionamento do botão de fechada de portas (evento não-periódico, passa do estado "portas abertas" para "portas fechadas").
  - Pessoa entre a porta (evento não-periódico, mantém-se no sub estado "portas abertas").
  - Detecção de sobrecarga (evento não-periódico, mantém-se no sub estado "portas abertas").
  - Detecção de falha (evento não-periódico, passa do estado  "subindo" ou "descendo" para "parado").

### Tratamento de Eventos
  - Chamada de um andar:
    Ao receber uma chamada, o sistema deve organizar as chamadas da melhor maneira, de forma que não fique subindo e descendo várias vezes.
  - Chegada do elevador a um andar solicitado:
    Ao chegar em um andar, o sistema deve alinhar corretamente o chão do elevador com o andar.
  - Ao parar, abertura das portas:
    Após o alinhamento correto do chão do elevador e do andar, o sistema deve mandar um sinal para abertura da porta correta.
  - Fechamento das portas após um tempo para entrada e saída de passageiros:
    Após um tempo previamente definido de abertura das portas, o sistema deve enviar um sinal para o fechamento das portas se as condições de segurança forem satisfeitas.
  - Pressionamento do botão de fechada de portas:
    Caso esteja pressionado o botão, o sistema deve enviar um sinal para fechamento da porta.
  - Pessoa entre a porta:
    O sistema, ao detectar que há algo no local de fechamento da porta, deve enviar o sinal para manter a porta aberta ou cancelar o fechamento.
  - Detecção de sobrecarga:
    Ao detectar sobre carga, o sistema deve manter-se parado.
  - Detecção de falha:
    Ao detectar falha, o sistema deve interromper o movimento e ficar parado.

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
