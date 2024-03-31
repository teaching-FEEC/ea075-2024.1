# `<OptiSort: Classificador de objetos>`
# `<OptiSort: Object classifier>`
## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Henrique Stumm Rocha  | 239694  | Eng. Elétrica|
> | Melvin Gustavo Maradiaga Elvir  | 185068  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
O OptiSort é um sistema de classificação automática para linhas de produção, com foco na indústria alimentícia, farmacêutica, automobilística e outras. Sua função principal é garantir a qualidade dos produtos através da identificação, classificação e remoção de itens que não atendam aos padrões de qualidade.


* Identificação e classificação: Reconhece diferentes tipos de itens e os separa em categorias, utilizando técnicas avançadas de visão computacional e aprendizado de máquina.
* Atuação na linha de produção: Remove automaticamente os itens defeituosos da esteira principal com um servomotor, direcionando-os para uma linha secundária para reavaliação ou descarte.

#### Exemplo de aplicação

Em uma linha de separação de frutas, o OptiSort:

* Detecta frutas estragadas por visão computacional.
* Empurra as frutas estragadas para fora da esteira principal com um servomotor.
* Direciona as frutas estragadas para uma linha secundária para reavaliação ou descarte.


### Configurabilidade
O sistema OptiSort oferece diversas configurações para atender às necessidades específicas de cada aplicação. As principais configurações disponíveis são:

1. Parâmetros de Identificação:
   - Tipos de itens: Defininição de quais tipos de itens o sistema deve identificar e classificar. O usuário precisará capturar imagens de itens de diferentes níveis de qualidade para treinar o classificador com visão computacional. O processo de treinamento deve ser simples e intuitivo e não requerer o uso de programação.
   - Limite de rejeição: A saída do classificador visual é um número correspondente à probabilidade de um item ser da categoria rejeitada. O limite de rejeição é a probabilidade a partir da qual o item deve ser identificado e retirado da linha de separação. Por exemplo, se o limite de rejeição for de 0.7, apenas produtos atribuídos com mais de 70% de probabilidade pelo sistema de visão computacional são removidos da esteira.
   - Número máximo de itens rejeitados abandonados: No caso de um item rejeitado não ser removido da esteira por fatores externos, o sistema registra esse evento. Se o número de itens rejeitados que passarem pela inspeção passar de uma determinada taxa, a esteira é interrompida
  
2. Parâmetros de Atuação
   - Velocidade da esteira: Ajuste da velocidade da esteira de acordo com o fluxo de produção.
   - Velocidade do servomotor: Velocidade com que o servomotor atua para retirar os itens defeituosos da linha de separação
   - Ação do servomotor: Distância em que o servomotor atua para remover os itens defeituosos da esteira. Pode ser regulada de acordo com os parâmetros da linha de separação.

#### Recursos Adicionais

O sistema OptiSort também pode ser configurado para:

  * Gerar relatórios de produção.
  * Monitorar o desempenho do sistema.
  * Receber atualizações de software.

#### Exemplo

Em uma linha de separação de frutas, o sistema OptiSort pode ser configurado para:

* Identificar diferentes tipos de frutas (por exemplo, maçãs, laranjas, bananas).
* Classificar as frutas por qualidade.
* Remover as frutas estragadas da esteira com um servomotor.
* Gerar relatórios de produção que detalham o número de frutas processadas e classificadas.


### Eventos

#### Eventos Periódicos

1. Aquisição de Imagens:

    Periodicidade: Contínua (a cada X milissegundos).
    Descrição: O sistema captura imagens da esteira transportadora para identificar e classificar os itens.

2. Processamento de Imagens:

    Periodicidade: Contínua (a cada X milissegundos).
    Descrição: O sistema aplica algoritmos de visão computacional e aprendizado de máquina para analisar as imagens e identificar os itens.

3. Monitoramento do Sistema:

    Periodicidade: Variável (pode ser configurado).
    Descrição: O sistema monitora seu próprio desempenho e gera relatórios de produção.

4. Atualizações de Software:

    Periodicidade: Variável (manual ou automática).
    Descrição: O sistema pode receber atualizações de software para melhorar seu desempenho ou adicionar novas funcionalidades.

#### Eventos Não Periódicos:

1. Atuação na Linha de Produção:

    Descrição: O sistema remove os itens defeituosos da esteira de acordo com as configurações definidas.

2. Passagem de item defeituoso para a próxima etapa:

    Descrição: Devido a algum fator externo, como excesso de itens na esteira, o OptiSort não é capaz de remover o item defeituoso a tempo e ele passa para a próxima etapa de produção.


### Tratamento de Eventos
Tratamento de Eventos no Sistema OptiSort

O tratamento de eventos é crucial para o bom funcionamento do sistema OptiSort. Abaixo, detalhamos o comportamento do sistema para cada tipo de evento.

Eventos Periódicos:

1. Aquisição de Imagens:

    O sistema captura imagens da esteira transportadora utilizando uma câmera de alta resolução.
    As imagens são armazenadas em um buffer de memória para serem processadas posteriormente.

2. Processamento de Imagens:

    O sistema aplica algoritmos de visão computacional e aprendizado de máquina para analisar as imagens e identificar os itens.
    As características dos itens (por exemplo, cor, tamanho, forma, textura) são extraídas e utilizadas para classificá-los.

3. Monitoramento do Sistema:

    O sistema monitora diversos parâmetros, como temperatura, vibração e consumo de energia.
    Se um parâmetro estiver fora da faixa normal, o sistema gera um alarme para alertar o operador.

4. Atualizações de Software:

    O sistema pode ser atualizado via software para melhorar seu desempenho ou adicionar novas funcionalidades.
    As atualizações podem ser instaladas manualmente ou automaticamente.

Eventos Não Periódicos:

1. Atuação na Linha de Produção:

    Se um item defeituoso for detectado, o sistema aciona um servomotor para removê-lo da esteira.
    O item defeituoso é direcionado para uma linha secundária para reavaliação ou descarte.

2. Passagem de item defeituoso para a próxima etapa:

    A passagem acidental de um item defeituoso é registrada na memória do sistema. Se o número de itens defeituosos que passarem para a próxima etapa de produção for maior que o parâmetro especificado, o OptiSort interrompe a esteira e solicita avaliação do operador.


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
