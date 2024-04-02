# `<Projeto de um circuito de controle para elevadores>`
# `<Elevator control circuit project>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| André Guilherme da Luz  | 231343  | Eng. Elétrica|
| Gabriel Vianna Serra  | 258555  | Eng. Elétrica|


## Descrição do Projeto
A ideia do projeto consiste em desenvolver um circuito controlador para elevadores, a fim de tomar decisões como a escolha de qual elevador deve subir, descer ou manter-se no lugar com base no andar atual, prioridade de chamada, distância do andar solicitado e número de elevadores disponíveis, por exemplo. Nosso contexto de concepção desse projeto veio do motivo de que é algo muito útil e presente no dia a dia de pessoas, bem como factível de ser projeto durante o semestre da disciplina, permitindo nos desafiar com as possíveis variáveis de desenvolvimento sem sobrecarregar os esforços dentro do tempo estipulado.

Outro lado positivo do projeto é que seu custo não tende a ser alto, levando em conta que a lógica pode ser desenvolvida sem a necessidade de processamento muito avançado, e os demais dispositivos que podem ser possivelmente usados não tendem a ser caros (alguns sensores e circuitos básicos para mudança de direção do motor). Dessa forma, levando em conta um investimento que requer pouca manutenção (o principal serviço é o software envolvido no controle dos elevadores e o microprocessador do mesmo, que tende ter boa durabilidade), pouco capital e que proporciona um controle útil e necessário na logística dos elevadores, temos um projeto viável e de custo acessível. 
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
O sistema de controle de elevadores deverá ser capaz de executar as seguintes tarefas:
  - Chamadas do elevador: receber e registrar chamadas de todos os andares do prédio.
  - Registrar as solicitações dentro do elevador.
  - Organizar as chamadas com base na localização, direção e disponibilidade, para economizar energia.
  - Movimentar o elevador de forma suave e segura.
  - Gerenciar a abertura e fechamento das portas.
  - Controle de sobrecarga. Impedir o movimento do elevador se estiver sobrecarregado.
  - Detectar quantidade de pessoas dentro do elevador.
  - Responder imediatamente a situações de emergência.
  - Diagnosticar problemas mecânicos e elétricos.
  - Gerenciamento de energia quando está parado. (Entrar em stand-by depois de algum tempo sem chamadas).
  - Fornecer feedback aos passageiros sobre o andar que está.
    
    

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

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

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
